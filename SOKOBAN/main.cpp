#define _CRT_SECURE_NO_WARNINGS
#include"3DCube.h"
#include "Texture.h"

#include"FinalZone.h"
#include"Timer.h"
#include"Move.h"


//флажок для коліізії
bool timePrinted = false;

HWND hwnd;

Move move;

float xAlfa = 20;
float zAlfa = 0;
//Позиція камери
POINTFLOAT pos = { 0, 0};


const float pi = 3.14159;
//Кубики
Cube3D cube;
Cube3D cube2;
//Розміщення кубів
static float cubeX = 3.0f;
static float cubeY = 3.0f;
static float cube2X = -3.0f;
static float cube2Y = -3.0f;
// Рощміщення фінальних зон
FinalZone final{-12,-12,-1.99};
FinalZone final2{ 12,12,-1.99 };

TimeRecord record;

std::chrono::steady_clock::time_point startTime;

//Текстурки
TextureWall wallTexture;
TextureWall wall;
TextureWall wallSKY;
TextureWall wallPOOL;


void GameOver()
{

   
   
        Sleep(100);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        record.TextWrite("GAME OVER", 450, 100);
        record.TextWrite("Enter ESC - end game", 650, 40);
        record.TextWrite("Enter F2 - restart", 350, 40);
        record.TextWrite("Best players : ", 450, 200);

        record.printTopRecords();



        pos.x = 100;
        pos.y = 100;
    
}


void ShowWorld()
{
    wallTexture.CreationWall(wall.GettextureID(), wallPOOL.GettextureID(), wallSKY.GettextureID());
    //Фіналькі зони
    final.Draw(0, 0, 1);
    final2.Draw(1, 0, 0);

    // Малювання стінок
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, wall.GettextureID());
    wallTexture.DrawWall(5, 7, 10, 0);
    wallTexture.DrawWall(-5, -7, 10, 0);
    wallTexture.DrawWall(15, 0, 7, 90);
    wallTexture.DrawWall(5, -12, 5, 90);
    wallTexture.DrawWall(-15, -15, 8, 90);
    wallTexture.DrawWall(-5, 12, 5, 90);
    wallTexture.DrawWall(-10, 17, 5, 0);
    wallTexture.DrawWall(-10, 17, 5, 0);
    wallTexture.DrawWall(19, -7, 4, 0);


    //Кубики
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glColor3f(1, 0, 0);
    cube.Draw(0, 0, -2);
    glColor3f(0, 0, 1);
    cube2.Draw(0, 0, 0);
    glPopMatrix();

    record.TextWrite("Enter ESC - end game", 800, 20);
    record.TextWrite("Enter F2 - restart", 500, 20);
    
    if (final.CheckCollision(cube) && final2.CheckCollision(cube2) == true)
    {
        GameOver();
    }
    
    //Відображення ігроового часу
    record.PrintTime(startTime);

        cube.SetPosition(cubeX, cubeY);
        cube2.SetPosition(cube2X, cube2Y);
}
void Kontrol()

{
    if (GetAsyncKeyState(VK_F2) < 0)
    {
        xAlfa = 20;
        zAlfa = 0;
        pos = { 0, 0 };
        cubeX = 3.0f;
        cubeY = 3.0f;
        cube2X = -3.0f;
        cube2Y = -3.0f;
        timePrinted = false;
        startTime = std::chrono::steady_clock::now();


      
            

        
    }
    
    if (GetAsyncKeyState(VK_ESCAPE) < 0)
    {
        exit(0);

    }
   
    
  
}

float scaleIncrement = 5.0f;
float scale = 1.0f;

void specialInput(int key, int x, int y)
{
   
    switch (key)
    {
    case GLUT_KEY_UP: // Масштабування вгору
       
        if (scale > 6.0f)
        {
           
            break;
        }
        else
        {
            scale += scaleIncrement;
            glTranslatef(0, 0, 2);
            break;
        }
       
    case GLUT_KEY_DOWN: // Масштабування вниз
        
        if (scale < 1.1f)
        {
            break;
        }
        else
        {
            
            scale -= scaleIncrement ;
            glTranslatef(0, 0, -2);
            break;
        }
      
        break;
    

    default:
        break;
    }

    glutPostRedisplay();
}

