#pragma once
#include <iostream>
#include <functional>
#include <vector>


template <class T>
bool safeCin(T& input);

bool isEmailValid(std::string email);

bool isStudentClassValid(std::string studentClass);

bool setColor(uint16_t newColor);

template<class T>
std::vector<T> findRecords(std::vector<T> records, std::function<bool(const T&)> const& lambda);