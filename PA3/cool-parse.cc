
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yylval          cool_yylval
#define yychar          cool_yychar
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs
#define yylloc          cool_yylloc

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "cool.y"

  #include <iostream>
  #include "cool-tree.h"
  #include "stringtab.h"
  #include "utilities.h"
  
  extern char *curr_filename;
  
  
  /* Locations */
  #define YYLTYPE int              /* the type of locations */
  #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer
  for the location of tokens */
    
    extern int node_lineno;          /* set before constructing a tree node
    to whatever you want the line number
    for the tree node to be */
      
      
      #define YYLLOC_DEFAULT(Current, Rhs, N)         \
      Current = Rhs[1];                             \
      node_lineno = Current;
    
    
    #define SET_NODELOC(Current)  \
    node_lineno = Current;
    
    /* IMPORTANT NOTE ON LINE NUMBERS
    *********************************
    * The above definitions and macros cause every terminal in your grammar to 
    * have the line number supplied by the lexer. The only task you have to
    * implement for line numbers to work correctly, is to use SET_NODELOC()
    * before constructing any constructs from non-terminals in your grammar.
    * Example: Consider you are matching on the following very restrictive 
    * (fictional) construct that matches a plus between two integer constants. 
    * (SUCH A RULE SHOULD NOT BE  PART OF YOUR PARSER):
    
    plus_consts	: INT_CONST '+' INT_CONST 
    
    * where INT_CONST is a terminal for an integer constant. Now, a correct
    * action for this rule that attaches the correct line number to plus_const
    * would look like the following:
    
    plus_consts	: INT_CONST '+' INT_CONST 
    {
      // Set the line number of the current non-terminal:
      // ***********************************************
      // You can access the line numbers of the i'th item with @i, just
      // like you acess the value of the i'th exporession with $i.
      //
      // Here, we choose the line number of the last INT_CONST (@3) as the
      // line number of the resulting expression (@$). You are free to pick
      // any reasonable line as the line number of non-terminals. If you 
      // omit the statement @$=..., bison has default rules for deciding which 
      // line number to use. Check the manual for details if you are interested.
      @$ = @3;
      
      
      // Observe that we call SET_NODELOC(@3); this will set the global variable
      // node_lineno to @3. Since the constructor call "plus" uses the value of 
      // this global, the plus node will now have the correct line number.
      SET_NODELOC(@3);
      
      // construct the result node:
      $$ = plus(int_const($1), int_const($3));
    }
    
    */
    
    
    
    void yyerror(char *s);        /*  defined below; called for each parse error */
    extern int yylex();           /*  the entry point to the lexer  */
    
    /************************************************************************/
    /*                DONT CHANGE ANYTHING IN THIS SECTION                  */
    
    Program ast_root;	      /* the result of the parse  */
    Classes parse_results;        /* for use in semantic analysis */
    int omerrs = 0;               /* number of errors in lexing and parsing */
    

/* Line 189 of yacc.c  */
#line 164 "cool.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     ELSE = 259,
     FI = 260,
     IF = 261,
     IN = 262,
     INHERITS = 263,
     LET = 264,
     LOOP = 265,
     POOL = 266,
     THEN = 267,
     WHILE = 268,
     CASE = 269,
     ESAC = 270,
     OF = 271,
     DARROW = 272,
     NEW = 273,
     ISVOID = 274,
     STR_CONST = 275,
     INT_CONST = 276,
     BOOL_CONST = 277,
     TYPEID = 278,
     OBJECTID = 279,
     ASSIGN = 280,
     NOT = 281,
     LE = 282,
     ERROR = 283
   };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 89 "cool.y"

      Boolean boolean;
      Symbol symbol;
      Program program;
      Class_ class_;
      Classes classes;
      Feature feature;
      Features features;
      Formal formal;
      Formals formals;
      Case case_;
      Cases cases;
      Expression expression;
      Expressions expressions;
      char *error_msg;
    


