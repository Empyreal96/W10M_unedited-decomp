// PiProcessNewDeviceNode 
 
int __fastcall PiProcessNewDeviceNode(int a1)
{
  int v3; // r6
  int v4; // r8
  int v5; // r1
  int v6; // r2
  int v7; // r0
  _WORD *v8; // r0
  int v9; // r4
  char v10; // r3
  int v11; // r9
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r2
  int v15; // r4
  int v16; // r0
  unsigned __int16 *v17; // r4
  int v18; // r2
  int v19; // r0
  int v20; // r4
  int v21; // r9
  unsigned __int16 *v22; // r10
  unsigned int v23; // r2
  unsigned __int16 *v24; // r10
  BOOL v25; // r3
  int v26; // r10
  int v27; // r3
  int v28; // r2
  int v29; // r0
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  unsigned __int16 *v33; // r10
  unsigned int v34; // r9
  unsigned __int16 *v35; // r7
  int v36; // r2
  int v37; // r1
  unsigned int v38; // r2
  int v39; // r0
  unsigned int v40; // r1
  __int16 v41; // r3
  int v42; // r2
  int v43; // r3
  int v44; // r0
  unsigned int v45; // r1
  __int16 v46; // r3
  unsigned int v47; // r2
  int v48; // r9
  int v49; // r3
  int v50; // r3
  int v51; // r0
  int v52; // r2
  int v53; // r1
  int v54; // r3
  unsigned __int16 *v55; // r4
  int v56; // r1
  int v57; // r3
  unsigned int v58; // r4
  int v59; // r3
  int v60; // r2
  unsigned int v61; // r2
  int v62; // r0
  unsigned int v63; // r1
  __int16 v64; // r3
  int v65; // r0
  int v66; // r2
  int v67; // r1
  unsigned int v68; // r7
  int v69; // r0
  unsigned int v70; // r0
  int v71; // r3
  int v72; // r3
  int v73; // r1
  unsigned int v74; // r2
  int v75; // r0
  unsigned int v76; // r1
  int v77; // r3
  int v78; // r3
  int v79; // r2
  int v80; // r1
  int v81; // r3
  int v82; // r0
  int v83; // r2
  int v84; // r3
  int v85; // r5
  int v86; // r2
  int v87; // r2
  int v88; // r3
  int v89; // r0
  int v90; // r2
  int v91; // r3
  int v92; // r5
  int v93; // r2
  int v94; // r1
  int v95; // r3
  int v96; // r2
  int v97; // r3
  unsigned int v98; // r4
  int v99; // r3
  char v100[4]; // [sp+20h] [bp-D0h] BYREF
  unsigned int i; // [sp+24h] [bp-CCh] BYREF
  unsigned int v102; // [sp+28h] [bp-C8h] BYREF
  unsigned int v103; // [sp+2Ch] [bp-C4h] BYREF
  unsigned __int16 *v104; // [sp+30h] [bp-C0h] BYREF
  int v105; // [sp+34h] [bp-BCh]
  int v106; // [sp+38h] [bp-B8h] BYREF
  unsigned __int16 *v107; // [sp+3Ch] [bp-B4h]
  int v108; // [sp+40h] [bp-B0h] BYREF
  BOOL v109; // [sp+44h] [bp-ACh]
  unsigned __int8 v110; // [sp+48h] [bp-A8h]
  int v111; // [sp+4Ch] [bp-A4h]
  int v112; // [sp+50h] [bp-A0h] BYREF
  unsigned __int16 *v113; // [sp+54h] [bp-9Ch] BYREF
  _WORD *v114; // [sp+58h] [bp-98h]
  _WORD *v115; // [sp+5Ch] [bp-94h] BYREF
  _WORD *v116; // [sp+60h] [bp-90h] BYREF
  int v117; // [sp+64h] [bp-8Ch] BYREF
  int v118; // [sp+68h] [bp-88h] BYREF
  int v119; // [sp+6Ch] [bp-84h] BYREF
  unsigned __int16 v120[4]; // [sp+70h] [bp-80h] BYREF
  _DWORD v121[2]; // [sp+78h] [bp-78h] BYREF
  char v122[4]; // [sp+80h] [bp-70h] BYREF
  int v123; // [sp+84h] [bp-6Ch]
  char v124[48]; // [sp+C0h] [bp-30h] BYREF

  v118 = 0;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
    return sub_7CA7F4(&Microsoft_Windows_Kernel_PnPHandle);
  KeQuerySystemTime(v121);
  v111 = 0;
  v3 = 0;
  v4 = *(_DWORD *)(a1 + 16);
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v103 = 0;
  v104 = 0;
  v100[0] = 0;
  v105 = 0;
  PiPnpRtlBeginOperation(&v118, v5, v6, 0);
  PipClearDevNodeFlags(a1, 0x2000000);
  v114 = 0;
  v116 = 0;
  v7 = PnpQueryID(a1, 0, &v115, &v113);
  if ( v7 < 0 )
  {
    if ( v7 == -1073479624 )
      v111 = -1073741823;
    else
      v111 = v7;
  }
  else
  {
    v114 = v115;
    v8 = wcschr(v115, 92);
    v116 = v8 + 1;
    *v8 = 0;
  }
  v9 = PpIrpQueryCapabilities(v4, v122);
  PipClearDevNodeUserFlags(a1, 2);
  v10 = v123;
  v11 = 0;
  if ( v9 >= 0 )
  {
    if ( (v123 & 0x20000) != 0 )
    {
      PipSetDevNodeUserFlags(a1, 2);
      v10 = v123;
    }
    if ( (v10 & 0x40) != 0 )
      v11 = 1;
  }
  if ( (v10 & 0x20) != 0 )
  {
    if ( *(_DWORD *)(a1 + 372) == 4 )
      PpProfileCancelTransitioningDock(a1);
    *(_DWORD *)(a1 + 372) = 1;
  }
  else
  {
    *(_DWORD *)(a1 + 372) = 0;
  }
  PnpQueryDeviceText(*(_DWORD *)(a1 + 16), 0, PsDefaultSystemLocaleId, &v113);
  PnpQueryDeviceText(*(_DWORD *)(a1 + 16), 1, PsDefaultSystemLocaleId, &v115);
  v12 = PnpQueryID(a1, 3, &i, &v102);
  if ( v11 )
  {
    if ( v12 == -1073741637 )
    {
      PipSetDevNodeProblem(a1, 9, -1073741637);
      PipSetDevNodeFlags(*(_DWORD *)(a1 + 8), 0x200000);
      PnpSetInvalidIDEvent(*(_DWORD *)(a1 + 8) + 20);
    }
  }
  else if ( (*(_DWORD *)(a1 + 268) & 0x2000) == 0 || *(_DWORD *)(a1 + 276) != 9 )
  {
    v67 = *(_DWORD *)(a1 + 8);
    if ( v67 != IopRootDeviceNode )
    {
      v68 = i;
      v69 = *(_DWORD *)(v67 + 16);
      v102 = 0;
      v12 = PipMakeGloballyUniqueId(v69, i, &v102);
      if ( v68 )
        ExFreePoolWithTag(v68);
      v13 = v102;
      goto LABEL_16;
    }
  }
  v13 = i;
LABEL_16:
  for ( i = v13; ; i = v102 )
  {
    if ( v12 < 0 )
    {
      v78 = *(_DWORD *)(a1 + 268);
      v111 = v12;
      if ( (v78 & 0x2000) == 0 || *(_DWORD *)(a1 + 276) != 9 )
      {
        if ( v12 == -1073741670 )
        {
          v79 = -1073741670;
          v80 = 3;
        }
        else
        {
          v79 = v12;
          v80 = 19;
        }
        PipSetDevNodeProblem(a1, v80, v79);
      }
    }
    v15 = PiBuildDeviceNodeInstancePath(a1, v114, v116);
    if ( v15 < 0 )
      goto LABEL_202;
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
      Template_pz(
        Microsoft_Windows_Kernel_PnPHandle,
        dword_649E54,
        v14,
        (int)&Microsoft_Windows_Kernel_PnPHandle,
        a1,
        *(unsigned __int16 **)(a1 + 24));
    v16 = PiCreateDeviceInstanceKey(a1, &v103, &v104);
    v15 = v16;
    v107 = v104;
    if ( v16 < 0 )
      PipSetDevNodeProblem(a1, 19, v16);
    else
      v105 = v104 == (unsigned __int16 *)1 ? 0x20000 : 0;
    v3 = v103;
    if ( v15 < 0 )
LABEL_202:
      v111 = v15;
    PpMarkDeviceStackExtensionFlag(v4, 16, 1);
    PipSetDevNodeState((_DWORD *)a1, 770);
    v17 = v113;
    v18 = *(_DWORD *)(a1 + 268) & 0x2000;
    if ( v18 )
    {
      if ( *(_DWORD *)(a1 + 276) == 9 )
        break;
    }
    if ( v18 )
    {
      v81 = *(_DWORD *)(a1 + 276);
      if ( v81 == 3 || v81 == 19 )
        break;
    }
    if ( v107 == (unsigned __int16 *)1 )
    {
      v74 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v74 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      if ( v17 && v3 )
      {
        wcslen(v17);
        CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3);
      }
      v75 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v76 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v77 = (__int16)(*(_WORD *)(v76 + 0x134) + 1);
      *(_WORD *)(v76 + 308) = v77;
      if ( !v77 && *(_DWORD *)(v76 + 100) != v76 + 100 && !*(_WORD *)(v76 + 310) )
        KiCheckForKernelApcDelivery(v75);
      goto LABEL_29;
    }
    v19 = PnpDeviceObjectFromDeviceInstance(a1 + 20);
    v20 = v19;
    if ( !v19 )
      goto LABEL_29;
    if ( v19 == v4 )
    {
      ObfDereferenceObject(v19);
LABEL_29:
      if ( (*(_DWORD *)(a1 + 268) & 0x2000) != 0 && *(_DWORD *)(a1 + 276) == 42 )
        PipClearDevNodeProblem(a1);
      break;
    }
    if ( !v11 )
    {
      PpvUtilFailDriver(0);
      IoAddTriageDumpDataBlock(v4, *(unsigned __int16 *)(v4 + 2));
      v82 = *(_DWORD *)(v4 + 8);
      if ( v82 )
      {
        IoAddTriageDumpDataBlock(v82, *(__int16 *)(v82 + 2));
        v83 = *(_DWORD *)(v4 + 8);
        if ( *(_WORD *)(v83 + 28) )
        {
          IoAddTriageDumpDataBlock(v83 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(v4 + 8) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(v4 + 8) + 28));
        }
      }
      v84 = *(_DWORD *)(v4 + 176);
      v85 = *(_DWORD *)(v84 + 20);
      if ( v85 )
      {
        IoAddTriageDumpDataBlock(*(_DWORD *)(v84 + 20), 460);
        if ( *(_WORD *)(v85 + 20) )
        {
          IoAddTriageDumpDataBlock(v85 + 20, 2);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v85 + 24), *(unsigned __int16 *)(v85 + 20));
        }
        v86 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
        if ( *(_WORD *)(v86 + 28) )
        {
          IoAddTriageDumpDataBlock(v86 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 176) + 20) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v4 + 176) + 20) + 28));
        }
        v87 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 176) + 20) + 8);
        if ( v87 && *(_WORD *)(v87 + 28) )
        {
          IoAddTriageDumpDataBlock(v87 + 28, 2);
          v88 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 176) + 20) + 8);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v88 + 32), *(unsigned __int16 *)(v88 + 28));
        }
      }
      IoAddTriageDumpDataBlock(v20, *(unsigned __int16 *)(v20 + 2));
      v89 = *(_DWORD *)(v20 + 8);
      if ( v89 )
      {
        IoAddTriageDumpDataBlock(v89, *(__int16 *)(v89 + 2));
        v90 = *(_DWORD *)(v20 + 8);
        if ( *(_WORD *)(v90 + 28) )
        {
          IoAddTriageDumpDataBlock(v90 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(v20 + 8) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(v20 + 8) + 28));
        }
      }
      v91 = *(_DWORD *)(v20 + 176);
      v92 = *(_DWORD *)(v91 + 20);
      if ( v92 )
      {
        IoAddTriageDumpDataBlock(*(_DWORD *)(v91 + 20), 460);
        if ( *(_WORD *)(v92 + 20) )
        {
          IoAddTriageDumpDataBlock(v92 + 20, 2);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v92 + 24), *(unsigned __int16 *)(v92 + 20));
        }
        v93 = *(_DWORD *)(*(_DWORD *)(v20 + 176) + 20);
        if ( *(_WORD *)(v93 + 28) )
        {
          IoAddTriageDumpDataBlock(v93 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 176) + 20) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v20 + 176) + 20) + 28));
        }
        v94 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 176) + 20) + 8);
        if ( v94 && *(_WORD *)(v94 + 28) )
        {
          IoAddTriageDumpDataBlock(v94 + 28, 2);
          v95 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 176) + 20) + 8);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v95 + 32), *(unsigned __int16 *)(v95 + 28));
        }
      }
      KeBugCheckEx(202, 1, v4, v20, 0);
    }
    ZwClose();
    v3 = 0;
    v123 &= 0xFFFFFFBF;
    v103 = 0;
    v11 = 0;
    PipSetDevNodeProblem(a1, 42, 0);
    PnpLogDuplicateDevice(v114, i);
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 176) + 20) + 8) == *(_DWORD *)(a1 + 8) )
      PpvUtilFailDriver(0);
    ObfDereferenceObject(v20);
    v12 = PipMakeGloballyUniqueId(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 16), i, &v102);
    if ( i )
      ExFreePoolWithTag(i);
  }
  v21 = v105;
  if ( v3 )
  {
    PnpSetObjectProperty(
      PiPnpRtlCtx,
      *(_DWORD *)(a1 + 24),
      1,
      v3,
      0,
      (int)DEVPKEY_Device_LastKnownParent,
      18,
      *(_DWORD *)(*(_DWORD *)(a1 + 8) + 24),
      *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 20) + 2,
      v105);
    PnpSetObjectProperty(
      PiPnpRtlCtx,
      *(_DWORD *)(a1 + 24),
      1,
      v3,
      0,
      (int)DEVPKEY_Device_LastArrivalDate,
      16,
      (int)v121,
      8,
      v21);
    PnpSetObjectProperty(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 1, v3, 0, (int)DEVPKEY_Device_LastRemovalDate, 0, 0, 0, v21);
    PnpSetObjectProperty(
      PiPnpRtlCtx,
      *(_DWORD *)(a1 + 24),
      1,
      v3,
      0,
      (int)DEVPKEY_Device_HardwareConfigurationIndex,
      7,
      (int)&PnpCurrentHardwareConfigurationIndex,
      4,
      v21);
  }
  if ( (v123 & 0x4000) != 0 )
  {
    v96 = *(_DWORD *)(a1 + 268) & 0x2000;
    if ( (!v96 || *(_DWORD *)(a1 + 276) != 1) && (!v96 || *(_DWORD *)(a1 + 276) != 14) )
      PnpDisableDevice(a1, 29);
  }
  v22 = v115;
  if ( (*(_DWORD *)(a1 + 268) & 0x2000) == 0 || *(_DWORD *)(a1 + 276) != 9 )
  {
    if ( (*(_DWORD *)(a1 + 268) & 0x2000) == 0 || (v97 = *(_DWORD *)(a1 + 276), v97 != 3) && v97 != 19 )
    {
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v23 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      if ( v22 && v3 )
      {
        wcslen(v22);
        CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3);
      }
      v24 = v107;
      PnpSaveDeviceCapabilities(a1, v122, v107 == (unsigned __int16 *)1);
      v25 = v24 == (unsigned __int16 *)1;
      v26 = v25;
      v109 = v25;
      v112 = 4;
      if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3, 11, (int)&v117, (int)&v108, (int)&v112) >= 0
        && v117 == 4
        && (v27 = v112, v112 == 4) )
      {
        v28 = v108;
        if ( (v108 & 0x20) == 0 )
        {
          if ( (v108 & 0x40) == 0 )
          {
LABEL_41:
            v29 = PnpMapDeviceObjectToDeviceInstance(*(_DWORD *)(a1 + 16), a1 + 20, v28, v27);
            if ( v29 < 0 )
              v111 = v29;
            if ( !v26
              && PnpGetObjectProperty(
                   PiPnpRtlCtx,
                   *(_DWORD *)(a1 + 24),
                   1,
                   v3,
                   0,
                   (int)DEVPKEY_Device_FirmwareDependencies,
                   (int)&v119,
                   0,
                   0,
                   (int)&v112,
                   0) == -1073741789
              && v119 == 8210 )
            {
              v109 = 1;
            }
            v30 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
            v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v32 = *(_WORD *)(v31 + 0x134) + 1;
            *(_WORD *)(v31 + 308) = v32;
            if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
              KiCheckForKernelApcDelivery(v30);
            goto LABEL_47;
          }
          v73 = 28;
LABEL_155:
          if ( (v123 & 0x100) != 0 )
          {
            v108 = v28 | 0x400;
            CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3);
          }
          else
          {
            PipSetDevNodeProblem(a1, v73, 0);
          }
          goto LABEL_41;
        }
        v73 = 18;
        if ( (v108 & 1) != 0 )
          goto LABEL_155;
      }
      else
      {
        v28 = 0;
        v108 = 0;
        v73 = 1;
      }
      v26 = 1;
      v109 = 1;
      goto LABEL_155;
    }
  }
