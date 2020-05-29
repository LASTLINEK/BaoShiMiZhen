#include "UI.h"

UI::UI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initIcons(10, 10);
	//⏲
	timer = new QTimer(this);
	initime = ui.lineEdit->text();
	m_time = initime.toInt();
	timer->start(1000);
	connect(timer, SIGNAL(timeout()), this, SLOT(timeUp()));
}
void UI::iconClicked() {
	if (iswait == false) {
		Icon* icon = (Icon*)sender();
		//icon->drop(2);
	}
	else {
		;
	}
}

void UI::iconReleased()
{
	if (iswait == false) {}
	else {
		;
	}
}
void UI::timeUp()//倒计时函数
{
	if (iswait == false) {
		--m_time;
		ui.progressBar->setValue(m_time / 3);
		ui.lineEdit->setText(QString::number(m_time));
		if (m_time == 0)
		{
			timer->stop();

		}
	}
	else {

	}
}

void UI::on_pushButton_clicked()//暂停
{
	if (iswait == false) {
		ui.pushButton->setText("继续");
		iswait = true;
		Wait.exec();
	}
	else {
		ui.pushButton->setText("暂停");
		iswait = false;
		Wait.exit();
	}
}
void UI::iconSwap(int dir)
{
	if (iswait == false) {
		Icon* source = (Icon*)sender();
		int sourceCol = source->column;
		int sourceRow = source->row;
		//source = icons[sourceRow][sourceCol];
		int endCol = sourceCol;
		int endRow = sourceRow;
		switch (dir) {
		case UP:
			endRow--;
			break;
		case DOWN:
			endRow++;
			break;
		case LEFT:
			endCol--;
			break;
		case RIGHT:
			endCol++;
			break;
		}
		Icon* end = icons[endRow][endCol];
		source->swapWith(end);
		swap(sourceRow, sourceCol, endRow, endCol);
	}
	else {
		;
	}
}

void UI::iconExplode(Icon* icon)
{
	QLabel* boomImage = new QLabel(ui.centralWidget);
	QPixmap pix(pixFileName[5]);
	boomImage->setPixmap(pix);
	boomImage->setScaledContents(true);
	int x = 100 + icon->column * ICON_WIDTH+ICON_WIDTH/2;
	int y = 100 + icon->row * ICON_HEIGHT+ICON_HEIGHT/2;
	qDebug() << icon->row << "row,col" << icon->column;
	boomImage->setGeometry(QRect(x, y, 0, 0));
	boomImage->show();

	x -= ICON_WIDTH / 2;
	y -= ICON_HEIGHT / 2;
	QPropertyAnimation* ani = new QPropertyAnimation(boomImage, "geometry");
	ani->setStartValue(boomImage->geometry());
	ani->setEndValue(QRect(x, y, ICON_WIDTH, ICON_HEIGHT));
	ani->setDuration(1000);
	ani->start();
}

