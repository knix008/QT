#include "mariadb.h"

bool mariadb_connect()
{
    // 0. Check available SQL Drivers
    qDebug() << "Drivers" << QSqlDatabase::drivers();
    // 1. 데이터베이스 연결 객체 생성
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    // 2. 연결 정보 설정
    db.setHostName("127.0.0.1");  // MariaDB 서버 주소
    db.setPort(3306);             // MariaDB 포트
    db.setDatabaseName(""); // 데이터베이스 이름
    db.setUserName("");     // 사용자 이름
    db.setPassword("");       // 비밀번호

    // 3. 데이터베이스 연결 시도
    if (db.open()) {
        qInfo() << "✅ MariaDB에 성공적으로 연결되었습니다!";
        db.close();
    } else {
        qCritical() << "❌ 데이터베이스 연결 실패:" << db.lastError().text();
        return false;
    }
    return true;
}
