
#include"Timer.h"





void TimeRecord::TextWrite(std::string text, int positionx, int positiony)
{

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1, 0, 0);

    glRasterPos2i(glutGet(GLUT_WINDOW_WIDTH) - positionx, positiony);
    std::string buttonText = text;
    for (char c : buttonText)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);


}

void TimeRecord:: saveTimeRecord(const TimeRecord& record) {

    std::vector<TimeRecord> records;
    std::ifstream file("records.txt");
    if (file.is_open()) {
        TimeRecord r;
        while (file >> r.playerName >> r.timeInSeconds) {
            records.push_back(r);
        }
        file.close();
    }

    records.push_back(record);
    std::sort(records.begin(), records.end(), [](const TimeRecord& a, const TimeRecord& b) {
        return a.timeInSeconds < b.timeInSeconds;
        });

    std::ofstream outputFile("records.txt");
    if (outputFile.is_open()) {
        int count = std::min(static_cast<int>(records.size()), 10);
        for (int i = 0; i < count; ++i) {
            outputFile<< records[i].playerName << " " << records[i].timeInSeconds << std::endl;
        }
        outputFile.close();
    }

}
void TimeRecord::printTopRecords() 
{
    std::vector<TimeRecord> records;
    std::ifstream file("records.txt");
    if (file.is_open()) {
        TimeRecord r;
        while (file >> r.playerName >> r.timeInSeconds) {
            records.push_back(r);
        }
        file.close();
    }
    int count = std::min(static_cast<int>(records.size()), 10);
    for (int i = 0; i < count; ++i) {
        std::string recordText = std::to_string(i+1) +" "+ records[i].playerName + ": " + std::to_string(records[i].timeInSeconds) + " секунд";
        TextWrite(recordText, 450, (i+1) * 30 + 200);
    }
}







void TimeRecord::PrintTime(std::chrono::steady_clock::time_point &startime)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0, 1, 0);


    std::chrono::steady_clock::time_point gametime = std::chrono::steady_clock::now();
    std::chrono::duration<int> elapsedSeconds2 = std::chrono::duration_cast<std::chrono::seconds>(gametime - startime);

    std::string gameTime = "Time: " + std::to_string(elapsedSeconds2.count()) + "s";

    glRasterPos2i(glutGet(GLUT_WINDOW_WIDTH) - 100, 600);
    std::string buttonText = gameTime;
    for (char c : buttonText)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
