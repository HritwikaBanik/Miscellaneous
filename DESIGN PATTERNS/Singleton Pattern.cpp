#include <iostream>
#include <thread>
/*
Use When:
    ~You need centralized state or resource management.
    ~You want to limit creation to only one shared instance.

Key Ideas:
    `Private constructor
    `Static instance method
    `Prevents duplication (copy constructor deleted)
*/
class Singleton {
private:
    Singleton() {
        std::cout << "Singleton created\n";
    }

    // Prevent copy and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance; // Thread-safe in C++11+
        return instance;
    }

    void doSomething() {
        std::cout << "Using singleton instance\n";
    }
};


void useSingleton() {
    Singleton& s = Singleton::getInstance();
    s.doSomething();
}

int main() {
    std::thread t1(useSingleton);
    std::thread t2(useSingleton);
    std::thread t3(useSingleton);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/*
| Use Case              | Why Singleton?                             |
| --------------------- | ------------------------------------------ |
| Logger                | Only one logger needed across modules      |
| Configuration Manager | Centralized configuration loaded once      |
| Database Connection   | Only one DB handler to manage pool         |
| Thread Pool           | One shared pool to manage worker threads   |
| Cache Manager         | Shared cache used across system components |

*/