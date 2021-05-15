// ExReleasePushLockExclusiveEx 
 
int __fastcall ExReleasePushLockExclusiveEx(int result, int a2, int a3)
{
  char v3; // r4
  unsigned int v4; // r6
  unsigned int v5; // r1
  int v6; // r8
  int v7; // r4
  int v8; // r3
  int v9; // r9
  int v10; // r2
  int v11; // r5
  __int16 v12; // r3
  int v13; // r2
  __int16 v14; // r3
  int v15; // r1
  int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned __int8 *v19; // r2
  unsigned int v20; // r4

  v3 = a2;
  v4 = result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_50CB80(result, a2, a3, a2 & 0xFFFFFFFC);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)result);
  while ( __strex(v5 - 1, (unsigned int *)result) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    result = ExfTryToWakePushLock(result);
  if ( (v3 & 2) == 0 && KiAbEnabled && (v4 & 0x7FFFFFFC) != 0 )
  {
    v6 = 0;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v4 >= dword_63389C
      && ((v8 = *((unsigned __int8 *)&MiState[2423]
                + ((int)(((v4 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v8 == 1)
       || v8 == 11)
      && (v15 = *(_DWORD *)(v7 + 116), (v16 = *(_DWORD *)(v15 + 324)) != 0)
      && v15 != PsInitialSystemProcess )
    {
      v9 = *(_DWORD *)(v16 + 8);
    }
    else
    {
      v9 = -1;
    }
    if ( (unsigned int)KeGetCurrentIrql(result) <= 1 )
    {
      v6 = 1;
      --*(_WORD *)(v7 + 310);
    }
    result = KiAbThreadClearAcquiredLockEntry(v7, v4, v9);
    v11 = result;
    if ( result )
    {
      *(_BYTE *)(result + 16) |= 2u;
      if ( *(int *)(result + 16) < 0 )
        KiAbEntryRemoveFromTree(result);
      v12 = *(_WORD *)(v11 + 44);
      if ( v12 )
      {
        if ( (v12 & 1) != 0 )
        {
          __dmb(0xBu);
          v17 = (unsigned int *)(v7 + 804);
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 - 1, v17) );
          __dmb(0xBu);
          PsBoostThreadIoEx(v7, 1, 0);
        }
        if ( (*(_WORD *)(v11 + 44) & 0xFFFE) != 0 )
          KiAbThreadUnboostCpuPriority(v7, v11, v10, *(_WORD *)(v11 + 44) & 0xFFFE);
        if ( (dword_682604 & 0x200) != 0 )
          EtwTraceAutoBoostClearFloor(
            v7,
            *(_DWORD *)(v11 + 16) & 0xFFFFFFFC | 0x80000000,
            *(unsigned __int16 *)(v11 + 44));
        *(_WORD *)(v11 + 44) = 0;
      }
      *(_BYTE *)(v11 + 13) &= 0xFEu;
      result = (unsigned __int64)(715827883i64 * (v11 - v7 - 488)) >> 32;
      *(_DWORD *)(v11 + 16) = 0;
      v13 = (v11 - v7 - 488) / 48;
      if ( !v6 )
      {
        __dmb(0xBu);
        result = (char)(1 << v13);
        v19 = (unsigned __int8 *)(v7 + 810);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 | result, v19) );
        __dmb(0xBu);
        return result;
      }
      *(_BYTE *)(v7 + 484) |= 1 << v13;
      goto LABEL_21;
    }
    if ( (*(_DWORD *)(v7 + 80) & 0x8000) == 0 )
      KeBugCheckEx(354, v7, v4);
    if ( v6 )
    {
LABEL_21:
      v14 = *(_WORD *)(v7 + 310) + 1;
      *(_WORD *)(v7 + 310) = v14;
      if ( !v14 && *(_DWORD *)(v7 + 100) != v7 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      return result;
    }
  }
  return result;
}
