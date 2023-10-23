#pragma once

#ifdef __cplusplus
#define EXPORT extern "C" __declspec (dllexport)
#else
#define EXPORT __declspec (dllexport)
#endif

EXPORT void Addition(int a, int b);
EXPORT void Subtraction(int a, int b);
EXPORT void Multiplication (int a, int b);
EXPORT void Division(int a, int b);
EXPORT void DoYouLikeCats(char* str);