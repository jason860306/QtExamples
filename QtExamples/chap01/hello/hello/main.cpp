#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

#if 0
class MySlot : public QObject
{
	Q_OBJECT

public:
	explicit MySlot(QObject *parent = NULL)
		: QObject(parent)
	{

	}

signals:

public slots:
};

class MySlotTest : public MySlot
{
	Q_OBJECT

public:
	MySlotTest(QLabel *pLabel = NULL, QObject *parent = NULL)
		: MySlot(parent)
	{
	}
	
	~MySlotTest()
	{
	}

private slots:
	void hide_show_label()
	{
		static int i = 0;
		if (0 == i++ % 2)
		{
			pLabel->hide();
		}
		else
		{
			pLabel->show();
		}
	}

private:
	QLabel *pLabel;
};
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QLabel *pLabel = new QLabel("<h2><i>hello</i> <font color=red>Qt!</font></h2>");
	pLabel->move(0, 0);
	pLabel->show();
	
	// MySlotTest mySlot(pLabel);

	QPushButton *button = new QPushButton("Quit");
	button->move(50, 50);
	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
	// QObject::connect(button, SIGNAL(clicked()), &mySlot, SLOT(hide_show_label()));
	button->show();

	QWidget *window = new QWidget();
	window->setWindowTitle("Enter Your Age");

	QSpinBox *spinBox = new QSpinBox();
	QSlider *slider = new QSlider(Qt::Horizontal);
	spinBox->setRange(0, 130);
	slider->setRange(0, 130);

	QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
	spinBox->setValue(35);

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(pLabel);
	layout->addWidget(button);
	layout->addWidget(spinBox);
	layout->addWidget(slider);

	window->setLayout(layout);

	window->show();

    return app.exec();
}
