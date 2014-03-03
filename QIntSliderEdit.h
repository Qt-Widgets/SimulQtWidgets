#ifndef QINTSLIDEREDIT_H
#define QINTSLIDEREDIT_H

#include <QWidget>
#include "../SimulQtWidgets/GeneratedFiles/ui_QIntSliderEdit.h"
#ifndef _LIB
	#if defined(SIMUL_QT_WIDGETS)
		#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_EXPORT
	#else
		#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_IMPORT
	#endif
#else
	#define SIMUL_QT_WIDGETS_EXPORT
#endif
#ifndef SIMUL_QT_WIDGETS
	#ifdef NDEBUG
		#pragma comment(lib,"SimulQtWidgets_MD")
	#else
		#pragma comment(lib,"SimulQtWidgets_MDd")
	#endif
#endif

class SIMUL_QT_WIDGETS_EXPORT QIntSliderEdit : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString title READ title WRITE setTitle DESIGNABLE true)
	Q_PROPERTY(int labelWidth READ labelWidth WRITE setLabelWidth DESIGNABLE true)
	Q_PROPERTY(int minimum READ minimum WRITE setMinimum DESIGNABLE true)
	Q_PROPERTY(int maximum READ maximum WRITE setMaximum DESIGNABLE true)
	Q_PROPERTY(QVariant value READ value WRITE setValue DESIGNABLE true)
	Q_PROPERTY(bool powerOfTwo READ powerOfTwo WRITE setPowerOfTwo DESIGNABLE true)
    Q_PROPERTY(Qt::Orientation orientation READ orientation WRITE setOrientation)
public:
	QIntSliderEdit(QWidget *parent = 0);
	~QIntSliderEdit();
	Qt::Orientation orientation()
	{
		return ui.slider->orientation();
	}
	void setOrientation(Qt::Orientation o);
	int labelWidth() const
	{
		return labelWidth_;
	}
	void setLabelWidth(int w);
	void setMinimum(int f);
	int minimum() const
	{
		return minimum_;
	}
	int maximum() const
	{
		return maximum_;
	}
	void setMaximum(int f);
	void setPowerOfTwo(bool l);
	bool powerOfTwo() const;
	void setValue(QVariant f);
	void setValue(QVariant f,bool single_valued);
	QVariant value() const
	{
		return value_;
	}
	void setTitle(QString f);
	QString title() const;
signals:
	void valueChanged();
public slots:
	void on_slider_sliderMoved(int);
	void on_slider_valueChanged(int);
	void on_lineEdit_editingFinished();
private:
	void updateSlider();
	Ui::QIntSliderEdit ui;
	int labelWidth_;
	int minimum_;
	int maximum_;
	int value_;
	bool power_of_two_;
};

#endif // QINTSLIDEREDIT_H
