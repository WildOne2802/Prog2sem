//
// Created by Timur Oshnokov on 2019-05-06.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

class Vector2D{

private:
    double x,y;

public:
    Vector2D(double _x, double _y): x(_x), y(_y){}

    double len(){
        return sqrt(x * x + y * y);
    }

    bool operator ==(const Vector2D& b){
        return x == b.x && y == b.y;
    }

    string to_string(){
        ostringstream ss;
        ss << "Vector [" << x << ", " << y << "]";
        return ss.str();
    }

};

template<class C>

class Predicate {
public:
    bool operator()(C &collection, typename C::iterator it) = 0;
};

template<class C>

class Comparator{
public:
    int operator()(C &collection, typename C::iterator a, typename C::iterator b) = 0;
};

template <class T, class Condition>

bool any_of(T &collection, Condition parameter){
    for(typename T::iterator it = collection.begin(); it != collection.end(); it++){
        if(parameter(*it))
            return true;
    }
    return false;
}

template <class T, class Condition>

bool one_of(T &collection, Condition parameter){
    int z=0;
    for(typename T::iterator it = collection.begin(); it != collection.end(); it++){
        if(parameter(*it))
           z++;
    }
    return (z==1);
}


template <class T>

typename T::iterator find_not(T &collection, typename T::value_type val){
    for(typename T::iterator it = collection.begin(); it != collection.end(); it++){
        if(!(*it == val))
            return it;
    }

    return collection.end();
}

int main(){
    vector<int> v;

    v.push_back(2);

    v.push_back(5);

    v.push_back(10);

    cout << "Standart:" << endl
    << any_of(v, [](int i){ return i % 2 == 0; }) << endl
    << one_of(v, [](int a){ return a % 5 == 0; }) << endl
    << *find_not(v, 5) << endl<<endl;


    vector<Vector2D> p;
>
    p.push_back(Vector2D(0, 0));

    p.push_back(Vector2D(12, 12));

    p.push_back(Vector2D(2, 0));

    cout << "Custom:" << endl
    << any_of(p, [](Vector2D vec){return vec.len() == 0.0; }) << endl
    << one_of(p, [](Vector2D vec){return vec.len()== 2.0;}) << endl
    << find_not(p, Vector2D(0, 0))->to_string() << endl;

    return 0;
}
