#include <iostream>

#include "internal/GameObject.h"
#include "internal/Component.h"
#include "internal/Scene.h"

#include "math.h"

#include "components/Transform.h"
#include "components/Player.h"

using namespace std;


int main() {
    Scene* mainScene = new Scene("main scene");

    GameObject* player = new GameObject("player");

    player->AddComponent<Transform>();
    player->AddComponent<Player>();

    player->StartAll();

    return 0;
}