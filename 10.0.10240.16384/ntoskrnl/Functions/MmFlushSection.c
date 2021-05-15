// MmFlushSection 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MmFlushSection(int a1, int *a2, int a3, int a4, _DWORD *a5, unsigned int a6)
{
  int v6; // r6 OVERLAPPED
  int v7; // r3
  int v8; // r5
  unsigned int v9; // r8
  int v10; // r7
  int v11; // r10
  int v12; // r5
  int v13; // r0
  int v15; // r9
  _DWORD *v16; // r10
  unsigned int *v17; // r4
  int v18; // r8
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v24[2]; // [sp+18h] [bp-40h] BYREF
  int v25; // [sp+20h] [bp-38h] BYREF
  int v26; // [sp+24h] [bp-34h]
  int v27; // [sp+28h] [bp-30h]
  _DWORD *v28; // [sp+2Ch] [bp-2Ch]
  int v29; // [sp+30h] [bp-28h]
  int v30; // [sp+34h] [bp-24h]

  v6 = a3;
  if ( a2 )
  {
    v24[0] = *a2;
    v7 = a2[1];
    a2 = v24;
    v24[1] = v7;
  }
  v8 = 0;
  *(_QWORD *)a5 = *(_QWORD *)(&v6 - 1);
  if ( !MiComputeFlushRange(a1, a2, a3, &v25) )
    return 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24[0] = *(unsigned __int8 *)(v9 + 0x3CC);
  v10 = v25;
  *(_BYTE *)(v9 + 972) = 1;
  if ( (a6 & 1) != 0 )
  {
    v11 = MI_REFERENCE_CONTROL_AREA_FILE(v10);
    v12 = FsRtlAcquireFileForCcFlushEx(v11);
    if ( v12 >= 0 )
    {
      v12 = MiFlushSectionInternal(v26, v27, v28, v29, 0, a6, a5);
      v13 = FsRtlReleaseFileForCcFlush(v11);
      if ( v12 == -1073741740 )
        return sub_53D18C(v13);
    }
    v10 = v25;
    MI_DEREFERENCE_CONTROL_AREA_FILE(v25, v11);
    v6 = a3;
    v16 = v28;
    v15 = v29;
  }
  else
  {
    v16 = v28;
    v15 = v29;
    v12 = MiFlushSectionInternal(v26, v27, v28, v29, 0, a6, a5);
  }
  if ( v12 < 0 || a5[1] )
    a5[1] += v30 << 12;
  else
    a5[1] = v6;
  v17 = (unsigned int *)(v10 + 36);
  *(_BYTE *)(v9 + 972) = v24[0];
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v10 + 36);
  }
  else
  {
    v19 = (unsigned __int8 *)(v10 + 39);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 | 0x80, v19) );
    __dmb(0xBu);
    if ( v20 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v10 + 36));
    while ( 1 )
    {
      v21 = *v17;
      if ( (*v17 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v21 & 0x40000000) == 0 )
      {
        do
          v22 = __ldrex(v17);
        while ( v22 == v21 && __strex(v21 | 0x40000000, v17) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiDecrementSubsections(v16);
  MiDecrementSubsections(v15);
  --*(_DWORD *)(v10 + 20);
  MiCheckControlArea(v10, v18);
  return v12;
}
