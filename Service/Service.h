//
// Created by Bogdan Zarnescu on 14.04.2022.
//

#ifndef LAB_7_SERVICE_H
#define LAB_7_SERVICE_H

#include "../Repo/Repo.h"

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo &repo);
    void create(Entity &entity);
    void update(Entity entity, Entity newEntity);
    void delete1(Entity entity);
    Entity getById(int id);
    vector<Entity> getAll();
    virtual ~Service();
};


#endif //LAB_7_SERVICE_H
