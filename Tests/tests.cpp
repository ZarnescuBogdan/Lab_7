//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#include "tests.h"
#include <cassert>
#include "../Domain//Entity.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"

void testAll() {
    testConstructor();
    testConstructor2();
    testSetterGetter();
    testRepoCRUD();
    //testServiceCRUD();
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

void testRepoCRUD() {
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
    repo.addEntity(e1);
    repo.addEntity(e2);
    repo.addEntity(e3);
    repo.addEntity(e4);

    assert(repo.getEntityById(4) == e4);
    assert(repo.getSize() == 4);

    repo.modifyEntity(e4, e5);

    assert(repo.getEntityById(5) == e5);
    assert(repo.getSize() == 4);

    repo.deleteEntity(2);

    assert(repo.getSize() == 3);
}

void testServiceCRUD() {
    const char *type1 = "apa";
    const char *type2 = "caldura";
    const char *type3 = "gaz";
    const char *type4 = "altele";
    const char *type5 = "electricitate";

    Repo repo;
    Service service(repo);
    Entity e1(1, type1, 4, 100);
    Entity e2(2, type2, 5, 200);
    Entity e3(3, type3, 6, 150);
    Entity e4(4, type5, 7, 70);
    Entity e5(5, type4, 8, 180);
    service.create(e1);
    service.create(e2);
    service.create(e3);
    service.create(e4);

    assert(service.getById(1) == e1);
    assert(service.getById(2) == e2);
    assert(service.getById(3) == e3);
    assert(service.getById(4) == e4);

    service.update(e4, e5);

    assert(service.getById(5) == e5);

    service.delete1(e2);

    assert(service.getById(1) == e1);
    assert(service.getById(3) == e3);
    assert(service.getById(5) == e5);
}
