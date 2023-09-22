#include <iostream>

using namespace std;

enum CPU_Rank {
    P1 = 1, P2, P3, P4, P5, P6, P7
};

//-----------------内容1------------------
class CPU {
private:
    CPU_Rank rank;
    int frequency;
    double voltage;
public:
    //构造函数
    CPU(CPU_Rank r, int f, double v) {
        rank = r;
        frequency = f;
        voltage = v;
        cout << "构造了一个CPU!" << endl;
    }

    //析构函数
    ~CPU() {
        cout << "析构了一个CPU!" << endl;
    }

    void run();

    void stop();
};

//-----------------内容2------------------
class RAM {
};

class CDROM {
};

class Computer {
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
public:
    Computer(CPU c, RAM r, CDROM cd) : cpu(c), ram(r), cdrom(cd) {
        cpu = c;
        ram = r;
        cdrom = cd;
        cout << "构造了一台电脑!" << endl;
    }

    ~Computer() {
        cout << "析构了一台电脑!" << endl;
    }

    void run() {
        cpu.run();
    }

    void stop() {
        cpu.stop();
    }
};



int main() {
    CPU cpu(P6, 300, 2.8);
    cpu.run();
    cpu.stop();
    Computer computer(cpu, RAM(), CDROM());
    computer.run();
    computer.stop();
    return 0;
}

void CPU::run() {
    cout << "CPU开始运行!" << endl;
}

void CPU::stop() {
    cout << "CPU停止运行!" << endl;
}