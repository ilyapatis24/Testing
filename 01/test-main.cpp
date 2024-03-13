#include "main.cpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


TEST_CASE("Empty", "[Check empty list]") {
    List test_list;
    SECTION("Тестирование методов двусвязного списка") {
        try
        {
            test_list.PopBack();
        }
        catch (std::runtime_error err)
        {
            CHECK(test_list.Empty() == true);
        }

        try
        {
            test_list.PopFront();
        }
        catch (std::runtime_error err)
        {
            CHECK(test_list.Empty() == true);
        }

        test_list.PushBack(11);
        test_list.PushBack(21);
        CHECK(test_list.Size() == 2);
        CHECK(test_list.PopFront() == 11);
        CHECK(test_list.PopBack() == 21);
        CHECK(test_list.Empty() == true);
        test_list.PushFront(14);
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