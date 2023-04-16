#include <graphics.h> // 就是需要引用这个图形库 

int main() { 

    initgraph(640, 480); // 初始化，显示一个窗口 

    circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100 

    getch(); // 暂停一下等待用户按键 

    closegraph(); // 关闭图形界面 

    return 0; 

} 
