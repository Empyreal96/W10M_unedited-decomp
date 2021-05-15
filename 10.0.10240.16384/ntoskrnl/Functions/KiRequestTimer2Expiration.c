// KiRequestTimer2Expiration 
 
int KiRequestTimer2Expiration()
{
  int v0; // r5
  int v1; // r4
  unsigned __int16 *v2; // r2
  int result; // r0
  int v4; // r3
  unsigned int *v5; // r2
  unsigned int v6; // r4
  unsigned int v7; // r3

  v0 = KiClockTimerOwner;
  v1 = (int)*(&KiProcessorBlock + KiClockTimerOwner);
  __dmb(0xBu);
  v2 = (unsigned __int16 *)(v1 + 1756);
  do
    result = __ldrex(v2);
  while ( __strex(result | 8, v2) );
  __dmb(0xBu);
  if ( (result & 0x29) == 0 )
  {
    if ( ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 == v1 )
    {
      result = HalRequestSoftwareInterrupt(2);
    }
    else
    {
      v4 = (int)*(&KiProcessorBlock + v0);
      __dmb(0xBu);
      v5 = (unsigned int *)(v4 + 1676);
      do
        v6 = __ldrex(v5);
      while ( __strex(v6 | 2, v5) );
      __dmb(0xBu);
      v7 = (unsigned int)KeGetPcr();
      ++*(_DWORD *)((v7 & 0xFFFFF000) + 0x1414);
      result = HalSendSoftwareInterrupt(v0, 2);
    }
  }
  return result;
}
