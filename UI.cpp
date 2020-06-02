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
        if (swapAndDelete(sourceRow, sourceCol, endRow, endCol)){
            do{
            DropUnit(10,10);  //逻辑重力下落
            freshMap();  //刷新地图
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


bool UI::swapAndDelete(int row1, int column1, int row2, int column2) {
	
	Icon* tmp = icons[row1][column1];//new Icon(ui.centralWidget, d);
	icons[row1][column1] = icons[row2][column2];
	icons[row2][column2] = tmp;

    //交换后有可消除的点，得到可消除的点并进行消除
    if (!helper.IsValid(icons, 10, 10)) {
        //将Icon的属性修改
        icons[row1][column1]->row = row1;
        icons[row1][column1]->column = column1;
        icons[row2][column2]->row = row2;
        icons[row2][column2]->column = column2;

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
    //交换后没有可消除的点，将原来的两个点交换回来
	else {
		icons[row2][column2] = icons[row1][column1];
		icons[row1][column1] = tmp;
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
    bool isDroped =false;
    //每列向下遍历,把status为1的给冒泡上去;
    for(int i =0;i< column;i++){  //列数
        for (int j =1; j<row;j++){   //从上向下总共row-1个点需要冒泡，每次把一个点交换到顶部
            if(icons[j][i]->status ==-1&&icons[j-1][i]->status!= -1){
                isDroped =true;
                int count =j;  //count记录当前Icon的位置
                do {
                    swap(count,i, count - 1,i);
                } while (--count >= 1 && icons[count - 1][i]->status != -1);
            }
        }
    }
    return isDroped;
}
void UI::RandomAdd(int row, int column){
    for(int i = 0; i < row ;i ++){
        for(int j = 0; j< column; j++){
            if (icons[i][j]->status == -1){  //状态为-1时添加
                                             //未完成。
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
