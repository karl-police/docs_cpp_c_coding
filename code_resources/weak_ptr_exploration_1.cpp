#include <iostream>
#include <memory>

int main() {
    std::weak_ptr<int> weakPointer;

    {
        std::shared_ptr<int> sharedPointerInt = std::make_shared<int>(123);

        // Use count does not go up.
        weakPointer = sharedPointerInt;

        {
            // Use count goes up.
            auto test = sharedPointerInt;

            // Use count will also go up.
            auto test2 = weakPointer.lock();
            printf(".lock(): %d\n", *test2);

            printf("Use count: %d\n", sharedPointerInt.use_count());


            // Both objects point to the same pointer.
            printf("%p\n", test.get());
            printf("%p\n", test2.get());
        }


        printf("Use count: %d\n", sharedPointerInt.use_count());
        std::cout << "Result: " << *sharedPointerInt.get() << std::endl;
        printf("\n");

        
        // "0" means object is not expired, aka. "false"
        std::cout << "Expired?: " << weakPointer.expired() << "\n";
    }

    // "1" means object is expired.
    std::cout << "Expired?: " << weakPointer.expired() << "\n";
}
