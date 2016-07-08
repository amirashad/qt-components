/* 
 * File:   HttpRequester2.h
 * Author: Rashad Amirjanov
 *
 * Created on October 20, 2010, 5:48 PM
 */

#ifndef HTTPREQUESTER2_H
#define	HTTPREQUESTER2_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QAuthenticator>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QNetworkDiskCache>

#include "../qcomps_global.h"

class QCOMPS_EXPORT HttpRequester2 : public QObject {
    Q_OBJECT
public:
    HttpRequester2(QObject *parent = NULL);
    virtual ~HttpRequester2();

    enum RequestMethod {
        GET, POST, PUT, DELETE_RESOURCE, OPTIONS
    };
private:
    QNetworkAccessManager m_qnam;
    QNetworkReply *m_reply;
    QString m_userName;
    QString m_password;
    bool m_authDialogEnabled;
    int m_timeout;

    RequestMethod m_requestMethod;
    QString m_requestUrl;
    QByteArray m_response;
    QByteArray m_postData;
    QMap<QByteArray, QByteArray> m_headers;
    QSslConfiguration m_sslConfiguration;
    bool m_cacheEnabled;
    QNetworkDiskCache m_diskCache;

    //    QString m_errorString;
    //    bool m_requestFinished;

    void showAuthDialog();
public slots:
    //    void httpFinished();
    //    void httpReadyRead();
    void slotAuthenticationRequired(QNetworkReply*, QAuthenticator *);

public:
    void setAuthDialogEnabled(bool enable = true);
    void setAuthentication(QString userName, QString password);
    QString userName();
    QString password();

    void setRequestMethod(RequestMethod method);
    RequestMethod requestMethod();

    void setPostData(QByteArray postData);
    QByteArray postData();

    void setRawHeader(const QByteArray &headerName, const QByteArray &value);
    QByteArray rawHeader(const QByteArray &headerName) const;

    void setSslConfiguration(const QSslConfiguration & config);
    QSslConfiguration sslConfiguration() const;

    bool isCacheEnabled() const;
    void setCacheEnabled(bool isCacheEnabled);
    void clearCache();

    void setTimeout(const int& timeout);
    const int& timeout() const;

    void sendRequest(QString url);

    QString errorString();
    QByteArray response();
    void printErr();

    static QByteArray downloadFile(QString url, QString user = "", QString pass = "",
                                   QString fileName = "", RequestMethod method = GET,
                                   QByteArray postData = QByteArray(),
                                   QMap<QByteArray, QByteArray> rawHeaders = QMap<QByteArray, QByteArray>(),
                                   QSslConfiguration config = QSslConfiguration(),
                                   bool cacheEnabled = false);

    static void clearCacheStatic();
};

#endif	/* HTTPREQUESTER2_H */
