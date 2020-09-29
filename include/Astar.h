#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED

#endif // ASTAR_H_INCLUDED
#pragma once

#include <vector>
#include <list>

const int kCost1=10; //直移一格消耗
const int kCost2=14; //斜移一格消耗

/** 方块点 **/
struct Point
{
	int x,y;        //点坐标，这里为了方便按照C++的数组来计算，x代表横排，y代表竖列
	int F,G,H;      //F=G+H
	Point *parent;  //parent的坐标，这里用到指针，简化代码

	Point(int _x,int _y):x(_x),y(_y),F(0),G(0),H(0),parent(NULL) {}  //变量初始化
};

/** A*算法对象类 **/
class Astar
{
public:
	void InitAstar(std::vector<std::vector<int>> &_maze);   //初始化地图
	std::list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);

private:
	Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);                 //★★★关键算法★★★
	std::vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;   //获取相邻格子坐标

	bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const;      //判断某点是否可以用于下一步判断
	Point *isInList(const std::list<Point *> &list, const Point *point) const;               //判断开启/关闭列表中是否包含某点
	Point *getLeastFpoint();    //从开启列表中返回F值最小的节点

	/*计算FGH值*/
	int calcG(Point *temp_start,Point *point);
	int calcH(Point *point,Point *end);
	int calcF(Point *point);
private:
	std::vector<std::vector<int>> maze; //地图
	std::list<Point *> openList;  //开启列表
	std::list<Point *> closeList; //关闭列表
};
