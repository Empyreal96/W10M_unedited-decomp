// IopLoadDriver 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopLoadDriver(int a1, int a2, _BYTE *a3, int *a4)
{
  _BYTE *v4; // r4
  int v7; // r0
  unsigned int v9; // r1
  _BYTE *v10; // r0
  _BYTE *v11; // r6
  int v12; // r5
  int v13; // r1
  int v14; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r5 OVERLAPPED
  int v18; // r6 OVERLAPPED
  int v19; // r3
  int v20; // r2
  int v21; // r3
  int v22; // r0
  _BYTE *v23; // r6
  int v24; // r0
  char v25; // r0
  _BYTE *v26; // r4
  unsigned int v27; // r3
  int v28; // r0
  _BYTE *v29; // r2
  int v30; // r3
  char v31; // r3
  int v32; // r0
  int v33; // r6
  int v34; // r0
  int v35; // r0
  unsigned __int16 *v36; // r7
  int v37; // r0
  int v38; // r2
  __int64 v39; // kr00_8
  __int64 v40; // r8
  unsigned int v41; // r2
  unsigned int v42; // r1
  unsigned int v43; // r6
  unsigned int v44; // r4
  int v45; // r2
  __int64 v46; // r6
  unsigned __int16 *v47; // r1
  __int16 *v48; // r2
  int v49; // r3
  int v50; // r3
  int v51; // r0
  int v52; // r3
  int v53; // r3
  int v54; // r3
  int v55; // r4
  int v56; // r3
  int v57; // r4
  int v58; // r3
  int v59; // r3
  int v60; // r2
  int v61; // [sp+0h] [bp-F8h]
  int *v62; // [sp+4h] [bp-F4h]
  unsigned __int16 v63; // [sp+18h] [bp-E0h] BYREF
  __int16 v64; // [sp+1Ah] [bp-DEh]
  unsigned int v65; // [sp+1Ch] [bp-DCh]
  int v66[2]; // [sp+20h] [bp-D8h] BYREF
  unsigned __int16 v67; // [sp+28h] [bp-D0h] BYREF
  unsigned __int16 v68; // [sp+2Ah] [bp-CEh]
  int v69; // [sp+2Ch] [bp-CCh]
  _BYTE *v70[2]; // [sp+30h] [bp-C8h] BYREF
  unsigned __int16 v71; // [sp+38h] [bp-C0h] BYREF
  unsigned __int16 v72; // [sp+3Ah] [bp-BEh]
  int v73; // [sp+3Ch] [bp-BCh]
  _BYTE *v74; // [sp+40h] [bp-B8h] BYREF
  int v75; // [sp+44h] [bp-B4h] BYREF
  unsigned int v76; // [sp+48h] [bp-B0h] BYREF
  int *v77; // [sp+4Ch] [bp-ACh] BYREF
  unsigned int v78; // [sp+50h] [bp-A8h] BYREF
  _BYTE *v79; // [sp+54h] [bp-A4h]
  int v80; // [sp+58h] [bp-A0h] BYREF
  int v81[6]; // [sp+60h] [bp-98h] BYREF
  int v82[32]; // [sp+78h] [bp-80h] BYREF

  v4 = a3;
  *a4 = 0;
  v77 = a4;
  v78 = 0;
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v79 = 0;
  v80 = 0;
  v69 = 0;
  v70[0] = a3;
  v67 = 0;
  v68 = 0;
  v73 = 0;
  v71 = 0;
  v72 = 0;
  v7 = NtQueryKey(a1, 0, 0, 0, &v78);
  if ( v7 != -2147483643 && v7 != -1073741789 )
    return sub_7CA0B8();
  v9 = v78 + 8;
  if ( v78 + 8 < v78 )
    JUMPOUT(0x7CA0BC);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v49 = 40;
    else
      v49 = 32;
    v10 = (_BYTE *)ExAllocatePoolWithTagPriority(512, v9, 538996553, v49);
  }
  else
  {
    v10 = (_BYTE *)ExAllocatePoolWithTag(512, v9, 538996553);
  }
  v11 = v10;
  v74 = v10;
  if ( !v10 )
    goto LABEL_116;
  v12 = NtQueryKey(a1, 0, v10, v78, &v78);
  if ( v12 < 0 )
    goto LABEL_87;
  v13 = (unsigned __int16)*((_DWORD *)v11 + 3);
  v64 = v13 + 8;
  v65 = (unsigned int)(v11 + 16);
  v63 = v13;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v50 = 40;
    else
      v50 = 32;
    v14 = ExAllocatePoolWithTagPriority(1, v13 + 2, 538996553, v50);
  }
  else
  {
    v14 = ExAllocatePoolWithTag(1, v13 + 2, 538996553);
  }
  v69 = v14;
  if ( !v14 )
  {
    v12 = -1073741670;
    goto LABEL_147;
  }
  v68 = v63 + 2;
  v67 = v63;
  memmove(v14, v65, v63);
  v15 = v63 >> 1;
  v16 = v69;
  *(_WORD *)(v69 + 2 * v15) = 0;
  RtlAppendUnicodeToString(&v63, (int)L".SYS", v15, v16);
  HeadlessKernelAddLogEntry();
  *(_QWORD *)&v17 = PnpEtwHandle;
  v19 = PnpEtwHandle | HIDWORD(PnpEtwHandle);
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverLoad_Start) )
  {
    LOWORD(v66[0]) = v67 >> 1;
    v82[0] = (int)v66;
    v82[1] = 0;
    v82[2] = 2;
    v82[3] = 0;
    v82[6] = v67;
    v82[4] = v69;
    v82[5] = 0;
    v82[7] = 0;
    v62 = v82;
    v61 = 2;
    EtwWrite(v17, v18, (int)KMPnPEvt_DriverLoad_Start, 0);
    v4 = v70[0];
  }
  if ( !a2
    || (v19 = InitSafeBootMode) == 0
    || (RtlInitUnicodeString((unsigned int)v66, L"Group"),
        memset(v82, 0, 76),
        v51 = NtQueryValueKey(a1, v66, 2, (int)v82, 76, (unsigned int)v70),
        v51 >= 0
     && (LOWORD(v66[0]) = LOWORD(v82[2]) - 2,
         HIWORD(v66[0]) = LOWORD(v82[2]) - 2,
         v66[1] = (int)&v82[3],
         IopSafebootDriverLoad(v66)))
    || IopSafebootDriverLoad(&v63) )
  {
    v12 = IopBuildFullDriverPath(&v67, a1, &v63, v19, v61, v62);
    if ( v12 >= 0 )
    {
      v12 = IopGetDriverNameFromKeyNode(a1, &v71);
      if ( v12 >= 0 )
      {
        v81[0] = 24;
        v81[1] = 0;
        if ( IopCaseInsensitive )
          v21 = 64;
        else
          v21 = 0;
        v81[3] = v21 | 0x210;
        v81[2] = (int)&v71;
        v81[4] = 0;
        v81[5] = 0;
        ExAcquireResourceExclusiveLite((int)&IopDriverLoadResource, 1, v20, 0);
        v22 = MmLoadSystemImage((int)&v63, 0);
        v12 = v22;
        if ( v22 < 0 )
        {
          if ( v22 == -1073741554 )
          {
            v12 = ObOpenObjectByName((int)v81, IoDriverObjectType, 0, 0, 0, 0, &v75);
            if ( v12 < 0 )
            {
              ExReleaseResourceLite((int)&IopDriverLoadResource);
              IopBootLog(&v63, 0);
              if ( v12 == -1073741772 )
                v12 = -1073740914;
              goto LABEL_65;
            }
            v12 = ObReferenceObjectByHandle(v75, 0, IoDriverObjectType, 0, (int)v66, 0);
            ZwClose();
            if ( v12 >= 0 )
            {
              v12 = IopResurrectDriver(v66[0]);
              ObfDereferenceObject(v66[0]);
            }
          }
          ExReleaseResourceLite((int)&IopDriverLoadResource);
          IopBootLog(&v63, 0);
          goto LABEL_65;
        }
        v23 = v70[0];
        v24 = RtlImageNtHeader((int)v70[0]);
        v79 = (_BYTE *)(*(unsigned __int16 *)(v24 + 70) | (*(unsigned __int16 *)(v24 + 68) << 16));
        v12 = PnpPrepareDriverLoading(&v67, a1, v23, v4, &v80, v70);
        if ( v12 < 0
          || (v25 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
              v12 = ObCreateObject(v25, (_DWORD *)IoDriverObjectType, (int)v81, 0, 0, 208, 0, 0, v70),
              v12 < 0) )
        {
          MmUnloadSystemImage(v66[0]);
          ExReleaseResourceLite((int)&IopDriverLoadResource);
        }
        else
        {
          v26 = v70[0];
          memset(v70[0], 0, 208);
          *((_DWORD *)v26 + 6) = v26 + 168;
          *((_DWORD *)v26 + 42) = v26;
          v27 = 0;
          v76 = 0;
          do
          {
            *(_DWORD *)&v26[4 * v27 + 56] = IopInvalidDeviceRequest;
            v27 = v76 + 1;
            v76 = v27;
          }
          while ( v27 <= 0x1B );
          *(_WORD *)v26 = 4;
          *((_WORD *)v26 + 1) = 168;
          v28 = RtlImageNtHeader((int)v23);
          v79 = (_BYTE *)(*(unsigned __int16 *)(v28 + 70) | (*(unsigned __int16 *)(v28 + 68) << 16));
          v29 = &v23[*(_DWORD *)(v28 + 40)];
          if ( (*(_WORD *)(v28 + 94) & 0x2000) == 0 )
            *((_DWORD *)v26 + 2) |= 2u;
          v30 = v66[0];
          *((_DWORD *)v26 + 11) = v29;
          *((_DWORD *)v26 + 5) = v30;
          *((_DWORD *)v26 + 3) = v23;
          *((_DWORD *)v26 + 4) = *(_DWORD *)(v28 + 80);
          v12 = ObInsertObject((int)v26, 0, 1, 0, 0, (int)&v75);
          ExReleaseResourceLite((int)&IopDriverLoadResource);
          if ( v12 >= 0 )
          {
            v31 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
            v32 = ObReferenceObjectByHandle(v75, 0, IoDriverObjectType, v31, (int)v66, 0);
            if ( v32 )
              KeBugCheckEx(287, v75, v32, v66[0], 0);
            ZwClose();
            v33 = v66[0];
            *(_DWORD *)(v66[0] + 36) = &CmRegistryMachineHardwareDescriptionSystemName;
            if ( ViVerifierDriverAddedThunkListHead )
            {
              if ( (MmVerifierData & 0x10) != 0 )
                v52 = 40;
              else
                v52 = 32;
              v34 = ExAllocatePoolWithTagPriority(512, v72, 538996553, v52);
            }
            else
            {
              v34 = ExAllocatePoolWithTag(512, v72, 538996553);
            }
            *(_DWORD *)(v33 + 32) = v34;
            if ( v34 )
            {
              *(_WORD *)(v33 + 30) = v72;
              *(_WORD *)(v33 + 28) = v71;
              memmove(*(_DWORD *)(v33 + 32), v73, v72);
            }
            if ( ViVerifierDriverAddedThunkListHead )
            {
              if ( (MmVerifierData & 0x10) != 0 )
                v53 = 40;
              else
                v53 = 32;
              v35 = ExAllocatePoolWithTagPriority(512, 0x1000u, 538996553, v53);
            }
            else
            {
              v35 = ExAllocatePoolWithTag(512, 4096, 538996553);
            }
            v36 = (unsigned __int16 *)v35;
            if ( v35 )
            {
              v12 = NtQueryObject(a1, 1, v35, 0x1000u, (unsigned int)&v76);
              if ( v12 < 0 )
              {
                ObMakeTemporaryObject(v33);
                ObfDereferenceObject(v33);
                ExFreePoolWithTag((unsigned int)v36);
              }
              else
              {
                if ( v69 )
                {
                  if ( ViVerifierDriverAddedThunkListHead )
                  {
                    v54 = (MmVerifierData & 0x10) != 0 ? 40 : 32;
                    v37 = ExAllocatePoolWithTagPriority(512, v68, 538996553, v54);
                  }
                  else
                  {
                    v37 = ExAllocatePoolWithTag(512, v68, 538996553);
                  }
                  *(_DWORD *)(*(_DWORD *)(v33 + 24) + 16) = v37;
                  v38 = *(_DWORD *)(v33 + 24);
                  if ( *(_DWORD *)(v38 + 16) )
                  {
                    *(_WORD *)(v38 + 14) = v68;
                    *(_WORD *)(*(_DWORD *)(v33 + 24) + 12) = v67;
                    memmove(*(_DWORD *)(*(_DWORD *)(v33 + 24) + 16), v69, v68);
                  }
                }
                if ( (v80 & 1) != 0 )
                  *(_DWORD *)(v33 + 8) |= 0x100u;
                v39 = PnpEtwHandle;
                if ( PnpEtwHandle
                  && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverInit_Start) )
                {
                  v55 = *v36;
                  LOWORD(v66[0]) = *v36 >> 1;
                  v82[0] = (int)v66;
                  v82[1] = 0;
                  v82[2] = 2;
                  v82[3] = 0;
                  v56 = *((_DWORD *)v36 + 1);
                  v82[6] = v55;
                  v82[4] = v56;
                  v82[5] = 0;
                  v82[7] = 0;
                  EtwWrite(v39, SHIDWORD(v39), (int)KMPnPEvt_DriverInit_Start, 0);
                }
                v12 = (*(int (__fastcall **)(int, unsigned __int16 *))(v33 + 44))(v33, v36);
                if ( v12 >= 0 )
                {
                  VfXdvDriverCaptureIoCallbacks(v33);
                  KseShimDriverIoCallbacks(v33);
                }
                v40 = PnpEtwHandle;
                v70[0] = (_BYTE *)v12;
                if ( PnpEtwHandle
                  && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverInit_Stop) )
                {
                  v57 = *v36;
                  LOWORD(v66[0]) = *v36 >> 1;
                  v82[0] = (int)v66;
                  v82[1] = 0;
                  v82[2] = 2;
                  v82[3] = 0;
                  v58 = *((_DWORD *)v36 + 1);
                  v82[6] = v57;
                  v82[4] = v58;
                  v82[5] = 0;
                  v82[7] = 0;
                  v82[8] = (int)v70;
                  v82[9] = 0;
                  v82[10] = 4;
                  v82[11] = 0;
                  EtwWrite(v40, SHIDWORD(v40), (int)KMPnPEvt_DriverInit_Stop, 0);
                }
                *v77 = v12;
                if ( v12 < 0 )
                  v12 = -1073740955;
                v41 = 0;
                v76 = 0;
                do
                {
                  v42 = v33 + 4 * v41;
                  if ( !*(_DWORD *)(v42 + 56) )
                  {
                    *(_DWORD *)(v42 + 56) = IopInvalidDeviceRequest;
                    v41 = v76;
                  }
                  v76 = ++v41;
                }
                while ( v41 <= 0x1B );
                ExFreePoolWithTag((unsigned int)v36);
                if ( v12 >= 0 )
                {
                  if ( !PnpIsLegacyDriver(v33) )
                  {
                    v12 = 0;
                    if ( !*(_DWORD *)(v33 + 4)
                      && v69
                      && !PnpIsAnyDeviceInstanceEnabled(&v67)
                      && (*(_DWORD *)(v33 + 8) & 0x808) == 0 )
                    {
                      PnpDriverLoadingFailed(a1, 0);
                      v12 = -1073741218;
                    }
                    if ( v12 >= 0 )
                      goto LABEL_64;
                    if ( *(_DWORD *)(v33 + 52) )
                    {
                      *(_DWORD *)(v33 + 8) |= 1u;
                      (*(void (__fastcall **)(int))(v33 + 52))(v33);
                      IopBootLog(&v63, 0);
                    }
                  }
                  if ( v12 >= 0 )
                  {
LABEL_64:
                    IopBootLog(&v63, 1);
                    MiFreeDriverInitialization(*(_DWORD *)(v33 + 20));
                    IopReadyDeviceObjects(v33);
                    goto LABEL_65;
                  }
                }
                ObMakeTemporaryObject(v33);
                ObfDereferenceObject(v33);
              }
LABEL_65:
              if ( v12 >= 0 )
              {
LABEL_66:
                HeadlessKernelAddLogEntry();
                v43 = (unsigned int)v74;
                goto LABEL_67;
              }
              goto LABEL_87;
            }
            ObMakeTemporaryObject(v33);
            ObfDereferenceObject(v33);
LABEL_116:
            v12 = -1073741670;
            goto LABEL_88;
          }
        }
        IopBootLog(&v63, 0);
        goto LABEL_65;
      }
