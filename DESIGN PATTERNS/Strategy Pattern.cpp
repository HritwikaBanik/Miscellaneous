#include <iostream>
#include <memory>

class SortingStrategy {  //Interface 
public:
    virtual void sort() = 0;
    virtual ~SortingStrategy() {}
};

class QuickSort : public SortingStrategy {
public:
    void sort() override { std::cout << "Using QuickSort\n"; }
};

class MergeSort : public SortingStrategy {
public:
    void sort() override { std::cout << "Using MergeSort\n"; }
};

//strategy to interchange the choices
class Context {
private:
    std::unique_ptr<SortingStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<SortingStrategy> s) {
        strategy = std::move(s);
    }

    void execute() {
        if (strategy) strategy->sort();
        else std::cout << "No strategy set.\n";
    }
};


//client code
int main() {
    Context context;

    context.setStrategy(std::make_unique<QuickSort>());
    context.execute();

    context.setStrategy(std::make_unique<MergeSort>());
    context.execute();

    return 0;
}

/*
 Why is main() the client code?
Because:

The client is the consumer of the strategy pattern, i.e., the part of the program that:
Instantiates the Context
Sets the desired SortingStrategy
Calls the execute() function

It does not care about the internal details of how sorting is done—it just asks Context to "execute the strategy".
*/
