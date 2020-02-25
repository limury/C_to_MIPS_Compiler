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


#line 117 "parser.tab.c"

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
    T_XOR_ASSIGN = 282,
    T_OR_ASSIGN = 283,
    T_TYPE_NAME = 284,
    T_TYPEDEF = 285,
    T_EXTERN = 286,
    T_STATIC = 287,
    T_AUTO = 288,
    T_REGISTER = 289,
    T_CHAR = 290,
    T_SHORT = 291,
    T_INT = 292,
    T_LONG = 293,
    T_SIGNED = 294,
    T_UNSIGNED = 295,
    T_FLOAT = 296,
    T_DOUBLE = 297,
    T_CONST = 298,
    T_VOLATILE = 299,
    T_VOID = 300,
    T_STRUCT = 301,
    T_ENUM = 302,
    T_ELLIPSIS = 303,
    T_CASE = 304,
    T_DEFAULT = 305,
    T_IF = 306,
    T_ELSE = 307,
    T_SWITCH = 308,
    T_WHILE = 309,
    T_DO = 310,
    T_FOR = 311,
    T_GOTO = 312,
    T_CONTINUE = 313,
    T_BREAK = 314,
    T_RETURN = 315
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

#line 195 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYLAST   1364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
       2,     2,     2,    71,     2,     2,     2,    73,    67,     2,
      61,    62,    68,     2,    66,    69,    65,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    81,
      74,    80,    75,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    76,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    49,    50,    51,    55,    56,    57,    58,
      59,    60,    61,    62,    66,    67,    71,    72,    73,    74,
      75,    76,    80,    81,    82,    83,    84,    85,    89,    90,
      94,    95,    96,    97,   101,   102,   103,   107,   108,   109,
     113,   114,   115,   116,   117,   121,   122,   123,   127,   128,
     132,   133,   137,   138,   142,   143,   147,   148,   152,   153,
     157,   158,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   176,   177,   181,   185,   186,   190,   191,
     192,   193,   194,   195,   199,   200,   204,   205,   209,   210,
     211,   212,   213,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   232,   233,   234,   238,   239,
     243,   244,   248,   252,   253,   254,   255,   259,   260,   264,
     265,   266,   270,   271,   272,   276,   277,   281,   282,   286,
     287,   291,   292,   296,   297,   298,   299,   300,   301,   302,
     306,   307,   308,   309,   313,   314,   319,   320,   324,   325,
     329,   330,   331,   335,   336,   340,   341,   345,   346,   347,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   363,
     364,   365,   369,   370,   374,   375,   376,   377,   378,   379,
     383,   384,   385,   389,   390,   391,   392,   396,   397,   401,
     402,   406,   407,   411,   412,   413,   417,   418,   419,   420,
     424,   425,   426,   427,   428,   432,   435,   436,   440,   441,
     445,   446,   447,   448
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
  "T_AND_ASSIGN", "T_ADD", "T_XOR_ASSIGN", "T_OR_ASSIGN", "T_TYPE_NAME",
  "T_TYPEDEF", "T_EXTERN", "T_STATIC", "T_AUTO", "T_REGISTER", "T_CHAR",
  "T_SHORT", "T_INT", "T_LONG", "T_SIGNED", "T_UNSIGNED", "T_FLOAT",
  "T_DOUBLE", "T_CONST", "T_VOLATILE", "T_VOID", "T_STRUCT", "T_ENUM",
  "T_ELLIPSIS", "T_CASE", "T_DEFAULT", "T_IF", "T_ELSE", "T_SWITCH",
  "T_WHILE", "T_DO", "T_FOR", "T_GOTO", "T_CONTINUE", "T_BREAK",
  "T_RETURN", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
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
     315,    40,    41,    91,    93,    46,    44,    38,    42,    45,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    58,
      61,    59,   123,   125
};
# endif

#define YYPACT_NINF -213

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-213)))

