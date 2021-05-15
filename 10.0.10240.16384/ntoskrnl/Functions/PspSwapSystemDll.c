// PspSwapSystemDll 
 
unsigned int *__fastcall PspSwapSystemDll(unsigned int *a1)
{
  unsigned int v2; // r4
  unsigned int *result; // r0
  int v4; // r7
  unsigned int v5; // r3
  int v6; // r6
  __int16 v7; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = (unsigned int *)ObFastReplaceObject(a1, 0);
  v4 = (int)result;
  if ( result )
  {
    --*(_WORD *)(v2 + 308);
    __dmb(0xFu);
    v5 = a1[1];
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
    {
      v6 = KeAbPreAcquire((unsigned int)(a1 + 1), 0, 0);
      ExfAcquirePushLockExclusiveEx(a1 + 1, v6, (unsigned int)(a1 + 1));
      if ( v6 )
        *(_BYTE *)(v6 + 14) |= 1u;
      result = ExfReleasePushLockExclusive(a1 + 1);
      if ( v6 )
        result = (unsigned int *)KeAbPostRelease((unsigned int)(a1 + 1));
    }
    v7 = *(_WORD *)(v2 + 308) + 1;
    *(_WORD *)(v2 + 308) = v7;
    if ( !v7 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
      KiCheckForKernelApcDelivery((int)result);
    result = (unsigned int *)ObfDereferenceObject(v4);
  }
  return result;
}
