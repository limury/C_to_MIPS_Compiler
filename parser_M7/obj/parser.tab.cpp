/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_OBJ_PARSER_TAB_HPP_INCLUDED
# define YY_YY_OBJ_PARSER_TAB_HPP_INCLUDED
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


#line 120 "obj/parser.tab.cpp"

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
    T_ADD = 281,
    T_SUB = 282,
    T_XOR_ASSIGN = 283,
    T_OR_ASSIGN = 284,
    T_TYPE_NAME = 285,
    T_TYPEDEF = 286,
    T_EXTERN = 287,
    T_STATIC = 288,
    T_AUTO = 289,
    T_REGISTER = 290,
    T_CHAR = 291,
    T_SHORT = 292,
    T_INT = 293,
    T_LONG = 294,
    T_SIGNED = 295,
    T_UNSIGNED = 296,
    T_FLOAT = 297,
    T_DOUBLE = 298,
    T_CONST = 299,
    T_VOLATILE = 300,
    T_VOID = 301,
    T_STRUCT = 302,
    T_ENUM = 303,
    T_ELLIPSIS = 304,
    T_CASE = 305,
    T_DEFAULT = 306,
    T_IF = 307,
    T_ELSE = 308,
    T_SWITCH = 309,
    T_WHILE = 310,
    T_DO = 311,
    T_FOR = 312,
    T_GOTO = 313,
    T_CONTINUE = 314,
    T_BREAK = 315,
    T_RETURN = 316
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

#line 199 "obj/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_OBJ_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

#define YYUNDEFTOK  2
#define YYMAXUTOK   316

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,    73,    68,     2,
      62,    63,    69,     2,    67,     2,    66,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    81,
      74,    80,    75,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,    77,    83,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    49,    50,    51,    55,    56,    57,    58,
      59,    60,    61,    62,    66,    67,    71,    72,    73,    74,
      75,    76,    80,    81,    83,    84,    85,    89,    90,    94,
      95,    96,    97,   101,   102,   103,   107,   108,   109,   113,
     114,   115,   116,   117,   121,   122,   123,   127,   128,   132,
     133,   137,   138,   142,   143,   147,   148,   152,   153,   157,
     158,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   176,   177,   181,   185,   186,   190,   191,   192,
     193,   194,   195,   199,   200,   204,   205,   209,   210,   211,
     212,   213,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   232,   233,   234,   238,   239,   243,
     244,   248,   252,   253,   254,   255,   259,   260,   264,   265,
     266,   270,   271,   272,   276,   277,   281,   282,   286,   287,
     291,   292,   296,   297,   298,   299,   300,   301,   302,   306,
     307,   308,   309,   313,   314,   319,   320,   324,   325,   329,
     330,   331,   335,   336,   340,   341,   345,   346,   347,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   363,   364,
     365,   369,   370,   374,   375,   376,   377,   378,   379,   383,
     384,   385,   389,   390,   391,   392,   396,   397,   401,   402,
     406,   407,   411,   412,   413,   417,   418,   419,   420,   424,
     425,   426,   427,   428,   432,   435,   436,   440,   441,   445,
     446,   447,   448
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENTIFIER", "T_CONSTANT",
  "T_STRING_LITERAL", "T_PTR_OP", "T_INC_OP", "T_DEC_OP", "T_LEFT_OP",
  "T_RIGHT_OP", "T_LE_OP", "T_GE_OP", "T_EQ_OP", "T_NE_OP", "T_SIZEOF",
  "T_AND_OP", "T_OR_OP", "T_MUL_ASSIGN", "T_DIV_ASSIGN", "T_MOD_ASSIGN",
  "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_LEFT_ASSIGN", "T_RIGHT_ASSIGN",
  "T_AND_ASSIGN", "T_ADD", "T_SUB", "T_XOR_ASSIGN", "T_OR_ASSIGN",
  "T_TYPE_NAME", "T_TYPEDEF", "T_EXTERN", "T_STATIC", "T_AUTO",
  "T_REGISTER", "T_CHAR", "T_SHORT", "T_INT", "T_LONG", "T_SIGNED",
  "T_UNSIGNED", "T_FLOAT", "T_DOUBLE", "T_CONST", "T_VOLATILE", "T_VOID",
  "T_STRUCT", "T_ENUM", "T_ELLIPSIS", "T_CASE", "T_DEFAULT", "T_IF",
  "T_ELSE", "T_SWITCH", "T_WHILE", "T_DO", "T_FOR", "T_GOTO", "T_CONTINUE",
  "T_BREAK", "T_RETURN", "'('", "')'", "'['", "']'", "'.'", "','", "'&'",
  "'*'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "start", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    40,    41,    91,    93,    46,    44,    38,    42,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    58,
      61,    59,   123,   125
};
# endif

#define YYPACT_NINF -216

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-216)))

