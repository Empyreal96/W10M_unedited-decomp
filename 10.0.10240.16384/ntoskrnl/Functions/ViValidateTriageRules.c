// ViValidateTriageRules 
 
int __fastcall ViValidateTriageRules(unsigned int *a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r2
  const char *v5; // r2

  v4 = (unsigned int)a1 + a2;
  do
  {
    if ( (unsigned int)a1 >= v4 )
    {
      v5 = "CRASH TRIAGE: rules are ok.\n";
LABEL_6:
      DbgPrintEx(93, 3, (int)v5, a4);
      return 1;
    }
    a4 = *a1;
    if ( (*a1 & 0x70000) == 0 )
    {
      v5 = "CRASH TRIAGE: found zeroed rule during validation.\n";
      goto LABEL_6;
    }
    a4 = (unsigned int)a1 + (a4 >> 19);
    a1 = (unsigned int *)(a4 + 8);
  }
  while ( a4 + 8 <= v4 );
  DbgPrintEx(93, 3, (int)"CRASH TRIAGE: invalid rules structure! \n", a4);
  return 0;
}
