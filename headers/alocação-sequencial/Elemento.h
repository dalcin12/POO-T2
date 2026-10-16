#ifndef ELEMENTO_H
#define ELEMENTO_H

using namespace std;

class Elemento{
    public:
        int getID()const;
        virtual void imprimirInfo() const = 0;
    protected:
        int ID;
};

#endif // ELEMENTO_H