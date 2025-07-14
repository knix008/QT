#include <stdio.h>
#include "sqlite.h"

bool sqlite_connect(){

    // SQLite 데이터베이스 연결
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db"); // 파일명(경로) 지정

    if (!db.open()) {
        qDebug() << "데이터베이스 연결 실패:" << db.lastError().text() << "\n";
        return false;
    }
    qDebug() << "데이터베이스 연결 성공!" << "\n";
    printf("DB Connection Successful!!!\n");
    fflush(stdout);
    return true;
}
