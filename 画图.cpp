#include <graphics.h> // ������Ҫ�������ͼ�ο� 

int main() { 

    initgraph(640, 480); // ��ʼ������ʾһ������ 

    circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100 

    getch(); // ��ͣһ�µȴ��û����� 

    closegraph(); // �ر�ͼ�ν��� 

    return 0; 

} 
