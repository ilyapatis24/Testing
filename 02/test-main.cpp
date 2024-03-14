#include "main.cpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


TEST_CASE("Empty", "[Check empty list]") {
    List test_list;
    SECTION("Тестирование списка на пустоту") {
        CHECK(test_list.Empty() == true);
        CHECK(test_list.Size() == 0);
        test_list.PushBack(20);
        CHECK(test_list.Size() == 1);
        test_list.PushBack(21);
        CHECK(test_list.Size() == 2);
        test_list.PopBack();
        CHECK(test_list.Size() == 1);
    }

    SECTION("Проверка очистки списка") {
        test_list.Clear();
        CHECK(test_list.Size() == 0);
    }
}

int main(int argc, char** argv)
{   
    return Catch::Session().run(argc, argv);
}