#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Classes
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
    int getRebelStatus(){return rebellion;}

    void setName(string name){this->name = name;}
    void setPop(int pop){population = pop;}
    void setMoney(int money){this->money = money;}
    void setShops(int shops){this->shops = shops;}
    void setEcon(int econ){econ_rating = econ;}
    void setJoy()(int joy){this->joy = joy;}
    void setRebelStatus(boolean rebellion){this->rebellion = rebellion;}

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
    string name;
  public:
    string getText(){return text;}
    string getName(){return name;}
    void setText(string text){this->text = text;}
    void setName(string name){this->name = name;}
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
    int getTroops(){return troops;}
    int getEquipment(){return equipment;}
    int getDefenseRating(){return def_rating;}
    int getDefenseMoney(){return def_money;}
    void setTroops(int troops){this->troops = troops;}
    void setEquipment(int equipment){this->equipment = equipment;}
    void setDefenseRating(int def_rating){this->def_rating = def_rating;}
    void setDefenseMoney(int def_money){this->def_money = def_money;}

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
    vector<Town> town_list;
    vector<City> city_list;
    string civ_name;
    vector<Law> laws;
    Econ econ;
    Health health;
    Defense defense;
    boolean war_status;
  public:
    //getters/setters
    vector<Town> getTownList(){return town_list;}
    vector<City> getCityList(){return city_list;}
    string getCivName(){return civ_name;}
    vector<Law> getLaws(){return laws;}
    Econ getEcon(){return Econ;}
    Health getHealth(){return Health;}
    Defense getDefense(){return Defense;}
    boolean getWarStatus(){return war_status;}
    void addTown(Town town){town_list.push_back(town);}
    void addCity(City city){city_list.push_back(city);}
    void setCivName(string civ_name){this->civ_name = civ_name;}
    void addLaw(Law law){laws.push_back(law);}
    void setEcon(Econ econ){this->econ = econ;}
    void setHealth(Health health){this->health = health;}
    void setDefense(Defense defense){this->defense = defense;}
    void setWarStatus(boolean war_status){this->war_status = war_status;}

    //Constructor
    Gov(string civ_name){
      this->civ_name = civ_name
      string[5] town_names = {"Alpha", "Beta", "Charlie", "Delta", "Echo"};
      for(int i = 0; i < 5; i++){
        Town town;
        town.setName(town_names[i]);
        town_list.push_back(town);
      }
      Econ econ;
      Health health;
      Defense defense;
      this->econ = econ;
      this->health = health;
      this->defense = defense;
    }

    //functonal methods
    void passLaw(Law law);
    void declareEmergency();
    Operation declareWar(string objective);
};

//Util/factory function prototypes
Town findTown(string, vector<Town>)
void displayGovData();
void displayDepartData(string);
void displayTownData(string);
void displayCityData( string);
void updateData();

//Global constants
const string[4] LAW_REF = {"boost troops", "boost equipment", "boost tax", "boost health", "emergency prep"};
const string[3] WAR_OBJ_REF = {"invade", "raid", "destroy"};
const string[9] actions = {"crt town", 
                            "prt town", 
                            "see town", 
                            "see city", 
                            "see department", 
                            "crt law",
                            "dec emergency",
                            "dec war", 
                            "pass law"};

int main() {
  //Init stage
  string civ_name;
  cout << "Enter civilization name: " << endl;
  cin >> civ_name;
  Gov user_gov(civ_name);

  //Game specific data
  string action;
  vector<Town> prt_list;
  vector<Gov> govs = {user_gov};

  //mainloop
  while(true){
    displayGovData();
    cout << "Enter action: " << endl;
    cin >> action;
    if(action == actions[0]){
      Town town;
      string town_name;
      cout << "Enter town name: " << endl;
      cin >> town_name;
      town.setName(town_name);
      user_gov.addTown(town);
    }

    else if(action == actions[1]){
      if(prt_list.size() > 0){
        cout << "Eligible towns: " << prt_list << endl;
        for(Town town : prt_list){
          cout << town.getName() << endl;
        }
        string town_name;
        cout << "Which town would you like to Promote?" << endl;
        cin >> town_name;
        if(findTown(town_name, prt_list) == null){
          cout << "Town not eligible" << endl;
        }
        else{
          City city;
          city.setName(town_name);
          user_gov.addCity(city);
        }
      }
      else{
        cout << "No towns can be promoted." << endl;
      }
    }

    else if(action == actions[2]){
      string town_name;
      string gov_name;
      cout << "Enter gov name: " << endl;
      cin >> gov_name;
      cout << "Enter town name: " << endl;
      cin >> town_name;
      for(Gov gov : auto_govs){
        if(gov.getCivName() == gov_name){
          displayTownData(gov, town_name);
        }
      }
    }

    else if(actions == actions[3]){
      string city_name;
      cout << "Enter city name: " << endl;
      cin >> city_name;
      for(Gov gov : auto_govs){
        if(gov.getCivName() == gov_name){
          displayCityData(gov, city_name);
        }
      }
    }

    else if(actions == actions[4]){
      string depart_name;
      cout << "Enter department name: " << endl;
      cin >> depart_name;
      for(Gov gov : auto_govs){
        if(gov.getCivName() == gov_name){
          displayDepartData(gov, depart_name);
        }
      }
    }

    else if(actions == actions[5]){
      string law_name;
      string law_text;
      cout << "Enter law name: " << endl;
      cin >> law_name;
      cout << "Law Text Options:" << endl;
      for(string text : LAW_REF){
        cout << "   - " << text << endl;
      }
      cout << "Enter law text: " << endl;
      cin >> law_text;
      Law law;
      law.setName(law_name);
      law.setText(law_text);
      user_gov.addLaw(law);
    }

    else if(actions == actions[6]){
      user_gov.declareEmergency();
    }

    else if(actions == actions[7]){
      string objective;
      cout << "War Objective Options: " << endl;
      for(string objective : WAR_OBJ_REF){
        cout << "   - " << objective << endl;
      }
      Operation operation = user_gov.declareWar(objective);
    }

    else if(actions == actions[8]){
      string law_name;
      cout << "Enter law name: " << endl;
      cin >> law_name;
      for(Law law : user_gov.getLaws()){
        if(law.getName() == law_name){
          user_gov.passLaw(law);
          break;
        }
      }
    }

    else{
      cout << "Invalid command" << endl;
    }
  }
}

