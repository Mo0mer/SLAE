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
    DivisionByZeroException() : MatrixException("������� ������� �� ����") {}
};

class InsufficientDataException : public MatrixException {
public:
    InsufficientDataException() : MatrixException("������������ ������ ��� ���������� ��������") {}
};

class InvalidInputException : public MatrixException {
public:
    InvalidInputException() : MatrixException("������������ ������� ������") {}
};