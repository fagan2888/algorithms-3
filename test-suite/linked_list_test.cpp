#include<linked_list.hpp>

using namespace algorithms;

int main() {

    linkedList<double> L;
    L.add(2.0);
    L.add(4.6);
    L.push(3.0);
    L.push(4.5);
    std::cout << L;
    
    std::cout << std::endl;

    L.insert(19.0, 2);
    std::cout << L;

    return 0;
}
