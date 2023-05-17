#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(n), age(a) {}
    virtual ~Person() {}
    virtual void printInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Father : virtual public Person {
protected:
    std::string occupation;
public:
    Father(std::string n, int a, std::string o) : Person(n, a), occupation(o) {}
    virtual ~Father() {}
    virtual void printInfo() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Occupation: " << occupation << std::endl;
    }
};

class Mother : virtual public Person {
protected:
    std::string hobby;
public:
    Mother(std::string n, int a, std::string h) : Person(n, a), hobby(h) {}
    virtual ~Mother() {}
    virtual void printInfo() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Hobby: " << hobby << std::endl;
    }
};

class Son : public Father, public Mother {
public:
    Son(std::string n, int a, std::string o, std::string h) : Person(n, a), Father(n, a, o), Mother(n, a, h) {}
    virtual ~Son() {}
    virtual void printInfo() const override {
        std::cout << "Name: " << name << ", Age: " << age << ", Occupation: " << occupation << ", Hobby: " << hobby << std::endl;
    }
};

int main() {
    Son john("John", 10, "Engineer", "Reading");
    john.printInfo();
    return 0;
}
