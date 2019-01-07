#ifndef MYQFILE_H
#define MYQFILE_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

class file_error {};
class open_error : public file_error {};

class myQfile {
public:
    myQfile(const QString filename);
    QJsonDocument makeJSONDoc();

    ~myQfile();

private:
    QFile m_file;
};

#endif // MYQFILE_H

