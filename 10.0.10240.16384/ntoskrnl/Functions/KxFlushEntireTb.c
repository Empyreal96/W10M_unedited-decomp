// KxFlushEntireTb 
 
int KxFlushEntireTb()
{
  int v0; // r7
  int v1; // r3
  int v2; // r1
  unsigned int v3; // r2
  unsigned int v5; // r2

  v0 = KfRaiseIrql(12);
  __pld(&KiTbFlushTimeStamp);
  LOBYTE(v1) = KiTbFlushTimeStamp;
  v2 = KiTbFlushTimeStamp;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      __dmb(0xBu);
      do
        v3 = __ldrex((unsigned __int8 *)&KiTbFlushTimeStamp);
      while ( __strex(v3 | 1, (unsigned __int8 *)&KiTbFlushTimeStamp) );
      __dmb(0xBu);
      if ( (v3 & 1) == 0 )
        break;
    }
    __dmb(0xAu);
    __yield();
    v1 = KiTbFlushTimeStamp;
    __dmb(0xBu);
    if ( v1 - v2 >= 3 || v1 - v2 >= 2 && (v2 & 1) == 0 )
      return KfLowerIrql(v0);
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 3, 0);
  __dsb(0xFu);
  __isb(0xFu);
  if ( KiTbSendIpiForBroadcastFlushes )
    return sub_50DC10(1, v2);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&KiTbFlushTimeStamp);
  while ( __strex(v5 + 1, (unsigned int *)&KiTbFlushTimeStamp) );
  __dmb(0xBu);
  return KfLowerIrql(v0);
}
