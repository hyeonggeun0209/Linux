class Student {
private:
    char *_name;
    int _age;
public:
    Student();
    Student(char *name, int age) {
        _name=name;
        _age=age;
    }
    char *getName();
};