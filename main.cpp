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
    boolean rebellion;
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

    Operation rebel();
    
};

class City : public Town{
  private:
    int corps;
    int essential_supply;
    int life_rating;
  public:
    int getCorps(){return corps;}
    int getEssentialSupply(){return essential_supply;}
    int getLifeRating(){return life_rating;}
    void setCorps(int corps){this->corps = corps;}
    void setEssentialSupply(int essential_supply){this->essential_supply = essential_supply;}
    void setLifeRating(int life_rating){this->life_rating = life_rating;}
};

class Law{
  private:
    string text;
    string type;
  public:
    string getText(){return text;}
    string getType(){return type;}
    void setText(string text){this->text = text;}
    void setType(string type){this->type = type;}
};

//Prelim class decs to allow friend class decs
class Gov;
class Defense;
class Operation;

class Health{
  friend class Gov;
  friend class Operation;
  private:
    int health_rating;
    int med_stock;
    int h_money;
  public:
    int getHealthRating(){return health_rating;}
    int getMedStock(){return med_stock;}
    int getHealthMoney(){return h_money;}
    void setHealthRating(int health_rating){this->health_rating = health_rating;}
    void setMedStock(int med_stock){this->med_stock = med_stock;}
    void setHealthMoney(int h_money){this->h_money = h_money;}
    
    void enforceLaw(Law law);
};

class Econ{
  friend class Gov;
  private:
    int econ_rating;
    int econ_money;
    int gov_money;
    double tax_rate;
  public:
    int getEconRating(){return econ_rating;}
    int getEconMoney(){return econ_money;}
    int getGovMoney(){return gov_money;}
    double getTaxRate(){return tax_rate;}
    void setEconRating(int econ_rating){this->econ_rating = econ_rating;}
    void setEconMoney(int econ_money){this->econ_money = econ_money;}
    void setGovMoney(int gov_money){this->gov_money = gov_money;}
    void setTaxRate(double tax_rate){this->tax_rate = tax_rate;}

    void enforceLaw(Law law);
    void sendMoney(string);
};

class Defense{
  friend class Gov;
  friend class Operation;
  private:
    int troops;
    int equipment;
    int def_rating;
    int def_money;
  public:
    Operation deploy(Gov);
    void enforceLaw(Law law);
};

class Operation{
  friend class Defense;
  friend class Health;
  private:
    int members;
    int equipment;
    double progress;
    string objective;
    string name;
  public:
    int getMembers(){return members;}
    int getEquipment(){return equipment;}
    double getProgress(){return progress;}
    string getObjective(){return objective;}
    string getName(){return name;}
    void setMembers(int members){this->members = members;}
    void setEquipment(int equipment){this->equipment = equipment;}
    void setProgess(double progress){this->progress = progress;}
    void setObjective(string objective){this->objective = objective;}
    void setName(string name){this->name = name;}
};

class Gov{
  friend class Health;
  friend class Econ;
  friend class Defense;
  private:
    int money;
    double tax_rate;
    vector<Town> town_list;
    vector<City> city_list;
    string civ_name;
    vector<Law> laws;
  public:
    //getters/setters
    int getMoney(){return money;}
    double getTaxRate(){return tax_rate;}
    vector<Town> getTownList(){return town_list;}
    vector<City> getCityList(){return city_list;}
    string getCivName(){return civ_name;}
    vector<Law> getLaws(){return laws;}
    void setMoney(int money){this->money = money;}
    void setTaxRate(double tax_rate){this->tax_rate = tax_rate;}
    void addTown(Town town){town_list.push_back(town);}
    void addCity(City city){city_list.push_back(city);}
    void setCivName(string civ_name){this->civ_name = civ_name;}
    void addLaw(Law law){laws.push_back(law);}

    //functonal methods
    Law createLaw(string text);
    void passLaw(Law law);
    void declareEmergency();
    Operation declareWar(string objective);
};

int main() {
  
}
