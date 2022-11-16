#include <iostream>

using namespace std;

#include "util.cpp"

#include <string>
#include <vector>
#include <map>

#include "internal/GameObject.h"
#include "internal/Scene.h"

static Scene* currentScene;

#include "internal/Component.h"

#include "math.h"

#include "components/Transform.h"
#include "components/Player.h"

#include "internal/GameObject.cpp"
#include "internal/Scene.cpp"


int main() {
    Scene* mainScene = new Scene("main scene");

    cout << mainScene->name << endl;

    GameObject* player = new GameObject("player");
        player->AddComponent<Transform>();
        player->AddComponent<Player>();
        player->StartAll();

        GameObject* camera = new GameObject("camera");
            camera->AddComponent<Transform>();
            camera->StartAll();

            camera->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());

        GameObject* playerBody = new GameObject("player body");
            playerBody->AddComponent<Transform>();
            playerBody->StartAll();

            playerBody->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());

            GameObject* playerStaff = new GameObject("player staff");
                playerStaff->AddComponent<Transform>();
                playerStaff->StartAll();

                playerStaff->GetComponent<Transform>()->SetParent(playerBody->GetComponent<Transform>());


            GameObject* playerHat = new GameObject("player hat");
                playerHat->AddComponent<Transform>();
                playerHat->StartAll();

                playerHat->GetComponent<Transform>()->SetParent(playerBody->GetComponent<Transform>());

    GameObject* enemy = new GameObject("enemy");
        enemy->AddComponent<Transform>();
        enemy->StartAll();

        GameObject* enemySword = new GameObject("enemy sword");
            enemySword->AddComponent<Transform>();
            enemySword->StartAll();

            enemySword->GetComponent<Transform>()->SetParent(enemy->GetComponent<Transform>());

    mainScene->print();

    //the staff can grab enemies i guess
    enemy->GetComponent<Transform>()->SetParent(playerStaff->GetComponent<Transform>());

    mainScene->print();

    return 0;
}