/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "bison.y"

#include"globals.h"
#include<stack>
//extern int yylex();
//void yyerror(const char* s);
int yyerror(const char* s);
#define YYSTYPE TreeNode*
extern char id[10];
struct TreeNode* root;
void type_check(char* val, ValType type, ValType correct_type);
char savedname[10];
static int yylex();

/* Line 371 of yacc.c  */
#line 81 "bison.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     RETURN = 263,
     ASSIGN = 264,
     SEMI = 265,
     COMMA = 266,
     LBRACE = 267,
     RBRACE = 268,
     LBRACKET = 269,
     RBRACKET = 270,
     LCOMM = 271,
     RCOMM = 272,
     ID = 273,
     NUM = 274,
     LESS = 275,
     LESSEQUAL = 276,
     MORE = 277,
     MOREEQUAL = 278,
     EQUAL = 279,
     NOTEQUAL = 280,
     MINUS = 281,
     PLUS = 282,
     DIVIDE = 283,
     MULTI = 284,
     RPAREN = 285,
     LPAREN = 286,
     LOWER_THEN_ELSE = 287
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 176 "bison.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  104

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    25,
      27,    29,    30,    38,    40,    42,    46,    48,    51,    56,
      61,    64,    65,    68,    69,    72,    74,    76,    78,    80,
      82,    88,    96,   102,   105,   109,   113,   115,   117,   118,
     124,   128,   130,   132,   134,   136,   138,   140,   142,   146,
     148,   150,   152,   156,   158,   160,   162,   166,   168,   170,
     172,   173,   179,   181,   182,   186
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    35,    36,    -1,    36,    -1,
      37,    -1,    39,    -1,    38,    18,    10,    -1,    38,    18,
      14,    19,    15,    10,    -1,     4,    -1,     3,    -1,    -1,
      38,    18,    31,    40,    41,    30,    44,    -1,    42,    -1,
       3,    -1,    42,    11,    43,    -1,    43,    -1,    38,    18,
      -1,    38,    18,    14,    15,    -1,    12,    45,    46,    13,
      -1,    45,    37,    -1,    -1,    46,    48,    -1,    -1,    52,
      10,    -1,    47,    -1,    44,    -1,    49,    -1,    50,    -1,
      51,    -1,     5,    31,    52,    30,    48,    -1,     5,    31,
      52,    30,    48,     6,    48,    -1,     7,    31,    52,    30,
      48,    -1,     8,    10,    -1,     8,    52,    10,    -1,    53,
       9,    52,    -1,    55,    -1,    18,    -1,    -1,    18,    14,
      54,    52,    15,    -1,    57,    56,    57,    -1,    57,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    57,    58,    59,    -1,    59,    -1,    27,    -1,
      26,    -1,    59,    60,    61,    -1,    61,    -1,    29,    -1,
      28,    -1,    31,    52,    30,    -1,    53,    -1,    62,    -1,
      19,    -1,    -1,    18,    31,    63,    64,    30,    -1,    65,
      -1,    -1,    65,    11,    52,    -1,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    50,    56,    58,    59,    61,    68,    78,
      79,    81,    81,    94,    95,   100,   106,   108,   114,   123,
     133,   144,   146,   157,   160,   163,   164,   165,   166,   167,
     169,   174,   182,   188,   189,   191,   196,   198,   200,   200,
     211,   216,   218,   219,   220,   221,   222,   223,   225,   230,
     232,   233,   235,   240,   242,   243,   245,   246,   247,   248,
     250,   250,   260,   261,   263,   269
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "IF", "ELSE", "WHILE",
  "RETURN", "ASSIGN", "SEMI", "COMMA", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "LCOMM", "RCOMM", "ID", "NUM", "LESS", "LESSEQUAL", "MORE",
  "MOREEQUAL", "EQUAL", "NOTEQUAL", "MINUS", "PLUS", "DIVIDE", "MULTI",
  "RPAREN", "LPAREN", "LOWER_THEN_ELSE", "$accept", "program",
  "declaration_list", "declaration", "var_declaration", "type_specifier",
  "fun_declaration", "@1", "params", "param_list", "param",
  "compound_stmt", "local_declarations", "statement_list",
  "expression_stmt", "statement", "selection_stmt", "iteration_stmt",
  "return_stmt", "expression", "var", "@2", "simple_expression", "relop",
  "additive_expression", "addop", "term", "mulop", "factor", "call", "@3",
  "args", "arg_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    40,    39,    41,    41,    42,    42,    43,    43,    44,
      45,    45,    46,    46,    47,    48,    48,    48,    48,    48,
      49,    49,    50,    51,    51,    52,    52,    53,    54,    53,
      55,    55,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      63,    62,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     0,     7,     1,     1,     3,     1,     2,     4,     4,
       2,     0,     2,     0,     2,     1,     1,     1,     1,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       0,     5,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     9,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,     0,    11,     0,     0,     0,    10,     0,
       0,    13,    16,     8,    17,     0,     0,     0,    21,    12,
      15,    18,    23,    20,     0,     0,     0,     0,     0,     0,
      19,    37,    59,     0,    26,    25,    22,    27,    28,    29,
       0,    57,    36,    41,    49,    53,    58,     0,     0,    33,
       0,    38,    60,     0,    24,     0,    42,    43,    44,    45,
      46,    47,    51,    50,     0,     0,    55,    54,     0,     0,
       0,    34,     0,    63,    56,    35,    57,    40,    48,    52,
       0,     0,     0,    65,     0,    62,    30,    32,    39,    61,
       0,     0,    64,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    16,    20,    21,
      22,    44,    32,    35,    45,    46,    47,    48,    49,    50,
      51,    82,    52,    74,    53,    75,    54,    78,    55,    56,
      83,    94,    95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int8 yypact[] =
{
      35,   -60,   -60,     8,    35,   -60,   -60,    -6,   -60,   -60,
     -60,    -1,   -60,    -4,   -60,     6,    44,    53,    10,    27,
      39,    59,   -60,   -60,    57,    60,    35,    58,   -60,   -60,
     -60,   -60,    35,   -60,    56,    -2,    50,    45,    46,    18,
     -60,    -7,   -60,   -17,   -60,   -60,   -60,   -60,   -60,   -60,
      65,    69,   -60,    30,    37,   -60,   -60,   -17,   -17,   -60,
      70,   -60,   -60,    49,   -60,   -17,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -17,   -17,   -60,   -60,   -17,    51,
      52,   -60,   -17,   -17,   -60,   -60,   -60,    41,    37,   -60,
      15,    15,    68,   -60,    54,    74,    80,   -60,   -60,   -60,
     -17,    15,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,    83,    61,     9,   -60,   -60,   -60,   -60,
      62,    64,   -60,   -60,   -60,   -59,   -60,   -60,   -60,   -39,
     -16,   -60,   -60,   -60,    16,   -60,    17,   -60,    13,   -60,
     -60,   -60,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      60,    41,    42,    37,    63,    38,    39,    61,     9,    12,
      28,    40,    11,    13,    43,    15,    41,    42,    79,    80,
      37,    17,    38,    39,    62,    19,    85,    28,    59,    43,
      14,    96,    97,    41,    42,    19,    41,    42,     1,     2,
     -14,    34,   103,    92,    93,    24,    43,    18,     2,    43,
      66,    67,    68,    69,    70,    71,    72,    73,    86,    86,
      12,   102,    86,    23,    13,    76,    77,    72,    73,    25,
      26,    27,    28,    31,    36,    64,    57,    58,    65,    84,
      81,    90,    91,    98,    99,   100,   101,    10,    30,    29,
      87,    89,    88,    33
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      39,    18,    19,     5,    43,     7,     8,    14,     0,    10,
      12,    13,    18,    14,    31,    19,    18,    19,    57,    58,
       5,    15,     7,     8,    31,    16,    65,    12,    10,    31,
      31,    90,    91,    18,    19,    26,    18,    19,     3,     4,
      30,    32,   101,    82,    83,    18,    31,     3,     4,    31,
      20,    21,    22,    23,    24,    25,    26,    27,    74,    75,
      10,   100,    78,    10,    14,    28,    29,    26,    27,    30,
      11,    14,    12,    15,    18,    10,    31,    31,     9,    30,
      10,    30,    30,    15,    30,    11,     6,     4,    26,    25,
      74,    78,    75,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    34,    35,    36,    37,    38,    39,     0,
      36,    18,    10,    14,    31,    19,    40,    15,     3,    38,
      41,    42,    43,    10,    18,    30,    11,    14,    12,    44,
      43,    15,    45,    37,    38,    46,    18,     5,     7,     8,
      13,    18,    19,    31,    44,    47,    48,    49,    50,    51,
      52,    53,    55,    57,    59,    61,    62,    31,    31,    10,
      52,    14,    31,    52,    10,     9,    20,    21,    22,    23,
      24,    25,    26,    27,    56,    58,    28,    29,    60,    52,
      52,    10,    54,    63,    30,    52,    53,    57,    59,    61,
      30,    30,    52,    52,    64,    65,    48,    48,    15,    30,
      11,     6,    52,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 48 "bison.y"
    {root = (yyvsp[(1) - (1)]);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 50 "bison.y"
    { 
                            YYSTYPE t = (yyvsp[(1) - (2)]);
                            (yyval) = t;
                            while(t->sibling) t = t->sibling;
                            t->sibling = (yyvsp[(2) - (2)]);
                        }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 56 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 58 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 59 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 61 "bison.y"
    {  
                            (yyval) = new TreeNode(VarDeclK);
                            (yyval)->child[0] = (yyvsp[(1) - (3)]);
                            (yyval)->child[1] = new TreeNode(IDK);
                            strcpy((yyval)->child[1]->attr.name, id);
                            // type_check(id, $$->type, TYPE_INT);
                        }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 68 "bison.y"
    {  
                            (yyval) = new TreeNode(VarDeclK);
                            (yyval)->child[0] = (yyvsp[(1) - (6)]);
                            (yyval)->child[1] = new TreeNode(IDK);
                            strcpy((yyval)->child[1]->attr.name,id);
                            (yyval)->child[2] = new TreeNode(NumK);
                            (yyval)->child[2]->value = value;
                            //$$->child[1]->array_len = value;
                        }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 78 "bison.y"
    {(yyval) = new TreeNode(TypeK); (yyval)->type = TYPE_INT;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 79 "bison.y"
    {(yyval) = new TreeNode(TypeK); (yyval)->type = TYPE_VOID;}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 81 "bison.y"
    {(yyval)=new TreeNode(IDK);strcpy((yyval)->attr.name,id);strcpy(savedname,id); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 82 "bison.y"
    {
                            (yyval) = new TreeNode(FunK);
                            (yyval)->child[0] = (yyvsp[(1) - (7)]);
                            //$$->child[1] = new TreeNode(IDK);
                            (yyval)->child[1] = (yyvsp[(4) - (7)]);
                            (yyval)->child[2] = (yyvsp[(5) - (7)]);
                            (yyval)->child[3] = (yyvsp[(7) - (7)]);
                            //strcpy($$->child[1]->attr.name,savedname);
                            //type_check(id, $$->type, TYPE_VOID);
                        }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 94 "bison.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 95 "bison.y"
    {
                            (yyval) = new TreeNode(TypeK);
                            (yyval)->type = TYPE_VOID;
                        }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 100 "bison.y"
    {  
                            YYSTYPE t = (yyvsp[(1) - (3)]); 
                            (yyval) = t;
                            while(t->sibling) t = t->sibling;
                            t->sibling = (yyvsp[(3) - (3)]);
                        }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 106 "bison.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 108 "bison.y"
    {   
                            (yyval) = new TreeNode(ParamK);
                            (yyval)->child[0] = (yyvsp[(1) - (2)]);
                            (yyval)->child[1] = new TreeNode(IDK);
                            strcpy((yyval)->child[1]->attr.name, id);
                        }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 114 "bison.y"
    {
                            (yyval) = new TreeNode(ParamK);
                            (yyval)->child[0] = (yyvsp[(1) - (4)]);
                            (yyval)->child[1] = new TreeNode(IDK);
                            strcpy((yyval)->child[1]->attr.name, id);
                            (yyval)->child[1]->array_len = -1;
                        }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 123 "bison.y"
    {
                            YYSTYPE t = (yyvsp[(2) - (4)]);
                            if(!t) (yyval) = (yyvsp[(3) - (4)]);
                            else{
                                (yyval) = t;
                                while(t->sibling) t = t->sibling;
                                t->sibling = (yyvsp[(3) - (4)]);
                            }  
                        }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 133 "bison.y"
    {
                            if((yyvsp[(1) - (2)]) == NULL)
                                (yyval) = (yyvsp[(2) - (2)]);
                            else
                            {
                                YYSTYPE t = (yyvsp[(1) - (2)]);
                                (yyval) = t;
                                while(t->sibling) t = t->sibling;
                                t->sibling = (yyvsp[(2) - (2)]);
                            }
                        }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 144 "bison.y"
    {(yyval) = NULL;}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 146 "bison.y"
    {
                            if((yyvsp[(1) - (2)]) == NULL) 
                                (yyval) = (yyvsp[(2) - (2)]);
                            else
                            {
                                YYSTYPE t = (yyvsp[(1) - (2)]);
                                (yyval) = t;
                                while(t->sibling) t = t->sibling;
                                t->sibling = (yyvsp[(2) - (2)]);
                            }
                        }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 157 "bison.y"
    {(yyval) = NULL;}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 160 "bison.y"
    { (yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 163 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 164 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 165 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 166 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 167 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 170 "bison.y"
    {   (yyval) = new TreeNode(IfK);
                            (yyval)->child[0] = (yyvsp[(3) - (5)]);
                            (yyval)->child[1] = (yyvsp[(5) - (5)]);
                        }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 175 "bison.y"
    {   (yyval) = new TreeNode(IfK);
                           (yyval)->child[0] = (yyvsp[(3) - (7)]);
                            (yyval)->child[1] = (yyvsp[(5) - (7)]);
                            (yyval)->child[2] = (yyvsp[(7) - (7)]);
                        }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 183 "bison.y"
    {   (yyval) = new TreeNode(WhileK);
                            (yyval)->child[0] = (yyvsp[(3) - (5)]);
                            (yyval)->child[1] = (yyvsp[(5) - (5)]);
                        }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 188 "bison.y"
    { (yyval) = new TreeNode(ReturnK);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 189 "bison.y"
    { (yyval) = new TreeNode(ReturnK); (yyval)->child[0] = (yyvsp[(2) - (3)]);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 192 "bison.y"
    {   (yyval) = new TreeNode(ExprK);
                            (yyval)->child[0] = (yyvsp[(1) - (3)]);
                            (yyval)->child[1] = (yyvsp[(3) - (3)]);
                        }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 196 "bison.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 198 "bison.y"
    {(yyval) = new TreeNode(IDK); strcpy((yyval)->attr.name, id);
                        }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 200 "bison.y"
    {(yyval)=new TreeNode(IDK);strcpy((yyval)->attr.name,id);strcpy(savedname, id);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 202 "bison.y"
    {   (yyval) = new TreeNode(VarK);
                            //strcpy($$->attr.name, id);
                            //$$->child[0] = new TreeNode(IDK);
                            //strcpy($$->child[0]->attr.name, savedname); 
                            (yyval)->child[0] = (yyvsp[(3) - (5)]);
                            (yyval)->array_len = -1;  // or -2;
                            (yyval)->child[1] = (yyvsp[(4) - (5)]);
                        }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 212 "bison.y"
    {   (yyval) = (yyvsp[(2) - (3)]); 
                            (yyval)->child[0] = (yyvsp[(1) - (3)]);
                            (yyval)->child[1] = (yyvsp[(3) - (3)]);
                        }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 216 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 218 "bison.y"
    { (yyval) = new TreeNode(OPK); (yyval)->attr.op = Less;}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 219 "bison.y"
    { (yyval) = new TreeNode(OPK); (yyval)->attr.op = Lessqual;}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 220 "bison.y"
    { (yyval) = new TreeNode(OPK); (yyval)->attr.op = More;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 221 "bison.y"
    { (yyval) = new TreeNode(OPK); (yyval)->attr.op = Moreequal;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 222 "bison.y"
    { (yyval) = new TreeNode(OPK); (yyval)->attr.op = Equal;}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 223 "bison.y"
    { (yyval) = new TreeNode(OPK); (yyval)->attr.op = Notequal;}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 226 "bison.y"
    {   (yyval) = (yyvsp[(2) - (3)]); 
                            (yyval)->child[0] = (yyvsp[(1) - (3)]);
                            (yyval)->child[1] = (yyvsp[(3) - (3)]);
                        }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 230 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 232 "bison.y"
    {(yyval) = new TreeNode(OPK); (yyval)->attr.op = Plus;}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 233 "bison.y"
    {(yyval) = new TreeNode(OPK); (yyval)->attr.op=Minus;}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 236 "bison.y"
    {   (yyval) = (yyvsp[(2) - (3)]);
                            (yyval)->child[0] = (yyvsp[(1) - (3)]);
                            (yyval)->child[1] = (yyvsp[(3) - (3)]);
                        }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 240 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 242 "bison.y"
    {(yyval) = new TreeNode(OPK); (yyval)->attr.op=Multi;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 243 "bison.y"
    {(yyval) = new TreeNode(OPK);(yyval)->attr.op = Divide;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 245 "bison.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 246 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 247 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 248 "bison.y"
    {(yyval)=new TreeNode(NumK);(yyval)->value = value;}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 250 "bison.y"
    {(yyval)=new TreeNode(IDK);strcpy((yyval)->attr.name,id);strcpy(savedname, id);}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 252 "bison.y"
    {   (yyval) = new TreeNode(CallK);
                            //$$->child[0] = new TreeNode(IDK);
                            (yyval)->child[0] = (yyvsp[(3) - (5)]);
                            //strcpy($$->child[0]->attr.name, id);
                            //strcpy($$->child[0]->attr.name,savedname);
                            (yyval)->child[1] = (yyvsp[(4) - (5)]);
                        }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 260 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 261 "bison.y"
    {(yyval) = NULL; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 264 "bison.y"
    {   YYSTYPE t = (yyvsp[(1) - (3)]);
                            (yyval) = t;
                            while(t->sibling) t = t->sibling;
                            t->sibling = (yyvsp[(3) - (3)]);
                        }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 269 "bison.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;


/* Line 1792 of yacc.c  */
#line 1962 "bison.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 273 "bison.y"


void type_check(char* val, ValType type, ValType correct_type)
{
    if(correct_type == type) return;
    if(type == TYPE_INT)printf("类型检查错误, 变量%s的类型应为int\n", val);
    else printf("类型检查错误, 函数%s的返回类型应为void\n", val);
}
/*
int yyerror(char * message)
{ //fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  //fprintf(listing,"Current token: ");
  //printToken(yychar,tokenString);
  //Error = TRUE;
  return 0;
}
*/

static int yylex()
{ return getToken(); }

int yyerror(const char* s){
    //fprintf(stderr, "error: %s at line %d\n", s, lineno);

    fprintf(fd,"Syntax error at line %d\n",lineno);
    return 0;
}
TreeNode * parse(void)
{ yyparse();
  return root;
}

