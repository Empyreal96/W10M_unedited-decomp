// PopSpoilBatteryEstimate 
 
int __fastcall PopSpoilBatteryEstimate(int result, int a2)
{
  int v3; // r0
  unsigned int v4; // r5
  const char *v5; // r3
  unsigned int v6; // r1

  if ( result < 2 )
  {
    v3 = (unsigned __int8)(1 << result);
    __dmb(0xBu);
    if ( a2 )
    {
      do
        v6 = __ldrex((unsigned int *)&PopEstimateSpoilerMask);
      while ( __strex(v6 | v3, (unsigned int *)&PopEstimateSpoilerMask) );
    }
    else
    {
      do
        v4 = __ldrex((unsigned int *)&PopEstimateSpoilerMask);
      while ( __strex(v4 & ~v3, (unsigned int *)&PopEstimateSpoilerMask) );
    }
    __dmb(0xBu);
    PopBatteryQueueWork(4);
    if ( a2 )
      v5 = "indefinitely";
    else
      v5 = "temporarily";
    __dmb(0xBu);
    result = DbgPrintEx(146, 3, (int)"Battery estimates spoiled %s by %d; mask=%x\n", (int)v5);
  }
  return result;
}
