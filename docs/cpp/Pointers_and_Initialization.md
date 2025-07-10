# Pointers and Initialization

**Be careful!**

Be careful whenever creating a new pointer, e.g. like that.

```cpp
int* p_IntTest = new int(5);
```

See:

* https://godbolt.org/z/WqnT8957Y
* https://godbolt.org/z/Wzn1WcPhs


Such pointers need to manually be deleted, or else it will result in a **Memory Leak**.

To delete you'd do ``delete p_IntTest``

However, in C++ there are very additional special pointers, e.g. [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)


Note on **godbolt** ``-fsanitize=address`` can hint on Memory Leaks. LeakSanitizer doesn't exist on Windows though.
But there are workarounds for it as well.

Additionally:

``-Wall -Wextra -Werror -Wpedantic``
or on Windows ``/W4``, I think.


<br>
<br>
<br>

# Smart Pointers
