//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#include "Entity.h"
#include <cstring>
#include <vector>

using namespace std;

/**
 * Constructor.
 */
Entity::Entity() {
    this->id = 0;
    this->type = nullptr;
    this->number = 0;
    this->sum = 0;
}

/**
 * Copy-constructor.
 * @param entity
 */
Entity::Entity(const Entity &entity) {
    this->id = entity.id;
    this->type = new char[strlen(entity.type) + 1];
    strlcpy(this->type, entity.type, size_t(this->type));
    this->number = entity.number;
    this->sum = entity.sum;
}

/**
 * Constructor with parameters.
 * @param id id of entity
 * @param type type of entity
 * @param number number of entity
 * @param sum sum of entity
 */
Entity::Entity(int id, const char *type, int number, int sum) {
    this->id = id;
    this->type = new char[strlen(type) + 1];
    strlcpy(this->type, type, size_t(this->type));
    this->number = number;
    this->sum = sum;
}

/**
 * Set id of entity.
 * @param id id of entity
 */
void Entity::setId(int id1) {
    this->id = id1;
}

/**
 * Set number of entity.
 * @param number number of entity
 */
void Entity::setNumber(int number1) {
    this->number = number1;
}

/**
 * Set sum of entity.
 * @param sum sum of entity
 */
void Entity::setSum(int sum1) {
    this->sum = sum1;
}

/**
 * Set type of entity.
 * @param type type of entity
 */
void Entity::setType(const char *type1) {
    if(this->type) {
        delete[] this->type;
    }
    this->type = new char[strlen(type1) + 1];
    strlcpy(this->type, type1, size_t(this->type));
}

/**
 * Get id of entity.
 * @return id of entity
 */
int Entity::getId() {
    return this->id;
}

/**
 * Get number of entity.
 * @return number of entity
 */
int Entity::getNumber() {
    return this->number;
}

/**
 * sum of entity.
 * @return sum of entity
 */
int Entity::getSum() {
    return this->sum;
}

/**
 * type of entity.
 * @return type of entity
 */
char* Entity::getType() {
    return this->type;
}

/**
 * Destructor.
 */
Entity::~Entity() {
    if(this->type) {
        delete[] this->type;
        this->id = 0;
        this->type = nullptr;
        this->number = 0;
        this->sum = 0;
    }
}

/**
 * Assignment operator.
 * @param entity entity to be assigned
 * @return the entity assigned
 */
Entity& Entity::operator=(const Entity &entity) {
    this->setId(entity.id);
    this->setType(entity.type);
    this->setNumber(entity.number);
    this->setSum(entity.sum);
    return *this;
}

/**
 * Equal operator.
 * @param entity entity to be compared
 * @return true or false
 */
bool Entity::operator==(const Entity &entity) {
    return ((this->sum == entity.sum) and (this->number == entity.number) and (strcmp(this->type, entity.type) == 0));
}

/**
 * Validator.
 * @return true or false
 */
bool Entity::isValid() {
    const char *s1 = "apa";
    const char *s2 = "caldura";
    const char *s3 = "electricitate";
    const char *s4 = "gaz";
    const char *s5 = "altele";
    vector<const char*>types = {s1, s2, s3, s4, s5};
    for(auto &s: types) {
        if(strcmp(s, type) == 0) {
            return true;
        }
    }
    return false;
}
