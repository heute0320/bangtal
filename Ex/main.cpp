#include <bangtal>
using namespace bangtal;

int main()
{
    auto room1 = Scene::create("룸1", "방배경_1.png");
    auto room2 = Scene::create("룸2", "방배경2.png");

    auto door1 = Object::create("문-오른쪽-닫힘.png", room1, 1000, 620);
    auto closed1 = true;
    
    auto key = Object::create("Images/열쇠.png", room1, 600, 150);
        key->setScale(0.2f);
        key->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
            object->pick();
            return true;
        });
    
    auto door2 = Object::create("문-왼쪽-열림.png", room2, 420, 290);
    auto door3 = Object::create("문-오른쪽-닫힘.png", room2, 900, 280);
    door3->setScale(0.5f);

    auto open1 = true;
    auto open2 = false;
    
    door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
        if (closed1) {
            if (key->isHanded()) {
                object->setImage("문-오른쪽-열림.png");
                closed1 = false;
            }
            else {
                showMessage("열쇠가 필요해~~~");
            }
        }
        else {
            room2->enter();
//            endGame();
        }
        return true;
    });
    door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (open1 == true) {
            room1->enter();
        }
        return true;
        });

    door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
//        if (open2 == true) {
//            endGame();
//        } else {
//            object->setImage("문-오른쪽-열림.png");
//            open2 = true;
//        }
        endGame();
        return true;
    });

    startGame(room1);
}
