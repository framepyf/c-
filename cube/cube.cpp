#include <iostream>
using namespace std;
//立方体类
class Cub{
public:
	void setL(int l){ mL = l; }
	void setW(int w){ mW = w; }
	void setH(int h){ mH = h; }
	int getL(){ return mL; }
	int getW(){ return mW; }
	int getH(){ return mH; }
	//立方体面积
	int caculateS(){ return (mL*mW + mL*mH + mW*mH) * 2; }
	//立方体体积
	int caculateV(){ return mL * mW * mH; }
	//成员方法
	bool CubCompare(Cub& c){
		if (getL() == c.getL() && getW() == c.getW() && getH() == c.getH()){
			return true;
		}
		return false;
	}
private:
	int mL; //长
	int mW; //宽
	int mH; //高
};

//比较两个立方体是否相等
bool CubCompare(Cub& c1, Cub& c2){
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()){
		return true;
	}
	return false;
}

void test(){
	Cub c1, c2;
	c1.setL(10);
	c1.setW(20);
	c1.setH(30);

	c2.setL(20);
	c2.setW(20);
	c2.setH(30);

	cout << "c1面积:" << c1.caculateS() << " 体积:" << c1.caculateV() << endl;
	cout << "c2面积:" << c2.caculateS() << " 体积:" << c2.caculateV() << endl;

	//比较两个立方体是否相等
	if (CubCompare(c1, c2)){
		cout << "c1和c2相等!" << endl;
	}
	else{
		cout << "c1和c2不相等!" << endl;
	}

	if (c1.CubCompare(c2)){
		cout << "c1和c2相等!" << endl;
	}
	else{
		cout << "c1和c2不相等!" << endl;
	}
}

int main(){
 
  test();
  return 0;
}
