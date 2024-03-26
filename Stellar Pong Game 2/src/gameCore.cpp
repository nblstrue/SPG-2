#include <src/gameCore.h>

void Beginning(std::vector<Music> music)
{
    Texture2D raylibImage = LoadTexture("src/img/Raylib_logo.png");
    Texture2D OC_image = LoadTexture("src/img/OC.png");
    int a = 0;

    PlayMusicStream(music[0]);

    while(a <= 300)
    {
        UpdateMusicStream(music[0]);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Press the S Key to skip the credits", 0, screenHeight-20, fontsize, YELLOW);
        DrawText("Made With :", 10, 20, fontsize, WHITE);
        DrawTexture(raylibImage, 10, 40, WHITE);
        DrawText("Made by n3izvn", screenWidth/2, 20, fontsize, WHITE);
        DrawTexture(OC_image, screenWidth/2, 40, WHITE);
        EndDrawing();

        if(IsKeyPressed(KEY_ESCAPE))
        {
            EndDrawing();
            CloseWindow();
            CloseAudioDevice();
            exit(0);
        }

        a++;
    }

    while(!IsKeyPressed(KEY_ENTER))
    {
        UpdateMusicStream(music[0]);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Stellar Pong Game 2 - by n3izvn", 20, 120, 40, RED);
        DrawText("Press Enter", 20, (screenHeight/2) + 10, 20, ORANGE);
        EndDrawing();
        Shotscreen();

        if(IsKeyPressed(KEY_ESCAPE))
        {
            EndDrawing();
            CloseWindow();
            CloseAudioDevice();
            exit(0);
        }
    }

    StopMusicStream(music[0]);
}

void Shotscreen()
{
    static int shots = 0;
    
    if(IsKeyDown(KEY_S) && (IsKeyDown(KEY_RIGHT_CONTROL) || IsKeyDown(KEY_LEFT_CONTROL)))
    {
        TakeScreenshot(TextFormat("Screenshot_%d.png", shots));
        shots++;
    }
}

void framing()
{
    int f = GetFPS();

    if(f < 20)
        DrawText(TextFormat("%d FPS", f), 20, 0, fontsize, RED);

    if(f < 45 && f >= 20)
        DrawText(TextFormat("%d FPS", f), 20, 0, fontsize, YELLOW);

    if(f >= 45)
        DrawText(TextFormat("%d FPS", f), 20, 0, fontsize, GREEN);
}

std::string name_recup()
{
    std::string name;
    std::cout << "Veuillez ecrire votre nom de joueur (50 caracteres maximum)\n=>";
    std::getline(std::cin, name);

    return name;
}

void saving(std::string player_name)
{
    /*By Howard Hinnant, on stack overflow*/
    using namespace date;
    using namespace std::chrono;
    std::ofstream demo1("spg2.save");
    demo1 << player_name << " won the game\nTime = " << system_clock::now() << "\n\n";
    demo1.close();
}

void music_init(int *size, std::vector<Music> *music)
{
    const char* path_music[] =
    {
        "src/aud/Ouranos Island.mp3", "src/aud/Tails Mvt.mp3",
        "src/aud/Arrow_of_Time_Remix.mp3", "src/aud/ULTRA_NECROZMA.mp3",
        "src/aud/Egg Reverie Zone Remix.mp3", "src/aud/The Greatest Warrior in the Galaxy Remix.mp3", 
        "src/aud/Pressing Pursuit GaMetal Remix.mp3"
    };
        
    *size = (int)countof(path_music);

    for(int i = 0; i < *size; i++)
        music->push_back(LoadMusicStream(path_music[i]));
}
