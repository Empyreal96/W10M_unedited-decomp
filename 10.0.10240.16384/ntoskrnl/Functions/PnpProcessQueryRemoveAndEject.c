// PnpProcessQueryRemoveAndEject 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpProcessQueryRemoveAndEject(int *a1, int a2)
{
  int v2; // r5 OVERLAPPED
  int *v3; // r8
  int v4; // r4
  int v5; // r6
  int v6; // r7
  int v7; // r2
  int v9; // r3
  _DWORD *v10; // r0
  int v11; // r4
  int v12; // r9
  int v13; // r4
  int **v14; // r9
  _DWORD *v15; // r8
  _DWORD *v16; // r1
  int v17; // r3
  int v18; // r0
  int v19; // r0
  int *v20; // r4
  unsigned __int16 *v21; // r8
  int v22; // r10
  int v23; // r4
  int *v24; // r8
  int v25; // r1
  int v26; // t1
  int v27; // r3
  int v28; // r3
  int *v29; // r4
  int v30; // r2
  int j; // r0
  bool v32; // r3
  int v33; // r7
  _DWORD *v34; // r6
  unsigned int i; // r4
  int v36; // r4
  _DWORD *v37; // r8
  int v38; // r1
  int v39; // r8
  int v40; // r10
  int v41; // r0
  int v42; // r8
  int *v43; // r4
  int v44; // r1
  int v45; // t1
  int v46; // r3
  int v47; // r3
  int v48; // r0
  unsigned int v49; // r3
  int v50; // r6
  int v51; // r0
  _DWORD *v52; // r4
  unsigned int v53; // r8
  int v54; // r4
  _DWORD *v55; // r5
  int v56; // r2
  int v57; // r3
  int v58; // r4
  int v59; // r1
  int v60; // r2
  int v61; // r2
  int v62; // r3
  int v63; // r4
  int *v64; // r8
  int v65; // t1
  int v66; // r4
  int *v67; // r8
  int v68; // r1
  int v69; // t1
  int v70; // r3
  int v71; // r3
  int v72; // r1
  unsigned __int16 *v73; // r8
  _DWORD *v74; // r0
  int v75; // r0
  int v76; // r4
  int v77; // r3
  __int64 v78; // kr00_8
  _DWORD *v79; // r8
  _DWORD *v80; // r4
  __int64 v81; // r2
  int v82; // r4
  int *v83; // r8
  int v84; // r1
  int v85; // t1
  int v86; // r3
  int v87; // r3
  int v88; // r0
  unsigned int v89; // r4
  int **v90; // r10
  int v91; // r0
  int v92; // r3
  int v93; // r4
  int v94; // r6
  int v95; // r0
  int v96; // r4
  int v97; // r4
  int v98; // r6 OVERLAPPED
  char v99; // r0
  int v100; // r0
  int v101; // r1
  unsigned int v102; // [sp+10h] [bp-A8h] BYREF
  _DWORD *v103; // [sp+14h] [bp-A4h]
  int v104; // [sp+18h] [bp-A0h] BYREF
  int v105; // [sp+1Ch] [bp-9Ch]
  int *v106; // [sp+20h] [bp-98h]
  int v107; // [sp+24h] [bp-94h]
  int **v108; // [sp+28h] [bp-90h] BYREF
  unsigned int v109; // [sp+2Ch] [bp-8Ch] BYREF
  int v110; // [sp+30h] [bp-88h]
  unsigned __int16 *v111; // [sp+34h] [bp-84h]
  int v112; // [sp+38h] [bp-80h] BYREF
  int v113; // [sp+3Ch] [bp-7Ch]
  int *v114; // [sp+40h] [bp-78h]
  int v115; // [sp+44h] [bp-74h]
  int v116; // [sp+48h] [bp-70h] BYREF
  int v117; // [sp+4Ch] [bp-6Ch]
  int v118; // [sp+50h] [bp-68h]
  unsigned int v119; // [sp+54h] [bp-64h] BYREF
  int v120[2]; // [sp+58h] [bp-60h] BYREF
  int v121[6]; // [sp+60h] [bp-58h] BYREF
  int v122; // [sp+78h] [bp-40h] BYREF
  int v123; // [sp+7Ch] [bp-3Ch]
  int v124; // [sp+80h] [bp-38h]
  int v125; // [sp+88h] [bp-30h]
  unsigned int v126[10]; // [sp+90h] [bp-28h] BYREF

  v2 = *a1;
  v3 = a1;
  v126[0] = -1000000;
  v4 = *(_DWORD *)(v2 + 96);
  v126[1] = -1;
  v118 = 0;
  v119 = 0;
  v120[0] = 0;
  v106 = 0;
  v107 = v4;
  v102 = 0;
  v103 = 0;
  v114 = a1;
  v115 = 0;
  v125 = 0;
  v122 = 0;
  v124 = 0;
  v5 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
  v109 = 0;
  v117 = v6;
  PpDevNodeLockTree(1, a2);
  v7 = *(_DWORD *)(v6 + 172);
  if ( v7 == 787 || v7 == 788 )
  {
    v13 = -1073741738;
    goto LABEL_298;
  }
  if ( PnpCompareGuid((unsigned __int8 *)(v2 + 64), (int)&GUID_DEVICE_EJECT) )
    return sub_7DFCA4();
  if ( (*(_DWORD *)(v2 + 88) & 4) != 0 )
  {
    v56 = *(_DWORD *)(v6 + 176);
    if ( (*(_DWORD *)(v6 + 268) & 0x10) != 0 )
    {
      if ( v56 == 776 || v56 == 778 || v56 == 775 || v56 == 779 )
        v5 = 5;
      else
        v5 = 6;
    }
    else if ( v56 == 776 || v56 == 778 || v56 == 775 || v56 == 779 || (*(_DWORD *)(*(_DWORD *)(v4 + 176) + 16) & 4) != 0 )
    {
      v5 = 3;
    }
    else
    {
      v5 = 2;
    }
    v9 = 1;
  }
  else
  {
    v9 = 0;
  }
  v110 = v5;
  v123 = v9;
  if ( !v5 && (*(_DWORD *)(v6 + 268) & 0x1000) != 0 )
  {
    v59 = 1;
LABEL_152:
    v60 = v6 + 20;
LABEL_154:
    PnpFinalizeVetoedRemove(v2, v59, v60);
    v13 = -2147483608;
LABEL_298:
    v53 = 0;
    goto LABEL_107;
  }
  if ( !v5 && *(_DWORD *)(v2 + 8) == 22 && *(_DWORD *)(v6 + 388) )
  {
    v59 = 10;
    goto LABEL_152;
  }
  v10 = (_DWORD *)PnpAllocateCriticalMemory(v5, 1, 1036, 1299213904);
  v11 = (int)v10;
  v106 = v10;
  if ( !v10 )
  {
    v60 = 0;
    v59 = 0;
    goto LABEL_154;
  }
  v12 = (int)(v10 + 1);
  *v10 = 0;
  *((_WORD *)v10 + 3) = 512;
  *((_WORD *)v10 + 2) = 0;
  v10[2] = v10 + 3;
  v111 = (unsigned __int16 *)(v10 + 1);
  if ( !v5 && !PipAreDriversLoaded(v6) )
  {
    v61 = *(_DWORD *)(v6 + 172);
    v13 = 0;
    if ( v61 == 770 || v61 == 786 )
    {
      if ( (*(_DWORD *)(v6 + 268) & 0x6000) != 0 && !PipIsProblemReadonly(v6, *(_DWORD *)(v6 + 276)) )
        PipClearDevNodeProblem(v6);
      v62 = *(_DWORD *)(v2 + 88);
      if ( (*(_DWORD *)(v6 + 268) & 0x6000) != 0 )
      {
        if ( (v62 & 2) == 0 )
          v13 = -1073741811;
      }
      else if ( (v62 & 2) != 0 )
      {
        PipSetDevNodeProblem(v6, *(_DWORD *)(v2 + 8), 0);
      }
      else
      {
        PnpRestartDeviceNode(v6);
      }
    }
    goto LABEL_298;
  }
  v13 = PnpBuildRemovalRelationList(v107, v5, v11, v12, (int *)&v108);
  if ( v13 < 0 )
  {
    v60 = v12;
    v59 = *v106;
    goto LABEL_154;
  }
  v14 = v108;
  v105 = **v108;
  v103 = (_DWORD *)PnpAllocateCriticalMemory(v5, 512, 4 * v105, 1315991120);
  if ( !v103 )
  {
    v13 = -1073741670;
    goto LABEL_25;
  }
  v105 = 0;
  v112 = 1;
  v113 = 0;
  if ( IopEnumerateRelations(v14, &v112, &v104, &v116, 0) )
  {
    v15 = v103;
    while ( 1 )
    {
      if ( v116 || !v5 )
      {
        v16 = *(_DWORD **)(*(_DWORD *)(v104 + 176) + 20);
        if ( v5 )
        {
          if ( v5 != 2 )
          {
            v57 = v16[93];
            if ( v57 == 1 )
            {
              v115 = 1;
            }
            else if ( v57 )
            {
              v125 = 1;
            }
          }
        }
        else
        {
          if ( (v16[67] & 0x1000) != 0 )
          {
            PnpFinalizeVetoedRemove(v2, 1, v16 + 5);
            v13 = -1073741823;
            goto LABEL_175;
          }
          if ( v16[43] == 785 )
          {
            PnpFinalizeVetoedRemove(v2, 5, v16 + 5);
            v13 = -1073741823;
LABEL_24:
            v3 = v114;
            break;
          }
        }
        v17 = v105;
        *v15++ = v104;
        v105 = v17 + 1;
      }
      if ( !IopEnumerateRelations(v14, &v112, &v104, &v116, 0) )
        goto LABEL_24;
    }
  }
LABEL_25:
  if ( v13 < 0 || (v18 = PnpResizeTargetDeviceBlock(v3, v5), v2 = *v3, v13 = v18, v114 = (int *)*v3, v18 < 0) )
  {
LABEL_175:
    v53 = 0;
LABEL_176:
    IopFreeRelationList(v14);
    PnpFinalizeVetoedRemove(v2, 0, 0);
    goto LABEL_107;
  }
  v19 = PnpCompileDeviceInstancePaths(v5, v14, v123, 0, &v109);
  v13 = v19;
  if ( v5 == 3 )
  {
    PnpBuildUnsafeRemovalDeviceList(v19, v14, &v102);
    v119 = v102;
  }
  if ( v13 < 0 )
  {
    v53 = v109;
    goto LABEL_176;
  }
  if ( v115 )
  {
    PpProfileBeginHardwareProfileTransition(v125);
    v63 = v105 - 1;
    if ( v105 - 1 >= 0 )
    {
      v64 = &v103[v63];
      do
      {
        v65 = *v64--;
        v104 = v65;
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v65 + 176) + 20) + 372) == 1 )
          PpProfileIncludeInHardwareProfileTransition();
        --v63;
      }
      while ( v63 >= 0 );
    }
  }
  if ( v5 )
  {
    if ( v5 != 5 && v5 != 3 )
    {
      v39 = v109;
      v102 = v109;
      goto LABEL_68;
    }
    v40 = v107;
    PnpDeleteLockedDeviceNodes(v107, (int)v14, 3, 0, 0, 0, 0);
    v39 = v109;
    v102 = v109;
LABEL_69:
    if ( v5 == 3 )
    {
      v89 = v119;
      if ( v119 )
      {
        PnpNotifyUserModeDeviceRemoval(v2, v119, &GUID_DEVICE_SURPRISE_REMOVAL, 0, 0);
        ExFreePoolWithTag(v89);
      }
      v41 = PnpNotifyUserModeDeviceRemoval(v2, v39, &GUID_TARGET_DEVICE_REMOVE_COMPLETE, 0, 0);
    }
    else
    {
      v41 = PnpNotifyUserModeDeviceRemoval(v2, v39, &GUID_DEVICE_REMOVE_PENDING, 0, 0);
    }
    v42 = v105;
    if ( v105 > 0 )
    {
      v43 = v103;
      do
      {
        v45 = *v43++;
        v44 = v45;
        v104 = v45;
        if ( v45 )
          v46 = *(_DWORD *)(*(_DWORD *)(v44 + 176) + 20);
        else
          v46 = 0;
        if ( v5 || !v46 || (*(_DWORD *)(v46 + 456) & 2) == 0 )
          v41 = PnpNotifyTargetDeviceChange(&GUID_TARGET_DEVICE_REMOVE_COMPLETE, v44, 0);
        --v42;
      }
      while ( v42 );
      v42 = v105;
    }
    if ( v5 == 5 || v5 == 2 || v5 == 3 )
    {
      v41 = PnpInvalidateRelationsInList(v14, v5, 1, 0);
      v58 = **v14 - 1;
      if ( v58 >= 0 )
      {
        do
        {
          v41 = PipDeviceObjectListElementAt(*v14, v58, &v122, &v119, 0);
          if ( !v119 )
            v41 = PipDeviceObjectListRemove(*v14, v58);
          --v58;
        }
        while ( v58 >= 0 );
        v40 = v107;
      }
    }
    if ( v5 == 5 || v5 == 3 )
    {
      PnpUnlinkDeviceRemovalRelations(v41, (int)v14);
      if ( !*(_DWORD *)(v6 + 8) )
      {
        ++*(_DWORD *)(*(_DWORD *)(v6 + 412) + 416);
        *(_DWORD *)(v6 + 412) |= 1u;
      }
      PnpQueuePendingSurpriseRemoval(v40, &v108, *(_DWORD *)(v2 + 8), v5);
      PpDevNodeUnlockTree(1);
      v55 = v103;
      PnpIsChainDereferenced(v103, v42, 0, 1, 0);
      v53 = v102;
      v13 = 0;
      goto LABEL_109;
    }
    if ( *(_DWORD *)(v6 + 372) )
    {
      IopQueryDockRemovalInterface(v40, v120);
      v118 = v120[0];
      if ( v120[0] )
        (*(void (__fastcall **)(_DWORD, int))(v120[0] + 16))(*(_DWORD *)(v120[0] + 4), 3);
    }
    if ( v5 )
    {
      if ( v5 != 4 )
      {
        v47 = 0;
        goto LABEL_90;
      }
    }
    else
    {
      PipSetDevNodeFlags(v6, 0x2000000);
    }
    v47 = 1;
LABEL_90:
    v48 = PnpDeleteLockedDeviceNodes(v40, (int)v14, 2, v47, *(_DWORD *)(v2 + 8), 0, 0);
    v49 = *(_DWORD *)(v6 + 368);
    if ( v5 == 4 )
    {
      if ( ((v49 >> 3) & 1) == 0 && (v49 & 0x10000) == 0 )
      {
LABEL_100:
        PnpUnlinkDeviceRemovalRelations(v48, (int)v108);
        IopFreeRelationList(v108);
        v53 = v102;
        if ( v5 == 2 )
          PnpNotifyUserModeDeviceRemoval(v2, v102, &GUID_TARGET_DEVICE_REMOVE_COMPLETE, 0, 0);
        if ( !v5
          && (*(_DWORD *)(v2 + 88) & 2) == 0
          && (*(_DWORD *)(v6 + 268) & 0x2000) != 0
          && *(_DWORD *)(v6 + 276) == 18 )
        {
          PipClearDevNodeProblem(v6);
          PnpRestartDeviceNode(v6);
          PnpRequestDeviceAction(*(int **)(v6 + 16), 16, 1, 0, 0, 0);
        }
        v54 = v118;
        if ( v118 )
        {
          (*(void (__fastcall **)(_DWORD, int))(v118 + 16))(*(_DWORD *)(v118 + 4), 1);
          (*(void (__fastcall **)(_DWORD))(v54 + 12))(*(_DWORD *)(v54 + 4));
        }
        v13 = 0;
        goto LABEL_107;
      }
      v90 = v108;
      v112 = 1;
      v113 = 0;
      v91 = IopEnumerateRelations(v108, &v112, &v104, 0, 0);
      if ( v91 )
      {
        do
        {
          v92 = *(_DWORD *)(v104 + 176);
          v93 = *(_DWORD *)(v92 + 20);
          if ( v93 )
          {
            PipSetDevNodeFlags(*(_DWORD *)(v92 + 20), 0x80000);
            v94 = *(_DWORD *)(v93 + 452);
            if ( v94 )
            {
              IopFreeRelationList(*(_DWORD **)(v94 + 32));
              *(_DWORD *)(v94 + 32) = 0;
              *(_DWORD *)(v93 + 452) = 0;
            }
          }
          v91 = IopEnumerateRelations(v90, &v112, &v104, 0, 0);
        }
        while ( v91 );
        v6 = v117;
      }
      PnpUnlinkDeviceRemovalRelations(v91, (int)v90);
      v95 = ExAllocatePoolWithTag(512, 68, 538996816);
      v96 = v95;
      if ( v95 )
      {
        v98 = v107;
        ObfReferenceObject(v107);
        v99 = v115;
        *(_QWORD *)(v96 + 24) = *(_QWORD *)&v2;
        *(_DWORD *)(v96 + 32) = v90;
        *(_BYTE *)(v96 + 48) = v99;
        *(_BYTE *)(v96 + 49) = (*(_DWORD *)(v2 + 88) & 8) != 0;
        *(_DWORD *)(v96 + 56) = v118;
        *(_DWORD *)(v6 + 452) = v96;
        v100 = PoGetLightestSystemStateForEject();
        if ( v100 >= 0 )
        {
          PpDevNodeUnlockTree(1);
          IopEjectDevice(v98, v96);
          v53 = v102;
          v13 = 259;
          goto LABEL_108;
        }
        if ( v100 == -1073741090 )
          v101 = 9;
        else
          v101 = 0;
        PnpFinalizeVetoedRemove(v2, v101, 0);
        *(_DWORD *)(v96 + 24) = 0;
        *(_BYTE *)(v96 + 49) = 0;
        *(_DWORD *)v96 = v96;
        *(_DWORD *)(v96 + 4) = v96;
        PnpProcessCompletedEject(v96);
      }
      else
      {
        v97 = v118;
        if ( v118 )
        {
          (*(void (__fastcall **)(_DWORD, int))(v118 + 16))(*(_DWORD *)(v118 + 4), 1);
          v95 = (*(int (__fastcall **)(_DWORD))(v97 + 12))(*(_DWORD *)(v97 + 4));
        }
        if ( v115 )
          PpProfileCancelHardwareProfileTransition(v95);
        PnpInvalidateRelationsInList(v90, 4, 0, 1);
        IopFreeRelationList(v90);
        PnpFinalizeVetoedRemove(v2, 0, 0);
      }
      v13 = -2147483608;
      goto LABEL_188;
    }
    v112 = 1;
    v113 = 0;
    v48 = IopEnumerateRelations(v108, &v112, &v104, &v116, 0);
    if ( !v48 )
      goto LABEL_100;
    v50 = v107;
    while ( 1 )
    {
      v51 = v104;
      if ( v104 )
        v52 = *(_DWORD **)(*(_DWORD *)(v104 + 176) + 20);
      else
        v52 = 0;
      if ( *(_DWORD *)(v2 + 8) == 54 && v116 != 1 )
      {
        if ( v52[43] != 788 )
        {
          *(_DWORD *)(v104 + 28) |= 0x4000000u;
          IopQueryDeviceState(v51, v120);
        }
        goto LABEL_98;
      }
      if ( v50 == v104 )
      {
        if ( (*(_DWORD *)(v2 + 88) & 2) != 0 || v52[43] != 786 || (v52[67] & 0x2000) == 0 || v52[69] != 21 )
          goto LABEL_98;
        PipClearDevNodeProblem(v52);
      }
      else if ( (v52[67] & 0x6000) != 0 || v52[43] != 786 )
      {
        goto LABEL_98;
      }
      PnpRestartDeviceNode(v52);
LABEL_98:
      v48 = IopEnumerateRelations(v108, &v112, &v104, &v116, 0);
      if ( !v48 )
      {
        v5 = v110;
        v6 = v117;
        goto LABEL_100;
      }
    }
  }
  v20 = v106;
  v21 = v111;
  v102 = v109;
  v22 = PnpNotifyUserModeDeviceRemoval(v2, v109, &GUID_TARGET_DEVICE_QUERY_REMOVE, v106, v111);
  if ( v22 < 0 )
  {
    j = PnpFinalizeVetoedRemove(v2, *v20, v21);
    v39 = v102;
    goto LABEL_67;
  }
  v23 = 0;
  if ( v105 <= 0 )
    goto LABEL_45;
  v24 = v103;
  while ( 1 )
  {
    v26 = *v24++;
    v25 = v26;
    v104 = v26;
    v27 = v26 ? *(_DWORD *)(*(_DWORD *)(v25 + 176) + 20) : 0;
    if ( !v27 )
      break;
    v28 = *(_DWORD *)(v27 + 172);
    if ( v28 != 786 && v28 != 770 && v28 != 769 )
      break;
LABEL_43:
    if ( ++v23 >= v105 )
      goto LABEL_44;
  }
  if ( !*(_BYTE *)(v2 + 40) )
  {
    v22 = PnpNotifyTargetDeviceChange(&GUID_TARGET_DEVICE_QUERY_REMOVE, v25, 0);
    if ( v22 < 0 )
      goto LABEL_191;
    goto LABEL_43;
  }
  v22 = -1073741536;
