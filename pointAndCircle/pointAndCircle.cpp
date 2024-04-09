#include <iostream>

using namespace std;
//点类
class Point{
public:
	void setX(int x){ mX = x; }
	void setY(int y){ mY = y; }
	int getX(){ return mX; }
	int getY(){ return mY; }
private:
	int mX;
	int mY;
};

//圆类
class Circle{
public:
	void setP(int x,int y){
		mP.setX(x);
		mP.setY(y);
	}
	void setR(int r){ mR = r; }
	Point& getP(){ return mP; }
	int getR(){ return mR; }
	//判断点和圆的关系
	void IsPointInCircle(Point& point){
		int distance = (point.getX() - mP.getX()) * (point.getX() - mP.getX()) + (point.getY() - mP.getY()) * (point.getY() - mP.getY());
		int radius = mR * mR;
		if (distance < radius){
			cout << "Point(" << point.getX() << "," << point.getY() << ")在圆内!" << endl;
		}
		else if (distance > radius){
			cout << "Point(" << point.getX() << "," << point.getY() << ")在圆外!" << endl;
		}
		else{
			cout << "Point(" << point.getX() << "," << point.getY() << ")在圆上!" << endl;
		}
	}
private:
	Point mP; //圆心
	int mR; //半径
};

void test(){
	//实例化圆对象
	Circle circle;
	circle.setP(20, 20);
	circle.setR(5);
	//实例化点对象
	Point point;
	point.setX(25);
	point.setY(20);

	circle.IsPointInCircle(point);
}

int main(){

        test();
 	return 0;
}
