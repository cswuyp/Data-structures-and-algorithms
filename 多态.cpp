/*《深度探索C++对象模型》如果我要处理一个坐标点，而不打算在乎它是一个Point2d或Point3d实例，那么我需要在继承关系中提供
一个virtual function 接口。让我们看看如果这么做情况会有什么变化：*/
class Pint2d
{
public:
	Point2d(float x=0.0,float y=0.0):_x(x),_y(y){};
	float x(){return x;}
	float y(){return y;}
	
	void x(float newX){_x=newX;}
	void y(float newY){_y=newY;}
	//由于对不同维度的点，这些函数操作固定工不变，所以不必设计为virtual
	
	//加上z的保留空间（目前什么也没做）
	virtual float z()
	{
		return 0.0;
	}
	virtual void z(float){}
	
	//设定以下的运算符为virtual
	virtual void operator+=(const Point2d& rhs)
	{
		_x+=rhs.x();
		_y+=rhs.y();
	}
	
protected:
	float _x,_y;
};



//Point3d声明
class Point3d:public Point2d
{
public:
	Point3d(float x=0.0,float y=0.0,float z=0.0):Pint2d(x,y),_z(z){};
	float z(){return _z;}
	void z(float newZ)
	{
		_z=newZ;
	}
	
	void operator+=(const Point2d& rhs)
	{
		//注意上行是Point2d& 而非Point3d&
		Point2d::operator+=(rhs);
		_z+=rhs.z();//因为在Point2d中虚函数z()返回的值是0.0所以此时用Point2d&，如果用Point3d则rhs.z()是未知的
	}
protected:
	float _z;
}

/*上述的Point2d和Point3d声明，最大的一个好处是，你可以把operator+=运用在一个Point3d对象和一个Point2d对象身上：
Point2d p2d(2.1,2.2);
Point3d p3d(3.1,3.2,3.3);
p3d+=p2d;
得到的p3d新值将是(5.2,5.4,3.3)*/