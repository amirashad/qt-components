/* 
 * File:   HttpRequester2.cpp
 * Author: Rashad Amirjanov
 *
 * Created on October 20, 2010, 5:48 PM
 */

#include "QHttpRequester.h"
#include <stdio.h>
#include <QFile>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include <QDir>

#ifdef QT_WIDGET_LIB
    #include <QtWidgets>
#endif

HttpRequester::HttpRequester(QObject * parent) : QObject(parent) {
    //    m_requestFinished = false;
    m_authDialogEnabled = false;
    m_requestMethod = GET;
    m_reply = NULL;
    m_timeout = 60000; // timeout 60 sec.
    m_cacheEnabled = false;
    m_diskCache.setCacheDirectory(QDir::tempPath() + "/saferegion/caches");

    connect(&m_qnam, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)),
            this, SLOT(slotAuthenticationRequired(QNetworkReply*, QAuthenticator*)));
}

HttpRequester::~HttpRequester() {
    if (m_reply != NULL) {
        m_reply->abort();
        m_reply->deleteLater();
    }
}
bool HttpRequester::isCacheEnabled() const
{
    return m_cacheEnabled;
}

void HttpRequester::setCacheEnabled(bool cacheEnabled)
{
    m_cacheEnabled = cacheEnabled;
}

void HttpRequester::clearCache(){
    m_diskCache.clear();
}

void HttpRequester::setAuthDialogEnabled(bool enable) {
    this->m_authDialogEnabled = enable;
}

void HttpRequester::setAuthentication(QString userName, QString password) {
    this->m_userName = userName;
    this->m_password = password;
}

QString HttpRequester::userName() {
    return this->m_userName;
}

QString HttpRequester::password() {
    return this->m_password;
}

void HttpRequester::sendRequest(QString url) {
    //    m_requestFinished = false;
    //    m_errorString = "";
    m_response = "";
    m_requestUrl = url;

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    for (int i = 0; i < m_headers.size(); i++) {
        request.setRawHeader(m_headers.keys()[i], m_headers.values()[i]);
    }

    if (!m_sslConfiguration.isNull()) {
        //        //    QSslConfiguration sslConfiguration = request.sslConfiguration();
        //        QSslConfiguration sslConfiguration = QSslConfiguration::defaultConfiguration();
        //        sslConfiguration.setProtocol(QSsl::AnyProtocol);
        //        sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
        request.setSslConfiguration(m_sslConfiguration);
    }
    
    if (m_cacheEnabled){
        m_qnam.setCache(&m_diskCache);
        //        request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    }else{
        m_qnam.setCache(NULL);
    }

    if (m_requestMethod == GET) {
        m_reply = m_qnam.get(request);
    } else if (m_requestMethod == POST) {
        m_reply = m_qnam.post(request, m_postData);
    } else if (m_requestMethod == PUT) {
        m_reply = m_qnam.put(request, m_postData);
    } else if (m_requestMethod == DELETE_RESOURCE) {
        m_reply = m_qnam.deleteResource(request);
    } else if (m_requestMethod == OPTIONS) {
        m_reply = m_qnam.sendCustomRequest(request, m_postData);
    }
    //    connect(m_reply, SIGNAL(finished()), this, SLOT(httpFinished()));
    //    connect(m_reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));

    QTimer timer;
    timer.setSingleShot(true);

    QEventLoop loop;
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    connect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));
    timer.start(m_timeout);
    loop.exec();

    if (timer.isActive()) {
        timer.stop();
        if (m_reply->error() > 0) {
            // error
            printErr();
        } else {
            int v = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

            if (v >= 200 && v < 300) { // Success
                m_response = m_reply->readAll();
            }
        }
    } else {
        // timeout
        disconnect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));

        m_reply->abort();
    }
}

void HttpRequester::slotAuthenticationRequired(QNetworkReply*, QAuthenticator *authenticator) {
    showAuthDialog();

    authenticator->setUser(m_userName);
    authenticator->setPassword(m_password);
}