/* Line 214 of yacc.c  */
#line 275 "cool.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 300 "cool.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    35,    33,    46,    34,    39,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    40,
      31,    32,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,    37,     2,     2,     2,
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
      25,    26,    27,    28,     2,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    18,    26,    28,    29,
      32,    36,    46,    50,    56,    58,    59,    61,    65,    69,
      70,    72,    76,    79,    83,    86,    92,   100,   106,   114,
     121,   129,   133,   140,   149,   154,   162,   168,   172,   174,
     180,   183,   186,   190,   194,   198,   202,   205,   209,   213,
     217,   220,   224,   226,   228,   230,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    40,    -1,    49,    50,
      40,    -1,     3,    23,    41,    51,    42,    -1,     3,    23,
       8,    23,    41,    51,    42,    -1,     1,    -1,    -1,    52,
      40,    -1,    51,    52,    40,    -1,    24,    43,    53,    44,
      45,    23,    41,    60,    42,    -1,    24,    45,    23,    -1,
      24,    45,    23,    25,    60,    -1,     1,    -1,    -1,    54,
      -1,    53,    46,    54,    -1,    24,    45,    23,    -1,    -1,
      60,    -1,    55,    46,    60,    -1,    60,    40,    -1,    56,
      60,    40,    -1,     9,    58,    -1,    24,    45,    23,     7,
      60,    -1,    24,    45,    23,    25,    60,     7,    60,    -1,
      24,    45,    23,    46,    58,    -1,    24,    45,    23,    25,
      60,    46,    58,    -1,    24,    45,    23,    17,    60,    40,
      -1,    59,    24,    45,    23,    17,    60,    40,    -1,    24,
      25,    60,    -1,    60,    39,    24,    43,    55,    44,    -1,
      60,    38,    23,    39,    24,    43,    55,    44,    -1,    24,
      43,    55,    44,    -1,     6,    60,    12,    60,     4,    60,
       5,    -1,    13,    60,    10,    60,    11,    -1,    41,    56,
      42,    -1,    57,    -1,    14,    60,    16,    59,    15,    -1,
      18,    23,    -1,    19,    60,    -1,    60,    33,    60,    -1,
      60,    34,    60,    -1,    60,    35,    60,    -1,    60,    36,
      60,    -1,    37,    60,    -1,    60,    31,    60,    -1,    60,
      30,    60,    -1,    60,    32,    60,    -1,    26,    60,    -1,
      43,    60,    44,    -1,    24,    -1,    21,    -1,    20,    -1,
      22,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   175,   182,   192,   199,   205,   211,   214,
     220,   231,   237,   244,   252,   259,   262,   268,   277,   288,
     291,   297,   305,   312,   320,   328,   334,   340,   346,   354,
     362,   372,   378,   385,   392,   399,   405,   411,   418,   427,
     435,   441,   447,   453,   459,   465,   471,   477,   483,   489,
     495,   500,   506,   512,   518,   524,   530
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "\"<-\"", "\"<=\"",
  "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'", "';'",
  "'{'", "'}'", "'('", "')'", "':'", "','", "$accept", "program",
  "class_list", "class", "feature_list", "feature", "formal_list",
  "formal", "comma_expr_list", "expr_semi_list", "expr_let_part_1",
  "expr_let_part_2", "expr_case_list", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   285,
     286,    60,    61,    43,    45,    42,    47,   126,    64,    46,
      59,   123,   125,    40,    41,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      51,    52,    52,    52,    52,    53,    53,    53,    54,    55,
      55,    55,    56,    56,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     5,     7,     1,     0,     2,
       3,     9,     3,     5,     1,     0,     1,     3,     3,     0,
       1,     3,     2,     3,     2,     5,     7,     5,     7,     6,
       7,     3,     6,     8,     4,     7,     5,     3,     1,     5,
       2,     2,     3,     3,     3,     3,     2,     3,     3,     3,
       2,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     0,     0,     1,     0,     3,
       0,     0,     4,     0,    14,     0,     0,     0,     0,    15,
       0,     5,     0,     9,     0,     0,     0,    16,    12,    10,
       6,     0,     0,     0,     0,    18,     0,    17,    56,     0,
       0,     0,     0,     0,     0,    54,    53,    55,    52,     0,
       0,     0,     0,    38,    13,     0,     0,     0,    24,     0,
       0,    40,    41,     0,     0,    50,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    20,    37,     0,    22,
      51,    48,    47,    49,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,    23,     0,
       0,    11,     0,     0,     0,     0,    36,     0,    39,     0,
      21,     0,     0,     0,    25,     0,    27,     0,     0,     0,
      32,    35,     0,     0,     0,     0,     0,    26,    28,     0,
       0,    33,    29,     0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    17,    26,    27,    85,    67,
      53,    58,   105,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
      60,  -107,    12,    58,    74,     9,    -7,  -107,    22,  -107,
      53,     1,  -107,    40,  -107,   -24,     2,    45,     1,    70,
      78,  -107,    57,  -107,     8,    62,    25,  -107,    77,  -107,
    -107,    82,    68,    70,   116,  -107,    92,  -107,  -107,   116,
      95,   116,   116,    97,   116,  -107,  -107,  -107,   -19,   116,
     116,   116,   116,  -107,   279,    80,   187,    79,  -107,   162,
     197,  -107,   -11,   116,    46,   279,   -11,    90,   235,   207,
     116,   116,   116,   116,   116,   116,   116,   100,   102,   116,
     116,   105,   116,   117,   279,    38,   279,  -107,   246,  -107,
    -107,   289,   289,   289,    18,    18,   -11,   -11,   111,   112,
     222,   150,     5,   176,   115,    -4,  -107,   116,  -107,   134,
      46,  -107,   116,   116,   116,    95,  -107,   133,  -107,   124,
     279,   118,    42,   113,   279,   132,  -107,   156,   151,    46,
    -107,  -107,   116,    95,   116,   158,    49,   279,  -107,   257,
     116,  -107,  -107,   268,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,   172,   159,    -2,  -107,   146,  -106,  -107,
    -107,  -102,  -107,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      54,    10,    14,    14,   122,    56,    63,    59,    60,    14,
      62,   118,   113,   126,    22,    65,    66,    68,    69,    19,
     119,    20,    22,   136,    64,    15,    15,    77,    78,    84,
     114,   138,    15,    88,    11,     6,    91,    92,    93,    94,
      95,    96,    97,    -8,    21,   100,   101,    38,   103,     9,
      30,   115,    39,    75,    76,    40,    77,    78,     7,    41,
      42,     1,    12,     2,    43,    44,    45,    46,    47,    32,
      48,    33,    49,   120,    -2,     1,    13,     2,   123,   124,
     125,    18,   106,    50,   107,    23,   130,    51,   107,    52,
     -19,    38,   -19,   141,    25,   107,    39,    29,   137,    40,
     139,    28,    34,    41,    42,    35,   143,    31,    43,    44,
      45,    46,    47,    36,    48,    55,    49,    38,   131,    57,
      61,    79,    39,    98,    81,    40,    99,    50,   102,    41,
      42,    51,    87,    52,    43,    44,    45,    46,    47,   132,
      48,   104,    49,    70,    71,    72,    73,    74,    75,    76,
     109,    77,    78,    50,   112,   110,   127,    51,   121,    52,
     117,   129,    70,    71,    72,    73,    74,    75,    76,   128,
      77,    78,    82,   134,   135,   140,     8,    24,   133,    37,
      70,    71,    72,    73,    74,    75,    76,   116,    77,    78,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    80,
      77,    78,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    83,    77,    78,     0,    70,    71,    72,
      73,    74,    75,    76,     0,    77,    78,    70,    71,    72,
      73,    74,    75,    76,     0,    77,    78,    70,    71,    72,
      73,    74,    75,    76,     0,    77,    78,     0,     0,     0,
       0,    90,    70,    71,    72,    73,    74,    75,    76,     0,
      77,    78,     0,     0,   111,    70,    71,    72,    73,    74,
      75,    76,     0,    77,    78,    89,    70,    71,    72,    73,
      74,    75,    76,     0,    77,    78,   108,    70,    71,    72,
      73,    74,    75,    76,     0,    77,    78,   142,    70,    71,
      72,    73,    74,    75,    76,     0,    77,    78,   144,    70,
      71,    72,    73,    74,    75,    76,     0,    77,    78,   -20,
     -20,   -20,    73,    74,    75,    76,     0,    77,    78
};

