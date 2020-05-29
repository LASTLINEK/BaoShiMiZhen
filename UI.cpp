#include "UI.h"

UI::UI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ui.label->setVisible(1);
	initIcons(10, 10);
}
void UI::iconClicked() {
	Icon* icon = (Icon*)sender();
	//icon->drop(2);
}

void UI::iconReleased()
{
}

void UI::iconSwap(int dir)
{
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
	Icon* temp = end;
	icons[endRow][endCol] = source;
	icons[sourceRow][sourceCol] = temp;
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
	//Data d[row][column];
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
			qDebug() << i << "," << j;

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
			//icons[i][j]->iconkind = d[i][j].kind;
			connect(icons[i][j], SIGNAL(Clicked()), this, SLOT(iconClicked()));
			connect(icons[i][j], SIGNAL(Released()), this, SLOT(iconReleased()));
			connect(icons[i][j], SIGNAL(Swap(int)), this, SLOT(iconSwap(int)));
		}
	}

}


void UI::swap(int row1, int column1, int row2, int column2) {
	Data d;
	d.y = 100;
	d.kind = 0;
	d.x = 100;
	Icon* tmp = new Icon(ui.centralWidget, d);
	tmp = icons[row1][column1];
	icons[row1][column1] = icons[row2][column2];
	icons[row2][column2] = tmp;
	if (helper.IsValid(icons, 10, 10)) {
		std::vector<Icon*> result1 = getPoints(row1, column1);  //获得交换以后(row1,col1)的可消除点
		std::vector<Icon*> result2 = getPoints(row2, column2);  //获得交换以后(row2,col2)的可消除点
		for (int i = 0; i < result1.size(); i++) {
			result1[i]->status = -1;
		}
		for (int i = 0; i < result2.size(); i++) {
			result2[i]->status = -1;
		}
	}
	else {
		icons[row1][column1] = icons[row2][column2];
		icons[row2][column2] = tmp;
	}
}

std::vector<Icon*> UI::getPoints(int row, int column) {
	std::vector<Icon*> horPoints, verPoints;
	int  status = icons[row][column]->status;
	//向四方向遍历
	for (int left = column - 1; left >= 0; --left) {
		if (icons[row][left]->status == status)
			horPoints.push_back(icons[row][left]);
		else break;
	}

	for (int right = column + 1; right < 3; ++right) {
		if (icons[row][right]->status == status)
			horPoints.push_back(icons[row][right]);
		else break;
	}

	for (int up = row - 1; up >= 0; --up) {
		if (icons[up][column]->status == status)
			verPoints.push_back(icons[up][column]);
		else break;
	}

	for (int down = row + 1; down < 3; ++down) {
		if (icons[down][column]->status == status)
			verPoints.push_back(icons[down][column]);
		else break;
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
