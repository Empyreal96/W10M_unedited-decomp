// sub_765A80 
 
int sub_765A80()
{
  int v0; // r10
  int v1; // r7
  int v2; // r0
  unsigned int v3; // r2
  int result; // r0
  int v5; // r0
  int v6; // r0
  BOOL v7; // r4
  int v8; // r7
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r1
  unsigned int v18; // r0
  int v19; // [sp+0h] [bp-A8h]
  int (*v20)(); // [sp+4h] [bp-A4h]
  int v21; // [sp+8h] [bp-A0h]
  int v22; // [sp+Ch] [bp-9Ch]
  int v23; // [sp+10h] [bp-98h]
  int v24; // [sp+14h] [bp-94h]
  unsigned int v25; // [sp+18h] [bp-90h] BYREF
  int v26; // [sp+1Ch] [bp-8Ch]
  unsigned int v27[2]; // [sp+20h] [bp-88h] BYREF
  int v28; // [sp+28h] [bp-80h] BYREF
  int v29; // [sp+2Ch] [bp-7Ch]
  int v30; // [sp+30h] [bp-78h]
  int v31; // [sp+34h] [bp-74h]
  char v32[4]; // [sp+38h] [bp-70h] BYREF
  int v33; // [sp+3Ch] [bp-6Ch] BYREF
  int v34[6]; // [sp+40h] [bp-68h] BYREF
  char v35[8]; // [sp+58h] [bp-50h] BYREF
  char v36[12]; // [sp+60h] [bp-48h] BYREF
  char v37[60]; // [sp+6Ch] [bp-3Ch] BYREF

  v30 = 1;
  v31 = 0;
  v0 = 0;
  v28 = 0;
  v1 = 0;
  RtlInitUnicodeString((unsigned int)v35, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions");
  v34[0] = 24;
  v34[1] = 0;
  v34[3] = 576;
  v34[2] = (int)v35;
  v34[4] = 0;
  v34[5] = 0;
  v2 = KeAbPreAcquire((unsigned int)&ExpKeyManipLock, 0, 0);
  do
    v3 = __ldrex((unsigned int *)&ExpKeyManipLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&ExpKeyManipLock) );
  __dmb(0xBu);
  if ( v3 )
    return sub_7EB908(v2, 17);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  if ( ExpProductTypeKey )
  {
    while ( 1 )
    {
      v5 = CmOpenKey(&v33, 0x2001Fu, (int)v34, 0, 0);
      if ( v5 != -1073741670 )
        break;
      v25 = -10000000;
      v26 = -1;
      KeDelayExecutionThread(0, 0, &v25);
    }
    if ( v5 < 0 )
      KeBugCheckEx(154, 13, v5, 0, 0);
    v29 = ExpProductTypeKey;
    ExpProductTypeKey = v33;
    if ( !ExpSetupModeDetected )
    {
      RtlInitUnicodeString((unsigned int)v27, L"ProductType");
      v6 = NtQueryValueKey(ExpProductTypeKey, v27, 2, (int)v36, 34, (unsigned int)v32);
      if ( v6 == -1073741670 )
      {
        v25 = -10000000;
        v26 = -1;
        do
        {
          KeDelayExecutionThread(0, 0, &v25);
          v6 = NtQueryValueKey(ExpProductTypeKey, v27, 2, (int)v36, 34, (unsigned int)v32);
        }
        while ( v6 == -1073741670 );
      }
      if ( v6 >= 0 )
      {
        v7 = !wcscmp((char *)L"LanmanNT", v37) || !wcscmp((char *)L"ServerNT", v37);
        v8 = ExpProductTypeValueInfo;
        if ( wcscmp((char *)L"WinNT", (char *)(ExpProductTypeValueInfo + 12)) && v7 )
        {
          memmove(v8, (int)v36, 0x22u);
          v30 = 0;
        }
        if ( !wcscmp((char *)(v8 + 12), v37) )
          v30 = 0;
      }
      v9 = ExUpdateLicenseRegistry(ExpProductTypeKey);
      if ( v9 < 0 )
        KeBugCheckEx(154, 17, v9, 1, 0);
      CmpLockRegistryFreezeAware(1);
      v31 = 1;
      v10 = NtSetValueKey(
              ExpProductTypeKey,
              (int)v27,
              0,
              *(_DWORD *)(ExpProductTypeValueInfo + 4),
              ExpProductTypeValueInfo + 12,
              *(_DWORD *)(ExpProductTypeValueInfo + 8));
      if ( v10 == -1073741670 )
      {
        v25 = -10000000;
        v26 = -1;
        do
        {
          KeDelayExecutionThread(0, 0, &v25);
          v10 = NtSetValueKey(
                  ExpProductTypeKey,
                  (int)v27,
                  0,
                  *(_DWORD *)(ExpProductTypeValueInfo + 4),
                  ExpProductTypeValueInfo + 12,
                  *(_DWORD *)(ExpProductTypeValueInfo + 8));
        }
        while ( v10 == -1073741670 );
      }
      if ( v10 < 0 )
        KeBugCheckEx(154, 17, v10, 1, 0);
      if ( dword_6416B4 )
      {
        RtlInitUnicodeString((unsigned int)v27, L"ProductSuite");
        v11 = NtSetValueKey(
                ExpProductTypeKey,
                (int)v27,
                0,
                *(_DWORD *)(dword_6416B4 + 4),
                dword_6416B4 + 12,
                *(_DWORD *)(dword_6416B4 + 8));
        if ( v11 == -1073741670 )
        {
          v25 = -10000000;
          v26 = -1;
          do
          {
            KeDelayExecutionThread(0, 0, &v25);
            v11 = NtSetValueKey(
                    ExpProductTypeKey,
                    (int)v27,
                    0,
                    *(_DWORD *)(dword_6416B4 + 4),
                    dword_6416B4 + 12,
                    *(_DWORD *)(dword_6416B4 + 8));
          }
          while ( v11 == -1073741670 );
        }
        if ( v11 < 0 )
          KeBugCheckEx(154, 17, v11, 2, 0);
      }
      else
      {
        RtlInitUnicodeString((unsigned int)v27, L"ProductSuite");
        NtDeleteValueKey(ExpProductTypeKey, v27);
      }
      v28 = 1;
    }
    while ( 1 )
    {
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
      if ( v12 != -1073741670 )
        break;
      v25 = -10000000;
      v26 = -1;
      KeDelayExecutionThread(0, 0, &v25);
    }
    v0 = v28;
    if ( v31 )
      CmpUnlockRegistry();
    if ( v12 < 0 )
      KeBugCheckEx(154, 17, v12, 4, 0);
    if ( !ExpSetupModeDetected )
    {
      if ( v30 )
      {
        v21 = -1073741206;
        v20 = ExpExpirationThread;
        v19 = 0;
        if ( PsCreateSystemThread((int)&v28, 0x1FFFFF, 0) >= 0 )
          ZwClose();
      }
    }
    v1 = v29;
  }
  __pld(&ExpKeyManipLock);
  v17 = ExpKeyManipLock;
  if ( (ExpKeyManipLock & 0xFFFFFFF0) <= 0x10 )
    v18 = 0;
  else
    v18 = ExpKeyManipLock - 16;
  if ( (ExpKeyManipLock & 2) != 0 )
    goto LABEL_69;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&ExpKeyManipLock);
  while ( v13 == v17 && __strex(v18, (unsigned int *)&ExpKeyManipLock) );
  if ( v13 != v17 )
LABEL_69:
    ExfReleasePushLock(&ExpKeyManipLock, v17);
  result = KeAbPostRelease((unsigned int)&ExpKeyManipLock);
  if ( v1 )
  {
    if ( v0 )
      NtFlushKey(v1, v14, v15, v16, v19, (int)v20, v21, v22, v23, v24, v25);
    result = ObCloseHandle(v1);
  }
  return result;
}
