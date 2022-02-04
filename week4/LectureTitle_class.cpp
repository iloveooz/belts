#include <string>

struct Specialization {
    explicit Specialization(const std::string& new_value) {
        value = new_value;
    }
    std::string value;
};

struct Course {
    explicit Course(const std::string& new_value) {
        value = new_value;
    }
    std::string value;
};

struct Week {
    explicit Week(const std::string& new_value) {
        value = new_value;
    }
    std::string value;
};

struct LectureTitle {
    LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week) {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
    std::string specialization;
    std::string course;
    std::string week;
};

int main() {
    LectureTitle title1(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

    // LectureTitle title2("C++", "White belt", "4th");
    // LectureTitle title3(std::string("C++"), std::string("White belt"), std::string("4th"));
    // LectureTitle title4 = {"C++", "White belt", "4th"};
    // LectureTitle title5 = {{"C++"}, {"White belt"}, {"4th"}};
    // LectureTitle title6(Course("White belt"), Specialization("C++"), Week("4th"));
    // LectureTitle title7(Specialization("C++"), Week("4th"), Course("White belt"));
}
