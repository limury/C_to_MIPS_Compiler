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


#line 120 "src/parser.tab.cpp"

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

#line 197 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



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
#define YYLAST   1268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
       2,     2,     2,    71,     2,     2,     2,    73,    66,     2,
      60,    61,    67,    68,    65,    69,    64,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    81,
      74,    80,    75,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    76,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    48,    49,    50,    54,    55,    56,    57,
      58,    59,    60,    61,    65,    66,    70,    71,    72,    73,
      74,    75,    79,    80,    81,    82,    83,    84,    88,    89,
      93,    94,    95,    96,   100,   101,   102,   106,   107,   108,
     112,   113,   114,   115,   116,   120,   121,   122,   126,   127,
     131,   132,   136,   137,   141,   142,   146,   147,   151,   152,
     156,   157,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   175,   176,   180,   184,   185,   189,   190,
     191,   192,   193,   194,   198,   199,   203,   204,   208,   209,
     210,   211,   212,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   231,   232,   233,   237,   238,
     242,   243,   247,   251,   252,   253,   254,   258,   259,   263,
     264,   265,   269,   270,   271,   275,   276,   280,   281,   285,
     286,   290,   291,   295,   296,   297,   298,   299,   300,   301,
     305,   306,   307,   308,   312,   313,   318,   319,   323,   324,
     328,   329,   330,   334,   335,   339,   340,   344,   345,   346,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   362,
     363,   364,   368,   369,   373,   374,   375,   376,   377,   378,
     382,   383,   384,   388,   389,   390,   391,   395,   396,   400,
     401,   405,   406,   410,   411,   412,   416,   417,   418,   419,
     423,   424,   425,   426,   427,   431,   434,   435,   439,   440,
     444,   445,   446,   447
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
  "T_AND_ASSIGN", "T_XOR_ASSIGN", "T_OR_ASSIGN", "T_TYPE_NAME",
  "T_TYPEDEF", "T_EXTERN", "T_STATIC", "T_AUTO", "T_REGISTER", "T_CHAR",
  "T_SHORT", "T_INT", "T_LONG", "T_SIGNED", "T_UNSIGNED", "T_FLOAT",
  "T_DOUBLE", "T_CONST", "T_VOLATILE", "T_VOID", "T_STRUCT", "T_ENUM",
  "T_ELLIPSIS", "T_CASE", "T_DEFAULT", "T_IF", "T_ELSE", "T_SWITCH",
  "T_WHILE", "T_DO", "T_FOR", "T_GOTO", "T_CONTINUE", "T_BREAK",
  "T_RETURN", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
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
      40,    41,    91,    93,    46,    44,    38,    42,    43,    45,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    58,
      61,    59,   123,   125
};
# endif

#define YYPACT_NINF -200

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-200)))

