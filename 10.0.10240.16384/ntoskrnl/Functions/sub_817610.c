// sub_817610 
 
int sub_817610()
{
  int v0; // r4
  int v1; // r7
  int v2; // r9
  _DWORD *v3; // r10
  int v4; // r5
  int v5; // r6
  int v6; // r8
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r6
  unsigned int v10; // r1
  __int64 v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r0
  int v14; // r6
  int v15; // r9
  unsigned int v16; // r2
  int v17; // r6
  unsigned int v18; // r1
  int v19; // r0
  int v20; // r0
  int v22; // [sp+0h] [bp-48h] BYREF
  int v23; // [sp+4h] [bp-44h]
  int v24; // [sp+8h] [bp-40h]
  int v25; // [sp+Ch] [bp-3Ch]
  int v26; // [sp+10h] [bp-38h]
  int v27; // [sp+14h] [bp-34h]
  int (__fastcall *v28)(int); // [sp+18h] [bp-30h]
  int (*v29)(); // [sp+1Ch] [bp-2Ch]
  int (__fastcall *v30)(int); // [sp+44h] [bp-4h]

  v4 = v0 + v2;
  v5 = KeAbPreAcquire(v0 + v2, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)v4);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)v4) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended(v0 + v2, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v4 + 28) = v6;
  *(_DWORD *)(v4 + 4) = v8;
  v9 = *(_DWORD *)(v4 + 28);
  *(_DWORD *)(v4 + 4) = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v4);
  while ( !v10 && __strex(1u, (unsigned int *)v4) );
  if ( v10 )
    ExpReleaseFastMutexContended((unsigned int *)(v0 + v2), v10);
  KfLowerIrql((unsigned __int8)v9);
  KeAbPostRelease(v0 + v2);
  memset((_BYTE *)(v0 + 520), 0, 24);
  *(_DWORD *)(v0 + 544) = 0;
  *(_DWORD *)(v0 + 548) = 0;
  *(_DWORD *)(v0 + 552) = 0;
  *(_DWORD *)(v0 + 556) = 0;
  v11 = (unsigned int)KeQueryTimeIncrement();
  if ( !(_DWORD)v11 )
    __brkdiv0();
  *(_QWORD *)v3 = (unsigned int)_rt_udiv64(v11, 0x23C34600ui64);
  memset((_BYTE *)(v0 + 16), 0, 24);
  *(_WORD *)(v0 + 26) = 0;
  *(_DWORD *)(v0 + 28) = 0;
  *(_DWORD *)(v0 + 32) = v0 + 32;
  *(_DWORD *)(v0 + 36) = v0 + 32;
  *(_DWORD *)(v0 + 16) &= 0xFFFFFFF0;
  *(_WORD *)(v0 + 24) = 2;
  memset((_BYTE *)(v0 + 40), 0, 24);
  *(_WORD *)(v0 + 50) = 0;
  *(_DWORD *)(v0 + 52) = 0;
  *(_DWORD *)(v0 + 56) = v0 + 56;
  *(_DWORD *)(v0 + 60) = v0 + 56;
  v12 = v0 + v2;
  *(_DWORD *)(v0 + 40) = *(_DWORD *)(v0 + 40) & 0xFFFFFFF0 | 1;
  *(_WORD *)(v0 + 48) = 0;
  v13 = v0 + v2;
  if ( v1 )
  {
    v14 = KeAbPreAcquire(v13, 0, 0);
    v15 = KfRaiseIrql(1);
    do
      v16 = __ldrex((unsigned __int8 *)v12);
    while ( __strex(v16 & 0xFE, (unsigned __int8 *)v12) );
    __dmb(0xBu);
    if ( (v16 & 1) == 0 )
      ExpAcquireFastMutexContended(v12, v14);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    *(_DWORD *)(v12 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v12 + 28) = v15;
  }
  else
  {
    KeInitializeGuardedMutex(v13);
  }
  *(_DWORD *)(v0 + 348) = v0 + 348;
  *(_DWORD *)(v0 + 352) = v0 + 348;
  *(_DWORD *)(v0 + 356) = v0 + 356;
  *(_DWORD *)(v0 + 360) = v0 + 356;
  if ( v1 )
  {
    v17 = *(_DWORD *)(v12 + 28);
    *(_DWORD *)(v12 + 4) = 0;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v12);
    while ( !v18 && __strex(1u, (unsigned int *)v12) );
    if ( v18 )
      ExpReleaseFastMutexContended((unsigned int *)v12, v18);
    KfLowerIrql((unsigned __int8)v17);
    KeAbPostRelease(v12);
  }
  else
  {
    PfTAccessTracingInitialize(v0, v3, 0);
  }
  v19 = v0 + 84;
  if ( v1 )
  {
    KeResetEvent(v19);
    KeResetEvent(v0 + 100);
    KeResetEvent(v0 + 68);
    KeResetEvent(v0 + 128);
  }
  else
  {
    KeInitializeEvent(v19, 0, 0);
    KeInitializeEvent(v0 + 100, 0, 0);
    KeInitializeEvent(v0 + 68, 0, 0);
    KeInitializeEvent(v0 + 128, 0, 0);
  }
  v22 = -827260927;
  v23 = 1280206416;
  v24 = 1;
  v25 = 56;
  v26 = 64;
  v27 = 0;
  v29 = PfpSectInfoHandleFullBuffer;
  v28 = (int (__fastcall *)(int))PfpSectInfoHandleOutOfBuffers;
  PfFbBufferListInitialize(v0 + 160, &v22, v1);
  *(_DWORD *)(v0 + 336) = 0;
  *(_DWORD *)(v0 + 340) = 0;
  *(_DWORD *)(v0 + 344) = -1;
  v22 = -827260926;
  v23 = 1279616592;
  v24 = 512;
  v25 = 24;
  v26 = 64;
  v27 = 0;
  v29 = (int (*)())PfpEventHandleFullBuffer;
  v28 = PfpEventHandleOutOfBuffers;
  v20 = PfFbBufferListInitialize(v0 + 256, &v22, v1);
  return v30(v20);
}
