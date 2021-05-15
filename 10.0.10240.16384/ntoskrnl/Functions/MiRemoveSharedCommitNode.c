// MiRemoveSharedCommitNode 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiRemoveSharedCommitNode(_DWORD *a1, int a2, int a3)
{
  int result; // r0
  int v7; // r1
  unsigned int v8; // r6
  _DWORD *v9; // r10
  unsigned __int8 *v10; // r9
  int v11; // r7
  unsigned int v12; // r2
  int v13; // r9
  unsigned __int8 *v14; // r7
  int v15; // r4
  unsigned int v16; // r2
  __int64 v17; // kr00_8
  int v18; // r3
  unsigned int v19; // r4
  unsigned int *v20; // r4
  unsigned int v21; // r1
  int v22; // r3
  unsigned int *v23; // r4
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r7
  unsigned int *v28; // r2
  unsigned int v29; // r4
  int v30; // r1 OVERLAPPED
  _DWORD *v31; // r2 OVERLAPPED
  int v32; // [sp+4h] [bp-4Ch]
  char v33[12]; // [sp+8h] [bp-48h] BYREF
  int v34; // [sp+14h] [bp-3Ch]

  v34 = a2;
  if ( (a2 & 1) != 0 )
    return sub_8022A0();
  result = MiIncludeSharedCommit((int)a1);
  if ( result && (a1[7] & 0x20) == 0 && (*(_DWORD *)(a2 + 736) & 0x40) == 0 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = (_DWORD *)*a1;
    v32 = a3 & v7;
    if ( (a3 & v7) == 0 )
    {
      --*(_WORD *)(v8 + 310);
      v10 = (unsigned __int8 *)(a2 + 868);
      result = KeAbPreAcquire(a2 + 868, 0, 0);
      v11 = result;
      do
        v12 = __ldrex(v10);
      while ( __strex(v12 | 1, v10) );
      __dmb(0xBu);
      if ( (v12 & 1) != 0 )
        result = ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 868), result, a2 + 868);
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
    }
    v13 = a3 & 2;
    if ( (a3 & 2) == 0 )
    {
      --*(_WORD *)(v8 + 310);
      v14 = (unsigned __int8 *)(v9 + 7);
      result = KeAbPreAcquire((unsigned int)(v9 + 7), 0, 0);
      v15 = result;
      do
        v16 = __ldrex(v14);
      while ( __strex(v16 | 1, v14) );
      __dmb(0xBu);
      if ( (v16 & 1) != 0 )
        result = ExfAcquirePushLockExclusiveEx(v9 + 7, result, (unsigned int)(v9 + 7));
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
    }
    v27 = v9[12];
    while ( v27 )
    {
      result = MiSharedCommitCompare((int)v33, v27);
      if ( result < 0 )
      {
        v27 = *(_DWORD *)v27;
      }
      else
      {
        if ( result <= 0 )
          break;
        v27 = *(_DWORD *)(v27 + 4);
      }
    }
    v17 = *(_QWORD *)(v27 + 16) - 1i64;
    *(_QWORD *)(v27 + 16) = v17;
    if ( *(_DWORD *)(v27 + 20) | (unsigned int)v17 )
    {
      v27 = 0;
    }
    else
    {
      RtlAvlRemoveNode((int)(v9 + 12), v27);
      v18 = v9[3];
      if ( a2 )
      {
        v28 = (unsigned int *)(a2 + 864);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 - v18, v28) );
        result = v27 + 24;
        *(_QWORD *)&v30 = *(_QWORD *)(v27 + 24);
        if ( *(_DWORD *)(v30 + 4) != v27 + 24 || *v31 != result )
          __fastfail(3u);
        *v31 = v30;
        *(_DWORD *)(v30 + 4) = v31;
        if ( (*(_DWORD *)(a2 + 736) & 0x20) != 0 )
        {
          v26 = *(_DWORD *)(a2 + 288);
          __dmb(0xBu);
          result = MiRemoveSharedCommitNode(a1, v26 | 1, 3);
        }
      }
      else
      {
        result = -v18;
        do
          v19 = __ldrex((unsigned int *)0x2F4);
        while ( __strex(v19 - v18, (unsigned int *)0x2F4) );
      }
    }
    if ( !v13 )
    {
      v20 = v9 + 7;
      __dmb(0xBu);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 - 1, v20) );
      if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
        ExfTryToWakePushLock(v9 + 7);
      result = KeAbPostRelease((unsigned int)(v9 + 7));
      v22 = (__int16)(*(_WORD *)(v8 + 310) + 1);
      *(_WORD *)(v8 + 310) = v22;
      if ( !v22 && *(_DWORD *)(v8 + 100) != v8 + 100 )
        result = KiCheckForKernelApcDelivery(result);
    }
    if ( !v32 )
    {
      v23 = (unsigned int *)(a2 + 868);
      __dmb(0xBu);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 - 1, v23) );
      if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(a2 + 868));
      result = KeAbPostRelease(a2 + 868);
      v25 = (__int16)(*(_WORD *)(v8 + 310) + 1);
      *(_WORD *)(v8 + 310) = v25;
      if ( !v25 && *(_DWORD *)(v8 + 100) != v8 + 100 )
        result = KiCheckForKernelApcDelivery(result);
    }
    if ( v27 )
      result = ExFreePoolWithTag(v27);
  }
  return result;
}
