
#include "myhelper.h"

MyHelper::MyHelper()
{
}
int MyHelper::getRandomNum(int mod){ //mod为模，基于所选择的基本方块种类(难度)
        std::srand(time(NULL));
        int random = std::rand() % mod;
        return random;
}
/*void MyHelper::initial_RanMatrix(Icon *** Matrix,int row,int column,int mod){ //对输入的矩阵进行随机生成处理
    for(int i = 0;i<row;i++){
        for(int j =0;j<column;j++){
            int random = getRandomNum(mod);
            switch(random){
				
            case 0: Matrix[i][j]->status = random; break; //矩阵元素的样式 （待用枚举补充）
            case 1: Matrix[i][j]->status = random; break;
            case 2: Matrix[i][j]->status = random; break;
            case 3: Matrix[i][j]->status = random; break;
			case 4: Matrix[i][j]->status = random; break;
            }
        }
    }
}*/
bool MyHelper::IsValid(Icon *** Matrix, int row, int column){  //用于检验初始化所得矩阵是否合理（初始矩阵中是否已有三个相连）
    for(int i=0;i<row;i++){
        for(int j =0;j<column-2;j++){
            if(Matrix[i][j]->status ==Matrix[i][j+1]->status&&Matrix[i][j+1]->status==Matrix[i][j+2]->status) //判断一行上面是否有三个连续相同的单元
                return false;
        }
    }
    for(int i=0;i<row-2;i++){
        for(int j =0;j<column;j++){
            if(Matrix[i][j]->status ==Matrix[i+1][j]->status&&Matrix[i+1][j]->status==Matrix[i+2][j]->status) //判断一行上面是否有三个连续相同的单元
                return false;
        }
    }
    return true;
}
