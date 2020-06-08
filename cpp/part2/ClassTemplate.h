#ifndef ClassTemplate_H
#define ClassTemplate_H

template<typename TYPE>
class ClassTemplate
{
    private:
        TYPE number;

    public:
        ClassTemplate(TYPE number_to_memorize);
        ~ClassTemplate();
        TYPE GetNumber();
};

template<typename TYPE>
ClassTemplate<TYPE>::ClassTemplate(TYPE number_to_memorize)
{
	number = number_to_memorize;
}

template<typename TYPE>
ClassTemplate<TYPE>::~ClassTemplate()
{}

template<typename TYPE>
TYPE ClassTemplate<TYPE>::GetNumber()
{
    return number;
}
#endif