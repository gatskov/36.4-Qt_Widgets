#include <QPaintEvent>
#include <QApplication>
#include <QSlider>
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QVBoxLayout>
#include <iostream>

class CircleIndicator : public QWidget
{
    Q_OBJECT

public:
    CircleIndicator() = default;
    CircleIndicator(QWidget* parent);
    void paintEvent(QPaintEvent* e) override;
    QSize minimumSizeHint() const override;
    void setGreen();
    void setYellow();
    void setRed();

public slots:
    void setValue(int value);


private:
    QPixmap greenCircle;
    QPixmap yellowCircle;
    QPixmap redCircle;
    QPixmap currentSprite;
};

CircleIndicator::CircleIndicator(QWidget* parent)
{

    setParent(parent);
    setToolTip("Indicator");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    greenCircle = QPixmap(":/GreenCircle.png");
    yellowCircle = QPixmap(":/YellowCircle.png");
    redCircle = QPixmap(":/RedCircle.png");
    currentSprite = greenCircle;
    setGeometry(currentSprite.rect());
}

void CircleIndicator::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), currentSprite);
}

QSize CircleIndicator::minimumSizeHint() const
{
    return QSize(100, 100);
}

void CircleIndicator::setGreen()
{
    currentSprite = greenCircle;
    update();
}

void CircleIndicator::setYellow()
{
    currentSprite = yellowCircle;
    update();
}

void CircleIndicator::setRed()
{
    currentSprite = redCircle;
    update();
}

void CircleIndicator::setValue(int value)
{
    if (value <= 33)
        setGreen();
    else if (value > 33 && value <= 66)
        setYellow();
    else
        setRed();

    update();
}


#include "main.moc"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto* qvBox = new QVBoxLayout(nullptr);
    auto* window = new QWidget();
    window->setFixedSize(240, 290);

    auto* circleIndicator = new CircleIndicator(window);
    circleIndicator->setFixedSize (200, 200);
    circleIndicator->move (20, 10);

    auto* slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->resize(200, 50);
    slider->move(20, 230);
    slider->setParent(window);

    qvBox->addWidget(window);
    window->show();

    QObject::connect(slider, &QSlider::valueChanged, circleIndicator, &CircleIndicator::setValue);

    return a.exec();
}
