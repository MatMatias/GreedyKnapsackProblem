#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
    public:
        string name;
        double weight;
        double value;
        double ratio;
        double weight_in = 0;

    Item(string _name)
    {
        name = _name;
    }
    
    void fill(double _weight, double _value)
    {
        weight = _weight;
        value = _value;
        ratio = value/weight;
        return;
    }

    bool operator<(Item& i) const
    {
        return (i.ratio < ratio);
    }

};

ostream& operator<<(ostream& stream, const Item& item)
{
    stream << item.name << ": quantity: " << item.weight_in << ", value: " << item.value;
    return stream;
}

void sort_by_ratio(vector<Item>& items_list)
{
    sort(items_list.begin(), items_list.end());
}

int main()
{

    string name;
    double weight_inp, value_inp;
    double max_capacity = 0;
    int items_num;

    cout << "Please insert the number of items to be considered: ";
    cin >> items_num;
    cout << endl;

    cout << "Please insert the max capacity: ";
    cin >> max_capacity;
    cout << endl;


    vector<Item> items_list;
    for(int i = 0; i < items_num; i++)
    {
        cout << "Please insert the name of the item: ";
        cin >> name;
        cout << "Please insert the weight and the value of the item " << i << " (on that order): ";
        cin >> weight_inp >> value_inp;

        Item item(name);
        item.fill(weight_inp, value_inp);
        items_list.push_back(item);
    }

    sort_by_ratio(items_list);

    vector<Item> container;
    double total_weight = 0;

    for(Item item : items_list)
    {
        if(item.weight + total_weight >= max_capacity)
        {
            item.weight_in = max_capacity - total_weight;
            total_weight += item.weight_in;
            container.push_back(item);
        }
        else
        {
            item.weight_in = item.weight;
            total_weight += item.weight_in;
            container.push_back(item);
        }
    }


    double total_value = 0;
    cout << "Items inside: " << endl;
    for(Item item: container)
    {
        total_value += (item.value/item.weight) * item.weight_in;
        cout << item << endl;
    }
    cout << "Total value inside: " << total_value << endl;

    return 0;
}