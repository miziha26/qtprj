#include "database.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "logindialog.h"

database::database(QObject *parent) : QObject(parent)
{

}

bool database::databaseinit()
{
    //初始化数据库对象
    //使用QSqlDatabase类中的静态成员函数addDatebase来指定数据库类型
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库文件的路径名
    db.setDatabaseName("../test.db");
    //打开数据库，如果数据库存在，则直接打开，不存在就创建后在打开
    if(!db.open())
    {
        //打开数据库失败
        qDebug() << "open test.db error" << db.lastError().text();
        return false;
    }
    qDebug() << "test.db init success";

    //准备sql原始语句创建用户信息表，用户账号id，密码passwd，用户电话号码tel
    QString sql_str = "create table if not exists t_user(id varchar(12) not null primary key,"
                      "passwd varchar(12) not null,"
                      "tel char(11) not null unique);";
    //实例化一个QSqlQuery对象
    QSqlQuery query(db);
    //执行sql语句
    if(!query.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "create t_user error:" << query.lastError().text();
        return false;
    }

    //准备sql原始语句创建音乐表，音乐编号mus_id，音乐名mus_name，音乐vip权限
    sql_str = "create table if not exists t_music(mus_id varchar(32) primary key,"
                      "mus_name varchar(255) not null,"
                      "mus_path varchar(512) not null unique);";
    //实例化一个QSqlQuery对象
    QSqlQuery query1(db);
    //执行sql语句
    if(!query1.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "create t_music error:" << query.lastError().text();
        return false;
    }

    //准备sql原始语句创建用户喜欢歌曲表，用户编号uid，账号id，用户喜欢列表
    sql_str = "create table if not exists t_liked_mus(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "user_id VARCHAR(12),"
                      "song_id VARCHAR(12),"
                      "FOREIGN KEY (user_id) REFERENCES t_user(id),"
                      "FOREIGN KEY (song_id) REFERENCES t_music(mus_id));";
    //实例化一个QSqlQuery对象
    QSqlQuery query2(db);
    //执行sql语句
    if(!query2.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "create t_liked_mus error:" << query.lastError().text();
        return false;
    }
    qDebug() << "create t_user success!";
    qDebug() << "create t_music success!";
    qDebug() << "create t_liked_mus success!";
}

bool database::usrreg(QString &id, QString &passwd, QString &tel)
{
    //准备sql原始语句
    QString sql_str = QString("insert into t_user values('%1','%2','%3');").arg(id).arg(passwd).arg(tel);
    qDebug() << sql_str;
    //实例化一个QSqlQuery对象
    QSqlQuery query(db);
    //执行sql语句
    if(!query.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "insert into t_user error:" << query.lastError().text();
        return false;
    }
    qDebug() << "insert into t_user success!";
    return true;
}

bool database::usrlogin(QString &id, QString &passwd)
{
    //准备sql原始语句
    QString sql_str = QString("select * from t_user where id='%1' and passwd='%2';").arg(id).arg(passwd);
    //实例化一个QSqlQuery对象
    QSqlQuery query(db);
    //执行sql语句
    if(!query.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "select error:" << query.lastError().text();
        return false;
    }
    if(!query.next())
    {
        //没有找到这个信息
        return false;
    }
    return true;
}

bool database::usrfind(QString &id,QString &newpwd)
{
    //准备sql原始语句
    QString sql_str = QString("select * from t_user where id='%1' ;").arg(id);
    //实例化一个QSqlQuery对象
    QSqlQuery query(db);
    //执行sql语句
    if(!query.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "select error:" << query.lastError().text();
        return false;
    }
    if(!query.next())
    {
        //没有找到这个信息
        return false;
    }
    //找到了，修改密码
    sql_str = QString(" update t_user set passwd = '%1' where id = '%2';").arg(newpwd).arg(id);
    QSqlQuery query1(db);
    //执行sql语句
    if(!query1.exec(sql_str))
    {
        //sql语句执行失败
        qDebug() << "update error:" << query.lastError().text();
        return false;
    }
    return true;
}

