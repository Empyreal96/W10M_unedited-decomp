// SepDereferenceLowBoxNumberEntry 
 
int __fastcall SepDereferenceLowBoxNumberEntry(unsigned int a1, _DWORD *a2)
{
  int v2; // r7
  int *v4; // r4
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r1
  signed int v11; // r1
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3

  v2 = 0;
  if ( a1 >= 5 )
    return sub_7BFFC0(a1);
  v4 = &g_SessionLowboxArray[5 * a1];
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)v4, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)v4);
  while ( __strex(v8 | 1, (unsigned __int8 *)v4) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v4, v6, (unsigned int)v4);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  __dmb(0xBu);
  v9 = a2 + 3;
  do
  {
    v10 = __ldrex(v9);
    v11 = v10 - 1;
  }
  while ( __strex(v11, v9) );
  if ( v11 <= 0 )
  {
    if ( v11 )
      __fastfail(0xEu);
    __dmb(0xBu);
    if ( RtlRemoveEntryHashTable(v4[3], a2, 0) )
    {
      *(_BYTE *)(((unsigned int)(a2[5] - 1) >> 3) + v4[2]) &= ~(1 << ((*((_BYTE *)a2 + 20) - 1) & 7));
      if ( a2[6] )
      {
        ExRemoveLowBoxAtomReferences();
        RtlDereferenceAtomTable();
      }
      ExFreePoolWithTag((unsigned int)a2);
    }
    else
    {
      v2 = -1073741823;
    }
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v4);
    while ( __strex(v17 - 1, (unsigned int *)v4) );
    if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v4);
    v18 = KeAbPostRelease((unsigned int)v4);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
  }
  else
  {
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v4);
    while ( __strex(v12 - 1, (unsigned int *)v4) );
    if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v4);
    v13 = KeAbPostRelease((unsigned int)v4);
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = *(_WORD *)(v14 + 0x134) + 1;
    *(_WORD *)(v14 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v13);
    v2 = 0;
  }
  return v2;
}
