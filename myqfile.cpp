#include <myqfile.h>

myQfile::myQfile(const QString filename)
    : m_file(filename) {
    if(!m_file.open(QIODevice::ReadOnly)) {
        throw open_error();
    }
}

QJsonDocument myQfile::makeJSONDoc()
{
    return QJsonDocument::fromJson(m_file.readAll());
}

myQfile::~myQfile()
{
    m_file.close();
}
