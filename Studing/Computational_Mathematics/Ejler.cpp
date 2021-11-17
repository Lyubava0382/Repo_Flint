#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define PI 3.14159265
#define wB 175881 * pow(10,3)


class DrawLines{
public:
    //Подаются на вход массивы с данными, которые нужно отобразить и их размер N.
    void print(int N, float **array_x,float **array_y,float **array_z) {
        using namespace sf;
        int W = 500; // Ширина и высота окна
        int H = 500;
        RenderWindow windowX(VideoMode(W, H), "Graphic X / time");
        RenderWindow windowY(VideoMode(W, H), "Graphic Y / time");
        RenderWindow windowZ(VideoMode(W, H), "Graphic Z / time");
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(W/10, 0);
        line[0].color = Color::Blue;
        line[1].position = Vector2f(W/10, H);
        line[1].color = Color::Magenta;

        VertexArray linet(Lines, 3);
        linet[0].position = Vector2f(0, H/2);
        linet[0].color = Color::Blue;
        linet[1].position = Vector2f(W, H/2);
        linet[1].color = Color::Magenta;

        VertexArray linesX1(sf::LineStrip, N);
        VertexArray linesX2(sf::LineStrip, N);
        VertexArray linesX3(sf::LineStrip, N);
        VertexArray linesY1(sf::LineStrip, N);
        VertexArray linesY2(sf::LineStrip, N);
        VertexArray linesY3(sf::LineStrip, N);
        VertexArray linesZ1(sf::LineStrip, N);
        VertexArray linesZ2(sf::LineStrip, N);
        VertexArray linesZ3(sf::LineStrip, N);

        float size_gr = 0.00008; //Масштаб
        double step_gr = (W-100)/N;
        double t = 0.0;
        for (int i = 0; i < N; i++) {
            linesX1[i].position = Vector2f(int(t + W/10), H/2 - array_x[0][i]/size_gr);
            linesX1[i].color = Color::White;
            linesX2[i].position = Vector2f(int(t + W/10), H/2 - array_x[1][i]/size_gr);
            linesX2[i].color = Color::Magenta;
            linesX3[i].position = Vector2f(int(t + W/10), H/2 - array_x[2][i]/size_gr);
            linesX3[i].color = Color::Cyan;

            linesY1[i].position = Vector2f(int(t + W/10), H/2 - array_y[0][i]/size_gr);
            linesY1[i].color = Color::White;
            linesY2[i].position = Vector2f(int(t + W/10), H/2 - array_y[1][i]/size_gr);
            linesY2[i].color = Color::Magenta;
            linesY3[i].position = Vector2f(int(t + W/10), H/2 - array_y[2][i]/size_gr);
            linesY3[i].color = Color::Cyan;

            linesZ1[i].position = Vector2f(int(t + W/10), H/2 - array_z[0][i]/size_gr);
            linesZ1[i].color = Color::White;
            linesZ2[i].position = Vector2f(int(t + W/10), H/2 - array_z[1][i]/size_gr);
            linesZ2[i].color = Color::Magenta;
            linesZ3[i].position = Vector2f(int(t + W/10), H/2 - array_z[2][i]/size_gr);
            linesZ3[i].color = Color::Cyan;

            t += step_gr;

        }

        while (windowX.isOpen() && windowY.isOpen() && windowZ.isOpen()) {
            // Конструктор обработчика событий
            Event event;
            while (windowX.pollEvent(event)) {
                if (event.type == Event::Closed)
                    windowX.close();
            }
            while (windowY.pollEvent(event)) {
                if (event.type == Event::Closed)
                    windowY.close();
            }
            while (windowZ.pollEvent(event)) {
                if (event.type == Event::Closed)
                    windowZ.close();
            }
            windowX.clear();
            windowY.clear();
            windowZ.clear();
            windowX.draw(line);
            windowY.draw(line);
            windowZ.draw(line);
            windowX.draw(linet);
            windowY.draw(linet);
            windowZ.draw(linet);
            windowX.draw(linesX1);
            windowX.draw(linesX2);
            windowX.draw(linesX3);
            windowY.draw(linesY1);
            windowY.draw(linesY2);
            windowY.draw(linesY3);
            windowZ.draw(linesZ1);
            windowZ.draw(linesZ2);
            windowZ.draw(linesZ3);
            windowX.display();
            windowY.display();
            windowZ.display();
        }
    }
};

