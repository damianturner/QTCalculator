#ifndef ENTEREVENTFILTER_H
#define ENTEREVENTFILTER_H

#include <QObject>

class EnterEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit EnterEventFilter(QObject *parent = 0);

signals:

public slots:
};

#endif // ENTEREVENTFILTER_H