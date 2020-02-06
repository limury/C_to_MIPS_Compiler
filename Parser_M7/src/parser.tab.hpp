/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"



    #include "../include/Node.hpp"
    #include <cassert>

    inline Operator* opGen(OperatorEnum _op){
        return new Operator(_op);
    }

    extern NodePtr root;
//    extern YYSTYPE yylval;

    int yylex(void);
    void yyerror(const char *);


#line 66 "src/parser.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IDENTIFIER = 258,
    T_CONSTANT = 259,
    T_STRING_LITERAL = 260,
    T_PTR_OP = 261,
    T_INC_OP = 262,
    T_DEC_OP = 263,
    T_LEFT_OP = 264,
    T_RIGHT_OP = 265,
    T_LE_OP = 266,
    T_GE_OP = 267,
    T_EQ_OP = 268,
    T_NE_OP = 269,
    T_SIZEOF = 270,
    T_AND_OP = 271,
    T_OR_OP = 272,
    T_MUL_ASSIGN = 273,
    T_DIV_ASSIGN = 274,
    T_MOD_ASSIGN = 275,
    T_ADD_ASSIGN = 276,
    T_SUB_ASSIGN = 277,
    T_LEFT_ASSIGN = 278,
    T_RIGHT_ASSIGN = 279,
    T_AND_ASSIGN = 280,
    T_XOR_ASSIGN = 281,
    T_OR_ASSIGN = 282,
    T_TYPE_NAME = 283,
    T_TYPEDEF = 284,
    T_EXTERN = 285,
    T_STATIC = 286,
    T_AUTO = 287,
    T_REGISTER = 288,
    T_CHAR = 289,
    T_SHORT = 290,
    T_INT = 291,
    T_LONG = 292,
    T_SIGNED = 293,
    T_UNSIGNED = 294,
    T_FLOAT = 295,
    T_DOUBLE = 296,
    T_CONST = 297,
    T_VOLATILE = 298,
    T_VOID = 299,
    T_STRUCT = 300,
    T_ENUM = 301,
    T_ELLIPSIS = 302,
    T_CASE = 303,
    T_DEFAULT = 304,
    T_IF = 305,
    T_ELSE = 306,
    T_SWITCH = 307,
    T_WHILE = 308,
    T_DO = 309,
    T_FOR = 310,
    T_GOTO = 311,
    T_CONTINUE = 312,
    T_BREAK = 313,
    T_RETURN = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "src/parser.y"

    NodePtr node;
    yytokentype token;
    std::string* string;

#line 143 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
