// sub_95F378 
 
int sub_95F378()
{
  int v0; // r0
  int v1; // r0
  int v2; // r4
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r8
  int v11; // r0
  int v12; // r0
  int v14; // r5
  int v15; // r0
  unsigned int v16; // r4
  int v17; // r8
  int v18; // r6
  int v19; // r9
  unsigned int v20; // r5
  int v21; // r0
  int v22; // r5
  int v23; // r0
  int v24; // r0
  char *v25; // r0
  int *v26; // r2
  int v27; // r0
  unsigned __int16 v28; // [sp+18h] [bp-100h] BYREF
  unsigned __int16 v29; // [sp+1Ah] [bp-FEh]
  char *v30; // [sp+1Ch] [bp-FCh]
  int v31; // [sp+20h] [bp-F8h] BYREF
  int v32; // [sp+24h] [bp-F4h] BYREF
  int v33; // [sp+28h] [bp-F0h] BYREF
  int v34; // [sp+2Ch] [bp-ECh]
  int v35; // [sp+30h] [bp-E8h]
  int v36; // [sp+34h] [bp-E4h]
  unsigned __int16 *v37; // [sp+38h] [bp-E0h]
  int v38; // [sp+3Ch] [bp-DCh]
  int v39; // [sp+40h] [bp-D8h]
  int v40; // [sp+44h] [bp-D4h]
  _DWORD v41[4]; // [sp+48h] [bp-D0h] BYREF
  char v42[8]; // [sp+58h] [bp-C0h] BYREF
  int v43; // [sp+60h] [bp-B8h]
  int v44; // [sp+64h] [bp-B4h]
  _DWORD v45[2]; // [sp+68h] [bp-B0h] BYREF
  char v46[20]; // [sp+70h] [bp-A8h] BYREF
  unsigned int v47; // [sp+84h] [bp-94h]
  unsigned int v48; // [sp+88h] [bp-90h]
  unsigned int v49; // [sp+98h] [bp-80h]
  char v50[16]; // [sp+A0h] [bp-78h] BYREF
  char v51[12]; // [sp+B0h] [bp-68h] BYREF
  int v52; // [sp+BCh] [bp-5Ch]

  v33 = 0;
  ExpSetupModeDetected = 0;
  ExpSystemSetupInProgress = 0;
  MEMORY[0xFFFF9268] = 1;
  RtlInitUnicodeString((unsigned int)v42, L"\\Registry\\Machine\\System\\Setup");
  v35 = 24;
  v36 = 0;
  v38 = 576;
  v37 = (unsigned __int16 *)v42;
  v39 = 0;
  v40 = 0;
  v41[2] = 131103;
  v0 = NtOpenKey();
  if ( v0 < 0 )
    KeBugCheckEx(154, 2, v0, 0, 0);
  v1 = ObReferenceObjectByHandle(ExpSetupKey, 0, (int)CmKeyObjectType, 0, (int)&v32, 0);
  v2 = v32;
  if ( v1 < 0 )
    sub_96DA48();
  RtlInitUnicodeString((unsigned int)v41, L"SetupType");
  v3 = NtQueryValueKey(ExpSetupKey, v41, 2, (int)v51, 72, (unsigned int)&v31);
  if ( v3 < 0 )
    KeBugCheckEx(154, 3, v3, 0, 0);
  if ( v52 == 1 || v52 == 4 )
  {
    ExpSetupModeDetected = 1;
    MEMORY[0xFFFF9268] = 0;
    ObfDereferenceObject(v2);
    v2 = 0;
  }
  RtlInitUnicodeString((unsigned int)v41, L"SystemSetupInProgress");
  v4 = NtQueryValueKey(ExpSetupKey, v41, 2, (int)v51, 72, (unsigned int)&v31);
  if ( v4 < 0 )
    KeBugCheckEx(154, 3, v4, 0, 0);
  if ( v52 == 1 )
    ExpSystemSetupInProgress = 1;
  dword_6416B0 |= 0x10u;
  MEMORY[0xFFFF92D0] = dword_6416B0;
  if ( !ExpMultiUserTS )
    MEMORY[0xFFFF92D0] = dword_6416B0 | 0x100;
  ExpLicenseWatchInitWorker();
  if ( InitIsWinPEMode )
  {
    ExpControlKey = v2;
    return 1;
  }
  dword_61A128 = (int)sub_765A80;
  dword_61A12C = 0;
  ExpWatchProductTypeWorkItem = 0;
  RtlInitUnicodeString((unsigned int)v42, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions");
  v35 = 24;
  v36 = 0;
  v38 = 576;
  v37 = (unsigned __int16 *)v42;
  v39 = 0;
  v40 = 0;
  v5 = NtOpenKey();
  if ( v5 < 0 )
  {
    if ( !ExpSetupModeDetected )
      KeBugCheckEx(154, 6, v5, 0, 0);
    return 0;
  }
  if ( !ExpSetupModeDetected )
  {
    v6 = ObReferenceObjectByHandle(ExpProductTypeKey, 0, (int)CmKeyObjectType, 0, (int)&v32, 0);
    v33 = v32;
    if ( v6 < 0 )
      KeBugCheckEx(154, 12, v6, 0, 0);
  }
  ExpControlKey = v2;
  dword_61A10C = v33;
  ExpUpdateProductSuiteTypeInRegistry(ExpProductTypeKey);
  RtlInitUnicodeString((unsigned int)v41, L"ProductType");
  v7 = ExAllocatePoolWithTag(1, 34, 544826699);
  ExpProductTypeValueInfo = v7;
  if ( v7 )
  {
    v8 = NtQueryValueKey(ExpProductTypeKey, v41, 2, v7, 34, (unsigned int)&v31);
    if ( v8 < 0 )
    {
      if ( !ExpSetupModeDetected )
        KeBugCheckEx(154, 7, v8, 0, 0);
      return 0;
    }
    RtlInitUnicodeString((unsigned int)v41, L"ProductSuite");
    if ( NtQueryValueKey(ExpProductTypeKey, v41, 2, (int)v50, 16, (unsigned int)&v31) != -2147483643 )
      goto LABEL_21;
    v31 += 16;
    v9 = ExAllocatePoolWithTag(1, v31, 544826699);
    dword_6416B4 = v9;
    if ( !v9 )
      KeBugCheckEx(154, 20, v31, 2, 0);
    if ( NtQueryValueKey(ExpProductTypeKey, v41, 2, v9, v31, (unsigned int)&v31) < 0 )
    {
      ExFreePoolWithTag(dword_6416B4);
      v10 = (unsigned __int8)ExpSetupModeDetected;
      dword_6416B4 = 0;
      if ( ExpSetupModeDetected )
        return 0;
    }
    else
    {
LABEL_21:
      v10 = (unsigned __int8)ExpSetupModeDetected;
    }
    v11 = wcslen(L"LanmanNT");
    if ( !wcsncmp(L"LanmanNT", (unsigned __int16 *)(ExpProductTypeValueInfo + 12), v11) && InitSafeBootMode == 3 && !v10 )
    {
      MEMORY[0xFFFF9268] = 1;
      MEMORY[0xFFFF9264] = 3;
    }
    v43 = 268435461;
    v12 = NtNotifyChangeKey(
            ExpProductTypeKey,
            0,
            (int)&ExpWatchProductTypeWorkItem,
            1,
            (int)&ExpProductTypeIoSb,
            268435461,
            0,
            (int)&ExpProductTypeChangeBuffer,
            4,
            1u);
    if ( v12 >= 0 )
    {
      RtlInitUnicodeString(
        (unsigned int)v42,
        L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\LicenseInfoSuites");
      v35 = 24;
      v36 = 0;
      v38 = 576;
      v37 = (unsigned __int16 *)v42;
      v39 = 0;
      v40 = 0;
      if ( NtOpenKey() >= 0 )
      {
        v14 = 0;
        v28 = 2 * (wcslen(L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\LicenseInfoSuites") + 64);
        v29 = v28;
        v30 = (char *)ExAllocatePoolWithTag(512, v28, 544826699);
        if ( !v30 )
          KeBugCheckEx(154, 20, v28, 3, 0);
        v15 = NtQueryKey(v34, 2, v46, 0x30u, &v33);
        if ( v15 < 0 )
          KeBugCheckEx(154, 19, v15, 1, 0);
        v16 = 2 * (v48 + 28);
        if ( v16 < v48 || v16 < 2 * (v48 + 16) )
          v14 = 1;
        v17 = ExAllocatePoolWithTag(512, 2 * (v48 + 28), 544826699);
        if ( !v17 || v14 )
          KeBugCheckEx(154, 20, v16, 4, 0);
        v18 = v49 + 32;
        if ( v49 + 32 < v49 )
          v14 = 1;
        v19 = ExAllocatePoolWithTag(512, v49 + 32, 544826699);
        if ( !v19 || v14 )
          KeBugCheckEx(154, 20, v18, 5, 0);
        v20 = v47;
        ExpLicenseInfoCount = v47;
        if ( RtlULongLongToULong(40 * v47, (40 * (unsigned __int64)v47) >> 32, &v32) < 0 )
          KeBugCheckEx(154, 20, 40 * v20, 6, 0);
        ExpLicenseInfo = ExAllocatePoolWithTag(512, v32, 544826699);
        if ( !ExpLicenseInfo )
          KeBugCheckEx(154, 20, 40 * ExpLicenseInfoCount, 6, 0);
        RtlInitUnicodeString((unsigned int)v45, L"ConcurrentLimit");
        v32 = 0;
        v21 = NtEnumerateKey(v34, 0, 0, v17, v16, (unsigned int)&v33);
        v44 = -2147483622;
        if ( v21 != -2147483622 )
        {
          v22 = 0;
          do
          {
            if ( v21 < 0 )
              KeBugCheckEx(154, 26, v21, 0, 0);
            *(_WORD *)(v17 + 2 * (*(_DWORD *)(v17 + 12) >> 1) + 16) = 0;
            wcscpy_s(
              v30,
              v29 >> 1,
              (char *)L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\LicenseInfoSuites");
            wcscat_s(v30, v29 >> 1, (char *)L"\\");
            wcscat_s(v30, v29 >> 1, (char *)(v17 + 16));
            v28 = 2 * wcslen((unsigned __int16 *)v30);
            v35 = 24;
            v36 = 0;
            v38 = 576;
            v37 = &v28;
            v39 = 0;
            v40 = 0;
            v23 = NtOpenKey();
            if ( v23 < 0 )
              KeBugCheckEx(154, 22, v23, 1, 0);
            v24 = NtQueryValueKey(*(_DWORD *)(v22 + ExpLicenseInfo), v45, 2, v19, v18, (unsigned int)&v33);
            if ( v24 < 0 )
              KeBugCheckEx(154, 19, v24, 2, 0);
            v25 = (char *)ExAllocatePoolWithTag(512, v28, 544826699);
            *(_DWORD *)(ExpLicenseInfo + v22 + 8) = v25;
            if ( !v25 )
              KeBugCheckEx(154, 20, v28, 7, 0);
            wcscpy_s(v25, v28 >> 1, v30);
            v26 = (int *)(v22 + ExpLicenseInfo);
            v26[1] = *(_DWORD *)(v19 + 12);
            v26[5] = (int)sub_8A3470;
            v26[6] = (int)v26;
            v26[3] = 0;
            v27 = NtNotifyChangeKey(*v26, 0, (int)(v26 + 3), 1, (int)(v26 + 7), v43, 1u, (int)(v26 + 9), 4, 1u);
            if ( v27 < 0 )
              KeBugCheckEx(154, 24, v27, 1, 0);
            ++v32;
            v22 += 40;
            v21 = NtEnumerateKey(v34, v32, 0, v17, v16, (unsigned int)&v33);
          }
          while ( v21 != v44 );
        }
        ExFreePoolWithTag(v17);
        ExFreePoolWithTag(v19);
        ExFreePoolWithTag((unsigned int)v30);
        NtClose();
      }
      return 1;
    }
    if ( !ExpSetupModeDetected )
      KeBugCheckEx(154, 8, v12, 0, 0);
  }
  return 0;
}
