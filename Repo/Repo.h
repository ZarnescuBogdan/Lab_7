//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#ifndef LAB_7_REPO_H
#define LAB_7_REPO_H

#include "../Domain//Entity.h"
#include <vector>

using namespace std;

class Repo {
private:
    Entity entities[100];
    int noEntities;
public:
    Repo();
    ~Repo();
    void addEntity(Entity &entity);
    void modifyEntity(Entity &entity, Entity &newEntity);
    void deleteEntity(int id);
    Entity getEntityById(int id);
    Entity getEntityFromPos(int pos);
    int getSize();
    vector<Entity> getAll();
    Repo &operator=(const Repo &repo);
};


#endif //LAB_7_REPO_H
