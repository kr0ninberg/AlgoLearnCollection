#include <iostream>

struct CMTeller{
    static int counter;
    int id;
    
    CMTeller() : id(++counter) {
        std::cout << "CMTeller #" << id << " default ctor called" << std::endl;
    }
    
    CMTeller(const CMTeller &other) : id(++counter) {
        std::cout << "CMTeller #" << id << " copy ctor called (from #" << other.id << ")" << std::endl;
    }
    
    CMTeller(CMTeller &&other) noexcept : id(++counter) {
        std::cout << "CMTeller #" << id << " move ctor called (from #" << other.id << ")" << std::endl;
    }
    
    CMTeller& operator= (const CMTeller &other){
        std::cout << "CMTeller #" << id << " copy assignment called (from #" << other.id << ")" << std::endl;
        return *this;
    }
    
    CMTeller& operator= (CMTeller &&other) noexcept {
        std::cout << "CMTeller #" << id << " move assignment called (from #" << other.id << ")" << std::endl;
        return *this;
    }
    
    ~CMTeller(){
        std::cout << "CMTeller #" << id << " destructor called" << std::endl;
    }
};

int CMTeller::counter = 0;