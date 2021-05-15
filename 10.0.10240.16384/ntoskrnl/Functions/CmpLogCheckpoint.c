// CmpLogCheckpoint 
 
int __fastcall CmpLogCheckpoint(_DWORD *a1, int a2, int a3)
{
  int v5; // r6
  unsigned int v6; // r1
  unsigned int v7; // r8
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r8
  int v13; // r4
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22; // r0
  unsigned int v23; // r4
  int *v24; // r3
  int v25; // r0
  int v26; // r0
  unsigned int v27; // r4
  int v29; // [sp+10h] [bp-B8h] BYREF
  int v30; // [sp+14h] [bp-B4h]
  int v31; // [sp+18h] [bp-B0h] BYREF
  int v32; // [sp+1Ch] [bp-ACh] BYREF
  int v33[2]; // [sp+20h] [bp-A8h] BYREF
  int v34[2]; // [sp+28h] [bp-A0h] BYREF
  char v35[88]; // [sp+30h] [bp-98h] BYREF
  int v36; // [sp+88h] [bp-40h]
  int v37; // [sp+8Ch] [bp-3Ch]

  v31 = 0;
  v29 = 0;
  v30 = -1;
  v5 = 0;
  v33[0] = 0;
  v33[1] = 0;
  v32 = 120;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v8);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_632184 = v7;
  while ( 1 )
  {
    v11 = CmListGetNextElement(a1 + 2, &v31, 0);
    v12 = v11;
    if ( !v11 )
      break;
    if ( !ClfsLsnInvalid(v11 + 56) )
    {
      v13 = ClfsLsnContainer(v12 + 56);
      if ( v13 == ClfsLsnContainer(a1 + 18) )
      {
        dword_632184 = 0;
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)&CmpTransactionListLock);
        while ( !v14 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
        if ( v14 )
          ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v14);
        v15 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
        v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v17 = *(_WORD *)(v16 + 0x134) + 1;
        *(_WORD *)(v16 + 308) = v17;
        if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
          KiCheckForKernelApcDelivery(v15);
        return 0;
      }
    }
    if ( ClfsLsnInvalid(&v29) || ClfsLsnLess(v12 + 56, &v29) )
    {
      v29 = *(_DWORD *)(v12 + 56);
      v30 = *(_DWORD *)(v12 + 60);
    }
  }
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v18 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v18 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v18);
  v19 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  if ( ClfsLsnInvalid(&v29) )
  {
    v5 = ClfsGetLogFileInformation(a1[13], v35, &v32);
    if ( v5 >= 0 )
    {
      v29 = v36;
      v30 = v37;
    }
  }
  v31 = 120;
  v22 = ExAllocatePoolWithTag(1, 120, 538987843);
  v23 = v22;
  if ( v22 )
  {
    ClfsGetLogFileInformation(a1[13], v22, &v31);
    ExFreePoolWithTag(v23);
  }
  if ( v5 >= 0 )
  {
    v34[0] = v29;
    v34[1] = v30;
    v24 = a3 ? &v29 : 0;
    v25 = ClfsWriteRestartArea(a1[14], v34, 8, v24, 0, &v32, v33);
    v5 = v25;
    if ( a3 )
    {
      if ( v25 >= 0 )
      {
        a1[18] = v29;
        a1[19] = v30;
      }
    }
  }
  v31 = 120;
  v26 = ExAllocatePoolWithTag(1, 120, 538987843);
  v27 = v26;
  if ( v26 )
  {
    ClfsGetLogFileInformation(a1[13], v26, &v31);
    ExFreePoolWithTag(v27);
  }
  return v5;
}
