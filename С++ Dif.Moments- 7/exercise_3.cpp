#include "exercise_2.hpp"
#include "exercise_3.hpp"
#include <numeric>

using namespace std;

void exercise_3()
{
    exercise_2::FullName fn;
    fn.set_name("Vasiliy");
    fn.set_surname("Nikolaev");
    fn.set_patronymic("Victorovich");

    exercise_2::Student s;
    *s.mutable_name() = fn;
    s.add_grades(5);
    s.add_grades(2);
    s.add_grades(4);
    s.add_grades(3);
    s.add_grades(4);
    s.add_grades(3);
    s.add_grades(4);
    s.add_grades(3);
    s.set_avg_score(accumulate(s.grades().begin(), s.grades().end(), 0) / s.grades().size());

    SG::StudentsGroup sg;
    sg.add_student(s);
    sg.Save();

    SG::StudentsGroup new_sg;
    new_sg.Open();
    cout << new_sg.GetAllInfo(fn) <<endl;
}

int main()
{
    exercise_1_2();
    exercise_3();

    return 0;
}