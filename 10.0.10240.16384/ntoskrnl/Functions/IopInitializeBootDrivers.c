// IopInitializeBootDrivers 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopInitializeBootDrivers(_DWORD *a1)
{
  int v3; // r0
  int v4; // r0
  unsigned int v5; // r2
  int v6; // r3
  unsigned __int16 v7; // r1
  _DWORD *v8; // r3
  unsigned int v9; // r5
  unsigned int v10; // r4
  unsigned int v11; // r8
  int v12; // r6
  _DWORD *v13; // r6
  _DWORD *v14; // r4
  int v15; // r3
  _BYTE *v16; // r0
  unsigned int v17; // r5
  int v18; // r4
  _DWORD *v19; // r1
  unsigned __int16 v20; // r0
  int v21; // r3
  int ***v22; // r1
  int **i; // r2
  unsigned int *v24; // r2 OVERLAPPED
  unsigned int v25; // r1 OVERLAPPED
  unsigned int v26; // r2
  int v27; // r1
  int v28; // r6
  unsigned int v29; // r10
  int *v30; // r4
  int v31; // r8
  int v32; // r9
  int v33; // r0
  int v34; // r1
  _DWORD *v35; // r6
  int v36; // r3
  int v37; // r5
  int v38; // r6
  int v39; // r0
  int v40; // r0
  int v41; // r5
  _BYTE *v42; // r0
  int v43; // r0
  int v44; // r0
  unsigned __int16 *v45; // r10
  int v46; // r9
  unsigned int v47; // r8
  unsigned int k; // r1
  unsigned int *v49; // r2
  __int64 v50; // r4
  unsigned int v51; // r4
  __int64 v52; // kr00_8
  _DWORD *v53; // r5
  int v54; // r4
  int v55; // r3
  _DWORD *v56; // r4
  _DWORD *v57; // r2
  int v58; // r3
  _DWORD *v59; // r2
  _DWORD *j; // r0
  int v61; // r4
  unsigned __int16 *v62; // r8
  unsigned int v63; // r4
  _WORD *v64; // r0
  int v65; // r6
  unsigned int v66; // r0
  int v67; // r9
  unsigned int v68; // r10
  _BYTE *v69; // r0
  _BYTE *v70; // r6
  _DWORD *v71; // r6
  int v72; // r0
  int v73; // r2
  unsigned __int16 *v74; // r7
  int v75; // [sp+18h] [bp-190h] BYREF
  int v76; // [sp+1Ch] [bp-18Ch] BYREF
  unsigned __int16 *v77; // [sp+20h] [bp-188h] BYREF
  _DWORD *v78; // [sp+24h] [bp-184h] BYREF
  int v79[2]; // [sp+28h] [bp-180h] BYREF
  __int16 v80; // [sp+30h] [bp-178h]
  __int16 v81; // [sp+32h] [bp-176h]
  const __int16 *v82; // [sp+34h] [bp-174h]
  int v83; // [sp+38h] [bp-170h] BYREF
  int v84; // [sp+3Ch] [bp-16Ch] BYREF
  __int16 v85[2]; // [sp+40h] [bp-168h] BYREF
  int *v86; // [sp+44h] [bp-164h]
  char *v87; // [sp+48h] [bp-160h] BYREF
  int v88; // [sp+4Ch] [bp-15Ch]
  unsigned __int16 *v89; // [sp+50h] [bp-158h]
  int *v90; // [sp+54h] [bp-154h]
  __int16 v91[2]; // [sp+58h] [bp-150h] BYREF
  const __int16 *v92; // [sp+5Ch] [bp-14Ch]
  int v93; // [sp+60h] [bp-148h]
  int v94; // [sp+64h] [bp-144h]
  int *v95; // [sp+68h] [bp-140h]
  int v96; // [sp+6Ch] [bp-13Ch]
  int v97; // [sp+70h] [bp-138h]
  int v98; // [sp+74h] [bp-134h]
  char v99[144]; // [sp+78h] [bp-130h] BYREF
  __int16 v100[80]; // [sp+108h] [bp-A0h] BYREF

  v79[0] = 0;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_BootStart_Start) )
    return sub_968AA4();
  PnpDriverImageLoadPolicy = 3;
  v81 = 128;
  v80 = 126;
  v82 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\EarlyLaunch";
  if ( IopOpenRegistryKeyEx(&v75) >= 0
    || (v81 = 126,
        v80 = 124,
        v82 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\EarlyLaunch",
        IopOpenRegistryKeyEx(&v75) >= 0) )
  {
    v54 = IopGetRegistryValue(v75, L"DriverLoadPolicy", 0, (int *)&v78);
    ZwClose();
    if ( v54 >= 0 )
    {
      if ( v78[1] == 4 && v78[3] >= 4u )
        PnpDriverImageLoadPolicy = *(_DWORD *)((char *)v78 + v78[2]);
      ExFreePoolWithTag((unsigned int)v78);
    }
  }
  if ( PnpDriverImageLoadPolicy == 8 )
  {
    v55 = 0;
  }
  else
  {
    if ( (PnpDriverImageLoadPolicy & 0xFFFFFFF8) == 0 )
      goto LABEL_8;
    v55 = 3;
  }
  PnpDriverImageLoadPolicy = v55;
