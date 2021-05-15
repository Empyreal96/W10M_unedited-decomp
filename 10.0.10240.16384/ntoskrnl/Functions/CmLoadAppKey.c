// CmLoadAppKey 
 
int __fastcall CmLoadAppKey(int a1, int a2, int a3, int a4, int a5, int *a6, _DWORD *a7)
{
  _DWORD *v7; // r3
  __int16 v8; // r5
  int v9; // r6
  unsigned int v10; // r4
  int v11; // r10
  int v12; // r3
  unsigned int v13; // r0
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r0
  int v18; // r5
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  unsigned int v23; // r1
  int v24; // r3
  unsigned int v25; // r6
  int v26; // r4
  int v27; // r0
  int v28; // r0
  int v29; // r0
  int v30; // r10
  int v31; // r3
  int i; // r0
  int v33; // r4
  unsigned int v34; // r3
  int v35; // r0
  int v36; // r2
  int v37; // r0
  int v38; // r0
  int v39; // r0
  int v40; // r0
  unsigned int v41; // r2
  int v42; // r0
  int v43; // r4
  unsigned int v44; // r2
  int v45; // r0
  int **v46; // r1
  int v47; // r0
  int v48; // r8
  char v49; // r3
  unsigned int v50; // r2
  int v51; // r0
  int v52; // r4
  unsigned int v53; // r2
  int v54; // r4
  int v55; // r5
  int v57; // r1
  unsigned int v58; // r0
  unsigned int v59; // r2
  int v60; // r0
  unsigned int v61; // r1
  int v62; // r3
  unsigned int v63; // r1
  unsigned int v64; // r4
  unsigned int v65; // r1
  unsigned int v66; // r1
  int v67; // r3
  unsigned int v69; // r1
  __int16 v70; // r3
  int **v71; // r1
  int **v72; // r4
  unsigned int *v73; // r5
  unsigned int v74; // r0
  unsigned int v75; // r1
  int v76; // r1
  unsigned int v77; // r0
  unsigned int v78; // r2
  int v79; // r0
  unsigned int v80; // r1
  __int16 v81; // r3
  unsigned int v82; // r4
  unsigned int v83; // r1
  int v84; // r0
  int v85; // r0
  int v86; // r0
  int v87; // r0
  int v88; // r0
  int v89; // r3
  int v90; // r0
  int v91; // r0
  int v92; // r0
  int v93; // r0
  int v94; // r0
  int *v95; // r1
  int **v96; // r4
  int *v97; // r0
  int **v98; // r2
  unsigned __int8 v99[4]; // [sp+10h] [bp-A0h] BYREF
  unsigned int v100; // [sp+14h] [bp-9Ch] BYREF
  unsigned __int8 v101[4]; // [sp+18h] [bp-98h] BYREF
  int v102; // [sp+1Ch] [bp-94h]
  int v103; // [sp+20h] [bp-90h] BYREF
  int v104; // [sp+24h] [bp-8Ch]
  int v105; // [sp+28h] [bp-88h]
  int v106; // [sp+2Ch] [bp-84h]
  int v107; // [sp+30h] [bp-80h]
  _DWORD *v108; // [sp+34h] [bp-7Ch]
  int v109; // [sp+38h] [bp-78h]
  int v110; // [sp+3Ch] [bp-74h]
  int v111; // [sp+40h] [bp-70h]
  int v112; // [sp+44h] [bp-6Ch] BYREF
  _DWORD *v113; // [sp+48h] [bp-68h] BYREF
  int v114; // [sp+4Ch] [bp-64h]
  int *v115; // [sp+50h] [bp-60h] BYREF
  int **v116; // [sp+54h] [bp-5Ch]
  int *v117; // [sp+58h] [bp-58h] BYREF
  int **v118; // [sp+5Ch] [bp-54h]
  int v119; // [sp+60h] [bp-50h]
  char v120; // [sp+64h] [bp-4Ch]
  char v121[16]; // [sp+68h] [bp-48h] BYREF
  unsigned int v122; // [sp+78h] [bp-38h] BYREF
  int v123; // [sp+7Ch] [bp-34h] BYREF
  unsigned int v124; // [sp+80h] [bp-30h] BYREF
  char v125[4]; // [sp+84h] [bp-2Ch] BYREF
  int v126; // [sp+88h] [bp-28h]
  int v127; // [sp+8Ch] [bp-24h] BYREF
  int v128; // [sp+90h] [bp-20h]

  v126 = a4;
  v7 = (_DWORD *)a1;
  v8 = a3;
  v9 = a2;
  v10 = **(unsigned __int16 **)(a1 + 8);
  v106 = a2;
  v107 = a3;
  v108 = (_DWORD *)a1;
  v109 = 0;
  v100 = 0;
  v11 = 0;
  v102 = 0;
  v110 = 0;
  v111 = 0;
  v104 = 0;
  if ( v10 >= 2 )
  {
    if ( v10 >> 1 )
    {
      if ( *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 4) + 2 * (v10 >> 1) - 2) == 92 )
        return sub_7C2F70();
      v7 = v108;
      v9 = v106;
      v11 = 0;
    }
    v8 = v107;
  }
  if ( *(unsigned __int16 *)v7[2] < 2u )
    return -1073741811;
  v12 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v12 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v13 = CmpShutdownRundown & 0xFFFFFFFE;
  v14 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v15 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v15 == v13 && __strex(v14, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v15 != v13 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v69 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v70 = *(_WORD *)(v69 + 0x134) + 1;
    *(_WORD *)(v69 + 308) = v70;
    if ( !v70 && *(_DWORD *)(v69 + 100) != v69 + 100 && !*(_WORD *)(v69 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741431;
  }
  v16 = 50397185;
  v128 = v8 & 0x20;
  v105 = 50397185;
  if ( (v8 & 0x20) != 0 )
  {
    v16 = 117506049;
    v105 = 117506049;
  }
  if ( (v8 & 0x80) != 0 )
  {
    v16 |= 0x8000000u;
    v105 = v16;
  }
  if ( (v8 & 0x200) != 0 )
    v105 = v16 | 0x10000000;
  v114 = 0;
  if ( (v8 & 0x2000) != 0 )
  {
    v114 = 1;
    v110 = 1;
  }
  v17 = CmpOpenHiveFile(v9, 0, &v103, v125, 8, 0, 0, &v100);
  v18 = v17;
  if ( v17 == -1073741772 )
  {
    v49 = 1;
    v109 = 1;
    v119 = v9;
  }
  else
  {
    if ( v17 < 0 )
    {
      v25 = v100;
      goto LABEL_98;
    }
    v47 = ObReferenceObjectByHandle(v103, 0, *(_DWORD *)CmIoFileObjectType, 0, &v123, 0);
    v48 = v123;
    v18 = v47;
    v104 = v123;
    v17 = ZwClose();
    if ( v18 < 0 )
    {
      v25 = v100;
      goto LABEL_96;
    }
    v119 = *(_DWORD *)(v48 + 20);
    v49 = 0;
  }
  v120 = v49;
  KeInitializeEvent((int)v121, 0, 0);
  v122 = 0;
  v118 = &v117;
  v117 = (int *)&v117;
  v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v50 + 308);
  v51 = KeAbPreAcquire((unsigned int)&CmpAppHiveLoadListLock, 0, 0);
  v52 = v51;
  do
    v53 = __ldrex((unsigned __int8 *)&CmpAppHiveLoadListLock);
  while ( __strex(v53 | 1, (unsigned __int8 *)&CmpAppHiveLoadListLock) );
  __dmb(0xBu);
  if ( (v53 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpAppHiveLoadListLock, v51, (unsigned int)&CmpAppHiveLoadListLock);
  if ( v52 )
    *(_BYTE *)(v52 + 14) |= 1u;
  v54 = CmpAppHiveLoadList;
  if ( (int *)CmpAppHiveLoadList == &CmpAppHiveLoadList )
  {
LABEL_166:
    v115 = &CmpAppHiveLoadList;
    v116 = (int **)dword_63246C;
    if ( *(int **)dword_63246C != &CmpAppHiveLoadList )
      __fastfail(3u);
    *(_DWORD *)dword_63246C = &v115;
    __pld(&CmpAppHiveLoadListLock);
    dword_63246C = (int)&v115;
    v19 = CmpAppHiveLoadListLock;
    if ( (CmpAppHiveLoadListLock & 0xFFFFFFF0) > 0x10 )
      v20 = CmpAppHiveLoadListLock - 16;
    else
      v20 = 0;
    if ( (CmpAppHiveLoadListLock & 2) != 0 )
      goto LABEL_113;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&CmpAppHiveLoadListLock);
    while ( v21 == v19 && __strex(v20, (unsigned int *)&CmpAppHiveLoadListLock) );
    if ( v21 != v19 )
LABEL_113:
      ExfReleasePushLock(&CmpAppHiveLoadListLock, v19);
    v22 = KeAbPostRelease((unsigned int)&CmpAppHiveLoadListLock);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = (__int16)(*(_WORD *)(v23 + 0x134) + 1);
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v22);
  }
  else
  {
    v55 = v119;
    while ( !(*(_BYTE *)(v54 + 20) ? RtlEqualUnicodeString(*(_DWORD *)(v54 + 16), v9, 1) : *(_DWORD *)(v54 + 16) == v55) )
    {
      v54 = *(_DWORD *)v54;
      if ( (int *)v54 == &CmpAppHiveLoadList )
        goto LABEL_166;
    }
    v71 = *(int ***)(v54 + 12);
    v117 = (int *)(v54 + 8);
    v118 = v71;
    if ( *v71 != (int *)(v54 + 8) )
      __fastfail(3u);
    *v71 = (int *)&v117;
    *(_DWORD *)(v54 + 12) = &v117;
    v72 = v118;
    v73 = (unsigned int *)(v118 + 8);
    __pld(v118 + 8);
    v74 = *v73 & 0xFFFFFFFE;
    do
      v75 = __ldrex(v73);
    while ( v75 == v74 && __strex(v74 + 2, v73) );
    __dmb(0xBu);
    if ( v75 != v74 )
      ExfAcquireRundownProtection(v73);
    __pld(&CmpAppHiveLoadListLock);
    v76 = CmpAppHiveLoadListLock;
    if ( (CmpAppHiveLoadListLock & 0xFFFFFFF0) <= 0x10 )
      v77 = 0;
    else
      v77 = CmpAppHiveLoadListLock - 16;
    if ( (CmpAppHiveLoadListLock & 2) != 0 )
      goto LABEL_156;
    __dmb(0xBu);
    do
      v78 = __ldrex((unsigned int *)&CmpAppHiveLoadListLock);
    while ( v78 == v76 && __strex(v77, (unsigned int *)&CmpAppHiveLoadListLock) );
    if ( v78 != v76 )
LABEL_156:
      ExfReleasePushLock(&CmpAppHiveLoadListLock, v76);
    v79 = KeAbPostRelease((unsigned int)&CmpAppHiveLoadListLock);
    v80 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v81 = *(_WORD *)(v80 + 0x134) + 1;
    *(_WORD *)(v80 + 308) = v81;
    if ( !v81 && *(_DWORD *)(v80 + 100) != v80 + 100 && !*(_WORD *)(v80 + 310) )
      KiCheckForKernelApcDelivery(v79);
    KeWaitForSingleObject((unsigned int)(v72 + 4), 0, 0, 0, 0);
    __pld(v73);
    v82 = *v73 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v83 = __ldrex(v73);
    while ( v83 == v82 && __strex(v82 - 2, v73) );
    if ( v83 != v82 )
      ExfReleaseRundownProtection((unsigned __int8 *)v73);
  }
  v25 = v100;
  v26 = v106;
  while ( 1 )
  {
    v101[0] = 1;
    v99[0] = 0;
    v113 = 0;
    v27 = CmpCmdHiveOpen(v26, 1, v101, &v113, v105, v114, v99);
    v18 = v27;
    if ( !v27 )
    {
      v18 = CmpLoadKeyCommon(v113, v108, v107, v126, a5, a7, v101[0], v99[0]);
      goto LABEL_63;
    }
    if ( v27 != -1073741757 || v128 || v11 )
      goto LABEL_63;
    if ( !v109 )
      goto LABEL_35;
    v84 = CmpOpenHiveFile(v26, 0, &v103, v125, 8, 0, 0, &v100);
    v18 = v84;
    if ( v84 < 0 )
      break;
    v18 = ObReferenceObjectByHandle(v103, 0, *(_DWORD *)CmIoFileObjectType, 0, &v127, 0);
    v104 = v127;
    v27 = ZwClose();
    if ( v18 < 0 )
      goto LABEL_185;
    v25 = v100;
LABEL_35:
    LOCK_HIVE_LOAD(v27);
    v28 = CmpLockRegistryFreezeAware(1);
    v29 = CmpGetLastHive(v28);
    v30 = v29;
    v102 = v29;
    if ( v29 )
    {
      do
      {
        v31 = CmpActiveAppHiveUnloadCount;
        v112 = CmpActiveAppHiveUnloadCount;
        __dmb(0xBu);
        if ( v31 )
        {
          do
          {
            v87 = CmpUnlockRegistry(v29);
            UNLOCK_HIVE_LOAD(v87);
            v88 = ExBlockOnAddressPushLock(
                    (int)&CmpActiveAppHiveUnloadEvent,
                    (unsigned __int64 *)&CmpActiveAppHiveUnloadCount,
                    (unsigned int *)&v112,
                    4,
                    0);
            LOCK_HIVE_LOAD(v88);
            v29 = CmpLockRegistryFreezeAware(1);
            v89 = CmpActiveAppHiveUnloadCount;
            v112 = CmpActiveAppHiveUnloadCount;
            __dmb(0xBu);
          }
          while ( v89 );
        }
        for ( i = 0; ; i = v33 )
        {
          v29 = CmpGetNextHive(i);
          v33 = v29;
          if ( !v29 )
            goto LABEL_174;
          v34 = *(_DWORD *)(v29 + 3856);
          v124 = v34;
          __dmb(0xBu);
          if ( v34 )
            break;
          if ( *(_BYTE *)(v29 + 3865) || !*(_DWORD *)(v29 + 1776) )
          {
            if ( v29 == v30 )
            {
              v29 = CmpDereferenceHive(v29);
              goto LABEL_174;
            }
          }
          else
          {
            v35 = CmpIsThisSameFile(v104);
            v25 = v100;
            if ( v35 )
            {
              v36 = *(_DWORD *)(v33 + 3228);
              if ( (v36 & 0x20) != 0 && (v36 & 0x40) == 0 )
              {
                if ( v110 )
                {
                  if ( (*(_DWORD *)(v33 + 92) & 0x8000) == 0 && !CmpCheckHivePrimaryFileReadWriteAccess(v100) )
                  {
                    v92 = CmpUnlockRegistry(0);
                    UNLOCK_HIVE_LOAD(v92);
                    CmpDereferenceHive(v33);
                    v18 = -1073741790;
                    goto LABEL_54;
                  }
LABEL_51:
                  v37 = *(_DWORD *)(v33 + 2528);
                  v111 = v33;
                  v38 = CmpConstructName(v37);
                  *a6 = v38;
                  if ( !v38 )
                  {
                    v94 = CmpUnlockRegistry(0);
                    UNLOCK_HIVE_LOAD(v94);
                    v18 = -1073741670;
                    CmpDereferenceHive(v33);
                    goto LABEL_54;
                  }
                  v39 = CmpReferenceKeyControlBlockUnsafe(*(_DWORD *)(v33 + 2528));
                  *a7 = *(_DWORD *)(v33 + 2528);
                  v40 = CmpUnlockRegistry(v39);
                  UNLOCK_HIVE_LOAD(v40);
                  v18 = 0;
LABEL_53:
                  v29 = CmpDereferenceHive(v33);
                  if ( v111 )
                    goto LABEL_54;
LABEL_175:
                  v86 = CmpUnlockRegistry(v29);
                  UNLOCK_HIVE_LOAD(v86);
                  v26 = v106;
                  goto LABEL_176;
                }
                if ( (*(_DWORD *)(v33 + 92) & 0x8000) == 0 )
                  goto LABEL_51;
              }
              v93 = CmpUnlockRegistry(v35);
              UNLOCK_HIVE_LOAD(v93);
              CmpDereferenceHive(v33);
              v25 = v100;
              v18 = -1073741757;
              goto LABEL_54;
            }
            if ( v33 == v30 )
              goto LABEL_53;
          }
        }
        v90 = CmpUnlockRegistry(v29);
        UNLOCK_HIVE_LOAD(v90);
        v91 = ExBlockOnAddressPushLock(v33 + 3860, (unsigned __int64 *)(v33 + 3856), &v124, 4, 0);
        LOCK_HIVE_LOAD(v91);
        CmpLockRegistryFreezeAware(1);
        v29 = CmpDereferenceHive(v33);
      }
      while ( v33 != v30 );
LABEL_174:
      v25 = v100;
      goto LABEL_175;
    }
    v85 = CmpUnlockRegistry(0);
    UNLOCK_HIVE_LOAD(v85);
LABEL_176:
    v11 = 1;
  }
  if ( v84 == -1073741772 )
    v18 = -1073741757;
