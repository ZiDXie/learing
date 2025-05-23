在 C++ 中，`const` 是一个关键字，用于定义常量或指定某些内容不可修改。`const` 可以应用于变量、函数参数、函数返回值、成员函数以及指针等，具有多种用途。以下是 `const` 的主要用法和示例：

---

### 1. **常量变量**

用 `const` 修饰的变量是常量，其值在初始化后不能被修改。

#### 示例

```cpp
const int MAX_VALUE = 100;
// MAX_VALUE = 200; // 错误：常量不可修改
```

---

### 2. **常量指针和指针常量**

- **常量指针**：指针指向的内容不可修改，但指针本身可以修改。
- **指针常量**：指针本身不可修改，但指针指向的内容可以修改。
- **常量指针常量**：指针本身和指针指向的内容都不可修改。

#### 示例

```cpp
int a = 10;
int b = 20;

const int* ptr1 = &a; // 常量指针：指向的内容不可修改
// *ptr1 = 30;       // 错误：指向的内容不可修改
ptr1 = &b;           // 正确：指针本身可以修改

int* const ptr2 = &a; // 指针常量：指针本身不可修改
*ptr2 = 30;           // 正确：指向的内容可以修改
// ptr2 = &b;         // 错误：指针本身不可修改

const int* const ptr3 = &a; // 常量指针常量：指针和内容都不可修改
// *ptr3 = 40;              // 错误：指向的内容不可修改
// ptr3 = &b;               // 错误：指针本身不可修改
```

---

### 3. **常量函数参数**

用 `const` 修饰函数参数，表示参数在函数内部不可修改。

#### 示例

```cpp
void printValue(const int value) {
    // value = 10; // 错误：value 是常量，不可修改
    cout << value << endl;
}
```

---

### 4. **常量返回值**

用 `const` 修饰函数返回值，表示返回值是常量，不可修改。

#### 示例

```cpp
const int getValue() {
    return 42;
}

int main() {
    // getValue() = 10; // 错误：返回值是常量，不可修改
    return 0;
}
```

---

### 5. **常量成员函数**

用 `const` 修饰类的成员函数，表示该函数不会修改类的成员变量。

#### 示例

```cpp
class MyClass {
public:
    int value;

    void setValue(int v) {
        value = v;
    }

    int getValue() const { // 常量成员函数
        // value = 10; // 错误：常量成员函数不能修改成员变量
        return value;
    }
};

int main() {
    const MyClass obj;
    // obj.setValue(10); // 错误：常量对象只能调用常量成员函数
    cout << obj.getValue() << endl; // 正确：getValue 是常量成员函数
    return 0;
}
```

---

### 6. **常量对象**

用 `const` 修饰对象，表示该对象是常量，只能调用常量成员函数。

#### 示例

```cpp
class MyClass {
public:
    void nonConstFunc() {}
    void constFunc() const {}
};

int main() {
    const MyClass obj;
    // obj.nonConstFunc(); // 错误：常量对象不能调用非常量成员函数
    obj.constFunc();      // 正确：常量对象可以调用常量成员函数
    return 0;
}
```

---

### 7. **常量引用**

用 `const` 修饰引用，表示引用的内容不可修改。

#### 示例

```cpp
int a = 10;
const int& ref = a;
// ref = 20; // 错误：引用的内容不可修改
```

---

### 8. **常量表达式（C++11 引入）**

用 `constexpr` 修饰变量或函数，表示其值或返回值是编译时常量。

#### 示例

```cpp
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result = square(10); // 编译时常量
    return 0;
}
```

---

### 9. **`mutable` 关键字**

在类的常量成员函数中，用 `mutable` 修饰的成员变量可以被修改。

#### 示例

```cpp
class MyClass {
public:
    mutable int counter;

    void increment() const {
        counter++; // 正确：mutable 成员变量可以在常量成员函数中修改
    }
};
```

---

### 总结

- `const` 用于定义常量或指定不可修改的内容。
- 可以应用于变量、指针、函数参数、函数返回值、成员函数等。
- 常量对象只能调用常量成员函数。
- `const` 提高了代码的安全性和可读性，避免了意外的修改。

通过合理使用 `const`，可以编写出更加健壮和易于维护的 C++ 代码。