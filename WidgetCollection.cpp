#include "WidgetCollection.h"

#include <QtCore/QtPlugin>
#include "SliderEditInterface.h"
#include "QIntSliderEditInterface.h"

#ifdef QT5
#pragma comment(lib,"Qt5Designer")
#pragma comment(lib,"Qt5Core")
#pragma comment(lib,"Qt5Gui")
#pragma comment(lib,"Qt5Widgets")
#else

#ifdef _DEBUG
	#pragma comment(lib,"QtDesignerd4")
	#pragma comment(lib,"QtCored4")
	#pragma comment(lib,"QtGuid4")
#else
	#pragma comment(lib,"QtDesigner4")
	#pragma comment(lib,"QtCore4")
	#pragma comment(lib,"QtGui4")
#endif

#endif

 WidgetCollection::WidgetCollection(QObject *parent)
         : QObject(parent)
 {
     widgets.append(new QSliderEditInterface(this));
     widgets.append(new QIntSliderEditInterface(this));
 }

 QList<QDesignerCustomWidgetInterface*> WidgetCollection::customWidgets() const
 {
     return widgets;
 }

#ifndef QT5
Q_EXPORT_PLUGIN2(SimulQtWidgets, WidgetCollection)
#endif