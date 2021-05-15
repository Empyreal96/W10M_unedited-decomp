// IovpCallDriver1 
 
int __fastcall IovpCallDriver1(int *a1)
{
  int v2; // r5
  unsigned int v3; // r4
  int result; // r0
  int v5; // r6
  unsigned int v6; // r2
  unsigned __int8 *v7; // r8
  int v8; // r9
  unsigned int v9; // r0
  unsigned int v10; // r3
  int v11; // r3
  int v12; // r2
  bool v13; // zf
  int v14; // r2
  int v15; // r4
  int v16; // r10
  int v17; // r3
  int v18; // r4
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r3
  unsigned int *v22; // r2
  unsigned int v23; // r1
  int v24; // r3
  int v25; // r0
  char v26; // r1
  int v27; // r9
  int v28; // r0
  _DWORD *v29; // r4
  int v30; // r1
  int v31; // r2
  int v32; // r9
  int v33; // r0
  _DWORD *v34; // r2
  __int64 v35; // r0
  int v36; // r0
  int v37; // r2
  int v38; // r3
  int v39; // r2
  unsigned int *v40; // r2
  unsigned int v41; // r1
  int v42; // r1
  int v43; // r3
  int v44; // [sp+10h] [bp-48h]
  unsigned int v45; // [sp+14h] [bp-44h]
  int v46; // [sp+18h] [bp-40h]
  int v47; // [sp+1Ch] [bp-3Ch]
  int v48; // [sp+20h] [bp-38h]
  int v49; // [sp+24h] [bp-34h]
  _DWORD *v50; // [sp+28h] [bp-30h] BYREF
  int v51; // [sp+2Ch] [bp-2Ch]
  _DWORD v52[10]; // [sp+30h] [bp-28h] BYREF

  v2 = a1[25];
  v3 = KeGetCurrentIrql(a1);
  result = IovpPacketFromIrp(v2);
  v5 = result;
  if ( !result )
    return result;
  *(_BYTE *)(result + 41) = v3;
  *(_BYTE *)(result + 40) = v3;
  v6 = a1[26];
  v7 = (unsigned __int8 *)(*(_DWORD *)(v2 + 96) - 40);
  v48 = 0;
  v45 = v6;
  v8 = 0;
  if ( (*(_DWORD *)(result + 136) & 0x200) != 0
    && v3 < 2
    && !*(_DWORD *)(result + 128)
    && (!ViDriverKernelBase || v6 < ViDriverKernelBase || v6 >= ViDriverKernelEnd) )
  {
    if ( VfTargetDriversIsEnabled(v6) )
    {
      if ( (*(_DWORD *)(v2 + 8) & 0xC0) == 0 && !*(_BYTE *)(v2 + 33) )
      {
        v9 = VfRandomGetNumber(0, 0x64u);
        v10 = ViPendingProbability;
        __dmb(0xBu);
        if ( v9 < v10 )
        {
          v11 = *v7;
          if ( v11 == 13 )
          {
            v12 = *((_DWORD *)v7 + 4);
            if ( v12 == 589824
              || v12 == 589828
              || v12 == 589832
              || v12 == 589836
              || v12 == 589840
              || v12 == 589844
              || v12 == 589904
              || v12 == 589916 )
            {
              goto LABEL_28;
            }
            v13 = v12 == 590400;
LABEL_26:
            if ( v13 )
              goto LABEL_28;
            goto LABEL_27;
          }
          v14 = v7[1];
          if ( v11 != 12 )
          {
            if ( v11 == 17 )
            {
              v13 = v14 == 1;
              goto LABEL_26;
            }
            if ( v11 != 27 )
            {
LABEL_27:
              v8 = 1;
              goto LABEL_28;
            }
          }
          v13 = v14 == 2;
          goto LABEL_26;
        }
      }
    }
  }
LABEL_28:
  v15 = *(_DWORD *)(v5 + 140);
  v16 = a1[24];
  v47 = v15;
  if ( v15 || (v17 = *(_DWORD *)(v5 + 36), (v17 & 1) != 0) )
  {
    v44 = 0;
  }
  else
  {
    *(_DWORD *)(v5 + 36) = v17 | 1;
    v44 = 1;
    v15 = IovpSessionDataCreate(v16, v5, v8);
    v47 = v15;
  }
  *a1 = v15;
  a1[2] = v5;
  if ( v15 )
  {
    KeQuerySystemTime(v52);
    if ( v44 )
    {
      v18 = IovUtilGetBottomDeviceObject(v16);
      VfIrpLogRecordEvent(*(_DWORD *)(v5 + 136), v18, v2);
      ObfDereferenceObject(v18);
      __dmb(0xBu);
      v19 = (unsigned int *)(v5 + 12);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + 1, v19) );
      __dmb(0xBu);
      v15 = v47;
      ++*(_DWORD *)(v5 + 16);
      IovpSessionDataReference(v47);
    }
    if ( *(_DWORD *)(v2 + 56) )
    {
      VfErrorReport1(515, v45, v2);
      *(_DWORD *)(v2 + 56) = 0;
    }
    if ( (*(_DWORD *)(v5 + 36) & 0x10) != 0 )
      VfErrorReport1(517, v45, v2);
    if ( *(char *)(v2 + 35) <= *(char *)(v2 + 34) )
    {
      v21 = *v7;
      if ( (v21 == 3 || v21 == 4) && *(_DWORD *)(a1[25] + 4) && (MmVerifierData & 0x6000) != 0 )
        MdlInvariantPreProcessing1(__SPAIR64__(v5, (unsigned int)a1), (int)v7);
    }
    *(_DWORD *)(v15 + 28) = IovpExamineDevObjForwarding(v16, *(_DWORD *)(v15 + 24));
    IovpExamineIrpStackForwarding(v5, v44);
    if ( v8 )
    {
      __dmb(0xBu);
      v22 = (unsigned int *)(v5 + 12);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 + 1, v22) );
      __dmb(0xBu);
      v24 = *(_DWORD *)(v5 + 16);
      *(_DWORD *)(v5 + 128) = v7;
      *(_DWORD *)(v5 + 16) = v24 + 1;
      v48 = VfPendingStartLogging(v2);
    }
    v25 = VfMajorIsNewRequest(v46);
    v26 = *(_BYTE *)(v2 + 35);
    v27 = v25;
    v51 = v25;
    v28 = IovpAdvanceStackDownwards(v15 + 40, v26, (int)v7, v46, v49, v25, 1, &v50);
    v29 = v50;
    v31 = v52[0];
    v30 = v52[1];
    v50[8] = v52[0];
    v29[9] = v30;
    if ( v28 )
    {
      v32 = v44;
    }
    else
    {
      a1[3] |= 0x4000000u;
      a1[4] = (int)(a1 + 4);
      a1[5] = (int)(a1 + 4);
      v29[10] = v31;
      v29[11] = v30;
      v13 = v27 == 0;
      v32 = v44;
      v29[18] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( !v13 )
      {
        v29[14] = *(_DWORD *)(v2 + 24);
        v29[15] = *(_DWORD *)(v2 + 28);
        v29[16] = *(_DWORD *)(v2 + 24);
        v29[17] = *(_DWORD *)(v2 + 28);
        if ( v44 )
          v29[1] |= 0x8000000u;
      }
    }
    v33 = IovUtilGetLowerDeviceObject(v16);
    if ( v33 )
      ObfDereferenceObject(v33);
    else
      v29[1] |= 0x10000000u;
    v29[6] = VfGetPristineDispatchRoutine(*(_DWORD *)(v16 + 8), *v7);
    HIDWORD(v35) = v29 + 3;
    v34 = a1 + 4;
    v29[1] &= 0xBFFFFFFF;
    LODWORD(v35) = v29[3];
    *((_QWORD *)a1 + 2) = v35;
    if ( *(_DWORD **)(v35 + 4) != v29 + 3 )
      __fastfail(3u);
    *(_DWORD *)(v35 + 4) = v34;
    *(_DWORD *)HIDWORD(v35) = v34;
    a1[1] = (int)v29;
    a1[10] = v2;
    memmove((int)(a1 + 12), *(_DWORD *)(v2 + 96) - 40, 0x28u);
    if ( (v7[3] & 1) != 0 )
      a1[3] |= 0x1000000u;
    if ( *v7 == 27 && v7[1] == 2 )
    {
      a1[3] |= 0x20000000u;
      v36 = IovUtilGetBottomDeviceObject(v16);
      a1[9] = v36;
      ObfDereferenceObject(v36);
      if ( IovUtilIsInFdoStack(v16) && !IovUtilIsDeviceObjectMarked(v16, 3) )
        a1[3] |= 0x10000000u;
      VfDevObjMarkDeviceRemoved(v16);
    }
    if ( v32 )
      VfMajorVerifyNewIrp(v5, v2, v7, v29, v45);
    if ( v51 && (*(_DWORD *)(v5 + 36) & 0x80000) == 0 )
      VfMajorVerifyNewRequest(v5, v16, v46, v7, v29);
    VfMajorVerifyIrpStackDownward(v5, v16, v46, v7, v29);
    *(_DWORD *)(v47 + 24) = v16;
    *(_BYTE *)(v5 + 110) = *(_BYTE *)(v2 + 35);
    v37 = v29[2];
    *(_DWORD *)(v37 + 64) = *(_DWORD *)(v2 + 24);
    *(_DWORD *)(v37 + 68) = *(_DWORD *)(v2 + 28);
    v38 = *(char *)(v2 + 35);
    if ( v38 > 2 )
    {
      *(_BYTE *)(v2 + 35) = v38 - 1;
      v39 = *(_DWORD *)(v2 + 96) - 40;
      *(_DWORD *)(v2 + 96) = v39;
      *(_BYTE *)(v39 - 37) |= 0x10u;
      ++*(_BYTE *)(v2 + 35);
      *(_DWORD *)(v2 + 96) += 40;
    }
    IovpSessionDataReference(v47);
    __dmb(0xBu);
    v40 = (unsigned int *)(v5 + 12);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 + 1, v40) );
    __dmb(0xBu);
    v42 = a1[6];
    v43 = VfWdCancelTimeoutTicks;
    __dmb(0xBu);
    if ( v43 )
      ViWdBeforeCallDriver(v2, v42, v5 + 144);
  }
  result = VfIrpDatabaseEntryReleaseLock(v5);
  if ( v48 )
    result = VfPendingFinishLogging(v48);
  return result;
}
