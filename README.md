<!-------cpp02_Image-------->
<a name="readme-top"></a>
<p align="center">
	<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=0ABAB5&text=cpp02&fontAlign=50&fontAlignY=61&animation=fadeIn&fontColor=fcf3f2&fontSize=100" />
</p>

<!-------About-------->

## About

This is the third Module of C++. This module dives into operator overloading, ad-hoc polymorphism, and the Orthodox Canonical Form in C++.

----
<!-------Index-------->

## <a name="#index-0">Index</a>

<ul>
	<li><strong><a href="#1-orthodox-canonical-class-form" style="color:white">1. Orthodox Canonical Class form</a></strong></li>
	<li><strong><a href="#2-ad-hoc-polymorphism" style="color:white">2. Ad-hoc polymorphism</a></strong></li>
	<ul style="list-style-type:disc">
		<li><a href="#21-details-and-purpose"> 2.1. Details and Purpose</a></li>
	</ul>
	<li><strong><a href="#3-operator-overloading" style="color:white">3. Operator overloading</a></strong></li>
	<ul style="list-style-type:disc">
		<li><a href="#31-definition-and-purpose"> 3.1. Definition and Purpose</a></li>
	</ul>
	<li><strong><a href="#references" style="color:white">References</a></strong></li>
</ul>

----

# 1. Orthodox Canonical Class form

The **Orthodox Canonical Class Form (OCCF)** also known as the **Rule of Five**, which refers to a set of special member functions in C++ that a class should explicitly define when it manages **resources that require deep management**, such as dynamic memory, file handles, or other system-level resources. The OCCF ensures correct behavior for object copying, assignment, and destruction, safeguarding against issues like memory leaks, shallow copies, and double deletions.

### Definitions

A class that follows the Orthodox Canonical Class Form is a set of mandatory member functions that ensure your class behaves predictably, safely, and efficiently. It consists of:

1. Default constructor (`ClassName()`)
2. Copy constructor (`ClassName(const ClassName& other)`)
3. Copy assignment operator (`ClassName& operator=(const ClassName& rhs)`)
4. Destructor (`~ClassName()`)

> (Since C++11) Move constructor and move assignment operator

As Scott Meyers notes in _Effective C++_ (2005), "if you need to explicitly declare any one of the copy constructor, copy assignment operator, or destructor, you probably need to declare all three." With C++11 and beyond, the move operations complete this set, forming what is now often referred to as the Rule of Five.

### Breaking Down

1. Default Constructor (`ClassName()`)

* **Purpose**: Creates an object in a valid "empty" state.
* **Why?** Because sometimes you just need an object to exist before giving it real work.

Example:
```cpp
class Necromancer {
public:
    Necromancer() : _mana(100), _undeadArmy(nullptr) {} // Ready to raise the dead!
};
```

2. Copy Constructor (`ClassName(const ClassName& other)`)

* **Purpose:** Creates a deep copy of an existing object.
* **Why?** So you don’t end up with two wizards accidentally sharing the same spellbook (disaster!).

Example:

```cpp
Necromancer(const Necromancer& other) {
    _mana = other._mana;
    _undeadArmy = new Zombie[*other._undeadArmy]; // Deep copy, no sharing!
}
```

3. Copy Assignment Operator (`ClassName& operator=(const ClassName& rhs)`)

* **Purpose**: Safely replaces an object’s contents with another’s.
* **Why?** Because = should not cause apocalyptic memory leaks.

>[!TIP]
> Golden Rule: Check for self-assignment (`if (this == &rhs) return *this;`).

Example:

```cpp
Necromancer& operator=(const Necromancer& rhs) {
    if (this != &rhs) {
        delete[] _undeadArmy; // Clean up old army
        _mana = rhs._mana;
        _undeadArmy = new Zombie[*rhs._undeadArmy]; // Raise a new one
    }
    return *this;
}
```

4. Destructor (~ClassName())
* **Purpose**: Releases all resources (memory, files, etc.).
* **Why?** Because even necromancers must eventually rest in peace.

Example:

```cpp
~Necromancer() {
    delete[] _undeadArmy; // No zombie leaks allowed!
}
```

### What Happens If You Ignore This Form?
Well.... nothing exatcly haha but!! Important things to know about OCCF

* "Shallow Copy Hell" – Two objects point to the same memory. One deletes it, the other crashes trying to use it. 💥

* "Memory Leak Apocalypse" – Your program slowly consumes all RAM until the system weeps. 🏴‍☠️

* "Undefined Behavior" – The C++ gods punish you with bizarre, unpredictable bugs. 🔮


# 2. Ad-hoc polymorphism

**Polymorphism**, from the Greek “poly” (many) and “morph” (form), refers to the ability of a single interface or function to operate on different types of data. It is a core concept in both object-oriented and functional programming, enabling code generality, reusability, and extensibility.

There are three main categories of polymorphism in programming languages, as originally formalized by Christopher Strachey (1967):

### 1. Ad-hoc polymorphism

