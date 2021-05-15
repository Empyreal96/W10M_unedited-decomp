// MiReduceWs 
 
unsigned int __fastcall MiReduceWs(unsigned int result, int a2, unsigned int a3)
{
  unsigned int v5; // r7
  int i; // r5
  unsigned int v7; // r4

  v5 = result;
  for ( i = 7; ; --i )
  {
    v7 = *(_DWORD *)(v5 + 60);
    if ( v7 <= a3 )
      break;
    if ( i )
    {
      result = *(_DWORD *)(v5 + 4 * i + 16);
      if ( result > v7 - a3 )
        result = v7 - a3;
    }
    else
    {
      result = v7 - a3;
    }
    if ( result )
    {
      result = MiTrimWorkingSet(result, v5, a2, i, 0);
      if ( !i )
        break;
    }
  }
  return result;
}
