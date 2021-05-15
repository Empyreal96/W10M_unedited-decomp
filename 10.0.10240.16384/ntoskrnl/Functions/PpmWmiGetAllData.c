// PpmWmiGetAllData 
 
int __fastcall PpmWmiGetAllData(_DWORD *a1, unsigned int a2, unsigned int a3, int *a4, int *a5, char a6)
{
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r9
  int v14; // r8
  int v15; // r3
  unsigned int v16; // r4
  int v17; // r5
  int v18; // r4
  int v19; // r3
  char *v20; // r4
  int v21; // r6
  int v22; // lr
  int v23; // r8
  char *v24; // r0
  int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r2
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  int v32; // [sp+8h] [bp-30h]
  unsigned int v34; // [sp+10h] [bp-28h]
  _DWORD *v35; // [sp+14h] [bp-24h]

  v34 = a2;
  v35 = a1 - 736;
  if ( !memcmp((unsigned int)PPM_IDLESTATES_DATA_GUID, a2, 16) )
  {
    v32 = 1;
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
    while ( !v12 && __strex(0x11u, (unsigned int *)&PpmIdlePolicyLock) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(&PpmIdlePolicyLock, v10, (unsigned int)&PpmIdlePolicyLock);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
  }
  else
  {
    v32 = 0;
  }
  v13 = a1[64];
  if ( !memcmp((unsigned int)PPM_PERFSTATES_DATA_GUID, a2, 16) && v13 )
  {
    v14 = 80;
  }
  else if ( !memcmp((unsigned int)PPM_IDLESTATES_DATA_GUID, a2, 16) && *a1 )
  {
    v14 = 32 * *(_DWORD *)(*a1 + 28) + 56;
  }
  else
  {
    if ( memcmp((unsigned int)PPM_PERFMON_PERFSTATE_GUID, a2, 16) || !v13 )
    {
      v17 = 0;
      v18 = -1073741808;
      goto LABEL_43;
    }
    v14 = 12;
  }
  if ( a6 )
    v15 = 72;
  else
    v15 = 64;
  v16 = (v15 + 7) & 0xFFFFFFF8;
  v17 = v16 + v14;
  if ( a3 >= v16 + v14 )
  {
    *a4 = v17;
    if ( a6 )
    {
      KeQuerySystemTime(a4 + 4);
      v19 = a4[11];
      a4[12] = v16;
      a4[11] = v19 | 0x10;
      a4[13] = 1;
    }
    else
    {
      a4[14] = v16;
    }
    v20 = (char *)a4 + v16;
    a4[15] = v14;
    memset(v20, 0, v14);
    if ( !memcmp((unsigned int)PPM_PERFSTATES_DATA_GUID, v34, 16) && v13 )
    {
      *(_DWORD *)v20 = 0;
      *((_DWORD *)v20 + 1) = *(_DWORD *)(v13 + 80);
      *((_DWORD *)v20 + 2) = 0;
      v20[28] = 100;
      *((_DWORD *)v20 + 3) = 0;
      *((_DWORD *)v20 + 4) = 0;
      *((_DWORD *)v20 + 5) = 0;
      v20[29] = *(_BYTE *)(v13 + 112);
      *((_DWORD *)v20 + 8) = PpmCurrentProfile[44 * dword_61EC0C + 13];
      *((_DWORD *)v20 + 10) = *(_DWORD *)(v13 + 20);
      *((_DWORD *)v20 + 11) = 0;
      *((_DWORD *)v20 + 16) = 1;
    }
    else if ( !memcmp((unsigned int)PPM_IDLESTATES_DATA_GUID, v34, 16) && *a1 )
    {
      *((_DWORD *)v20 + 1) = *(_DWORD *)(*a1 + 28);
      *((_DWORD *)v20 + 2) = *(_DWORD *)(*a1 + 12);
      *((_DWORD *)v20 + 3) = *(_DWORD *)(*a1 + 20);
      *((_DWORD *)v20 + 4) = *(a1 - 474);
      *((_DWORD *)v20 + 5) = 0;
      v21 = *a1;
      v22 = *(_DWORD *)(*a1 + 28);
      if ( v22 )
      {
        v23 = 0;
        v24 = v20 + 24;
        do
        {
          *(_DWORD *)v24 = *(_DWORD *)(*a1 + v23 + 272) / 0xAu;
          *((_DWORD *)v24 + 1) = *(_DWORD *)(*a1 + v23 + 280);
          *((_DWORD *)v24 + 2) = *(_DWORD *)(v21 + 164);
          v24[12] = *(_BYTE *)(v21 + 168);
          v24[13] = *(_BYTE *)(v21 + 169);
          v24[14] = *(_BYTE *)(*a1 + v23 + 308);
          *((_DWORD *)v24 + 4) = *(_DWORD *)(*a1 + v23 + 284);
          *((_DWORD *)v24 + 5) = 0;
          *((_DWORD *)v24 + 6) = 1;
          v24 += 32;
          --v22;
          v23 += 64;
        }
        while ( v22 );
      }
    }
    else if ( !memcmp((unsigned int)PPM_PERFMON_PERFSTATE_GUID, v34, 16) && v13 )
    {
      PpmPerfGetCurrentState(v35, v20, 0, (_DWORD *)v20 + 2, (int *)v20 + 1, 0);
    }
  }
  else
  {
    if ( a3 < 0x38 )
    {
      v18 = -1073741789;
      goto LABEL_43;
    }
    a4[11] = 32;
    a4[12] = v17;
    v17 = 56;
  }
  v18 = 0;
LABEL_43:
  if ( v32 )
  {
    dword_61E89C = 0;
    __pld(&PpmIdlePolicyLock);
    v25 = PpmIdlePolicyLock;
    v26 = PpmIdlePolicyLock - 16;
    if ( (PpmIdlePolicyLock & 0xFFFFFFF0) <= 0x10 )
      v26 = 0;
    if ( (PpmIdlePolicyLock & 2) != 0 )
      goto LABEL_51;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
    while ( v27 == v25 && __strex(v26, (unsigned int *)&PpmIdlePolicyLock) );
    if ( v27 != v25 )
LABEL_51:
      ExfReleasePushLock(&PpmIdlePolicyLock, v25);
    v28 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v30 = *(_WORD *)(v29 + 0x134) + 1;
    *(_WORD *)(v29 + 308) = v30;
    if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
      KiCheckForKernelApcDelivery(v28);
  }
  if ( v18 < 0 )
    *a5 = 0;
  else
    *a5 = v17;
  return v18;
}