#define YYTABLE_NINF -110

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     963,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,     7,  -200,  -200,
      14,    76,    -2,  -200,    20,  1222,  1222,  -200,    16,  -200,
    1222,  1109,    46,    21,    53,   963,  -200,  -200,    -5,   100,
      49,  -200,  -200,  -200,    -2,  -200,   -37,  -200,  1054,  -200,
    -200,    36,  1085,  -200,   279,  -200,    20,  -200,  1109,  1007,
     630,    46,  -200,  -200,   100,    44,   -23,  -200,  -200,  -200,
    -200,    76,  -200,   561,  -200,  1109,  1085,  1085,   399,  -200,
      68,  1085,    58,  -200,  -200,   830,   830,   861,   874,    72,
     117,   148,   158,   525,   166,   220,   157,   171,   594,   679,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   213,
     165,   874,  -200,    60,   180,   245,    10,   248,   184,   181,
     182,   247,    -3,  -200,  -200,    -9,  -200,  -200,  -200,   348,
     417,  -200,  -200,  -200,  -200,   188,  -200,  -200,  -200,  -200,
      59,   215,   209,  -200,    80,  -200,  -200,  -200,  -200,   227,
     -16,   874,   100,  -200,  -200,   561,  -200,  -200,  -200,  1035,
    -200,  -200,  -200,   874,    -7,  -200,   212,  -200,   525,   874,
    -200,  -200,   679,  -200,   214,   525,   874,   874,   874,   239,
     610,   216,  -200,  -200,  -200,     1,    87,    82,   234,   293,
    -200,  -200,   723,   874,   296,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,   874,  -200,   874,   874,
     874,   874,   874,   874,   874,   874,   874,   874,   874,   874,
     874,   874,   874,   874,   874,   874,   874,   874,  -200,  -200,
     453,  -200,  -200,   919,   748,  -200,    45,  -200,   169,  -200,
    1202,  -200,   297,  -200,  -200,  -200,  -200,  -200,   -10,  -200,
    -200,    68,  -200,   874,  -200,   240,   525,  -200,   132,   135,
     144,   242,   610,  -200,  -200,  -200,  1128,   170,  -200,   874,
    -200,  -200,   149,  -200,   -20,  -200,  -200,  -200,  -200,  -200,
      60,    60,   180,   180,   245,   245,   245,   245,    10,    10,
     248,   184,   181,   182,   247,    -1,  -200,  -200,  -200,   244,
     265,  -200,   243,   169,  1168,   761,  -200,  -200,  -200,   489,
    -200,  -200,  -200,  -200,  -200,   525,   525,   525,   874,   792,
    -200,  -200,   874,  -200,   874,  -200,  -200,  -200,  -200,   269,
    -200,   277,  -200,  -200,   252,  -200,  -200,   152,   525,   163,
    -200,  -200,  -200,  -200,   525,   260,  -200,   525,  -200,  -200,
    -200
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
       0,   116,     2,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,   191,   183,     6,    16,
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
    -200,  -200,  -200,  -200,   -54,  -200,   -96,    67,    75,    26,
      61,   121,   122,   120,   130,   133,  -200,   -59,   -53,  -200,
     -47,   -52,    11,     0,  -200,   286,  -200,   126,  -200,  -200,
     283,   -66,   -72,  -200,   113,  -200,   301,   217,    39,   -17,
     -30,    -6,  -200,   -57,  -200,   127,  -200,   194,   -93,  -199,
    -137,  -200,   -80,  -200,   164,    22,   241,  -172,  -200,  -200,
    -200,  -200,  -200,   333,  -200
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
      24,   148,   141,    61,    40,   160,   147,    48,   262,   167,
    -109,    23,   162,   179,   225,   207,    43,    38,   247,    51,
     156,   215,   216,     1,     1,    49,    50,   187,    71,   148,
      53,   170,   171,   173,   147,    24,   174,   303,    70,   135,
      16,    41,   152,   323,    72,   227,    23,   237,     1,   152,
     232,   185,   186,    62,   135,   309,   227,   147,   251,   140,
     153,    42,     1,   166,   227,    22,   227,   244,   303,   136,
      75,     1,   228,   310,   252,   226,   129,    64,   324,     1,
      21,    21,   264,    69,   217,   218,   136,    22,   254,  -109,
     319,    81,   148,   162,   268,   257,    39,   147,    52,   245,
     187,    45,   156,    65,   148,   233,    59,   234,    60,   147,
      68,   250,   277,   278,   279,    81,    81,    81,    76,   233,
      81,   234,   186,   235,   151,   186,    22,   208,    21,   258,
     259,   260,   209,   210,   236,    22,    21,   168,    81,   273,
     136,   241,   266,    22,   234,   242,   274,   163,   265,    22,
     232,   175,   227,   276,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   333,   320,   296,   148,   314,   176,    77,   295,
     147,   267,   302,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   315,   148,    57,   316,   227,    81,   147,
     227,   312,    77,    77,    77,   317,    61,    77,   177,   227,
     321,    81,    74,   345,   322,   147,    40,   227,   178,   189,
     190,   191,   137,   181,   347,    77,   180,   236,   227,   304,
     266,   305,   234,   140,   166,   334,   335,   336,   182,   158,
     140,   284,   285,   286,   287,   205,   148,   329,   211,   212,
     221,   147,   183,   331,   213,   214,   156,   222,   346,   223,
     267,   219,   220,   224,   348,   341,   140,   350,    73,   340,
     147,   337,   339,   192,   240,   193,   239,   194,   280,   281,
     288,   289,    82,    83,    84,    77,    85,    86,   282,   283,
     243,   253,   261,   256,    87,   269,   270,   263,    77,   275,
     308,   313,   318,   344,   140,   325,   327,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   326,    88,    89,    90,
     342,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     343,   349,   290,   292,   291,   100,   101,   102,   103,   104,
     105,    82,    83,    84,   293,    85,    86,   154,   294,   159,
     106,    54,   107,    87,   311,   150,   255,   307,    63,   246,
     230,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    88,    89,    90,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
      82,    83,    84,     0,    85,    86,     0,     2,     0,   106,
      54,   229,    87,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
      85,    86,     0,     0,     0,    88,    89,    90,    87,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,     0,
       0,     0,   161,   100,   101,   102,   103,   104,   105,     0,
       0,     0,   145,    83,    84,     0,    85,    86,   106,    54,
     231,    88,    89,    90,    87,    91,    92,    93,    94,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,    82,    83,
      84,     0,    85,    86,   106,    54,   297,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   145,    83,    84,     0,    85,    86,
       0,   155,   332,    88,    89,    90,    87,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   145,    83,    84,
       0,    85,    86,     0,     0,     0,   106,    54,     0,    87,
       0,     0,     0,   145,    83,    84,     0,    85,    86,     0,
       0,    99,     0,     0,     0,    87,     0,   100,   101,   102,
     103,   104,   105,   145,    83,    84,     0,    85,    86,     0,
       0,     0,     0,   155,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   184,   100,   101,   102,   103,
     104,   105,   145,    83,    84,     0,    85,    86,     0,     0,
      99,   106,     0,   146,    87,     0,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   145,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,    87,    99,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   145,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,     0,    87,   145,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    99,   271,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   145,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,    87,    99,     0,
       0,   301,     0,     0,   100,   101,   102,   103,   104,   105,
       0,    99,     0,     0,   330,     0,     0,   100,   101,   102,
     103,   104,   105,   145,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,    99,   338,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   145,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    87,   145,    83,    84,
       0,    85,    86,     0,     0,     0,     0,     0,     0,    87,
     169,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,     1,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,     0,    99,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     298,   234,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,   139,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,   249,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,    73,     0,    54,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,   298,
     234,    54,     0,     0,     0,    22,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   306,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    60,    59,    33,    21,    77,    60,    24,   180,    81,
       3,     0,    78,    93,    17,   111,    22,     3,   155,     3,
      73,    11,    12,     3,     3,    25,    26,    99,    65,    88,
      30,    85,    86,    87,    88,    35,    88,   236,    44,    56,
      42,    43,    65,    63,    81,    65,    35,   140,     3,    65,
     130,    98,    99,     0,    71,    65,    65,   111,    65,    59,
      83,    22,     3,    80,    65,    67,    65,    83,   267,    58,
      48,     3,    81,    83,    81,    78,    54,    82,    79,     3,
      60,    60,    81,    44,    74,    75,    75,    67,   168,    82,
     262,    52,   151,   159,   187,   175,    82,   151,    82,   151,
     172,    81,   155,     3,   163,    60,    60,    62,    62,   163,
      61,   163,   208,   209,   210,    76,    77,    78,    82,    60,
      81,    62,   169,   140,    80,   172,    67,    67,    60,   176,
     177,   178,    72,    73,   140,    67,    60,    79,    99,   192,
     129,    61,    60,    67,    62,    65,   193,    79,    61,    67,
     230,    79,    65,   206,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   309,   269,   227,   234,   256,    60,    52,   226,
     234,   187,   234,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    61,   253,    31,    61,    65,   159,   253,
      65,   253,    76,    77,    78,    61,   236,    81,    60,    65,
      61,   172,    48,    61,    65,   269,   233,    65,    60,     6,
       7,     8,    58,     3,    61,    99,    60,   233,    65,    60,
      60,    62,    62,   233,   251,   315,   316,   317,    81,    75,
     240,   215,   216,   217,   218,    80,   305,   304,    68,    69,
      66,   305,    81,   305,     9,    10,   309,    76,   338,    77,
     266,    13,    14,    16,   344,   324,   266,   347,    80,   322,
     324,   318,   319,    60,    65,    62,    61,    64,   211,   212,
     219,   220,     3,     4,     5,   159,     7,     8,   213,   214,
      63,    79,    53,    79,    15,    61,     3,    81,   172,     3,
       3,    61,    60,    51,   304,    61,    63,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    61,    48,    49,    50,
      61,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      63,    81,   221,   223,   222,    66,    67,    68,    69,    70,
      71,     3,     4,     5,   224,     7,     8,    71,   225,    76,
      81,    82,    83,    15,   251,    64,   172,   240,    35,   152,
     129,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
       3,     4,     5,    -1,     7,     8,    -1,    28,    -1,    81,
      82,    83,    15,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    48,    49,    50,    15,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    83,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,    81,    82,
      83,    48,    49,    50,    15,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,    81,    82,    83,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    82,    83,    48,    49,    50,    15,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    81,    82,    -1,    15,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    60,    -1,    -1,    -1,    15,    -1,    66,    67,    68,
      69,    70,    71,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    82,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    81,    66,    67,    68,    69,
      70,    71,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      60,    81,    -1,    63,    15,    -1,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,     3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,     3,     4,     5,    -1,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      -1,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,     3,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    61,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    83,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    80,    -1,    82,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    82,    -1,    -1,    -1,    67,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    60,    67,   106,   107,   110,   111,   112,   113,   119,
     122,   123,   124,   125,   145,   146,   147,   148,     3,    82,
     123,    43,   122,   125,   126,    81,   108,   109,   123,   107,
     107,     3,    82,   107,    82,   106,   107,   138,   139,    60,
      62,   124,     0,   147,    82,     3,   120,   121,    61,   122,
     125,    65,    81,    80,   138,   139,    82,   111,   114,   115,
     116,   122,     3,     4,     5,     7,     8,    15,    48,    49,
      50,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      66,    67,    68,    69,    70,    71,    81,    83,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   104,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   123,   106,   138,     3,    61,
     107,   127,   128,   129,   130,     3,    63,    88,   101,   105,
     120,    80,    65,    83,   109,    82,   102,   134,   138,   114,
     116,    83,   115,    79,   117,   118,   123,   116,    79,    60,
      88,    88,    60,    88,   105,    79,    60,    60,    60,   136,
      60,     3,    81,    81,    81,   104,   104,   116,   131,     6,
       7,     8,    60,    62,    64,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    80,   103,    90,    67,    72,
      73,    68,    69,     9,    10,    11,    12,    74,    75,    13,
      14,    66,    76,    77,    16,    17,    78,    65,    81,    83,
     140,    83,   136,    60,    62,   123,   125,   132,   133,    61,
      65,    61,    65,    63,    83,   105,   121,   134,   135,    83,
     105,    65,    81,    79,   136,   131,    79,   136,   104,   104,
     104,    53,   141,    81,    81,    61,    60,   125,   132,    61,
       3,    61,    87,   102,   104,     3,   102,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    96,    97,    98,    99,   104,   102,    83,    61,   127,
     132,    63,   105,   133,    60,    62,    47,   129,     3,    65,
      83,   118,   105,    61,   136,    61,    61,    61,    60,   141,
      90,    61,    65,    63,    79,    61,    61,    63,    61,   127,
      63,   105,    83,   134,   136,   136,   136,   104,    61,   104,
     102,   101,    61,    63,    51,    61,   136,    61,   136,    81,
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
#line 47 "src/parser.y"
    { (yyval.node) = new Node(IDENTIFIER, (yyvsp[0].string)); }
