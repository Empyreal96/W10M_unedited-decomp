// CmpLoadKeyCommon 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpLoadKeyCommon(_DWORD *a1, _DWORD *a2, __int16 a3, int a4, int a5, _DWORD *a6, unsigned __int8 a7, unsigned __int8 a8)
{
  int v10; // r4
  int v12; // r8
  int v14; // r0
  int v15; // r0
  int v16; // r4
  int v17; // r0
  int v18; // r6
  int v19; // r0
  void ***v20; // r1
  int v21; // r0
  int v22; // r0
  int v23; // r0
  int v24; // r0
  int v25; // r0
  int v26; // r0
  int v27; // r1
  int v28; // r4
  int v29; // r4
  int v30; // r4
  unsigned __int16 *v31; // r1
  _WORD *v32; // r2
  __int16 v33; // r1
  int v34; // r3
  _DWORD *v35; // r0
  _DWORD *v36; // r2
  int v37; // r0
  int v38; // r0
  int v39; // r0
  _DWORD *v40; // r4
  int v41; // r0
  int v42; // r1 OVERLAPPED
  _DWORD *v43; // r2 OVERLAPPED
  int v45; // [sp+1Ch] [bp-7Ch] BYREF
  __int16 v46; // [sp+20h] [bp-78h] BYREF
  _BYTE v47[6]; // [sp+22h] [bp-76h]
  int v48; // [sp+28h] [bp-70h] BYREF
  char v49[76]; // [sp+2Ch] [bp-6Ch] BYREF

  v10 = a1[23];
  v45 = 0;
  a1[23] = v10 | 0x20;
  a1[817] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = a3 & 0x10;
  if ( (a3 & 0x10) != 0 )
  {
    a1[807] |= 0x20u;
    if ( (a3 & 0x20) != 0 )
      return sub_51A0B4();
  }
  a1[807] |= 1u;
  v14 = LockShutdownShared();
  LOCK_HIVE_LOAD(v14);
  v15 = CmpLockRegistryFreezeAware(1);
  if ( !a4 )
    goto LABEL_5;
  v29 = *(_DWORD *)(a4 + 4);
  v15 = CmRmIsKCBDeleted(v29, 0);
  if ( v15 == 1 )
  {
    v18 = -1073741444;
LABEL_39:
    v37 = CmpUnlockRegistry(v15);
    v38 = UNLOCK_HIVE_LOAD(v37);
    ObDrainDeferredObjectDeletion(v38);
    v39 = CmpDestroySecurityCache(a1);
    v40 = a1 + 808;
    if ( (_DWORD *)a1[808] != a1 + 808 )
    {
      v41 = CmpLockHiveListExclusive(v39);
      *(_QWORD *)&v42 = *(_QWORD *)v40;
      if ( *(_DWORD **)(*v40 + 4) != v40 || (_DWORD *)*v43 != v40 )
        __fastfail(3u);
      *v43 = v42;
      *(_DWORD *)(v42 + 4) = v43;
      CmpUnlockHiveList(v41);
    }
    if ( (a1[807] & 2) != 0 )
      CmpRemoveHiveFromMapping(a1);
    HvFreeHive(a1, 1);
    CmpCmdHiveClose(a1);
    v25 = CmpDereferenceHive(a1);
    goto LABEL_19;
  }
  v30 = *(_DWORD *)(v29 + 20);
  if ( !v30 )
    goto LABEL_5;
  if ( (*(_DWORD *)(v30 + 3228) & 1) == 0 )
  {
    v18 = -1073741811;
    goto LABEL_39;
  }
  v46 = 0;
  v31 = (unsigned __int16 *)a2[2];
  *(_DWORD *)v47 = 0;
  *(_WORD *)&v47[4] = 0;
  v32 = (_WORD *)(*((_DWORD *)v31 + 1) + 2 * (((unsigned int)*v31 - 2) >> 1));
  if ( *v32 != 92 )
  {
    v33 = v46;
    do
    {
      --v32;
      v33 += 2;
      v34 = (unsigned __int16)*v32;
      v46 = v33;
    }
    while ( v34 != 92 );
  }
  a1[807] |= 2u;
  *(_DWORD *)&v47[2] = v32 + 1;
  v18 = CmpAddStringToMapping(&v46, a1);
  ((void (*)(void))CmpLockHiveListExclusive)();
  v35 = *(_DWORD **)(v30 + 3236);
  v36 = a1 + 808;
  a1[808] = v30 + 3232;
  a1[809] = v35;
  if ( *v35 != v30 + 3232 )
    __fastfail(3u);
  *v35 = v36;
  *(_DWORD *)(v30 + 3236) = v36;
  v15 = CmpUnlockHiveList(v35);
  if ( v18 < 0 )
    goto LABEL_39;
LABEL_5:
  CmpUnlockRegistry(v15);
  v16 = a7;
  v17 = CmpLinkHiveToMaster(a2[2], a2[1], a1, a7, 512, v12 != 0, a5, a2[4], 0);
  v18 = v17;
  if ( (a3 & 0x800) != 0 && v17 >= 0 )
  {
    v48 = 0;
    memset(v49, 0, sizeof(v49));
    v18 = ObReferenceObjectByNameEx(a2, v27, 131097, CmKeyObjectType, 0, &v48, &v45);
    if ( v18 >= 0 )
    {
      v28 = v45;
      CmpLockKcbExclusive(*(_DWORD *)(v45 + 4));
      CmpReferenceKeyControlBlock(*(_DWORD *)(v28 + 4));
      CmpUnlockKcb(*(_DWORD *)(v28 + 4));
      *a6 = *(_DWORD *)(v28 + 4);
      ObfDereferenceObject(v28);
      v16 = a7;
    }
  }
  v15 = CmpLockRegistryFreezeAware(1);
  if ( v18 < 0 )
    goto LABEL_39;
  if ( v12 )
  {
    v15 = CmpReferenceKeyControlBlockUnsafe(a1[632]);
    *a6 = a1[632];
  }
  v19 = CmpLockHiveListExclusive(v15);
  v20 = (void ***)off_92078C;
  a1[452] = &CmpHiveListHead;
  a1[453] = v20;
  if ( *v20 != &CmpHiveListHead )
    __fastfail(3u);
  *v20 = (void **)(a1 + 452);
  off_92078C = a1 + 452;
  v21 = CmpUnlockHiveList(v19);
  v22 = CmpUnlockRegistry(v21);
  v23 = UNLOCK_HIVE_LOAD(v22);
  if ( (a3 & 0x110) == 0 )
  {
    v23 = CmpInitCmRM(a1, a8);
    a1[807] |= 8u;
  }
  if ( v16 == 1 )
    v23 = CmpFlushHive(a1, 4);
  if ( !v12 )
    v23 = CmpAddToHiveFileList(a1);
  if ( a1[814] )
  {
    TmEnableCallbacks();
    v23 = CmRmFinalizeRecovery(a1[814]);
  }
  v24 = LOCK_HIVE_LOAD(v23);
  a1[23] &= 0xFFFFFFDF;
  a1[817] = 0;
  v25 = UNLOCK_HIVE_LOAD(v24);
LABEL_19:
  v26 = UnlockShutdown(v25);
  if ( !CmpProfileLoaded && !CmpWasSetupBoot )
  {
    CmpProfileLoaded = 1;
    CmpSetGlobalQuotaAllowed(v26);
  }
  return v18;
}