void UI::initIcons(int row, int column)
{
	Data** d = new Data * [row];
	Data temp;
	temp.kind = 0;
	temp.x = 0;
	temp.y = 0;
	for (int i = 0; i < row; i++) {
		d[i] = new Data[column];
		for (int j = 0; j < column; j++) {
			d[i][j] = temp;
		}
	}
	icons = new Icon * *[row];
	srand((int)time(NULL));//@clh
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			d[i][j].kind = rand() % 5;
			d[i][j].y = 100 + i * ICON_HEIGHT;
			d[i][j].x = 100 + j * ICON_WIDTH;
		}
	}
	for (int i = 1; i < row - 2; i++) {
		
		for (int j = 1; j < column - 2; j++) {

			if (d[i][j].kind == d[i][j + 1].kind && d[i][j + 1].kind == d[i][j + 2].kind) {

				int newkind = rand() % 5;
				while (newkind == d[i][j + 1].kind || newkind == d[i + 1][j].kind || newkind == d[i - 1][j].kind || newkind == d[i][j - 1].kind) {
					newkind = rand() % 5;
				}
				d[i][j].kind = newkind;
			}

			if (d[i][j].kind == d[i + 1][j].kind && d[i + 1][j].kind == d[i + 2][j].kind) {
				int newkind = rand() % 5;
				while (newkind == d[i][j + 1].kind || newkind == d[i + 1][j].kind || newkind == d[i - 1][j].kind || newkind == d[i][j - 1].kind) {
					newkind = rand() % 5;
				}
				d[i][j].kind = newkind;
			}
		}
	}
			
	
	for (int i = 0; i < row; i++) {
		icons[i] = new Icon * [column];
		for (int j = 0; j < column; j++) {
			icons[i][j] = new Icon(ui.centralWidget, d[i][j]);
			icons[i][j]->row = i;
			icons[i][j]->column = j;
			connect(icons[i][j], SIGNAL(Clicked()), this, SLOT(iconClicked()));
			connect(icons[i][j], SIGNAL(Released()), this, SLOT(iconReleased()));
			connect(icons[i][j], SIGNAL(Swap(int)), this, SLOT(iconSwap(int)));
		}
	}

}


void UI::swap(int row1, int column1, int row2, int column2) {
	
	Icon* tmp = icons[row1][column1];//new Icon(ui.centralWidget, d);
	icons[row1][column1] = icons[row2][column2];
	icons[row2][column2] = tmp;
	if (!helper.IsValid(icons, 10, 10)) {
		std::vector<Icon*> result1 = getPoints(row1, column1);  //获得交换以后(row1,col1)的可消除点
		std::vector<Icon*> result2 = getPoints(row2, column2);  //获得交换以后(row2,col2)的可消除点
		for (int i = 0; i < result1.size(); i++) {
			result1[i]->status = -1;
			iconExplode(result1[i]);
			qDebug() << result1[i]->x() << "," << result1[i]->y();
		}
		for (int i = 0; i < result2.size(); i++) {
			result2[i]->status = -1;
			iconExplode(result2[i]);
			qDebug() << result2[i]->x() << "," << result2[i]->y();
		}
	}
	else {
		//icons[row1][column1]->swapWith(icons[row2][column2]);
		icons[row2][column2] = icons[row1][column1];
		icons[row1][column1] = tmp;
	}
}

std::vector<Icon*> UI::getPoints(int row, int column) {
	std::vector<Icon*> horPoints, verPoints;
	int  status = icons[row][column]->status;
	//向四方向遍历
	for (int left = column - 1; left >= 0; --left) {
		if (icons[row][left]->status == status)
			horPoints.push_back(icons[row][left]);
		else { break; }
	}

	for (int right = column + 1; right < 10; ++right) {
		if (icons[row][right]->status == status)
			horPoints.push_back(icons[row][right]);
		else { break; }
	}

	for (int up = row - 1; up >= 0; --up) {
		if (icons[up][column]->status == status)
			verPoints.push_back(icons[up][column]);
		else { break; }
	}

	for (int down = row + 1; down < 10; ++down) {
		if (icons[down][column]->status == status)
			verPoints.push_back(icons[down][column]);
		else { break; }
	}

	if (horPoints.size() < 2) horPoints.clear();
	if (verPoints.size() < 2) verPoints.clear();

	std::vector<Icon*> results;
	for (auto h = horPoints.begin(); h < horPoints.end(); ++h)
		results.push_back(*h);
	for (auto v = verPoints.begin(); v < verPoints.end(); ++v)
		results.push_back(*v);
	if (horPoints.size() >= 2 || verPoints.size() >= 2)
		results.push_back(icons[row][column]);
	
	return results;
}

void UI::sleep(int sleepTime)
{
	QTime time;
	time.start();
	while (time.elapsed() < 5000)             //等待时间流逝5秒钟
		QCoreApplication::processEvents();
}

void UI::on_orderBtn_clicked()
{
    v->show();
}
