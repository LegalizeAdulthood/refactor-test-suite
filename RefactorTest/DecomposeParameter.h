#pragma once

namespace DecomposeParameterNamespace
{
    struct Bag
    {
        int a;
        int b;
        int c;
    };

    union BagUnion
    {
        int i;
        float f;
        double d;
        const char *s;
    };

    struct BagAnonymousUnion
    {
        int type;
        union
        {
            int i;
            float f;
            double d;
            const char *s;
        };
    };

    class Bagger
    {
    public:
        Bagger();

        int A() const { return 1; }
        int B() const { return 2; }
        int C() const { return 3; }
        int D() const { return A() + B(); }

        void X(int val);
        int X() const;

        int MunchConstReference(const Bag &bag);
        int MunchReference(Bag &bag);
        int MunchConstPointer(const Bag *bag);
        int MunchPointer(Bag *bag);
        
        int MunchConstReferenceInline(const Bag &bag)
        {
            return bag.a + bag.b + bag.c;
        }
        int MunchReferenceInline(Bag &bag)
        {
            bag.a = bag.b + bag.c;
            return bag.b;
        }
        int MunchConstPointerInline(const Bag *bag)
        {
            return bag->a + bag->b + bag->c;
        }
        int MunchPointerInline(Bag *bag)
        {
            bag->a = bag->b + bag->c;
            return bag->b;
        }

    private:
        int x;
    };

    extern int MunchBagConstReference(const Bag &bag);
    extern int MunchBagReference(Bag &bag);
    extern int MunchBagConstPointer(const Bag *bag);
    extern int MunchBagPointer(Bag *bag);

    extern int MunchBaggerConstReference(const Bagger &bagger);
    extern int MunchBaggerReference(Bagger &bagger);
    extern int MunchBaggerConstPointer(const Bagger *bagger);
    extern int MunchBaggerPointer(Bagger *bagger);
}
