#include <src/gameCore.h>

int main()
{
    int a = 0;
    std::vector<Music> playlist;
    //std::string name = name_recup();

    InitWindow(screenWidth, screenHeight, "Stellar Ping Pong");
    HideCursor();
    InitAudioDevice();
    music_init(&a, &playlist);
    SetTargetFPS(60);
    Beginning(playlist);
    PlayMusicStream(playlist[1]);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(playlist[1]);
        BeginDrawing();
        ClearBackground(BLACK);
        framing();
        EndDrawing();
        Shotscreen();
    }

    for(int i = 0; i < a; i++)
        UnloadMusicStream(playlist[i]);

    //saving(name);
    CloseWindow();
    CloseAudioDevice();

    return 0;
}
