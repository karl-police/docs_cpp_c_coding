# Pointers and Initialization

**Be careful!**

Be careful whenever creating a new _raw_ **pointer**

_e.g. like this_
```cpp
int* p_IntTest = new int(5);
```
This here will _allocate_ to the memory.


**See:**

* https://godbolt.org/z/WqnT8957Y
* https://godbolt.org/z/Wzn1WcPhs
<br>

* https://godbolt.org/z/7xPTYxWMx - To showcase raw pointers within structs and de-constructors
* https://godbolt.org/z/vjvn3aj49

<br>

Such pointers need to be **manually deleted**, or else it will result in a **Memory Leak**.

To delete you'd do this here below. **Just make sure it hasn't been deleted already**, otherwise it's gonna give a _"double free error"_.
```cpp
delete p_IntTest;

// Optionally, you can set it to nullptr
// https://stackoverflow.com/a/49509254/11161500
p_IntTest = nullptr;
```

However, in C++ there are very additional special pointers, e.g. [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)


Note on **godbolt** ``-fsanitize=address`` can hint on Memory Leaks. LeakSanitizer doesn't exist on Windows though.
But there are workarounds for it as well.

**Additionally:**

``-Wall -Wextra -Werror -Wpedantic``
or on Windows ``/W4``, I think.


<br>
<br>
<br>
