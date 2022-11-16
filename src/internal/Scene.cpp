#include "Scene.h"

Scene::Scene(string sceneName) {
    cout << "ffef" << endl;

    name = sceneName;
    currentScene = this;
}

void Scene::printRecur(vector<GameObject*> children, int depth) {
    for(auto i : children) {
        cout << repeatString("....", depth) <<  i->name << endl;



        vector<GameObject*> childrenGameObjects;

        for(auto j : i->GetComponent<Transform>()->children) {
            childrenGameObjects.push_back(j->gameObject);
        }

        printRecur(childrenGameObjects, depth+1);
    }
}

void Scene::print() {
    printRecur(children,0);
}