* A function or operator can be applied to arguments of different types, but each type requires a specific implementation.
* Commonly realized through function **overloading** and operator **overloading**.
* Compile-time resolution.

Example in C++:

```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```
In this case, `add` is polymorphic, but only within a finite set of explicitly defined types.

### 2. Parametric polymorphism
* A function or data type is written generically, so it can operate on any type without depending on the specific type.
* Enables generic programming (e.g., templates in C++ or generics in Java).

Example in C++:

```cpp
template <typename T>
T max(T a, T b) { return (a > b) ? a : b; }
```
One implementation works for any type `T` that supports `>`.

### 3. Subtype polymorphism (or inclusion polymorphism)
* An object of a derived class can be treated as if it were an object of its base class.
* Central to **object-oriented programming via virtual functions.**

Example in C++:

```cpp
class Shape { public: virtual void draw() = 0; };
class Circle : public Shape { public: void draw() override { /*...*/ } };
void render(Shape* s) { s->draw(); }
```

## 2.1. Details and Purpose

Ad-hoc polymorphism provides a mechanism for defining functions or operators with the same name that behave differently depending on the argument types. Its main characteristics:

 * Resolved at compile time (static dispatch).
 * Improves expressiveness and code readability.
 * Allows type-safe behavior specialization.

In C++, ad-hoc polymorphism includes:

* Function overloading — multiple functions with the same name and different signatures.
* Operator overloading — customizing behavior for operators like `+`, `==`, `[]`, etc.
Ad-hoc polymorphism contrasts with parametric polymorphism by requiring different implementations for each applicable type, rather than a single generic one.

### Theoretical Foundation
Term introduced by Strachey (1967) in his seminal lecture Fundamental Concepts in Programming Languages.

Further formalized in Milner’s Hindley-Milner type system, which distinguishes parametric polymorphism (e.g., in ML/Haskell) from ad-hoc.

# 3. Operator overloading
**Operator overloading** is a form of ad-hoc polymorphism that allows user-defined types (classes or structs) to redefine the behavior of standard operators (such as `+`, `==`, `[]`, etc.) when applied to instances of these types. It is a key feature of C++ that enables intuitive syntax for **domain-specific abstractions** (e.g., complex numbers, vectors, matrices) while maintaining type safety and readability

## 3.1. Definition and Purpose
In standard C++, operators are essentially syntactic sugar for function calls. Operator overloading allows programmers to define or redefine the semantics of operators for their own types. This mechanism:

* Enhances code expressiveness
* Provides natural and intuitive interfaces
* Supports encapsulation and abstraction
* Promotes maintainability in mathematical or algebraic domains

Only a subset of operators can be overloaded (e.g., arithmetic, comparison, logical, and dereference operators), and overloading **must respect the expected semantics to avoid confusion** and maintain logical coherence.

**Example: Overloading + for a Complex Number Class**
```cpp
class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload the '+' operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};
```
This allow expressions like:
```
Complex c1(2.0, 3.0), c2(1.0, -1.0);
Complex result = c1 + c2;
```
Without operator overloading, one would need to write `c1.add(c2)` or use a global function.

### Restrictions and Best Practices
* Operators must be either **member functions** or friend functions.
* Certain operators cannot be overloaded: `.:`, `.*`, `::`, `sizeof`, `typeid`, etc.
* Overloading should preserve **semantic clarity**; for example, `+` should not subtract or divide.
* Overloading should be avoided if it decreases **readability** or **predictability**.

### Operator Overloading vs. Function Overloading
While function overloading allows multiple functions of the same name with different parameter types, **operator overloading** provides a syntactic extension where the operator symbol is treated as a function name. For example:
```
Complex operator+(const Complex&, const Complex&); // Equivalent to a named function
```
In both cases, the polymorphism is ad-hoc and resolved at compile time.

### Theoretical Foundations
Operator overloading is a syntactic form of **ad-hoc polymorphism** (Strachey, 1967), allowing functions to be defined for specific types but sharing the same symbol or name. It extends **customizable binding** in type systems while remaining **statically typed**.


# References
* Meyers, Scott. Effective C++, 3rd ed. Addison-Wesley, 2005.
* Stroustrup, Bjarne. The C++ Programming Language, 4th ed. Addison-Wesley, 2013.
* ISO/IEC 14882:2011. Information Technology – Programming Languages – C++
* Strachey, C. (1967). Fundamental Concepts in Programming Languages. Higher-Order and Symbolic Computation, 13(1–2), 11–49.
* Cardelli, L., & Wegner, P. (1985). On Understanding Types, Data Abstraction, and Polymorphism. ACM Computing Surveys, 17(4), 471–522.
* Bjarne Stroustrup. The C++ Programming Language, 4th ed. Addison-Wesley, 2013.

### License

This work is published under the terms of <a href="https://github.com/lude-bri/42_Common_Core/blob/main/LICENSE.md">42 Unlicense</a>.

<p align="right">(<a href="#readme-top">get to top</a>)</p>

