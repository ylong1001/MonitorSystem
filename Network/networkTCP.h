#ifndef NETWORKTCP_H
#define NETWORKTCP_H

#include <QThread>

class NetworkTCP : public QThread
{
    Q_OBJECT
public:
    explicit NetworkTCP(QObject *parent = 0);

signals:

public slots:

};

#endif // NETWORKTCP_H
