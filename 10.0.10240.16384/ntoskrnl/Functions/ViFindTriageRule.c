// ViFindTriageRule 
 
unsigned int *__fastcall ViFindTriageRule(unsigned int *a1, int a2, int a3)
{
  unsigned int *v3; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1
  int v7; // r3

  v3 = a1;
  v5 = (unsigned int)a1 + a2;
  while ( 1 )
  {
    if ( (unsigned int)v3 >= v5 )
    {
      DbgPrintEx(93, 3, (int)"CRASH TRIAGE: no rule found for crash code %X.\n", a3);
      return 0;
    }
    v6 = *v3;
    v7 = HIWORD(*v3) & 7;
    if ( !v7 )
    {
      DbgPrintEx(93, 3, (int)"CRASH TRIAGE: zeroed rules structure (hit an invalid type rule).\n", 0);
      return 0;
    }
    if ( v7 == 1 )
      break;
    if ( v7 == 2 )
LABEL_7:
      v3 = (unsigned int *)((char *)v3 + (v6 >> 19) + 8);
  }
  if ( (unsigned __int16)v6 != (unsigned __int16)a3 )
    goto LABEL_7;
  DbgPrintEx(93, 3, (int)"CRASH TRIAGE: rule was found for crash code %X.\n", a3);
  return v3;
}