#line 1758 "src/parser.tab.cpp"
    break;

  case 3:
#line 48 "src/parser.y"
    { (yyval.node) = new Node(CONSTANT, (yyvsp[0].string)); }
#line 1764 "src/parser.tab.cpp"
    break;

  case 4:
#line 49 "src/parser.y"
    { (yyval.node) = new Node(STRING_LIT, (yyvsp[0].string)); }
#line 1770 "src/parser.tab.cpp"
    break;

  case 5:
#line 50 "src/parser.y"
    { (yyval.node) = new Node(expression, NodeVec{(yyvsp[-1].node)}); }
#line 1776 "src/parser.tab.cpp"
    break;

  case 7:
#line 55 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-3].node), new Operator(L_BRACKET), (yyvsp[-1].node), new Operator(R_BRACKET) }); }
#line 1782 "src/parser.tab.cpp"
    break;

  case 8:
#line 56 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-2].node), new Operator(L_PARENTHESES), new Operator(R_PARENTHESES)}); }
#line 1788 "src/parser.tab.cpp"
    break;

  case 9:
#line 57 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{ (yyvsp[-3].node), new Operator(L_PARENTHESES), (yyvsp[-1].node), new Operator(R_PARENTHESES) }) ; }
#line 1794 "src/parser.tab.cpp"
    break;

  case 10:
#line 58 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-2].node), new Operator(DOT), new Node(IDENTIFIER, (yyvsp[0].string))} ); }
#line 1800 "src/parser.tab.cpp"
    break;

  case 11:
#line 59 "src/parser.y"
    { (yyval.node) = new Node(   postfix_expression, NodeVec{  (yyvsp[-2].node), new Operator(PTR_OP), new Node(IDENTIFIER, (yyvsp[0].string))  }   ); }
#line 1806 "src/parser.tab.cpp"
    break;

  case 12:
#line 60 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-1].node), new Operator(INC_OP)}); }
#line 1812 "src/parser.tab.cpp"
    break;

  case 13:
#line 61 "src/parser.y"
    { (yyval.node) = new Node(postfix_expression, NodeVec{(yyvsp[-1].node), new Operator(DEC_OP)}); }
#line 1818 "src/parser.tab.cpp"
    break;

  case 15:
#line 66 "src/parser.y"
    { (yyval.node) = new Node(argument_expression_list, NodeVec{(yyvsp[-2].node), new Operator(COMMA), (yyvsp[0].node)}); }
#line 1824 "src/parser.tab.cpp"
    break;

  case 17:
#line 71 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(INC_OP), (yyvsp[0].node)} );}
#line 1830 "src/parser.tab.cpp"
    break;

  case 18:
#line 72 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(DEC_OP), (yyvsp[0].node)} );}
#line 1836 "src/parser.tab.cpp"
    break;

  case 19:
#line 73 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{(yyvsp[-1].node), (yyvsp[0].node)} ); }
#line 1842 "src/parser.tab.cpp"
    break;

  case 20:
#line 74 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(SIZEOF), (yyvsp[0].node)} ); }
#line 1848 "src/parser.tab.cpp"
    break;

  case 21:
#line 75 "src/parser.y"
    { (yyval.node) = new Node( unary_expression, NodeVec{new Operator(SIZEOF),new Operator(L_PARENTHESES), (yyvsp[-1].node), new Operator(R_PARENTHESES),} ); }
#line 1854 "src/parser.tab.cpp"
    break;

  case 22:
#line 79 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(BIN_AND)} ); }
#line 1860 "src/parser.tab.cpp"
    break;

  case 23:
#line 80 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(MULT)} ); }
#line 1866 "src/parser.tab.cpp"
    break;

  case 24:
#line 81 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(PLUS)} ); }
#line 1872 "src/parser.tab.cpp"
    break;

  case 25:
#line 82 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(MINUS)} ); }
#line 1878 "src/parser.tab.cpp"
    break;

  case 26:
#line 83 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(BIN_NOT)} ); }
#line 1884 "src/parser.tab.cpp"
    break;

  case 27:
#line 84 "src/parser.y"
    { (yyval.node) = new Node( unary_operator, NodeVec{new Operator(LOGICAL_NOT)} ); }
#line 1890 "src/parser.tab.cpp"
    break;

  case 29:
#line 89 "src/parser.y"
    { (yyval.node) = new Node( cast_expression, NodeVec{  new Operator(L_PARENTHESES), (yyvsp[-2].node), new Operator(R_PARENTHESES), (yyvsp[0].node)  } ); }
#line 1896 "src/parser.tab.cpp"
    break;

  case 31:
#line 94 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(MULT), (yyvsp[0].node) } ); }
#line 1902 "src/parser.tab.cpp"
    break;

  case 32:
#line 95 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(DIVIDE), (yyvsp[0].node) } ); }
#line 1908 "src/parser.tab.cpp"
    break;

  case 33:
#line 96 "src/parser.y"
    { (yyval.node) = new Node( multiplicative_expression, NodeVec{ (yyvsp[-2].node), opGen(MODULO), (yyvsp[0].node) } ); }
#line 1914 "src/parser.tab.cpp"
    break;

  case 35:
#line 101 "src/parser.y"
    { (yyval.node) = new Node( additive_expression, NodeVec{ (yyvsp[-2].node), opGen(PLUS), (yyvsp[0].node) } ); }
#line 1920 "src/parser.tab.cpp"
    break;

  case 36:
#line 102 "src/parser.y"
    { (yyval.node) = new Node( additive_expression, NodeVec{ (yyvsp[-2].node), opGen(MINUS), (yyvsp[0].node) } ); }
#line 1926 "src/parser.tab.cpp"
    break;

  case 38:
#line 107 "src/parser.y"
    { (yyval.node) = new Node( shift_expression, NodeVec{ (yyvsp[-2].node), opGen(LEFT_OP), (yyvsp[0].node)} ); }
#line 1932 "src/parser.tab.cpp"
    break;

  case 39:
#line 108 "src/parser.y"
    { (yyval.node) = new Node( shift_expression, NodeVec{ (yyvsp[-2].node), opGen(RIGHT_OP), (yyvsp[0].node)} ); }
#line 1938 "src/parser.tab.cpp"
    break;

  case 41:
#line 113 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(LT), (yyvsp[0].node) } );}
#line 1944 "src/parser.tab.cpp"
    break;

  case 42:
#line 114 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(GT), (yyvsp[0].node) } );}
#line 1950 "src/parser.tab.cpp"
    break;

  case 43:
#line 115 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(LE_OP), (yyvsp[0].node) } );}
#line 1956 "src/parser.tab.cpp"
    break;

  case 44:
#line 116 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), opGen(GE_OP), (yyvsp[0].node) } );}
#line 1962 "src/parser.tab.cpp"
    break;

  case 46:
#line 121 "src/parser.y"
    { (yyval.node) = new Node( equality_expression, NodeVec{ (yyvsp[-2].node), opGen(EQ_OP), (yyvsp[0].node) } );}
#line 1968 "src/parser.tab.cpp"
    break;

  case 47:
#line 122 "src/parser.y"
    { (yyval.node) = new Node( equality_expression, NodeVec{ (yyvsp[-2].node), opGen(NE_OP), (yyvsp[0].node) } );}
#line 1974 "src/parser.tab.cpp"
    break;

  case 49:
#line 127 "src/parser.y"
    { (yyval.node) = new Node( and_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_AND), (yyvsp[0].node) } );}
#line 1980 "src/parser.tab.cpp"
    break;

  case 51:
#line 132 "src/parser.y"
    { (yyval.node) = new Node( exclusive_or_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_XOR), (yyvsp[0].node) } );}
#line 1986 "src/parser.tab.cpp"
    break;

  case 53:
#line 137 "src/parser.y"
    { (yyval.node) = new Node( inclusive_or_expression, NodeVec{ (yyvsp[-2].node), opGen(BIN_OR), (yyvsp[0].node) } );}
#line 1992 "src/parser.tab.cpp"
    break;

  case 55:
#line 142 "src/parser.y"
    { (yyval.node) = new Node( logical_and_expression, NodeVec{ (yyvsp[-2].node), opGen(AND_OP), (yyvsp[0].node) } );}
#line 1998 "src/parser.tab.cpp"
    break;

  case 57:
#line 147 "src/parser.y"
    { (yyval.node) = new Node( logical_or_expression, NodeVec{ (yyvsp[-2].node), opGen(OR_OP), (yyvsp[0].node) } ); }
#line 2004 "src/parser.tab.cpp"
    break;

  case 59:
#line 152 "src/parser.y"
    { (yyval.node) = new Node( conditional_expression, NodeVec{ (yyvsp[-4].node), opGen(QUESTION_MARK), (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } );}
#line 2010 "src/parser.tab.cpp"
    break;

  case 61:
#line 157 "src/parser.y"
    { (yyval.node) = new Node( relational_expression, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } );}
#line 2016 "src/parser.tab.cpp"
    break;

  case 62:
#line 161 "src/parser.y"
    { (yyval.node) = opGen(EQUALS); }
#line 2022 "src/parser.tab.cpp"
    break;

  case 63:
#line 162 "src/parser.y"
    { (yyval.node) = opGen(MUL_ASSIGN); }
#line 2028 "src/parser.tab.cpp"
    break;

  case 64:
#line 163 "src/parser.y"
    { (yyval.node) = opGen(DIV_ASSIGN); }
#line 2034 "src/parser.tab.cpp"
    break;

  case 65:
#line 164 "src/parser.y"
    { (yyval.node) = opGen(MOD_ASSIGN); }
#line 2040 "src/parser.tab.cpp"
    break;

  case 66:
#line 165 "src/parser.y"
    { (yyval.node) = opGen(ADD_ASSIGN); }
#line 2046 "src/parser.tab.cpp"
    break;

  case 67:
#line 166 "src/parser.y"
    { (yyval.node) = opGen(SUB_ASSIGN); }
#line 2052 "src/parser.tab.cpp"
    break;

  case 68:
#line 167 "src/parser.y"
    { (yyval.node) = opGen(LEFT_ASSIGN); }
#line 2058 "src/parser.tab.cpp"
    break;

  case 69:
#line 168 "src/parser.y"
    { (yyval.node) = opGen(RIGHT_ASSIGN); }
#line 2064 "src/parser.tab.cpp"
    break;

  case 70:
#line 169 "src/parser.y"
    { (yyval.node) = opGen(AND_ASSIGN); }
#line 2070 "src/parser.tab.cpp"
    break;

  case 71:
#line 170 "src/parser.y"
    { (yyval.node) = opGen(XOR_ASSIGN); }
#line 2076 "src/parser.tab.cpp"
    break;

  case 72:
#line 171 "src/parser.y"
    { (yyval.node) = opGen(OR_ASSIGN); }
#line 2082 "src/parser.tab.cpp"
    break;

  case 74:
