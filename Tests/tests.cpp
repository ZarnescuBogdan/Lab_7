//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#include "tests.h"
#include <cassert>
#include "../Domain//Entity.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include <vector>

void testAll() {
    testConstructor();
    testConstructor2();
    testSetterGetter();
    testRepoAddEntity();
    testRepoModifyEntity();
    testRepoDelete();
    testServiceCreate();
    testServiceUpdate();
    testServiceDelete();
}

void testConstructor() {
    Entity entity;
    assert(entity.getId() == 0);
    assert(entity.getNumber() == 0);
    assert(entity.getSum() == 0);
    assert(entity.getType() == nullptr);
}

void testConstructor2() {
    const char *type = "apa";
    Entity entity(1, type, 1, 100);
    assert(entity.getId() == 1);
    assert(strcmp(entity.getType(), type) == 0);
    assert(entity.getNumber() == 1);
    assert(entity.getSum() == 100);
}

void testSetterGetter() {
    Entity entity;
    entity.setId(1);
    entity.setNumber(1);
    entity.setSum(50);
    const char *type = "gaz";
    entity.setType(type);
    assert(entity.getId() == 1);
    assert(strcmp(entity.getType(), type) == 0);
    assert(entity.getNumber() == 1);
    assert(entity.getSum() == 50);
}

void testRepoAddEntity() {
    const char *type1 = "apa";
    const char *type2 = "caldura";
    const char *type3 = "gaz";
    const char *type4 = "altele";
    const char *type5 = "electricitate";
    Repo repo;
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);
    Entity e3(3, type3, 6, 150);
    Entity e4(4, type5, 7, 70);
    Entity e5(5, type4, 8, 180);

    assert(repo.getSize() == 0);

    repo.addEntity(e1);
    repo.addEntity(e2);
    repo.addEntity(e3);
    repo.addEntity(e4);

    assert(repo.getEntityById(4) == e4);
    assert(repo.getSize() == 4);
}

void testRepoModifyEntity() {
    const char *type1 = "apa";
    const char *type2 = "caldura";

    Repo repo;
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);

    repo.addEntity(e1);

    assert(repo.getEntityById(1) == e1);
    assert(repo.getSize() == 1);

    repo.modifyEntity(e1, e2);

    assert(repo.getEntityById(2) == e2);
    assert(repo.getSize() == 1);
}

void testRepoDelete() {
    const char *type1 = "apa";
    const char *type2 = "caldura";

    Repo repo;
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);


    repo.addEntity(e1);
    repo.addEntity(e2);

    assert(repo.getEntityById(1) == e1);
    assert(repo.getSize() == 2);

    repo.deleteEntity(1);

    assert(repo.getSize() == 1);
}

void testServiceCreate() {
    const char *type1 = "apa";
    const char *type2 = "caldura";

    Repo repo;
    Service service(repo);
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);

    service.create(e1);
    service.create(e2);

    assert(service.getSize() == 2);
    assert(service.getById(1) == e1);
    assert(service.getById(2) == e2);
}

void testServiceUpdate() {
    const char *type1 = "apa";
    const char *type2 = "caldura";

    Repo repo;
    Service service(repo);
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);

    service.create(e1);

    assert(service.getSize() == 1);
    assert(service.getById(1) == e1);

    service.update(e1, e2);

    assert(service.getSize() == 1);
    assert(service.getById(2) == e2);
}

void testServiceDelete() {
    const char *type1 = "apa";
    const char *type2 = "caldura";

    Repo repo;
    Service service(repo);
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);


    service.create(e1);
    service.create(e2);

    assert(service.getSize() == 2);

    service.delete1(e1);

    assert(service.getSize() == 1);
    assert(service.getEntityFromPos(1) == e2);
}
