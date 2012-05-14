/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

// nested comment level counter
int nested = 0;
%}

/*
 *  Add Your own definitions here
 */
DIGIT		[0-9]
INTEGER		{DIGIT}+

ASSIGN		"<-"
LE		"<="

c		[cC]
l		[lL]
a		[aA]
s		[sS]
e		[eE]
f		[fF]
i		[iI]
n		[nN]
h		[hH]
r		[rR]
t		[tT]
v		[vV]
o		[oO]
d		[dD]
p		[pP]
w		[wW]
u		[uU]
CLASS		{c}{l}{a}{s}{s}
ELSE		{e}{l}{s}{e}
FI		{f}{i}
IF		{i}{f}
IN		{i}{n}
INHERITS	{i}{n}{h}{e}{r}{i}{t}{s}
ISVOID		{i}{s}{v}{o}{i}{d}
LET		{l}{e}{t}
LOOP		{l}{o}{o}{p}
POOL		{p}{o}{o}{l}
THEN		{t}{h}{e}{n}
WHILE		{w}{h}{i}{l}{e}
CASE		{c}{a}{s}{e}
ESAC		{e}{s}{a}{c}
NEW		{n}{e}{w}
OF		{o}{f}
NOT		{n}{o}{t}
TRUE		t{r}{u}{e}
FALSE		f{a}{l}{s}{e}

NEWLINE		\n

TYPEID		[A-Z][a-zA-Z0-9_]*
OBJECTID	[a-z][a-zA-Z0-9_]*

WHITESPACE	[ \f\r\t\v]*

DARROW          =>

/*
 * Start state definition
 *
 * str: used in string process
 * Comment: used in comment process
 */
%s str Comment strnull
   	        
%%

 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */

 /* end of string */
<str>\"	{
    int maxchars = string_buf_ptr - string_buf;
    if (maxchars < MAX_STR_CONST) {
        BEGIN(INITIAL);
	string_buf_ptr = '\0';
	cool_yylval.symbol = stringtable.add_string(string_buf, maxchars);
	return STR_CONST;
    } else {
        cool_yylval.error_msg = "String constant too long";
	BEGIN(INITIAL);
	return ERROR;
    }
}	

 /* escaped white space */
<str>\\n	*string_buf_ptr++ = '\n'; 
<str>\\t	*string_buf_ptr++ = '\t';
<str>\\b	*string_buf_ptr++ = '\b';
<str>\\f	*string_buf_ptr++ = '\f';

 /* escaped null character '\0', recovery should start from */
 /* next line, so need to eat up '\n' */
<str>\\\0.*\n*    {
    cool_yylval.error_msg = "String contains escaped null character.";
    BEGIN(INITIAL);
    return ERROR;
}

 /* escaped other character */
<str>\\. 	*string_buf_ptr++ = yytext[1];
 /* escaped new line, using span multi-line string */
<str>\\\n	*string_buf_ptr++ = yytext[1]; ++curr_lineno;

 /* normal string character */
<str>[^\\\n"\0]*	{
    char *yptr = yytext;
    while (*yptr) {
        *string_buf_ptr++ = *yptr++;
    }
}
 /* null chararcter, should recovery from new line */
<str>\0(.|\\n)*\"		{
    cool_yylval.error_msg = "String contains null character.";
    BEGIN(INITIAL);
    return ERROR;
}
 /* non-escaped new line, it is error */
<str>\n	{
    cool_yylval.error_msg = "Unterminated string constant";
    curr_lineno += 1;
    BEGIN(INITIAL);
    return ERROR;
   
}
 /* end of file */
<str><<EOF>>	{
    cool_yylval.error_msg = "EOF in string constant";
    BEGIN(INITIAL);
    return ERROR;
}
 /* start of string */
<INITIAL>\"		{
    // initiate string point
    string_buf_ptr = string_buf;
    BEGIN(str);
}

 /*
  * one line comment
  */
