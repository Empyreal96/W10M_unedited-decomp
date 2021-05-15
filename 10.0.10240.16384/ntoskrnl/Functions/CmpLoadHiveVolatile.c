// CmpLoadHiveVolatile 
 
int __fastcall CmpLoadHiveVolatile(int a1, int a2)
{
  unsigned __int16 *v4; // r10
  int v5; // r3
  unsigned int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1
  __int16 v10; // r3
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r4
  unsigned int v14; // r1
  bool v15; // zf
  unsigned int v16; // r1
  _BYTE *v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r1
  __int16 v21; // r3
  _DWORD *v22; // r3
  int v23; // r7
  _DWORD *v24; // r6
  int v25; // r0
  int v26; // r4
  int v27; // r6
  __int16 v28; // r2
  int v29; // r4
  unsigned int v30; // r1
  __int16 v31; // r3
  int v33; // r2
  int v34; // r3
  __int16 v35; // r2
  int v36; // r0
  int v37; // r8
  unsigned int v38; // r2
  void ***v39; // r0
  int v40; // r1
  unsigned int v41; // r0
  unsigned int v42; // r2
  int v43; // [sp+4h] [bp-19Ch]
  unsigned __int16 v44; // [sp+20h] [bp-180h] BYREF
  unsigned __int16 v45; // [sp+22h] [bp-17Eh]
  int v46; // [sp+24h] [bp-17Ch]
  _DWORD *v47; // [sp+28h] [bp-178h] BYREF
  int v48; // [sp+2Ch] [bp-174h] BYREF
  int v49; // [sp+30h] [bp-170h] BYREF
  int v50; // [sp+34h] [bp-16Ch]
  int v51; // [sp+38h] [bp-168h]
  int v52; // [sp+3Ch] [bp-164h]
  int v53; // [sp+40h] [bp-160h] BYREF
  char v54[284]; // [sp+44h] [bp-15Ch] BYREF
  char v55[16]; // [sp+160h] [bp-40h] BYREF
  char v56[48]; // [sp+170h] [bp-30h] BYREF

  v48 = -1;
  v53 = 0;
  v4 = 0;
  memset(v54, 0, sizeof(v54));
  v5 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v5 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v6 = CmpShutdownRundown & 0xFFFFFFFE;
  v7 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v8 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v8 != v6 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741431;
  }
  v12 = CmpUuidCreate((int)v56);
  v11 = v12;
  if ( v12 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v13 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v14 == v13 && __strex(v13 - 2, (unsigned int *)&CmpShutdownRundown) );
    v15 = v14 == v13;
    goto LABEL_55;
  }
  v11 = CmpUuidCreate((int)v55);
  if ( v11 < 0 )
    goto LABEL_17;
  v17 = *(_BYTE **)(a1 + 20);
  if ( v17 == CmpMasterHive )
  {
    v50 = 0;
    v51 = 0;
    v52 = 0;
    v49 = a2;
    v11 = CmpInitializeHive((int)&v47, 2u, 0, 0, 0, &v49, 0, 16777217, 0, 0, 0, &v53);
    if ( v11 >= 0 )
    {
      v11 = CmpInitializeHive((int)&v49, 0, 1, 0, 0, 0, 0, 0x1000000, (int)v56, (int)v55, 0, &v53);
      v22 = v47;
      if ( v11 >= 0 )
      {
        CmpLockRegistryExclusive();
        v23 = v49;
        if ( (*(_DWORD *)(a1 + 4) & 0x20000) != 0 )
        {
          v11 = -1073741444;
        }
        else if ( v17[2532] == 1 )
        {
          v11 = -1073741431;
        }
        else
        {
          v24 = v47;
          v25 = CmpCopyKeyPartial((int)v47, *(_DWORD *)(v47[8] + 36), v49, 0xFFFFFFFF, 2, v43, 1);
          v26 = v25;
          if ( v25 != -1 )
          {
            *(_DWORD *)(*(_DWORD *)(v23 + 32) + 36) = v25;
            if ( CmpCopySyncTree((int)v24, *(_DWORD *)(v24[8] + 36), v23, v25) )
            {
              v27 = (*(int (__fastcall **)(int, int, int *))(v23 + 4))(v23, v26, &v48);
              if ( v27 )
              {
                v4 = (unsigned __int16 *)CmpConstructName(a1);
                if ( (*(_WORD *)(v27 + 2) & 0x20) != 0 )
                  v28 = 2 * *(_WORD *)(v27 + 72);
                else
                  v28 = *(_WORD *)(v27 + 72);
                v29 = (unsigned __int16)(*v4 + v28 + 2);
                v46 = ExAllocatePoolWithTag(1, v29, 538987843);
                if ( v46 )
                {
                  v45 = v29;
                  v44 = v29;
                  RtlCopyUnicodeString(&v44, v4);
                  RtlAppendUnicodeToString(&v44, (int)L"\\", v33, v34);
                  if ( (*(_WORD *)(v27 + 2) & 0x20) != 0 )
                  {
                    CmpCopyCompressedName(
                      (_WORD *)(v46 + 2 * (v44 >> 1)),
                      v45 - v44,
                      v27 + 76,
                      (unsigned __int16)(2 * *(_WORD *)(v27 + 72)));
                    if ( (*(_WORD *)(v27 + 2) & 0x20) != 0 )
                      v35 = 2 * *(_WORD *)(v27 + 72);
                    else
                      v35 = *(_WORD *)(v27 + 72);
                    v44 += v35;
                  }
                  else
                  {
                    v50 = v27 + 76;
                    HIWORD(v49) = *(_WORD *)(v27 + 72);
                    LOWORD(v49) = HIWORD(v49);
                    RtlAppendUnicodeStringToString(&v44, (unsigned __int16 *)&v49);
                  }
                  (*(void (__fastcall **)(int, int *))(v23 + 8))(v23, &v48);
                  v11 = CmpLinkHiveToMaster(&v44, 0, v23, 0, 512, 0, 0, 0, 1);
                  if ( v11 >= 0 )
                  {
                    CmpAddToHiveFileList(v23);
                    v36 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
                    v37 = v36;
                    do
                      v38 = __ldrex((unsigned __int8 *)&CmpHiveListHeadLock);
                    while ( __strex(v38 | 1, (unsigned __int8 *)&CmpHiveListHeadLock) );
                    __dmb(0xBu);
                    if ( (v38 & 1) != 0 )
                      ExfAcquirePushLockExclusiveEx(&CmpHiveListHeadLock, v36, (unsigned int)&CmpHiveListHeadLock);
                    if ( v37 )
                      *(_BYTE *)(v37 + 14) |= 1u;
                    v39 = (void ***)off_92078C;
                    *(_DWORD *)(v23 + 1808) = &CmpHiveListHead;
                    *(_DWORD *)(v23 + 1812) = v39;
                    if ( *v39 != &CmpHiveListHead )
                      __fastfail(3u);
                    *v39 = (void **)(v23 + 1808);
                    __pld(&CmpHiveListHeadLock);
                    off_92078C = (void *)(v23 + 1808);
                    v40 = CmpHiveListHeadLock;
                    if ( (CmpHiveListHeadLock & 0xFFFFFFF0) <= 0x10 )
                      v41 = 0;
                    else
                      v41 = CmpHiveListHeadLock - 16;
                    if ( (CmpHiveListHeadLock & 2) != 0 )
                      goto LABEL_85;
                    __dmb(0xBu);
                    do
                      v42 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
                    while ( v42 == v40 && __strex(v41, (unsigned int *)&CmpHiveListHeadLock) );
                    if ( v42 != v40 )
LABEL_85:
                      ExfReleasePushLock(&CmpHiveListHeadLock, v40);
                    KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
                    if ( !CmpProfileLoaded )
                    {
                      CmpProfileLoaded = 1;
                      CmpGlobalQuotaAllowed = CmpGlobalQuota;
                    }
                  }
                  CmpUnlockRegistry();
                  if ( v11 < 0 )
                    CmpDestroyTemporaryHive((_DWORD *)v23);
                  CmpDestroyTemporaryHive(v47);
                  ExFreePoolWithTag(v46);
                  ExFreePoolWithTag((unsigned int)v4);
                  __pld(&CmpShutdownRundown);
                  v12 = CmpShutdownRundown & 0xFFFFFFFE;
                  goto LABEL_18;
                }
                (*(void (__fastcall **)(int, int *))(v23 + 8))(v23, &v48);
              }
            }
          }
          v11 = -1073741670;
        }
        CmpUnlockRegistry();
        CmpDestroyTemporaryHive((_DWORD *)v23);
        v22 = v47;
      }
      CmpDestroyTemporaryHive(v22);
      if ( v4 )
        ExFreePoolWithTag((unsigned int)v4);
      __pld(&CmpShutdownRundown);
      v12 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v16 == v12 && __strex(v12 - 2, (unsigned int *)&CmpShutdownRundown) );
      goto LABEL_54;
    }
LABEL_17:
    __pld(&CmpShutdownRundown);
    v12 = CmpShutdownRundown & 0xFFFFFFFE;
LABEL_18:
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v16 == v12 && __strex(v12 - 2, (unsigned int *)&CmpShutdownRundown) );
LABEL_54:
    v15 = v16 == v12;
LABEL_55:
    if ( !v15 )
      v12 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v31 = *(_WORD *)(v30 + 0x134) + 1;
    *(_WORD *)(v30 + 308) = v31;
    if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
      KiCheckForKernelApcDelivery(v12);
    return v11;
  }
  __pld(&CmpShutdownRundown);
  v18 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v19 == v18 && __strex(v18 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v19 != v18 )
    v18 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return -1073741811;
}
