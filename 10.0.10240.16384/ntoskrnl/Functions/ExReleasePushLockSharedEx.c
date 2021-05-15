// ExReleasePushLockSharedEx 
 
int __fastcall ExReleasePushLockSharedEx(int result, int a2, int a3)
{
  char v3; // r4
  unsigned int v4; // r5
  unsigned int v5; // r2
  int v6; // r7
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r8
  int v10; // r6
  int v11; // r2
  __int16 v12; // r3
  int v13; // r6
  unsigned __int8 *v14; // r2
  unsigned int v15; // r4

  v3 = a2;
  v4 = result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_50CC1C(result, a2, a3, a2 & 0xFFFFFFFC);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)result);
  while ( v5 == 17 && __strex(0, (unsigned int *)result) );
  if ( v5 != 17 )
    result = ExfReleasePushLockShared(result, 0);
  if ( (v3 & 2) == 0 && KiAbEnabled && (v4 & 0x7FFFFFFC) != 0 )
  {
    v6 = 0;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v4 >= dword_63389C
      && ((v8 = *((unsigned __int8 *)&MiState[2423]
                + ((int)(((v4 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v8 == 1)
       || v8 == 11)
      && (result = *(_DWORD *)(v7 + 116), (v13 = *(_DWORD *)(result + 324)) != 0)
      && (result = PsIsSystemProcess(result)) == 0 )
    {
      v9 = *(_DWORD *)(v13 + 8);
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
    v10 = result;
    if ( result )
    {
      *(_BYTE *)(result + 16) |= 2u;
      if ( *(int *)(result + 16) < 0 )
        KiAbEntryRemoveFromTree(result);
      KiAbEntryRemoveBoosts(v10, v7);
      *(_BYTE *)(v10 + 13) &= 0xFEu;
      *(_DWORD *)(v10 + 16) = 0;
      result = (unsigned __int64)(715827883i64 * (int)(v10 - v7 - 488)) >> 32;
      v11 = (int)(v10 - v7 - 488) / 48;
      if ( !v6 )
      {
        __dmb(0xBu);
        result = (char)(1 << v11);
        v14 = (unsigned __int8 *)(v7 + 810);
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 | result, v14) );
        __dmb(0xBu);
        return result;
      }
      *(_BYTE *)(v7 + 484) |= 1 << v11;
      goto LABEL_22;
    }
    if ( (*(_DWORD *)(v7 + 80) & 0x8000) == 0 )
      KeBugCheckEx(354, v7, v4);
    if ( v6 )
    {
LABEL_22:
      v12 = *(_WORD *)(v7 + 310) + 1;
      *(_WORD *)(v7 + 310) = v12;
      if ( !v12 && *(_DWORD *)(v7 + 100) != v7 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      return result;
    }
  }
  return result;
}
