// FsRtlpOplockCleanup 
 
int __fastcall FsRtlpOplockCleanup(int result, int a2)
{
  int v2; // r8
  _DWORD *v3; // r5
  int v4; // r10
  int *i; // r4
  _DWORD *v6; // r2
  int v7; // r0
  _DWORD *v8; // r1
  int v9; // r10
  _DWORD *j; // r4
  int v11; // r1
  int v12; // r1
  _DWORD *v13; // r4
  int v14; // r8
  int v15; // r0
  _DWORD *v16; // r1
  int v17; // r8
  int v18; // r4
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r4
  int v22; // r3
  int v23; // r2
  int v24; // r3
  int v25; // r2
  char v26; // [sp+10h] [bp-28h]
  int v28; // [sp+18h] [bp-20h]
  int _40; // [sp+40h] [bp+8h]
  int _44; // [sp+44h] [bp+Ch]

  _44 = a2;
  v2 = a2;
  v3 = (_DWORD *)result;
  _40 = result;
  v26 = 0;
  if ( *(_DWORD *)(result + 72) == 1 )
    goto LABEL_65;
  result = IoGetOplockFullFoExt(*(_DWORD *)(a2 + 28));
  v4 = result;
  v28 = result;
  if ( (v3[18] & 0x1000000) != 0 )
  {
    for ( i = (int *)v3[13]; i != v3 + 13; i = (int *)*i )
    {
      if ( *(_DWORD *)(v2 + 28) == i[2] )
      {
        while ( (_DWORD *)v3[11] != v3 + 11 )
          FsRtlpRemoveAndCompleteWaitingIrp(v3[11]);
        v6 = *(_DWORD **)i[1];
        v7 = *v6;
        v8 = (_DWORD *)v6[1];
        if ( *(_DWORD **)(*v6 + 4) != v6 || (_DWORD *)*v8 != v6 )
          __fastfail(3u);
        *v8 = v7;
        *(_DWORD *)(v7 + 4) = v8;
        ObfDereferenceObjectWithTag(i[2]);
        result = ExFreePoolWithTag(i, 0);
        break;
      }
    }
    v3[18] &= 0xFEFFFFFF;
    if ( (_DWORD *)v3[13] != v3 + 13 )
      v26 = 1;
  }
  if ( (_DWORD *)v3[5] != v3 + 5 )
  {
    v9 = 0;
    for ( j = (_DWORD *)v3[5]; j != v3 + 5; j = (_DWORD *)*j )
    {
      v11 = j[2];
      if ( *(_DWORD *)(a2 + 28) == *(_DWORD *)(v11 + 28) )
      {
        j = (_DWORD *)j[1];
        if ( *(_DWORD *)(v11 + 16) == 590400 )
        {
          v12 = 534;
          v9 = 1;
        }
        else
        {
          v12 = 0;
        }
        FsRtlpRemoveAndCompleteReadOnlyIrp(*j, v12, 0);
        if ( v9 )
          break;
      }
    }
    result = FsRtlpComputeShareableOplockState(v3);
    v4 = v28;
  }
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 40);
    if ( v13 )
    {
      v14 = 0;
      if ( (v13[6] & 0xF00000) != 0 )
      {
        FsRtlpOplockDequeueRH(*(_DWORD *)(v4 + 40));
        FsRtlpModifyThreadPriorities(v3, v13, 0);
        FsRtlpClearOwnerThread((int)v3, (int)v13);
        if ( (_DWORD *)v3[9] == v3 + 9 )
          *((_BYTE *)v3 + 16) = 0;
        ObfDereferenceObjectWithTag(v13[3]);
      }
      else
      {
        if ( (v3[18] & 0x10000) == 0 || !v13[7] )
        {
          FsRtlpRemoveAndBreakRHIrp(v13, (int)v3, 1, 534, 0, 0);
          goto LABEL_42;
        }
        FsRtlpOplockDequeueRH(*(_DWORD *)(v4 + 40));
        v15 = v13[7];
        v16 = (_DWORD *)v13[8];
        if ( *(_DWORD **)(v15 + 4) != v13 + 7 || (_DWORD *)*v16 != v13 + 7 )
          __fastfail(3u);
        *v16 = v15;
        *(_DWORD *)(v15 + 4) = v16;
        if ( (_DWORD *)v3[15] == v3 + 15 )
          v3[18] &= 0xFFFCFFFF;
        if ( v13[5] )
          FsRtlpClearOwnerThread((int)v3, (int)v13);
      }
      ExFreePoolWithTag(v13, 0);
      v14 = 1;
LABEL_42:
      result = FsRtlpComputeShareableOplockState(v3);
      if ( v14 )
        result = FsRtlpReleaseIrpsWaitingForRH(result);
      goto LABEL_44;
    }
  }
LABEL_44:
  if ( *(_DWORD *)(a2 + 28) == v3[1] )
  {
    if ( (v3[18] & 0x1F00F80) == 0 )
    {
      v17 = *v3;
      v18 = *(_DWORD *)(*v3 + 96);
      *(_BYTE *)(v17 + 37) = KeAcquireQueuedSpinLock(7);
      __dmb(0xBu);
      v19 = (unsigned int *)(v17 + 56);
      do
        v20 = __ldrex(v19);
      while ( __strex(0, v19) );
      __dmb(0xBu);
      KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v17 + 37));
      if ( *(_DWORD *)(v18 + 16) == 590400 )
      {
        v21 = *(_DWORD *)(v17 + 12);
        memset((_BYTE *)v21, 0, 24);
        *(_WORD *)v21 = 1;
        *(_WORD *)(v21 + 2) = 24;
        v22 = v3[18];
        if ( (v22 & 0x4000) != 0 )
          v23 = 4;
        else
          v23 = 0;
        if ( (v22 & 0x2000) != 0 )
          v24 = 2;
        else
          v24 = 0;
        *(_DWORD *)(v21 + 4) = v24 | v23 | ((v3[18] & 0x1000) != 0);
        *(_DWORD *)(v21 + 8) = 0;
        *(_DWORD *)(v17 + 28) = 24;
        v25 = 534;
      }
      else
      {
        *(_DWORD *)(v17 + 28) = 8;
        v25 = 0;
      }
      *(_DWORD *)(*v3 + 24) = v25;
      result = pIofCompleteRequest(*v3, 1);
    }
    if ( (v3[18] & 0x80) == 0 )
      result = ObfDereferenceObjectWithTag(v3[1]);
    v3[1] = 0;
    *v3 = 0;
    if ( v3[3] )
    {
      FsRtlpModifyThreadPriorities(v3, 0, 0);
      result = FsRtlpClearOwnerThread((int)v3, 0);
      *((_BYTE *)v3 + 16) = 0;
    }
    v3[18] = v3[18] & 0x20 | 1;
    while ( (_DWORD *)v3[11] != v3 + 11 )
      result = FsRtlpRemoveAndCompleteWaitingIrp(v3[11]);
  }
LABEL_65:
  if ( v26 )
    *(_DWORD *)(_40 + 72) |= 0x1000000u;
  return result;
}
