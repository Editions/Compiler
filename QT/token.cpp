#include"globals.h"
#include"bison.tab.h"
extern FILE* tokenlisting;
extern char id[10];
extern int value;
extern int lineno;

void printToken(int type)
{
    fprintf(tokenlisting, "line %d:", lineno);
    switch(type)
    {
    case ELSE:
        fprintf(tokenlisting, "  else    Reserved word\n");
        break;
    case IF:
        fprintf(tokenlisting, "  if      Reserved word\n");
        break;
    case RETURN:
        fprintf(tokenlisting, "  return  Reserved word\n");
        break;
    case WHILE:
        fprintf(tokenlisting, "  while   Reserved word\n");
        break;
    case VOID:
        fprintf(tokenlisting, "  void    Reserved word\n");
        break;
    case INT:
        fprintf(tokenlisting, "  int     Reserved word\n");
        break;
    case ASSIGN:
        fprintf(tokenlisting, "  =\n");
        break;
    case SEMI:
        fprintf(tokenlisting, "  ;\n");
        break;
    case COMMA:
        fprintf(tokenlisting, "  ,\n");
        break;
    case LBRACE:
        fprintf(tokenlisting, "  {\n");
        break;
    case RBRACE:
        fprintf(tokenlisting, "  }\n");
        break;
    case LBRACKET:
        fprintf(tokenlisting, "  [\n");
        break;
    case RBRACKET:
        fprintf(tokenlisting, "  ]\n");
        break;
    case ID:
        fprintf(tokenlisting, "  %s       ID\n", id);
        break;
    case NUM:
        fprintf(tokenlisting, "  %d       NUM\n", value);
        break;
    case LESS:
        fprintf(tokenlisting, "  <\n");
        break;
    case LESSEQUAL:
        fprintf(tokenlisting, "  <=\n");
        break;
    case MORE:
        fprintf(tokenlisting, "  >\n");
        break;
    case MOREEQUAL:
        fprintf(tokenlisting, "  >=\n");
        break;
    case EQUAL:
        fprintf(tokenlisting, "  ==\n");
        break;
    case NOTEQUAL:
        fprintf(tokenlisting, "  !=\n");
        break;
    case MINUS:
        fprintf(tokenlisting, "  -\n");
        break;
    case PLUS:
        fprintf(tokenlisting, "  +\n");
        break;
    case MULTI:
        fprintf(tokenlisting, "  *\n");
        break;
    case RPAREN:
        fprintf(tokenlisting, "  )\n");
        break;
    case LPAREN:
        fprintf(tokenlisting, "  (\n");
        break;
    case DIVIDE:
        fprintf(tokenlisting, "  /\n");
        break;
    case 0:
        fprintf(tokenlisting, "END OF FILE\n");
        break;
    default:
        fprintf(tokenlisting, "error %d\n", type);
    }
}