LABEL_8:
  PipInitializeCoreDriversAndElam((int)a1);
  PipInitComputerIds((int)a1);
  v91[1] = 32;
  v91[0] = 30;
  v92 = L"\\FileSystem\\RAW";
  v85[1] = 2;
  v85[0] = 0;
  v86 = &dword_97E66C;
  PnpInitializeBootStartDriver(v91, v85, RawInitialize);
  v77 = (unsigned __int16 *)v79[0];
  if ( !v79[0] )
    return 0;
  v3 = PpInitGetGroupOrderIndex(0);
  v76 = 0xFFFF;
  IopGroupIndex = v3;
  if ( v3 == 0xFFFF )
    goto LABEL_98;
  v4 = ExAllocatePoolWithTag(1, 8 * v3, 1852403792);
  IopGroupTable = v4;
  if ( !v4 )
    goto LABEL_98;
  v5 = IopGroupIndex;
  v6 = 0;
  if ( IopGroupIndex )
  {
    v7 = 0;
    do
    {
      v8 = (_DWORD *)(v4 + 8 * v6);
      *v8 = v8;
      v8[1] = v8;
      v6 = ++v7;
    }
    while ( v7 < v5 );
  }
  PipInitializeDriverDependentDLLs(2, (int)a1);
  RtlInitUnicodeString((unsigned int)&v87, L"System Reserved");
  RtlInitUnicodeString((unsigned int)v79, L"Boot Bus Extender");
  v9 = 0;
  v10 = 0;
  v11 = (unsigned __int16)PiInitGroupOrderTableCount;
  if ( PiInitGroupOrderTableCount )
  {
    v12 = PiInitGroupOrderTable;
    while ( 1 )
    {
      if ( RtlCompareUnicodeString((unsigned __int16 *)(v12 + 8 * v10), (unsigned __int16 *)&v87, 1) )
      {
        if ( RtlCompareUnicodeString((unsigned __int16 *)(v12 + 8 * v10), (unsigned __int16 *)v79, 1) )
          goto LABEL_18;
        v76 = v10;
      }
      v9 = (unsigned __int16)(v9 + 1);
LABEL_18:
      if ( v9 < 2 )
      {
        v10 = (unsigned __int16)(v10 + 1);
        if ( v10 < v11 )
          continue;
      }
      break;
    }
  }
  v13 = (_DWORD *)a1[8];
  while ( v13 != a1 + 8 )
  {
    v14 = v13;
    v15 = v13[7];
    v13 = (_DWORD *)*v13;
    if ( v15 >= 0 )
    {
      v16 = (_BYTE *)ExAllocatePoolWithTag(1, 28, 1852403792);
      v17 = (unsigned int)v16;
      if ( v16 )
      {
        memset(v16, 0, 28);
        *(_DWORD *)v17 = v17;
        *(_DWORD *)(v17 + 4) = v17;
        *(_DWORD *)(v17 + 12) = v14;
        if ( IopOpenRegistryKeyEx(&v75) < 0 )
        {
          ExFreePoolWithTag(v17);
        }
        else
        {
          *(_DWORD *)(v17 + 16) = v75;
          v18 = PpInitGetGroupOrderIndex(v75);
          v20 = PipGetDriverTagPriority(v75, v19);
          v21 = IopGroupTable;
          *(_WORD *)(v17 + 24) = v20;
          v22 = (int ***)(v21 + 8 * v18);
          for ( i = *v22; i != (int **)v22; i = (int **)*i )
          {
            if ( *((unsigned __int16 *)i + 12) > (unsigned int)v20 )
              break;
          }
          v24 = (unsigned int *)i[1];
          v25 = *v24;
          *(_QWORD *)v17 = *(_QWORD *)&v25;
          if ( *(unsigned int **)(v25 + 4) != v24 )
            __fastfail(3u);
          *(_DWORD *)(v25 + 4) = v17;
          *v24 = v17;
        }
      }
    }
  }
  PnpNotifyEarlyLaunchStatusUpdate();
  v26 = 0;
  if ( IopGroupIndex )
  {
    v27 = IopGroupTable;
    v28 = (int)v77;
    v29 = 0;
    while ( 1 )
    {
      v30 = *(int **)(v27 + 8 * v26);
      if ( v30 != (int *)(v27 + 8 * v29) )
        break;
LABEL_36:
      if ( v29 == v76 )
      {
        IopAllocateLegacyBootResources(0, 0);
        IopBootConfigsReserved = 1;
        IopAllocateBootResourcesRoutine = IopAllocateBootResources;
        v27 = IopGroupTable;
      }
      v26 = (unsigned __int16)(v29 + 1);
      v29 = v26;
      if ( v26 >= IopGroupIndex )
        goto LABEL_107;
    }
    while ( 1 )
    {
      v75 = v30[4];
      v31 = v30[3];
      v32 = *(_DWORD *)(v31 + 24);
      *((_BYTE *)v30 + 27) = 1;
      v33 = IopGetDriverNameFromKeyNode(v75);
      if ( v33 >= 0 )
        break;
      *((_BYTE *)v30 + 26) = 1;
LABEL_54:
      if ( !*((_BYTE *)v30 + 26) )
      {
        PnpLockDeviceActionQueue(v33, v34);
        PipAddDevicesToBootDriver(v28);
        PnpUnlockDeviceActionQueue();
        PnpWaitForEmptyDeviceActionQueue();
        PnpRequestDeviceAction(0, 7, 0, 0, 0, 0);
      }
      if ( PnpWaitForEmptyDeviceEventQueue() < 0 )
        goto LABEL_98;
      v30 = (int *)*v30;
      v27 = IopGroupTable;
      if ( v30 == (int *)(IopGroupTable + 8 * v29) )
        goto LABEL_36;
    }
    if ( IopGetRegistryValue(v75, L"Group", 0, (int *)&v78) < 0 )
    {
      v37 = 0;
    }
    else
    {
      v35 = v78;
      v36 = v78[3];
      if ( v36 )
      {
        LOWORD(v87) = v78[3];
        HIWORD(v87) = v36;
        v88 = (int)v78 + v78[2];
        v37 = PipLookupGroupName(&v87, 1);
      }
      else
      {
        v37 = 0;
      }
      ExFreePoolWithTag((unsigned int)v35);
    }
    v28 = 0;
    if ( PipCheckDependencies(v75) )
    {
      v38 = v30[2];
      v77 = (unsigned __int16 *)v38;
      v79[0] = v38;
      if ( v38 )
      {
LABEL_50:
        if ( v37 )
          ++*(_DWORD *)(v37 + 16);
        v30[2] = v38;
        v28 = (int)v77;
        goto LABEL_53;
      }
      if ( !*((_BYTE *)v30 + 26) )
      {
        v39 = PnpInitializeBootStartDriver(v85, v31 + 16, *(_DWORD *)(v32 + 28));
        v38 = v79[0];
        v30[5] = v39;
        v77 = (unsigned __int16 *)v38;
        if ( v38 )
        {
          ObfReferenceObject(v38);
          goto LABEL_50;
        }
      }
      v28 = (int)v77;
    }
    *((_BYTE *)v30 + 26) = 1;
LABEL_53:
    v33 = ExFreePoolWithTag((unsigned int)v86);
    goto LABEL_54;
  }
