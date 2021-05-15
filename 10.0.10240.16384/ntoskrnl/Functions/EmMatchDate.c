// EmMatchDate 
 
int __fastcall EmMatchDate(int a1, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  int v6; // r4

  v6 = 1;
  if ( !a3 )
    return 1;
  if ( a4 == 1 && *a3 && a6 == 3 && (EmpCachedBiosDate || *(_BYTE *)*a3 == 42) )
  {
    if ( EmpCheckOperator() )
      v6 = 2;
  }
  return v6;
}
