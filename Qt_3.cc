////////////////////////////////////////////////////////////////////////
//
//slider & spinbox
//
//sliderとspinboxの表示・layoutの使用方法
//sliderとspinboxの同期、初期値の設定
//
//QhBoxLayout-ウィジェットを左から右に配置する
//QVBoxLayout-ウィジェットを上から下に配置する
//QGridLayout-ウィジェットを格子上に配置する。
////////////////////////////////////////////////////////////////////////

#include    <QApplication>
#include    <QHBoxLayout>
#include    <QSlider>
#include    <QSpinBox>

int main(int argc , char *argv[])
{
    QApplication app(argc , argv);
    QWidget *window = new QWidget;
    window -> setWindowTitle("Enter your Age");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    
    spinBox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(
                    spinBox , SIGNAL(valueChanged(int)),
                    slider  , SLOT(setValue(int))
    );

    QObject::connect(
        slider , SIGNAL(valueChanged(int)),
        spinBox, SLOT(setValue(int))
    );

    spinBox -> setValue(23);

    QHBoxLayout *layout = new QHBoxLayout;
    layout -> addWidget(spinBox);
    layout -> addWidget(slider);
    window -> setLayout(layout);
    window -> show();
    return app.exec();


}
