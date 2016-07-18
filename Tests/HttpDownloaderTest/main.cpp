#include <QApplication>
#include <QDebug>
#include <qcomponents/http/QHttpRequester.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString url = "https://raw.githubusercontent.com/amirashad/qt-components/master/Tests/HttpDownloaderTest/testfile.txt";

    qInfo() << "Request 1:\n\tFile opening...";
    QByteArray response1 = QHttpRequester::downloadFile(url);
//    if(!response1.isEmpty()) {//if no error and has content
        qInfo() << "Request 1:\nfile content: " << response1;
//    }

    qInfo() << "Request 2:\n\tFile downloading...";
    QByteArray response2 = QHttpRequester::downloadFile(url, "", "", "downloaded_file.txt");
    if(!response2.isEmpty()) {//if no error and has content
        qInfo() << "\n\tFile downloaded: downloaded_file.txt";
    }

    qInfo() << "Request 3:\n\tFTP request...";
    QByteArray response3 = QHttpRequester::downloadFile("ftp://ftp.fau.de/qtproject/official_releases/qt/5.7/5.7.0/md5sums.txt", "", "", "downloaded_file3.txt");
    if(!response3.isEmpty()) {//if no error and has content
        qInfo() << "\n\tFTP File downloaded: downloaded_file3.txt";
    }
    return app.exec();
}