//Класс для формирования данных для отрисовки: метод Эйлера, Хьюна и аналитический метод
class MoveElectron{
    float B, V_0, degree, x_0,y_0,z_0;
    float w;
public:
    float **array_x, **array_y, **array_z;
    int number_of_methods; 
    MoveElectron(float B_ = 1.2, float V_0_ = 2000000,
                 float degree_ = 45 * PI/180, float x_0_ = 0,float y_0_ = 0,
                 float z_0_ = 0):B(B_),V_0(V_0_),degree(degree_),
                 x_0(x_0_),y_0(y_0_),z_0(z_0_){
        w = wB*B;
        number_of_methods = 0;
        array_x = new float*[3];
        array_y = new float*[3];
        array_z = new float*[3];
    };
    void EjlerMethod(int N,float time){
        array_x[number_of_methods] = new float[N];
        array_y[number_of_methods] = new float[N];
        array_z[number_of_methods] = new float[N];
        float step = time/N;
        float x = x_0, y = y_0,z = z_0;
        std::ofstream file;
        file.open("./logs/logsEjler");
        int amount_now = 0;
        for(float cur_time = step;cur_time < time;cur_time+=step){
            x = (x + V_0*step*sin(degree)*cos(w*cur_time));
            y = (y + V_0*step*sin(degree)*sin(w*cur_time));
            z = (V_0*cur_time*cos(degree));
            file << x << "   " << y << "   " << z << "\n";
            array_x[number_of_methods][amount_now] = x;
            array_y[number_of_methods][amount_now] = y;
            array_z[number_of_methods][amount_now] = z;
            amount_now++;
        }
        number_of_methods++;
        file.close();
    }
    void HyunMethod(int N,float time){
        array_x[number_of_methods] = new float[N];
        array_y[number_of_methods] = new float[N];
        array_z[number_of_methods] = new float[N];
        float step = time/N;
        float x = x_0, y = y_0,z = z_0;
        std::ofstream file;
        file.open("./logs/HyunMethod");
        int amount_now = 0;
        for(float cur_time = step;cur_time < time;cur_time+=step){
            x = x + step*(x+V_0*sin(degree)*cos(w*cur_time+step));
            y = y + step*(y+V_0*sin(degree)*sin(w*cur_time+step));
            z = V_0*cur_time*cos(degree);
            file << x << "   " << y << "   " << z << "\n";
            array_x[number_of_methods][amount_now] = x;
            array_y[number_of_methods][amount_now] = y;
            array_z[number_of_methods][amount_now] = z;
            amount_now++;
        }
        number_of_methods++;
        file.close();
    }
    void AnaliticMethod(int N,float time){
        array_x[number_of_methods] = new float[N];
        array_y[number_of_methods] = new float[N];
        array_z[number_of_methods] = new float[N];
        float step = time/N;
        float x = x_0, y = y_0,z = z_0;
        std::ofstream file;
        file.open("./logs/logsAnalytic");
        int amount_now = 0;
        for(float cur_time = step;cur_time < time;cur_time+=step){
            x = (V_0*sin(degree)*sin(w*cur_time)/w);
            y = (V_0*sin(degree)/w * (1-cos(w*cur_time)));
            z = (V_0*cur_time*cos(degree));
            file << x << "   " << y << "   " << z << "\n";
            array_x[number_of_methods][amount_now] = x;
            array_y[number_of_methods][amount_now] = y;
            array_z[number_of_methods][amount_now] = z;
            amount_now++;
        }
        number_of_methods++;
        file.close();
    }
    ~MoveElectron(){
    for (int i = 0; i < 3; i++){
    delete [] array_x[i], delete [] array_y[i],delete [] array_z[i];
    }
       delete [] array_x, delete [] array_y,delete [] array_z; 
    }
};


int main(){
 DrawLines drawer;
    MoveElectron el;
    el.EjlerMethod(200,0.00000025);
    el.HyunMethod(200,0.00000025);
    el.AnaliticMethod(200,0.00000025);
    drawer.print(200,el.array_x,el.array_y,el.array_z);
    return 0;
}

//MoveElectron el(100,0.00000025); - хорошие значения для метода Эйлера