void Collision()
{
    

  
    float cameraX = pos.x;
    float cameraY = pos.y;

    float distance1 = sqrt(pow(cubeX - cameraX, 2) + pow(cubeY - cameraY, 2));
    float distance2 = sqrt(pow(cube2X - cameraX, 2) + pow(cube2Y - cameraY, 2));

    float interactionDistance = 1.0f;
    float ugol = -zAlfa / 180 * pi;

    float cubeSize = 1.0f;
    if (abs(cubeX - cube2X) < cubeSize + interactionDistance && abs(cubeY - cube2Y) < cubeSize + interactionDistance)
    {
        if (cubeX < cube2X)
            cubeX -= 0.01;
        else
            cubeX += 0.01;

        if (cubeY < cube2Y)
            cubeY -= 0.01;
        else
            cubeY += 0.01;
    }
    if (distance1 < cubeSize + interactionDistance)
    {
        cubeX += sin(ugol) * 0.01;
        cubeY += cos(ugol) * 0.01;
    }

    if (distance2 < cubeSize + interactionDistance)
    {
        cube2X += sin(ugol) * 0.01;
        cube2Y += cos(ugol) * 0.01;
    }
    if (cubeX <= -21.5f)
        cubeX += 0.01f;
    else if (cubeX >= 21.5f)
        cubeX -= 0.01f;

    if (cubeY <= -21.5f)
        cubeY += 0.01f;
    else if (cubeY >= 21.5f)
        cubeY -= 0.01f;
    if (cube2X <= -22.5f)
        cube2X += 0.01f;
    else if (cube2X >= 22.5f)
        cube2X -= 0.01f;

    if (cube2Y <= -21.5f)
        cube2Y += 0.01f;
    else if (cube2Y >= 21.5f)
        cube2Y -= 0.01f;

    // Відштовхування камери від стін
    if (pos.y <= -21.5f)
        pos.y += 0.01f;
    else if (pos.y >= 21.5f)
        pos.y -= 0.01f;

    if (pos.x <= -22.0f)
        pos.x += 0.01f;
    else if (pos.x >= 21.5f)
        pos.x -= 0.01f;

    if (pos.y <= -22.0f)
        pos.y += 0.01f;
    else if (pos.y >= 21.5f)
        pos.y -= 0.01f;


///
    if (pos.x >= -5.2 && pos.x < 15.5 && pos.y <= 7.5&&pos.y>=6.5)
    {
     
        pos.y -= 0.01f;

    }
    if (pos.x > -5.2 && pos.x < 15.5 && pos.y <= 7.6 && pos.y >= 6.6)
    {
       
        pos.y += 0.01f;

    }
    ////
    if (pos.y < 17 && pos.y > 6.3 && pos.x <= -5.6 && pos.x >= -5.8)
    {

        pos.x -= 0.01f;

    }
    if (pos.y < 17 && pos.y > 6.6 && pos.x <= -4.2 && pos.x >= -5.0)
    {

        pos.x += 0.01f;

    }
    /// //
    if (pos.x <= -4.6 && pos.x > -16 && pos.y <= 17.5 && pos.y >= 16.5)
    {

        pos.y -= 0.01f;

    }
    if (pos.x < -4.6 && pos.x > -16 && pos.y <= 17.6 && pos.y >=16.6)
    {

        pos.y += 0.01f;

    }
    //////
    if (pos.y < 7.3 && pos.y > -7.3 && pos.x >= 14.6 && pos.x <= 14.8)
    {

        pos.x -= 0.01f;

    }
    if (pos.y < 7.3 && pos.y > -7.3 && pos.x >= 15.2 && pos.x <= 15.7)
    {

        pos.x += 0.01f;

    }
    ////////
    if (pos.x >= 14.8 && pos.x < 24 && pos.y <= -6.7 && pos.y >=-7.5)
    {

        pos.y -= 0.01f;

    }
    if (pos.x >= 14.8 && pos.x < 24 && pos.y <= -6.6 && pos.y >= -7.4)
    {

        pos.y += 0.01f;

    }
    //////2
    if (pos.x >= -15.5 && pos.x < 6.4 && pos.y >= -8 && pos.y <= -6.2) 
    {

        pos.y -= 0.01f;

    }
    if (pos.x > -15.5 && pos.x < 6.4 && pos.y >= -6.7 && pos.y <= -6)
    {

        pos.y += 0.01f;

    }
    //
    if (pos.y < -6 && pos.y > -18 && pos.x >= 4.5 && pos.x <= 4.8)
    {

        pos.x -= 0.01f;

    }
    if (pos.y < -6 && pos.y > -18 && pos.x >= 4.8 && pos.x <= 6.5)
    {

        pos.x += 0.01f;

    }
    ////
    if (pos.y < -6 && pos.y > -24 && pos.x <= -15.6 && pos.x >= -15.8)
    {

        pos.x -= 0.01f;

    }
    if (pos.y < -6 && pos.y > -24 && pos.x <= -14.2 && pos.x >= -15.0)
    {

        pos.x += 0.01f;

    }
    




    cube.CubeCollision(cubeX, cubeY);
    cube2.CubeCollision(cube2X, cube2Y);

    
    if (final.CheckCollision(cube) && final2.CheckCollision(cube2) == true && timePrinted == false)
    {

        std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = endTime - startTime;
        record.timeInSeconds= static_cast<double>(elapsedSeconds.count());

        record.saveTimeRecord(record);



        timePrinted = true;
      
    }
    


    final.CheckCollision(cube);
    final2.CheckCollision(cube2);
   

}


void RenderScene()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    move.MoveHero(zAlfa, xAlfa,pos.x,pos.y);
    move.Move_Camera(zAlfa,xAlfa);
    Kontrol();
    ShowWorld();
    glPopMatrix();
 
    Collision();
    
   
    

    glFlush();
    glutSwapBuffers();
    
}

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1, Timer, 0);
}



std::string player;
void Console()
{
    setlocale(LC_ALL, "ukr");
    

    do {
        std::cout << "Enter name : ";
        std::getline(std::cin, player);

        if (player.empty()) {
            std::cout << "Error: Ви не ввели жодного символу.\n";
        }
        else {
            record.playerName = player;
            break; // Вийти з циклу, якщо введення коректне
        }
    } while (true);
}

int main(int argc, char** argv)
{

    Console();

    if (player.length() > 0)
    {
        startTime = std::chrono::steady_clock::now();
        glEnable(GL_ALPHA_TEST);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Sokoban");
        glutDisplayFunc(RenderScene);
        glutTimerFunc(1, Timer, 0);
        glFrustum(-1, 1, -1, 1, 1, 80);

        glutSpecialFunc(specialInput);

        wallTexture.LoadTexture("TEXTURE/WALL.jpg");
        wall.LoadTexture("TEXTURE/wall_texture.jpg");
        wallSKY.LoadTexture("TEXTURE/NEBO.jpg");
        wallPOOL.LoadTexture("TEXTURE/PARKET.jpg");


        glutMainLoop();

        return 0;
    }
}