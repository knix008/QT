#include "ConnectDB.h"

bool connectDB(){

    // SQLite 데이터베이스 연결
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db"); // 파일명(경로) 지정

    if (!db.open()) {
        qDebug() << "데이터베이스 연결 실패:" << db.lastError().text() << "\n";
        return false;
    }
    qDebug() << "데이터베이스 연결 성공!" << "\n";
    return true;
}