#define YYTABLE_NINF -109

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     924,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,     2,  -216,  -216,
      21,     8,     9,  -216,    14,  1185,  1185,  -216,    24,  -216,
    1185,  1070,   145,    45,    28,   924,  -216,  -216,   -61,    62,
     -32,  -216,  -216,  -216,     9,  -216,   -26,  -216,  1017,  -216,
    -216,    11,  1046,  -216,   274,  -216,    14,  -216,  1070,   970,
     222,   145,  -216,  -216,    62,    31,   -44,  -216,  -216,  -216,
    -216,     8,  -216,   568,  -216,  1070,  1046,  1046,   404,  -216,
      43,  1046,    22,  -216,  -216,   805,   805,   818,  -216,   836,
      29,    57,    82,    90,   553,   140,   209,   150,   159,   637,
     720,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   422,   166,
     836,  -216,   124,   107,   168,    52,   255,   179,   177,   187,
     240,    26,  -216,  -216,   -23,  -216,  -216,  -216,   343,   412,
    -216,  -216,  -216,  -216,   196,  -216,  -216,  -216,  -216,    79,
     217,   219,  -216,   -11,  -216,  -216,  -216,  -216,   223,   -17,
     836,    62,  -216,  -216,   568,  -216,  -216,  -216,   998,  -216,
    -216,  -216,   836,    64,  -216,   244,  -216,   553,   836,  -216,
    -216,   720,  -216,   248,   553,   836,   836,   836,   241,   651,
     221,  -216,  -216,  -216,    72,    83,   144,   275,   334,  -216,
    -216,   668,   836,   336,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,   836,  -216,   836,   836,   836,
     836,   836,   836,   836,   836,   836,   836,   836,   836,   836,
     836,   836,   836,   836,   836,   836,   836,  -216,  -216,   450,
    -216,  -216,   878,   683,  -216,   139,  -216,   155,  -216,  1165,
    -216,   337,  -216,  -216,  -216,  -216,  -216,    53,  -216,  -216,
      43,  -216,   836,  -216,   278,   553,  -216,   116,   147,   157,
     287,   651,  -216,  -216,  -216,  1091,   186,  -216,   836,  -216,
    -216,   175,  -216,   218,  -216,  -216,  -216,  -216,  -216,   124,
     124,   107,   107,   168,   168,   168,   168,    52,    52,   255,
     179,   177,   187,   240,     7,  -216,  -216,  -216,   289,   290,
    -216,   294,   155,  1131,   766,  -216,  -216,  -216,   519,  -216,
    -216,  -216,  -216,  -216,   553,   553,   553,   836,   791,  -216,
    -216,   836,  -216,   836,  -216,  -216,  -216,  -216,   291,  -216,
     295,  -216,  -216,   308,  -216,  -216,   192,   553,   195,  -216,
    -216,  -216,  -216,   553,   281,  -216,   553,  -216,  -216,  -216
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   132,   103,    87,    88,    89,    90,    91,    93,    94,
      95,    96,    99,   100,    97,    98,   128,   129,    92,   107,
       0,     0,   139,   208,     0,    77,    79,   101,     0,   102,
      81,     0,   131,     0,     0,   204,   205,   207,   123,     0,
       0,   129,   143,   141,   140,    75,     0,    83,    85,    78,
      80,   106,     0,    82,     0,   186,     0,   212,     0,     0,
       0,   130,     1,   206,     0,   126,     0,   124,   133,   144,
     142,     0,    76,     0,   210,     0,     0,   113,     0,   109,
       0,   115,     2,     3,     4,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    25,    26,   190,   182,     6,    16,    27,
       0,    29,    33,    36,    39,    44,    47,    49,    51,    53,
      55,    57,    59,    72,     0,   188,   173,   174,     0,     0,
     175,   176,   177,   178,    85,   187,   211,   152,   138,   151,
       0,   145,   147,     0,     2,   135,    27,    74,     0,     0,
       0,     0,   121,    84,     0,   168,    86,   209,     0,   112,
     105,   110,     0,     0,   116,   118,   114,     0,     0,    17,
      18,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   201,   202,     0,     0,   154,     0,     0,    12,
      13,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    61,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   184,     0,
     183,   189,     0,     0,   149,   156,   150,   157,   136,     0,
     137,     0,   134,   122,   127,   125,   171,     0,   104,   119,
       0,   111,     0,   179,     0,     0,   181,     0,     0,     0,
       0,     0,   199,   203,     5,     0,   156,   155,     0,    11,
       8,     0,    14,     0,    10,    60,    30,    31,    32,    34,
      35,    37,    38,    42,    43,    40,    41,    45,    46,    48,
      50,    52,    54,    56,     0,    73,   185,   164,     0,     0,
     160,     0,   158,     0,     0,   146,   148,   153,     0,   169,
     117,   120,    21,   180,     0,     0,     0,     0,     0,    28,
       9,     0,     7,     0,   165,   159,   161,   166,     0,   162,
       0,   170,   172,   192,   194,   195,     0,     0,     0,    15,
      58,   167,   163,     0,     0,   197,     0,   193,   196,   198
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,  -216,  -216,   -53,  -216,   -94,    84,    85,    58,
      81,   143,   146,   142,   148,   141,  -216,   -52,   -54,  -216,
     -96,   -60,    10,     0,  -216,   297,  -216,    40,  -216,  -216,
     293,   -69,   -39,  -216,   122,  -216,   302,   245,    47,    -9,
     -31,    -4,  -216,   -58,  -216,   153,  -216,   235,  -126,  -215,
    -132,  -216,   -80,  -216,   185,    19,   279,  -173,  -216,  -216,
    -216,  -216,  -216,   373,  -216
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    55,    56,    46,    47,    25,    26,    27,    28,
      78,    79,    80,   163,   164,    29,    66,    67,    30,    31,
      32,    33,    44,   298,   141,   142,   143,   187,   299,   237,
     156,   247,   125,   126,   127,    58,   129,   130,   131,   132,
     133,    34,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   140,    61,   184,   185,  -108,   261,   146,   147,   161,
      23,     1,    40,   236,   178,    48,   206,     1,    43,   155,
     302,    64,   246,   151,    38,    49,    50,    51,    62,   173,
      53,    68,   169,   170,   172,    24,   146,   147,   159,   152,
      70,    71,   166,   224,   226,    23,     1,   134,     1,   231,
     151,   302,   240,    16,    41,    72,   241,   146,   227,   139,
     267,   186,   134,   214,   215,    65,   243,    75,   135,    42,
      21,   165,   185,   128,   226,   185,    21,    22,    22,   257,
     258,   259,     1,    22,  -108,   135,   323,   253,   318,   161,
     244,    69,    77,    76,   256,    45,   273,   146,   147,    81,
     155,   167,   249,    39,   225,    21,    52,    21,   174,   146,
     147,   150,    22,   276,   277,   278,    77,    77,    77,   175,
     308,    77,   162,    81,    81,    81,   216,   217,    81,   294,
     234,   250,   186,   210,   211,   235,   309,   272,   135,   226,
      77,   232,     1,   233,   176,   251,   264,    81,    22,   231,
     226,   275,   177,   263,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   295,   301,   319,   313,   332,   212,   213,   314,
     146,   147,   266,   226,   194,   195,   196,   197,   198,   199,
     200,   201,   311,   207,   202,   203,   208,   209,    77,   146,
     147,   232,   179,   233,    61,    81,   265,    59,   233,    60,
     315,    77,   180,    22,   226,   146,    57,   303,    81,   304,
     316,   336,   338,    40,   226,   144,    83,    84,   235,    85,
      86,   181,   139,    74,   333,   334,   335,    87,   320,   139,
     182,   165,   321,   136,   330,   328,   204,   220,   265,    88,
     233,   146,   147,   221,   155,   344,   223,   345,   346,   226,
     157,   266,   226,   347,   222,   139,   349,   339,   218,   219,
     146,   340,   283,   284,   285,   286,    73,    82,    83,    84,
     238,    85,    86,   322,   100,   226,   239,   145,   242,    87,
     101,   102,   103,   104,   279,   280,   260,   281,   282,   287,
     288,    88,   262,   139,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   252,    89,    90,    91,   255,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   269,   268,   274,
     307,   312,   101,   102,   103,   104,    82,    83,    84,   317,
      85,    86,   324,   325,   341,   105,    54,   106,    87,   326,
     342,   343,   348,   289,   291,   293,   149,   290,   153,   158,
      88,   292,   310,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   306,    89,    90,    91,   245,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   254,   229,    63,     0,
       0,   101,   102,   103,   104,    82,    83,    84,     0,    85,
      86,     0,     0,     0,   105,    54,   228,    87,   188,   189,
     190,     0,     0,     0,     2,     0,     0,     0,     0,    88,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    82,    83,    84,     0,    85,    86,     0,
       0,     0,    89,    90,    91,    87,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,    88,     0,     0,
     101,   102,   103,   104,   191,     0,   192,   160,   193,     0,
       0,     0,     0,   105,    54,   230,     0,     0,     0,     0,
      89,    90,    91,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   144,    83,    84,     0,    85,    86,     0,     0,
       0,   105,    54,   296,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,    87,     0,
       0,   144,    83,    84,     0,    85,    86,     0,     0,     0,
      88,   100,     0,    87,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,   154,   331,    89,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,     0,     0,     0,     0,
     100,     0,     0,     0,   105,    54,   101,   102,   103,   104,
     144,    83,    84,     0,    85,    86,     0,     0,     0,     0,
     154,     0,    87,     0,   144,    83,    84,     0,    85,    86,
       0,     0,     0,     0,    88,     0,    87,     0,     0,     0,
       0,   144,    83,    84,     0,    85,    86,     0,    88,     0,
       0,     0,     0,    87,     0,     0,   144,    83,    84,     0,
      85,    86,     0,     0,     0,    88,     0,     0,    87,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,     0,
      88,     0,     0,   100,     0,     0,     0,     0,   183,   101,
     102,   103,   104,   144,    83,    84,     0,    85,    86,     0,
     100,   270,   105,     0,     0,    87,   101,   102,   103,   104,
       0,     0,     0,     0,     0,   100,     0,    88,   300,     0,
       2,   101,   102,   103,   104,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   144,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,    87,   100,     0,     0,     0,     0,     0,   101,   102,
     103,   104,     0,    88,   144,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    87,     0,   144,    83,
      84,     0,    85,    86,     0,     0,     0,     0,    88,     0,
      87,   144,    83,    84,     0,    85,    86,     0,   100,     0,
       0,   329,    88,    87,   101,   102,   103,   104,     0,   144,
      83,    84,     0,    85,    86,    88,     0,     0,     0,     0,
       0,    87,     0,   100,   337,     0,     0,     0,     0,   101,
     102,   103,   104,    88,     0,     0,     0,   168,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,     0,     0,
     171,     1,     0,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   297,   233,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,   138,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,   248,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    73,     0,    54,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,   265,   297,   233,     0,     0,     0,     0,
      22,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   305,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    59,    33,    99,   100,     3,   179,    60,    60,    78,
       0,     3,    21,   139,    94,    24,   110,     3,    22,    73,
     235,    82,   154,    67,     3,    25,    26,     3,     0,    89,
      30,    63,    85,    86,    87,    35,    89,    89,    77,    83,
      44,    67,    81,    17,    67,    35,     3,    56,     3,   129,
      67,   266,    63,    44,    45,    81,    67,   110,    81,    59,
     186,   100,    71,    11,    12,     3,    83,    48,    58,    22,
      62,    80,   168,    54,    67,   171,    62,    69,    69,   175,
     176,   177,     3,    69,    82,    75,    79,   167,   261,   158,
     150,    44,    52,    82,   174,    81,   192,   150,   150,    52,
     154,    79,   162,    82,    78,    62,    82,    62,    79,   162,
     162,    80,    69,   207,   208,   209,    76,    77,    78,    62,
      67,    81,    79,    76,    77,    78,    74,    75,    81,   225,
     139,    67,   171,    26,    27,   139,    83,   191,   128,    67,
     100,    62,     3,    64,    62,    81,    63,   100,    69,   229,
      67,   205,    62,    81,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   226,   233,   268,   255,   308,     9,    10,    63,
     233,   233,   186,    67,    18,    19,    20,    21,    22,    23,
      24,    25,   252,    69,    28,    29,    72,    73,   158,   252,
     252,    62,    62,    64,   235,   158,    62,    62,    64,    64,
      63,   171,     3,    69,    67,   268,    31,    62,   171,    64,
      63,   317,   318,   232,    67,     3,     4,     5,   232,     7,
       8,    81,   232,    48,   314,   315,   316,    15,    63,   239,
      81,   250,    67,    58,   304,   303,    80,    68,    62,    27,
      64,   304,   304,    76,   308,    63,    16,   337,    63,    67,
      75,   265,    67,   343,    77,   265,   346,   321,    13,    14,
     323,   323,   214,   215,   216,   217,    80,     3,     4,     5,
      63,     7,     8,    65,    62,    67,    67,    65,    65,    15,
      68,    69,    70,    71,   210,   211,    55,   212,   213,   218,
     219,    27,    81,   303,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    79,    50,    51,    52,    79,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     3,    63,     3,
       3,    63,    68,    69,    70,    71,     3,     4,     5,    62,
       7,     8,    63,    63,    63,    81,    82,    83,    15,    65,
      65,    53,    81,   220,   222,   224,    64,   221,    71,    76,
      27,   223,   250,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   239,    50,    51,    52,   151,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   171,   128,    35,    -1,
      -1,    68,    69,    70,    71,     3,     4,     5,    -1,     7,
       8,    -1,    -1,    -1,    81,    82,    83,    15,     6,     7,
       8,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    27,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    50,    51,    52,    15,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    27,    -1,    -1,
      68,    69,    70,    71,    62,    -1,    64,    83,    66,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    81,    82,    83,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,     3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,
      27,    62,    -1,    15,    -1,    -1,    -1,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    82,    83,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    81,    82,    68,    69,    70,    71,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      82,    -1,    15,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    27,    -1,    15,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,    -1,    27,    -1,
      -1,    -1,    -1,    15,    -1,    -1,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    27,    -1,    -1,    15,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    -1,
      27,    -1,    -1,    62,    -1,    -1,    -1,    -1,    81,    68,
      69,    70,    71,     3,     4,     5,    -1,     7,     8,    -1,
      62,    63,    81,    -1,    -1,    15,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    27,    65,    -1,
      30,    68,    69,    70,    71,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    -1,    27,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    27,    -1,
      15,     3,     4,     5,    -1,     7,     8,    -1,    62,    -1,
      -1,    65,    27,    15,    68,    69,    70,    71,    -1,     3,
       4,     5,    -1,     7,     8,    27,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    62,    63,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    27,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    -1,
      62,     3,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    63,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    83,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    80,    -1,    82,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    62,    69,   106,   107,   110,   111,   112,   113,   119,
     122,   123,   124,   125,   145,   146,   147,   148,     3,    82,
     123,    45,   122,   125,   126,    81,   108,   109,   123,   107,
     107,     3,    82,   107,    82,   106,   107,   138,   139,    62,
      64,   124,     0,   147,    82,     3,   120,   121,    63,   122,
     125,    67,    81,    80,   138,   139,    82,   111,   114,   115,
     116,   122,     3,     4,     5,     7,     8,    15,    27,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    68,    69,    70,    71,    81,    83,    85,    86,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   104,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   123,   106,   138,     3,    63,   107,
     127,   128,   129,   130,     3,    65,    88,   101,   105,   120,
      80,    67,    83,   109,    82,   102,   134,   138,   114,   116,
      83,   115,    79,   117,   118,   123,   116,    79,    62,    88,
      88,    62,    88,   105,    79,    62,    62,    62,   136,    62,
       3,    81,    81,    81,   104,   104,   116,   131,     6,     7,
       8,    62,    64,    66,    18,    19,    20,    21,    22,    23,
      24,    25,    28,    29,    80,   103,    90,    69,    72,    73,
      26,    27,     9,    10,    11,    12,    74,    75,    13,    14,
      68,    76,    77,    16,    17,    78,    67,    81,    83,   140,
      83,   136,    62,    64,   123,   125,   132,   133,    63,    67,
      63,    67,    65,    83,   105,   121,   134,   135,    83,   105,
      67,    81,    79,   136,   131,    79,   136,   104,   104,   104,
      55,   141,    81,    81,    63,    62,   125,   132,    63,     3,
      63,    87,   102,   104,     3,   102,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      96,    97,    98,    99,   104,   102,    83,    63,   127,   132,
      65,   105,   133,    62,    64,    49,   129,     3,    67,    83,
     118,   105,    63,   136,    63,    63,    63,    62,   141,    90,
      63,    67,    65,    79,    63,    63,    65,    63,   127,    65,
     105,    83,   134,   136,   136,   136,   104,    63,   104,   102,
     101,    63,    65,    53,    63,   136,    63,   136,    81,   136
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    91,    91,    92,    92,    92,    93,    93,    93,    94,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   112,   113,   113,   114,
     114,   115,   116,   116,   116,   116,   117,   117,   118,   118,
     118,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   130,   130,   131,   131,   132,   132,   132,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   137,
     137,   137,   138,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   143,   143,   143,   143,   144,
     144,   144,   144,   144,   145,   146,   146,   147,   147,   148,
     148,   148,   148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     2,
       3,     4,     5,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     3,
       2,     2,     2,     3,     1,     1,     2,     1,     1,     4,
       3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 48 "src/parser.y"
    { (yyval.node) = new Node(IDENTIFIER, (yyvsp[0].string)); }
