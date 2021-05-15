// MiProcessWsInSwapFault 
 
int __fastcall MiProcessWsInSwapFault(int result)
{
  int v1; // r2
  unsigned int v2; // r3
  unsigned int v3; // r4
  int v4; // r4
  unsigned __int8 *v5; // r1
  unsigned int v6; // r2
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r4

  v1 = 0;
  while ( 1 )
  {
    v2 = **(_DWORD **)(result + 4 * v1);
    if ( (v2 & 2) == 0 || !v1 && (v2 & 0x400) != 0 )
      break;
    if ( (unsigned int)++v1 >= 2 )
    {
      v3 = v2 >> 12;
      result = MI_IS_PFN(v2 >> 12);
      if ( result )
      {
        v4 = MmPfnDatabase + 24 * v3;
        v5 = (unsigned __int8 *)(v4 + 15);
        do
          v6 = __ldrex(v5);
        while ( __strex(v6 | 0x80, v5) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v6 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v7 = *(_DWORD *)(v4 + 12);
            __dmb(0xBu);
          }
          while ( v7 < 0 );
          do
            v6 = __ldrex(v5);
          while ( __strex(v6 | 0x80, v5) );
        }
        result = MiReleaseWsSwapReservationPfn(v4);
        __dmb(0xBu);
        v8 = (unsigned int *)(v4 + 12);
        do
          v9 = __ldrex(v8);
        while ( __strex(v9 & 0x7FFFFFFF, v8) );
        if ( result )
          result = MiReleasePageFileInfo((int)MiSystemPartition, result, 1, 0);
      }
      return result;
    }
  }
  return result;
}
