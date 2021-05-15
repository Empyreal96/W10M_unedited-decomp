// CmRestoreKey 
 
int __fastcall CmRestoreKey(_DWORD *a1, int a2, int a3)
{
  int v6; // r10
  int v7; // r9
  int v8; // r7
  int v9; // r6
  int v10; // r1
  int v11; // r5
  int v12; // r0
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r8
  int v16; // r0
  unsigned int v17; // r3
  int v18; // r0
  unsigned int v19; // r4
  int v20; // r0
  unsigned int v21; // r8
  __int16 v22; // r3
  char v23; // r4
  int v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r1
  __int16 v27; // r3
  int v28; // r3
  unsigned int v29; // r0
  unsigned int v30; // r2
  unsigned int v31; // r1
  int v32; // r2
  int v33; // r2
  unsigned int v34; // r1
  __int16 v35; // r3
  int v36; // r0
  int v37; // r4
  int v38; // r0
  int v39; // r0
  int v40; // r0
  int v41; // r4
  void (__fastcall *v42)(int, int *); // r3
  _WORD *v43; // r0
  unsigned int v44; // r3
  int *v45; // r10
  unsigned __int16 *v46; // r4
  int v47; // t1
  int v48; // r2
  unsigned int v49; // r2
  unsigned __int16 *v50; // r0
  int v51; // t1
  unsigned __int16 *v52; // r1
  int v53; // r4
  int v54; // r1
  int v55; // r2
  int v56; // r3
  int v57; // r2
  unsigned int v58; // r2
  unsigned int v59; // r4
  int v60; // r1
  unsigned __int16 *v61; // r3
  unsigned __int8 *v62; // r0
  unsigned int v63; // r4
  unsigned int v64; // r1
  __int16 v65; // r3
  int v67; // [sp+4h] [bp-1ACh]
  int v68; // [sp+20h] [bp-190h] BYREF
  unsigned int v69; // [sp+24h] [bp-18Ch] BYREF
  int v70; // [sp+28h] [bp-188h] BYREF
  int v71; // [sp+2Ch] [bp-184h]
  int v72; // [sp+30h] [bp-180h] BYREF
  int v73; // [sp+34h] [bp-17Ch] BYREF
  _DWORD v74[2]; // [sp+38h] [bp-178h] BYREF
  int v75; // [sp+40h] [bp-170h] BYREF
  int v76; // [sp+44h] [bp-16Ch] BYREF
  unsigned int v77[2]; // [sp+48h] [bp-168h] BYREF
  int v78; // [sp+50h] [bp-160h]
  int v79; // [sp+54h] [bp-15Ch] BYREF
  int v80; // [sp+58h] [bp-158h] BYREF
  int v81; // [sp+5Ch] [bp-154h] BYREF
  int v82[2]; // [sp+60h] [bp-150h] BYREF
  int v83; // [sp+68h] [bp-148h] BYREF
  _WORD *v84; // [sp+6Ch] [bp-144h]
  int v85; // [sp+70h] [bp-140h] BYREF
  char v86[284]; // [sp+74h] [bp-13Ch] BYREF

  v69 = a3;
  v70 = 0;
  v83 = -1;
  v84 = 0;
  v79 = -1;
  v80 = -1;
  v73 = 0;
  v74[0] = -1;
  v72 = -1;
  v6 = 0;
  v7 = 0;
  v85 = 0;
  memset(v86, 0, sizeof(v86));
  v8 = a1[1];
  v9 = *(_DWORD *)(v8 + 20);
  v68 = 0;
  v78 = 0;
  CmpTraceHiveRestoreStart(a2, a3);
  if ( (a3 & 2) != 0 && (a3 & 0xFFFFFFFD) != 0 )
  {
    v11 = -1073741811;
    goto LABEL_133;
  }
  v10 = 1;
  if ( a1[7] || a1[8] )
  {
    v11 = -1073741811;
    goto LABEL_117;
  }
  if ( (a3 & 1) != 0 )
  {
    v12 = CmpLoadHiveVolatile(v8, a2, a3 & 2);
LABEL_8:
    v11 = v12;
    goto LABEL_133;
  }
  if ( (a3 & 2) != 0 )
  {
    v12 = CmpRefreshHive(v8, 1);
    goto LABEL_8;
  }
  v82[1] = (int)v82;
  v82[0] = (int)v82;
  v76 = 0;
  v77[0] = 0;
  v77[1] = 0;
  v75 = a2;
  v11 = CmpInitializeHive((int)&v70, 2u, 0, 0, 0, &v75, 0, 16777217, 0, 0, 0, &v85);
  if ( v11 < 0 )
    goto LABEL_133;
  CmpLockRegistryFreezeAware(0);
  CmpLockKcbShared((_DWORD *)v8);
  v13 = *(_DWORD *)(v8 + 24);
  v14 = *(_DWORD *)(v8 + 4);
  v15 = v70;
  v71 = v13;
  if ( (v14 & 0x20000) != 0 )
  {
    v11 = -1073741535;
    goto LABEL_33;
  }
  if ( (void *)v9 == CmpMasterHive )
  {
    v11 = -1073741790;
    goto LABEL_33;
  }
  if ( *(_BYTE *)(v9 + 2532) == 1 )
  {
    v11 = -1073741431;
    goto LABEL_33;
  }
  CmpLockHiveFlusherShared(v9);
  v16 = (*(int (__fastcall **)(int, unsigned int, _DWORD *))(v9 + 4))(v9, v13, v74);
  v7 = v16;
  if ( !v16
    || ((*(_WORD *)(v16 + 2) & 4) == 0 ? (v17 = *(_DWORD *)(v16 + 16)) : (v17 = -1),
        v81 = v13 >> 31,
        v18 = CmpCopyKeyPartial(v15, *(_DWORD *)(*(_DWORD *)(v15 + 32) + 36), v9, v17, 6, v67, v13 >> 31),
        v19 = v18,
        v18 == -1) )
  {
    v11 = -1073741670;
LABEL_32:
    CmpUnlockHiveFlusher(v9);
LABEL_33:
    CmpUnlockKcb((_DWORD *)v8);
    CmpUnlockRegistry();
    CmpDestroyTemporaryHive(v15);
LABEL_119:
    if ( v7 )
      (*(void (__fastcall **)(int, _DWORD *))(v9 + 8))(v9, v74);
    goto LABEL_121;
  }
  v20 = HvReallocateCell(v9, v18, *(unsigned __int16 *)(v7 + 72) + 76, 1, &v73, &v79);
  v6 = v73;
  v21 = v20;
  if ( v20 == -1
    || ((v19 = v20,
         memmove(v73 + 76, v7 + 76, *(unsigned __int16 *)(v7 + 72)),
         *(_WORD *)(v6 + 72) = *(_WORD *)(v7 + 72),
         (*(_WORD *)(v7 + 2) & 0x20) == 0) ? (v22 = *(_WORD *)(v6 + 2) & 0xFFDF) : (v22 = *(_WORD *)(v6 + 2) | 0x20),
        *(_WORD *)(v6 + 2) = v22,
        !CmpCopySyncTree(v70, *(_DWORD *)(*(_DWORD *)(v70 + 32) + 36), v9, v21)) )
  {
    v11 = -1073741670;
    if ( CmpDeleteTree(v9, v19) )
      CmpFreeKeyByCell(v9, v19, 0);
    v15 = v70;
    goto LABEL_32;
  }
  CmpUnlockHiveFlusher(v9);
  CmpUnlockKcb((_DWORD *)v8);
  CmpUnlockRegistry();
  (*(void (__fastcall **)(int, _DWORD *))(v9 + 8))(v9, v74);
  v7 = 0;
  (*(void (__fastcall **)(int, int *))(v9 + 8))(v9, &v79);
  v6 = 0;
  CmpLockRegistryFreezeAware(1);
  v23 = v69;
  while ( 1 )
  {
    if ( v78 )
    {
      __pld(&CmpShutdownRundown);
      v24 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v25 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v25 == v24 && __strex(v24 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v25 != v24 )
        v24 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(_WORD *)(v26 + 0x134) + 1;
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v24);
    }
    v78 = 0;
    v28 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v28 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v29 = CmpShutdownRundown & 0xFFFFFFFE;
    v30 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v31 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v31 == v29 && __strex(v30, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v31 != v29 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    {
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v35 = *(_WORD *)(v34 + 0x134) + 1;
      *(_WORD *)(v34 + 308) = v35;
      if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
        KiCheckForKernelApcDelivery(0);
LABEL_70:
      v11 = -1073741431;
LABEL_63:
      if ( CmpDeleteTree(v9, v21) )
        CmpFreeKeyByCell(v9, v21, 0);
      CmpUnlockRegistry();
      CmpDestroyTemporaryHive(v70);
      goto LABEL_117;
    }
    v32 = *(_DWORD *)(v8 + 4);
    v78 = 1;
    if ( (v32 & 0x20000) != 0 )
      goto LABEL_62;
    if ( v71 != *(_DWORD *)(v8 + 24) )
    {
      v11 = -1073741444;
      goto LABEL_63;
    }
    if ( (v32 & 0x40000) != 0 )
    {
      v11 = -1073740763;
      goto LABEL_63;
    }
    if ( *(_BYTE *)(v9 + 2532) == 1 )
      goto LABEL_70;
    v76 = 0;
    v77[0] = 0;
    if ( CmpTryAcquireIXLockExclusive((_DWORD *)(v8 + 128))
      || (v11 = CmpSnapshotTxOwnerArray(v8 + 128, &v76, v77), v11 < 0) )
    {
      if ( CmpTryAcquireIXLockExclusive((_DWORD *)(v8 + 136)) )
        break;
      v11 = CmpSnapshotTxOwnerArray(v8 + 136, &v76, v77);
      if ( v11 < 0 )
        break;
    }
LABEL_56:
    CmpUnlockRegistry();
    v11 = CmpRollbackTransactionArray(v76, v77[0], 0, (unsigned int *)&v68);
    CmpLockRegistryFreezeAware(1);
    if ( v11 < 0 )
      goto LABEL_63;
  }
  v75 = 0;
  v76 = 0;
  v77[0] = 0;
  if ( CmpSearchForOpenSubKeys(v8, (v23 & 8) != 0, v33, &v75) )
  {
    if ( v75 != -1073741267 )
      goto LABEL_62;
    goto LABEL_56;
  }
  if ( *(_DWORD *)v8 != 1 && (v23 & 8) == 0 )
  {
LABEL_62:
    v11 = -1073741535;
    goto LABEL_63;
  }
  if ( !HvpMarkCellDirty(v9, v21, 0, 0) )
  {
    v11 = -1073741443;
    goto LABEL_63;
  }
  v36 = (*(int (__fastcall **)(int, int, int *))(v9 + 4))(v9, v71, &v79);
  v6 = v36;
  v68 = v36;
  if ( !v36 )
    goto LABEL_76;
  v37 = *(_DWORD *)(v36 + 16);
  if ( (*(_WORD *)(v36 + 2) & 4) != 0 )
  {
    v38 = (*((int (__fastcall **)(void *, int, int *))CmpMasterHive + 1))(CmpMasterHive, v37, &v80);
    if ( !v38 )
      goto LABEL_76;
    *(_DWORD *)(v38 + 28) = v21;
    (*((void (__fastcall **)(void *, int *))CmpMasterHive + 2))(CmpMasterHive, &v80);
    v39 = (*(int (__fastcall **)(int, unsigned int, _DWORD *))(v9 + 4))(v9, v21, v74);
    v7 = v39;
    if ( !v39 )
      goto LABEL_76;
    *(_DWORD *)(v39 + 16) = v37;
    *(_DWORD *)(*(_DWORD *)(v9 + 32) + 36) = v21;
    (*(void (__fastcall **)(int, _DWORD *))(v9 + 8))(v9, v74);
    v7 = 0;
  }
  else
  {
    v40 = (*(int (__fastcall **)(int, int, int *))(v9 + 4))(v9, v37, &v80);
    if ( !v40 )
      goto LABEL_76;
    v42 = *(void (__fastcall **)(int, int *))(v9 + 8);
    v81 = *(_DWORD *)(v40 + 4 * v81 + 28);
    v41 = v81;
    v42(v9, &v80);
    v43 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(v9 + 4))(v9, v41, &v83);
    v84 = v43;
    if ( !v43 )
      goto LABEL_76;
    if ( *v43 == 26994 )
    {
      v44 = (unsigned __int16)v43[1];
      v45 = (int *)(v43 + 2);
    }
    else
    {
      v44 = 1;
      v45 = &v81;
    }
    v73 = 0;
    v69 = v44;
    if ( v44 )
    {
      while ( 1 )
      {
        v46 = (unsigned __int16 *)(*(int (__fastcall **)(int, int, int *))(v9 + 4))(v9, *v45, &v72);
        if ( !v46 )
          break;
        v47 = *v45++;
        if ( !HvpMarkCellDirty(v9, v47, 0, 0) )
        {
          (*(void (__fastcall **)(int, int *))(v9 + 8))(v9, &v72);
          v11 = -1073741443;
          goto LABEL_113;
        }
        v48 = *v46;
        if ( v48 == 26220 || v48 == 26732 )
        {
          v49 = 0;
          if ( v46[1] )
          {
            v52 = v46;
            while ( *((_DWORD *)v52 + 1) != v71 )
            {
              ++v49;
              v52 += 4;
              if ( v49 >= v46[1] )
                goto LABEL_100;
            }
            v61 = &v46[4 * v49];
            goto LABEL_109;
          }
        }
        else
        {
          v49 = 0;
          if ( v46[1] )
          {
            v50 = v46;
            while ( 1 )
            {
              v51 = *((_DWORD *)v50 + 1);
              v50 += 2;
              if ( v51 == v71 )
                break;
              if ( ++v49 >= v46[1] )
                goto LABEL_100;
            }
            v61 = &v46[2 * v49];
LABEL_109:
            *((_DWORD *)v61 + 1) = v21;
            (*(void (__fastcall **)(int, int *))(v9 + 8))(v9, &v72);
            goto LABEL_101;
          }
        }
LABEL_100:
        (*(void (__fastcall **)(int, int *, unsigned int))(v9 + 8))(v9, &v72, v49);
        if ( ++v73 >= v69 )
          goto LABEL_101;
      }
      v11 = -1073741670;
LABEL_113:
      v6 = v68;
      goto LABEL_63;
    }
LABEL_101:
    v6 = v68;
  }
  *(_DWORD *)(v8 + 24) = v21;
  CmpCleanUpKcbValueCache(v8);
  v69 = -1;
  v53 = (*(int (__fastcall **)(_DWORD, _DWORD, unsigned int *))(*(_DWORD *)(v8 + 20) + 4))(
          *(_DWORD *)(v8 + 20),
          *(_DWORD *)(v8 + 24),
          &v69);
  if ( !v53 )
  {
LABEL_76:
    v11 = -1073741670;
    goto LABEL_63;
  }
  *(_DWORD *)(v8 + 52) = *(_DWORD *)(v53 + 36);
  *(_DWORD *)(v8 + 56) = *(_DWORD *)(v53 + 40);
  *(_WORD *)(v8 + 106) = *(_WORD *)(v53 + 2);
  CmpAssignSecurityToKcb(v8, *(_DWORD *)(v53 + 44), 0, 0);
  CmpCleanUpSubKeyInfo((_DWORD *)v8, v54, v55, v56);
  v57 = *(_DWORD *)(v8 + 104);
  *(_DWORD *)(v8 + 88) = *(_DWORD *)(v53 + 4);
  *(_DWORD *)(v8 + 92) = *(_DWORD *)(v53 + 8);
  *(_WORD *)(v8 + 96) = *(_DWORD *)(v53 + 52);
  *(_WORD *)(v8 + 98) = *(_DWORD *)(v53 + 60);
  *(_DWORD *)(v8 + 100) = *(_DWORD *)(v53 + 64);
  v58 = v57 & 0xFFFFFFF0 | *(_WORD *)(v53 + 54) & 0xF;
  *(_DWORD *)(v8 + 104) = v58;
  *(_DWORD *)(v8 + 104) = ((unsigned __int8)*(_WORD *)(v53 + 54) ^ (unsigned __int8)v58) & 0xF0 ^ v58;
  *(_BYTE *)(v8 + 105) = *(_BYTE *)(v53 + 55);
  (*(void (__fastcall **)(_DWORD, unsigned int *))(*(_DWORD *)(v8 + 20) + 8))(*(_DWORD *)(v8 + 20), &v69);
  v59 = v71;
  v60 = v71;
  *(_WORD *)(v8 + 4) = 64;
  if ( CmpDeleteTree(v9, v60) )
    CmpFreeKeyByCell(v9, v59, 0);
  CmpReportNotify(v8, *(void (__fastcall ***)(void *, int *))(v8 + 20), *(_DWORD *)(v8 + 24), 0, 1, (int)v82);
  if ( !CmpProfileLoaded )
  {
    CmpProfileLoaded = 1;
    CmpGlobalQuotaAllowed = CmpGlobalQuota;
  }
  CmpUnlockRegistry();
  CmpDestroyTemporaryHive(v70);
  CmpSignalDeferredPosts((unsigned int)v82);
LABEL_117:
  if ( v84 )
  {
    (*(void (__fastcall **)(int, int *))(v9 + 8))(v9, &v83);
    goto LABEL_119;
  }
LABEL_121:
  if ( v6 )
    (*(void (__fastcall **)(int, int *))(v9 + 8))(v9, &v79);
  if ( v78 )
  {
    v62 = (unsigned __int8 *)&CmpShutdownRundown;
    __pld(&CmpShutdownRundown);
    v63 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v64 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v64 == v63 && __strex(v63 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v64 != v63 )
      v62 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v65 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v65;
    if ( !v65 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery((int)v62);
  }
LABEL_133:
  CmpTraceHiveRestoreStop(v11, v10);
  return v11;
}