#line 1751 "obj/parser.tab.cpp"
    break;

  case 3:
#line 49 "src/parser.y"
    { (yyval.node) = new Node(CONSTANT, (yyvsp[0].string)); }
#line 1757 "obj/parser.tab.cpp"
    break;

  case 4:
#line 50 "src/parser.y"
    { (yyval.node) = new Node(STRING_LIT, (yyvsp[0].string)); }
#line 1763 "obj/parser.tab.cpp"
    break;

  case 5:
#line 51 "src/parser.y"
    { (yyval.node) = new Node(expression, NodeVec{(yyvsp[-1].node)}); }
#line 1769 "obj/parser.tab.cpp"
    break;

  case 7:
#line 56 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-3].node), new Operator(L_BRACKET), (yyvsp[-1].node), new Operator(R_BRACKET) }); }
#line 1775 "obj/parser.tab.cpp"
    break;

  case 8:
#line 57 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-2].node), new Operator(L_PARENTHESES), new Operator(R_PARENTHESES)}); }
#line 1781 "obj/parser.tab.cpp"
    break;

  case 9:
#line 58 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-3].node), new Operator(L_PARENTHESES), (yyvsp[-1].node), new Operator(R_PARENTHESES) }) ; }
#line 1787 "obj/parser.tab.cpp"
    break;

  case 10:
