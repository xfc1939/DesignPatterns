//
// Created by xfc on 2018/8/2.
//

#ifndef DESIGNPATTERNS_SINGLETONPATTERN_H
#define DESIGNPATTERNS_SINGLETONPATTERN_H
/*
 * 单例模式：保证一个类仅有一个示例，并提供一个访问它的全局访问点
 * 饿汉单例模式：在自己被加载时就将自己示例化了。
 * 懒汉单例模式：要在第一次引用时才会将自己实例化。
 */

#include <mutex>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
private:
    Singleton() = default;
    ~Singleton() = default;
};

// 多线程下的单例，在C++11标准下，使用static变量可以保证线程安全
/*
 * SingletonThreadSafe1 使用加锁的方式来保证线程安全
 * 该方法每次调用getInstance()都需要加锁和解锁，性能低下
 */
class SingletonThreadSafe1 {
public:
    static SingletonThreadSafe1 * getInstance() {
        static SingletonThreadSafe1 *instance = nullptr;
        mutex_.lock();
        if (instance == nullptr) {
            instance = new SingletonThreadSafe1();
        }
        mutex_.unlock();
        return instance;
    }
private:
    SingletonThreadSafe1() = default;
    ~SingletonThreadSafe1() = default;
    static std::mutex mutex_;
};

/*
 * SingletonThreadSafe2将解决上面这个问题
 */
class SingletonThreadSafe2 {
public:
    static SingletonThreadSafe2 * getInstance() {
        static SingletonThreadSafe2 *instance = nullptr;
        if (instance == nullptr) {
            mutex_.lock();
            // 增加这一层判断的原因：两个线程同时运行到了上面加锁的代码时：
            // 一个线程被锁住，而另外一个线程通过，然后创建出实例，等这个线程解锁，另外那个
            // 从阻塞中恢复的线程还会创建另外一个示例，这样其实是线程不安全的。
            if(instance == nullptr) {
                instance = new SingletonThreadSafe2();
            }
            mutex_.unlock();
        }
        return instance;
    }
private:
    SingletonThreadSafe2() = default;
    ~SingletonThreadSafe2() = default;
    static std::mutex mutex_;
};
#endif //DESIGNPATTERNS_SINGLETONPATTERN_H
