// CmpInitCmRM 
 
int __fastcall CmpInitCmRM(_DWORD *a1, int a2)
{
  int v2; // r9
  _DWORD *v4; // r10
  __int16 **v5; // r8
  _DWORD *v6; // r6
  int v7; // r4
  _BYTE *v8; // r0
  _DWORD *v9; // r7
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  _DWORD *v12; // r4
  int v13; // r4
  int v14; // r0
  int v15; // r1
  unsigned int v16; // r5
  unsigned int v17; // r9
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r2
  unsigned int *v21; // r4
  unsigned int v22; // r1
  int v23; // r0
  int v24; // r5
  _BYTE *v25; // r0
  unsigned __int16 *v26; // r4
  unsigned int v27; // r5
  unsigned int v28; // r0
  _DWORD *v29; // r5
  int v30; // r1
  int v31; // r2
  int v32; // r3
  _DWORD *v33; // r5
  int v34; // r1
  int v35; // r2
  int v36; // r3
  _DWORD *v37; // r5
  int v38; // r2
  int v39; // r3
  int v40; // r3
  int v41; // r5
  int v42; // r1
  int v43; // r0
  _DWORD *v44; // r5
  int v46; // r3
  int v47; // r1
  int v48; // r2
  int v49; // r3
  int v50; // r1
  int v51; // r2
  int v52; // r3
  int *v53; // r5
  int *v54; // r4
  int v55; // r2
  int v56; // r3
  unsigned int v57; // r5
  unsigned int v58; // r2
  __int16 *v59; // r1
  int v60; // r4
  int v61; // r0
  int v62; // r1
  int v63; // r1
  int v64; // r1
  int v65; // r2
  int v66; // r3
  int v67; // r0
  int v68; // r2
  __int16 *v69; // r3
  __int16 *v70; // r3
  __int16 *v71; // r3
  unsigned int v72; // r2
  unsigned int v73; // r6
  int v74; // r0
  int v75; // r5
  unsigned int v76; // r2
  void **v77; // r1
  unsigned int v78; // r1
  int v79; // r0
  unsigned int v80; // r1
  __int16 v81; // r3
  int v82; // [sp+20h] [bp-E8h]
  int v83; // [sp+28h] [bp-E0h] BYREF
  _BYTE *v84; // [sp+2Ch] [bp-DCh]
  int v85; // [sp+30h] [bp-D8h] BYREF
  int v86; // [sp+34h] [bp-D4h] BYREF
  int v87[2]; // [sp+38h] [bp-D0h] BYREF
  int v88; // [sp+40h] [bp-C8h] BYREF
  int v89; // [sp+44h] [bp-C4h]
  int v90; // [sp+48h] [bp-C0h]
  int v91; // [sp+50h] [bp-B8h] BYREF
  int v92; // [sp+54h] [bp-B4h]
  __int16 v93; // [sp+58h] [bp-B0h]
  __int16 v94; // [sp+5Ah] [bp-AEh]
  _BYTE *v95; // [sp+5Ch] [bp-ACh]
  int v96; // [sp+60h] [bp-A8h]
  unsigned int v97; // [sp+64h] [bp-A4h] BYREF
  int v98; // [sp+68h] [bp-A0h]
  int v99; // [sp+6Ch] [bp-9Ch]
  int v100; // [sp+70h] [bp-98h]
  int v101; // [sp+74h] [bp-94h]
  int v102; // [sp+78h] [bp-90h]
  int v103; // [sp+7Ch] [bp-8Ch]
  _DWORD *v104; // [sp+80h] [bp-88h]
  int v105[8]; // [sp+88h] [bp-80h] BYREF
  int v106; // [sp+A8h] [bp-60h]
  int v107; // [sp+ACh] [bp-5Ch]
  int v108; // [sp+B0h] [bp-58h]
  int v109; // [sp+B4h] [bp-54h]
  _DWORD v110[4]; // [sp+B8h] [bp-50h] BYREF
  int v111; // [sp+C8h] [bp-40h] BYREF
  int v112; // [sp+CCh] [bp-3Ch]
  int v113; // [sp+D0h] [bp-38h]
  int v114; // [sp+D4h] [bp-34h]
  int v115; // [sp+D8h] [bp-30h] BYREF
  int v116; // [sp+DCh] [bp-2Ch]
  int v117; // [sp+E0h] [bp-28h]
  int v118; // [sp+E4h] [bp-24h]

  v110[0] = 0;
  v110[1] = 0;
  v110[2] = 0;
  v110[3] = 0;
  v106 = 0;
  v107 = 0;
  v108 = 0;
  v109 = 0;
  v91 = 0;
  v92 = 0;
  v88 = 0;
  v82 = 0;
  v89 = 0;
  v90 = 0;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v93 = 0;
  v94 = 0;
  v95 = 0;
  v86 = 0;
  v87[0] = 0;
  v97 = 0;
  v2 = 0;
  v96 = a2;
  v4 = a1;
  if ( CmpMiniNTBoot )
    goto LABEL_145;
  v5 = CmpMachineHiveList;
  v6 = a1 ? a1 : off_60E8A4;
  if ( (v6[23] & 0x8001) != 0 )
    goto LABEL_145;
  v7 = CmpUuidCreate(&v111);
  if ( v7 < 0 || (v7 = CmpUuidCreate(&v115), v7 < 0) )
  {
    v46 = 1;
LABEL_80:
    v6[815] = v46;
    v6[816] = v7;
    ((void (*)(void))CmpLogTxrInitEvent)();
    return v7;
  }
  v8 = (_BYTE *)ExAllocatePoolWithTag(1, 88, 1834110275);
  v9 = v8;
  if ( !v8 )
  {
    v46 = 1;
LABEL_79:
    v7 = -1073741670;
    goto LABEL_80;
  }
  memset(v8, 0, 88);
  v10 = (_DWORD *)ExAllocatePoolWithTag(512, 56, 1819430211);
  v104 = v10;
  if ( !v10 )
  {
    ExFreePoolWithTag((unsigned int)v9);
    v46 = 2;
    goto LABEL_79;
  }
  v9[2] = v9 + 2;
  v9[3] = v9 + 2;
  v9[13] = 0;
  v9[14] = 0;
  if ( a2 )
    v9[15] = 4;
  else
    v9[15] = 0;
  v9[16] = 0;
  v9[17] = 0;
  v9[9] = 0;
  v9[10] = 0;
  v9[11] = 0;
  v9[20] = v10;
  ExInitializeResourceLite((int)v10);
  v11 = (_DWORD *)v6[8];
  if ( v11[41] != 1836346738 )
  {
    v11[41] = 1836346738;
    goto LABEL_42;
  }
  if ( !memcmp((unsigned int)v110, (unsigned int)(v11 + 37), 16) )
  {
    v90 = 1;
    v2 = 1;
    v47 = v116;
    v48 = v117;
    v49 = v118;
    v11[37] = v115;
    v11[38] = v47;
    v11[39] = v48;
    v11[40] = v49;
  }
  v12 = (_DWORD *)v6[8];
  if ( !memcmp((unsigned int)v110, (unsigned int)(v12 + 28), 16) )
  {
    v50 = v112;
    v51 = v113;
    v52 = v114;
    v2 = 1;
    v12[28] = v111;
    v12[29] = v50;
    v12[30] = v51;
    v12[31] = v52;
  }
  v13 = v6[8];
  v14 = memcmp((unsigned int)v110, v13 + 128, 16);
  if ( !v14 )
  {
    v53 = (int *)(v13 + 128);
    v54 = (int *)(v13 + 112);
    v14 = *v54;
    v15 = v54[1];
    v55 = v54[2];
    v56 = v54[3];
    v2 = 1;
    *v53 = *v54;
    v53[1] = v15;
    v53[2] = v55;
    v53[3] = v56;
  }
  while ( 1 )
  {
    if ( v2 )
    {
      CmpLockRegistry(v14, v15);
      ExAcquireResourceSharedLite(v6[468], 1);
      v16 = v6[467];
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = KeAbPreAcquire(v16, 0, 0);
      v19 = v18;
      do
        v20 = __ldrex((unsigned __int8 *)v16);
      while ( __strex(v20 & 0xFE, (unsigned __int8 *)v16) );
      __dmb(0xBu);
      if ( (v20 & 1) == 0 )
        ExpAcquireFastMutexContended(v16, v18);
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      *(_DWORD *)(v16 + 4) = v17;
      HvMarkBaseBlockDirty(v6);
      v21 = (unsigned int *)v6[467];
      v21[1] = 0;
      __dmb(0xBu);
      do
        v22 = __ldrex(v21);
      while ( !v22 && __strex(1u, v21) );
      if ( v22 )
        ExpReleaseFastMutexContended(v21, v22);
      KeAbPostRelease((unsigned int)v21);
      v23 = ExReleaseResourceLite(v6[468]);
      CmpUnlockRegistry(v23);
    }
    v24 = v6[444];
    v25 = (_BYTE *)RtlStringFromGUIDEx(v6[8] + 148, (int)&v91, 1);
    v7 = (int)v25;
    if ( (int)v25 < 0 )
    {
      v40 = 3;
      goto LABEL_45;
    }
    if ( v4 )
    {
      v25 = (_BYTE *)CmpQueryNameString(v4[444], &v88);
      v7 = (int)v25;
      if ( (int)v25 < 0 )
      {
        v41 = v89;
        v40 = 4;
        goto LABEL_46;
      }
      v26 = (unsigned __int16 *)&v88;
      v82 = v89;
    }
    else
    {
      v26 = (unsigned __int16 *)&CmpLogPath;
      v87[0] = 52;
    }
    HIWORD(v83) = *v26 + TmLogExt[0] + CmpClfsLogPrefix[0] + v91;
    v25 = (_BYTE *)ExpAllocateStringRoutine(HIWORD(v83));
    v84 = v25;
    if ( !v25 )
    {
      v7 = -1073741670;
      v40 = 5;
      goto LABEL_45;
    }
    RtlAppendUnicodeStringToString((unsigned __int16 *)&v83, CmpClfsLogPrefix);
    RtlAppendUnicodeStringToString((unsigned __int16 *)&v83, v26);
    RtlAppendUnicodeStringToString((unsigned __int16 *)&v83, (unsigned __int16 *)&v91);
    RtlAppendUnicodeStringToString((unsigned __int16 *)&v83, TmLogExt);
    RtlFreeAnsiString(&v91);
    if ( v4 )
    {
      RtlFreeAnsiString(&v88);
      v82 = v89;
    }
    v25 = (_BYTE *)CmpQueryFileSecurityDescriptor(v24, (int *)&v97);
    v7 = (int)v25;
    if ( (int)v25 < 0 )
    {
      v40 = 6;
      goto LABEL_45;
    }
    v27 = v97;
    v7 = ClfsCreateLogFile(&v85, &v83, -1073741824, 7, v97, 3, 8, 0, 512, 0, 0);
    v25 = (_BYTE *)ExFreePoolWithTag(v27);
    if ( v7 >= 0 )
      break;
    if ( v90 )
    {
      v40 = 7;
      goto LABEL_45;
    }
    v28 = RtlFreeAnsiString(&v83);
    CmpLogTxrInitEvent(v28, v6, v7);
LABEL_42:
    v90 = 1;
    v2 = 1;
    v29 = (_DWORD *)(v6[8] + 148);
    v30 = v116;
    v31 = v117;
    v32 = v118;
    *v29 = v115;
    v29[1] = v30;
    v29[2] = v31;
    v29[3] = v32;
    v33 = (_DWORD *)(v6[8] + 112);
    v34 = v112;
    v35 = v113;
    v36 = v114;
    *v33 = v111;
    v33[1] = v34;
    v33[2] = v35;
    v33[3] = v36;
    v37 = (_DWORD *)(v6[8] + 128);
    v14 = v111;
    v15 = v112;
    v38 = v113;
    v39 = v114;
    *v37 = v111;
    v37[1] = v15;
    v37[2] = v38;
    v37[3] = v39;
    if ( !v4 )
      v96 = 1;
  }
  memset(v105, 0, 28);
  v105[0] = 1;
  v25 = (_BYTE *)ClfsMgmtRegisterManagedClient(v85, v105, &v86);
  v7 = (int)v25;
  if ( (int)v25 < 0 )
  {
    v40 = 8;
    goto LABEL_45;
  }
  v25 = (_BYTE *)ExAllocatePoolWithTag(1, (unsigned __int16)TmContainerExt + 24, 1834110275);
  v57 = (unsigned int)v25;
  if ( !v25 )
  {
    v40 = 9;
LABEL_45:
    v41 = v82;
LABEL_46:
    v6[815] = v40;
    CmpLogTxrInitEvent(v25, v6, v7);
    if ( v86 )
    {
      ClfsMgmtDeregisterManagedClient(v86, v42);
      v86 = 0;
    }
    if ( v85 )
      ClfsCloseLogFileObject(v85, v42);
    if ( v92 )
      RtlFreeAnsiString(&v91);
    if ( v41 )
      RtlFreeAnsiString(&v88);
    if ( v84 )
      RtlFreeAnsiString(&v83);
    if ( v9 )
    {
      if ( v9[6] )
        ZwClose();
      v43 = v9[5];
      if ( v43 )
        ObfDereferenceObject(v43);
      if ( v9[4] )
        ZwClose();
      ExFreePoolWithTag((unsigned int)v9);
    }
    v44 = v104;
    ExDeleteResourceLite(v104);
    ExFreePoolWithTag((unsigned int)v44);
    v6[816] = v7;
    return v7;
  }
  memset(v25, 0, 24);
  *(_DWORD *)v57 = 1;
  *(_DWORD *)(v57 + 12) = 9;
  v58 = (unsigned __int16)TmContainerExt;
  v59 = off_618228;
  v60 = (unsigned __int16)TmContainerExt + 24;
  *(_DWORD *)(v57 + 4) = v60;
  *(_WORD *)(v57 + 16) = v58;
  memmove(v57 + 18, (int)v59, v58);
  v7 = ClfsMgmtInstallPolicy(v85, v57, v60);
  v25 = (_BYTE *)ExFreePoolWithTag(v57);
  if ( v7 < 0 )
  {
    v40 = 10;
    goto LABEL_45;
  }
  v93 = v83 - CmpClfsLogPrefix[0];
  v94 = HIWORD(v83) - CmpClfsLogPrefix[0];
  v95 = &v84[CmpClfsLogPrefix[0]];
  v98 = 24;
  v99 = 0;
  v101 = 576;
  v100 = 0;
  v102 = 0;
  v103 = 0;
  v61 = ZwCreateTransactionManager();
  v7 = v61;
  if ( v61 == -1073741771 )
  {
    if ( v84 )
      RtlFreeAnsiString(&v83);
    if ( v85 )
    {
      ClfsCloseLogFileObject(v85, v62);
      v85 = 0;
    }
    if ( v86 )
    {
      ClfsMgmtDeregisterManagedClient(v86, v62);
      v86 = 0;
    }
    if ( v90 )
      goto LABEL_95;
    goto LABEL_42;
  }
  if ( v61 >= 0 )
    v7 = ZwRecoverTransactionManager();
LABEL_95:
  v25 = (_BYTE *)RtlFreeAnsiString(&v83);
  if ( v7 < 0 )
  {
    v40 = 11;
    goto LABEL_45;
  }
  if ( v85 )
  {
    ClfsCloseLogFileObject(v85, v63);
    v85 = 0;
  }
  if ( v86 )
  {
    ClfsMgmtDeregisterManagedClient(v86, v63);
    v86 = 0;
  }
  v25 = (_BYTE *)ObReferenceObjectByHandle(v9[4], 983103, TmTransactionManagerObjectType, 0, v87, 0);
  v7 = (int)v25;
  v9[5] = v87[0];
  if ( (int)v25 < 0 )
  {
    v40 = 12;
    goto LABEL_45;
  }
  v64 = *(_DWORD *)(v6[8] + 116);
  v65 = *(_DWORD *)(v6[8] + 120);
  v66 = *(_DWORD *)(v6[8] + 124);
  v106 = *(_DWORD *)(v6[8] + 112);
  v107 = v64;
  v108 = v65;
  v109 = v66;
  v98 = 24;
  v99 = 0;
  v101 = 576;
  v100 = 0;
  v102 = 0;
  v103 = 0;
  v25 = (_BYTE *)ZwCreateResourceManager();
  v7 = (int)v25;
  if ( v25 == (_BYTE *)-1073741771 )
  {
    v25 = (_BYTE *)ZwOpenResourceManager();
    v7 = (int)v25;
  }
  if ( v7 < 0 )
  {
    v40 = 13;
    goto LABEL_45;
  }
  v25 = (_BYTE *)ZwRecoverResourceManager();
  v7 = (int)v25;
  if ( (int)v25 < 0 )
  {
    v40 = 14;
    goto LABEL_45;
  }
  v25 = (_BYTE *)ObReferenceObjectByHandle(v9[6], 2031743, TmResourceManagerObjectType, 0, v87, 0);
  v7 = (int)v25;
  v9[7] = v87[0];
  if ( (int)v25 < 0 )
  {
    v40 = 15;
    goto LABEL_45;
  }
  if ( v4 )
  {
    v4[814] = v9;
    v9[8] = 1;
    goto LABEL_123;
  }
  v67 = 6;
  v68 = (int)v9;
  CmRmSystem = (int)v9;
  while ( 2 )
  {
    v69 = v5[7];
    if ( v69 && (*((_DWORD *)v69 + 23) & 2) == 0 )
    {
      ++*(_DWORD *)(v68 + 32);
      v70 = v5[7];
      goto LABEL_119;
    }
    v71 = v5[3];
    if ( v71 && (*((_DWORD *)v71 + 23) & 2) == 0 )
    {
      ++*(_DWORD *)(v68 + 32);
      v70 = v5[3];
LABEL_119:
      *((_DWORD *)v70 + 814) = v68;
      v68 = CmRmSystem;
    }
    v5 += 24;
    if ( --v67 )
      continue;
    break;
  }
  *((_DWORD *)CmpMasterHive + 814) = v68;
  ++*(_DWORD *)(CmRmSystem + 32);
LABEL_123:
  v9[12] = v4;
  v72 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v72 + 308);
  v73 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v74 = KeAbPreAcquire((unsigned int)&CmpRmListLock, 0, 0);
  v75 = v74;
  do
    v76 = __ldrex((unsigned __int8 *)&CmpRmListLock);
  while ( __strex(v76 & 0xFE, (unsigned __int8 *)&CmpRmListLock) );
  __dmb(0xBu);
  if ( (v76 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpRmListLock, v74);
  if ( v75 )
    *(_BYTE *)(v75 + 14) |= 1u;
  dword_631FA4 = v73;
  v77 = (void **)dword_631F94;
  *v9 = &CmpRmListHead;
  v9[1] = v77;
  if ( *v77 != &CmpRmListHead )
    __fastfail(3u);
  *v77 = v9;
  dword_631FA4 = 0;
  dword_631F94 = (int)v9;
  __dmb(0xBu);
  do
    v78 = __ldrex((unsigned int *)&CmpRmListLock);
  while ( !v78 && __strex(1u, (unsigned int *)&CmpRmListLock) );
  if ( v78 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpRmListLock, v78);
  v79 = KeAbPostRelease((unsigned int)&CmpRmListLock);
  v80 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v81 = *(_WORD *)(v80 + 0x134) + 1;
  *(_WORD *)(v80 + 308) = v81;
  if ( !v81 && *(_DWORD *)(v80 + 100) != v80 + 100 && !*(_WORD *)(v80 + 310) )
    v79 = KiCheckForKernelApcDelivery(v79);
  if ( !v96 )
LABEL_145:
    JUMPOUT(0x7D0F34);
  return sub_7D0F2C(v79);
}
