#ifndef POLYNOM_H
#define POLYNOM_H

#include <QString>
#include <deque>

class Polynom
{
public:
    Polynom();

    Polynom operator -(const Polynom &o) const;
    Polynom operator *(int k) const;

    void sub(const Polynom &o); // works as -=
    void mul_scalar(int k); // works as *=
    int get(int i) const;
    void mul_var_bang(); // bang!
    Polynom mul_var() const;

    QString toString() const;
    int size() const;

    void setOne();
    void setVar();

private:
    std::deque<int> a;
};

#endif // POLYNOM_H
