/*
*  cool.y
*              Parser definition for the COOL language.
*
*/
%{
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
    %}
    
    /* A union of all the types that can be the result of parsing actions. */
    %union {
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
    }
    
    /* 
    Declare the terminals; a few have types for associated lexemes.
    The token ERROR is never used in the parser; thus, it is a parse
    error when the lexer returns it.
    
    The integer following token declaration is the numeric constant used
    to represent that token internally.  Typically, Bison generates these
    on its own, but we give explicit numbers to prevent version parity
    problems (bison 1.25 and earlier start at 258, later versions -- at
    257)
    */
    %token CLASS 258 ELSE 259 FI 260 IF 261 IN 262 
    %token INHERITS 263 LET 264 LOOP 265 POOL 266 THEN 267 WHILE 268
    %token CASE 269 ESAC 270 OF 271 DARROW 272 NEW 273 ISVOID 274
    %token <symbol>  STR_CONST 275 INT_CONST 276 
    %token <boolean> BOOL_CONST 277
    %token <symbol>  TYPEID 278 OBJECTID 279 
    %token ASSIGN 280 NOT 281 LE 282 ERROR 283
    
    /*  DON'T CHANGE ANYTHING ABOVE THIS LINE, OR YOUR PARSER WONT WORK       */
    /**************************************************************************/
    
    /* Complete the nonterminal list below, giving a type for the semantic
    value of each non terminal. (See section 3.6 in the bison 
    documentation for details). */
    
    /* Declare types for the grammar's non-terminals. */
    %type <program> program
    %type <classes> class_list
    %type <class_> class
    
    /* You will want to change the following line. */
    %type <features> feature_list
    %type <feature> feature
    %type <formals> formal_list
    %type <formal> formal
    %type <expression> expr
    %type <expressions> comma_expr_list
    %type <expressions> expr_semi_list
    %type <cases> expr_case_list
    %type <expression> expr_let_part_1
    %type <expression> expr_let_part_2

    /* Precedence declarations go here. */
    /* the bottom, the precedence is higher*/
    %nonassoc     IN
    %right        ASSIGN "<-"
    %left         NOT
    %nonassoc     "<=" '<' '='
    %left         '+' '-'
    %left         '*' '/'
    %left         ISVOID
    %left         '~'
    %left         '@'
    %left         '.'
    
    %%
    /* 
    Save the root of the abstract syntax tree in a global variable.
    */
    program	: class_list
    {
      @$ = @1;
      SET_NODELOC(@1)
      ast_root = program($1);
    }
    ;
    
    class_list
    : class ';'			/* single class */
    { 
      @$ = @1;
      SET_NODELOC(@1);
      $$ = single_Classes($1);
      parse_results = $$; 
    }
    | class_list class ';'	/* several classes */
    { 
      @$ = @2;
      SET_NODELOC(@2);
      $$ = append_Classes($1,single_Classes($2)); 
      parse_results = $$; 
    }
    ;
    
    /* If no parent is specified, the class inherits from the Object class. */
    class	: CLASS TYPEID '{' feature_list '}' 
    {   
      @$ = @4;
      SET_NODELOC(@4);
      $$ = class_($2,idtable.add_string("Object"),$4,
		  stringtable.add_string(curr_filename));
    }
    | CLASS TYPEID INHERITS TYPEID '{' feature_list '}'
    {  
      @$ = @6;
      SET_NODELOC(@6);
      $$ = class_($2,$4,$6,stringtable.add_string(curr_filename)); 
    }
    | error 
    {}
    ;
    
    /* Feature list may be empty, but no empty features in list. */
    feature_list:		/* empty */
    {   
      $$ = nil_Features(); 
    }
    | feature ';'                 /* single feature */
    {
      @$ = @1;
      SET_NODELOC(@1);
      $$ = single_Features($1);
    }
    | feature_list feature ';'   /* mutil features */
    {     
      @$ = @2;
      SET_NODELOC(@2);
      $$ = append_Features($1, single_Features($2));
    }
    ;

    /* feature grammar, two kinds of features, one is method, the
     * other is attr
     */
    feature     : OBJECTID '(' formal_list ')' ':' TYPEID '{' expr '}'
    { 
      @$ = @8;
      SET_NODELOC(@8);
      $$ = method($1, $3, $6, $8);
    }
    | OBJECTID ':' TYPEID
    {  
      @$ = @3;
      SET_NODELOC(@3);
      // init is null, so to create a null expression
      $$ = attr($1, $3, no_expr());
    }
    | OBJECTID ':' TYPEID ASSIGN expr
    {   
      @$ = @5;
      SET_NODELOC(@5);
      // create ASSIGN node
      Expression assign_node = assign($1, $5);
      $$ = attr($1, $3, assign_node);
    }
    | error
    {}
    ;

    /* formal list grammar */
    /* [formal[, formal]*] , need to return Formals*/
    formal_list :      /* empty */
    { 
      $$ = nil_Formals();
    }
    | formal
    {
      @$ = @1;
      SET_NODELOC(@1)
      $$ = single_Formals($1);    
    }
    | formal_list ',' formal
    {  
      @$ = @3;
      SET_NODELOC(@3);
      $$ = append_Formals($1, single_Formals($3));  
    }
    ;

    /* formal grammar */
    formal      : OBJECTID ':' TYPEID
    { 
      @$ = @3;
      SET_NODELOC(@3);
      $$ = formal($1, $3);
    }
    ;

    /* comma expr list grammar */
    /* [expr[,expr]*] should return Expresstions */
    comma_expr_list   : /* empty*/
    {
      $$ = nil_Expressions();
    }
    | expr
    {  
      @$ = @1;
      SET_NODELOC(@1);
      $$ = single_Expressions($1);
    }
    | comma_expr_list ',' expr
    {
      @$ = @3;
      SET_NODELOC(@3);
      $$ = append_Expressions($1, single_Expressions($3));
    }
    ;

    expr_semi_list    : expr ';'
    { 
      @$ = @1;
      SET_NODELOC(@1);
      // Expressions single_Expression(Expression e)
      $$ = single_Expressions($1);
    }
    | expr_semi_list  expr ';'
    { 
      @$ = @2;
      SET_NODELOC(@2);
      $$ = append_Expressions($1, single_Expressions($2));
    } 
    | error ';'
    { }
    ;

    expr_let_part_1 : LET expr_let_part_2
    { 
      @$ = @2;
      SET_NODELOC(@2);
      $$ = $2;
    }
    ;  

    expr_let_part_2 : OBJECTID ':' TYPEID IN expr
    { 
      @$ = @5;
      SET_NODELOC(@5);
      $$ = let($1, $3, no_expr(), $5);
    }
    | OBJECTID ':' TYPEID ASSIGN expr IN expr
    { 
      @$ = @7;
      SET_NODELOC(@7);
      $$ = let($1, $3, $5, $7);
    }
    | OBJECTID ':' TYPEID ',' expr_let_part_2
    {  
      @$ = @5;
      SET_NODELOC(@5);
      $$ = let($1, $3, no_expr(), $5);
    }
    | OBJECTID ':' TYPEID ASSIGN expr ',' expr_let_part_2
    {
      @$ = @7;
      SET_NODELOC(@7);
      $$ = let($1, $3, $5, $7);
    }
    | error IN  expr
    {}
    | error ',' expr_let_part_2
    {}
    ;

    expr_case_list    : OBJECTID ':' TYPEID DARROW  expr ';' 
    {//ID:TYPE=>expr;
      @$ = @5;
      SET_NODELOC(@5);
      // Cases single_Cases(Case e)
      // Case branch(Symbol name, Symbol type_decl, Expression expr)
      $$ = single_Cases(branch($1, $3, $5));
    }
    | expr_case_list OBJECTID ':' TYPEID DARROW  expr ';' 
    { //ID:TYPE=>expr;ID:TYPE=>expr;......ID:TYPE=>expr;
      @$ = @6;
      SET_NODELOC(@6);
      $$ = append_Cases($1, single_Cases(branch($2, $4, $6)));
    }
    ;

    /* expr grammar */
    expr        : OBJECTID ASSIGN expr
    { 
      @$ = @3;
      SET_NODELOC(@3);
      $$ = assign($1, $3);
    }
    | expr '.' OBJECTID '(' comma_expr_list ')'
    {  
      // dispatch
      @$ = @5;
      SET_NODELOC(@5);
      $$ = dispatch($1, $3, $5);
    }
    | expr '@' TYPEID '.' OBJECTID '(' comma_expr_list ')' 
    {   
      // static dispatch, used to access methods in parent class
      @$ = @7;
      SET_NODELOC(@7);
	  $$ = static_dispatch($1, $3, $5, $7);
    }
    | OBJECTID '(' comma_expr_list ')'
    { // self dispatch
      // self.id(), so need to create a 'self' expression
      @$ = @3;
      SET_NODELOC(@3);
      $$ = dispatch(object(idtable.add_string("self")), $1, $3);
    }
    | IF expr THEN expr ELSE expr FI
    { // if...else.... grammar
      @$ = @7;
      SET_NODELOC(@7);
      $$ = cond($2, $4, $6);
    }
    | WHILE expr LOOP expr POOL
    { // while grammar
      @$ = @5;
      SET_NODELOC(@5);
      $$ = loop($2, $4);
    }
    | '{' expr_semi_list '}'
    { // block grammar
      // block(Expressions): Expression
      @$ = @2;
      SET_NODELOC(@2);
      $$ = block($2);
    }
    | expr_let_part_1 
    {
      // let grammar is a recursive grammar--TODO
      // it is hard, wait to solve
      // ***********************************
      @$ = @1;
      SET_NODELOC(@1);
      $$ = $1;
    }
    | CASE expr OF expr_case_list ESAC
    { 
      // case grammar
      // typcase(expression, cases)
      @$ = @5;
      SET_NODELOC(@5);
      $$ = typcase($2, $4);
    }
    | NEW TYPEID
    { 
        @$ = @2;
        SET_NODELOC(@2);
        $$ = new_($2);
    }
    | ISVOID expr
    {   
        @$ = @2;
        SET_NODELOC(@2);
        $$ = isvoid($2);
    }
    | expr '+' expr
    {    
        @$ = @3;
        SET_NODELOC(@3);
        $$ = plus($1, $3);
    }
    | expr '-' expr
    {    
        @$ = @3;
        SET_NODELOC(@3);
        $$ = sub($1, $3);
    }
    | expr '*' expr
    {   
        @$ = @3;
        SET_NODELOC(@3);
        $$ = mul($1, $3);
    }
    | expr '/' expr
    {    
        @$ = @3;
        SET_NODELOC(@3);
        $$ = divide($1, $3);
    }
    | '~' expr
    {    
        @$ = @2;
        SET_NODELOC(@2);
        $$ = neg($2);
    }
    | expr '<' expr
    {    
        @$ = @3;
        SET_NODELOC(@3);
        $$ = lt($1, $3);
    }
    | expr "<=" expr
    {    
        @$ = @3;
        SET_NODELOC(@3);
        $$ = leq($1, $3);
    }
    | expr '=' expr
    {   
        @$ = @3;
        SET_NODELOC(@3); 
        $$ = eq($1, $3);
    }
    | NOT expr
    { 
        @$ = @2;
        $$ = comp($2);
    }
    | '(' expr ')'
    {    
      @$ = @2;
      SET_NODELOC(@2);
      $$ = $2;        
    }
    | OBJECTID
    { 
      @$ = @1;
	  SET_NODELOC(@1);
      $$ = object($1);
    }
    | INT_CONST
    {   
      @$ = @1;
      SET_NODELOC(@1);
      $$ = int_const($1);
    }
    | STR_CONST
    {  
      @$ = @1;
	  SET_NODELOC(@1);
      $$ = string_const($1);
    }
    | BOOL_CONST
    {   
      @$ = @1;
      SET_NODELOC(@1);
	  $$ = bool_const($1);
    }
    ;
    
    
    /* end of grammar */
    %%
    
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
    
    
