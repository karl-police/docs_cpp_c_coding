# Smart Pointers

<sub>_See also <a target="_blank">https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp</a>_</sub><br>
<sub>**Note:** _See also <a target="_blank">https://en.cppreference.com/book/intro/smart_pointers</a>_</sub>
<br><br>

In modern C++, **Smart Pointers** are Pointers that have their own sort of memory management "technology", at cost of heap allocation. Depends, what kind of Smart Pointer, I guess.

This means that these smart pointers seem to know their scope and if they're unused, they should delete the managed object and itself.
**Note** that the smart pointer is also an object and deletes itself as well. A ``unique_ptr`` can be re-used but will delete the managed object if the methods are used properly. _e.g. swapping_

It's basically like initializing a _**raw pointer**_, except that it can call ``delete`` on its own.


## **[``std::unique_ptr``](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)**

``std::unique_ptr<T, Deleter (optional)>``

Create a ``unique_ptr`` for a defined type ``T``, with an optional custom Deleter, _e.g. if you wanted to log the deletions for debugging purposes_.

It also provides methods to swap pointers out and more. _See the C++ docs for more info._

A ``unique_ptr`` can be created out of an already existing pointer or through ``std::make_unique``.

_See here what happens when you provide an already existing pointer: https://godbolt.org/z/WeG39GfzK_ ``.reset(nullptr)`` can be used, if one wanted to 

<br>
<br>

See this **<a>https://godbolt.org/z/7njs4Kdx6</a>** which sort of shows a full comprehensive overview of ``std::unique_ptr`` itself alone.

See also https://godbolt.org/z/65Mvx876v and https://godbolt.org/z/7PsrYdWx7 for a sort of comparison for with and without ``std::unique_ptr``.


Additionally:

* https://godbolt.org/z/TG7j4PnGv - _Showcasing that de-constructors get called when destroyed as well, like expected_
* https://godbolt.org/z/hcn8xdTjo and https://godbolt.org/z/WP7ae55qq
* https://godbolt.org/z/4Meo9zWej
* https://godbolt.org/z/zb5nneEzb
* https://godbolt.org/z/q7h8M7rzY
* https://godbolt.org/z/q68dfxh1d

<br>

Also, see this for within structs:

* https://godbolt.org/z/vsKMh9oc5 and https://godbolt.org/z/jKaGv45Ks


### **[``std::make_unique``](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique)**

``std::make_unique`` can be used to _directly_ intialize a ``std::unique_ptr``'s value with ``=``.

Note that, if you have **raw pointers** in a struct, that they are still due to manual memory management, unless replaced with a Smart Pointer.

Note that ``std::make_unique`` returns a ``std::unique_ptr``.

```cpp
std::unique_ptr<int> uniquePointer = std::make_unique<int>(123);
```

<sub>It's better like that, instead of passing it into the constructor of ``std::unique_ptr variable()`` itself. If you see it in any example code, don't mind it
but avoid actually doing that, I guess.</sub>

<br>

## **[``std::shared_ptr``](https://en.cppreference.com/w/cpp/memory/shared_ptr.html)**

Unlike ``std::unique_ptr``, **a ``std::shared_ptr`` will only delete the managed object, when there are no ``shared_ptr`` left which own that said object**.
This is why it's called **"shared"**, while **"unique"** is limited to own the same object once across all ``unique_ptr``, otherwise there may be unexpected issues.

<sub>See _https://godbolt.org/z/vsTE9cssG and https://godbolt.org/z/fjPMnYWcT_ for what would happen if more than one ``unique_ptr`` would initialize from the same pointer.</sub>

_See **https://godbolt.org/z/xd9Tz184n** and **https://godbolt.org/z/YMYGK6Wh9**._


``std::shared_ptr`` that own the same object, will obviously also point at the same address. Hence why a _"shared pointer"_.


### **[``std::make_shared``](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared.html)**

``std::make_shared`` is used to create a shared object that can be used by multiple ``std::shared_ptr``.

You should use ``std::make_shared`` for ``std::shared_ptr``. If ``std::shared_ptr`` is not in the same control block,
it may believe, that it is the sole owner and unexpectedly delete the object.

Note that ``std::make_shared`` returns a ``std::shared_ptr``.

```cpp
std::shared_ptr<int> sharedPointer = std::make_shared<int>(123);
```

<br>

## **[``std::weak_ptr``](https://en.cppreference.com/w/cpp/memory/weak_ptr.html)**

A ``std::weak_ptr`` is used to point to other ``std::shared_ptr`` without actually claiming ownership of one.

See **_https://godbolt.org/z/eGabaY1WG_**.

<br>

It's also used to break cycles, e.g. useful when having a "Node" that points to previous nodes.

For instance, you may want the **parent** Node to be a **"weak reference"**, and the child node a full ``std::shared_ptr``,
so that the Node owns the child object.

For instance, in a Folder structure, Folder A is in Folder B, and Folder B owns things inside of it.
However, Folder B is the parent of Folder A. Hence why Folder B **should not own** Folder A. Therefore a ``std::weak_ptr`` should be used.



<br><br>

## **[``std::move``](https://en.cppreference.com/w/cpp/utility/move.html)** with Smart Pointers

``std::move`` is also useful for non-copyable objects.

This here would make ``valuePtr`` not own an object when it gets moved to the other ``std::unique_ptr``.

```cpp
std::unique_ptr<int> valuePtr(new int(15));
std::unique_ptr<int> valuePtrNow(std::move(valuePtr));
```


See also:

* https://godbolt.org/z/f99Pq5vzP
* https://godbolt.org/z/vWeo7Toje
