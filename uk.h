#ifndef UK_H
#define UK_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QtNetwork/QNetworkReply>

class UK : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int porc READ getPorc WRITE setPorc NOTIFY porcChanged)
    Q_PROPERTY(QString uploadState READ getUploadState WRITE setUploadState NOTIFY uploadStateChanged)
    Q_PROPERTY(QString ukStd READ getUkStd() WRITE setUkStd NOTIFY ukStdChanged)
    Q_PROPERTY(QString stdErr READ getStdErr WRITE setStdErr NOTIFY stdErrChanged)
    Q_PROPERTY(bool runCL READ getRunCL WRITE setRunCL NOTIFY runCLChanged)
public:
    explicit UK(QObject *parent = nullptr);    

    //Propiedades para QML
    int porc;
    QString uploadState;
    QString ukStd;
    QString stdErr;
    bool runCL;

    Q_INVOKABLE int getPorc(){
        return porc;
    }
    Q_INVOKABLE void setPorc(int p){
        porc = p;
        emit porcChanged();
    }
    Q_INVOKABLE QString getUploadState(){
        return uploadState;
    }
    Q_INVOKABLE void setUploadState(QString us){
        uploadState = us;
        emit uploadStateChanged();
    }
    Q_INVOKABLE QString getUkStd(){
        return ukStd;
    }
    Q_INVOKABLE void setUkStd(QString s){
        ukStd = s;
        emit ukStdChanged();
    }
    Q_INVOKABLE QString getStdErr(){
        return stdErr;
    }
    Q_INVOKABLE void setStdErr(QString s){
        stdErr = s;
        emit stdErrChanged();
    }
    Q_INVOKABLE bool getRunCL(){
        return runCL;
    }
    Q_INVOKABLE void setRunCL(bool b){
        runCL = b;
        emit runCLChanged();
    }
    Q_INVOKABLE void setHost(QString nh);
    Q_INVOKABLE QString host();      
    bool debugLog=false;
signals:
    //Señales para QML
    void porcChanged();
    void uploadStateChanged();
    void ukStdChanged();
    void stdErrChanged();
    void runCLChanged();
public slots:
    //Funciones del Sistema Unik
    bool downloadRemoteFolder(QString urlFolder, QString list, QString dirDestination);
    void restartApp();
    bool run(QString commandLine);    
    QString getPath(int path);
    //Funciones Network
    QByteArray getHttpFile(QByteArray url);
    void sendFile(QString file, QString phpReceiver);
    //Funciones Sqlite
    bool sqliteInit(QString pathName, bool debug);
    bool sqlQuery(QString query, bool debug);
    QString getJsonSql(QString table, QString query, QString type, bool debug);
    bool mysqlInit(QString hostName, QString dataBaseName, QString userName, QString password, int firtOrSecondDB);
    void setMySqlDatabase(QString databaseName, int firtOrSecondDB);
    //Funciones de Sistema de Archivos
    void deleteFile(QByteArray f);
    bool setFile(QByteArray n, QByteArray d);
    QString getFile(QByteArray n);
    bool mkdir(const QString path);    
    QString getUpksLocalPath();
    bool fileExist(QByteArray fileName);    

#ifdef Q_OS_WIN
    int frameHeight(QObject *window);
    int frameWidth(QObject *window);
#endif
private:    
    QNetworkReply *respuentaSendDatos;
};
#endif
