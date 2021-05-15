// IopInitializeBuiltinDriver 
 
int __fastcall IopInitializeBuiltinDriver(int a1, unsigned __int16 *a2, int a3, int a4, unsigned __int8 a5, _DWORD *a6)
{
  unsigned __int16 *v7; // r8
  char v9; // r9
  _BYTE *v11; // r4
  int (__fastcall **v12)(int, int); // r3
  int v13; // r0
  int i; // r5
  _BYTE *v15; // r5
  int v16; // r0
  int v17; // r1
  int v18; // r0
  int v19; // r5
  unsigned __int16 *v20; // r5
  int v21; // r6
  unsigned int v22; // r3
  _WORD *v23; // r2
  _WORD *v24; // r5
  unsigned int v25; // r8
  int v26; // t1
  unsigned int v27; // r1
  int v28; // r0
  int v29; // r9
  int v30; // r5
  int v31; // r0
  int v32; // r1
  int v33; // r2
  int v34; // r3
  int v35; // r3
  int v36; // r1
  _BYTE *v38; // [sp+Ch] [bp-54h] BYREF
  int v39; // [sp+10h] [bp-50h] BYREF
  int v40; // [sp+14h] [bp-4Ch] BYREF
  int v41; // [sp+18h] [bp-48h] BYREF
  unsigned int v42; // [sp+1Ch] [bp-44h] BYREF
  unsigned __int16 *v43; // [sp+20h] [bp-40h]
  char v44[56]; // [sp+28h] [bp-38h] BYREF

  v7 = (unsigned __int16 *)a1;
  v43 = (unsigned __int16 *)a1;
  *a6 = 0;
  v9 = 0;
  v40 = 0;
  HeadlessKernelAddLogEntry();
  if ( IopInitializeAttributesAndCreateObject(v7, v44, &v38) < 0 )
    return sub_968F80();
  v11 = v38;
  memset(v38, 0, 208);
  *((_DWORD *)v11 + 6) = v11 + 168;
  *((_DWORD *)v11 + 42) = v11;
  v12 = (int (__fastcall **)(int, int))(v11 + 56);
  do
    *v12++ = IopInvalidDeviceRequest;
  while ( v12 != (int (__fastcall **)(int, int))(v11 + 168) );
  *(_WORD *)v11 = 4;
  *((_WORD *)v11 + 1) = 168;
  *((_DWORD *)v11 + 11) = a3;
  if ( ObInsertObject((int)v11, 0, 1, 0, 0, (int)&v41) < 0 )
    return sub_968F80();
  v13 = ObReferenceObjectByHandle(v41, 0, IoDriverObjectType, 0, (int)&v42, 0);
  for ( i = PsLoadedModuleList; (int *)i != &PsLoadedModuleList && a4; i = *(_DWORD *)i )
  {
    v13 = RtlEqualString((unsigned __int16 *)(a4 + 44), (unsigned __int16 *)(i + 44), 1);
    if ( v13 )
    {
      *((_DWORD *)v11 + 5) = i;
      break;
    }
  }
  InbvIndicateProgress(v13);
  if ( a4 )
  {
    v38 = *(_BYTE **)(a4 + 24);
    v15 = v38;
    v16 = RtlImageNtHeader((int)v38);
    *((_DWORD *)v11 + 3) = v15;
    *((_DWORD *)v11 + 4) = *(_DWORD *)(v16 + 80);
    if ( (*(_WORD *)(v16 + 94) & 0x2000) != 0 )
      goto LABEL_16;
  }
  else
  {
    v38 = 0;
  }
  *((_DWORD *)v11 + 2) |= 2u;
LABEL_16:
  v17 = v7[1];
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v34 = 40;
    else
      v34 = 32;
    v18 = ExAllocatePoolWithTagPriority(512, v17 + 2, 538996553, v34);
  }
  else
  {
    v18 = ExAllocatePoolWithTag(512, v17 + 2, 538996553);
  }
  v19 = v18;
  if ( v18 )
  {
    *((_DWORD *)v11 + 8) = v18;
    *((_WORD *)v11 + 15) = v7[1];
    *((_WORD *)v11 + 14) = *v7;
    memmove(*((_DWORD *)v11 + 8), *((_DWORD *)v7 + 1), v7[1]);
    *(_WORD *)(v19 + 2 * (*v7 >> 1)) = 0;
  }
  v20 = a2;
  v21 = *((_DWORD *)v11 + 6);
  if ( !a2 || !*a2 )
  {
    *(_DWORD *)(v21 + 16) = 0;
    *(_WORD *)(v21 + 14) = 0;
    *(_WORD *)(v21 + 12) = 0;
    goto LABEL_38;
  }
  v23 = (_WORD *)*((_DWORD *)a2 + 1);
  v22 = *a2;
  v24 = &v23[(v22 >> 1) - 1];
  if ( *v24 == 92 )
    v24 = &v23[(v22 >> 1) - 2];
  v25 = 0;
  while ( v24 != v23 )
  {
    v26 = (unsigned __int16)*v24--;
    if ( v26 == 92 )
    {
      v24 += 2;
      break;
    }
    v25 = (unsigned __int16)(v25 + 2);
  }
  if ( v24 == v23 )
    v25 = (unsigned __int16)(v25 + 2);
  v27 = v25 + 2;
  v42 = v25 + 2;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v35 = 40;
    else
      v35 = 32;
    v28 = ExAllocatePoolWithTagPriority(512, v27, 538996553, v35);
  }
  else
  {
    v28 = ExAllocatePoolWithTag(512, v27, 538996553);
  }
  v29 = v28;
  if ( v28 )
  {
    *(_WORD *)(v21 + 14) = v42;
    *(_DWORD *)(v21 + 16) = v28;
    *(_WORD *)(v21 + 12) = v25;
    memmove(v28, (int)v24, v25);
    *(_WORD *)(v29 + 2 * (*(unsigned __int16 *)(v21 + 12) >> 1)) = 0;
    v30 = IopOpenRegistryKeyEx(&v39);
    if ( v30 >= 0 )
    {
      v30 = PnpPrepareDriverLoading(v21 + 12, v39, (int)v38, a5, &v40);
      NtClose();
      if ( v30 >= 0 )
      {
        v9 = v40;
        v7 = v43;
        v20 = a2;
LABEL_38:
        if ( (v9 & 1) != 0 )
          *((_DWORD *)v11 + 2) |= 0x100u;
        *((_DWORD *)v11 + 9) = CmRegistryMachineHardwareDescriptionSystemName;
        KseDriverLoadImage(a4);
        v31 = (*((int (__fastcall **)(_BYTE *, unsigned __int16 *))v11 + 11))(v11, v20);
        v30 = v31;
        if ( v31 < 0 )
        {
          if ( v31 == -1073741218 )
            v36 = 3;
          else
            v36 = 0;
          DbgPrintEx(101, v36, (int)"IOINIT: Built-in driver %wZ failed to initialize with status - 0x%lX\n", (int)v7);
        }
        else
        {
          VfXdvDriverCaptureIoCallbacks((int)v11);
          if ( a4 )
            v33 = a4 + 36;
          else
            v33 = 0;
          KseShimDriverIoCallbacks((int)v11, v32, v33);
        }
        goto LABEL_44;
      }
    }
  }
  else
  {
    v30 = -1073741670;
    *(_DWORD *)(v21 + 16) = 0;
    *(_WORD *)(v21 + 12) = 0;
  }
LABEL_44:
  NtClose();
  if ( v30 < 0 )
  {
    if ( v30 != -1073741218 )
      PnpDriverLoadingFailed(0, *((_DWORD *)v11 + 6) + 12);
    HeadlessKernelAddLogEntry();
    ObMakeTemporaryObject((int)v11);
    ObfDereferenceObject((int)v11);
  }
  else
  {
    IopReadyDeviceObjects((int)v11);
    HeadlessKernelAddLogEntry();
    *a6 = v11;
  }
  return v30;
}
