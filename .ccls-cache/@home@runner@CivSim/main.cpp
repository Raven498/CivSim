#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Town{
  protected:
    string name;
    int population;
    int money;
    int shops;
    int econ_rating;
    int joy;

  public:
    string getName(){return name;}
    int getPop(){return population;}
    int getMoney(){return money;}
    int getShops(){return shops;}
    int getEcon(){return econ_rating;}
    int getJoy(){return joy;}

    void setName(string name){this->name = name;}
    void setPop(int pop){population = pop;}
    void setMoney(int money){this->money = money;}
    void setShops(int shops){this->shops = shops;}
    void setEcon(int econ){econ_rating = econ;}
    void setJoy()(int joy){this->joy = joy;}
    
};

class City{

};

class Gov{

};

class Health{

};

class Defense{

};

class Operation{

};

class Law{

};
int main() {
  
}
