// CmpFinishSystemHivesLoad 
 
int __fastcall CmpFinishSystemHivesLoad(int a1)
{
  int result; // r0
  int *v2; // r6
  int v3; // r0
  unsigned int *v4; // r10
  int v5; // r0
  unsigned int *v6; // r2
  char *v7; // r3
  int v8; // r1
  __int16 **v9; // r4
  int v10; // r6
  unsigned int i; // r7
  unsigned __int16 *v12; // r1
  int v13; // r6
  int v14; // r2
  int v15; // r6
  void **v16; // r1
  void ***v17; // r0
  int v18; // r1
  int v19; // r0
  const __int16 *v20; // r1
  const __int16 *v21; // r0
  int v22; // r0
  int v23; // r0
  int v24; // r0
  int v25; // r0
  __int16 *v26; // r2
  __int16 *v27; // r3
  __int16 *v28; // r2
  int v29; // r0
  int v30; // r0
  int v31; // r3
  unsigned int v32; // r0
  unsigned int v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int v37; // r4
  unsigned int v38; // r1
  int v39; // r0
  __int16 v40; // r2
  unsigned __int16 v41[2]; // [sp+18h] [bp-E8h] BYREF
  char *v42; // [sp+1Ch] [bp-E4h]
  int v43; // [sp+20h] [bp-E0h]
  int *v44; // [sp+24h] [bp-DCh]
  int v45; // [sp+28h] [bp-D8h]
  int v46; // [sp+2Ch] [bp-D4h] BYREF
  char v47[8]; // [sp+30h] [bp-D0h] BYREF
  unsigned int v48; // [sp+38h] [bp-C8h]
  int v49; // [sp+3Ch] [bp-C4h]
  int v50; // [sp+40h] [bp-C0h]
  int v51; // [sp+48h] [bp-B8h]
  int v52; // [sp+4Ch] [bp-B4h]
  void *v53; // [sp+50h] [bp-B0h]
  int v54; // [sp+54h] [bp-ACh]
  int v55; // [sp+58h] [bp-A8h]
  int v56; // [sp+5Ch] [bp-A4h]
  char v57; // [sp+60h] [bp-A0h] BYREF

  if ( a1 )
    return sub_80B04C();
  CmpNoWrite = 0;
  v41[1] = 128;
  v41[0] = 0;
  v42 = &v57;
  RtlInitUnicodeString((unsigned int)v47, L"\\REGISTRY\\");
  RtlAppendStringToString(v41, v47);
  v50 = v41[0];
  v2 = (int *)ExAllocatePoolWithTag(512, 144, 538987843);
  v44 = v2;
  v3 = ExAllocatePoolWithTag(512, 24, 538987843);
  v4 = (unsigned int *)v3;
  if ( !v2 || !v3 )
    KeBugCheckEx(116, 2, 4, 0, -1073741670);
  CmpMountThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v45 = CmpHiveRootSecurityDescriptor();
  v5 = CmpAdminSystemSecurityDescriptor();
  v6 = v4;
  CmpAdminSystemFileSecurityDescriptor = v5;
  v7 = (char *)&unk_60E7B0;
  v8 = 6;
  do
  {
    *v6++ = (unsigned int)v7;
    v7 += 96;
    --v8;
  }
  while ( v8 );
  KeWaitForSingleObject((unsigned int)&unk_60E8D0, 0, 0, 0, 0);
  KeSetEvent((int)&unk_60E8D0, 0, 0);
  CmpInitCmRM(0, (unsigned __int8)CmpInitRmLogOnLoad);
  if ( CmRmSystem )
  {
    TmEnableCallbacks();
    CmRmFinalizeRecovery(CmRmSystem);
  }
  while ( 2 )
  {
    KeWaitForMultipleObjects(6u, v4, 1, 0, 0, 0, 0, v2);
    v10 = 0;
    v43 = 0;
    CmpLockRegistryExclusive();
    for ( i = 0; i < 6; ++i )
    {
      v9 = &CmpMachineHiveList[24 * i];
      v48 = 96 * i;
      if ( *((_BYTE *)v9 + 32) )
        continue;
      if ( *((_BYTE *)v9 + 33) != 1 )
      {
        v10 = 1;
        v43 = 1;
        continue;
      }
      v12 = (unsigned __int16 *)v9[1];
      v13 = 0;
      v41[0] = v50;
      v46 = 0;
      RtlInitUnicodeString((unsigned int)v47, v12);
      RtlAppendStringToString(v41, v47);
      if ( *(_WORD *)&v42[2 * (v41[0] >> 1) - 2] == 92 )
      {
        RtlInitUnicodeString((unsigned int)v47, (unsigned __int16 *)v9[2]);
        RtlAppendStringToString(v41, v47);
      }
      if ( !v9[3] )
      {
        v14 = (int)v9[7];
        if ( v14 )
        {
          v15 = CmpLinkHiveToMaster(v41, 0, v14, *((unsigned __int8 *)v9 + 35), (int)v9[6], 0, 0, v45, 1);
          if ( v15 )
          {
            v31 = __mrc(15, 0, 13, 0, 3);
            --*(_WORD *)((v31 & 0xFFFFFFC0) + 0x134);
            __pld(&CmpShutdownRundown);
            v32 = CmpShutdownRundown & 0xFFFFFFFE;
            v33 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
            do
              v34 = __ldrex((unsigned int *)&CmpShutdownRundown);
            while ( v34 == v32 && __strex(v33, (unsigned int *)&CmpShutdownRundown) );
            __dmb(0xBu);
            if ( v34 == v32 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
            {
              __pld(&CmpShutdownRundown);
              v37 = CmpShutdownRundown & 0xFFFFFFFE;
              __dmb(0xBu);
              do
                v38 = __ldrex((unsigned int *)&CmpShutdownRundown);
              while ( v38 == v37 && __strex(v37 - 2, (unsigned int *)&CmpShutdownRundown) );
              if ( v38 != v37 )
                ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
              v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v40 = *(_WORD *)(v39 + 0x134) + 1;
              *(_WORD *)(v39 + 308) = v40;
              if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
                KiCheckForKernelApcDelivery(v39);
              KeBugCheckEx(115, 1, v15, i, (int)v41);
            }
            v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v36 = *(_WORD *)(v35 + 0x134) + 1;
            *(_WORD *)(v35 + 308) = v36;
            if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
              KiCheckForKernelApcDelivery(0);
            CmpLoadingSystemHivesActive = 0;
            CmpMountThread = 0;
            CmpUnlockRegistry();
            ExFreePoolWithTag(v45);
            ExFreePoolWithTag((unsigned int)v44);
            return ExFreePoolWithTag((unsigned int)v4);
          }
          if ( *((_BYTE *)v9 + 35) == 1 )
            HvSyncHive(v9[7]);
          CmpLockHiveListExclusive();
          v16 = (void **)(v9[7] + 904);
          v17 = (void ***)off_92078C;
          *v16 = &CmpHiveListHead;
          v16[1] = v17;
          if ( *v17 != &CmpHiveListHead )
            __fastfail(3u);
          *v17 = v16;
          off_92078C = v16;
          CmpUnlockHiveList();
          v18 = CmRmSystem;
          if ( !CmRmSystem )
            goto LABEL_25;
          v26 = v9[7];
          if ( !v26 || (*((_DWORD *)v26 + 23) & 2) != 0 || *((_DWORD *)v26 + 814) )
          {
            v28 = v9[3];
            if ( !v28 || (*((_DWORD *)v28 + 23) & 2) != 0 || *((_DWORD *)v28 + 814) )
              goto LABEL_25;
            ++*(_DWORD *)(CmRmSystem + 32);
            v27 = v9[3];
          }
          else
          {
            ++*(_DWORD *)(CmRmSystem + 32);
            v27 = v9[7];
          }
          *((_DWORD *)v27 + 814) = v18;
LABEL_25:
          RtlInitUnicodeString((unsigned int)v47, (unsigned __int16 *)CmpMachineHiveList[v48 / 4]);
          v13 = v46;
          goto LABEL_26;
        }
      }
LABEL_26:
      v19 = (int)v9[7];
      if ( v19 )
        v19 = CmpAddToHiveFileList(v19);
      *((_BYTE *)v9 + 32) = 1;
      CmpNoMasterCreates = 0;
      switch ( i )
      {
        case 3u:
          v22 = CmpMountPreloadedHives(v19);
          CmpInterlockedFunction(v22);
          KeSetEvent((int)&unk_60E8E0, 0, 0);
          v13 = 1;
          if ( !byte_60E858 || !CmFastBoot )
            break;
          CmpUnlockRegistry();
          v30 = ExpRefreshSystemTime(v29);
          PsBootPhaseComplete(v30);
          goto LABEL_43;
        case 2u:
          CmpUnlockRegistry();
          v23 = KeSetEvent((int)&unk_60E880, 0, 0);
          v13 = 1;
          if ( byte_60E8B8 && CmFastBoot )
          {
            v24 = ExpRefreshSystemTime(v23);
            v23 = PsBootPhaseComplete(v24);
          }
          v25 = CmpSetVersionData(v23);
          CmpCreatePerfKeys(v25);
LABEL_43:
          CmpLockRegistryExclusive();
          break;
        case 1u:
          v20 = L"\\Registry\\Machine\\SAM\\SAM";
          v21 = L"\\Registry\\Machine\\Security\\SAM";
LABEL_36:
          CmpLinkKeyToHive(v21, v20);
          break;
        case 4u:
          v20 = L"\\Registry\\User\\.Default";
          v21 = L"\\Registry\\User\\S-1-5-18";
          goto LABEL_36;
      }
      CmpNoMasterCreates = 1;
      if ( !v13 )
        KeSetEvent((int)&unk_60E7C0 + v48, 0, 0);
      v10 = v43;
    }
    if ( v10 == 1 )
    {
      CmpUnlockRegistry();
      v2 = v44;
      continue;
    }
    break;
  }
  CmpSpecialBootCondition = 0;
  ExFreePoolWithTag(v45);
  ExFreePoolWithTag((unsigned int)v44);
  ExFreePoolWithTag((unsigned int)v4);
  if ( CmpShareSystemHives )
    CmpVEEnabled = 0;
  else
    CmpVEEnabled = CmVEEnabled == 1;
  CmpUnlockRegistry();
  v51 = 24;
  v52 = 0;
  v54 = 576;
  v53 = &CmpConfigurationManagerKeyName;
  v55 = 0;
  v56 = 0;
  result = ZwCreateKey();
  if ( result >= 0 )
  {
    ObReferenceObjectByHandle(v49, 2, (int)CmKeyObjectType, 0, (int)&v46, 0);
    CmpConfigurationManagerKeyObject = v46;
    result = ZwClose();
  }
  CmpLoadingSystemHivesActive = 0;
  CmpMountThread = 0;
  return result;
}