#define YYTABLE_NINF -110

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1003,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,    18,  -213,  -213,
      24,   127,    39,  -213,    66,  1317,  1317,  -213,    36,  -213,
    1317,  1169,    90,    17,    11,  1003,  -213,  -213,   -41,    19,
     -11,  -213,  -213,  -213,    39,  -213,    27,  -213,  1150,  -213,
    -213,   -12,  1125,  -213,   276,  -213,    66,  -213,  1169,  1048,
     756,    90,  -213,  -213,    19,     6,   -20,  -213,  -213,  -213,
    -213,   127,  -213,   593,  -213,  1169,  1125,  1125,  1076,  -213,
      41,  1125,    15,  -213,  -213,   878,   878,   902,  -213,   915,
      33,    79,    82,    85,   556,    93,   189,   116,   129,   625,
     709,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,   212,
     423,   915,  -213,   118,     5,   115,   173,   200,   158,   152,
     161,   233,    -1,  -213,  -213,    38,  -213,  -213,  -213,   345,
     414,  -213,  -213,  -213,  -213,   174,  -213,  -213,  -213,  -213,
      81,   194,   191,  -213,    75,  -213,  -213,  -213,  -213,   197,
     -18,   915,    19,  -213,  -213,   593,  -213,  -213,  -213,  1095,
    -213,  -213,  -213,   915,    47,  -213,   184,  -213,   556,   915,
    -213,  -213,   709,  -213,   186,   556,   915,   915,   915,   215,
     640,   193,  -213,  -213,  -213,    51,   136,   126,   208,   273,
    -213,  -213,   780,   915,   275,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,   915,  -213,   915,   915,
     915,   915,   915,   915,   915,   915,   915,   915,   915,   915,
     915,   915,   915,   915,   915,   915,   915,   915,  -213,  -213,
     451,  -213,  -213,   958,   793,  -213,     3,  -213,   117,  -213,
    1297,  -213,   279,  -213,  -213,  -213,  -213,  -213,   -10,  -213,
    -213,    41,  -213,   915,  -213,   227,   556,  -213,   137,   143,
     146,   229,   640,  -213,  -213,  -213,  1223,   171,  -213,   915,
    -213,  -213,   149,  -213,   175,  -213,  -213,  -213,  -213,  -213,
     118,   118,     5,     5,   115,   115,   115,   115,   173,   173,
     200,   158,   152,   161,   233,    26,  -213,  -213,  -213,   230,
     231,  -213,   232,   117,  1263,   806,  -213,  -213,  -213,   520,
    -213,  -213,  -213,  -213,  -213,   556,   556,   556,   915,   830,
    -213,  -213,   915,  -213,   915,  -213,  -213,  -213,  -213,   235,
    -213,   234,  -213,  -213,   242,  -213,  -213,   164,   556,   165,
    -213,  -213,  -213,  -213,   556,   214,  -213,   556,  -213,  -213,
    -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   104,    88,    89,    90,    91,    92,    94,    95,
      96,    97,   100,   101,    98,    99,   129,   130,    93,   108,
       0,     0,   140,   209,     0,    78,    80,   102,     0,   103,
      82,     0,   132,     0,     0,   205,   206,   208,   124,     0,
       0,   130,   144,   142,   141,    76,     0,    84,    86,    79,
      81,   107,     0,    83,     0,   187,     0,   213,     0,     0,
       0,   131,     1,   207,     0,   127,     0,   125,   134,   145,
     143,     0,    77,     0,   211,     0,     0,   114,     0,   110,
       0,   116,     2,     3,     4,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    25,    26,    27,   191,   183,     6,    16,
      28,     0,    30,    34,    37,    40,    45,    48,    50,    52,
      54,    56,    58,    60,    73,     0,   189,   174,   175,     0,
       0,   176,   177,   178,   179,    86,   188,   212,   153,   139,
     152,     0,   146,   148,     0,     2,   136,    28,    75,     0,
       0,     0,     0,   122,    85,     0,   169,    87,   210,     0,
     113,   106,   111,     0,     0,   117,   119,   115,     0,     0,
      17,    18,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   202,   203,     0,     0,   155,     0,     0,
      12,    13,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    62,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   185,
       0,   184,   190,     0,     0,   150,   157,   151,   158,   137,
       0,   138,     0,   135,   123,   128,   126,   172,     0,   105,
     120,     0,   112,     0,   180,     0,     0,   182,     0,     0,
       0,     0,     0,   200,   204,     5,     0,   157,   156,     0,
      11,     8,     0,    14,     0,    10,    61,    31,    32,    33,
      35,    36,    38,    39,    43,    44,    41,    42,    46,    47,
      49,    51,    53,    55,    57,     0,    74,   186,   165,     0,
       0,   161,     0,   159,     0,     0,   147,   149,   154,     0,
     170,   118,   121,    21,   181,     0,     0,     0,     0,     0,
      29,     9,     0,     7,     0,   166,   160,   162,   167,     0,
     163,     0,   171,   173,   193,   195,   196,     0,     0,     0,
      15,    59,   168,   164,     0,     0,   198,     0,   194,   197,
     199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,   -53,  -213,   -94,    32,    37,    70,
      40,    78,   102,    77,   104,    76,  -213,   -52,   -54,  -213,
     -97,   -60,    10,     0,  -213,   267,  -213,   -24,  -213,  -213,
     263,   -69,   -39,  -213,    52,  -213,   277,   188,    45,    -9,
     -29,    -4,  -213,   -58,  -213,   111,  -213,   170,  -127,  -212,
    -132,  -213,   -80,  -213,   148,    -5,   225,  -175,  -213,  -213,
    -213,  -213,  -213,   320,  -213
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   108,   109,   272,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   206,
     125,   149,    55,    56,    46,    47,    25,    26,    27,    28,
      78,    79,    80,   164,   165,    29,    66,    67,    30,    31,
      32,    33,    44,   299,   142,   143,   144,   188,   300,   238,
     157,   248,   126,   127,   128,    58,   130,   131,   132,   133,
     134,    34,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   141,   185,   186,    61,   262,     1,   147,   148,   162,
      23,    62,    40,   237,   179,    48,   225,   207,    43,   156,
       1,  -109,    65,   247,   303,    49,    50,    38,    77,   174,
      53,   211,   170,   171,   173,    24,   147,   148,   160,    51,
      70,    64,   167,    75,     1,    23,   152,   135,   152,   129,
     232,    68,    77,    77,    77,   303,   309,    77,   147,   140,
     268,   187,   135,   153,   233,   244,   234,    42,   136,     1,
      76,   166,   186,   310,   212,   186,    77,   226,    21,   258,
     259,   260,    16,    41,     1,   136,   151,   319,   254,    69,
     162,   245,   227,    71,   168,   257,   274,    81,   147,   148,
    -109,   156,    21,   250,   227,   324,    39,    22,    72,    22,
     147,   148,   175,   251,   277,   278,   279,   227,    52,   228,
     163,    81,    81,    81,   213,   214,    81,    21,   252,   295,
       1,   235,   264,   187,    22,    77,   236,   241,   273,   136,
     176,   242,   233,   177,   234,    81,   178,    45,    77,    22,
     232,    59,   276,    60,   180,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   296,   302,   320,   314,   333,   304,    57,
     305,   147,   148,   267,   215,   216,   208,   266,    21,   234,
     209,   210,   181,   312,    22,    22,    74,   182,   265,   315,
     147,   148,   227,   227,    81,   316,   137,    61,   317,   227,
     183,   321,   227,   219,   220,   322,   147,    81,   189,   190,
     191,   337,   339,   158,    40,   221,   345,   347,   222,   236,
     227,   227,   266,   140,   234,   334,   335,   336,   223,   323,
     140,   227,   166,   280,   281,   331,   329,   217,   218,   224,
     282,   283,   147,   148,    73,   156,   239,   240,   346,   288,
     289,   243,   267,   253,   348,   256,   140,   350,   340,   261,
     269,   147,   341,   192,   263,   193,   270,   194,   275,    82,
      83,    84,   308,    85,    86,   284,   285,   286,   287,   313,
     318,    87,   325,   326,   344,   349,   327,   342,   343,   290,
     292,   294,    88,   311,   140,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   291,    89,    90,    91,   293,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   154,   159,
     246,   150,   255,   101,   102,   103,   104,   105,    82,    83,
      84,   307,    85,    86,   230,    63,     0,   106,    54,   107,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    89,    90,    91,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,    82,    83,    84,
       0,    85,    86,     0,     0,     0,   106,    54,   229,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,   195,   196,   197,   198,   199,   200,   201,   202,     0,
     203,   204,     0,     0,    82,    83,    84,     0,    85,    86,
       0,     0,     0,    89,    90,    91,    87,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,    88,     0,     0,
       0,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,    54,   231,     0,     0,
      89,    90,    91,   205,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   145,    83,    84,     0,    85,    86,     0,
       0,     0,   106,    54,   297,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,    88,     0,     0,     0,     0,   101,   102,   103,
     104,   105,     0,     0,     0,     0,   145,    83,    84,     0,
      85,    86,   155,   332,     0,    89,    90,    91,    87,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     0,    88,
       0,     0,     0,   101,   102,   103,   104,   105,   145,    83,
      84,     0,    85,    86,     0,     0,     0,   106,    54,     0,
      87,     0,     0,   145,    83,    84,     0,    85,    86,     0,
       0,    88,     0,     0,   100,    87,     0,     0,     0,     0,
     101,   102,   103,   104,   105,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,     0,     0,     0,
       0,   100,     0,     0,     0,     0,   184,   101,   102,   103,
     104,   105,   145,    83,    84,     0,    85,    86,     0,     0,
       0,   106,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     2,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,   145,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
     100,    87,     0,     0,     0,     0,   101,   102,   103,   104,
     105,     0,    88,   145,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,    87,   145,    83,    84,     0,
      85,    86,     0,     0,     0,     0,    88,     0,    87,   145,
      83,    84,     0,    85,    86,     0,     0,   100,     0,    88,
     146,    87,     0,   101,   102,   103,   104,   105,     0,     0,
       0,     0,    88,   145,    83,    84,     0,    85,    86,     0,
       0,   100,   271,     0,     0,    87,     0,   101,   102,   103,
     104,   105,     0,     0,   100,     0,    88,   301,     0,     0,
     101,   102,   103,   104,   105,     0,     0,   100,     0,     0,
     330,     0,     0,   101,   102,   103,   104,   105,     0,     0,
       0,   145,    83,    84,     0,    85,    86,     0,     0,     0,
       0,   100,   338,    87,     0,     0,     0,   101,   102,   103,
     104,   105,     0,     0,    88,   145,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,    87,   145,    83,
      84,     0,    85,    86,     0,     0,     0,     0,    88,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,   169,
       0,    88,     0,     0,     0,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,   172,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,     0,     0,   100,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     298,   234,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
     139,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     2,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,   161,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,   249,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   298,   234,     0,     0,     0,
       0,    22,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   328,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   306,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    59,    99,   100,    33,   180,     3,    60,    60,    78,
       0,     0,    21,   140,    94,    24,    17,   111,    22,    73,
       3,     3,     3,   155,   236,    25,    26,     3,    52,    89,
      30,    26,    85,    86,    87,    35,    89,    89,    77,     3,
      44,    82,    81,    48,     3,    35,    66,    56,    66,    54,
     130,    62,    76,    77,    78,   267,    66,    81,   111,    59,
     187,   100,    71,    83,    61,    83,    63,    22,    58,     3,
      82,    80,   169,    83,    69,   172,   100,    78,    61,   176,
     177,   178,    43,    44,     3,    75,    80,   262,   168,    44,
     159,   151,    66,    66,    79,   175,   193,    52,   151,   151,
      82,   155,    61,   163,    66,    79,    82,    68,    81,    68,
     163,   163,    79,    66,   208,   209,   210,    66,    82,    81,
      79,    76,    77,    78,     9,    10,    81,    61,    81,   226,
       3,   140,    81,   172,    68,   159,   140,    62,   192,   129,
      61,    66,    61,    61,    63,   100,    61,    81,   172,    68,
     230,    61,   206,    63,    61,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   227,   234,   269,   256,   309,    61,    31,
      63,   234,   234,   187,    11,    12,    68,    61,    61,    63,
      72,    73,     3,   253,    68,    68,    48,    81,    62,    62,
     253,   253,    66,    66,   159,    62,    58,   236,    62,    66,
      81,    62,    66,    13,    14,    66,   269,   172,     6,     7,
       8,   318,   319,    75,   233,    67,    62,    62,    76,   233,
      66,    66,    61,   233,    63,   315,   316,   317,    77,    64,
     240,    66,   251,   211,   212,   305,   304,    74,    75,    16,
     213,   214,   305,   305,    80,   309,    62,    66,   338,   219,
     220,    64,   266,    79,   344,    79,   266,   347,   322,    54,
      62,   324,   324,    61,    81,    63,     3,    65,     3,     3,
       4,     5,     3,     7,     8,   215,   216,   217,   218,    62,
      61,    15,    62,    62,    52,    81,    64,    62,    64,   221,
     223,   225,    26,   251,   304,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   222,    49,    50,    51,   224,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    71,    76,
     152,    64,   172,    67,    68,    69,    70,    71,     3,     4,
       5,   240,     7,     8,   129,    35,    -1,    81,    82,    83,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    81,    82,    83,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    49,    50,    51,    15,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    26,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      49,    50,    51,    80,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    81,    82,    83,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    26,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,    82,    83,    -1,    49,    50,    51,    15,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    26,
      -1,    -1,    -1,    67,    68,    69,    70,    71,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    81,    82,    -1,
      15,    -1,    -1,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    26,    -1,    -1,    61,    15,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    81,    67,    68,    69,
      70,    71,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    81,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      61,    15,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    -1,    26,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    26,    -1,    15,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    61,    -1,    26,
      64,    15,    -1,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    26,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    61,    62,    -1,    -1,    15,    -1,    67,    68,    69,
      70,    71,    -1,    -1,    61,    -1,    26,    64,    -1,    -1,
      67,    68,    69,    70,    71,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,
      -1,    61,    62,    15,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    -1,    -1,    26,     3,     4,     5,    -1,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    26,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    26,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      62,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    29,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    83,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    83,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    61,    68,   106,   107,   110,   111,   112,   113,   119,
     122,   123,   124,   125,   145,   146,   147,   148,     3,    82,
     123,    44,   122,   125,   126,    81,   108,   109,   123,   107,
     107,     3,    82,   107,    82,   106,   107,   138,   139,    61,
      63,   124,     0,   147,    82,     3,   120,   121,    62,   122,
     125,    66,    81,    80,   138,   139,    82,   111,   114,   115,
     116,   122,     3,     4,     5,     7,     8,    15,    26,    49,
      50,    51,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    67,    68,    69,    70,    71,    81,    83,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   104,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   123,   106,   138,     3,    62,
     107,   127,   128,   129,   130,     3,    64,    88,   101,   105,
     120,    80,    66,    83,   109,    82,   102,   134,   138,   114,
     116,    83,   115,    79,   117,   118,   123,   116,    79,    61,
      88,    88,    61,    88,   105,    79,    61,    61,    61,   136,
      61,     3,    81,    81,    81,   104,   104,   116,   131,     6,
       7,     8,    61,    63,    65,    18,    19,    20,    21,    22,
      23,    24,    25,    27,    28,    80,   103,    90,    68,    72,
      73,    26,    69,     9,    10,    11,    12,    74,    75,    13,
      14,    67,    76,    77,    16,    17,    78,    66,    81,    83,
     140,    83,   136,    61,    63,   123,   125,   132,   133,    62,
      66,    62,    66,    64,    83,   105,   121,   134,   135,    83,
     105,    66,    81,    79,   136,   131,    79,   136,   104,   104,
     104,    54,   141,    81,    81,    62,    61,   125,   132,    62,
       3,    62,    87,   102,   104,     3,   102,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    96,    97,    98,    99,   104,   102,    83,    62,   127,
     132,    64,   105,   133,    61,    63,    48,   129,     3,    66,
      83,   118,   105,    62,   136,    62,    62,    62,    61,   141,
      90,    62,    66,    64,    79,    62,    62,    64,    62,   127,
      64,   105,    83,   134,   136,   136,   136,   104,    62,   104,
     102,   101,    62,    64,    52,    62,   136,    62,   136,    81,
     136
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    93,    93,    93,
      94,    94,    94,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   115,   116,   116,   116,   116,   117,   117,   118,
     118,   118,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   134,
     134,   134,   135,   135,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   142,   143,   143,   143,   143,
     144,   144,   144,   144,   144,   145,   146,   146,   147,   147,
     148,   148,   148,   148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     1,     2,     1,     1,
       4,     3,     3,     2
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
    { std::cout << "found identifier\n"; (yyval.node) = new Node(IDENTIFIER, (yyvsp[0].string)); }
