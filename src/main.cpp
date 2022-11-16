#include <iostream>

using namespace std;

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

    //player
    GameObject* player = new GameObject("player");
        player->AddComponent<Transform>();
        player->AddComponent<Player>();
        player->StartAll();


    //player body
    GameObject* playerBody = new GameObject("player body");
        playerBody->AddComponent<Transform>();
        playerBody->StartAll();

    playerBody->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());


    //print
    mainScene->print();

    return 0;
}