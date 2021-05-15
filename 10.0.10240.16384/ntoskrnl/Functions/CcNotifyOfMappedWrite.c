// CcNotifyOfMappedWrite 
 
int __fastcall CcNotifyOfMappedWrite(int a1, int a2, __int64 a3)
{
  int v4; // r5
  int v5; // r0
  int v6; // r4
  int v7; // r6
  int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  int v11; // r7
  int v12; // r5
  __int64 v14; // kr08_8
  int v15; // r1
  int v16; // r3
  _DWORD *v17; // r7
  int v18; // r6
  int v19; // r5
  int v20; // r6
  __int64 v21; // kr10_8
  int v22; // r0
  int *v23; // r1
  int v24; // [sp+14h] [bp-2Ch]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  __int64 varg_r2; // [sp+50h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v24 = 0;
  v4 = 0;
  v5 = KeAcquireQueuedSpinLock(5);
  v6 = *(_DWORD *)(a1 + 4);
  v7 = v5;
  if ( !v6 || (v8 = *(_DWORD *)(v6 + 96), (v8 & 0x100) != 0) )
  {
    v12 = 1;
    goto LABEL_10;
  }
  if ( (v8 & 0x20) != 0 || *(_DWORD *)(v6 + 364) )
  {
LABEL_11:
    v12 = 0;
LABEL_10:
    KeReleaseQueuedSpinLock(5, v7);
    return v12;
  }
  v9 = *(_DWORD *)(v6 + 76);
  if ( !v9 )
    goto LABEL_26;
  v10 = *(_DWORD *)(v6 + 68) & 0xFFFFFFF8;
  v11 = *(_DWORD *)(v10 + 12);
  if ( (*(_DWORD *)(v10 + 44) & 0x8000) == 0 )
    goto LABEL_29;
  *(_DWORD *)(v6 + 96) = v8 | 0x20;
  *(_DWORD *)(v6 + 76) = v9 + 1;
  KeReleaseQueuedSpinLock(5, v7);
  if ( (*(_BYTE *)(v11 + 4) & 0x20) != 0 )
    v4 = 1;
  v7 = KeAcquireQueuedSpinLock(5);
  *(_DWORD *)(v6 + 96) &= 0xFFFFFFDF;
  --*(_DWORD *)(v6 + 76);
  v10 = *(_DWORD *)(v6 + 68) & 0xFFFFFFF8;
  if ( !v4 )
  {
LABEL_29:
    if ( CcCanIWriteStream(v10, 0x1000000, 0, 1) )
    {
      v12 = 0;
      if ( CcCoalescingState )
      {
        ++CcDbgCoalescingFlushDueToMPW;
        CcScheduleLazyWriteScan(1, 0);
      }
      goto LABEL_10;
    }
  }
  v14 = *(_QWORD *)(v6 + 32);
  if ( varg_r2 <= v14 || *(_QWORD *)(v6 + 40) <= v14 )
LABEL_26:
    JUMPOUT(0x53C40A);
  v15 = *(_DWORD *)(v6 + 76);
  v16 = CcPagesYetToWrite;
  *(_DWORD *)(v6 + 120) = v15;
  CcPagesYetToWrite = v16 + v15;
  dword_6325E8 += v15;
  *(_DWORD *)(v6 + 96) |= 0x20u;
  ++*(_DWORD *)(v6 + 76);
  KeReleaseQueuedSpinLock(5, v7);
  v17 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  v18 = v17[716];
  ++*(_DWORD *)(v18 + 12);
  v19 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v18);
  if ( v19 )
    goto LABEL_22;
  ++*(_DWORD *)(v18 + 16);
  v20 = v17[717];
  ++*(_DWORD *)(v20 + 12);
  v19 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v20);
  if ( v19
    || (v21 = *(_QWORD *)(v20 + 32),
        v22 = *(_DWORD *)(v20 + 28),
        ++*(_DWORD *)(v20 + 16),
        (v19 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v20 + 40))(v22, HIDWORD(v21), v21)) != 0) )
  {
LABEL_22:
    *(_DWORD *)v19 = v17[357];
    *(_BYTE *)(v19 + 64) = 2;
    *(_DWORD *)(v19 + 8) = v6;
    v7 = KeAcquireQueuedSpinLock(5);
    --*(_DWORD *)(v6 + 76);
    if ( (*(_DWORD *)(v6 + 96) & 0x10000) != 0 )
    {
      v23 = &CcFastTeardownWorkQueue;
      *(_DWORD *)(v6 + 352) = v19 | 1;
    }
    else
    {
      v23 = &CcRegularWorkQueue;
      *(_DWORD *)(v6 + 352) = v19;
    }
    CcPostWorkQueue(v19, v23);
    goto LABEL_11;
  }
  return sub_53C3F4();
}
