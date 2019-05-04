
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <vector>
#include <memory>
#include "Rect.h"

using namespace std;


class Component;

class GameObject
{
public:
    GameObject(int layer=0);
    ~GameObject();
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(shared_ptr<Component> cpt);
    void RemoveComponent(shared_ptr<Component> cpt);
    shared_ptr<Component> GetComponent(string type);

    Rect box;
    int layer;      //Variable to place the render order

private:
    vector<shared_ptr<Component>> components;
    bool isDead;
};

#endif // GAMEOBJECT_H