#line 176 "src/parser.y"
    { (yyval.node) = new Node( expression, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2088 "src/parser.tab.cpp"
    break;

  case 76:
#line 184 "src/parser.y"
    { std::cout << "found declaration\n"; (yyval.node) = new Node( declaration, NodeVec{ (yyvsp[-1].node), opGen(SEMICOLON) } ); std::cout << "declaration ptr: " << (yyval.node) << std::endl; }
#line 2094 "src/parser.tab.cpp"
    break;

  case 77:
#line 185 "src/parser.y"
    { (yyval.node) = new Node( declaration, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2100 "src/parser.tab.cpp"
    break;

  case 79:
#line 190 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2106 "src/parser.tab.cpp"
    break;

  case 81:
#line 192 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2112 "src/parser.tab.cpp"
    break;

  case 83:
#line 194 "src/parser.y"
    { (yyval.node) = new Node( declaration_specifiers, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2118 "src/parser.tab.cpp"
    break;

  case 85:
#line 199 "src/parser.y"
    { (yyval.node) = new Node( init_declarator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2124 "src/parser.tab.cpp"
    break;

  case 87:
#line 204 "src/parser.y"
    { (yyval.node) = new Node( init_declarator, NodeVec{ (yyvsp[-2].node), opGen(EQUALS), (yyvsp[0].node) } ); }
#line 2130 "src/parser.tab.cpp"
    break;

  case 88:
#line 208 "src/parser.y"
    { (yyval.node) = opGen(TYPEDEF); }
#line 2136 "src/parser.tab.cpp"
    break;

  case 89:
#line 209 "src/parser.y"
    { (yyval.node) = opGen(EXTERN); }
#line 2142 "src/parser.tab.cpp"
    break;

  case 90:
#line 210 "src/parser.y"
    { (yyval.node) = opGen(STATIC); }
#line 2148 "src/parser.tab.cpp"
    break;

  case 91:
#line 211 "src/parser.y"
    { (yyval.node) = opGen(AUTO); }
#line 2154 "src/parser.tab.cpp"
    break;

  case 92:
#line 212 "src/parser.y"
    { (yyval.node) = opGen(REGISTER); }
#line 2160 "src/parser.tab.cpp"
    break;

  case 93:
#line 216 "src/parser.y"
    { std::cout << "Found void\n"; (yyval.node) = opGen(VOID); std::cout << "Void ptr: " << (yyval.node) << "\n"; }
#line 2166 "src/parser.tab.cpp"
    break;

  case 94:
#line 217 "src/parser.y"
    { (yyval.node) = opGen(CHAR); }
#line 2172 "src/parser.tab.cpp"
    break;

  case 95:
#line 218 "src/parser.y"
    { (yyval.node) = opGen(SHORT); }
#line 2178 "src/parser.tab.cpp"
    break;

  case 96:
#line 219 "src/parser.y"
    { (yyval.node) = opGen(INT); }
#line 2184 "src/parser.tab.cpp"
    break;

  case 97:
#line 220 "src/parser.y"
    { (yyval.node) = opGen(LONG); }
#line 2190 "src/parser.tab.cpp"
    break;

  case 98:
#line 221 "src/parser.y"
    { (yyval.node) = opGen(FLOAT); }
#line 2196 "src/parser.tab.cpp"
    break;

  case 99:
#line 222 "src/parser.y"
    { (yyval.node) = opGen(DOUBLE); }
#line 2202 "src/parser.tab.cpp"
    break;

  case 100:
#line 223 "src/parser.y"
    { (yyval.node) = opGen(SIGNED); }
#line 2208 "src/parser.tab.cpp"
    break;

  case 101:
#line 224 "src/parser.y"
    { (yyval.node) = opGen(UNSIGNED); }
#line 2214 "src/parser.tab.cpp"
    break;

  case 104:
#line 227 "src/parser.y"
    { (yyval.node) = opGen(TYPE_NAME); }
#line 2220 "src/parser.tab.cpp"
    break;

  case 105:
#line 231 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-4].node), new Node(IDENTIFIER, (yyvsp[-3].string)), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE)  } ); }
#line 2226 "src/parser.tab.cpp"
    break;

  case 106:
#line 232 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-3].node), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2232 "src/parser.tab.cpp"
    break;

  case 107:
#line 233 "src/parser.y"
    { (yyval.node) = new Node( struct_or_union_specifier, NodeVec{ (yyvsp[-1].node), new Node(IDENTIFIER, (yyvsp[0].string)) } ); }
#line 2238 "src/parser.tab.cpp"
    break;

  case 108:
#line 237 "src/parser.y"
    { (yyval.node) = opGen(STRUCT); }
#line 2244 "src/parser.tab.cpp"
    break;

  case 109:
#line 238 "src/parser.y"
    { (yyval.node) = opGen(UNION); }
#line 2250 "src/parser.tab.cpp"
    break;

  case 111:
#line 243 "src/parser.y"
    { (yyval.node) = new Node( struct_declaration_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2256 "src/parser.tab.cpp"
    break;

  case 112:
#line 247 "src/parser.y"
    { (yyval.node) = new Node( struct_declaration, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2262 "src/parser.tab.cpp"
    break;

  case 113:
#line 251 "src/parser.y"
    { (yyval.node) = new Node( specifier_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2268 "src/parser.tab.cpp"
    break;

  case 115:
#line 253 "src/parser.y"
    { (yyval.node) = new Node( specifier_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2274 "src/parser.tab.cpp"
    break;

  case 118:
#line 259 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2280 "src/parser.tab.cpp"
    break;

  case 120:
#line 264 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator, NodeVec{ opGen(COLON), (yyvsp[0].node) } ); }
#line 2286 "src/parser.tab.cpp"
    break;

  case 121:
#line 265 "src/parser.y"
    { (yyval.node) = new Node( struct_declarator, NodeVec{ (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } ); }
#line 2292 "src/parser.tab.cpp"
    break;

  case 122:
#line 269 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2298 "src/parser.tab.cpp"
    break;

  case 123:
#line 270 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, (yyvsp[-3].string) ), opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2304 "src/parser.tab.cpp"
    break;

  case 124:
#line 271 "src/parser.y"
    { (yyval.node) = new Node( enum_specifier, NodeVec{ opGen(ENUM), new Node( IDENTIFIER, (yyvsp[0].string) ) } ); }
#line 2310 "src/parser.tab.cpp"
    break;

  case 126:
#line 276 "src/parser.y"
    { (yyval.node) = new Node( enumerator_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ) ; }
#line 2316 "src/parser.tab.cpp"
    break;

  case 127:
#line 280 "src/parser.y"
    { (yyval.node) = new Node( IDENTIFIER, (yyvsp[0].string) ); }
#line 2322 "src/parser.tab.cpp"
    break;

  case 128:
#line 281 "src/parser.y"
    { (yyval.node) = new Node( enumerator, NodeVec{ new Node(IDENTIFIER, (yyvsp[-2].string)), opGen(EQUALS), (yyvsp[0].node) } ); }
#line 2328 "src/parser.tab.cpp"
    break;

  case 129:
#line 285 "src/parser.y"
    { (yyval.node) = opGen(CONST); }
#line 2334 "src/parser.tab.cpp"
    break;

  case 130:
#line 286 "src/parser.y"
    { (yyval.node) = opGen(VOLATILE); }
#line 2340 "src/parser.tab.cpp"
    break;

  case 131:
#line 290 "src/parser.y"
    { (yyval.node) = new Node( declarator, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2346 "src/parser.tab.cpp"
    break;

  case 133:
#line 295 "src/parser.y"
    { (yyval.node) = new Node(IDENTIFIER, (yyvsp[0].string)); }
#line 2352 "src/parser.tab.cpp"
    break;

  case 134:
#line 296 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2358 "src/parser.tab.cpp"
    break;

  case 135:
#line 297 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2364 "src/parser.tab.cpp"
    break;

  case 136:
#line 298 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2370 "src/parser.tab.cpp"
    break;

  case 137:
#line 299 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2376 "src/parser.tab.cpp"
    break;

  case 138:
#line 300 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2382 "src/parser.tab.cpp"
    break;

  case 139:
#line 301 "src/parser.y"
    { (yyval.node) = new Node( direct_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2388 "src/parser.tab.cpp"
    break;

  case 140:
#line 305 "src/parser.y"
    { (yyval.node) = opGen(MULT); }
#line 2394 "src/parser.tab.cpp"
    break;

  case 141:
#line 306 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[0].node) } ); }
#line 2400 "src/parser.tab.cpp"
    break;

  case 142:
#line 307 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[0].node) } ); }
#line 2406 "src/parser.tab.cpp"
    break;

  case 143:
#line 308 "src/parser.y"
    { (yyval.node) = new Node( pointer, NodeVec{ opGen(MULT), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2412 "src/parser.tab.cpp"
    break;

  case 145:
#line 313 "src/parser.y"
    { (yyval.node) = new Node( type_qualifier_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2418 "src/parser.tab.cpp"
    break;

  case 147:
#line 319 "src/parser.y"
    { (yyval.node) = new Node( parameter_type_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), opGen(ELLIPSIS) } ); }
#line 2424 "src/parser.tab.cpp"
    break;

  case 149:
#line 324 "src/parser.y"
    { (yyval.node) = new Node( parameter_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2430 "src/parser.tab.cpp"
    break;

  case 150:
#line 328 "src/parser.y"
    { (yyval.node) = new Node( parameter_declaration, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2436 "src/parser.tab.cpp"
    break;

  case 151:
#line 329 "src/parser.y"
    { (yyval.node) = new Node( parameter_declaration, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2442 "src/parser.tab.cpp"
    break;

  case 153:
#line 334 "src/parser.y"
    { (yyval.node) = new Node( IDENTIFIER, (yyvsp[0].string) ); }
#line 2448 "src/parser.tab.cpp"
    break;

  case 154:
#line 335 "src/parser.y"
    { (yyval.node) = new Node( identifier_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), new Node(IDENTIFIER, (yyvsp[0].string)) } ); }
#line 2454 "src/parser.tab.cpp"
    break;

  case 156:
#line 340 "src/parser.y"
    { (yyval.node) = new Node( type_name, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2460 "src/parser.tab.cpp"
    break;

  case 159:
#line 346 "src/parser.y"
    { (yyval.node) = new Node( abstract_declarator, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2466 "src/parser.tab.cpp"
    break;

  case 160:
#line 350 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2472 "src/parser.tab.cpp"
    break;

  case 161:
#line 351 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2478 "src/parser.tab.cpp"
    break;

  case 162:
#line 352 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2484 "src/parser.tab.cpp"
    break;

  case 163:
#line 353 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_BRACKET), opGen(R_BRACKET) } ); }
#line 2490 "src/parser.tab.cpp"
    break;

  case 164:
#line 354 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_BRACKET), (yyvsp[-1].node), opGen(R_BRACKET) } ); }
#line 2496 "src/parser.tab.cpp"
    break;

  case 165:
#line 355 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2502 "src/parser.tab.cpp"
    break;

  case 166:
#line 356 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2508 "src/parser.tab.cpp"
    break;

  case 167:
#line 357 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-2].node), opGen(L_PARENTHESES), opGen(R_PARENTHESES) } ); }
#line 2514 "src/parser.tab.cpp"
    break;

  case 168:
#line 358 "src/parser.y"
    { (yyval.node) = new Node( direct_abstract_declarator, NodeVec{ (yyvsp[-3].node), opGen(L_PARENTHESES), (yyvsp[-1].node), opGen(R_PARENTHESES) } ); }
#line 2520 "src/parser.tab.cpp"
    break;

  case 170:
#line 363 "src/parser.y"
    { (yyval.node) = new Node( initializer, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2526 "src/parser.tab.cpp"
    break;

  case 171:
#line 364 "src/parser.y"
    { (yyval.node) = new Node( initializer, NodeVec{ opGen(L_BRACE), (yyvsp[-2].node), opGen(COMMA), opGen(R_BRACE) } ); }
#line 2532 "src/parser.tab.cpp"
    break;

  case 173:
#line 369 "src/parser.y"
    { (yyval.node) = new Node( initializer_list, NodeVec{ (yyvsp[-2].node), opGen(COMMA), (yyvsp[0].node) } ); }
#line 2538 "src/parser.tab.cpp"
    break;

  case 180:
#line 382 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ new Node(IDENTIFIER, (yyvsp[-2].string)), opGen(COLON), (yyvsp[0].node) } ); }
#line 2544 "src/parser.tab.cpp"
    break;

  case 181:
#line 383 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ opGen(CASE), (yyvsp[-2].node), opGen(COLON), (yyvsp[0].node) } ); }
#line 2550 "src/parser.tab.cpp"
    break;

  case 182:
#line 384 "src/parser.y"
    { (yyval.node) = new Node( labeled_statement, NodeVec{ opGen(DEFAULT), opGen(COLON), (yyvsp[0].node) } ); }
#line 2556 "src/parser.tab.cpp"
    break;

  case 183:
#line 388 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), opGen(R_BRACE) } ); }
#line 2562 "src/parser.tab.cpp"
    break;

  case 184:
#line 389 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2568 "src/parser.tab.cpp"
    break;

  case 185:
#line 390 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2574 "src/parser.tab.cpp"
    break;

  case 186:
#line 391 "src/parser.y"
    { (yyval.node) = new Node( compound_statement, NodeVec{ opGen(L_BRACE), (yyvsp[-2].node), (yyvsp[-1].node), opGen(R_BRACE) } ); }
#line 2580 "src/parser.tab.cpp"
    break;

  case 188:
#line 396 "src/parser.y"
    { (yyval.node) = new Node( declaration_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2586 "src/parser.tab.cpp"
    break;

  case 190:
#line 401 "src/parser.y"
    { (yyval.node) = new Node( statement_list, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2592 "src/parser.tab.cpp"
    break;

  case 191:
#line 405 "src/parser.y"
    { (yyval.node) = opGen(SEMICOLON); }
#line 2598 "src/parser.tab.cpp"
    break;

  case 192:
#line 406 "src/parser.y"
    { (yyval.node) = new Node( expression_statement, NodeVec{ (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2604 "src/parser.tab.cpp"
    break;

  case 193:
#line 410 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2610 "src/parser.tab.cpp"
    break;

  case 194:
#line 411 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(IF), opGen(L_PARENTHESES), (yyvsp[-4].node), opGen(R_PARENTHESES), (yyvsp[-2].node), opGen(ELSE), (yyvsp[0].node) } ); }
#line 2616 "src/parser.tab.cpp"
    break;

  case 195:
#line 412 "src/parser.y"
    { (yyval.node) = new Node( selection_statement, NodeVec{ opGen(SWITCH), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2622 "src/parser.tab.cpp"
    break;

  case 196:
#line 416 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(WHILE), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2628 "src/parser.tab.cpp"
    break;

  case 197:
#line 417 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(DO), (yyvsp[-5].node), opGen(WHILE), opGen(L_PARENTHESES), (yyvsp[-2].node), opGen(R_PARENTHESES), opGen(SEMICOLON) } ); }
#line 2634 "src/parser.tab.cpp"
    break;

  case 198:
#line 418 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), (yyvsp[-3].node), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2640 "src/parser.tab.cpp"
    break;

  case 199:
#line 419 "src/parser.y"
    { (yyval.node) = new Node( iteration_statement, NodeVec{ opGen(FOR), opGen(L_PARENTHESES), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), opGen(R_PARENTHESES), (yyvsp[0].node) } ); }
#line 2646 "src/parser.tab.cpp"
    break;

  case 200:
#line 423 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(GOTO), new Node(IDENTIFIER, (yyvsp[-1].string)), opGen(SEMICOLON) } ); }
#line 2652 "src/parser.tab.cpp"
    break;

  case 201:
#line 424 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(CONTINUE), opGen(SEMICOLON) } ); }
#line 2658 "src/parser.tab.cpp"
    break;

  case 202:
#line 425 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(BREAK), opGen(SEMICOLON) } ); }
#line 2664 "src/parser.tab.cpp"
    break;

  case 203:
#line 426 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(RETURN), opGen(SEMICOLON) } ); }
#line 2670 "src/parser.tab.cpp"
    break;

  case 204:
#line 427 "src/parser.y"
    { (yyval.node) = new Node( jump_statement, NodeVec{ opGen(RETURN), (yyvsp[-1].node), opGen(SEMICOLON) } ); }
#line 2676 "src/parser.tab.cpp"
    break;

  case 205:
#line 431 "src/parser.y"
    { root = (yyvsp[0].node); }
#line 2682 "src/parser.tab.cpp"
    break;

  case 206:
#line 434 "src/parser.y"
    { (yyval.node) = (yyvsp[0].node); std::cout << "translation ptr: " << (yyval.node) << std::endl;}
#line 2688 "src/parser.tab.cpp"
    break;

  case 207:
#line 435 "src/parser.y"
    { (yyval.node) = new Node( translation_unit, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2694 "src/parser.tab.cpp"
    break;

  case 209:
#line 440 "src/parser.y"
    { (yyval.node) = (yyvsp[0].node); std::cout << "declaration ptr: " << (yyval.node) << std::endl; }
#line 2700 "src/parser.tab.cpp"
    break;

  case 210:
#line 444 "src/parser.y"
    { (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2706 "src/parser.tab.cpp"
    break;

  case 211:
#line 445 "src/parser.y"
    { (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2712 "src/parser.tab.cpp"
    break;

  case 212:
#line 446 "src/parser.y"
    { (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2718 "src/parser.tab.cpp"
    break;

  case 213:
#line 447 "src/parser.y"
    { (yyval.node) = new Node( function_definition, NodeVec{ (yyvsp[-1].node), (yyvsp[0].node) } ); }
#line 2724 "src/parser.tab.cpp"
    break;


#line 2728 "src/parser.tab.cpp"

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
#line 450 "src/parser.y"

#include <stdio.h>

extern char yytext[];
extern int column;

NodePtr root;

NodePtr parseAST(){
    root == nullptr;
    std::cout << "Parsing beginning" << std::endl;
    yyparse();
    std::cout << "Parsing done" << std::endl;
    std::cout << "Tree ptr: " << root << std::endl; 
    return root;
}
