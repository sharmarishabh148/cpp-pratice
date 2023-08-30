#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class ShallowCopyClass{
  public:
      int a;
      int b;
      ShallowCopyClass(int _a=0, int _b=1){a=_a; b=_b;}

      void show(){
      cout << "{a: " << a <<", b: "<<b <<"}"<<endl;}
};

class DeepCopyClass{
  public:
      int *a;
      int b;
      DeepCopyClass(int _b=1){b=_b/*could have been initializer list*/; a = new int[5];}
      DeepCopyClass(const DeepCopyClass &t){
            cout << "Copy constructor called " << endl;
            a = new int[5];
            // copy the data also from t.a
            memcpy (a, t.a, sizeof(t.a));
            b= t.b;

      }
      DeepCopyClass(DeepCopyClass&& t){
          cout << "Move constructor called " << endl;
          b = t.b;
          a = t.a;
          t.a = nullptr;

      }
      DeepCopyClass& operator=(DeepCopyClass&& t){
            cout << "Move assignment operator " << endl;
            if(this != &t){
                b = t.b;
                a = t.a;
                t.a = nullptr;
            }
            return *this;
      }
      DeepCopyClass& operator=(const DeepCopyClass &t){
            cout << "Assignment operator called " << endl;
            if(this != &t){ // check for self assignment
                *a = *(t.a);
                b  = t.b;
            }
            return *this;
      }

      void show(){
      cout << "{*a: " << a <<", b: "<<b <<"}"<<endl;}

      ~DeepCopyClass(){
          cout << "Destr called " << endl;
          delete a;
      }
};

int main(){
    {
    ShallowCopyClass ob1{1,2};
    ob1.show();
    cout << "Compiler will create Copy assignment operator " <<endl;
    cout << "Compiler will create Copy Constructor operator " <<endl;
    cout << "**C++11 will create Move Constructor and Move Assignment Operator" <<endl;

    ShallowCopyClass ob2=ob1;
    ob2.show();

    }
    {
    DeepCopyClass obj{5};
    obj.show();

    DeepCopyClass obj3=obj;
    obj3.show();

    cout << "*************************" <<endl;
    cout << "Move symantics" <<endl;
    cout << "*************************" <<endl;
    {
        std::vector<DeepCopyClass> v;
        //creating temporary objects;
        v.push_back(DeepCopyClass{190});
        v.push_back(DeepCopyClass{290});
    }
    cout << "*************************" <<endl;

    obj3 = std::move(obj);
    }
    return 0;
}