LABEL_185:
  v25 = v100;
LABEL_63:
  v30 = v102;
LABEL_54:
  v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v41 + 308);
  v42 = KeAbPreAcquire((unsigned int)&CmpAppHiveLoadListLock, 0, 0);
  v43 = v42;
  do
    v44 = __ldrex((unsigned __int8 *)&CmpAppHiveLoadListLock);
  while ( __strex(v44 | 1, (unsigned __int8 *)&CmpAppHiveLoadListLock) );
  __dmb(0xBu);
  if ( (v44 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpAppHiveLoadListLock, v42, (unsigned int)&CmpAppHiveLoadListLock);
  if ( v43 )
    *(_BYTE *)(v43 + 14) |= 1u;
  v45 = (int)v115;
  v46 = v116;
  if ( (int **)v115[1] != &v115 || *v116 != (int *)&v115 )
    __fastfail(3u);
  *v116 = v115;
  *(_DWORD *)(v45 + 4) = v46;
  v95 = v117;
  if ( v117 != (int *)&v117 )
  {
    v96 = v118;
    v97 = v117 - 2;
    if ( (int **)v117[1] != &v117 || *v118 != (int *)&v117 )
      __fastfail(3u);
    *v118 = v117;
    v95[1] = (int)v96;
    v98 = (int **)dword_63246C;
    *v97 = (int)&CmpAppHiveLoadList;
    *(v95 - 1) = (int)v98;
    if ( *v98 != &CmpAppHiveLoadList )
      __fastfail(3u);
    *v98 = v97;
    dword_63246C = (int)v97;
  }
  __pld(&CmpAppHiveLoadListLock);
  v57 = CmpAppHiveLoadListLock;
  if ( (CmpAppHiveLoadListLock & 0xFFFFFFF0) > 0x10 )
    v58 = CmpAppHiveLoadListLock - 16;
  else
    v58 = 0;
  if ( (CmpAppHiveLoadListLock & 2) != 0 )
    goto LABEL_129;
  __dmb(0xBu);
  do
    v59 = __ldrex((unsigned int *)&CmpAppHiveLoadListLock);
  while ( v59 == v57 && __strex(v58, (unsigned int *)&CmpAppHiveLoadListLock) );
  if ( v59 != v57 )
LABEL_129:
    ExfReleasePushLock(&CmpAppHiveLoadListLock, v57);
  v60 = KeAbPostRelease((unsigned int)&CmpAppHiveLoadListLock);
  v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v62 = (__int16)(*(_WORD *)(v61 + 0x134) + 1);
  *(_WORD *)(v61 + 308) = v62;
  if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
    KiCheckForKernelApcDelivery(v60);
  KeSetEvent((int)v121, 0, 0);
  v17 = 1;
  do
    v63 = __ldrex(&v122);
  while ( !v63 && __strex(1u, &v122) );
  __dmb(0xBu);
  if ( v63 && v63 != 1 )
    v17 = (int)ExfWaitForRundownProtectionRelease(&v122, v63);
  if ( v30 )
    v17 = CmpDereferenceHive(v30);
  v48 = v104;
LABEL_96:
  if ( v48 )
    v17 = ObfDereferenceObject(v48);
LABEL_98:
  if ( v25 )
    v17 = ExFreePoolWithTag(v25);
  __pld(&CmpShutdownRundown);
  v64 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v65 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v65 == v64 && __strex(v64 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v65 != v64 )
    v17 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v67 = (__int16)(*(_WORD *)(v66 + 0x134) + 1);
  *(_WORD *)(v66 + 308) = v67;
  if ( !v67 && *(_DWORD *)(v66 + 100) != v66 + 100 && !*(_WORD *)(v66 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v18;
}