LABEL_87:
      if ( v12 == -1073741554 )
        goto LABEL_66;
LABEL_88:
      v43 = (unsigned int)v74;
      HeadlessKernelAddLogEntry();
LABEL_67:
      if ( v12 < 0 && v12 != -1073741554 && v12 != -1073741218 )
      {
        PnpDriverLoadingFailed(a1, 0);
        if ( v12 != -1073740955 && IopGetRegistryValue(a1, L"ErrorControl", 0, &v77) >= 0 )
        {
          if ( v77[3] )
          {
            v47 = v65 ? &v63 : 0;
            v48 = (__int16 *)(v73 ? &v71 : 0);
            if ( CmFirstTime == 1 && (unsigned int)(*(int *)((char *)v77 + v77[2]) - 2) <= 1 )
            {
              if ( v47 )
                v59 = *((_DWORD *)v47 + 1);
              else
                v59 = 0;
              if ( v48 )
                v60 = *((_DWORD *)v48 + 1);
              else
                v60 = 0;
              KeBugCheckEx(90, 1, v60, v59, v12);
            }
          }
          ExFreePoolWithTag((unsigned int)v77);
        }
      }
      if ( v43 )
        ExFreePoolWithTag(v43);
      v44 = v69;
      if ( v69 )
      {
        v70[0] = v79;
        LOWORD(v66[0]) = v67 >> 1;
        v82[0] = (int)v66;
        v82[1] = 0;
        v82[2] = 2;
        v82[3] = 0;
        v82[4] = v69;
        v82[5] = 0;
        v82[6] = v67;
        v82[7] = 0;
        v82[8] = (int)&v77;
        v82[9] = 0;
        v82[10] = 4;
        v82[11] = 0;
        v77 = (int *)v12;
        if ( v73 )
          v45 = v71 >> 1;
        else
          v45 = 0;
        v82[12] = (int)&v74;
        v82[13] = 0;
        v82[14] = 2;
        v82[15] = 0;
        v82[16] = v73;
        v82[17] = 0;
        v82[18] = 2 * v45;
        v82[19] = 0;
        v82[20] = (int)v70;
        v82[21] = 0;
        v82[22] = 4;
        v82[23] = 0;
        LOWORD(v74) = v45;
        v46 = PnpEtwHandle;
        if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverLoad_Stop) )
        {
          EtwWrite(v46, SHIDWORD(v46), (int)KMPnPEvt_DriverLoad_Stop, 0);
          v44 = v69;
        }
        ExFreePoolWithTag(v44);
      }
      if ( v73 )
        ExFreePoolWithTag(v73);
      if ( v65 )
        ExFreePoolWithTag(v65);
      ObCloseHandle(a1);
      return v12;
    }
LABEL_147:
    v65 = 0;
    goto LABEL_65;
  }
  IopBootLog(&v63, 0);
  DbgPrint("SAFEBOOT: skipping device = %wZ(%wZ)\n", &v63, v66);
  HeadlessKernelAddLogEntry();
  ObCloseHandle(a1);
  return -1073740961;
}
