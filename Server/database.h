#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFile>

class DataBase;

class DataBaseDestroyer
{
private:
    DataBase *instance;
public:
    ~DataBaseDestroyer() { delete instance; }
    void initialize(DataBase *link) { instance = link; }
};


class DataBase
{
private:
    static DataBase *instance;
    static DataBaseDestroyer destroyer;
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
protected:
    DataBase()
    {
        if (!QFile::exists("../Server/OURCAFEDB.db")) {
            qDebug() << "DataВase file does not exist";
            std::exit(1);
        }
        qDebug()<<"Open DataBase";
        DB.setDatabaseName("../server/EduTest.db");

        if(!DB.open())
        {
            qDebug()<<"Error opening DataBase";
            std::exit(1);
        }
    }
    DataBase(const DataBase &) = delete;
    DataBase &operator = (DataBase &) = delete;
    ~DataBase() { DB.close(); }
    friend class DataBaseDestroyer;
public:
    static DataBase *Connect(){
        if (!instance)
        {
            instance = new DataBase();
            destroyer.initialize(instance);
        }

        return instance;
    }
};

DataBase *DataBase::instance;
DataBaseDestroyer DataBase::destroyer;

#endif // DATABASE_H
