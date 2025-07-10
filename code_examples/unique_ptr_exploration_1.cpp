// https://godbolt.org/z/7njs4Kdx6

#include <iostream>
#include <memory>

int* makeNumber() {
    int* p_num = new int;
    *p_num = 123; // Pre-defined test value

    std::cout << "Created at address: " << p_num << std::endl;

    return p_num;
}


#define MACRO_checkAddressValue(a) checkAddressValue(a, #a, __LINE__)

void checkAddressValue(int* p, const char* name = "N/A", int line = -1) {
    printf("[Line: %d] Checking \"%s\":\n", line, name);
    printf("Check Address: %p \n", reinterpret_cast<void*>(p));
    printf("Check Value: %d \n", *p);
    printf("\n");
}



int main() {
    int* p_safeCheck = makeNumber();
    int* p_safeCheck2 = makeNumber();
    printf("\n");

    MACRO_checkAddressValue(p_safeCheck);

    printf("-- Going into test scope --\n");
    {
        std::unique_ptr<int> refNum(p_safeCheck);

        // Re-assigning the pointer like that deletes the previous assigned one
        refNum = std::unique_ptr<int>(p_safeCheck2);
        //refNum.reset(p_safeCheck2); // alternate way


        // If doing this would delete both when out of scope
        // Because both ptr would be defined within this scope.
        //std::unique_ptr<int> refNum2(p_safeCheck2);
        //refNum.swap(refNum2);


        // Already deleted if using the example at the top with re-assigning only
        MACRO_checkAddressValue(p_safeCheck);
        MACRO_checkAddressValue(p_safeCheck2);


        // Retrieve what it's actually pointing to
        printf("Currently in test scope\n");
        std::cout << "Address: " << refNum.get() << std::endl;
        std::cout << "Value: " << *refNum << std::endl;
        printf("\n");


        // This would prevent deletion.
        //refNum.release();

    } // Out of scope makes it delete itself


    // note that using after "free" is use after free vulnerability
    // -fsanitize=address to check?
    // -Wall -Werror -fsanitize=address
    // -Wall -Wextra -Werror -Wpedantic -fsanitize=address
    // /W4

    printf("-- Out of test scope --\n");

    MACRO_checkAddressValue(p_safeCheck);
    MACRO_checkAddressValue(p_safeCheck2);
}
