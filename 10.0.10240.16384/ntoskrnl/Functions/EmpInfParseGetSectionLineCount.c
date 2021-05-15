// EmpInfParseGetSectionLineCount 
 
int __fastcall EmpInfParseGetSectionLineCount(int a1, int a2)
{
  int i; // r4
  int v5; // r0

  for ( i = 0; ; ++i )
  {
    v5 = CmpSearchSectionByName(a1, a2);
    if ( !v5 || !CmpSearchLineInSectionByIndex(v5, i) )
      break;
  }
  return i;
}
