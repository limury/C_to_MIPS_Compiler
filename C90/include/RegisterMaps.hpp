#ifndef REG_MAPS_HPP
#define REG_MAPS_HPP

// register definitions
#define $zero 0
#define $0 0
#define $1 1
#define $at 1
#define $2 2
#define $v0 2
#define $3 3
#define $v1 3
#define $4 4
#define $a0 4
#define $5 5
#define $a1 5
#define $6 6
#define $a2 6
#define $7 7
#define $a3 7
#define $8 8
#define $t0 8 
#define $9 9
#define $t1 9
#define $10 10
#define $t2 10
#define $11 11
#define $t3 11
#define $12 12
#define $t4 12
#define $13 13
#define $t5 13
#define $14 14
#define $t6 14
#define $15 15
#define $t7 15
#define $16 16
#define $s0 16
#define $17 17
#define $s1 17
#define $18 18
#define $s2 18
#define $19 19
#define $s3 19
#define $20 20
#define $s4 20
#define $21 21
#define $s5 21
#define $22 22
#define $s6 22
#define $23 23
#define $s7 23
#define $24 24
#define $t8 24
#define $25 25
#define $t9 25
#define $26 26
#define $k0 26
#define $27 27
#define $k1 27
#define $28 28
#define $gp 28
#define $29 29
#define $sp 29
#define $30 30
#define $fp 30
#define $31 31
#define $ra 31
#define $f0 32
#define $f1 33
#define $f2 34
#define $f3 35
#define $f4 36
#define $f5 37
#define $f6 38
#define $f7 39
#define $f8 40
#define $f9 41
#define $f10 42
#define $f11 43
#define $f12 44
#define $f13 45
#define $f14 46
#define $f15 47
#define $f16 48
#define $f17 49
#define $f18 50
#define $f19 51
#define $f20 52
#define $f21 53
#define $f22 54
#define $f23 55
#define $f24 56
#define $f25 57
#define $f26 58
#define $f27 59
#define $f28 60
#define $f29 61
#define $f30 62
#define $f31 63

static std::map<int, std::string> regMap = {
    {0, "$zero"},
    {1, "$at"},
    {2, "$v0"},
    {3, "$v1"},
    {4, "$a0"},
    {5, "$a1"},
    {6, "$a2"},
    {7, "$a3"},
    {8, "$t0"},
    {9, "$t1"},
    {10, "$t2"},
    {11, "$t3"},
    {12, "$t4"},
    {13, "$t5"},
    {14, "$t6"},
    {15, "$t7"},
    {16, "$s0"},
    {17, "$s1"},
    {18, "$s2"},
    {19, "$s3"},
    {20, "$s4"},
    {21, "$s5"},
    {22, "$s6"},
    {23, "$s7"},
    {24, "$t8"},
    {25, "$t9"},
    {26, "$k0"},
    {27, "$k1"},
    {28, "$gp"},
    {29, "$sp"},
    {30, "$fp"},
    {31, "$ra"},
    {32, "$f0"},
    {33, "$f1"},
    {34, "$f2"},
    {35, "$f3"},
    {36, "$f4"},
    {37, "$f5"},
    {38, "$f6"},
    {39, "$f7"},
    {40, "$f8"},
    {41, "$f9"},
    {42, "$f10"},
    {43, "$f11"},
    {44, "$f12"},
    {45, "$f13"},
    {46, "$f14"},
    {47, "$f15"},
    {48, "$f16"},
    {49, "$f17"},
    {50, "$f18"},
    {51, "$f19"},
    {52, "$f20"},
    {53, "$f21"},
    {54, "$f22"},
    {55, "$f23"},
    {56, "$f24"},
    {57, "$f25"},
    {58, "$f26"},
    {59, "$f27"},
    {60, "$f28"},
    {61, "$f29"},
    {62, "$f30"},
    {63, "$f31"}
};

#endif