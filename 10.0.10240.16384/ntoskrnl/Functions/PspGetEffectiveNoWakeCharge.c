// PspGetEffectiveNoWakeCharge 
 
int __fastcall PspGetEffectiveNoWakeCharge(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int result; // r0
  unsigned int *v5; // r2
  unsigned int *v6; // r2

  result = a1[186];
  *a2 = 0;
  a2[1] = 0;
  *a3 = 0;
  a3[1] = 0;
  if ( (result & 0x800) != 0 )
  {
    if ( a1[102] )
    {
      *a2 = a1[120];
      a2[1] = a1[121];
      if ( (result & 0x400000) == 0 )
      {
        result = a1[143];
        if ( !result || (*(_DWORD *)(result + 744) & 0x1000) == 0 || !*(_DWORD *)(result + 408) )
        {
          *a3 = *a2;
          a3[1] = a2[1];
          if ( result )
          {
            __dmb(0xBu);
            v5 = (unsigned int *)(result + 744);
            do
              result = __ldrex(v5);
            while ( __strex(result | 0x400000, v5) );
            __dmb(0xBu);
          }
        }
      }
    }
  }
  if ( (a1[186] & 0x400000) != 0 )
  {
    if ( a1[143] )
    {
      result = sub_7C2CE8();
    }
    else
    {
      __dmb(0xBu);
      v6 = a1 + 186;
      do
        result = __ldrex(v6);
      while ( __strex(result & 0xFFBFFFFF, v6) );
      __dmb(0xBu);
    }
  }
  return result;
}
