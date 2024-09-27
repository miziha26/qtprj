#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    bool databaseinit();
    bool usrreg(QString &id,QString &passwd,QString &tel);
    bool usrlogin(QString &id,QString &passwd);
    bool usrfind(QString &id,QString &newpwd);
    bool toggleLikedSong(const QString& userId, const QString& songId);
    bool isLikedSong(const QString& userId, const QString& songId);

signals:

public slots:

public:
    QSqlDatabase db;
};

#endif // DATABASE_H
