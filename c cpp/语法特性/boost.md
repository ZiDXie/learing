# Boost.Function 详解

`boost::function` 是 Boost 库中提供的一个通用函数包装器，它可以存储、复制和调用任意可调用对象（函数、函数指针、成员函数、函数对象等）。它类似于 C++11 标准库中的 `std::function`。

## 基本用法

```cpp
#include <boost/function.hpp>
#include <iostream>

// 普通函数
int add(int a, int b) {
    return a + b;
}

// 函数对象
struct multiply {
    int operator()(int a, int b) const {
        return a * b;
    }
};

int main() {
    // 声明一个可以接受两个int参数并返回int的function
    boost::function<int(int, int)> func;

    // 包装普通函数
    func = &add;
    std::cout << "Add: " << func(2, 3) << std::endl;  // 输出 5

    // 包装函数对象
    func = multiply();
    std::cout << "Multiply: " << func(2, 3) << std::endl;  // 输出 6

    // 包装lambda表达式
    func = [](int a, int b) { return a - b; };
    std::cout << "Subtract: " << func(5, 3) << std::endl;  // 输出 2

    return 0;
}
```

## 主要特性

1. **类型安全**：`boost::function` 提供了类型安全的函数包装
2. **空状态检查**：可以检查是否包含有效函数
3. **多态性**：可以存储多种类型的可调用对象

## 常用操作

```cpp
boost::function<void(int)> f;

// 检查是否包含有效函数
if (f) {
    f(42);  // 调用
} else {
    std::cout << "No function assigned" << std::endl;
}

// 清空函数
f.clear();  // 或 f = 0;

// 比较空状态
if (!f) {
    std::cout << "Function is empty" << std::endl;
}
```

## 绑定成员函数

```cpp
#include <boost/bind.hpp>

class MyClass {
public:
    void print(int x) {
        std::cout << "Value: " << x << std::endl;
    }
};

int main() {
    MyClass obj;

    // 绑定成员函数
    boost::function<void(int)> f = boost::bind(&MyClass::print, &obj, _1);
    f(42);  // 输出: Value: 42

    return 0;
}
```

## 与标准库的兼容性

如果你使用 C++11 或更高版本，可以考虑使用标准库中的 `std::function`，它的接口与 `boost::function` 非常相似：

```cpp
#include <functional>  // C++11标准库

std::function<int(int, int)> std_func = add;
```

## 性能考虑

`boost::function` 使用类型擦除技术，会有一定的性能开销：

- 比直接调用函数慢
- 比虚函数调用快
- 通常适用于回调机制、事件处理等不需要极致性能的场景

## 实际应用示例

```cpp
#include <boost/function.hpp>
#include <vector>

// 回调函数示例
class Button {
public:
    boost::function<void()> onClick;

    void click() {
        if (onClick) {
            onClick();
        }
    }
};

void sayHello() {
    std::cout << "Hello!" << std::endl;
}

int main() {
    Button btn;
    btn.onClick = &sayHello;
    btn.click();  // 输出: Hello!

    // 使用lambda
    btn.onClick = []() { std::cout << "Button clicked!" << std::endl; };
    btn.click();  // 输出: Button clicked!

    return 0;
}
```

`boost::function` 是 Boost 库中非常有用的组件，特别适合需要灵活回调机制的场景。
