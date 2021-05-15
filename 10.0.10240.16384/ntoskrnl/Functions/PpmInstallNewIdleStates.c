// PpmInstallNewIdleStates 
 
int __fastcall PpmInstallNewIdleStates(_DWORD *a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r9
  unsigned int v6; // r6
  int v8; // r8
  int v9; // r2
  int v10; // r1
  int v11; // r10
  _BYTE *v12; // r0
  _BYTE *v13; // r4
  char v14; // r3
  int v15; // r3
  unsigned int v16; // r0
  _BYTE *v17; // lr
  int *v18; // r1
  _BYTE *v19; // r2
  _DWORD *v20; // r5
  _DWORD *v21; // r5
  unsigned int v22; // r2
  int v23; // r9
  unsigned int v24; // r3
  unsigned int *v25; // r6
  unsigned int v26; // r8
  unsigned int *v27; // lr
  __int64 v28; // kr00_8
  int v29; // r0
  int v30; // r4
  int v31; // [sp+0h] [bp-50h]
  unsigned int v33; // [sp+Ch] [bp-44h]
  unsigned int v34; // [sp+10h] [bp-40h]
  unsigned int v36; // [sp+18h] [bp-38h]
  unsigned int v37; // [sp+1Ch] [bp-34h]
  __int16 v38[2]; // [sp+20h] [bp-30h] BYREF
  int v39; // [sp+24h] [bp-2Ch]
  int v40; // [sp+28h] [bp-28h]

  v3 = a1[736];
  v5 = 0;
  if ( a3 == 1 )
  {
    if ( v3 )
      return 0;
  }
  else if ( v3 )
  {
    v31 = *(unsigned __int8 *)(v3 + 1);
    PpmUpdateProcessorIdleAccounting(a1 + 736);
    goto LABEL_4;
  }
  v31 = 0;
LABEL_4:
  v6 = *(_DWORD *)(a2 + 60);
  if ( !v6 )
    return sub_5523D4();
  v8 = 0;
  if ( *(_BYTE *)(a2 + 14) == 1 )
  {
    v9 = a2;
    v10 = *(_DWORD *)(a2 + 60);
    do
    {
      if ( (*(_DWORD *)(v9 + 64) & 0x100) == 0 )
        ++v8;
      v9 += 24;
      --v10;
    }
    while ( v10 );
  }
  v33 = ((v6 << 6) + 255) & 0xFFFFFFFC;
  v37 = (v33 + 8 * *(_DWORD *)(a2 + 56) + 3) & 0xFFFFFFFC;
  v36 = (v37 + 16 * v8 + 7) & 0xFFFFFFF8;
  v34 = (v36 + 984 * v6 + 47) & 0xFFFFFFF8;
  v11 = (v34 + 4 * v6 + 11) & 0xFFFFFFFC;
  if ( PpmIdleVetoList )
    v11 += 16 * v6 * *(_DWORD *)PpmIdleVetoList;
  v12 = (_BYTE *)ExAllocatePoolWithTag(512, v11);
  v13 = v12;
  if ( !v12 )
    return -1073741670;
  memset(v12, 0, v11);
  *((_DWORD *)v13 + 8) = a3;
  *v13 = *(_BYTE *)(a2 + 14);
  v14 = *(_BYTE *)(a2 + 12);
  *((_DWORD *)v13 + 12) = 0;
  *((_DWORD *)v13 + 7) = v6;
  v13[2] = v14;
  *((_DWORD *)v13 + 20) = *(_DWORD *)(a2 + 16);
  *((_DWORD *)v13 + 23) = *(_DWORD *)(a2 + 24);
  *((_DWORD *)v13 + 24) = *(_DWORD *)(a2 + 28);
  *((_DWORD *)v13 + 25) = *(_DWORD *)(a2 + 32);
  *((_DWORD *)v13 + 22) = *(_DWORD *)(a2 + 40);
  *((_DWORD *)v13 + 21) = *(_DWORD *)(a2 + 36);
  *((_DWORD *)v13 + 26) = *(_DWORD *)(a2 + 44);
  *((_DWORD *)v13 + 27) = *(_DWORD *)(a2 + 20);
  *((_DWORD *)v13 + 28) = *(_DWORD *)(a2 + 48);
  *((_DWORD *)v13 + 29) = *(_DWORD *)(a2 + 52);
  *((_DWORD *)v13 + 30) = *(_DWORD *)(a2 + 8);
  v15 = *(_DWORD *)(a2 + 56);
  *((_DWORD *)v13 + 59) = 1;
  *((_DWORD *)v13 + 44) = v15;
  *((_DWORD *)v13 + 46) = &v13[v33];
  *((_DWORD *)v13 + 62) = v13 + 244;
  if ( v8 )
  {
    *((_DWORD *)v13 + 55) = v8;
    *((_DWORD *)v13 + 56) = &v13[v37];
    v5 = (int)&v13[16 * v8 + v37];
  }
  *((_WORD *)v13 + 28) = 1;
  *((_WORD *)v13 + 29) = 1;
  *((_DWORD *)v13 + 15) = 0;
  *((_DWORD *)v13 + 16) = 0;
  v16 = 0;
  v17 = &v13[(v34 + 4 * v6 + 11) & 0xFFFFFFFC];
  v18 = (int *)(a2 + 64);
  v19 = v13 + 252;
  v20 = (_DWORD *)PpmIdleVetoList;
  do
  {
    *((_DWORD *)v19 + 3) = v18[4];
    *((_DWORD *)v19 + 4) = v18[5];
    *(_WORD *)v19 = 1;
    *((_WORD *)v19 + 1) = 1;
    *((_DWORD *)v19 + 1) = 0;
    *((_DWORD *)v19 + 2) = 0;
    v19[56] = ((unsigned int)*v18 >> 3) & 0xF;
    v19[58] = *v18 & 1;
    v19[59] = (*v18 & 4) != 0;
    v19[60] = (*v18 & 2) != 0;
    if ( *v18 < 0 )
    {
      *((_DWORD *)v19 + 8) = 1;
      v19[57] = 1;
    }
    v19[61] = (*v18 & 0x80) != 0;
    v19[62] = BYTE1(*v18) & 1;
    v19[63] = (*v18 & 0x40000000) != 0;
    *((_DWORD *)v19 + 5) = v18[1];
    *((_DWORD *)v19 + 7) = v18[3];
    *((_DWORD *)v19 + 6) = v18[2];
    *((_DWORD *)v19 + 10) = v19 + 40;
    *((_DWORD *)v19 + 11) = v19 + 40;
    if ( v20 )
    {
      *((_DWORD *)v19 + 12) = *v20;
      *((_DWORD *)v19 + 13) = v17;
      v17 += 16 * *v20;
    }
    if ( v5 && (*v18 & 0x100) == 0 )
    {
      v5 -= 16;
      *(_BYTE *)(v5 + 1) = 1;
      *(_DWORD *)(v5 + 4) = v16;
    }
    ++v16;
    v19 += 64;
    v18 += 6;
  }
  while ( v16 < v6 );
  *((_DWORD *)v13 + 53) = &v13[v34];
  v21 = &v13[v36];
  *(_DWORD *)&v13[v36] = v6;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&PpmIdleVetoLock);
  }
  else
  {
    do
      v22 = __ldrex((unsigned int *)&PpmIdleVetoLock);
    while ( __strex(1u, (unsigned int *)&PpmIdleVetoLock) );
    __dmb(0xBu);
    if ( v22 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PpmIdleVetoLock);
  }
  v23 = a1[736];
  a1[736] = v13;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PpmIdleVetoLock);
  }
  else
  {
    __dmb(0xBu);
    PpmIdleVetoLock = 0;
  }
  if ( v31 )
    *((_DWORD *)v13 + 6) = *(_DWORD *)(v23 + 24);
  if ( v23 && (v24 = *(_DWORD *)(v23 + 12), v24 < v6) )
    *((_DWORD *)v13 + 3) = v24;
  else
    *((_DWORD *)v13 + 3) = 0;
  v13[1] = v31;
  v25 = (unsigned int *)a1[737];
  a1[737] = v21;
  if ( v25 )
  {
    v26 = 0;
    v21[6] = v25[6];
    v21[7] = v25[7];
    if ( *v25 )
    {
      v27 = v25;
      do
      {
        v28 = *((_QWORD *)v27 + 5);
        ++v26;
        v27 += 246;
        *((_QWORD *)v21 + 3) += v28;
      }
      while ( v26 < *v25 );
    }
  }
  else
  {
    *((_QWORD *)v21 + 3) = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(a1[3] + 404);
  }
  PpmResetIdlePolicy(a1 + 736);
  if ( v25 )
    v21[2] = v25[2] + 1;
  v38[0] = 1;
  v38[1] = 1;
  v39 = 0;
  v40 = 1 << a1[5];
  v29 = PpmDeepestHardwareIdleState(v13);
  off_6179FC(v29, v38);
  if ( *((_DWORD *)v13 + 8) != 1 && *v13 == 1 )
    PpmIdleCheckIdleDurationExpiration = 1;
  v30 = 0;
  if ( v23 )
    ExFreePoolWithTag(v23, 1766674512);
  return v30;
}
