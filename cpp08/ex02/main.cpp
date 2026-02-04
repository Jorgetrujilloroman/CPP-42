#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
    std::cout << "* MutantStack Test (Subject) *" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);

    std::cout << "\n* std::list Comparison Test *" << std::endl;
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << mlist.back() << std::endl; // Similar a top()
    
    mlist.pop_back();
    
    std::cout << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator it_l = mlist.begin();
    std::list<int>::iterator ite_l = mlist.end();
    
    ++it_l;
    --it_l;
    
    while (it_l != ite_l)
    {
        std::cout << *it_l << std::endl;
        ++it_l;
    }

    std::cout << "\n* Additional: Const Iterator Test *" << std::endl;
    const MutantStack<int> const_stack(mstack);
    MutantStack<int>::const_iterator cit = const_stack.begin();
    MutantStack<int>::const_iterator cite = const_stack.end();
    
    while (cit != cite)
    {
        std::cout << "Const: " << *cit << std::endl;
        ++cit;
    }

    return 0;
}