LABEL_47:
  PnpQueryID(a1, 1, &v104, &v102);
  v33 = v104;
  KseAddHardwareId(v104);
  PnpQueryID(a1, 2, &v103, &v116);
  v34 = v103;
  PnpGenerateDeviceIdsHash((int)v33, v103, (_DWORD *)(a1 + 444));
  PnpIrpQueryID(*(_DWORD *)(a1 + 16), 5, &v104);
  v35 = v104;
  if ( v104 )
  {
    RtlInitUnicodeString((unsigned int)v120, v104);
    if ( RtlGUIDFromString(v120, v124) < 0 )
    {
      ExFreePoolWithTag((unsigned int)v35);
      v35 = 0;
    }
  }
  if ( PiQueryRemovableDeviceOverride() >= 0 )
  {
    v36 = v110;
  }
  else
  {
    if ( (v123 & 0x20) != 0 || (v123 & 0x40000) != 0 )
      v36 = 0;
    else
      v36 = (v123 & 0x10) != 0;
    if ( v35 )
      goto LABEL_60;
  }
  if ( v107 == (unsigned __int16 *)1 )
    v37 = 0;
  else
    v37 = v3;
  if ( PipGenerateContainerID(a1, v37, v36, v35, &v104) >= 0 )
  {
    if ( v35 )
      ExFreePoolWithTag((unsigned int)v35);
    v35 = v104;
  }
  if ( v35 )
  {
LABEL_60:
    RtlInitUnicodeString((unsigned int)v120, v35);
    if ( RtlGUIDFromString(v120, (_BYTE *)(a1 + 424)) >= 0 )
      goto LABEL_61;
  }
  *(_DWORD *)(a1 + 424) = 0;
  *(_DWORD *)(a1 + 428) = 0;
  *(_DWORD *)(a1 + 432) = 0;
  *(_DWORD *)(a1 + 436) = 0;
