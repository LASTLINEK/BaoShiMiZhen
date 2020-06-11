#include"number.h"

Number::Number(QWidget* parent, Number_Data n) :QLabel(parent) {

	this->setGeometry(n.x, n.y, NUMBER_WIDTH, NUMBER_HEIGHT);
	QPixmap pix_num(numberName[n.kind]);
	
	this->setPixmap(pix_num);
	this->setScaledContents(true);
	this->show();

	
		n_timer = new QTimer(this);
		n_timer->start(1000);
		connect(n_timer, SIGNAL(timeout()), this, SLOT(timeUp()));
	

}

void Number::timeUp() {

	n_timer->stop();
	delete this ;
}