LABEL_191:
  v21 = v111;
  *v106 = 7;
  if ( v124 )
    RtlCopyUnicodeString(v21, (unsigned __int16 *)(v124 + 28));
  else
    RtlInitUnicodeString((unsigned int)v21, 0);
  v66 = v23 - 1;
  if ( v66 >= 0 )
  {
    v67 = &v103[v66];
    do
    {
      v69 = *v67--;
      v68 = v69;
      v104 = v69;
      if ( v69 )
        v70 = *(_DWORD *)(*(_DWORD *)(v68 + 176) + 20);
      else
        v70 = 0;
      if ( !v70 || (v71 = *(_DWORD *)(v70 + 172), v71 != 786) && v71 != 770 && v71 != 769 )
        PnpNotifyTargetDeviceChange(&GUID_TARGET_DEVICE_REMOVE_CANCELLED, v68, 0);
      --v66;
    }
    while ( v66 >= 0 );
    v2 = (int)v114;
    v5 = v110;
    v6 = v117;
LABEL_44:
    v21 = v111;
  }
LABEL_45:
  if ( v22 < 0 )
  {
LABEL_242:
    v20 = v106;
    PnpFinalizeVetoedRemove(v2, *v106, v106 + 1);
    v39 = v102;
    j = PnpNotifyUserModeDeviceRemoval(v2, v102, &GUID_TARGET_DEVICE_REMOVE_CANCELLED, 0, 0);
    goto LABEL_67;
  }
  v29 = v106;
  v22 = PnpDeleteLockedDeviceNodes(v107, (int)v14, 0, 1, *(_DWORD *)(v2 + 8), (int)v106, (int)v21);
  memset(v121, 0, sizeof(v121));
  if ( !v5 || v5 == 4 )
  {
    v30 = 1;
    BYTE1(v121[5]) = 1;
  }
  else
  {
    v30 = BYTE1(v121[5]);
  }
  v121[4] = 0;
  v121[0] = 0;
  v121[3] = (int)&v121[2];
  v121[2] = (int)&v121[2];
  j = v6 + 20;
  v121[1] = v6 + 20;
  v32 = PnpDumpVetoedHandles || (NtGlobalFlag & 0x4000) != 0;
  LOBYTE(v121[5]) = v32;
  if ( v22 < 0 )
  {
    if ( *v29 != 6 )
      goto LABEL_58;
    v36 = v105;
    v37 = v103;
    PnpCollectOpenHandles(v103, v105, v121);
    v30 = BYTE1(v121[5]);
    j = v121[1];
  }
  else
  {
    v33 = v105;
    v34 = v103;
    for ( i = 0; i < 0x32; ++i )
    {
      if ( i )
        KeDelayExecutionThread(0, 0, v126);
      if ( !PnpIsChainDereferenced(v34, v33, 1, 0, &v122) )
        break;
    }
    v5 = v110;
    v6 = v117;
    if ( i == 50 )
    {
      v72 = v105;
      v73 = (unsigned __int16 *)v106;
      v74 = v103;
      *v106 = 5;
      PnpCollectOpenHandles(v74, v72, v121);
      if ( v122 )
      {
        v75 = IoGetDeviceAttachmentBaseRef(v122);
        v76 = v75;
        if ( v75 )
          v77 = *(_DWORD *)(*(_DWORD *)(v75 + 176) + 20);
        else
          v77 = 0;
        RtlCopyUnicodeString(v73 + 2, (unsigned __int16 *)(v77 + 20));
        ObfDereferenceObject(v76);
      }
      else
      {
        RtlInitUnicodeString((unsigned int)(v73 + 2), 0);
      }
      PnpDeleteLockedDeviceNodes(v107, (int)v14, 1, 1, 0, 0, 0);
      v22 = -1073741823;
    }
    v30 = BYTE1(v121[5]);
    j = v121[1];
LABEL_58:
    v36 = v105;
    v37 = v103;
  }
  if ( v30 )
  {
    for ( j = PnpLogVetoInformation(j, &v121[2]); ; j = ExFreePoolWithTag((unsigned int)v79) )
    {
      v38 = v121[2];
      if ( (int *)v121[2] == &v121[2] )
        break;
      v78 = *(_QWORD *)v121[2];
      if ( *(int **)(v121[2] + 4) != &v121[2] || *(_DWORD *)(v78 + 4) != v121[2] )
        __fastfail(3u);
      v121[2] = *(_DWORD *)v121[2];
      *(_DWORD *)(v78 + 4) = &v121[2];
      v79 = (_DWORD *)(v38 - 12);
      while ( 1 )
      {
        v80 = (_DWORD *)*v79;
        if ( (_DWORD *)*v79 == v79 )
          break;
        v81 = *(_QWORD *)v80;
        if ( (_DWORD *)v80[1] != v79 || *(_DWORD **)(v81 + 4) != v80 )
          __fastfail(3u);
        *v79 = v81;
        *(_DWORD *)(v81 + 4) = v79;
        ObfDereferenceObject(*(v80 - 1));
        ExFreePoolWithTag((unsigned int)(v80 - 1));
      }
    }
    v14 = v108;
    v36 = v105;
    v37 = v103;
  }
  if ( v22 < 0 )
  {
    v82 = v36 - 1;
    if ( v82 >= 0 )
    {
      v83 = &v37[v82];
      do
      {
        v85 = *v83--;
        v84 = v85;
        v104 = v85;
        if ( v85 )
          v86 = *(_DWORD *)(*(_DWORD *)(v84 + 176) + 20);
        else
          v86 = 0;
        if ( !v86 || (v87 = *(_DWORD *)(v86 + 172), v87 != 786) && v87 != 770 && v87 != 769 )
          PnpNotifyTargetDeviceChange(&GUID_TARGET_DEVICE_REMOVE_CANCELLED, v84, 0);
        --v82;
      }
      while ( v82 >= 0 );
      v2 = (int)v114;
      v5 = v110;
      v6 = v117;
    }
    goto LABEL_242;
  }
  if ( *(_DWORD *)(v2 + 8) == 54 )
  {
    j = PnpCancelRemoveOnHungDevices(v2, v5, v123, v14, &v109);
    v39 = v109;
    v22 = j;
    v102 = v109;
  }
  else
  {
    v39 = v102;
  }
  v20 = v106;
