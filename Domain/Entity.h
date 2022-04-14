//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#ifndef LAB_7_ENTITY_H
#define LAB_7_ENTITY_H


class Entity {
private:
    int id;
    int number;
    int sum;
    char* type;
public:
    Entity();
    Entity(const Entity& entity);
    Entity(int id, const char* type, int number, int sum);
    int getId();
    int getNumber();
    int getSum();
    char* getType();
    void setId(int id);
    void setNumber(int number);
    void setSum(int sum);
    void setType(const char* name);
    Entity &operator=(const Entity& entity);
    bool operator==(const Entity& entity);
    ~Entity();
    bool isValid();
};


#endif //LAB_7_ENTITY_H
