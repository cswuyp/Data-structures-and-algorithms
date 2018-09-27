/*我们有一个设计策略，就是从Point2d派生出一个Point3d，于是Point3d将继承x和y坐标的一切（包括数据实例和操作方法）。
带来的影响则是可以共享“数据本身”以及“数据的处理方法”，并将之局部化。一般而言，具体继承（concrete inheritance,
译注：相对于虚继承virtual inheritance）并不会增加空间或存取时间上的额外负担。*/
class Point2d
{
public:
	Point2d(float x=0.0,float y=0.0):_x(x),_y(y){};
	float x(){return x;}
	float y(){return y;}
	
	void x(float newX)
	{
		_x=newX;
	}
	void y(float newY)
	{
		_y=newY;
	}
	
	void operator+=(const Point2d& rhs)
	{
		_x+=rhs.x();
		_y+=rhs.y();
	}
	
protected:
	float _x,_y;
};


//inheritance from concrete class
class Point3d:public Point2d
{
public:
	Point3d(float x=0.0,float y=0.0,float z=0.0):Point2d(x,y),_z(z){};
	float z(){return z;}
	void z(float newZ)
	{
		_z=newZ;
	}
	
	void operator+=(const Point3d& rhs)
	{
		Point2d::operator+=(rhs);
		_z+=rhs.z();
	}
	
protected:
	float _z;
};