//实现将歌曲添加为喜欢或移除出喜欢列表
bool database::toggleLikedSong(const QString& userId, const QString& songId)
{
    QSqlQuery query(db);

    // 1. 检查歌曲是否已在喜欢列表中
    query.prepare("SELECT COUNT(*) FROM t_liked_mus WHERE user_id = :userId AND song_id = :songId");
    query.bindValue(":userId", userId);
    query.bindValue(":songId", songId);

    if (!query.exec()) {
        qDebug() << "Failed to check liked song:" << query.lastError();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();

    // 2. 如果歌曲已在喜欢列表中，删除它
    if (count > 0) {
        query.prepare("DELETE FROM t_liked_mus WHERE user_id = :userId AND song_id = :songId");
        query.bindValue(":userId", userId);
        query.bindValue(":songId", songId);

        if (!query.exec()) {
            qDebug() << "Failed to remove liked song:" << query.lastError();
            return false;
        }

        return true; // 成功删除，返回 true
    }
    else {
        // 3. 如果歌曲不在喜欢列表中，添加它
        query.prepare("INSERT INTO t_liked_mus (user_id, song_id) VALUES (:userId, :songId)");
        query.bindValue(":userId", userId);
        query.bindValue(":songId", songId);

        if (!query.exec()) {
            qDebug() << "Failed to add liked song:" << query.lastError();
            return false;
        }

        return true; // 成功插入，返回 true
    }
}


//bool database::toggleLikedSong(const QString &userId, const QString &songId)
//{
//    QSqlQuery query(db);
//    if(isLikedSong(userId,songId))
//    {
//        // 歌曲已经被喜欢,删除记录
//        query.prepare("DELETE FROM t_liked_mus WHERE user_id = :userId AND song_id = :songId");
//    }
//    else
//    {
//        // 歌曲未被喜欢,添加记录
//        query.prepare("INSERT INTO t_liked_mus (user_id, song_id) VALUES (:userId, :songId)");
//    }

//    query.bindValue(":userId", userId);
//    query.bindValue(":songId", songId);
//    return query.exec();
//}
//1. 对 isLikedSong 的调用和处理
//你的版本:
//在执行 isLikedSong 后，直接决定执行删除或插入操作。
//如果 isLikedSong 返回 true，表示歌曲已被喜欢，则执行删除操作，否则执行插入操作。
//我的版本:
//先通过 SELECT COUNT(*) 查询数据库中是否存在匹配的记录，然后基于查询的结果（count > 0）决定执行删除或插入操作。
//问题:

//你版本中的 isLikedSong 可能存在潜在的问题，导致它返回了错误的结果（即 true 或 false 不正确）。在我的版本中，通过直接查询 COUNT(*)，减少了依赖 isLikedSong 函数的可能错误，并确保查询和操作是在同一函数中执行的，从而减少了出错的可能性。
//2. 查询的执行顺序
//你的版本:

//每次调用 isLikedSong 后，立即进行下一步的数据库操作（删除或插入）。但如果 isLikedSong 返回了错误的结果，后续的数据库操作将是不正确的。
//我的版本:

//将查询和修改操作集成在一个函数内，确保了顺序和上下文的一致性。所有的操作都基于查询结果（count），并且确保了每一步都是依赖于当前的数据库状态。
//问题:

//如果在你的版本中 isLikedSong 返回了错误的布尔值，删除和插入操作可能是错误的。例如，如果 isLikedSong 错误地返回 false，即使歌曲已存在，它仍会尝试插入，导致重复记录。我的版本避免了这一点，通过直接查询计数，然后执行相应操作，减少了依赖外部函数返回值的风险。
//3. 数据库事务的一致性
//你的版本:

//isLikedSong 的执行与后续的删除/插入操作是分开的，如果这两个操作之间存在任何变化（例如另一个线程或进程修改了数据库），可能会导致不一致的结果。
//我的版本:

//查询和后续操作在同一上下文中执行，确保了一致性。减少了数据库状态在操作之间可能发生变化的风险。
//问题:

//在你的版本中，如果在 isLikedSong 调用和后续数据库操作之间数据库状态发生了变化（例如，歌曲被另一个进程喜欢或取消喜欢），可能会导致不一致的行为。我的版本通过在一个函数内执行所有操作，确保了一致性。
//总结
//你之前的版本更依赖于 isLikedSong 的正确性，而我的版本减少了这种依赖，并确保了整个函数的操作在一个连贯的上下文中进行。这使得代码更加健壮，减少了出错的可能性。

//看歌曲是否为喜欢,如果表中有记录，说明歌曲为喜欢
bool database::isLikedSong(const QString &userId, const QString &songId) {
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM t_liked_mus WHERE user_id = :userId AND song_id = :songId");
    query.bindValue(":userId", userId);
    query.bindValue(":songId", songId);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Found" << count << "matching liked songs";
        return count > 0;
    } else {
        qDebug() << "Failed to execute query or retrieve data:" << query.lastError().text();
        return false;
    }
}

//bool database::isLikedSong(const QString &userId, const QString &songId)
//{
//    QSqlQuery query(db);
//    query.prepare("SELECT * FROM t_liked_mus WHERE user_id = :userId AND song_id = :songId");
//    query.bindValue("userId",userId);
//    query.bindValue("songId",songId);
//    qDebug() << "Executing query: SELECT * FROM t_liked_mus WHERE user_id =" << userId << "AND song_id =" << songId;

//    return query.exec() and query.next();
//}
//函数错误原因
//1. QSqlQuery::next() 行获取问题
//在之前的实现中，你使用了 query.exec() 和 query.next() 来检查查询结果。虽然 query.exec() 可能成功执行，但 query.next() 返回 false，这表明查询虽然执行了，但没有返回行数据。
//query.next() 适用于当你需要迭代查询结果中的每一行数据时使用。如果查询的结果集中没有行数据，或者有某些潜在问题（例如编码或事务问题），则 query.next() 会返回 false，导致你的函数返回 false。
//2. 编码或字符集问题
//虽然你的 SQL 查询是正确的，但在绑定参数时，特别是字符串参数（userId 和 songId），可能存在隐蔽的编码问题。例如，数据库中的实际数据和你程序中的字符串数据可能在编码上不一致，这种情况下，即使你认为传递的值是正确的，查询可能仍然无法匹配到预期的行。
//这种问题很难通过简单的调试检测到，因为打印的调试信息可能看起来是正确的。
//3. 查询优化问题
//使用 SELECT * 的查询可能会返回比预期更多的数据。如果有很多列，或者表非常大，QSqlQuery::next() 可能会表现得不如期望的那样，尤其是在资源受限的环境中。新的实现通过 SELECT COUNT(*) 只返回一个整数，减轻了数据库的负担，并使查询更加高效和直观。
//4. 潜在的逻辑错误
//之前的实现中，query.exec() 和 query.next() 结合的用法并不是在所有情况下都可靠。特别是在你只想知道是否存在某一行记录时，直接获取行数的实现（COUNT(*)）要比获取整行数据再进行判断更简单和可靠。

