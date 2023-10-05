#pragma once

#include <stdexcept>
#include <string>

class MatrixException : public std::exception {
public:
    MatrixException(const std::string& message) : message_(message) {}

    virtual const char* what() const noexcept {
        return message_.c_str();
    }

private:
    std::string message_;
};

class DivisionByZeroException : public MatrixException {
public:
    DivisionByZeroException() : MatrixException("Попытка деления на ноль") {}
};

class InsufficientDataException : public MatrixException {
public:
    InsufficientDataException() : MatrixException("Недостаточно данных для выполнения операции") {}
};

class InvalidInputException : public MatrixException {
public:
    InvalidInputException() : MatrixException("Некорректные входные данные") {}
};