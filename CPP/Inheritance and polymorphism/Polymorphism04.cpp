//  Created by 汪潇翔 on 15/8/20.
//  Copyright (c) 2015年 汪潇翔. All rights reserved.
//

#include <iostream>
using namespace std;

class Plane {
public:
    /*
     *  滑行
     *
     *  return  如果返回不是1代表失败。
     */
    virtual int slide() = 0;

    /*
     *  起飞
     *
     *  return  如果返回不是1代表失败。
     */
    virtual int take_of() = 0;

    /*
     *  起飞
     *
     *  return  如果返回不是1代表失败。
     */
    virtual int landing() = 0;
};


class Fighter:public Plane
{
public:
  /*
  开火
  */
  virtual void fire() = 0;
};

#pragma mark - Boeing747
class Boeing747:public Plane{
    static string Model;
public:
    int slide()
    {
        cout<<Boeing747::Model<<"===滑行"<<endl;
        return 1;
    }
    int take_of()
    {
        cout<<Boeing747::Model<<"===起飞"<<endl;
        return 1;
    }
    int landing()
    {
        cout<<Boeing747::Model<<"===降落"<<endl;
        return 1;
    }
};
string Boeing747::Model = "Boeing-747";

#pragma mark - LockheedMartinF117

class LockheedMartinF117:public Fighter {
    static string Model;
public:
    int slide()
    {
        cout<<LockheedMartinF117::Model<<"--->滑行"<<endl;
        return 1;
    }
    int take_of()
    {
        cout<<LockheedMartinF117::Model<<"--->起飞"<<endl;
        return 1;
    }
    int landing()
    {
        cout<<LockheedMartinF117::Model<<"--->降落"<<endl;
        return 1;
    }
    void fire()
    {
      cout<<LockheedMartinF117::Model<<"--->开火"<<endl;
    }
};

string LockheedMartinF117::Model = "Lockheed-F117A";

void show_plane(Plane* plane)
{
    plane->slide();
    plane->take_of();
    if (Fighter* fighter = dynamic_cast<Fighter*>(plane)) {
      fighter->fire();
    }
    plane->landing();
}

#pragma mark - main function
int main(int argc, const char * argv[])
{
    Boeing747 boeing747;
    LockheedMartinF117 F117A;

    show_plane(&boeing747);
    show_plane(&F117A);
    return 0;
}