//Returns Town object given its name
Town findTown(string town_name, vector<Town> town_list){
  for(Town town : town_list){
     if(town.getName() == town_name){
        return town;
     }
  }
  return null;
}

//Returns City object given its name
City findCity(string city_name, vector<City> city_list){
  for(City city : city_list){
     if(city.getName() == city_name){
        return city;
     }
  }
  return null;
}

//Displays Gov data - towns, cities, laws
void displayGovData(Gov gov){
  cout << "---GOV STATS---" << endl;
  cout << gov.getCivName() << endl;
  for(Law law : gov.getLaws()){
    cout << "   - LAW: " << law.getName();
  }
  for(Town town : gov.getTownList()){
    cout << "   - TOWN: " << town.getName();
  }
  for(City city : gov.getCityList()){
    cout << "   - CITY: " << city.getName();
  }
}

//Displays individual Town data - all Town attributes
void displayTownData(Gov gov, string town_name){
  Town town = findTown(town_name, gov.getTownList());
  cout << "---TOWN STATS---" << endl;
  cout << town.getName() << endl;
  cout << "   - Population: " << town.getPop() << endl;
  cout << "   - Money: " << town.getMoney() << endl;
  cout << "   - Shops: " << town.getShops() << endl;
  cout << "   - Econ Rating: " << town.getEconRating() << endl;
  cout << "   - Joy: "  << town.getJoy() << endl;
  cout << "   - Rebellion?: " << town.getRebelStatus() << endl; 
}

//Displays individual City data - all City attributes
void displayCityData(Gov gov, string city_name){
  City city = findCity(city_name, gov.getCityList());
  cout << city.getName() << endl;
  cout << "   - Population: " << city.getPop() << endl;
  cout << "   - Money: " << city.getMoney() << endl;
  cout << "   - Shops: " << city.getShops() << endl;
  cout << "   - Corps: " << city.getCorps() << endl;
  cout << "   - Econ Rating: " << city.getEconRating() << endl;
  cout << "   - Essential Supplies: " << city.getEssentialSupply() << endl;
  cout << "   - Health Rating: " << city.getHealthRating() << endl;
  cout << "   - Joy: "  << city.getJoy() << endl;
  cout << "   - Rebellion?: " << city.getRebelStatus() << endl;  
}

//Displays individual Department (Econ, Health, Defense) data - all Department attributes
void displayDepartData(Gov gov, string depart_name){
  if(depart_name == "econ"){
    cout << "---ECON STATS---" << endl;
    cout << gov.getCivName() << " Econ: " << endl;
    cout << "   - Econ Money: " << gov.getEcon().getEconMoney() << endl;
    cout << "   - Gov Money: " << gov..getEcon().getGovMoney() << endl;
    cout << "   - Tax Rate: " << gov..getEcon().getTaxRate() << endl;
    cout << "   - Econ Rating: " << gov.getEcon().getEconRating() << endl;
  }
  else if(depart_name == "health"){
    cout << "---HEALTH STATS---" << endl;
    cout << gov.getCivName() << " Health: " << endl;
    cout << "   - Med Stock: " << gov.getHealth().getMedStock() << endl;
    cout << "   - Health Money: " << gov.getHealth().getHealthMoney() << endl;
    cout << "   - Health Rating: " << gov.getHealth().getHealthRating() << endl;
  }
  else if(depart_name == "defense"){
    cout << "---DEFENSE STATS---" << endl;
    cout << gov.getCivName() << " Defense: " << endl;
    cout << "   - Troops: " << gov.getDefense().getTroops() << endl;
    cout << "   - Equipment: " << gov.getDefense().getEquipment() << endl;
    cout << "   - Defense Money: " << gov.getDefense().getDefenseMoney() << endl;
    cout << "   - Defense Rating: " << gov.getDefense().getDefenseRating() << endl;
  }
  else{
    cout << "Department doesn't exist" << endl;
  }
}

void updateData(Gov gov){
  
}