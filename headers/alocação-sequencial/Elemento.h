#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento{
    public:
        int getID() const;
        virtual void imprimirInfo() const = 0;
        virtual ~Elemento() = default;
    protected:
        int ID;
};

#endif // ELEMENTO_H