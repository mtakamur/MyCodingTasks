#include <random>

class EventGenerator
{
    private:
        std::random_device rnd;
        std::mt19937 mt;
        static const int MAX_NELEMENTS = 100000;
        int min;// Lower limit of integer
        int max;// Upper limit of integer
        int range;// Range of integer
        int nelements;// Number of integers to be generated (max: MAX_NELEMENTS)
        clock_t tstart = 0;// Start timing of integer generation
        clock_t tfinish = 0;// Finish timing of integer generation
        double tleng;
        int elements[MAX_NELEMENTS];

    public:
        EventGenerator(int lower_limit, int upper_limit, int number_of_elements);
        ~EventGenerator();
        void GenerateElements(int container[]);
        void GetElements(int *container);
        double GetTime();
        void SetNelements(int number_of_elements);
        void SetRange(int lower_limit, int upper_limit);
        void ShowElements();
};