// ExpGetSystemPlatformBinary 
 
int __fastcall ExpGetSystemPlatformBinary(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r9
  int v6; // r3
  int v7; // r4
  int v8; // r6
  int v9; // r8
  unsigned int v10; // r2
  int v11; // r6
  unsigned int v12; // r1
  int v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // r0
  unsigned int v19; // r4
  _DWORD *v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r6
  unsigned int v24; // r1
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r2
  int v30; // r6
  unsigned int v31; // lr
  __int64 v32; // r0
  unsigned int v33; // r3
  unsigned int v34; // r2
  int v35; // r2
  int v36; // r10
  int v37; // r10
  unsigned int v38; // r1
  int v39; // r0
  __int16 v40; // r3
  int v42; // [sp+4h] [bp-7Ch]
  int v43; // [sp+8h] [bp-78h]
  int v44; // [sp+Ch] [bp-74h]
  _DWORD *v45; // [sp+14h] [bp-6Ch] BYREF
  int v46; // [sp+18h] [bp-68h]
  unsigned int v47; // [sp+1Ch] [bp-64h]
  int v48; // [sp+20h] [bp-60h]
  unsigned int v49; // [sp+24h] [bp-5Ch]
  int v50; // [sp+28h] [bp-58h]
  unsigned int v51; // [sp+2Ch] [bp-54h]
  unsigned int v52; // [sp+30h] [bp-50h]
  int v53; // [sp+34h] [bp-4Ch]
  unsigned int v54; // [sp+38h] [bp-48h]
  unsigned int v55; // [sp+3Ch] [bp-44h]
  unsigned int v56; // [sp+40h] [bp-40h]
  _DWORD _48[18]; // [sp+48h] [bp-38h] BYREF
  int varg_r2; // [sp+90h] [bp+10h]
  int varg_r3; // [sp+94h] [bp+14h]

  _48[16] = a1;
  _48[17] = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v50 = (char)a3;
  LOBYTE(varg_r2) = a3;
  v45 = a1;
  v5 = 0;
  v6 = 0;
  v44 = 0;
  v48 = 0;
  v43 = 0;
  v46 = 0;
  if ( a2 < 0x18 )
  {
    v7 = -1073741811;
    v8 = 0;
    goto LABEL_76;
  }
  v9 = a1[5];
  v47 = v9;
  v53 = v9;
  v49 = a1[4];
  v56 = v49;
  v52 = a1[2];
  v54 = v52;
  v51 = a1[3];
  v55 = v51;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = KeAbPreAcquire((unsigned int)&ExpPlatformBinaryLock, 0, 0);
  do
    v12 = __ldrex((unsigned int *)&ExpPlatformBinaryLock);
  while ( !v12 && __strex(0x11u, (unsigned int *)&ExpPlatformBinaryLock) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(&ExpPlatformBinaryLock, v11, (unsigned int)&ExpPlatformBinaryLock);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v42 = 1;
  v13 = ExpPlatformBinaryTableInformation;
  if ( ExpPlatformBinaryTableInformation == -1 )
  {
    v7 = -1073741637;
LABEL_75:
    v6 = v42;
    v8 = v43;
    goto LABEL_76;
  }
  if ( !ExpPlatformBinaryTableInformation )
  {
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&ExpPlatformBinaryLock);
    while ( v14 == 17 && __strex(0, (unsigned int *)&ExpPlatformBinaryLock) );
    if ( v14 != 17 )
      ExfReleasePushLockShared(&ExpPlatformBinaryLock);
    v15 = KeAbPostRelease((unsigned int)&ExpPlatformBinaryLock);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    v42 = 0;
    if ( v49 || v9 )
    {
      v7 = -1073741811;
      goto LABEL_75;
    }
    _48[0] = 1094930505;
    _48[1] = 1;
    _48[2] = 1413632087;
    _48[3] = 0;
    v18 = ExpGetSystemFirmwareTableInformation(_48, 0, 0x14u, (int *)&v45);
    if ( v18 != -1073741789 )
    {
      v6 = 0;
      v8 = 0;
      if ( v18 < 0 )
        v7 = -1073741637;
      else
        v7 = -1073741701;
      goto LABEL_76;
    }
    v19 = (unsigned int)v45;
    v20 = (_DWORD *)ExAllocatePoolWithTag(512, (int)v45, 1413632087);
    v5 = (unsigned int)v20;
    if ( !v20 )
    {
LABEL_29:
      v7 = -1073741670;
      goto LABEL_75;
    }
    *v20 = 1094930505;
    v20[1] = 1;
    v20[2] = 1413632087;
    v20[3] = v19 - 16;
    v7 = ExpGetSystemFirmwareTableInformation(v20, 0, v19, (int *)&v45);
    if ( v7 < 0 )
      goto LABEL_75;
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v21 + 308);
    v22 = KeAbPreAcquire((unsigned int)&ExpPlatformBinaryLock, 0, 0);
    v23 = v22;
    do
      v24 = __ldrex((unsigned __int8 *)&ExpPlatformBinaryLock);
    while ( __strex(v24 | 1, (unsigned __int8 *)&ExpPlatformBinaryLock) );
    __dmb(0xBu);
    if ( (v24 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ExpPlatformBinaryLock, v22, (unsigned int)&ExpPlatformBinaryLock);
    if ( v23 )
      *(_BYTE *)(v23 + 14) |= 1u;
    if ( ExpPlatformBinaryTableInformation )
    {
      if ( ExpPlatformBinaryTableInformation == -1 )
      {
        __dmb(0xBu);
        do
          v25 = __ldrex((unsigned int *)&ExpPlatformBinaryLock);
        while ( __strex(v25 - 1, (unsigned int *)&ExpPlatformBinaryLock) );
        if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&ExpPlatformBinaryLock);
        v26 = KeAbPostRelease((unsigned int)&ExpPlatformBinaryLock);
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v28 = *(_WORD *)(v27 + 0x134) + 1;
        *(_WORD *)(v27 + 308) = v28;
        if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
          KiCheckForKernelApcDelivery(v26);
        v7 = -1073741637;
        goto LABEL_75;
      }
    }
    else
    {
      ExpPlatformBinaryTableInformation = v5;
      v5 = 0;
    }
    __dmb(0xBu);
    do
      v29 = __ldrex((unsigned int *)&ExpPlatformBinaryLock);
    while ( v29 == 1 && __strex(0x11u, (unsigned int *)&ExpPlatformBinaryLock) );
    __dmb(0xBu);
    v42 = 1;
    v13 = ExpPlatformBinaryTableInformation;
  }
  if ( (v47 & 1) != 0 )
  {
    v7 = -1073741811;
    goto LABEL_75;
  }
  v30 = v13 + 16;
  if ( *(_BYTE *)(v13 + 64) != 1
    || *(_BYTE *)(v13 + 65) != 1
    || (v31 = *(unsigned __int16 *)(v13 + 66), (v31 & 1) != 0)
    || (v32 = *(_QWORD *)(v13 + 56)) == 0
    || (v33 = *(_DWORD *)(v13 + 40)) == 0
    || v33 > 1 )
  {
    v7 = -1073741701;
    goto LABEL_75;
  }
  v34 = *(_DWORD *)(v30 + 36);
  if ( v34 > v49 || v31 > v47 )
  {
    v7 = -1073741789;
    a1[4] = v34;
    a1[5] = *(unsigned __int16 *)(v30 + 50);
    v6 = 1;
    v8 = 0;
    goto LABEL_76;
  }
  v43 = *(_DWORD *)(v30 + 36);
  v46 = v43;
  v44 = MmMapIoSpace(v32, SHIDWORD(v32), v34, 1);
  v48 = v44;
  if ( !v44 )
    goto LABEL_29;
  v35 = *(_DWORD *)(v30 + 44);
  *a1 = *(_DWORD *)(v30 + 40);
  a1[1] = v35;
  v36 = v52;
  if ( v50 )
    ProbeForWrite(v52, v49, 4);
  memmove(v36, v44, *(_DWORD *)(v30 + 36));
  if ( *(_WORD *)(v30 + 50) )
  {
    v37 = v51;
    if ( v50 )
      ProbeForWrite(v51, v47, 2);
    memmove(v37, v30 + 52, *(unsigned __int16 *)(v30 + 50));
  }
  v6 = 1;
  v8 = v43;
  v7 = 0;
LABEL_76:
  if ( v6 )
  {
    __dmb(0xBu);
    do
      v38 = __ldrex((unsigned int *)&ExpPlatformBinaryLock);
    while ( v38 == 17 && __strex(0, (unsigned int *)&ExpPlatformBinaryLock) );
    if ( v38 != 17 )
      ExfReleasePushLockShared(&ExpPlatformBinaryLock);
    KeAbPostRelease((unsigned int)&ExpPlatformBinaryLock);
    v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v40 = *(_WORD *)(v39 + 0x134) + 1;
    *(_WORD *)(v39 + 308) = v40;
    if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
      KiCheckForKernelApcDelivery(v39);
  }
  if ( v44 )
    MmUnmapIoSpace(v44, v8);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v7;
}
