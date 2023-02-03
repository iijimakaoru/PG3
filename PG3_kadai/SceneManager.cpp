#include "SceneManager.h"

SceneManager* SceneManager::GetInstance()
{
    static SceneManager instance;
    return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
    scene = sceneNo;
}

void SceneManager::Draw()
{
    if (scene == 1)
    {
        printf("TitleScene\n");
    }
    else if (scene == 2)
    {
        printf("NewGameScene\n");
    }
    else if (scene == 3)
    {
        printf("GamePlayScene\n");
    }
    else if (scene == 4)
    {
        printf("GameClearScene\n");
    }
    else
    {
        printf("ë∂ç›ÇµÇ»Ç¢ÇÕÇ∏ÇÃÉVÅ[Éì\n");
    }
}
