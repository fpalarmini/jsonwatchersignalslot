#ifndef JSONWATCHER_H
#define JSONWATCHER_H

#include <QObject>
#include <QDebug>
#include <QFileSystemWatcher>

class JSONWatcher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool statusTest READ statusTest WRITE setStatusTest NOTIFY statusChanged)
    //Q_PROPERTY(QString updateState READ updateState WRITE setUpdateState NOTIFY notifyUpdatingChanged)

public:
    explicit JSONWatcher(QObject *parent = nullptr);

    bool statusTest() const;
    void setStatusTest(bool statusTest);

private:
    bool m_statusTest {false};
    QFileSystemWatcher watcher;
signals:
    void statusChanged();

public slots:
    void handleFileChanged(const QString &change);

};

#endif // JSONWATCHER_H