LABEL_67:
  if ( v22 >= 0 )
  {
LABEL_68:
    v40 = v107;
    goto LABEL_69;
  }
  if ( v115 )
    PpProfileCancelHardwareProfileTransition(j);
  if ( *(_DWORD *)(v2 + 8) != 54 )
    goto LABEL_186;
  v112 = 1;
  v113 = 0;
  if ( IopEnumerateRelations(v14, &v112, &v104, 0, 0) )
  {
    do
      *(_DWORD *)(v6 + 456) &= 0xFFFFFFFD;
    while ( IopEnumerateRelations(v14, &v112, &v104, 0, 0) );
    v2 = (int)v114;
  }
  if ( *(_DWORD *)(v2 + 8) == 54 && **v14 == 1 )
  {
    if ( *v20 == 6 || *(_DWORD *)(v6 + 172) == 788 )
      KeBugCheckEx(202, 14, v5, *v20, (int)v14);
    v88 = v107;
    *(_DWORD *)(v107 + 28) |= 0x4000000u;
    IopQueryDeviceState(v88, v120);
    v13 = 0;
  }
  else
  {
LABEL_186:
    v13 = -2147483608;
  }
  IopFreeRelationList(v14);
LABEL_188:
  v53 = v102;
LABEL_107:
  PpDevNodeUnlockTree(1);
LABEL_108:
  v55 = v103;
LABEL_109:
  if ( v106 && !dword_630874 )
    ExFreePoolWithTag((unsigned int)v106);
  if ( v53 )
    ExFreePoolWithTag(v53);
  if ( v55 )
    ExFreePoolWithTag((unsigned int)v55);
  return v13;
}