#line 59 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-2].node), new Operator(DOT), new Node(IDENTIFIER, (yyvsp[0].string))} ); }
#line 1793 "obj/parser.tab.cpp"
    break;

  case 11:
#line 60 "src/parser.y"
    { (yyval.node) = new Node(   postfix_expression, NodeVec{  (yyvsp[-2].node), new Operator(PTR_OP), new Node(IDENTIFIER, (yyvsp[0].string))  }   ); }
#line 1799 "obj/parser.tab.cpp"
    break;

  case 12:
#line 61 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-1].node), new Operator(INC_OP)}); }
#line 1805 "obj/parser.tab.cpp"
    break;

  case 13:
#line 62 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-1].node), new Operator(DEC_OP)}); }
#line 1811 "obj/parser.tab.cpp"
    break;

  case 15:
#line 67 "src/parser.y"
    { (yyval.node) = new Node(argument_expression_list, NodeVec{(yyvsp[-2].node), new Operator(COMMA), (yyvsp[0].node)}); }
#line 1817 "obj/parser.tab.cpp"
    break;

  case 17:
#line 72 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(INC_OP), (yyvsp[0].node)} );}
#line 1823 "obj/parser.tab.cpp"
    break;

  case 18:
#line 73 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(DEC_OP), (yyvsp[0].node)} );}
#line 1829 "obj/parser.tab.cpp"
    break;

  case 19:
#line 74 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{(yyvsp[-1].node), (yyvsp[0].node)} ); }
#line 1835 "obj/parser.tab.cpp"
    break;

  case 20:
#line 75 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(SIZEOF), (yyvsp[0].node)} ); }
#line 1841 "obj/parser.tab.cpp"
    break;

  case 21:
#line 76 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(SIZEOF),new Operator(L_PARENTHESES), (yyvsp[-1].node), new Operator(R_PARENTHESES),} ); }
#line 1847 "obj/parser.tab.cpp"
    break;

  case 22:
#line 80 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(BIN_AND)} ); }
#line 1853 "obj/parser.tab.cpp"
    break;

  case 23:
#line 81 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(MULT)} ); }
#line 1859 "obj/parser.tab.cpp"
    break;

  case 24:
#line 83 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(MINUS)} ); }
#line 1865 "obj/parser.tab.cpp"
    break;

  case 25:
#line 84 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(BIN_NOT)} ); }
#line 1871 "obj/parser.tab.cpp"
    break;

  case 26:
#line 85 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(LOGICAL_NOT)} ); }
#line 1877 "obj/parser.tab.cpp"
    break;

  case 28:
#line 90 "src/parser.y"
    { (yyval.node) = new Node( cast_expression, NodeVec{  new Operator(L_PARENTHESES), (yyvsp[-2].node), new Operator(R_PARENTHESES), (yyvsp[0].node)  } ); }
#line 1883 "obj/parser.tab.cpp"
    break;

  case 30:
#line 95 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(MULT), (yyvsp[0].node) } ); }
#line 1889 "obj/parser.tab.cpp"
    break;

  case 31:
#line 96 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(DIVIDE), (yyvsp[0].node) } ); }
#line 1895 "obj/parser.tab.cpp"
    break;

  case 32:
#line 97 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(MODULO), (yyvsp[0].node) } ); }
#line 1901 "obj/parser.tab.cpp"
    break;

  case 34:
#line 102 "src/parser.y"
    { (yyval.node) = new Node( additive_expression, NodeVec{ (yyvsp[-2].node), opGen(PLUS), (yyvsp[0].node) } ); }
#line 1907 "obj/parser.tab.cpp"
    break;

  case 35:
#line 103 "src/parser.y"
    { (yyval.node) = new Node( additive_expression, NodeVec{ (yyvsp[-2].node), opGen(MINUS), (yyvsp[0].node) } ); }
#line 1913 "obj/parser.tab.cpp"
    break;

  case 37:
#line 108 "src/parser.y"
    { (yyval.node) = new Node( shift_expression, NodeVec{ (yyvsp[-2].node), opGen(LEFT_OP), (yyvsp[0].node)} ); }
#line 1919 "obj/parser.tab.cpp"
    break;

  case 38:
#line 109 "src/parser.y"
    { (yyval.node) = new Node( shift_expression, NodeVec{ (yyvsp[-2].node), opGen(RIGHT_OP), (yyvsp[0].node)} ); }
#line 1925 "obj/parser.tab.cpp"
    break;

  case 40:
#line 114 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(LT), (yyvsp[0].node) } );}
#line 1931 "obj/parser.tab.cpp"
    break;

  case 41:
#line 115 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(GT), (yyvsp[0].node) } );}
#line 1937 "obj/parser.tab.cpp"
    break;

  case 42:
#line 116 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(LE_OP), (yyvsp[0].node) } );}
#line 1943 "obj/parser.tab.cpp"
    break;

  case 43:
#line 117 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(GE_OP), (yyvsp[0].node) } );}
#line 1949 "obj/parser.tab.cpp"
    break;

  case 45:
#line 122 "src/parser.y"
    { (yyval.node) = new Node( equality_expression, NodeVec{ (yyvsp[-2].node), opGen(EQ_OP), (yyvsp[0].node) } );}
#line 1955 "obj/parser.tab.cpp"
    break;

  case 46:
#line 123 "src/parser.y"
    { (yyval.node) = new Node( equality_expression, NodeVec{ (yyvsp[-2].node), opGen(NE_OP), (yyvsp[0].node) } );}
#line 1961 "obj/parser.tab.cpp"
    break;

  case 48:
#line 128 "src/parser.y"
    { (yyval.node) = new Node( and_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_AND), (yyvsp[0].node) } );}
#line 1967 "obj/parser.tab.cpp"
    break;

  case 50:
#line 133 "src/parser.y"
    { (yyval.node) = new Node( exclusive_or_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_XOR), (yyvsp[0].node) } );}
#line 1973 "obj/parser.tab.cpp"
    break;

  case 52:
#line 138 "src/parser.y"
    { (yyval.node) = new Node( inclusive_or_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_OR), (yyvsp[0].node) } );}
#line 1979 "obj/parser.tab.cpp"
    break;

  case 54:
#line 143 "src/parser.y"
    { (yyval.node) = new Node( logical_and_expression, NodeVec{ (yyvsp[-2].node), opGen(AND_OP), (yyvsp[0].node) } );}
#line 1985 "obj/parser.tab.cpp"
    break;

  case 56:
#line 148 "src/parser.y"
    { (yyval.node) = new Node( logical_or_expression, NodeVec{ (yyvsp[-2].node), opGen(OR_OP), (yyvsp[0].node) } ); }
#line 1991 "obj/parser.tab.cpp"
    break;

  case 58:
#line 153 "src/parser.y"
    { (yyval.node) = new Node( conditional_expression, NodeVec{ (yyvsp[-4].node), opGen(QUESTION_MARK), (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } );}
#line 1997 "obj/parser.tab.cpp"
    break;

  case 60:
#line 158 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } );}
#line 2003 "obj/parser.tab.cpp"
    break;

  case 61:
#line 162 "src/parser.y"
    { (yyval.node) = opGen(EQUALS); }
#line 2009 "obj/parser.tab.cpp"
    break;

  case 62:
#line 163 "src/parser.y"
    { (yyval.node) = opGen(MUL_ASSIGN); }
#line 2015 "obj/parser.tab.cpp"
    break;

  case 63:
#line 164 "src/parser.y"
    { (yyval.node) = opGen(DIV_ASSIGN); }
#line 2021 "obj/parser.tab.cpp"
    break;

  case 64:
#line 165 "src/parser.y"
    { (yyval.node) = opGen(MOD_ASSIGN); }
#line 2027 "obj/parser.tab.cpp"
    break;

  case 65:
#line 166 "src/parser.y"
    { (yyval.node) = opGen(ADD_ASSIGN); }
#line 2033 "obj/parser.tab.cpp"
    break;

  case 66:
#line 167 "src/parser.y"
    { (yyval.node) = opGen(SUB_ASSIGN); }
#line 2039 "obj/parser.tab.cpp"
    break;

  case 67:
#line 168 "src/parser.y"
    { (yyval.node) = opGen(LEFT_ASSIGN); }
#line 2045 "obj/parser.tab.cpp"
    break;

  case 68:
#line 169 "src/parser.y"
    { (yyval.node) = opGen(RIGHT_ASSIGN); }
#line 2051 "obj/parser.tab.cpp"
    break;

  case 69:
#line 170 "src/parser.y"
    { (yyval.node) = opGen(AND_ASSIGN); }
#line 2057 "obj/parser.tab.cpp"
    break;

  case 70:
#line 171 "src/parser.y"
    { (yyval.node) = opGen(XOR_ASSIGN); }
#line 2063 "obj/parser.tab.cpp"
    break;

  case 71:
#line 172 "src/parser.y"
    { (yyval.node) = opGen(OR_ASSIGN); }
#line 2069 "obj/parser.tab.cpp"
    break;

  case 73:
#line 177 "src/parser.y"
    { (yyval.node) = new Node( expression, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2075 "obj/parser.tab.cpp"
    break;

  case 75:
#line 185 "src/parser.y"
    { (yyval.node) = new Node( declaration, NodeVec{ (yyvsp[-1].node), opGen(SEMICOLON) } );  }
#line 2081 "obj/parser.tab.cpp"
    break;

  case 76:
#line 186 "src/parser.y"
    { (yyval.node) = new Node( declaration, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2087 "obj/parser.tab.cpp"
    break;

  case 77:
#line 190 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[0].node) } ); }
#line 2093 "obj/parser.tab.cpp"
    break;

  case 78:
#line 191 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2099 "obj/parser.tab.cpp"
    break;

  case 79:
#line 192 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[0].node) } ); }
#line 2105 "obj/parser.tab.cpp"
    break;

  case 80:
#line 193 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2111 "obj/parser.tab.cpp"
    break;

  case 81:
#line 194 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[0].node) } ); }
#line 2117 "obj/parser.tab.cpp"
    break;

  case 82:
#line 195 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2123 "obj/parser.tab.cpp"
    break;

  case 84:
#line 200 "src/parser.y"
    { (yyval.node) = new Node( init_declarator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2129 "obj/parser.tab.cpp"
    break;

  case 86:
#line 205 "src/parser.y"
    { (yyval.node) = new Node( init_declarator, NodeVec{ (yyvsp[-2].node), opGen(EQUALS), (yyvsp[0].node) } ); }
#line 2135 "obj/parser.tab.cpp"
    break;

  case 87:
#line 209 "src/parser.y"
    { (yyval.node) = opGen(TYPEDEF); }
#line 2141 "obj/parser.tab.cpp"
    break;

  case 88:
#line 210 "src/parser.y"
    { (yyval.node) = opGen(EXTERN); }
#line 2147 "obj/parser.tab.cpp"
    break;

  case 89:
#line 211 "src/parser.y"
    { (yyval.node) = opGen(STATIC); }
#line 2153 "obj/parser.tab.cpp"
    break;

  case 90:
#line 212 "src/parser.y"
    { (yyval.node) = opGen(AUTO); }
#line 2159 "obj/parser.tab.cpp"
    break;

  case 91:
#line 213 "src/parser.y"
    { (yyval.node) = opGen(REGISTER); }
#line 2165 "obj/parser.tab.cpp"
    break;

  case 92:
#line 217 "src/parser.y"
    { (yyval.node) = opGen(VOID); }
#line 2171 "obj/parser.tab.cpp"
    break;

  case 93:
#line 218 "src/parser.y"
    { (yyval.node) = opGen(CHAR); }
#line 2177 "obj/parser.tab.cpp"
    break;

  case 94:
#line 219 "src/parser.y"
    { (yyval.node) = opGen(SHORT); }
#line 2183 "obj/parser.tab.cpp"
    break;

  case 95:
#line 220 "src/parser.y"
    { (yyval.node) = opGen(INT); }
#line 2189 "obj/parser.tab.cpp"
    break;

  case 96:
#line 221 "src/parser.y"
    { (yyval.node) = opGen(LONG); }
#line 2195 "obj/parser.tab.cpp"
    break;

  case 97:
#line 222 "src/parser.y"
    { (yyval.node) = opGen(FLOAT); }
#line 2201 "obj/parser.tab.cpp"
    break;

  case 98:
#line 223 "src/parser.y"
    { (yyval.node) = opGen(DOUBLE); }
#line 2207 "obj/parser.tab.cpp"
    break;

  case 99:
#line 224 "src/parser.y"
    { (yyval.node) = opGen(SIGNED); }
#line 2213 "obj/parser.tab.cpp"
    break;

  case 100:
#line 225 "src/parser.y"
    { (yyval.node) = opGen(UNSIGNED); }
#line 2219 "obj/parser.tab.cpp"
    break;

  case 103:
#line 228 "src/parser.y"
    { (yyval.node) = opGen(TYPE_NAME); }
#line 2225 "obj/parser.tab.cpp"
    break;

  case 104:
#line 232 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-4].node), new Node(IDENTIFIER, (yyvsp[-3].string)), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE)  } ); }
#line 2231 "obj/parser.tab.cpp"
    break;

  case 105:
#line 233 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-3].node), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2237 "obj/parser.tab.cpp"
    break;

  case 106:
#line 234 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-1].node), new Node(IDENTIFIER, (yyvsp[0].string)) } ); }
#line 2243 "obj/parser.tab.cpp"
    break;

  case 107:
#line 238 "src/parser.y"
    { (yyval.node) = opGen(STRUCT); }
#line 2249 "obj/parser.tab.cpp"
    break;

  case 108:
#line 239 "src/parser.y"
    { (yyval.node) = opGen(UNION); }
#line 2255 "obj/parser.tab.cpp"
    break;

  case 110:
#line 244 "src/parser.y"
    { (yyval.node) = new Node( struct_declaration_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2261 "obj/parser.tab.cpp"
    break;

  case 111:
#line 248 "src/parser.y"
    { (yyval.node) = new Node( struct_declaration, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2267 "obj/parser.tab.cpp"
    break;

  case 112:
#line 252 "src/parser.y"
    { (yyval.node) = new Node( specifier_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2273 "obj/parser.tab.cpp"
    break;

  case 114:
#line 254 "src/parser.y"
    { (yyval.node) = new Node( specifier_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2279 "obj/parser.tab.cpp"
    break;

  case 117:
#line 260 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2285 "obj/parser.tab.cpp"
    break;

  case 119:
#line 265 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator, NodeVec{ opGen(COLON), (yyvsp[0].node) } ); }
#line 2291 "obj/parser.tab.cpp"
    break;

  case 120:
#line 266 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator, NodeVec{ (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } ); }
#line 2297 "obj/parser.tab.cpp"
    break;

  case 121:
#line 270 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2303 "obj/parser.tab.cpp"
    break;

  case 122:
#line 271 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, (yyvsp[-3].string) ), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2309 "obj/parser.tab.cpp"
    break;

  case 123:
#line 272 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, (yyvsp[0].string) ) } ); }
#line 2315 "obj/parser.tab.cpp"
    break;

  case 125:
#line 277 "src/parser.y"
    { (yyval.node) = new Node( enumerator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ) ; }
#line 2321 "obj/parser.tab.cpp"
    break;

  case 126:
#line 281 "src/parser.y"
    { (yyval.node) = new Node( IDENTIFIER, (yyvsp[0].string) ); }
#line 2327 "obj/parser.tab.cpp"
    break;

  case 127:
#line 282 "src/parser.y"
    { (yyval.node) = new Node( enumerator, NodeVec{ new Node(IDENTIFIER, (yyvsp[-2].string)), opGen(EQUALS), (yyvsp[0].node) } ); }
#line 2333 "obj/parser.tab.cpp"
    break;

  case 128:
#line 286 "src/parser.y"
    { (yyval.node) = opGen(CONST); }
#line 2339 "obj/parser.tab.cpp"
    break;

  case 129:
#line 287 "src/parser.y"
    { (yyval.node) = opGen(VOLATILE); }
#line 2345 "obj/parser.tab.cpp"
    break;

  case 130:
#line 291 "src/parser.y"
    { (yyval.node) = new Node( declarator, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2351 "obj/parser.tab.cpp"
    break;

  case 132:
#line 296 "src/parser.y"
    { (yyval.node) = new Node(IDENTIFIER, (yyvsp[0].string)); }
#line 2357 "obj/parser.tab.cpp"
    break;

  case 133:
#line 297 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2363 "obj/parser.tab.cpp"
    break;

  case 134:
#line 298 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2369 "obj/parser.tab.cpp"
    break;

  case 135:
#line 299 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2375 "obj/parser.tab.cpp"
    break;

  case 136:
#line 300 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2381 "obj/parser.tab.cpp"
    break;

  case 137:
#line 301 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2387 "obj/parser.tab.cpp"
    break;

  case 138:
#line 302 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2393 "obj/parser.tab.cpp"
    break;

  case 139:
#line 306 "src/parser.y"
    { (yyval.node) = opGen(MULT); }
#line 2399 "obj/parser.tab.cpp"
    break;

  case 140:
#line 307 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[0].node) } ); }
#line 2405 "obj/parser.tab.cpp"
    break;

  case 141:
#line 308 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[0].node) } ); }
#line 2411 "obj/parser.tab.cpp"
    break;

  case 142:
#line 309 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2417 "obj/parser.tab.cpp"
    break;

  case 144:
#line 314 "src/parser.y"
    { (yyval.node) = new Node( type_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2423 "obj/parser.tab.cpp"
    break;

  case 146:
#line 320 "src/parser.y"
    { (yyval.node) = new Node( parameter_type_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), opGen(ELLIPSIS) } ); }
#line 2429 "obj/parser.tab.cpp"
    break;

  case 148:
#line 325 "src/parser.y"
    { (yyval.node) = new Node( parameter_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2435 "obj/parser.tab.cpp"
    break;

  case 149:
#line 329 "src/parser.y"
    { (yyval.node) = new Node( parameter_declaration, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2441 "obj/parser.tab.cpp"
    break;

  case 150:
#line 330 "src/parser.y"
    { (yyval.node) = new Node( parameter_declaration, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2447 "obj/parser.tab.cpp"
    break;

  case 152:
#line 335 "src/parser.y"
    { (yyval.node) = new Node( IDENTIFIER, (yyvsp[0].string) ); }
#line 2453 "obj/parser.tab.cpp"
    break;

  case 153:
#line 336 "src/parser.y"
    { (yyval.node) = new Node( identifier_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), new Node(IDENTIFIER, (yyvsp[0].string)) } ); }
#line 2459 "obj/parser.tab.cpp"
    break;

  case 155:
#line 341 "src/parser.y"
    { (yyval.node) = new Node( type_name, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2465 "obj/parser.tab.cpp"
    break;

  case 158:
#line 347 "src/parser.y"
    { (yyval.node) = new Node( abstract_declarator, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2471 "obj/parser.tab.cpp"
    break;

  case 159:
#line 351 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2477 "obj/parser.tab.cpp"
    break;

  case 160:
#line 352 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2483 "obj/parser.tab.cpp"
    break;

  case 161:
#line 353 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2489 "obj/parser.tab.cpp"
    break;

  case 162:
#line 354 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2495 "obj/parser.tab.cpp"
    break;

  case 163:
#line 355 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2501 "obj/parser.tab.cpp"
    break;

  case 164:
#line 356 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2507 "obj/parser.tab.cpp"
    break;

  case 165:
#line 357 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2513 "obj/parser.tab.cpp"
    break;

  case 166:
#line 358 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2519 "obj/parser.tab.cpp"
    break;

  case 167:
#line 359 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2525 "obj/parser.tab.cpp"
    break;

  case 169:
#line 364 "src/parser.y"
    { (yyval.node) = new Node( initializer, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2531 "obj/parser.tab.cpp"
    break;

  case 170:
#line 365 "src/parser.y"
    { (yyval.node) = new Node( initializer, NodeVec{ opGen(L_BRACE), (yyvsp[-2].node), opGen(COMMA), opGen(R_BRACE) } ); }
#line 2537 "obj/parser.tab.cpp"
    break;

  case 172:
#line 370 "src/parser.y"
    { (yyval.node) = new Node( initializer_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2543 "obj/parser.tab.cpp"
    break;

  case 179:
#line 383 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ new Node(IDENTIFIER, (yyvsp[-2].string)), opGen(COLON), (yyvsp[0].node) } ); }
#line 2549 "obj/parser.tab.cpp"
    break;

  case 180:
#line 384 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ opGen(CASE), (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } ); }
#line 2555 "obj/parser.tab.cpp"
    break;

  case 181:
#line 385 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ opGen(DEFAULT), opGen(COLON), (yyvsp[0].node) } ); }
#line 2561 "obj/parser.tab.cpp"
    break;

  case 182:
#line 389 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), opGen(R_BRACE) } ); }
#line 2567 "obj/parser.tab.cpp"
    break;

  case 183:
#line 390 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2573 "obj/parser.tab.cpp"
    break;

  case 184:
#line 391 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2579 "obj/parser.tab.cpp"
    break;

  case 185:
#line 392 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-2].node), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2585 "obj/parser.tab.cpp"
    break;

  case 187:
#line 397 "src/parser.y"
    { (yyval.node) = new Node( declaration_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2591 "obj/parser.tab.cpp"
    break;

  case 189:
#line 402 "src/parser.y"
    { (yyval.node) = new Node( statement_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2597 "obj/parser.tab.cpp"
    break;

  case 190:
#line 406 "src/parser.y"
    { (yyval.node) = opGen(SEMICOLON); }
#line 2603 "obj/parser.tab.cpp"
    break;

  case 191:
#line 407 "src/parser.y"
    { (yyval.node) = new Node( expression_statement, NodeVec{ (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2609 "obj/parser.tab.cpp"
    break;

  case 192:
#line 411 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2615 "obj/parser.tab.cpp"
    break;

  case 193:
#line 412 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), (yyvsp[-4].node), opGen(R_PARENTHESES), (yyvsp[-2].node), opGen(ELSE), (yyvsp[0].node) } ); }
#line 2621 "obj/parser.tab.cpp"
    break;

  case 194:
#line 413 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(SWITCH), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2627 "obj/parser.tab.cpp"
    break;

  case 195:
#line 417 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(WHILE), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2633 "obj/parser.tab.cpp"
    break;

  case 196:
#line 418 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(DO), (yyvsp[-5].node), opGen(WHILE), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), opGen(SEMICOLON) } ); }
#line 2639 "obj/parser.tab.cpp"
    break;

  case 197:
#line 419 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), (yyvsp[-3].node), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2645 "obj/parser.tab.cpp"
    break;

  case 198:
#line 420 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2651 "obj/parser.tab.cpp"
    break;

  case 199:
#line 424 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(GOTO), new Node(IDENTIFIER, (yyvsp[-1].string)), opGen(SEMICOLON) } ); }
#line 2657 "obj/parser.tab.cpp"
    break;

  case 200:
#line 425 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(CONTINUE), opGen(SEMICOLON) } ); }
#line 2663 "obj/parser.tab.cpp"
    break;

  case 201:
#line 426 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(BREAK), opGen(SEMICOLON) } ); }
#line 2669 "obj/parser.tab.cpp"
    break;

  case 202:
#line 427 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(RETURN), opGen(SEMICOLON) } ); }
#line 2675 "obj/parser.tab.cpp"
    break;

  case 203:
#line 428 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(RETURN), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2681 "obj/parser.tab.cpp"
    break;

  case 204:
#line 432 "src/parser.y"
    { root = (yyvsp[0].node); }
#line 2687 "obj/parser.tab.cpp"
    break;

  case 206:
#line 436 "src/parser.y"
    { (yyval.node) = new Node( translation_unit, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2693 "obj/parser.tab.cpp"
    break;

  case 208:
#line 441 "src/parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 2699 "obj/parser.tab.cpp"
    break;

  case 209:
#line 445 "src/parser.y"
    {  (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2705 "obj/parser.tab.cpp"
    break;

  case 210:
#line 446 "src/parser.y"
    {  (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2711 "obj/parser.tab.cpp"
    break;

  case 211:
#line 447 "src/parser.y"
    {  (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2717 "obj/parser.tab.cpp"
    break;

  case 212:
#line 448 "src/parser.y"
    { (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2723 "obj/parser.tab.cpp"
    break;


#line 2727 "obj/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 451 "src/parser.y"

#include <stdio.h>

extern char yytext[];
extern int column;

NodePtr root;

NodePtr parseAST(){
    root == nullptr;
    std::cout << "Parsing beginning" << std::endl;
    yyparse();
    std::cout << "Parsing done" << std::endl;
    
    return root;
}
