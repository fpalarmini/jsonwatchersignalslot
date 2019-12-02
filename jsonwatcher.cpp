#include "jsonwatcher.h"


void JSONWatcher::handleFileChanged(const QString& change)
{
    static bool test {false};

    test ^= 1;
    setStatusTest(test);

    qDebug() << "mudanca";
}

JSONWatcher::JSONWatcher(QObject *parent) : QObject(parent)
{
    watcher.addPath("/home/fernando/Documentos/teste.json");

    QObject::connect(&watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(handleFileChanged(const QString&)));
}

bool JSONWatcher::statusTest() const
{
    qDebug() << "status: " << m_statusTest;

    return m_statusTest;
}

void JSONWatcher::setStatusTest(bool statusTest)
{
    emit statusChanged();
    m_statusTest = statusTest;
}