static const yytype_int16 yycheck[] =
{
      34,     8,     1,     1,   110,    39,    25,    41,    42,     1,
      44,    15,     7,   115,    16,    49,    50,    51,    52,    43,
      24,    45,    24,   129,    43,    24,    24,    38,    39,    63,
      25,   133,    24,    67,    41,    23,    70,    71,    72,    73,
      74,    75,    76,    42,    42,    79,    80,     1,    82,    40,
      42,    46,     6,    35,    36,     9,    38,    39,     0,    13,
      14,     1,    40,     3,    18,    19,    20,    21,    22,    44,
      24,    46,    26,   107,     0,     1,    23,     3,   112,   113,
     114,    41,    44,    37,    46,    40,    44,    41,    46,    43,
      44,     1,    46,    44,    24,    46,     6,    40,   132,     9,
     134,    23,    25,    13,    14,    23,   140,    45,    18,    19,
      20,    21,    22,    45,    24,    23,    26,     1,     5,    24,
      23,    41,     6,    23,    45,     9,    24,    37,    23,    13,
      14,    41,    42,    43,    18,    19,    20,    21,    22,     7,
      24,    24,    26,    30,    31,    32,    33,    34,    35,    36,
      39,    38,    39,    37,     4,    43,    23,    41,    24,    43,
      45,    43,    30,    31,    32,    33,    34,    35,    36,    45,
      38,    39,    10,    17,    23,    17,     4,    18,    46,    33,
      30,    31,    32,    33,    34,    35,    36,    11,    38,    39,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    12,
      38,    39,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    16,    38,    39,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    44,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    42,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    48,    49,    50,    23,     0,    50,    40,
       8,    41,    40,    23,     1,    24,    51,    52,    41,    43,
      45,    42,    52,    40,    51,    24,    53,    54,    23,    40,
      42,    45,    44,    46,    25,    23,    45,    54,     1,     6,
       9,    13,    14,    18,    19,    20,    21,    22,    24,    26,
      37,    41,    43,    57,    60,    23,    60,    24,    58,    60,
      60,    23,    60,    25,    43,    60,    60,    56,    60,    60,
      30,    31,    32,    33,    34,    35,    36,    38,    39,    41,
      12,    45,    10,    16,    60,    55,    60,    42,    60,    40,
      44,    60,    60,    60,    60,    60,    60,    60,    23,    24,
      60,    60,    23,    60,    24,    59,    44,    46,    40,    39,
      43,    42,     4,     7,    25,    46,    11,    45,    15,    24,
      60,    24,    55,    60,    60,    60,    58,    23,    45,    43,
      44,     5,     7,    46,    17,    23,    55,    60,    58,    60,
      17,    44,    40,    60,    40
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 167 "cool.y"
    {
      (yyloc) = (yylsp[(1) - (1)]);
      SET_NODELOC((yylsp[(1) - (1)]))
      ast_root = program((yyvsp[(1) - (1)].classes));
    }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 176 "cool.y"
    { 
      (yyloc) = (yylsp[(1) - (2)]);
      SET_NODELOC((yylsp[(1) - (2)]));
      (yyval.classes) = single_Classes((yyvsp[(1) - (2)].class_));
      parse_results = (yyval.classes); 
    }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 183 "cool.y"
    { 
      (yyloc) = (yylsp[(2) - (3)]);
      SET_NODELOC((yylsp[(2) - (3)]));
      (yyval.classes) = append_Classes((yyvsp[(1) - (3)].classes),single_Classes((yyvsp[(2) - (3)].class_))); 
      parse_results = (yyval.classes); 
    }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 193 "cool.y"
    {   
      (yyloc) = (yylsp[(4) - (5)]);
      SET_NODELOC((yylsp[(4) - (5)]));
      (yyval.class_) = class_((yyvsp[(2) - (5)].symbol),idtable.add_string("Object"),(yyvsp[(4) - (5)].features),
		  stringtable.add_string(curr_filename));
    }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 200 "cool.y"
    {  
      (yyloc) = (yylsp[(6) - (7)]);
      SET_NODELOC((yylsp[(6) - (7)]));
      (yyval.class_) = class_((yyvsp[(2) - (7)].symbol),(yyvsp[(4) - (7)].symbol),(yyvsp[(6) - (7)].features),stringtable.add_string(curr_filename)); 
    }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 206 "cool.y"
    {}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 211 "cool.y"
    {   
      (yyval.features) = nil_Features(); 
    }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 215 "cool.y"
    {
      (yyloc) = (yylsp[(1) - (2)]);
      SET_NODELOC((yylsp[(1) - (2)]));
      (yyval.features) = single_Features((yyvsp[(1) - (2)].feature));
    }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 221 "cool.y"
    {     
      (yyloc) = (yylsp[(2) - (3)]);
      SET_NODELOC((yylsp[(2) - (3)]));
      (yyval.features) = append_Features((yyvsp[(1) - (3)].features), single_Features((yyvsp[(2) - (3)].feature)));
    }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 232 "cool.y"
    { 
      (yyloc) = (yylsp[(8) - (9)]);
      SET_NODELOC((yylsp[(8) - (9)]));
      (yyval.feature) = method((yyvsp[(1) - (9)].symbol), (yyvsp[(3) - (9)].formals), (yyvsp[(6) - (9)].symbol), (yyvsp[(8) - (9)].expression));
    }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 238 "cool.y"
    {  
      (yyloc) = (yylsp[(3) - (3)]);
      SET_NODELOC((yylsp[(3) - (3)]));
      // init is null, so to create a null expression
      (yyval.feature) = attr((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), no_expr());
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 245 "cool.y"
    {   
      (yyloc) = (yylsp[(5) - (5)]);
      SET_NODELOC((yylsp[(5) - (5)]));
      // create ASSIGN node
      Expression assign_node = assign((yyvsp[(1) - (5)].symbol), (yyvsp[(5) - (5)].expression));
      (yyval.feature) = attr((yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].symbol), assign_node);
    }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 253 "cool.y"
    {}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 259 "cool.y"
    { 
      (yyval.formals) = nil_Formals();
    }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 263 "cool.y"
    {
      (yyloc) = (yylsp[(1) - (1)]);
      SET_NODELOC((yylsp[(1) - (1)]))
      (yyval.formals) = single_Formals((yyvsp[(1) - (1)].formal));    
    }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 269 "cool.y"
    {  
      (yyloc) = (yylsp[(3) - (3)]);
      SET_NODELOC((yylsp[(3) - (3)]));
      (yyval.formals) = append_Formals((yyvsp[(1) - (3)].formals), single_Formals((yyvsp[(3) - (3)].formal)));  
    }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 278 "cool.y"
    { 
      (yyloc) = (yylsp[(3) - (3)]);
      SET_NODELOC((yylsp[(3) - (3)]));
      (yyval.formal) = formal((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol));
    }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 288 "cool.y"
    {
      (yyval.expressions) = nil_Expressions();
    }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 292 "cool.y"
    {  
      (yyloc) = (yylsp[(1) - (1)]);
      SET_NODELOC((yylsp[(1) - (1)]));
      (yyval.expressions) = single_Expressions((yyvsp[(1) - (1)].expression));
    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 298 "cool.y"
    {
      (yyloc) = (yylsp[(3) - (3)]);
      SET_NODELOC((yylsp[(3) - (3)]));
      (yyval.expressions) = append_Expressions((yyvsp[(1) - (3)].expressions), single_Expressions((yyvsp[(3) - (3)].expression)));
    }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 306 "cool.y"
    { 
      (yyloc) = (yylsp[(1) - (2)]);
      SET_NODELOC((yylsp[(1) - (2)]));
      // Expressions single_Expression(Expression e)
      (yyval.expressions) = single_Expressions((yyvsp[(1) - (2)].expression));
    }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 313 "cool.y"
    { 
      (yyloc) = (yylsp[(2) - (3)]);
      SET_NODELOC((yylsp[(2) - (3)]));
      (yyval.expressions) = append_Expressions((yyvsp[(1) - (3)].expressions), single_Expressions((yyvsp[(2) - (3)].expression)));
    }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 321 "cool.y"
    { 
      (yyloc) = (yylsp[(2) - (2)]);
      SET_NODELOC((yylsp[(2) - (2)]));
      (yyval.expression) = (yyvsp[(2) - (2)].expression);
    }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 329 "cool.y"
    { 
      (yyloc) = (yylsp[(5) - (5)]);
      SET_NODELOC((yylsp[(5) - (5)]));
      (yyval.expression) = let((yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].symbol), no_expr(), (yyvsp[(5) - (5)].expression));
    }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 335 "cool.y"
    { 
      (yyloc) = (yylsp[(7) - (7)]);
      SET_NODELOC((yylsp[(7) - (7)]));
      (yyval.expression) = let((yyvsp[(1) - (7)].symbol), (yyvsp[(3) - (7)].symbol), (yyvsp[(5) - (7)].expression), (yyvsp[(7) - (7)].expression));
    }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 341 "cool.y"
    {  
      (yyloc) = (yylsp[(5) - (5)]);
      SET_NODELOC((yylsp[(5) - (5)]));
      (yyval.expression) = let((yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].symbol), no_expr(), (yyvsp[(5) - (5)].expression));
    }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 347 "cool.y"
    {
      (yyloc) = (yylsp[(7) - (7)]);
      SET_NODELOC((yylsp[(7) - (7)]));
      (yyval.expression) = let((yyvsp[(1) - (7)].symbol), (yyvsp[(3) - (7)].symbol), (yyvsp[(5) - (7)].expression), (yyvsp[(7) - (7)].expression));
    }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 355 "cool.y"
    {//ID:TYPE=>expr;
      (yyloc) = (yylsp[(5) - (6)]);
      SET_NODELOC((yylsp[(5) - (6)]));
      // Cases single_Cases(Case e)
      // Case branch(Symbol name, Symbol type_decl, Expression expr)
      (yyval.cases) = single_Cases(branch((yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].symbol), (yyvsp[(5) - (6)].expression)));
    }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 363 "cool.y"
    { //ID:TYPE=>expr;ID:TYPE=>expr;......ID:TYPE=>expr;
      (yyloc) = (yylsp[(6) - (7)]);
      SET_NODELOC((yylsp[(6) - (7)]));
      (yyval.cases) = append_Cases((yyvsp[(1) - (7)].cases), single_Cases(branch((yyvsp[(2) - (7)].symbol), (yyvsp[(4) - (7)].symbol), (yyvsp[(6) - (7)].expression))));
    }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 373 "cool.y"
    { 
      (yyloc) = (yylsp[(3) - (3)]);
      SET_NODELOC((yylsp[(3) - (3)]));
      (yyval.expression) = assign((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 379 "cool.y"
    {  
      // dispatch
      (yyloc) = (yylsp[(5) - (6)]);
      SET_NODELOC((yylsp[(5) - (6)]));
      (yyval.expression) = dispatch((yyvsp[(1) - (6)].expression), (yyvsp[(3) - (6)].symbol), (yyvsp[(5) - (6)].expressions));
    }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 386 "cool.y"
    {   
      // static dispatch, used to access methods in parent class
      (yyloc) = (yylsp[(7) - (8)]);
      SET_NODELOC((yylsp[(7) - (8)]));
	  (yyval.expression) = static_dispatch((yyvsp[(1) - (8)].expression), (yyvsp[(3) - (8)].symbol), (yyvsp[(5) - (8)].symbol), (yyvsp[(7) - (8)].expressions));
    }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 393 "cool.y"
    { // self dispatch
      // self.id(), so need to create a 'self' expression
      (yyloc) = (yylsp[(3) - (4)]);
      SET_NODELOC((yylsp[(3) - (4)]));
      (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].expressions));
    }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 400 "cool.y"
    { // if...else.... grammar
      (yyloc) = (yylsp[(7) - (7)]);
      SET_NODELOC((yylsp[(7) - (7)]));
      (yyval.expression) = cond((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].expression), (yyvsp[(6) - (7)].expression));
    }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 406 "cool.y"
    { // while grammar
      (yyloc) = (yylsp[(5) - (5)]);
      SET_NODELOC((yylsp[(5) - (5)]));
      (yyval.expression) = loop((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].expression));
    }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 412 "cool.y"
    { // block grammar
      // block(Expressions): Expression
      (yyloc) = (yylsp[(2) - (3)]);
      SET_NODELOC((yylsp[(2) - (3)]));
      (yyval.expression) = block((yyvsp[(2) - (3)].expressions));
    }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 419 "cool.y"
    {
      // let grammar is a recursive grammar--TODO
      // it is hard, wait to solve
      // ***********************************
      (yyloc) = (yylsp[(1) - (1)]);
      SET_NODELOC((yylsp[(1) - (1)]));
      (yyval.expression) = (yyvsp[(1) - (1)].expression);
    }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 428 "cool.y"
    { 
      // case grammar
      // typcase(expression, cases)
      (yyloc) = (yylsp[(5) - (5)]);
      SET_NODELOC((yylsp[(5) - (5)]));
      (yyval.expression) = typcase((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].cases));
    }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 436 "cool.y"
    { 
        (yyloc) = (yylsp[(2) - (2)]);
        SET_NODELOC((yylsp[(2) - (2)]));
        (yyval.expression) = new_((yyvsp[(2) - (2)].symbol));
    }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 442 "cool.y"
    {   
        (yyloc) = (yylsp[(2) - (2)]);
        SET_NODELOC((yylsp[(2) - (2)]));
        (yyval.expression) = isvoid((yyvsp[(2) - (2)].expression));
    }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 448 "cool.y"
    {    
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)]));
        (yyval.expression) = plus((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 454 "cool.y"
    {    
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)]));
        (yyval.expression) = sub((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 460 "cool.y"
    {   
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)]));
        (yyval.expression) = mul((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 466 "cool.y"
    {    
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)]));
        (yyval.expression) = divide((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 472 "cool.y"
    {    
        (yyloc) = (yylsp[(2) - (2)]);
        SET_NODELOC((yylsp[(2) - (2)]));
        (yyval.expression) = neg((yyvsp[(2) - (2)].expression));
    }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 478 "cool.y"
    {    
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)]));
        (yyval.expression) = lt((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 484 "cool.y"
    {    
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)]));
        (yyval.expression) = leq((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 490 "cool.y"
    {   
        (yyloc) = (yylsp[(3) - (3)]);
        SET_NODELOC((yylsp[(3) - (3)])); 
        (yyval.expression) = eq((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 496 "cool.y"
    { 
        (yyloc) = (yylsp[(2) - (2)]);
        (yyval.expression) = comp((yyvsp[(2) - (2)].expression));
    }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 501 "cool.y"
    {    
      (yyloc) = (yylsp[(2) - (3)]);
      SET_NODELOC((yylsp[(2) - (3)]));
      (yyval.expression) = (yyvsp[(2) - (3)].expression);        
    }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 507 "cool.y"
    { 
      (yyloc) = (yylsp[(1) - (1)]);
	  SET_NODELOC((yylsp[(1) - (1)]));
      (yyval.expression) = object((yyvsp[(1) - (1)].symbol));
    }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 513 "cool.y"
    {   
      (yyloc) = (yylsp[(1) - (1)]);
      SET_NODELOC((yylsp[(1) - (1)]));
      (yyval.expression) = int_const((yyvsp[(1) - (1)].symbol));
    }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 519 "cool.y"
    {  
      (yyloc) = (yylsp[(1) - (1)]);
	  SET_NODELOC((yylsp[(1) - (1)]));
      (yyval.expression) = string_const((yyvsp[(1) - (1)].symbol));
    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 525 "cool.y"
    {   
      (yyloc) = (yylsp[(1) - (1)]);
      SET_NODELOC((yylsp[(1) - (1)]));
	  (yyval.expression) = bool_const((yyvsp[(1) - (1)].boolean));
    }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 531 "cool.y"
    {
      
    }
    break;



/* Line 1455 of yacc.c  */
#line 2285 "cool.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 1675 of yacc.c  */
#line 538 "cool.y"

    
    /* This function is called automatically when Bison detects a parse error. */
    void yyerror(char *s)
    {
      extern int curr_lineno;
      
      cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
      << s << " at or near ";
      print_cool_token(yychar);
      cerr << endl;
      omerrs++;
      
      if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
    }
    
    

