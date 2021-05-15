// IoReportDetectedDevice 
 
int __fastcall IoReportDetectedDevice(int a1, unsigned int a2, int a3, int a4, int *a5, int a6, char a7, _DWORD *a8)
{
  int v8; // r9
  int v9; // r5
  int v10; // r6
  int v11; // r2
  bool v12; // zf
  int v14; // r8
  int v16; // r3
  unsigned __int16 *v17; // r1
  unsigned __int16 *v18; // r2
  int v19; // r4
  unsigned __int16 *v20; // r1
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r2
  int v28; // r3
  unsigned __int16 v29; // r1
  int v30; // r8
  _WORD *v31; // r0
  int v32; // r3
  __int16 v33; // r3
  int v34; // r3
  int v35; // r0
  int v36; // r1
  int v37; // r2
  int v38; // r3
  int v39; // r8
  int v40; // r0
  int v41; // r9
  int v42; // r0
  unsigned int v43; // r1
  __int16 v44; // r3
  int v45; // t1
  _DWORD *v46; // r8
  int v47; // r3
  int v48; // r0
  int v49; // r0
  int v50; // r0
  int v51; // r3
  int v52; // r3
  int v53; // r3
  int v54; // r3
  int v55; // r9
  int v56; // r1
  int v57; // r0
  __int16 *v58; // r1
  int v59; // r2
  int v60; // r3
  int v61; // r4
  int v62; // r0
  unsigned int v63; // r6
  int v64; // r2
  int v65; // r1
  int v66; // r3
  char v67[4]; // [sp+18h] [bp-208h] BYREF
  int v68; // [sp+1Ch] [bp-204h]
  int v69; // [sp+20h] [bp-200h] BYREF
  int v70; // [sp+24h] [bp-1FCh] BYREF
  int v71; // [sp+28h] [bp-1F8h] BYREF
  char v72[4]; // [sp+2Ch] [bp-1F4h] BYREF
  unsigned __int16 v73[2]; // [sp+30h] [bp-1F0h] BYREF
  _WORD *v74; // [sp+34h] [bp-1ECh]
  int v75; // [sp+38h] [bp-1E8h] BYREF
  _WORD *v76; // [sp+3Ch] [bp-1E4h] BYREF
  int v77; // [sp+40h] [bp-1E0h] BYREF
  unsigned int v78; // [sp+44h] [bp-1DCh] BYREF
  int v79; // [sp+48h] [bp-1D8h] BYREF
  int v80; // [sp+4Ch] [bp-1D4h] BYREF
  _DWORD *v81; // [sp+50h] [bp-1D0h] BYREF
  __int16 v82; // [sp+58h] [bp-1C8h] BYREF
  __int16 v83; // [sp+5Ah] [bp-1C6h]
  unsigned __int16 *v84; // [sp+5Ch] [bp-1C4h]
  int v85; // [sp+60h] [bp-1C0h]
  int v86; // [sp+64h] [bp-1BCh] BYREF
  _DWORD *v87; // [sp+68h] [bp-1B8h]
  int v88; // [sp+6Ch] [bp-1B4h] BYREF
  _WORD v89[216]; // [sp+70h] [bp-1B0h] BYREF

  v76 = (_WORD *)a4;
  v78 = a2;
  v79 = a3;
  v85 = a6;
  v82 = 0;
  v83 = 0;
  v84 = 0;
  v77 = 0;
  v69 = 0;
  v70 = 0;
  v67[0] = 0;
  v74 = v89;
  v73[1] = 400;
  v73[0] = 0;
  v75 = 0;
  v68 = 0;
  v8 = 0;
  v81 = 0;
  v86 = 0;
  v87 = a8;
  v9 = 0;
  v10 = *(_DWORD *)(a1 + 24);
  v11 = 4;
  v12 = *a8 == 0;
  v71 = 0;
  v14 = 0;
  v80 = 0;
  if ( !v12 )
    return sub_80C824();
  v16 = *(_DWORD *)(a1 + 8);
  if ( (v16 & 4) != 0 )
  {
    v17 = *(unsigned __int16 **)(v10 + 16);
    v18 = &v17[(*(unsigned __int16 *)(v10 + 12) >> 1) - 1];
    while ( v18 != v17 )
    {
      v45 = *v18--;
      if ( v45 == 92 )
      {
        v84 = v18 + 2;
        v11 = ((int)v18 - *(_DWORD *)(v10 + 16) + 4) >> 1;
        v16 = *(unsigned __int16 *)(v10 + 12) - 2 * v11;
        v82 = v16;
        v83 = v16;
        goto LABEL_6;
      }
    }
    return -1073741585;
  }
LABEL_6:
  v19 = RtlAppendUnicodeToString(v73, (int)L"ROOT\\", v11, v16);
  if ( v19 >= 0 )
  {
    v20 = (unsigned __int16 *)((*(_DWORD *)(a1 + 8) & 4) != 0 ? &v82 : v10 + 12);
    v19 = RtlAppendUnicodeStringToString(v73, v20);
    if ( v19 >= 0 )
    {
      v19 = PiPnpRtlBeginOperation(&v86, v21, v22, v23);
      if ( v19 < 0 )
        goto LABEL_42;
      PpDevNodeLockTree(1, v24);
      if ( (*(_DWORD *)(a1 + 8) & 4) == 0 )
      {
        v19 = IopDuplicateDetection(v78, v79, v76, &v71);
        v9 = v71;
        if ( v19 >= 0 )
        {
          if ( v71 )
          {
            v14 = 1;
            v80 = 1;
          }
        }
      }
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = *(__int16 *)(v25 + 0x134) - 1;
      *(_WORD *)(v25 + 308) = v26;
      ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v25, v26);
      if ( !v9 )
      {
        v19 = RtlAppendUnicodeToString(v73, (int)L"\\", v27, v28);
        if ( v19 >= 0 )
        {
          v29 = v73[0];
          v30 = 0;
          v31 = &v89[v73[0] >> 1];
          v78 = 400 - v73[0];
          v79 = v73[0];
          v76 = v31;
          while ( 1 )
          {
            v73[0] = v29;
            v69 = (int)v31;
            RtlStringCchPrintfExW((int)v31, v78 >> 1, &v69, 0, 0, L"%04u");
            v32 = (v69 - 2 * (v73[0] >> 1) - (int)v89) >> 1;
            v33 = v32 == -1 ? 400 - v73[0] : 2 * v32;
            v73[0] += v33;
            v19 = CmCreateDevice(PiPnpRtlCtx, (int)v74, 983103, &v70, v67, 0);
            v34 = (unsigned __int8)v67[0];
            if ( v19 < 0 )
              goto LABEL_119;
            v69 = (unsigned __int8)v67[0];
            if ( v67[0] )
              goto LABEL_24;
            v80 = 0;
            if ( IopIsReportedAlready(v73, v70, v10 + 12, a5, &v80) )
            {
              v35 = PnpDeviceObjectFromDeviceInstance((int)v73);
              v8 = v35;
              v81 = (_DWORD *)v35;
              if ( v35 )
              {
                v9 = *(_DWORD *)(*(_DWORD *)(v35 + 176) + 20);
              }
              else
              {
                v19 = -1073741823;
                v9 = 0;
              }
              v71 = v9;
LABEL_24:
              if ( v19 < 0 )
                goto LABEL_61;
              if ( v9 )
              {
                v14 = v80;
                goto LABEL_27;
              }
              v19 = IoCreateDevice(PnpDriverObject, 0, 0, 4u, 128, 0, &v81);
              if ( v19 < 0 )
                goto LABEL_61;
              v46 = v81;
              v41 = 1;
              v47 = v81[7];
              v48 = (int)v81;
              v68 = 1;
              v81[7] = v47 | 0x1000;
              v49 = PipAllocateDeviceNode(v48, &v71);
              v9 = v71;
              if ( v49 == -1073740946 || !v71 )
              {
                IoDeleteDevice(v46);
                v19 = -1073741670;
                goto LABEL_61;
              }
              if ( (*(_DWORD *)(a1 + 8) & 4) == 0 )
              {
                v50 = ExAllocatePoolWithTag(257, *(unsigned __int16 *)(v10 + 12), 1215327824);
                *(_DWORD *)(v9 + 32) = v50;
                if ( !v50 )
                  goto LABEL_81;
                v52 = *(unsigned __int16 *)(v10 + 12);
                *(_WORD *)(v9 + 30) = v52;
                v19 = RtlUpcaseUnicodeString((unsigned __int16 *)(v9 + 28), (unsigned __int16 *)(v10 + 12), 0, v52);
                if ( v19 < 0 )
                  goto LABEL_82;
              }
              v19 = PnpAllocateDeviceInstancePath(v9, v73[0] + 2);
              if ( v19 < 0 || (v19 = RtlUpcaseUnicodeString((unsigned __int16 *)(v9 + 20), v73, 0, v53), v19 < 0) )
              {
LABEL_82:
                PipSetDevNodeProblem(v9, 3, v19, v53);
                goto LABEL_38;
              }
              *(_WORD *)(*(_DWORD *)(v9 + 24) + 2 * (*(unsigned __int16 *)(v9 + 20) >> 1)) = 0;
              v88 = 32;
              v19 = CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v9 + 24), v70, 11, 4, (int)&v88, 4, 0);
              if ( v19 >= 0 )
              {
                v72[0] = -1;
                v19 = PnpSetObjectProperty(
                        PiPnpRtlCtx,
                        *(_DWORD *)(v9 + 24),
                        1,
                        v70,
                        0,
                        (int)DEVPKEY_Device_Reported,
                        17,
                        (int)v72,
                        1,
                        0);
                if ( v19 >= 0 )
                {
                  v19 = PnpUnicodeStringToWstr(&v79, &v78, (unsigned __int16 *)(v10 + 12));
                  if ( v19 >= 0 )
                  {
                    v55 = v79;
                    v19 = RtlStringCbLengthW(v79, v78, &v76);
                    if ( v19 < 0 )
                    {
                      PnpUnicodeStringToWstrFree(v55, v10 + 12);
                      goto LABEL_80;
                    }
                    v19 = CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v9 + 24), v70, 5, 1, v55, (int)(v76 + 1), 0);
                    PnpUnicodeStringToWstrFree(v55, v10 + 12);
                    if ( v19 >= 0 )
                    {
                      v77 = 0;
                      v19 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v9 + 24), 19, 0, 983103, 1u, (int)&v77, 0);
                      if ( v19 >= 0 )
                      {
                        v19 = PnpSetRegistryDword(v77, L"DeviceReported");
                        if ( v19 >= 0 )
                        {
                          if ( (*(_DWORD *)(a1 + 8) & 4) == 0 )
                            PpDeviceRegistration((int)v73, 1, v9 + 28, 1);
                          if ( (*(_DWORD *)(a1 + 8) & 4) != 0 )
                            v58 = &v82;
                          else
                            v58 = (__int16 *)(v10 + 12);
                          v19 = PpCreateLegacyDeviceIds(v46, v58, a5);
                          v57 = v9;
                          if ( v19 < 0 )
                          {
                            v56 = 19;
                            goto LABEL_86;
                          }
                          PipSetDevNodeFlags(v9, 17);
                          *(_DWORD *)(v9 + 420) = *(_DWORD *)(IopRootDeviceNode + 420);
                          PipSetDevNodeState((_DWORD *)v9, 770);
                          PpDevNodeInsertIntoTree((_DWORD *)IopRootDeviceNode, v9);
                          v19 = PnpMapDeviceObjectToDeviceInstance((int)v46, v9 + 20, v59, v60);
                          if ( v19 < 0 )
                          {
                            v56 = 3;
                            goto LABEL_84;
                          }
                          ObfReferenceObject((int)v46);
                          goto LABEL_33;
                        }
                      }
                    }
                  }
                }
              }
              goto LABEL_80;
            }
            ZwClose();
            v29 = v79;
            v31 = v76;
            ++v30;
          }
        }
