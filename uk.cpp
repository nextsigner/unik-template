#include "uk.h"

UK::UK(QObject *parent) : QObject(parent){}
void UK::setHost(QString nh){}
QString UK::host(){return "";}
bool UK::downloadRemoteFolder(QString urlFolder, QString list, QString dirDestination){return true;}
void UK::restartApp(){}
bool UK::run(QString commandLine){return false;}
QString UK::getPath(int path){return "";}
QByteArray UK::getHttpFile(QByteArray url){return "";}
void UK::sendFile(QString file, QString phpReceiver){}
bool UK::sqliteInit(QString pathName, bool debug){return false;}
bool UK::sqlQuery(QString query, bool debug){return false;}
QString UK::getJsonSql(QString table, QString query, QString type, bool debug){return QString();}
bool UK::mysqlInit(QString hostName, QString dataBaseName, QString userName, QString password, int firtOrSecondDB){return false;}
void UK::setMySqlDatabase(QString databaseName, int firtOrSecondDB){}
void UK::deleteFile(QByteArray f){}
bool UK::setFile(QByteArray n, QByteArray d){return false;}
QString UK::getFile(QByteArray n){return "";}
bool UK::mkdir(const QString path){return false;}
QString UK::getUpksLocalPath(){return QString();}
bool UK::fileExist(QByteArray fileName){return false;}
#ifdef Q_OS_WIN
int UK::frameHeight(QObject *window)
{
    QQuickWindow *qw = qobject_cast<QQuickWindow *>(window);
    if(qw)
        return qw->frameGeometry().height();
    return QRect().height();
}

int UK::frameWidth(QObject *window)
{
    QQuickWindow *qw = qobject_cast<QQuickWindow *>(window);
    if(qw)
        return qw->frameGeometry().width();
    return QRect().width();
}
#endif
