#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class Mushroom
{
public:
    string common_name_;
    string science_name_;
    int quantity_;
    int total_value_;
    int value_;
    bool SortByValue(const Mushroom &lhs, const Mushroom &rhs);
    //Mushroom(string common_name, string science_name, int quantity, int total_value);
};

/*Mushroom::Mushroom()
{
    string common_name_ = common_name;
    string science_name_ = science_name;
    int quantity_ = quantity;
    int total_value_ = total_value;
    int value_ = total_value / quantity; //sets the objective value of the mushroom
}*/

class Graph
{
public:
    int basket_size;
    vector <Mushroom> mushrooms; //stores all mushrooms collected
    vector <Mushroom> basket; //stores the most mushrooms possible of the highest value
    void AddMushroom(string common_name, string science_name, int quantity, int total_value);
    void FillBasket();
    void Output();

};

void Graph::AddMushroom(string common_name, string science_name, int quantity, int total_value)
{
    Mushroom* newMushroom = new Mushroom;
    newMushroom->common_name_ = common_name;
    newMushroom->science_name_= science_name;
    newMushroom->quantity_ = quantity;
    newMushroom->total_value_ = total_value;
    newMushroom->value_ = total_value / quantity;
    mushrooms.push_back(*newMushroom);
}

bool SortByValue(const Mushroom &lhs, const Mushroom &rhs)
{
    return lhs.value_ < rhs.value_;
}

void Graph::FillBasket()
{
    cout << "test" << endl;
    sort(mushrooms.begin(), mushrooms.end(), SortByValue);
    int loop_iter = 0;
    int weight_iter = 0;
    while(weight_iter < basket_size)
    {
        basket.push_back(mushrooms[loop_iter]);
        cout << basket[loop_iter].common_name_ << endl;
        cout << weight_iter << endl;
        weight_iter = weight_iter + (mushrooms[loop_iter].quantity_);
        loop_iter++;
    }
}

void Graph::Output()
{
    for (int i = 0; i < basket.size()+1; i++)
    {
        cout << basket[i].quantity_ << " ounces of " << basket[i].common_name_ << " (" << basket[i].science_name_ << ") mushrooms" << endl;
    }
}
int main()
{
    ifstream fin;
    string the_word;
    fin.open("input1.csv");
    //while (!fin.eof()){
      //  getline(fin,the_word);
    //}

    Graph mygraph;
    mygraph.basket_size = 100;
    mygraph.AddMushroom("maitake", "Grifola frondosa", 5, 50);
    mygraph.AddMushroom("shiitake", "Lentinula edodes", 10, 60);
    mygraph.AddMushroom("oyster", "Pleuratus ostreatus", 12, 60);
    mygraph.AddMushroom("shaggy mane", "Coprinus comatus", 20, 120);
    mygraph.FillBasket();
    mygraph.Output();
}
