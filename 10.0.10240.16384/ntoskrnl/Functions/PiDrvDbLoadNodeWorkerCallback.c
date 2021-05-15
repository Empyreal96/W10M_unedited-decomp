// PiDrvDbLoadNodeWorkerCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDrvDbLoadNodeWorkerCallback(int a1, int a2, int a3)
{
  int v3; // r3
  int result; // r0
  int v6; // r6
  __int64 v7; // r2
  int v8; // r2
  int v9; // r0
  int v10; // r7 OVERLAPPED
  int v11; // r8 OVERLAPPED
  int v12; // r4
  int v13; // r3
  int v14; // r1
  int v15; // r3
  __int16 v16; // [sp+20h] [bp-68h] BYREF
  int v17; // [sp+24h] [bp-64h] BYREF
  int v18; // [sp+28h] [bp-60h] BYREF
  int v19; // [sp+2Ch] [bp-5Ch] BYREF
  int v20; // [sp+30h] [bp-58h] BYREF
  int v21; // [sp+34h] [bp-54h] BYREF
  __int16 *v22; // [sp+38h] [bp-50h]
  int v23; // [sp+3Ch] [bp-4Ch]
  int v24; // [sp+40h] [bp-48h]
  int v25; // [sp+44h] [bp-44h]
  int v26; // [sp+48h] [bp-40h]
  int v27; // [sp+4Ch] [bp-3Ch]
  int v28; // [sp+50h] [bp-38h]
  int v29; // [sp+54h] [bp-34h]
  int *v30; // [sp+58h] [bp-30h]
  int v31; // [sp+5Ch] [bp-2Ch]
  int v32; // [sp+60h] [bp-28h]
  int v33; // [sp+64h] [bp-24h]

  v18 = 0;
  v20 = 1;
  v21 = 0;
  v17 = 0;
  v3 = PnpEtwHandle | HIDWORD(PnpEtwHandle);
  if ( PnpEtwHandle )
    return sub_7F0E38(a1, a2, a3, v3);
  v6 = PiDrvDbLoadHive(a1 + 16, a1 + 24, &v18, v3);
  if ( v6 < 0 )
    goto LABEL_22;
  if ( SysCtxRegOpenKey(0, v18, (int)L"DriverDatabase", 0, 0x2000000) < 0 )
  {
    *(_BYTE *)(a1 + 40) = 1;
  }
  else
  {
    LODWORD(v7) = *(_DWORD *)(a1 + 276);
    HIDWORD(v7) = *(_DWORD *)(a1 + 272);
    if ( v7 == 0xFFFFFFFF00000000ui64 )
    {
      if ( PnpGetObjectProperty(
             PiPnpRtlCtx,
             *(_DWORD *)(a1 + 12),
             6,
             *(_DWORD *)(a1 + 36),
             0,
             (int)DEVPKEY_DriverDatabase_UnloadTimeout,
             (int)&v20,
             (int)&v17,
             4,
             (int)&v21,
             0) >= 0
        && v20 == 7
        && v21 == 4 )
      {
        v8 = v17;
      }
      else
      {
        v8 = 120000;
        v17 = 120000;
      }
      if ( v8 != -1 )
      {
        *(_QWORD *)(a1 + 272) = 10000i64 * (unsigned int)v8;
        *(_QWORD *)(a1 + 272) = -10000i64 * (unsigned int)v8;
      }
    }
  }
  ZwClose();
  ZwResetEvent();
  v9 = PiDrvDbUnloadHive(a1 + 16, *(_DWORD *)(a1 + 264));
  v6 = v9;
  if ( v9 != 259 )
  {
    if ( v9 < 0 )
      v6 = 0;
    ZwSetEvent();
LABEL_22:
    if ( v6 == -1073741431 )
      v6 = -1073741077;
    goto LABEL_12;
  }
  v6 = 0;
LABEL_12:
  *(_DWORD *)(a1 + 136) = v6;
  result = KeSetEvent(a1 + 104, 0, 0);
  *(_QWORD *)&v10 = PnpEtwHandle;
  v19 = v6;
  if ( PnpEtwHandle )
  {
    result = EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverDatabaseLoad_Stop);
    if ( result )
    {
      v12 = *(unsigned __int16 *)(a1 + 8);
      v16 = *(_WORD *)(a1 + 8) >> 1;
      v22 = &v16;
      v23 = 0;
      v24 = 2;
      v25 = 0;
      v13 = *(_DWORD *)(a1 + 12);
      v28 = v12;
      v26 = v13;
      v27 = 0;
      v29 = 0;
      v30 = &v19;
      v31 = 0;
      v32 = 4;
      v33 = 0;
      result = EtwWrite(v10, v11, (int)KMPnPEvt_DriverDatabaseLoad_Stop, 0);
      *(_QWORD *)&v10 = PnpEtwHandle;
    }
  }
  if ( v6 < 0 )
  {
    v19 = v6;
    if ( v10 | v11 )
    {
      result = EtwEventEnabled(v10, v11, (int)KMPnPEvt_DriverDatabaseLoaded_Stop);
      if ( result )
      {
        v14 = *(unsigned __int16 *)(a1 + 8);
        v16 = *(_WORD *)(a1 + 8) >> 1;
        v22 = &v16;
        v23 = 0;
        v24 = 2;
        v25 = 0;
        v15 = *(_DWORD *)(a1 + 12);
        v28 = v14;
        v26 = v15;
        v27 = 0;
        v29 = 0;
        v30 = &v19;
        v31 = 0;
        v32 = 4;
        v33 = 0;
        result = EtwWrite(v10, v11, (int)KMPnPEvt_DriverDatabaseLoaded_Stop, 0);
      }
    }
  }
  return result;
}
