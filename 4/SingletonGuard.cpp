#include <iostream>
#include <pthread.h>

// Guard class for managing mutex locks
class Guard {
private:
    pthread_mutex_t& mutex; // Reference to the mutex

public:
    // Constructor that locks the mutex
    explicit Guard(pthread_mutex_t& m) : mutex(m) {
        pthread_mutex_lock(&mutex); // Lock the mutex
    }
    
    // Destructor that unlocks the mutex
    ~Guard() {
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    
    // Prevent copying
    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;
};

// Singleton class definition
class Singleton {
protected:
    static pthread_mutex_t mutex; // Mutex for thread safety
    static Singleton* instance; // Pointer to the single instance

    // Private constructor to prevent instantiation
    Singleton() {}

public:
    // Method to access the single instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            Guard guard(mutex); // Lock to ensure thread safety
            if (instance == nullptr) { // Check again to ensure single instance
                instance = new Singleton();
            }
        }
        return instance; // Return the single instance
    }

    // Example method for demonstration
    void doSomething() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

    // Prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialize static members
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton* Singleton::instance = nullptr;

int main() {
    std::cout << "Classes defined successfully" << std::endl;

    // Get the single instance of Singleton
    Singleton* singletonInstance1 = Singleton::getInstance();
    Singleton* singletonInstance2 = Singleton::getInstance();
    
    // Use the Singleton instance
    singletonInstance1->doSomething(); // Calls the example method
    std::cout << "Are both instances the same? " << (singletonInstance1 == singletonInstance2) << std::endl;

    // Demonstrate usage of the Guard class
    pthread_mutex_t testMutex = PTHREAD_MUTEX_INITIALIZER;
    {
        Guard guard(testMutex); // Automatically locks the mutex
        // Critical section
        std::cout << "Guard is managing the mutex lock." << std::endl;
        // Mutex will be unlocked when guard goes out of scope
    }

    std::cout << "Guard has released the mutex." << std::endl;

    return 0;
}