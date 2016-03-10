//BoolSource.h
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#ifndef BOOLSOURCE_H
#define BOOLSOURCE_H


class BoolSource
{
    public:
        BoolSource(float prob);

        bool computeProb();  //Determines if a new plane will land or take off returns true or false

    private:
        int probability;
};

#endif // BOOLSOURCE_H
