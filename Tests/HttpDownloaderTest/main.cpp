#include <QApplication>
#include <QDebug>
#include <qcomponents/http/QHttpRequester.h>

#include <QNetworkProxy>
#include <QFile>

void initProxySettings(){
    QString fileName = "proxy.properties";
    QFile file(fileName);
    if(file.exists()){
        QString proxyAddress = getProxyConfig("ip");
        int proxyPort = getProxyConfig("port").toInt();
        QString proxyUserName = getProxyConfig("user");
        QString proxyPassword = getProxyConfig("password");
        QString proxyType = getProxyConfig("type");

        QNetworkProxy proxy;
        proxy.setType(QNetworkProxy::ProxyType(proxyType.toInt()));
        proxy.setHostName(proxyAddress);
        proxy.setPort(proxyPort);
        proxy.setUser(proxyUserName);
        proxy.setPassword(proxyPassword);
        QNetworkProxy::setApplicationProxy(proxy);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    initProxySettings();
    QString url = "http://raw.githubusercontent.com/amirashad/qt-components/master/Tests/HttpDownloaderTest/testfile.txt";
    qInfo() << QHttpRequester::downloadFile(url);

    return app.exec();
}
