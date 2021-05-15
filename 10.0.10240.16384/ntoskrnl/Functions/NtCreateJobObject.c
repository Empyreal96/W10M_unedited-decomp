// NtCreateJobObject 
 
int __fastcall NtCreateJobObject(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r8
  int *v5; // r2
  int v6; // r5
  int v7; // r4
  int v8; // r2
  _BYTE *v9; // r5
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  void ***v13; // r0
  unsigned int v14; // r1
  int v15; // r0
  __int16 v16; // r3
  int v17; // r3
  int v18; // r1
  char v20; // [sp+18h] [bp-48h]
  int v21; // [sp+1Ch] [bp-44h] BYREF
  _BYTE *v22; // [sp+20h] [bp-40h]
  int v23; // [sp+24h] [bp-3Ch]
  unsigned int v24[2]; // [sp+28h] [bp-38h] BYREF
  int v25; // [sp+30h] [bp-30h]
  _DWORD *v26; // [sp+34h] [bp-2Ch]
  BOOL v27; // [sp+38h] [bp-28h]
  int v28; // [sp+3Ch] [bp-24h]
  _DWORD *varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r3 = a4;
  v24[0] = a3;
  varg_r2 = a3;
  v25 = a2;
  varg_r1 = a2;
  v26 = a1;
  varg_r0 = a1;
  v22 = 0;
  v21 = 0;
  v23 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = v4;
  v20 = *(_BYTE *)(v4 + 0x15A);
  if ( v20 )
  {
    v5 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v5 = (int *)MmUserProbeAddress;
    v28 = *v5;
    *v5 = v28;
  }
  *a1 = 0;
  v6 = 760;
  v27 = PoEnergyEstimationEnabled();
  if ( v27 )
    v6 = 904;
  v7 = ObCreateObjectEx(v20, PsJobType, v24[0], v20);
  if ( v7 < 0 )
  {
    v9 = v22;
  }
  else
  {
    v8 = v6;
    v9 = v22;
    memset(v22, 0, v8);
    __dmb(0xBu);
    *((_DWORD *)v9 + 144) = v9;
    *((_DWORD *)v9 + 7) = v9 + 24;
    *((_DWORD *)v9 + 6) = v9 + 24;
    *((_DWORD *)v9 + 142) = v9 + 564;
    *((_DWORD *)v9 + 141) = v9 + 564;
    *((_DWORD *)v9 + 140) = v9 + 556;
    *((_DWORD *)v9 + 139) = v9 + 556;
    *((_DWORD *)v9 + 146) = v9 + 580;
    *((_DWORD *)v9 + 145) = v9 + 580;
    *((_DWORD *)v9 + 175) = v9 + 696;
    *((_DWORD *)v9 + 174) = v9 + 696;
    KeInitializeEvent((int)v9, 0, 0);
    *((_DWORD *)v9 + 138) = 0;
    *((_DWORD *)v9 + 173) = 0;
    *((_WORD *)v9 + 92) = 1;
    *((_WORD *)v9 + 93) = 1;
    *((_DWORD *)v9 + 47) = 0;
    *((_DWORD *)v9 + 48) = 0;
    *((_WORD *)v9 + 174) = 1;
    *((_WORD *)v9 + 175) = 1;
    *((_DWORD *)v9 + 88) = 0;
    *((_DWORD *)v9 + 89) = 0;
    *((_DWORD *)v9 + 182) = v9 + 724;
    *((_DWORD *)v9 + 181) = v9 + 724;
    *((_DWORD *)v9 + 183) = 0;
    if ( v27 )
      *((_DWORD *)v9 + 188) = v9 + 760;
    *((_DWORD *)v9 + 58) = -1;
    *((_DWORD *)v9 + 107) = 8190;
    *((_DWORD *)v9 + 101) = 10;
    *((_DWORD *)v9 + 59) = 5;
    ExInitializeResourceLite((int)(v9 + 32));
    --*(_WORD *)(v4 + 310);
    v10 = KeAbPreAcquire((unsigned int)&PspJobListLock, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned __int8 *)&PspJobListLock);
    while ( __strex(v12 | 1, (unsigned __int8 *)&PspJobListLock) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&PspJobListLock, v10, (unsigned int)&PspJobListLock);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = (void ***)off_920168;
    *((_DWORD *)v9 + 4) = &PspJobList;
    *((_DWORD *)v9 + 5) = v13;
    if ( *v13 != &PspJobList )
      __fastfail(3u);
    *v13 = (void **)(v9 + 16);
    off_920168 = v9 + 16;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&PspJobListLock);
    while ( __strex(v14 - 1, (unsigned int *)&PspJobListLock) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PspJobListLock);
    v15 = KeAbPostRelease((unsigned int)&PspJobListLock);
    v16 = *(_WORD *)(v4 + 310) + 1;
    *(_WORD *)(v4 + 310) = v16;
    if ( !v16 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      KiCheckForKernelApcDelivery(v15);
    v17 = *((_DWORD *)v9 + 186);
    *((_DWORD *)v9 + 186) = v17 | 0x200000;
    v23 = v17 | 0x200000;
    while ( 1 )
    {
      v7 = ExUuidCreate(v9 + 704);
      if ( v7 != -1073741267 )
        break;
      v24[0] = -10000;
      v24[1] = -1;
      KeDelayExecutionThread(0, 0, v24);
    }
    if ( v7 == 1073872982 )
      v7 = 0;
    if ( v7 < 0 )
    {
      ObfDereferenceObject((int)v9);
    }
    else
    {
      v7 = ObInsertObject(v9, 0, v25, 0, 0, &v21);
      if ( v7 >= 0 )
      {
        v18 = v21;
        *v26 = v21;
        goto LABEL_37;
      }
    }
  }
  v18 = v21;
LABEL_37:
  if ( (PerfGlobalGroupMask & 0x80000) != 0 )
    EtwTraceJob(v9, v18);
  return v7;
}
