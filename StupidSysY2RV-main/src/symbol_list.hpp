#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <koopa.h>

class BaseAST;

struct LValSymbol
{
    enum SymbolType
    {
        Const,
        Var,
        Array,
        Pointer,
        Function
    } type;
    void *number;
    LValSymbol() {}
    LValSymbol(SymbolType _type, void * _number) : type(_type), number(_number) {}
};

class SymbolList
{
    std::vector<std::map<std::string, LValSymbol>> sym_stk;

public:
    void NewEnv()
    {
        sym_stk.push_back(std::map<std::string, LValSymbol>());
    }
    void AddSymbol(const std::string &name, LValSymbol koopa_item)
    {
        auto &list = sym_stk[sym_stk.size() - 1];
        assert(list.count(name) == 0);
        list[name] = koopa_item;
    }
    LValSymbol GetSymbol(const std::string &name)
    {
        LValSymbol res;
        for (size_t i = sym_stk.size() - 1; i >= 0; i--)
            if (sym_stk[i].count(name) != 0)
            {
                res = sym_stk[i][name];
                break;
            }
        return res;
    }
    void DeleteEnv()
    {
        sym_stk.pop_back();
    }
};






/*
 #pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <iostream> // 用于输出

#include <koopa.h>

class BaseAST;

struct LValSymbol
{
    enum SymbolType
    {
        Const,
        Var,
        Array,
        Pointer,
        Function
    } type;
    void *number;
    LValSymbol() {}
    LValSymbol(SymbolType _type, void *_number) : type(_type), number(_number) {}
};

class SymbolList
{
    std::vector<std::map<std::string, LValSymbol>> sym_stk;

public:
    void NewEnv()
    {
        sym_stk.push_back(std::map<std::string, LValSymbol>());
    }

    void AddSymbol(const std::string &name, LValSymbol koopa_item)
    {
        auto &list = sym_stk[sym_stk.size() - 1];
        assert(list.count(name) == 0);
        list[name] = koopa_item;
    }

    LValSymbol GetSymbol(const std::string &name)
    {
        LValSymbol res;
        for (int i = sym_stk.size() - 1; i >= 0; i--)
        {
            if (sym_stk[i].count(name) != 0)
            {
                res = sym_stk[i][name];
                break;
            }
        }
        return res;
    }

    void DeleteEnv()
    {
        if (!sym_stk.empty())
        {
            // 输出当前基本块中的符号
            PrintCurrentBlock();

            // 删除当前基本块
            sym_stk.pop_back();
        }
    }

private:
    void PrintCurrentBlock()
    {
        if (sym_stk.empty())
            return;

        const auto &current_block = sym_stk.back();
        std::cout << "Current Block Symbols:" << std::endl;
        for (const auto &[name, symbol] : current_block)
        {
            std::cout << "Name: " << name << ", Type: " << SymbolTypeToString(symbol.type) << std::endl;
        }
    }

    std::string SymbolTypeToString(LValSymbol::SymbolType type)
    {
        switch (type)
        {
        case LValSymbol::Const:
            return "Const";
        case LValSymbol::Var:
            return "Var";
        case LValSymbol::Array:
            return "Array";
        case LValSymbol::Pointer:
            return "Pointer";
        case LValSymbol::Function:
            return "Function";
        default:
            return "Unknown";
        }
    }
};
*/