#include "entereventfilter.h"

EnterEventFilter::EnterEventFilter(QObject *parent) : QObject(parent)
{
    if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_Return) {

            return true;
    } else {
            // standard event processing
            return QObject::eventFilter(obj, event);
    }
}