LABEL_42:
        v42 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v44 = *(_WORD *)(v43 + 0x134) + 1;
        *(_WORD *)(v43 + 308) = v44;
        if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
          KiCheckForKernelApcDelivery(v42);
        PpDevNodeUnlockTree(1);
        if ( v75 )
          ZwClose();
        if ( v77 )
          ZwClose();
        if ( v70 )
          ZwClose();
        if ( v86 )
          PiPnpRtlEndOperation(v86);
        return v19;
      }
LABEL_27:
      if ( v14 )
      {
        if ( PipAreDriversLoaded(v9)
          || (v38 = *(_DWORD *)(v9 + 268), (v38 & 0x6000) != 0)
          && (v38 = *(_DWORD *)(v9 + 276), v38 != 1)
          && v38 != 18
          && v38 != 28 )
        {
          ObfDereferenceObject(*(_DWORD *)(v9 + 16));
          v19 = -1073741810;
          goto LABEL_61;
        }
        if ( !v8 )
          PipClearDevNodeProblem(v9, v36, v37, v38);
      }
      if ( !v70 )
      {
        v19 = PnpDeviceObjectToDeviceInstance(*(_DWORD *)(v9 + 16));
        if ( v19 < 0 )
          goto LABEL_61;
      }
LABEL_33:
      v39 = v85;
      if ( (a5 || v85)
        && ((v19 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v9 + 24), 20, 0, 983103, 1u, (int)&v75, 0), v19 < 0)
         || a5 && (v19 = PnpSetRegistryResourceList(v75), v19 < 0)
         || v39 && (v19 = PnpSetRegistryRequirementsList(v75), v19 < 0)) )
      {
LABEL_80:
        v56 = 19;
LABEL_84:
        v57 = v9;
LABEL_86:
        PipSetDevNodeProblem(v57, v56, v19, v54);
      }
      else if ( a7 )
      {
        PipSetDevNodeFlags(v9, 256);
        PnpSetRegistryDword(v70, L"NoResourceAtInitTime");
        v40 = PnpDetermineResourceListSize(a5);
        IopWriteAllocatedResourcesToRegistry(v9, a5, v40);
      }
      else if ( a5 && *a5 && a5[4] )
      {
        v61 = PnpDetermineResourceListSize(a5);
        v62 = ExAllocatePoolWithTag(1, v61, 1198550608);
        v63 = v62;
        if ( !v62 )
        {
LABEL_81:
          v19 = -1073741670;
          PipSetDevNodeProblem(v9, 3, -1073741670, v51);
LABEL_61:
          v34 = v69;
LABEL_119:
          if ( v34 )
          {
            if ( v75 )
              ZwDeleteKey();
            if ( v77 )
              ZwDeleteKey();
            if ( v70 )
              ZwDeleteKey();
            PnpCleanupDeviceRegistryValues(v9 + 20);
            PpDevNodeRemoveFromTree(v9);
            IoDeleteDevice(*(_DWORD **)(v9 + 16));
            ObfDereferenceObject(*(_DWORD *)(v9 + 16));
          }
          goto LABEL_42;
        }
        memmove(v62, (int)a5, v61);
        v64 = *(_DWORD *)(v9 + 16);
        v67[0] = 0;
        v19 = IoReportResourceUsageInternal(0, v65, *(_DWORD *)(v64 + 8), 0);
        ExFreePoolWithTag(v63);
        if ( v19 < 0 || v67[0] )
        {
          if ( !PipIsDevNodeDNStarted(v9) )
            PipSetDevNodeProblem(v9, 12, v19, v66);
          v19 = -1073741800;
        }
      }
      else
      {
        PipSetDevNodeFlags(v9, 256);
      }
      v41 = v68;
LABEL_38:
      if ( v19 >= 0 )
      {
        *(_DWORD *)(v9 + 420) = *(_DWORD *)(*(_DWORD *)(v9 + 8) + 420);
        IopDoDeferredSetInterfaceState(v9);
        PipSetDevNodeState((_DWORD *)v9, 775);
        if ( v41 )
          PipSetDevNodeFlags(v9, 0x80000000);
        *v87 = *(_DWORD *)(v9 + 16);
        goto LABEL_42;
      }
      goto LABEL_61;
    }
  }
  return v19;
}
