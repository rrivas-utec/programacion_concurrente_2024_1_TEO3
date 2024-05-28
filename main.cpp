#include <iostream>
#include <thread>

void tarea_1() {
    std::cout << "Tarea #1\n";
}

void tarea_2() {
    std::cout << "Tarea #2\n";
}

void ejemplo_1() {
    // Paso # 1
    std::thread t1;
    // Paso # 2
    t1 = std::thread(tarea_1);
    std::cout << "Ejemplo 1" << std::endl;
    // Paso # 3
    t1.join();
}
void ejemplo_2() {
    // Paso # 1 y 2
    std::thread t1(tarea_2);
    std::cout << "Ejemplo 2" << std::endl;
    // Paso # 3
    t1.join();
}

void ejemplo_3() {
    // Paso # 1 y 2
    std::thread t1([](){ std::cout << "tarea 3\n"; });
    std::cout << "Ejemplo 3" << std::endl;
    // Paso # 3
    t1.join();
}

void tarea(int n) {
    std::cout << "Hilo: " << n << std::endl;
}

void ejemplo_4() {
    std::thread t1(tarea, 1);
    std::thread t2(tarea, 2);
    std::thread t3(tarea, 3);
    std::cout << "Hilo Principal\n";
    t3.join();
    t2.join();
    t1.join();
}

void incrementar(int n, int& var) {
    var += n;
//    std::this_thread::sleep_for(std::chrono::milliseconds (100));
    std::cout << var << std::endl;
}

void ejemplo_5() {
    int x = 10;
    std::thread t1(incrementar, 3, std::ref(x));
    std::thread t2(incrementar, 10, std::ref(x));
    std::thread t3(incrementar, 5, std::ref(x));
    incrementar(20, x);
    t3.join();
    t2.join();
    t1.join();
}

int main() {
//    ejemplo_1();
//    ejemplo_2();
//    ejemplo_3();
//    ejemplo_4();
    ejemplo_5();
    std::cout << std::thread::hardware_concurrency() << std::endl;
    return 0;
}
