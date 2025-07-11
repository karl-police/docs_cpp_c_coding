# Smart Pointers

<sub>See also _<a>https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp</a>_</sub>
<br><br>

In modern C++, **Smart Pointers** are Pointers that have their own sort of memory management "technology", at cost of heap allocation. Depends, what kind of Smart Pointer, I guess.

This means that these smart pointers seem to know their scope and if they're unused, they should delete itself.

It's basically like initializing a _**raw pointer**_, except that it can call ``delete`` on its own.


## **[``std::unique_ptr``](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)**

``std::unique_ptr<T, Deleter (optional)>`` create a ``unique_ptr`` out of a class, with an optional custom Deleter, _e.g. if you wanted to log the deletions for debugging purposes_.

It also provides methods to swap pointers out and more. _See the C++ docs for more info._

See this **<a>https://godbolt.org/z/7njs4Kdx6</a>** which sort of shows a full comprehensive overview of ``std::unique_ptr`` itself alone.

See also https://godbolt.org/z/65Mvx876v and https://godbolt.org/z/7PsrYdWx7 for a sort of comparison for with and without ``std::unique_ptr``.


Additionally:

* https://godbolt.org/z/TG7j4PnGv
* https://godbolt.org/z/hcn8xdTjo and https://godbolt.org/z/WP7ae55qq
* https://godbolt.org/z/4Meo9zWej
* https://godbolt.org/z/zb5nneEzb
* https://godbolt.org/z/q7h8M7rzY

<br>

Also, see this for within structs:

* https://godbolt.org/z/vsKMh9oc5 and https://godbolt.org/z/jKaGv45Ks


## **[``std::shared_ptr``](https://en.cppreference.com/w/cpp/memory/shared_ptr.html)**


## **[``std::weak_ptr``](https://en.cppreference.com/w/cpp/memory/weak_ptr.html)**
