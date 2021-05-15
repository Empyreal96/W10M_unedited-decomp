// PfSnBeginTrace 
 
int __fastcall PfSnBeginTrace(int a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  _BYTE *v9; // r0
  unsigned int v10; // r5
  unsigned int v12; // r6
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  int *v16; // r2
  int v17; // r1
  _BYTE *v18; // r0
  int v19; // r3
  int v20; // r4
  unsigned int *v21; // r2
  unsigned int **v22; // r1

  if ( PfSnNumActiveTraces >= (unsigned int)dword_637108 )
    return -1073741618;
  if ( !FsRtlpVolumeStartupApplicationsComplete )
    return -1073741661;
  v9 = (_BYTE *)ExAllocatePoolWithTag(512, 416, 1414554435);
  v10 = (unsigned int)v9;
  if ( !v9 )
    return sub_8089E0();
  memset(v9, 0, 416);
  *(_DWORD *)v10 = 1128485697;
  KeInitializeTimerEx((_DWORD *)(v10 + 104), 0);
  v12 = v10 + 84;
  *(_DWORD *)(v10 + 84) = v10 + 84;
  *(_DWORD *)(v10 + 88) = v10 + 84;
  *(_DWORD *)(v10 + 320) = -1073741779;
  *(_DWORD *)(v10 + 96) = 0;
  KeQuerySystemTime((_DWORD *)(v10 + 328));
  *(_DWORD *)(v10 + 364) = 0;
  *(_DWORD *)(v10 + 368) = 0;
  *(_DWORD *)(v10 + 192) = 0;
  KeInitializeDpc(v10 + 160, (int)PfSnTraceTimerRoutine, v10);
  v13 = (unsigned int *)(v10 + 268);
  __pld((void *)(v10 + 268));
  *(_DWORD *)(v10 + 268) = 0;
  v14 = *(_DWORD *)(v10 + 268) & 0xFFFFFFFE;
  do
    v15 = __ldrex(v13);
  while ( v15 == v14 && __strex(v14 + 2, v13) );
  __dmb(0xBu);
  if ( v15 != v14 )
    ExfAcquireRundownProtection(v13);
  ObfReferenceObjectWithTag(a3);
  *(_DWORD *)(v10 + 264) = a3;
  *(_DWORD *)(v10 + 280) = PfSnEndTraceWorkerThreadRoutine;
  *(_DWORD *)(v10 + 284) = v10;
  *(_DWORD *)(v10 + 272) = 0;
  *(_DWORD *)(v10 + 288) = 0;
  memmove(v10 + 12, a1, 0x40u);
  *(_DWORD *)(v10 + 76) = a2;
  *(_WORD *)(v10 + 346) ^= (*(_WORD *)(v10 + 346) ^ (a5 != 0)) & 1;
  v16 = (int *)((char *)&unk_6370E8 + 16 * a2);
  v17 = *v16;
  *(_DWORD *)(v10 + 256) = *v16;
  *(_DWORD *)(v10 + 152) = v16[2];
  *(_DWORD *)(v10 + 156) = v16[3];
  if ( v17 )
  {
    if ( v17 > 0x100000 )
      *(_DWORD *)(v10 + 256) = 0x100000;
    v18 = PfSnTraceBufferAllocate();
    __dmb(0xBu);
    *(_DWORD *)(v10 + 80) = v18;
    v19 = *(_DWORD *)(v10 + 80);
    __dmb(0xBu);
    if ( v19 )
    {
      v21 = *(unsigned int **)(v10 + 80);
      __dmb(0xBu);
      v22 = *(unsigned int ***)(v10 + 88);
      *v21 = v12;
      v21[1] = (unsigned int)v22;
      if ( *v22 != (unsigned int *)v12 )
        __fastfail(3u);
      *v22 = v21;
      *(_DWORD *)(v10 + 88) = v21;
      *(_DWORD *)(v10 + 304) = -1;
      *(_DWORD *)(v10 + 300) = -8;
      *(_DWORD *)(v10 + 92) = 1;
      __dmb(0xBu);
      *(_DWORD *)(v10 + 296) = v10 + 300;
      if ( a4 )
      {
        *(_DWORD *)(v10 + 308) = a4;
        *(_DWORD *)(v10 + 312) = PsGetThreadId(a4);
      }
      v20 = PfSnActivateTrace(v10);
      if ( v20 >= 0 )
      {
        *a6 = v10;
        v10 = 0;
        v20 = 0;
      }
    }
    else
    {
      v20 = -1073741670;
    }
  }
  else
  {
    v20 = -1073741811;
  }
  if ( v10 )
  {
    PfSnCleanupTrace(v10);
    ExFreePoolWithTag(v10);
  }
  return v20;
}
