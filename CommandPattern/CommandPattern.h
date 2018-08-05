//
// Created by xfc on 2018/8/4.
//

#ifndef DESIGNPATTERNS_COMMANDPATTERN_H
#define DESIGNPATTERNS_COMMANDPATTERN_H
/*
 * 命令模式
 * 将一个请求封装成一个对象，从而使你可用不同的请求对客户进行参数化：对请求排队或者记录请求日志，以及支持可撤销操作。
 * 命令模式的作用：
 * 1、比较容易设计一个命令队列
 * 2、命令记录日志
 * 3、接收方可决定是否接受这个命令
 * 4、对请求的撤销和重做
 * 5、方便增加新的命令类
 * 6、把请求一个操作的对象和知道怎么执行一个操作的对象分割开来了。
 */
#include <iostream>
class Receiver {
public:
    Receiver() = default;
    virtual ~Receiver() = default;

public:
    void action() {
        std::cout << "execute..." <<  std::endl;
    }
};

class Command {
public:
    explicit  Command(Receiver *receiver):receiver_(receiver){}
    virtual ~Command() = default;
    virtual void execute() = 0;
protected:
    Receiver *receiver_;
};

class ConcreteCommand :public Command {
public:
    explicit ConcreteCommand(Receiver *receiver):Command(receiver) {}
    ~ConcreteCommand() override = default;

public:
    void execute() override {
        receiver_->action();
    }
};

class Invoker {
public:
    Invoker() = default;
    virtual ~Invoker() = default;

public:
    void setCommand(Command *command) {
        command_ = command;
    }
    void execCommand() {
        command_->execute();
    }
private:
    Command *command_;
};
#endif //DESIGNPATTERNS_COMMANDPATTERN_H