<INITIAL>"--".*		

 /*
  * Integers
  */
{INTEGER}	{
    cool_yylval.symbol = inttable.add_string(yytext);
    return INT_CONST;
}

 /*
  * Special Notation
  */
{ASSIGN}	{ return ASSIGN; }

 /*
  *  Nested comments
  */

 /* nested commment start notation */
<Comment>"(*"			++nested;

 /* end of comment */
<Comment>"*)"		{
	if (--nested < 0) {
	   BEGIN(INITIAL);
	}
}
 /* new line in comment */
<Comment>\n			++curr_lineno;
 
 /* normal character in comment */
<Comment>[^*(\n)]*			/* eat up anything in the comment, if you want, you can store the comment information.*/

 /* eat up '*' not followered by ')', leaving it to  '*)' to process */
<Comment>\*/[^)]
 /* eat up '(' not followerd by '*', leaving it to '(*' to process */
<Comment>\(/[^*]		
 /* eat up a single ')' */
<Comment>\)

 /* end of file in comment */
<Comment><<EOF>>	{
    cool_yylval.error_msg = "EOF in comment";
    BEGIN(INITIAL);
    return ERROR;
}

 /* begin of comment */
"(*"	BEGIN(Comment); nested = 0;

 /* "*)" should be always in Comment state, if not, unmatched */
"*)"		{
    cool_yylval.error_msg = "Unmatched *)";
    BEGIN(INITIAL);
    return ERROR;
}

 /*
  *  The multiple-character operators.
  */
<INITIAL>{DARROW}		{ return (DARROW); }
{LE}				return LE;

 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */
{CLASS}		return CLASS;
{ELSE}		return ELSE;
{FI}		return FI;
{IF}		return IF;
{IN}		return IN;
{INHERITS}	return INHERITS;
{LET}		return LET;
{LOOP}		return LOOP;
{POOL}		return POOL;
{THEN}		return THEN;
{WHILE}		return WHILE;
{CASE}		return CASE;
{ESAC}		return ESAC;
{OF}		return OF;
{NEW}		return NEW;
{ISVOID}	return ISVOID;
{NOT}		return NOT;

{TRUE}		{
    cool_yylval.boolean = 1;
    return BOOL_CONST;    
}
{FALSE}		{
    cool_yylval.boolean = 0;
    return BOOL_CONST;
}

 /*
  * Identifers
  */
self		{ 
    cool_yylval.symbol = idtable.add_string(yytext);
    return OBJECTID;
}

SELF_TYPE	{
    cool_yylval.symbol = idtable.add_string(yytext);
    return TYPEID;
}


{TYPEID}	{
    cool_yylval.symbol = idtable.add_string(yytext);
    return TYPEID;
}

^_	{
	cool_yylval.error_msg = "_";
	return ERROR;
}

{OBJECTID}	{
    cool_yylval.symbol = idtable.add_string(yytext);
    return OBJECTID;
}


 /*
  * single character notation
  */
";"		return ';';
"{"		return '{';
"}"		return '}';
":"		return ':';
"."		return '.';
"("		return '(';
")"		return ')';
"="		return '=';
"+"		return '+';
"-"		return '-';
"*"		return '*';
"/"		return '/';
"<"		return '<';
","		return ',';
"~"		return '~';
"@"		return '@';

[!#$%^&_\>?`\[\]\\\|]    {
    cool_yylval.error_msg = yytext;
    return ERROR;		
}

\001	{
    cool_yylval.error_msg = "\001";
    return ERROR;
}
\002	{
    cool_yylval.error_msg = "\002";
    return ERROR;
}
\003	{
    cool_yylval.error_msg = "\003";
    return ERROR;
}
\004	{
    cool_yylval.error_msg = "\004";
    return ERROR;
}

 /*
  * Line number
  */
{NEWLINE}	{ ++curr_lineno; }

 /*
  * White Space, do nothing
  */
{WHITESPACE}	/* do nothing */
%%