#line 1776 "parser.tab.c"
    break;

  case 3:
#line 49 "src/parser.y"
    { std::cout << "found constant\n"; (yyval.node) = new Node(CONSTANT, (yyvsp[0].string)); }
#line 1782 "parser.tab.c"
    break;

  case 4:
#line 50 "src/parser.y"
    { (yyval.node) = new Node(STRING_LIT, (yyvsp[0].string)); }
#line 1788 "parser.tab.c"
    break;

  case 5:
#line 51 "src/parser.y"
    { (yyval.node) = new Node(expression, NodeVec{(yyvsp[-1].node)}); }
#line 1794 "parser.tab.c"
    break;

  case 7:
#line 56 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-3].node), new Operator(L_BRACKET), (yyvsp[-1].node), new Operator(R_BRACKET) }); }
#line 1800 "parser.tab.c"
    break;

  case 8:
#line 57 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-2].node), new Operator(L_PARENTHESES), new Operator(R_PARENTHESES)}); }
#line 1806 "parser.tab.c"
    break;

  case 9:
#line 58 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-3].node), new Operator(L_PARENTHESES), (yyvsp[-1].node), new Operator(R_PARENTHESES) }) ; }
#line 1812 "parser.tab.c"
    break;

  case 10:
#line 59 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-2].node), new Operator(DOT), new Node(IDENTIFIER, (yyvsp[0].string))} ); }
#line 1818 "parser.tab.c"
    break;

  case 11:
#line 60 "src/parser.y"
    { (yyval.node) = new Node(   postfix_expression, NodeVec{  (yyvsp[-2].node), new Operator(PTR_OP), new Node(IDENTIFIER, (yyvsp[0].string))  }   ); }
#line 1824 "parser.tab.c"
    break;

  case 12:
#line 61 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-1].node), new Operator(INC_OP)}); }
#line 1830 "parser.tab.c"
    break;

  case 13:
#line 62 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-1].node), new Operator(DEC_OP)}); }
#line 1836 "parser.tab.c"
    break;

  case 15:
#line 67 "src/parser.y"
    { (yyval.node) = new Node(argument_expression_list, NodeVec{(yyvsp[-2].node), new Operator(COMMA), (yyvsp[0].node)}); }
#line 1842 "parser.tab.c"
    break;

  case 17:
#line 72 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(INC_OP), (yyvsp[0].node)} );}
#line 1848 "parser.tab.c"
    break;

  case 18:
#line 73 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(DEC_OP), (yyvsp[0].node)} );}
#line 1854 "parser.tab.c"
    break;

  case 19:
#line 74 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{(yyvsp[-1].node), (yyvsp[0].node)} ); }
#line 1860 "parser.tab.c"
    break;

  case 20:
#line 75 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(SIZEOF), (yyvsp[0].node)} ); }
#line 1866 "parser.tab.c"
    break;

  case 21:
