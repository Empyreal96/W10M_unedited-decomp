// CmLoadKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmLoadKey(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  __int16 *v8; // r10
  unsigned __int16 *v9; // r1
  unsigned int v11; // r2
  int v13; // r0
  int v14; // r9
  int v15; // r0
  int v16; // r3
  unsigned int v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r1
  int v20; // lr
  int v21; // r5
  int v22; // r4
  int v23; // r0
  int v24; // r1
  unsigned int v25; // r2
  int v26; // r5
  int v27; // r0
  int v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // r1
  __int16 v31; // r3
  unsigned int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  _BYTE *v35; // r0
  int v36; // r1
  int v37; // r10
  int v38; // r6
  int v39; // r4
  int v40; // r9
  int v41; // r0
  int v42; // r2
  _DWORD *v43; // r8
  _DWORD *v44; // r4
  int v45; // r1 OVERLAPPED
  _DWORD *v46; // r2 OVERLAPPED
  _DWORD *v47; // r1
  unsigned int v48; // r4
  unsigned int v49; // r1
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // [sp+Ch] [bp-A4h]
  int v53; // [sp+10h] [bp-A0h] BYREF
  _DWORD *v54; // [sp+14h] [bp-9Ch] BYREF
  int v55[2]; // [sp+18h] [bp-98h] BYREF
  __int16 v56; // [sp+20h] [bp-90h] BYREF
  _BYTE v57[6]; // [sp+22h] [bp-8Eh]
  int v58; // [sp+28h] [bp-88h]
  int v59; // [sp+2Ch] [bp-84h] BYREF
  __int16 *v60; // [sp+30h] [bp-80h]
  int v61; // [sp+34h] [bp-7Ch]
  int v62; // [sp+38h] [bp-78h] BYREF
  int v63; // [sp+40h] [bp-70h] BYREF
  char v64[76]; // [sp+44h] [bp-6Ch] BYREF

  v8 = (__int16 *)a2;
  v60 = (__int16 *)a2;
  v9 = (unsigned __int16 *)a1[2];
  v58 = a4;
  v11 = *v9;
  v54 = 0;
  LOBYTE(v53) = 0;
  v56 = 0;
  *(_DWORD *)v57 = 0;
  *(_WORD *)&v57[4] = 0;
  if ( v11 >= 2 && v11 >> 1 && *(_WORD *)(*(_DWORD *)(a1[2] + 4) + 2 * (v11 >> 1) - 2) == 92 )
    return sub_7E9DC8();
  if ( *(unsigned __int16 *)a1[2] < 2u )
    return -1073741811;
  v13 = ExAllocatePoolWithTag(1, 260, 1649626435);
  v14 = v13;
  v61 = v13;
  if ( !v13 )
    return -1073741670;
  *(_DWORD *)&v57[2] = v13;
  v15 = a1[2];
  v56 = 0;
  *(_WORD *)v57 = 260;
  if ( CmpQueryHiveRedirectionFileList(v15, &v56) && v56 != 2 )
  {
    v8 = &v56;
    v60 = &v56;
  }
  v16 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v16 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v17 = CmpShutdownRundown & 0xFFFFFFFE;
  v18 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v19 == v17 && __strex(v18, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v19 != v17 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v34 = *(_WORD *)(v33 + 0x134) + 1;
    *(_WORD *)(v33 + 308) = v34;
    if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741431;
  }
  BYTE1(v53) = 1;
  if ( (a3 & 0x20) != 0 )
    v20 = 0x4000000;
  else
    v20 = 0;
  if ( (a3 & 0x80) != 0 )
    v21 = 0x8000000;
  else
    v21 = 0;
  if ( (a3 & 0x200) != 0 )
    v22 = 0x10000000;
  else
    v22 = 0;
  if ( (a3 & 4) != 0 )
    v23 = 0x20000000;
  else
    v23 = 0;
  if ( (a3 & 0x400) != 0 )
    v24 = 0x40000000;
  else
    v24 = 0;
  if ( (a3 & 0x1000) != 0 )
    v25 = 0x80000000;
  else
    v25 = 0;
  v26 = CmpCmdHiveOpen(
          (int)v8,
          1,
          (int)&v53 + 1,
          (int *)&v54,
          v25 | v24 | v23 | v22 | v21 | v20 | 0x1010001,
          0,
          (int)&v53,
          v52,
          v53,
          (int)v54,
          v55[0]);
  if ( v26 < 0 )
  {
    v54 = 0;
    v63 = 0;
    v35 = memset(v64, 0, sizeof(v64));
    v55[0] = 0;
    v37 = 0;
    if ( v26 != -1073741757 )
      goto LABEL_85;
    v35 = (_BYTE *)ObReferenceObjectByNameEx(a1, v36, 131097, CmKeyObjectType, 0, &v63, v55);
    if ( (int)v35 < 0 )
    {
      v26 = -1073741757;
LABEL_85:
      __pld(&CmpShutdownRundown);
      v48 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v49 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v49 == v48 && __strex(v48 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v49 != v48 )
        v35 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v51 = *(_WORD *)(v50 + 0x134) + 1;
      *(_WORD *)(v50 + 308) = v51;
      if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
        KiCheckForKernelApcDelivery((int)v35);
      v32 = v61;
      goto LABEL_32;
    }
    v35 = (_BYTE *)CmpOpenHiveFile((int)v60, 0, &v59, &v62, 8, 0, 0, 0);
    v38 = v55[0];
    if ( (int)v35 < 0 )
    {
      v26 = -1073741757;
LABEL_81:
      if ( v38 )
        v35 = (_BYTE *)ObfDereferenceObject(v38);
      if ( v37 )
        v35 = (_BYTE *)ObfDereferenceObject(v37);
      goto LABEL_85;
    }
    v39 = ObReferenceObjectByHandle(v59, 0, *(_DWORD *)CmIoFileObjectType, 0, v55);
    v37 = v55[0];
    v35 = (_BYTE *)ZwClose();
    v26 = -1073741757;
    if ( v39 < 0 )
      goto LABEL_81;
    v40 = 0;
    LOCK_HIVE_LOAD();
    v41 = CmpLockRegistryFreezeAware(1);
    if ( v58 )
    {
      v42 = *(_DWORD *)(v58 + 4);
      if ( (*(_DWORD *)(v42 + 4) & 0x20000) != 0 )
      {
        v26 = -1073741444;
LABEL_80:
        CmpUnlockRegistry(v41);
        v35 = (_BYTE *)UNLOCK_HIVE_LOAD();
        goto LABEL_81;
      }
      v40 = *(_DWORD *)(v42 + 20);
      if ( v40 && (*(_DWORD *)(v40 + 3228) & 1) == 0 )
      {
        v26 = -1073741811;
        goto LABEL_80;
      }
    }
    v41 = CmpIsHiveAlreadyLoaded(v38, v37, a3, &v54, a6, 0);
    if ( v41 )
    {
      v26 = 0;
      CmpLockKcbExclusive(*(_DWORD *)(v38 + 4));
      if ( (a3 & 0x800) != 0 )
      {
        CmpReferenceKeyControlBlock(*(_DWORD *)(v38 + 4));
        *a7 = *(_DWORD *)(v38 + 4);
      }
      v43 = v54;
      if ( a5 )
        v26 = CmpRecordUnloadEventForHive(v54);
      v41 = CmpUnlockKcb(*(_DWORD *)(v38 + 4));
      if ( v26 >= 0 && v40 )
      {
        v44 = v43 + 808;
        if ( (_DWORD *)v43[808] != v43 + 808 )
        {
          CmpLockHiveListExclusive();
          *(_QWORD *)&v45 = *(_QWORD *)v44;
          if ( *(_DWORD **)(*v44 + 4) != v44 || (_DWORD *)*v46 != v44 )
            __fastfail(3u);
          *v46 = v45;
          *(_DWORD *)(v45 + 4) = v46;
          CmpUnlockHiveList();
        }
        CmpLockHiveListExclusive();
        v47 = *(_DWORD **)(v40 + 3236);
        *v44 = v40 + 3232;
        v43[809] = v47;
        if ( *v47 != v40 + 3232 )
          __fastfail(3u);
        *v47 = v44;
        *(_DWORD *)(v40 + 3236) = v44;
        v41 = CmpUnlockHiveList();
        v43[807] |= 1u;
      }
    }
    goto LABEL_80;
  }
  v27 = CmpLoadKeyCommon(v54, a1, a3, v58, a5, a7, BYTE1(v53), v53);
  __pld(&CmpShutdownRundown);
  v26 = v27;
  v28 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v29 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v29 == v28 && __strex(v28 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v29 != v28 )
    v28 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v31 = *(_WORD *)(v30 + 0x134) + 1;
  *(_WORD *)(v30 + 308) = v31;
  if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
    KiCheckForKernelApcDelivery(v28);
  v32 = v14;
LABEL_32:
  ExFreePoolWithTag(v32);
  return v26;
}
