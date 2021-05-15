// DrvDbValidateDriverInfFileName 
 
int __fastcall DrvDbValidateDriverInfFileName(int a1, _WORD *a2)
{
  int v3; // r4
  _WORD *v4; // r0
  _WORD *v5; // r0

  v3 = 0;
  if ( *a2 != 64 || (v4 = wcschr(a2 + 1, 58)) == 0 || (v5 = v4 + 1) == 0 )
    v5 = a2;
  if ( wcschr(v5, 92) )
    v3 = -1073741773;
  return v3;
}
