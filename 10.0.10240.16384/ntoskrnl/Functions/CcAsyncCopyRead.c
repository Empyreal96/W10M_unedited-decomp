// CcAsyncCopyRead 
 
int __fastcall CcAsyncCopyRead(int a1, int a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7, int a8)
{
  unsigned int v10; // r4
  __int64 v12; // kr08_8
  unsigned int v13; // r7
  _DWORD *v14; // r0
  _DWORD *v15; // r8
  _DWORD *v16; // r6
  int v17; // r5
  int v18; // r1
  int v19; // r4
  int v20; // r5
  int v21; // r1
  int v22; // r2
  int v23; // r0
  int v24; // r0
  int v25; // r6
  unsigned int *v26; // r2
  unsigned int v27; // r1
  int v28; // r3
  int v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r2
  int v34; // [sp+1Ch] [bp-24h]

  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(*(_DWORD *)(v10 + 0x150) + 192) & 0x100000) != 0 )
    return sub_522C00();
  if ( ((*(_DWORD *)(v10 + 0x3C0) >> 9) & 7u) < 2 )
    __mrc(15, 0, 13, 0, 3);
  v12 = *(_QWORD *)(a1 + 20);
  v34 = *(_DWORD *)(v12 + 4);
  if ( (signed __int64)(*(_QWORD *)a2 + a3) > *(_QWORD *)(v34 + 8) )
    KeBugCheckEx(52, 1002, -1073740768);
  if ( !a5 )
    RtlRaiseStatus(-1073741592);
  v13 = a7;
  if ( CcEnableReadAheadInAsyncRead && (*(_DWORD *)HIDWORD(v12) & 0x20000) != 0 )
    CcScheduleReadAheadEx(a1, a2, a3, a7);
  v14 = (_DWORD *)ExAllocatePoolWithTag(512, 4, 1933665091);
  v15 = v14;
  if ( !v14 )
    RtlRaiseStatus(-1073741670);
  *v14 = 0;
  v16 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  v17 = v16[716];
  ++*(_DWORD *)(v17 + 12);
  v19 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v17);
  if ( !v19 )
  {
    ++*(_DWORD *)(v17 + 16);
    v20 = v16[717];
    ++*(_DWORD *)(v20 + 12);
    v19 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v20);
    if ( !v19 )
    {
      v21 = *(_DWORD *)(v20 + 36);
      v22 = *(_DWORD *)(v20 + 32);
      v23 = *(_DWORD *)(v20 + 28);
      ++*(_DWORD *)(v20 + 16);
      v19 = (*(int (__fastcall **)(int, int, int))(v20 + 40))(v23, v21, v22);
      if ( !v19 )
      {
        ExFreePoolWithTag(v15, 1933665091);
        RtlRaiseStatus(-1073741670);
      }
    }
  }
  *(_DWORD *)v19 = v16[357];
  if ( !a7 )
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  PsUpdateDiskCounters(*(_DWORD *)(v13 + 336), v18, (a3 + 4095) & 0xFFFFF000, 0, 0, 0, 1, 0, 0);
  v24 = KeAcquireQueuedSpinLock(5);
  v25 = v34;
  ++*(_DWORD *)(v34 + 4);
  *(_DWORD *)(v34 + 96) |= 0x40000000u;
  KeReleaseQueuedSpinLock(5, v24);
  __dmb(0xBu);
  v26 = (unsigned int *)(v25 + 368);
  do
    v27 = __ldrex(v26);
  while ( __strex(v27 + 1, v26) );
  __dmb(0xBu);
  *(_BYTE *)(v19 + 64) = 5;
  *(_DWORD *)(v19 + 8) = v34;
  *(_DWORD *)(v19 + 24) = a1;
  *(_DWORD *)(v19 + 16) = *(_DWORD *)a2;
  v28 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v19 + 28) = a3;
  *(_DWORD *)(v19 + 32) = v15;
  *(_DWORD *)(v19 + 20) = v28;
  v29 = *(_DWORD *)(a8 + 8);
  *(_DWORD *)(v19 + 48) = a8;
  *(_DWORD *)(v19 + 40) = v29;
  *(_DWORD *)(v19 + 44) = a6;
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v31 = (*(_DWORD *)(v30 + 0x3C0) >> 12) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(v30 + 0x150) + 192) & 0x100000) != 0 && v31 >= 2 )
    v31 = 2;
  *(_DWORD *)(v19 + 36) = v31;
  *(_DWORD *)(v19 + 52) = *(_DWORD *)(v13 + 336);
  *(_BYTE *)(v19 + 56) = *(_BYTE *)(a8 + 12);
  *(_DWORD *)(v19 + 60) = *(_DWORD *)(a8 + 16);
  v32 = *(_DWORD *)(a8 + 16);
  if ( v32 > CcMaxNestingLevel )
    KeBugCheckEx(52, 1144, -1073740768);
  CcPostWorkQueueAsyncRead(v19, CcAsyncReadWorkQueue + 8 * v32);
  return 1;
}
