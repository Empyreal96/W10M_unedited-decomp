// ExSweepHandleTable 
 
int __fastcall ExSweepHandleTable(int a1)
{
  int v2; // r5
  unsigned int v3; // r7
  int v4; // r10
  int v5; // r6
  int *v6; // r4
  int v7; // r0
  int result; // r0
  unsigned int v9; // r1
  BOOL v10; // r2
  unsigned __int8 *v11; // r5
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r2
  __int16 v16; // r3

  v2 = 4;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v5 = 0;
  --*(_WORD *)(v3 + 308);
LABEL_2:
  v6 = (int *)ExpLookupHandleTableEntry(a1, v2);
  if ( v6 )
  {
    while ( 1 )
    {
      __pld(v6);
      v7 = *v6;
      if ( (*v6 & 1) == 0 )
        break;
      do
        v9 = __ldrex((unsigned int *)v6);
      while ( v9 == v7 && __strex(v7 - 1, (unsigned int *)v6) );
      __dmb(0xBu);
      if ( v9 == v7 )
      {
        v10 = ObCloseHandleTableEntry(a1, v6, v4, v2) >= 0;
        --*(_WORD *)(v3 + 308);
        if ( v10 )
          ++v5;
LABEL_6:
        v2 += 4;
        v6 += 2;
        if ( (v2 & 0x7FF) == 0 )
        {
          v2 += 4;
          goto LABEL_2;
        }
      }
    }
    if ( v7 )
      return sub_7DDA34();
    goto LABEL_6;
  }
  v11 = (unsigned __int8 *)(a1 + 40);
  v12 = KeAbPreAcquire(a1 + 40, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v11);
  while ( __strex(v14 | 1, v11) );
  __dmb(0xBu);
  if ( (v14 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 40), v12, a1 + 40);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  *(_DWORD *)(a1 + 52) -= v5;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v11);
  while ( __strex(v15 - 1, (unsigned int *)v11) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 40));
  result = KeAbPostRelease(a1 + 40);
  *(_BYTE *)(a1 + 28) |= 4u;
  v16 = *(_WORD *)(v3 + 308) + 1;
  *(_WORD *)(v3 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