LABEL_107:
  PnpNotifyEarlyLaunchStatusUpdate();
  if ( (_DWORD *)a1[10] != a1 + 10 )
  {
    v56 = (_DWORD *)a1[10];
    while ( v56 != a1 + 10 )
    {
      v57 = v56;
      v58 = v56[7];
      v56 = (_DWORD *)*v56;
      if ( v58 >= 0 )
        IopUnloadDriver(v57 + 4, 1);
    }
    RtlInitUnicodeString((unsigned int)&v87, L"\\Registry\\Machine\\ELAM");
    v93 = 24;
    v94 = 0;
    v96 = 576;
    v95 = (int *)&v87;
    v97 = 0;
    v98 = 0;
    ZwUnloadKey2();
  }
  if ( (PnPBootDriversLoaded = 1, PnpRequestDeviceAction(0, 0, 0, 0, 0, 0), !PnpWaitForDevicesToStart())
    || IopCallBootDriverReinitializationRoutines() && !PnpWaitForDevicesToStart()
    || (!memicmp(a1[26], "ramdisk(", 8) ? (v40 = RamdiskStart(a1)) : (v40 = -1073741275),
        v40 >= 0 && !PnpWaitForDevicesToStart()) )
  {
LABEL_98:
    HeadlessKernelAddLogEntry();
    return 0;
  }
  v41 = 0;
  v42 = strstr((_BYTE *)a1[26], "vdisk(");
  if ( v42 && strstr(v42 + 1, "partition(") )
  {
    v59 = (_DWORD *)a1[32];
    for ( j = (_DWORD *)*v59; ; j = (_DWORD *)*j )
    {
      if ( j == v59 )
        goto LABEL_67;
      if ( j[10] )
        break;
    }
    v61 = VhdiGetDiskParameters(j[10], v99, v79, &v77);
    if ( v61 < 0 )
    {
      v41 = 1;
      goto LABEL_140;
    }
    v87 = v99;
    v62 = v77;
    v88 = v79[0];
    v89 = v77;
    v90 = &v76;
    v61 = PnpBootDeviceWait((int)a1, (int (__fastcall *)(int, int, __int16 *))VhdiInitializeBootDisk, (int)&v87);
    if ( v61 < 0 )
    {
      v41 = 2;
      goto LABEL_140;
    }
    v63 = wcslen(v62) + 29;
    v64 = (_WORD *)ExAllocatePoolWithTag(512, 2 * v63, 1113876566);
    v65 = (int)v64;
    if ( !v64 )
    {
      v41 = 3;
LABEL_131:
      v61 = -1073741801;
      goto LABEL_141;
    }
    v61 = RtlStringCbPrintfW(v64, 2 * v63, (int)L"\\\\Device\\HarddiskVolume%d%ws", v76);
    if ( v61 >= 0 )
    {
      v61 = VhdiMountVhdFile(v65);
      if ( v61 >= 0 )
      {
        NtVhdBootFile = v65;
        v66 = wcslen(v62);
        v67 = 2 * (v66 + 42);
        v68 = v66;
        v69 = (_BYTE *)ExAllocatePoolWithTag(512, v67, 1113876566);
        v70 = v69;
        if ( !v69 )
        {
          v41 = 7;
          goto LABEL_131;
        }
        memset(v69, 0, v67);
        v61 = RtlStringCbPrintfW((_WORD *)v70 + 4, 0x48u, (int)L"\\Device\\HarddiskVolume%lu", v76);
        if ( v61 >= 0 )
        {
          *((_DWORD *)v70 + 1) = 80;
          memmove((int)(v70 + 80), (int)v62, 2 * (v68 + 1));
          off_6180F8 = v70;
          dword_6180FC = v67;
          *v70 = 1;
        }
        else
        {
          v41 = 8;
        }
      }
      else
      {
        v41 = 5;
      }
    }
    else
    {
      v41 = 4;
    }
LABEL_140:
    if ( v61 < 0 )
LABEL_141:
      KeBugCheck2(303, v41, v61, 0, 0, 0);
  }
