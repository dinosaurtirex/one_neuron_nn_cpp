#include <iostream>


float TrainDataset[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    {5, 11}
};


#define TrainDatasetLength (sizeof(TrainDataset) / sizeof(TrainDataset[0]))
#define LEARNING_ITERATIONS 50


float RootMeanSquaredError(float weight)
{
    float RMSE = 0.0f;
    for (size_t i = 0; i < TrainDatasetLength; ++i)
    {
        float ValueReceived = TrainDataset[i][0];
        float ValuePredicted = ValueReceived * weight;
        float TrueValue = TrainDataset[i][1];
        float Diffrence = ValuePredicted - TrueValue;
        RMSE += 2 * (ValueReceived * weight - TrueValue) * ValueReceived;
    }
    return RMSE / TrainDatasetLength;
}


float GetRandomInitializedWeight(int RandSeed)
{
    srand(RandSeed);
    float RandFloat = (float)rand() / (float)RAND_MAX;
    return RandFloat * 10.0f;
}


int main()
{
    float InitialWeight = GetRandomInitializedWeight(60);
    float LearningRate = 1e-1;
    for (size_t i = 0; i < LEARNING_ITERATIONS; i++)
    {
        float RMSE = RootMeanSquaredError(InitialWeight);
        InitialWeight -= LearningRate * RMSE;
        printf("cost = %f, w = %f\n", RootMeanSquaredError(InitialWeight), InitialWeight);
    }
    printf("------------------------------\n");
    printf("w = %f\n", InitialWeight);
    return 0;
}