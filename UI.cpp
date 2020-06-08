#include "UI.h"

UI::UI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

     musicicon.addFile(":/back/yinfu.jpg");                 //背景音乐
     ui.musicButton->setIcon(musicicon);
     ui.musicButton->setIconSize(QSize(65,63));
     music.playmusic();
     isPause = false;

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
		//Icon* icon = (Icon*)sender();
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
		Icon* icon = (Icon*)sender();
		icon->setSwapping(false);
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
		source->setSwapping(true);
		source->swapWith(end);
		
        if (swapAndDelete(sourceRow, sourceCol, endRow, endCol)){
			sleep(350);
           do{
				DropUnit(10,10);  //逻辑重力下落
				RandomAdd(10,10);  //刷新地图
           }while(AutoDelete(10,10));  //当不可以再自动消除时，跳出循环
        }
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
	int col = icon->column;
	int row = icon->row;
	int x = 100 + col * ICON_WIDTH+ICON_WIDTH/2;
	int y = 100 + row * ICON_HEIGHT+ICON_HEIGHT/2;
	boomImage->setGeometry(QRect(x, y, 0, 0));
	boomImage->show();

	x -= ICON_WIDTH / 2;
	y -= ICON_HEIGHT / 2;
	int aniTime = 250;
	QPropertyAnimation* ani = new QPropertyAnimation(boomImage, "geometry");
	ani->setStartValue(boomImage->geometry());
	ani->setEndValue(QRect(x, y, ICON_WIDTH, ICON_HEIGHT));
	ani->setDuration(aniTime);
	ani->start();
	sleep(aniTime);
	icons[row][col]->setVisible(false);
	delete boomImage;
}