LABEL_67:
  if ( !PnpWaitForDevicesToStart() )
    goto LABEL_98;
  if ( IopCreateArcNames(a1) < 0 )
    return 0;
  v43 = PnpBootDeviceWait((int)a1, (int (__fastcall *)(int, int, __int16 *))IopMarkBootPartition, 0);
  PnPBootDriversInitialized = 1;
  v100[0] = 0;
  v44 = PipHardwareConfigGetIndex(v43, (int)&v76);
  v45 = (unsigned __int16 *)v76;
  v46 = v44;
  if ( v44 >= 0 )
    v46 = RtlStringCchPrintfExW((int)v100, 64, 0, 0, 2048, L"%d");
  v47 = 0;
  for ( k = IopGroupIndex; v47 < k; v47 = (unsigned __int16)(v47 + 1) )
  {
    while ( 1 )
    {
      v49 = (unsigned int *)(IopGroupTable + 8 * v47);
      if ( (unsigned int *)*v49 == v49 )
        break;
      v51 = *v49;
      v52 = *(_QWORD *)*v49;
      if ( (unsigned int *)HIDWORD(v52) != v49 || *(_DWORD *)(v52 + 4) != v51 )
        __fastfail(3u);
      *v49 = v52;
      *(_DWORD *)(v52 + 4) = v49;
      v53 = *(_DWORD **)(v51 + 8);
      if ( v46 >= 0
        && !*(_BYTE *)(v51 + 26)
        && !v53[1]
        && *(_DWORD *)(v53[6] + 4)
        && (v53[2] & 0x408) == 0
        && IopGetRegistryValue(*(_DWORD *)(v51 + 16), L"Start", 0, (int *)&v78) >= 0 )
      {
        v71 = v78;
        if ( v78[1] == 4 && v78[3] >= 4u )
        {
          v83 = *(_DWORD *)((char *)v78 + v78[2]);
          if ( !v83 )
          {
            v83 = 3;
            v72 = PnpCtxRegCreateKey(
                    (int *)PiPnpRtlCtx,
                    *(_DWORD *)(v51 + 16),
                    L"StartOverride",
                    (int)&PiPnpRtlCtx,
                    2,
                    0,
                    (int)&v84,
                    0);
            if ( v72 >= 0 )
            {
              PnpCtxRegSetValue(v72, v84, (int)v100, 4, (int)&v83, 4);
              PnpCtxRegCloseKey();
              v84 = 0;
              if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x800000) != 0 )
              {
                v76 = 0;
                if ( PnpUnicodeStringToWstr(&v76, 0, (unsigned __int16 *)(v53[6] + 12)) >= 0 )
                {
                  v74 = (unsigned __int16 *)v76;
                  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x800000) != 0 )
                    Template_qzq(
                      Microsoft_Windows_Kernel_PnPHandle,
                      dword_649E54,
                      v73,
                      (int)&Microsoft_Windows_Kernel_PnPHandle,
                      (int)v45,
                      (unsigned __int16 *)v76);
                  PnpUnicodeStringToWstrFree((unsigned int)v74, v53[6] + 12);
                }
              }
            }
          }
        }
        ExFreePoolWithTag((unsigned int)v71);
      }
      if ( v53 )
        ObfDereferenceObject((int)v53);
      if ( *(_BYTE *)(v51 + 26) )
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v51 + 12) + 24) + 52) |= 0x20000u;
      ZwClose();
      ExFreePoolWithTag(v51);
      k = IopGroupIndex;
    }
  }
  ExFreePoolWithTag(IopGroupTable);
  v50 = PnpEtwHandle;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_BootStart_Stop) )
    EtwWrite(v50, SHIDWORD(v50), (int)KMPnPEvt_BootStart_Stop, 0);
  return 1;
}
