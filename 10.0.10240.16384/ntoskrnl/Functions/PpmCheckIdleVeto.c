// PpmCheckIdleVeto 
 
unsigned int __fastcall PpmCheckIdleVeto(_DWORD *a1)
{
  _DWORD *v2; // r2

  if ( !*a1 )
    return 0;
  if ( a1[4] )
  {
    v2 = (_DWORD *)a1[1];
    if ( v2 != a1 + 1 )
      return v2[2];
  }
  return 0x80000000;
}