QByteArray HttpRequester::response() {
    return m_response;
}

QString HttpRequester::errorString() {
    if (m_reply != NULL && m_reply->error() > 0) {
        return m_reply->errorString();
    } else {
        return "";
    }
}

void HttpRequester::setRequestMethod(RequestMethod method) {
    this->m_requestMethod = method;
}

HttpRequester::RequestMethod HttpRequester::requestMethod() {
    return m_requestMethod;
}

void HttpRequester::setPostData(QByteArray postData) {
    this->m_postData = postData;
}

QByteArray HttpRequester::postData() {
    return m_postData;
}

void HttpRequester::setRawHeader(const QByteArray& headerName, const QByteArray& value) {
    m_headers.insert(headerName, value);
}

QByteArray HttpRequester::rawHeader(const QByteArray& headerName) const {
    return m_headers.value(headerName);
}

void HttpRequester::setSslConfiguration(const QSslConfiguration& config) {
    m_sslConfiguration = config;
}

QSslConfiguration HttpRequester::sslConfiguration() const {
    return m_sslConfiguration;
}

void HttpRequester::setTimeout(const int &timeout) {
    m_timeout = timeout;
}

const int& HttpRequester::timeout() const {
    return m_timeout;
}

void HttpRequester::printErr() {
    printf("ERROR (HttpRequester2): %s\n\tPath: %s\n",
           errorString().toLatin1().data(),
           m_requestUrl.toLatin1().data());
}

void HttpRequester::showAuthDialog() {
    if (!m_authDialogEnabled) {
        return;
    }
#ifdef QT_WIDGET_LIB
    QDialog dialog;
    dialog.setWindowTitle(tr("Authentication"));
    QLineEdit leUsername(&dialog);
    QLineEdit lePassword(&dialog);
    lePassword.setEchoMode(QLineEdit::Password);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(tr("Username"), &leUsername);
    layout->addRow(tr("Password"), &lePassword);

    leUsername.setText(m_userName);
    lePassword.setText(m_password);

    QDialogButtonBox box;
    box.addButton(QDialogButtonBox::Ok);
    box.addButton(QDialogButtonBox::Cancel);

    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
    mainLayout->addLayout(layout);
    mainLayout->addWidget(&box);

    connect(&box, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&box, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        m_userName = leUsername.text();
        m_password = lePassword.text();
    } else {
        //        m_userName
    }
#endif
}

QByteArray HttpRequester::downloadFile(QString url, QString user, QString pass, QString fileName, RequestMethod method, QByteArray postData, QMap<QByteArray, QByteArray> rawHeaders, QSslConfiguration config, bool cacheEnabled) {
    HttpRequester httpRequester;
    if(url.contains('.')){
        httpRequester.setAuthentication(user, pass);
        httpRequester.setRequestMethod(method);
        httpRequester.setPostData(postData);
        //    httpRequester.setTimeout(10000);

        for (int i = 0; i < rawHeaders.size(); i++) {
            httpRequester.setRawHeader(rawHeaders.keys()[i], rawHeaders.values()[i]);
        }

        if (!config.isNull()) {
            httpRequester.setSslConfiguration(config);
        }
        httpRequester.setCacheEnabled(cacheEnabled);

        httpRequester.sendRequest(url);
        //    httpRequester.waitForFinished(false);
        if (!httpRequester.errorString().isEmpty()) {
            httpRequester.printErr();
        }
        if (!fileName.isEmpty() && !httpRequester.response().isEmpty()) {
            QFile outFile(fileName);
            outFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
            outFile.resize(0);
            outFile.write(httpRequester.response());
            outFile.close();
        }
    }else{
        //        qDebug()<<"not correct url for download data";
    }

    return httpRequester.response();
}

void HttpRequester::clearCacheStatic(){
    HttpRequester httpRequester;
    httpRequester.clearCache();
}
