// PfpScenCtxPrefetchAbortSet 
 
int __fastcall PfpScenCtxPrefetchAbortSet(unsigned int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v8; // r5
  int v9; // r0
  int v10; // r7
  unsigned int v11; // r5
  int v12; // r4
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  if ( !a5 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = KeAbPreAcquire(a1, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v11 | 1, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v9, a1);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
  }
  if ( *(_DWORD *)(a1 + 28) != a2 )
  {
    v12 = -1073741735;
    goto LABEL_16;
  }
  if ( a4 )
  {
    *(_DWORD *)(a1 + 24) = 0;
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 4) & 0xC) == 8 )
    {
      v12 = -1073741431;
      goto LABEL_16;
    }
    *(_DWORD *)(a1 + 24) = a3;
  }
  v12 = 0;
LABEL_16:
  if ( !a5 )
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)a1);
    while ( __strex(v13 - 1, (unsigned int *)a1) );
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)a1);
    v14 = KeAbPostRelease(a1);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
  }
  return v12;
}
