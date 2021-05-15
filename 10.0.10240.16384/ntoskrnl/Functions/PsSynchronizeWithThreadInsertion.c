// PsSynchronizeWithThreadInsertion 
 
unsigned int *__fastcall PsSynchronizeWithThreadInsertion(unsigned int *result, int a2)
{
  unsigned int *v3; // r6
  unsigned int v4; // r3
  int v5; // r5
  __int16 v6; // r3

  v3 = result;
  --*(_WORD *)(a2 + 308);
  __dmb(0xFu);
  v4 = result[236];
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
  {
    v5 = KeAbPreAcquire((unsigned int)(result + 236), 0, 0);
    ExfAcquirePushLockExclusiveEx(v3 + 236, v5, (unsigned int)(v3 + 236));
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    result = ExfReleasePushLockExclusive(v3 + 236);
    if ( v5 )
      result = (unsigned int *)KeAbPostRelease((unsigned int)(v3 + 236));
  }
  v6 = *(_WORD *)(a2 + 308) + 1;
  *(_WORD *)(a2 + 308) = v6;
  if ( !v6 && *(_DWORD *)(a2 + 100) != a2 + 100 && !*(_WORD *)(a2 + 310) )
    result = (unsigned int *)KiCheckForKernelApcDelivery((int)result);
  return result;
}