LABEL_61:
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v38 + 308);
  ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
  PipSetDevNodeFlags(a1, 32);
  v39 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v41 = *(_WORD *)(v40 + 0x134) + 1;
  *(_WORD *)(v40 + 308) = v41;
  if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
    KiCheckForKernelApcDelivery(v39);
  if ( v3 )
  {
    if ( v35 )
    {
      v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v43 = *(__int16 *)(v42 + 0x134) - 1;
      *(_WORD *)(v42 + 308) = v43;
      ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v42, v43);
      PiDcUpdateDeviceContainerMembership(*(_DWORD *)(a1 + 24), v3, v35);
      v44 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v46 = *(_WORD *)(v45 + 0x134) + 1;
      *(_WORD *)(v45 + 308) = v46;
      if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
        KiCheckForKernelApcDelivery(v44);
    }
  }
  v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v47 + 308);
  ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
  if ( v3 )
  {
    v48 = (int)v116;
    if ( !v109 && v107 != (unsigned __int16 *)1 )
    {
      if ( PnpCheckDeviceIdsChanged(a1, v3, v33, v102, 1, v100) < 0 )
      {
        v49 = 0;
        v100[0] = 0;
      }
      else
      {
        v49 = (unsigned __int8)v100[0];
      }
      v106 = v49;
      if ( !v49 )
      {
        if ( PnpCheckDeviceIdsChanged(a1, v3, v103, v48, 0, v100) < 0 )
          v50 = 0;
        else
          v50 = (unsigned __int8)v100[0];
        v106 = v50;
      }
    }
    if ( v33 )
      CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3);
    if ( v103 )
    {
      v34 = v103;
      CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3);
    }
    else
    {
      v34 = 0;
    }
    if ( v106 )
    {
      if ( PpDevCfgCheckDeviceNeedsUpdate(*(_DWORD *)(a1 + 24), v3, &v104) >= 0 )
      {
        v98 = (unsigned int)v104;
        if ( v104 )
        {
          v112 = 4;
          if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3, 11, (int)&v117, (int)&v108, (int)&v112) >= 0
            && v117 == 4
            && v112 == 4 )
          {
            v99 = v108;
          }
          else
          {
            v99 = 0;
          }
          v108 = v99 | v98;
          CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v3);
          if ( (v98 & 0x20) != 0 )
          {
            v109 = 1;
            PipSetDevNodeProblem(a1, 18, 0);
          }
        }
      }
    }
  }
  v51 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v54 = (__int16)(*(_WORD *)(v53 + 0x134) + 1);
  *(_WORD *)(v53 + 308) = v54;
  if ( !(_WORD)v54 )
  {
    v54 = *(_DWORD *)(v53 + 100);
    v52 = v53 + 100;
    if ( v54 != v53 + 100 )
    {
      v54 = *(__int16 *)(v53 + 310);
      if ( !*(_WORD *)(v53 + 310) )
        KiCheckForKernelApcDelivery(v51);
    }
  }
  v55 = v113;
  if ( v3 )
  {
    v56 = 0;
    v106 = 0;
    v102 = 0;
    if ( v113 && (v70 = wcslen(v113), PnpFindAlternateStringData(v55, 2 * (v70 + 1), &v106, &v102)) )
      v57 = 25;
    else
      v57 = 18;
    PnpSetObjectProperty(
      PiPnpRtlCtx,
      *(_DWORD *)(a1 + 24),
      1,
      v3,
      0,
      (int)DEVPKEY_Device_BusReportedDeviceDesc,
      v57,
      (int)v55,
      v56,
      v105);
    if ( PnpGetDeviceLocationStrings(a1, (unsigned int *)&v106, (int *)&v102) >= 0 )
    {
      v58 = v106;
      PnpSetObjectProperty(
        PiPnpRtlCtx,
        *(_DWORD *)(a1 + 24),
        1,
        v3,
        0,
        (int)DEVPKEY_Device_LocationPaths,
        8210,
        v106,
        2 * v102,
        v105);
      ExFreePoolWithTag(v58);
      v55 = v113;
    }
  }
  PnpQueryBusInformation(a1, v53, v52, v54);
  if ( v109 && (v123 & 0x4000) == 0 && ((*(_DWORD *)(a1 + 268) & 0x2000) == 0 || *(_DWORD *)(a1 + 276) != 14) )
    PpDevCfgProcessDevice(a1, v3, v107 == (unsigned __int16 *)1);
  PiQueryResourceRequirements((_DWORD *)a1);
  v59 = *(_DWORD *)(a1 + 268);
  if ( (v59 & 0x2000) == 0 || (v59 = *(_DWORD *)(a1 + 276), v59 != 22) )
  {
    if ( (*(_DWORD *)(a1 + 268) & 0x2000) == 0
      || (v59 = *(_DWORD *)(a1 + 276), v59 != 29) && v59 != 14 && v59 != 9 && v59 != 3 && v59 != 19 )
    {
      PnpIsDeviceInstanceEnabled(v3, (unsigned __int16 *)(a1 + 20), 1, v59);
    }
  }
  if ( v3 )
    PnpInitializeSessionId(a1, v3, v107 == (unsigned __int16 *)1);
  PiQueryAndAllocateBootResources((_DWORD *)a1);
  v60 = *(_DWORD *)(a1 + 268) & 0x2000;
  if ( !v60 || *(_DWORD *)(a1 + 276) != 9 )
  {
    if ( !v60 || (v71 = *(_DWORD *)(a1 + 276), v71 != 3) && v71 != 19 )
    {
      v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v61 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      PnpSaveDeviceCapabilities(a1, v122, v107 == (unsigned __int16 *)1);
      v62 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v63 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v64 = *(_WORD *)(v63 + 0x134) + 1;
      *(_WORD *)(v63 + 308) = v64;
      if ( !v64 && *(_DWORD *)(v63 + 100) != v63 + 100 && !*(_WORD *)(v63 + 310) )
        KiCheckForKernelApcDelivery(v62);
      PpHotSwapUpdateRemovalPolicy(a1);
      v65 = PpDeviceRegistration(a1 + 20, 1, a1 + 28, 0);
      if ( v65 < 0 )
        PipSetDevNodeProblem(a1, 19, v65);
    }
  }
  v66 = *(_DWORD *)(a1 + 268) & 0x2000;
  if ( !v66 || *(_DWORD *)(a1 + 276) != 9 )
  {
    if ( !v66 || (v72 = *(_DWORD *)(a1 + 276), v72 != 3) && v72 != 19 )
    {
      PnpIrpDeviceEnumerated(v4);
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 1);
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 14);
      PnpSetPlugPlayEvent(&GUID_DEVICE_ENUMERATED, v4);
      PnpNewDeviceNodeDependencyCheck(a1);
    }
  }
  if ( v33 )
    ExFreePoolWithTag((unsigned int)v33);
  if ( v34 )
    ExFreePoolWithTag(v34);
  if ( v35 )
    ExFreePoolWithTag((unsigned int)v35);
  if ( v3 )
    ZwClose();
  if ( i )
    ExFreePoolWithTag(i);
  if ( v115 )
    ExFreePoolWithTag((unsigned int)v115);
  if ( v55 )
    ExFreePoolWithTag((unsigned int)v55);
  if ( v114 )
    ExFreePoolWithTag((unsigned int)v114);
  if ( v118 )
    PiPnpRtlEndOperation(v118);
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
    Template_p(Microsoft_Windows_Kernel_PnPHandle, dword_649E54, (int)KMPnPEvt_ProcessNewDevice_Stop, 0);
  return v111;
}
