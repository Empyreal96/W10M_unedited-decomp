// EmpInfParseGetValueFromSectionAndKeyName 
 
int __fastcall EmpInfParseGetValueFromSectionAndKeyName(int a1, int a2, unsigned __int8 *a3, int a4, int *a5)
{
  int v5; // r6
  int i; // r4
  int v10; // r0
  int v11; // r0
  unsigned __int8 *v12; // r5
  char *v13; // r0

  v5 = 0;
  for ( i = 0; ; ++i )
  {
    v10 = CmpSearchSectionByName(a1, a2);
    if ( v10 && (v11 = CmpSearchLineInSectionByIndex(v10, i)) != 0 )
      v12 = *(unsigned __int8 **)(v11 + 4);
    else
      v12 = 0;
    if ( v12 )
    {
      v13 = strlen((unsigned int)a3);
      if ( !strnicmp(v12, a3, (int)v13) )
        break;
    }
    if ( !v12 )
      return v5;
  }
  v5 = CmpGetSectionLineIndex(a1, a2, i, 0);
  if ( a5 )
    *a5 = i;
  return v5;
}
