// ExReleaseFastMutex 
 
int __fastcall ExReleaseFastMutex(int a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r1
  int result; // r0
  int v5; // r8
  int v6; // r5
  int v7; // r0
  int v8; // r7
  int v9; // r2
  int v10; // r6
  int v11; // r2
  __int16 v12; // r3
  unsigned __int8 *v13; // r2
  unsigned int v14; // r4

  v2 = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 4) = 0;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)a1);
  while ( !v3 && __strex(1u, (unsigned int *)a1) );
  if ( v3 )
    ExpReleaseFastMutexContended((unsigned int *)a1, v3);
  result = KfLowerIrql((unsigned __int8)v2);
  if ( KiAbEnabled && (a1 & 0x7FFFFFFC) != 0 )
  {
    v5 = 0;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = MmIsSessionAddress(a1);
    if ( v7 )
    {
      v7 = MmGetSessionIdEx(*(_DWORD *)(v6 + 116));
      v8 = v7;
    }
    else
    {
      v8 = -1;
    }
    if ( (unsigned int)KeGetCurrentIrql(v7) <= 1 )
    {
      v5 = 1;
      --*(_WORD *)(v6 + 310);
    }
    result = KiAbThreadClearAcquiredLockEntry(v6, a1, v8);
    v10 = result;
    if ( result )
    {
      *(_BYTE *)(result + 16) |= 2u;
      if ( *(int *)(result + 16) < 0 )
        KiAbEntryRemoveFromTree(result);
      KiAbEntryRemoveBoosts(v10, v6, v9);
      *(_BYTE *)(v10 + 13) &= 0xFEu;
      result = (unsigned __int64)(715827883i64 * (v10 - v6 - 488)) >> 32;
      *(_DWORD *)(v10 + 16) = 0;
      v11 = (v10 - v6 - 488) / 48;
      if ( !v5 )
      {
        __dmb(0xBu);
        result = (char)(1 << v11);
        v13 = (unsigned __int8 *)(v6 + 810);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 | result, v13) );
        __dmb(0xBu);
        return result;
      }
      *(_BYTE *)(v6 + 484) |= 1 << v11;
      goto LABEL_17;
    }
    if ( (*(_DWORD *)(v6 + 80) & 0x8000) == 0 )
      sub_50DCF4();
    if ( v5 )
    {
LABEL_17:
      v12 = *(_WORD *)(v6 + 310) + 1;
      *(_WORD *)(v6 + 310) = v12;
      if ( !v12 && *(_DWORD *)(v6 + 100) != v6 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      return result;
    }
  }
  return result;
}
