// PopPepTryPowerDownComponent 
 
int __fastcall PopPepTryPowerDownComponent(int result, _DWORD *a2)
{
  int v2; // r2
  _DWORD *i; // r4
  unsigned int *v4; // r2
  unsigned int v5; // r1

  v2 = 1;
  for ( i = a2 + 1; !*(_DWORD *)i[12]; ++i )
  {
    if ( (unsigned int)++v2 > 3 )
    {
      if ( a2[36] == a2[39] - 1 )
      {
        a2[1] &= 0xFFFFFFFD;
        __dmb(0xBu);
        v4 = (unsigned int *)(result + 92);
        do
          v5 = __ldrex(v4);
        while ( __strex(v5 - 1, v4) );
        __dmb(0xBu);
      }
      return result;
    }
  }
  return result;
}
