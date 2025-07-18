#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Booking Conflict Checker");

    QVBoxLayout *layout = new QVBoxLayout();

    QLineEdit *startInput = new QLineEdit();
    startInput->setPlaceholderText("Start Time");
    QLineEdit *endInput = new QLineEdit();
    endInput->setPlaceholderText("End Time");

    QPushButton *addButton = new QPushButton("Add Booking");
    QLabel *resultLabel = new QLabel();
    QListWidget *bookingList = new QListWidget();

    layout->addWidget(startInput);
    layout->addWidget(endInput);
    layout->addWidget(addButton);
    layout->addWidget(resultLabel);
    layout->addWidget(bookingList);
    window.setLayout(layout);


    window.show();
    return app.exec();
}