#line 76 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(SIZEOF),new Operator(L_PARENTHESES), (yyvsp[-1].node), new Operator(R_PARENTHESES),} ); }
#line 1872 "parser.tab.c"
    break;

  case 22:
#line 80 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(BIN_AND)} ); }
#line 1878 "parser.tab.c"
    break;

  case 23:
#line 81 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(MULT)} ); }
#line 1884 "parser.tab.c"
    break;

  case 24:
#line 82 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(PLUS)} ); }
#line 1890 "parser.tab.c"
    break;

  case 25:
#line 83 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(MINUS)} ); }
#line 1896 "parser.tab.c"
    break;

  case 26:
#line 84 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(BIN_NOT)} ); }
#line 1902 "parser.tab.c"
    break;

  case 27:
#line 85 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(LOGICAL_NOT)} ); }
#line 1908 "parser.tab.c"
    break;

  case 29:
#line 90 "src/parser.y"
    { (yyval.node) = new Node( cast_expression, NodeVec{  new Operator(L_PARENTHESES), (yyvsp[-2].node), new Operator(R_PARENTHESES), (yyvsp[0].node)  } ); }
#line 1914 "parser.tab.c"
    break;

  case 31:
#line 95 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(MULT), (yyvsp[0].node) } ); }
#line 1920 "parser.tab.c"
    break;

  case 32:
#line 96 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(DIVIDE), (yyvsp[0].node) } ); }
#line 1926 "parser.tab.c"
    break;

  case 33:
#line 97 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(MODULO), (yyvsp[0].node) } ); }
#line 1932 "parser.tab.c"
    break;

  case 35:
#line 102 "src/parser.y"
    { std::cout << "found addition"; (yyval.node) = new Node( additive_expression, NodeVec{ (yyvsp[-2].node), opGen(PLUS), (yyvsp[0].node) } ); }
#line 1938 "parser.tab.c"
    break;

  case 36:
#line 103 "src/parser.y"
    { (yyval.node) = new Node( additive_expression, NodeVec{ (yyvsp[-2].node), opGen(MINUS), (yyvsp[0].node) } ); }
#line 1944 "parser.tab.c"
    break;

  case 38:
#line 108 "src/parser.y"
    { (yyval.node) = new Node( shift_expression, NodeVec{ (yyvsp[-2].node), opGen(LEFT_OP), (yyvsp[0].node)} ); }
#line 1950 "parser.tab.c"
    break;

  case 39:
#line 109 "src/parser.y"
    { (yyval.node) = new Node( shift_expression, NodeVec{ (yyvsp[-2].node), opGen(RIGHT_OP), (yyvsp[0].node)} ); }
#line 1956 "parser.tab.c"
    break;

  case 41:
#line 114 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(LT), (yyvsp[0].node) } );}
#line 1962 "parser.tab.c"
    break;

  case 42:
#line 115 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(GT), (yyvsp[0].node) } );}
#line 1968 "parser.tab.c"
    break;

  case 43:
#line 116 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(LE_OP), (yyvsp[0].node) } );}
#line 1974 "parser.tab.c"
    break;

  case 44:
#line 117 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(GE_OP), (yyvsp[0].node) } );}
#line 1980 "parser.tab.c"
    break;

  case 46:
#line 122 "src/parser.y"
    { (yyval.node) = new Node( equality_expression, NodeVec{ (yyvsp[-2].node), opGen(EQ_OP), (yyvsp[0].node) } );}
#line 1986 "parser.tab.c"
    break;

  case 47:
#line 123 "src/parser.y"
    { (yyval.node) = new Node( equality_expression, NodeVec{ (yyvsp[-2].node), opGen(NE_OP), (yyvsp[0].node) } );}
#line 1992 "parser.tab.c"
    break;

  case 49:
#line 128 "src/parser.y"
    { (yyval.node) = new Node( and_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_AND), (yyvsp[0].node) } );}
#line 1998 "parser.tab.c"
    break;

  case 51:
#line 133 "src/parser.y"
    { (yyval.node) = new Node( exclusive_or_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_XOR), (yyvsp[0].node) } );}
#line 2004 "parser.tab.c"
    break;

  case 53:
#line 138 "src/parser.y"
    { (yyval.node) = new Node( inclusive_or_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_OR), (yyvsp[0].node) } );}
#line 2010 "parser.tab.c"
    break;

  case 55:
#line 143 "src/parser.y"
    { (yyval.node) = new Node( logical_and_expression, NodeVec{ (yyvsp[-2].node), opGen(AND_OP), (yyvsp[0].node) } );}
#line 2016 "parser.tab.c"
    break;

  case 57:
#line 148 "src/parser.y"
    { (yyval.node) = new Node( logical_or_expression, NodeVec{ (yyvsp[-2].node), opGen(OR_OP), (yyvsp[0].node) } ); }
#line 2022 "parser.tab.c"
    break;

  case 59:
#line 153 "src/parser.y"
    { (yyval.node) = new Node( conditional_expression, NodeVec{ (yyvsp[-4].node), opGen(QUESTION_MARK), (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } );}
#line 2028 "parser.tab.c"
    break;

  case 61:
#line 158 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } );}
#line 2034 "parser.tab.c"
    break;

  case 62:
#line 162 "src/parser.y"
    { (yyval.node) = opGen(EQUALS); }
#line 2040 "parser.tab.c"
    break;

  case 63:
#line 163 "src/parser.y"
    { (yyval.node) = opGen(MUL_ASSIGN); }
#line 2046 "parser.tab.c"
    break;

  case 64:
#line 164 "src/parser.y"
    { (yyval.node) = opGen(DIV_ASSIGN); }
#line 2052 "parser.tab.c"
    break;

  case 65:
#line 165 "src/parser.y"
    { (yyval.node) = opGen(MOD_ASSIGN); }
#line 2058 "parser.tab.c"
    break;

  case 66:
#line 166 "src/parser.y"
    { (yyval.node) = opGen(ADD_ASSIGN); }
#line 2064 "parser.tab.c"
    break;

  case 67:
#line 167 "src/parser.y"
    { (yyval.node) = opGen(SUB_ASSIGN); }
#line 2070 "parser.tab.c"
    break;

  case 68:
#line 168 "src/parser.y"
    { (yyval.node) = opGen(LEFT_ASSIGN); }
#line 2076 "parser.tab.c"
    break;

  case 69:
#line 169 "src/parser.y"
    { (yyval.node) = opGen(RIGHT_ASSIGN); }
#line 2082 "parser.tab.c"
    break;

  case 70:
#line 170 "src/parser.y"
    { (yyval.node) = opGen(AND_ASSIGN); }
#line 2088 "parser.tab.c"
    break;

  case 71:
#line 171 "src/parser.y"
    { (yyval.node) = opGen(XOR_ASSIGN); }
#line 2094 "parser.tab.c"
    break;

  case 72:
#line 172 "src/parser.y"
    { (yyval.node) = opGen(OR_ASSIGN); }
#line 2100 "parser.tab.c"
    break;

  case 74:
#line 177 "src/parser.y"
    { (yyval.node) = new Node( expression, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2106 "parser.tab.c"
    break;

  case 76:
#line 185 "src/parser.y"
    { (yyval.node) = new Node( declaration, NodeVec{ (yyvsp[-1].node), opGen(SEMICOLON) } );  }
#line 2112 "parser.tab.c"
    break;

  case 77:
#line 186 "src/parser.y"
    { (yyval.node) = new Node( declaration, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2118 "parser.tab.c"
    break;

  case 79:
#line 191 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2124 "parser.tab.c"
    break;

  case 81:
#line 193 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2130 "parser.tab.c"
    break;

  case 83:
#line 195 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2136 "parser.tab.c"
    break;

  case 85:
#line 200 "src/parser.y"
    { (yyval.node) = new Node( init_declarator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2142 "parser.tab.c"
    break;

  case 87:
#line 205 "src/parser.y"
    { (yyval.node) = new Node( init_declarator, NodeVec{ (yyvsp[-2].node), opGen(EQUALS), (yyvsp[0].node) } ); }
#line 2148 "parser.tab.c"
    break;

  case 88:
#line 209 "src/parser.y"
    { (yyval.node) = opGen(TYPEDEF); }
#line 2154 "parser.tab.c"
    break;

  case 89:
#line 210 "src/parser.y"
    { (yyval.node) = opGen(EXTERN); }
#line 2160 "parser.tab.c"
    break;

  case 90:
#line 211 "src/parser.y"
    { (yyval.node) = opGen(STATIC); }
#line 2166 "parser.tab.c"
    break;

  case 91:
#line 212 "src/parser.y"
    { (yyval.node) = opGen(AUTO); }
#line 2172 "parser.tab.c"
    break;

  case 92:
#line 213 "src/parser.y"
    { (yyval.node) = opGen(REGISTER); }
#line 2178 "parser.tab.c"
    break;

  case 93:
#line 217 "src/parser.y"
    { (yyval.node) = opGen(VOID); }
#line 2184 "parser.tab.c"
    break;

  case 94:
#line 218 "src/parser.y"
    { (yyval.node) = opGen(CHAR); }
#line 2190 "parser.tab.c"
    break;

  case 95:
#line 219 "src/parser.y"
    { (yyval.node) = opGen(SHORT); }
#line 2196 "parser.tab.c"
    break;

  case 96:
#line 220 "src/parser.y"
    { (yyval.node) = opGen(INT); }
#line 2202 "parser.tab.c"
    break;

  case 97:
#line 221 "src/parser.y"
    { (yyval.node) = opGen(LONG); }
#line 2208 "parser.tab.c"
    break;

  case 98:
#line 222 "src/parser.y"
    { (yyval.node) = opGen(FLOAT); }
#line 2214 "parser.tab.c"
    break;

  case 99:
#line 223 "src/parser.y"
    { (yyval.node) = opGen(DOUBLE); }
#line 2220 "parser.tab.c"
    break;

  case 100:
#line 224 "src/parser.y"
    { (yyval.node) = opGen(SIGNED); }
#line 2226 "parser.tab.c"
    break;

  case 101:
#line 225 "src/parser.y"
    { (yyval.node) = opGen(UNSIGNED); }
#line 2232 "parser.tab.c"
    break;

  case 104:
#line 228 "src/parser.y"
    { (yyval.node) = opGen(TYPE_NAME); }
#line 2238 "parser.tab.c"
    break;

  case 105:
#line 232 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-4].node), new Node(IDENTIFIER, (yyvsp[-3].string)), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE)  } ); }
#line 2244 "parser.tab.c"
    break;

  case 106:
#line 233 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-3].node), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2250 "parser.tab.c"
    break;

  case 107:
#line 234 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-1].node), new Node(IDENTIFIER, (yyvsp[0].string)) } ); }
#line 2256 "parser.tab.c"
    break;

  case 108:
#line 238 "src/parser.y"
    { (yyval.node) = opGen(STRUCT); }
#line 2262 "parser.tab.c"
    break;

  case 109:
#line 239 "src/parser.y"
    { (yyval.node) = opGen(UNION); }
#line 2268 "parser.tab.c"
    break;

  case 111:
#line 244 "src/parser.y"
    { (yyval.node) = new Node( struct_declaration_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2274 "parser.tab.c"
    break;

  case 112:
#line 248 "src/parser.y"
    { (yyval.node) = new Node( struct_declaration, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2280 "parser.tab.c"
    break;

  case 113:
#line 252 "src/parser.y"
    { (yyval.node) = new Node( specifier_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2286 "parser.tab.c"
    break;

  case 115:
#line 254 "src/parser.y"
    { (yyval.node) = new Node( specifier_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2292 "parser.tab.c"
    break;

  case 118:
#line 260 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2298 "parser.tab.c"
    break;

  case 120:
#line 265 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator, NodeVec{ opGen(COLON), (yyvsp[0].node) } ); }
#line 2304 "parser.tab.c"
    break;

  case 121:
#line 266 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator, NodeVec{ (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } ); }
#line 2310 "parser.tab.c"
    break;

  case 122:
#line 270 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2316 "parser.tab.c"
    break;

  case 123:
#line 271 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, (yyvsp[-3].string) ), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2322 "parser.tab.c"
    break;

  case 124:
#line 272 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, (yyvsp[0].string) ) } ); }
#line 2328 "parser.tab.c"
    break;

  case 126:
#line 277 "src/parser.y"
    { (yyval.node) = new Node( enumerator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ) ; }
#line 2334 "parser.tab.c"
    break;

  case 127:
#line 281 "src/parser.y"
    { (yyval.node) = new Node( IDENTIFIER, (yyvsp[0].string) ); }
#line 2340 "parser.tab.c"
    break;

  case 128:
#line 282 "src/parser.y"
    { (yyval.node) = new Node( enumerator, NodeVec{ new Node(IDENTIFIER, (yyvsp[-2].string)), opGen(EQUALS), (yyvsp[0].node) } ); }
#line 2346 "parser.tab.c"
    break;

  case 129:
#line 286 "src/parser.y"
    { (yyval.node) = opGen(CONST); }
#line 2352 "parser.tab.c"
    break;

  case 130:
#line 287 "src/parser.y"
    { (yyval.node) = opGen(VOLATILE); }
#line 2358 "parser.tab.c"
    break;

  case 131:
#line 291 "src/parser.y"
    { (yyval.node) = new Node( declarator, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2364 "parser.tab.c"
    break;

  case 133:
#line 296 "src/parser.y"
    { (yyval.node) = new Node(IDENTIFIER, (yyvsp[0].string)); }
#line 2370 "parser.tab.c"
    break;

  case 134:
#line 297 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2376 "parser.tab.c"
    break;

  case 135:
#line 298 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2382 "parser.tab.c"
    break;

  case 136:
#line 299 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2388 "parser.tab.c"
    break;

  case 137:
#line 300 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2394 "parser.tab.c"
    break;

  case 138:
#line 301 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2400 "parser.tab.c"
    break;

  case 139:
#line 302 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2406 "parser.tab.c"
    break;

  case 140:
#line 306 "src/parser.y"
    { (yyval.node) = opGen(MULT); }
#line 2412 "parser.tab.c"
    break;

  case 141:
#line 307 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[0].node) } ); }
#line 2418 "parser.tab.c"
    break;

  case 142:
#line 308 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[0].node) } ); }
#line 2424 "parser.tab.c"
    break;

  case 143:
#line 309 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2430 "parser.tab.c"
    break;

  case 145:
#line 314 "src/parser.y"
    { (yyval.node) = new Node( type_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2436 "parser.tab.c"
    break;

  case 147:
#line 320 "src/parser.y"
    { (yyval.node) = new Node( parameter_type_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), opGen(ELLIPSIS) } ); }
#line 2442 "parser.tab.c"
    break;

  case 149:
#line 325 "src/parser.y"
    { (yyval.node) = new Node( parameter_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2448 "parser.tab.c"
    break;

  case 150:
#line 329 "src/parser.y"
    { (yyval.node) = new Node( parameter_declaration, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2454 "parser.tab.c"
    break;

  case 151:
#line 330 "src/parser.y"
    { (yyval.node) = new Node( parameter_declaration, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2460 "parser.tab.c"
    break;

  case 153:
#line 335 "src/parser.y"
    { (yyval.node) = new Node( IDENTIFIER, (yyvsp[0].string) ); }
#line 2466 "parser.tab.c"
    break;

  case 154:
#line 336 "src/parser.y"
    { (yyval.node) = new Node( identifier_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), new Node(IDENTIFIER, (yyvsp[0].string)) } ); }
#line 2472 "parser.tab.c"
    break;

  case 156:
#line 341 "src/parser.y"
    { (yyval.node) = new Node( type_name, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2478 "parser.tab.c"
    break;

  case 159:
#line 347 "src/parser.y"
    { (yyval.node) = new Node( abstract_declarator, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2484 "parser.tab.c"
    break;

  case 160:
#line 351 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2490 "parser.tab.c"
    break;

  case 161:
#line 352 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2496 "parser.tab.c"
    break;

  case 162:
#line 353 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2502 "parser.tab.c"
    break;

  case 163:
#line 354 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2508 "parser.tab.c"
    break;

  case 164:
#line 355 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2514 "parser.tab.c"
    break;

  case 165:
#line 356 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2520 "parser.tab.c"
    break;

  case 166:
#line 357 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2526 "parser.tab.c"
    break;

  case 167:
#line 358 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2532 "parser.tab.c"
    break;

  case 168:
#line 359 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2538 "parser.tab.c"
    break;

  case 170:
#line 364 "src/parser.y"
    { (yyval.node) = new Node( initializer, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2544 "parser.tab.c"
    break;

  case 171:
#line 365 "src/parser.y"
    { (yyval.node) = new Node( initializer, NodeVec{ opGen(L_BRACE), (yyvsp[-2].node), opGen(COMMA), opGen(R_BRACE) } ); }
#line 2550 "parser.tab.c"
    break;

  case 173:
#line 370 "src/parser.y"
    { (yyval.node) = new Node( initializer_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2556 "parser.tab.c"
    break;

  case 180:
#line 383 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ new Node(IDENTIFIER, (yyvsp[-2].string)), opGen(COLON), (yyvsp[0].node) } ); }
#line 2562 "parser.tab.c"
    break;

  case 181:
#line 384 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ opGen(CASE), (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } ); }
#line 2568 "parser.tab.c"
    break;

  case 182:
#line 385 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ opGen(DEFAULT), opGen(COLON), (yyvsp[0].node) } ); }
#line 2574 "parser.tab.c"
    break;

  case 183:
#line 389 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), opGen(R_BRACE) } ); }
#line 2580 "parser.tab.c"
    break;

  case 184:
#line 390 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2586 "parser.tab.c"
    break;

  case 185:
#line 391 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2592 "parser.tab.c"
    break;

  case 186:
#line 392 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-2].node), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2598 "parser.tab.c"
    break;

  case 188:
#line 397 "src/parser.y"
    { (yyval.node) = new Node( declaration_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2604 "parser.tab.c"
    break;

  case 190:
#line 402 "src/parser.y"
    { (yyval.node) = new Node( statement_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2610 "parser.tab.c"
    break;

  case 191:
#line 406 "src/parser.y"
    { (yyval.node) = opGen(SEMICOLON); }
#line 2616 "parser.tab.c"
    break;

  case 192:
#line 407 "src/parser.y"
    { (yyval.node) = new Node( expression_statement, NodeVec{ (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2622 "parser.tab.c"
    break;

  case 193:
#line 411 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2628 "parser.tab.c"
    break;

  case 194:
#line 412 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), (yyvsp[-4].node), opGen(R_PARENTHESES), (yyvsp[-2].node), opGen(ELSE), (yyvsp[0].node) } ); }
#line 2634 "parser.tab.c"
    break;

  case 195:
#line 413 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(SWITCH), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2640 "parser.tab.c"
    break;

  case 196:
#line 417 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(WHILE), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2646 "parser.tab.c"
    break;

  case 197:
#line 418 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(DO), (yyvsp[-5].node), opGen(WHILE), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), opGen(SEMICOLON) } ); }
#line 2652 "parser.tab.c"
    break;

  case 198:
#line 419 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), (yyvsp[-3].node), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2658 "parser.tab.c"
    break;

  case 199:
#line 420 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2664 "parser.tab.c"
    break;

  case 200:
#line 424 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(GOTO), new Node(IDENTIFIER, (yyvsp[-1].string)), opGen(SEMICOLON) } ); }
#line 2670 "parser.tab.c"
    break;

  case 201:
#line 425 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(CONTINUE), opGen(SEMICOLON) } ); }
#line 2676 "parser.tab.c"
    break;

  case 202:
#line 426 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(BREAK), opGen(SEMICOLON) } ); }
#line 2682 "parser.tab.c"
    break;

  case 203:
#line 427 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(RETURN), opGen(SEMICOLON) } ); }
#line 2688 "parser.tab.c"
    break;

  case 204:
#line 428 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(RETURN), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2694 "parser.tab.c"
    break;

  case 205:
#line 432 "src/parser.y"
    { std::cout << "found function" ;root = (yyvsp[0].node); }
#line 2700 "parser.tab.c"
    break;

  case 207:
#line 436 "src/parser.y"
    { (yyval.node) = new Node( translation_unit, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2706 "parser.tab.c"
    break;

  case 209:
#line 441 "src/parser.y"
    {std::cout << "found function" ; (yyval.node) = (yyvsp[0].node); }
#line 2712 "parser.tab.c"
    break;

  case 210:
#line 445 "src/parser.y"
    { std::cout << "found function" ; (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2718 "parser.tab.c"
    break;

  case 211:
#line 446 "src/parser.y"
    { std::cout << "found function" ; (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2724 "parser.tab.c"
    break;

  case 212:
#line 447 "src/parser.y"
    { std::cout << "found function" ; (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2730 "parser.tab.c"
    break;

  case 213:
#line 448 "src/parser.y"
    { std::cout << "found function" ; (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2736 "parser.tab.c"
    break;


#line 2740 "parser.tab.c"

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
