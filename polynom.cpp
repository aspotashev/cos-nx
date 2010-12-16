#include <algorithm>
#include <QStringList>
#include "polynom.h"

Polynom::Polynom()
{
}

Polynom Polynom::operator -(const Polynom &o) const
{
    Polynom res = *this;
    res.sub(o);

    return res;
}

void Polynom::sub(const Polynom &o) // works as -=
{
    if (o.size() > size())
    {
        a.resize(o.size(), 0);
    }

    int sz = std::min(o.size(), size());
    for (int i = 0; i < sz; i ++)
        a[i] -= o.get(i);
}

int Polynom::get(int i) const
{
    return a[i];
}

Polynom Polynom::operator *(int k) const
{
    Polynom res = *this;
    res.mul_scalar(k);

    return res;
}

void Polynom::mul_scalar(int k)
{
    for (int i = 0; i < (int)a.size(); i ++)
        a[i] *= k;
}

void Polynom::mul_var_bang() // bang!
{
    a.push_front(0);
}

Polynom Polynom::mul_var() const
{
    Polynom res = *this;
    res.mul_var_bang();

    return res;
}

QString Polynom::toString() const
{
    QStringList res = QStringList();
    for (int i = size() - 1; i >= 0; i --)
    {
        if (a[i])
            res << QString("%1%2%3%4").
                    arg(a[i] == 1 && i != 0 ? "" : QString("%1").arg(a[i])).
                    arg(i == 0 ? "" : "c").
                    arg(i > 1 ? "^" : "").
                    arg(i > 1 ? QString("%1").arg(i) : "");
    }

    return res.join("+").replace("+-", "-");
}

int Polynom::size() const
{
    return (int)a.size();
}

void Polynom::setOne()
{
    a.clear();
    a.push_back(1); // free term
}

void Polynom::setVar()
{
    a.clear();
    a.push_back(0); // free term
    a.push_back(1); // linear term
}