void UI::drop_tmp(int row, int col)
{
	int curRow = row-1;
	int dist = 1;
	int add = 1;
	while (curRow >= 0) {
		if (icons[curRow][col]->status == -1) {
			dist++;
			add++;
		}
		else {
			dist = 1;
		}
		icons[curRow][col]->drop(dist);
		swap(curRow, col, curRow + 1, col);
		curRow--;
	}
	for (int i = 0; i < add; i++) {
		int rand = helper.getRandomNum(5);
		icons[i][col]->refresh(rand);
	}
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column - 2; j++) {
			if (d[i][j].kind == d[i][j + 1].kind && d[i][j + 1].kind == d[i][j + 2].kind) {

				int newkind = rand() % 5;
				if (i == 0 || j == 0) {
					d[i][j].kind = newkind;
					continue;
				}
				while (newkind == d[i][j + 1].kind || newkind == d[i + 1][j].kind || newkind == d[i - 1][j].kind || newkind == d[i][j - 1].kind) {
					newkind = rand() % 5;
				}
				d[i][j].kind = newkind;
			}
		}
	}
	for (int i = 0; i < row - 2; i++) {
		for (int j = 0; j < column; j++) {
			if (d[i][j].kind == d[i + 1][j].kind && d[i + 1][j].kind == d[i + 2][j].kind) {
				int newkind = rand() % 5;
				if (i == 0 || j == 0) {
					d[i][j].kind = newkind;
					continue;
				}
				while (newkind == d[i][j + 1].kind || newkind == d[i + 1][j].kind || newkind == d[i - 1][j].kind || newkind == d[i][j - 1].kind) {
					newkind = rand() % 5;
				}
				d[i][j].kind = newkind;
			}
		}
	}
	//check four borders
	for (int i = 1; i < row - 2; i++) {					//need to change if row does not equal to column
		if (d[0][i].kind == d[0][i - 1].kind && d[0][i].kind == d[0][i + 1].kind) {
			while (d[0][i].kind == d[0][i+1].kind) {
				d[0][i].kind = rand() % 5;
			}
		}
		int lastRow = row - 1;
		if (d[lastRow][i].kind == d[lastRow][i - 1].kind && d[lastRow][i].kind == d[lastRow][i + 1].kind) {
			while (d[lastRow][i].kind == d[lastRow][i + 1].kind) {
				d[lastRow][i].kind = rand() % 5;
			}
		}
		
		if (d[i][0].kind == d[i-1][0].kind && d[i][0].kind == d[i+1][0].kind) {
			while (d[i][0].kind == d[i+1][0].kind) {
				d[i][0].kind = rand() % 5;
			}
		}
		int lastCol = column - 1;
		if (d[i][lastCol].kind == d[i-1][lastCol].kind && d[i][lastCol].kind == d[i+1][lastCol].kind) {
			while (d[i][lastCol].kind == d[i+1][lastCol].kind) {
				d[i][lastCol].kind = rand() % 5;
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

bool UI::swapAndDelete(int row1, int column1, int row2, int column2) {
	int status1 = icons[row1][column1]->status;
	int status2 = icons[row2][column2]->status;
	icons[row1][column1]->status = status2;
	icons[row2][column2]->status = status1;
	
    //交换后有可消除的点，得到可消除的点并进行消除
    if (!helper.IsValid(icons, 10, 10)) {
		icons[row1][column1]->status = status1;
		icons[row2][column2]->status = status2;
		Icon* tmp = icons[row1][column1];
		icons[row1][column1] = icons[row2][column2];
		icons[row2][column2] = tmp;
        std::vector<Icon*> result1 = getPoints(row1, column1);  //获得交换以后(row1,col1)的可消除点

		std::vector<Icon*> result2 = getPoints(row2, column2);  //获得交换以后(row2,col2)的可消除点
		for (int i = 0; i < result1.size(); i++) {
			result1[i]->status = -1;
			iconExplode(result1[i]);
			//drop_tmp(result1[i]->row, result1[i]->column);
		}
		for (int i = 0; i < result2.size(); i++) {
			result2[i]->status = -1;
			iconExplode(result2[i]);
			//drop_tmp(result2[i]->row, result2[i]->column);
		}
        return true;
	}

    //交换后没有可消除的点，将原来的两个点交换回来
	else {
		qDebug() << "no explosion";
		icons[row1][column1]->status = status1;
		icons[row2][column2]->status = status2;
		
		icons[row1][column1]->setSwapping(true);
		icons[row2][column2]->setSwapping(true);
		icons[row1][column1]->swapWith(icons[row2][column2]);
		sleep(300);
		icons[row1][column1]->setSwapping(false);
		icons[row2][column2]->setSwapping(false);
        return false;
    }

}

void UI::swap(int row1, int column1, int row2, int column2){
    Icon* tmp = icons[row1][column1];
    icons[row1][column1] = icons[row2][column2];
    icons[row2][column2] = tmp;
    icons[row1][column1]->row = row1;
    icons[row1][column1]->column = column1;

    icons[row2][column2]->row = row2;
    icons[row2][column2]->column = column2;
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

/*
 *全图死局处理函数
 * 输入: Map的行列
 * 输出: 是否是死局（死局处理可以在本函数补充，也可以在函数外补充调用）
*/
bool UI::CheckMapDead(int row, int column){
    std::vector<Icon*>result = Hint(row,column);
    if (!result.size()){  //如果vector中没有元素说明当前是死局
                       /*

                         添加处理死图代码

                       */

        return true;
    }else{
                       /*

                         添加提示UI代码

                       */
        return false;  //否则不是死局
    }
}
/*
 * 提示逻辑函数，
 * 输入：Map的行列
 * 输出：vector 装有两个或0个Icon;
*/
std::vector<Icon*> UI:: Hint(int row,int column){ //
    std::vector<Icon*> result;
    Icon * tmp;  //中间指针;
    for(int i =0;i<row-1;i++){  //对每一个元素进行向下向右的交换
        for(int j = 0; j<column-1;j++){
            tmp =icons[i][j];  //向下交换
            icons[i][j] = icons[i-1][j];
            icons[i-1][j] = tmp;

            if(!helper.IsValid(icons,10,10)){//如果存在三连就
                icons[i-1][j] = icons[i][j];
                icons[i][j] = tmp;
                result.push_back(icons[i][j]);
                result.push_back(icons[i-1][j]);
                return result;
            }
            else{
                icons[i-1][j] = icons[i][j];
                icons[i][j] = tmp;
            }

            icons[i][j] = icons[i][j+1]; //向右交换
            icons[i][j+1] = tmp;
            if(!helper.IsValid(icons,10,10)){//如果存在三连就
                icons[i][j+1] = icons[i][j];
                icons[i][j] = tmp;
                result.push_back(icons[i][j]);
                result.push_back(icons[i-1][j]);
                return result;
            }
            else{
                icons[i][j+1] = icons[i][j];
                icons[i][j] = tmp;
            }
        }
    }
    return result;  //返回result
}
/*
 * DropUint函数
 * 输入:Map行列数;
 * 输出:true or false()
 * 功能:对每一列进行重力下落
*/
bool UI::DropUnit(int row,int column){
	bool isDroped = false;
	for (int i = 0; i < column; i++) {  //列数
		int count = 0;
		for (int j = row-1; j >=0; j--) {  //行数
			if (icons[j][i]->status != -1) {
				if (count != 0) {
					icons[j][i]->drop(count);
					swap(j, i, j + count, i);  //进行交换
					isDroped = true;  //标明发生了重力降落
				}
			}
			else {
				count++;
			}
		}
	}
	return isDroped;
}
void UI::RandomAdd(int row, int column){
	sleep(300);
	srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (icons[i][j]->status == -1) {
				int random = rand()%5;
				qDebug() << random;
				icons[i][j]->refresh(random);
			}
		}
	}
}
/*
 * AutoDelete函数
 * 输入:Map行列数;
 * 输出:true or false()
 * 功能:true表示发生了自动消除,下一步进行下落和补充生成,，false说明没有自动消除,跳出下落循环
*/
bool UI::AutoDelete(int row, int column){
    std::vector<Icon*> Point_Deleted;
        // 行检查是否有连续 3 个
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column - 2; ++j) {
                if (icons[i][j]->status ==icons[i][j+1]->status&& icons[i][j+1]->status==icons[i][j+2]->status){
                    Point_Deleted.push_back(icons[i][j]);
                    j = j+3; //跳过这三个
                }
            }
        }
        // 列检查是否有连续 3 个
        for (int j = 0; j < column; ++j) {
            for (int i = 0; i < row - 2; ++i) { //i为行数
                if (icons[i][j]->status == icons[i+1][j]->status&&icons[i+1][j]->status ==icons[i+2][j]->status){
                    Point_Deleted.push_back(icons[i][j]);
                    i = i+3; //跳过这三个
                 }
            }
        }
        // 如果没有找到这样的点，则证明没有被动产生消除
        if (Point_Deleted.size() == 0) return false;
        // 根据点获取消除点
        for (int i = 0; i < Point_Deleted.size(); ++i) {
            std::vector<Icon*> tempPoints = getPoints(Point_Deleted[i]->row, Point_Deleted[i]->column);
            for (int j =0;j <tempPoints.size();j++){
                tempPoints[j]->status = -1;  //设为删除状态
                iconExplode(tempPoints[j]);  //消除点爆炸
            }
        }
        return true;
}

void UI::freshMap(int row, int column)
{
	
}


void UI::sleep(int sleepTime)
{
	QTime time;
	time.start();
	while (time.elapsed() < sleepTime)             //等待时间流逝
		QCoreApplication::processEvents();
}

void UI::on_orderBtn_clicked()
{

	v->show();

}

void UI::on_musicButton_clicked()
{
    if(isPause == false){
        isPause = true;
        music.pausemusic();
        musicicon.addFile(":/back/yinfu2.jpg");
        ui.musicButton->setIcon(musicicon);
    } else {
        isPause = false;
        music.continuemusic();
        musicicon.addFile(":/back/yinfu.jpg");
        ui.musicButton->setIcon(musicicon);
    }
}
