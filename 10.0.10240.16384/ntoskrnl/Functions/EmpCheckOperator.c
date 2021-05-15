// EmpCheckOperator 
 
int __fastcall EmpCheckOperator(int a1, unsigned int a2, unsigned int a3)
{
  int v6; // r4

  v6 = 0;
  if ( !strcmp(a1, (unsigned int *)"=") || !strcmp(a1, (unsigned int *)"==") )
  {
    if ( a2 == a3 )
      return 1;
    goto LABEL_25;
  }
  if ( !strcmp(a1, (unsigned int *)"!=") || !strcmp(a1, (unsigned int *)"<>") || !strcmp(a1, (unsigned int *)"=!") )
  {
    if ( a2 != a3 )
      return 1;
    goto LABEL_25;
  }
  if ( !strcmp(a1, (unsigned int *)"<") )
    return sub_81B5C0();
  if ( !strcmp(a1, (unsigned int *)"<=") || !strcmp(a1, (unsigned int *)"=<") )
  {
    if ( a2 <= a3 )
      return 1;
    goto LABEL_25;
  }
  if ( !strcmp(a1, (unsigned int *)">") )
    JUMPOUT(0x81B5C8);
  if ( !strcmp(a1, (unsigned int *)">=") || !strcmp(a1, (unsigned int *)"=>") )
  {
    if ( a2 >= a3 )
      return 1;
LABEL_25:
    JUMPOUT(0x81B5CE);
  }
  if ( !strcmp(a1, (unsigned int *)"*") )
    return 1;
  return v6;
}
