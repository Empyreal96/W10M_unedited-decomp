// ExpReleaseFannedOutPushLockExclusive 
 
unsigned int *__fastcall ExpReleaseFannedOutPushLockExclusive(unsigned int a1, int a2)
{
  unsigned int *result; // r0
  unsigned int *v4; // r6
  unsigned int v5; // r4
  int v6; // r7
  unsigned int v7; // r8
  int v8; // r5
  unsigned int v9; // r1

  result = (unsigned int *)KeQueryMaximumProcessorCountEx(0xFFFFu, a2);
  v4 = result;
  v5 = 0;
  if ( result )
  {
    v6 = (a1 >> 13) & 0x3FFFF;
    v7 = __clz(v6);
    v8 = (a1 >> 3) & 0x3FF;
    do
    {
      result = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ExSaPageArrays + 4 * v5) + 4 * (29 - v7))
                                          + 4 * ((1 << (31 - v7)) ^ v6)
                                          + 4)
                              + 4 * v8);
      __dmb(0xBu);
      do
        v9 = __ldrex(result);
      while ( __strex(v9 - 1, result) );
      if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
        result = ExfTryToWakePushLock(result);
      ++v5;
    }
    while ( v5 < (unsigned int)v4 );
  }
  return result;
}
