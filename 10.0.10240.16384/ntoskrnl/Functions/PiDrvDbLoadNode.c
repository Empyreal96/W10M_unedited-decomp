// PiDrvDbLoadNode 
 
int __fastcall PiDrvDbLoadNode(int a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r3
  int v12; // r0
  int v13; // r8
  __int64 v14; // r6
  int v15; // r4
  int v16; // r3
  int v17; // r1
  int v18; // r3
  __int16 v19; // [sp+8h] [bp-60h] BYREF
  int v20; // [sp+Ch] [bp-5Ch]
  int v21[2]; // [sp+10h] [bp-58h] BYREF
  __int16 *v22; // [sp+18h] [bp-50h]
  int v23; // [sp+1Ch] [bp-4Ch]
  int v24; // [sp+20h] [bp-48h]
  int v25; // [sp+24h] [bp-44h]
  int v26; // [sp+28h] [bp-40h]
  int v27; // [sp+2Ch] [bp-3Ch]
  int v28; // [sp+30h] [bp-38h]
  int v29; // [sp+34h] [bp-34h]
  int *v30; // [sp+38h] [bp-30h]
  int v31; // [sp+3Ch] [bp-2Ch]
  int v32; // [sp+40h] [bp-28h]
  int v33; // [sp+44h] [bp-24h]

  v20 = 0;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  v7 = ExAcquireResourceExclusiveLite(a1 + 44, 1, v5, v6);
  if ( *(_BYTE *)(a1 + 40) )
    return sub_7E3148(v7);
  if ( *(_BYTE *)(a1 + 280) )
  {
    KeCancelTimer(a1 + 144);
    *(_BYTE *)(a1 + 280) = 0;
  }
  if ( *(_DWORD *)(a1 + 36) )
    goto LABEL_6;
  if ( PnpCtxRegOpenKey(0, 0, *(_DWORD *)(a1 + 20), 0) >= 0 )
  {
    v4 = SysCtxRegOpenKey(0, v20, (int)L"DriverDatabase", 0, 0x2000000);
    ZwClose();
    if ( v4 >= 0 )
      goto LABEL_6;
  }
  if ( !dword_630874 )
  {
    v12 = ZwWaitForSingleObject();
    v13 = v12;
    if ( !*(_BYTE *)(a1 + 281) )
    {
      *(_BYTE *)(a1 + 281) = 1;
      v14 = PnpEtwHandle;
      v21[0] = v12;
      if ( PnpEtwHandle
        && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverDatabaseUnload_Stop) )
      {
        v15 = *(unsigned __int16 *)(a1 + 8);
        v19 = *(_WORD *)(a1 + 8) >> 1;
        v22 = &v19;
        v23 = 0;
        v24 = 2;
        v25 = 0;
        v16 = *(_DWORD *)(a1 + 12);
        v28 = v15;
        v26 = v16;
        v27 = 0;
        v29 = 0;
        v30 = v21;
        v31 = 0;
        v32 = 4;
        v33 = 0;
        EtwWrite(v14, SHIDWORD(v14), (int)KMPnPEvt_DriverDatabaseUnload_Stop, 0);
        v14 = PnpEtwHandle;
      }
      v21[0] = v13;
      if ( v14 && EtwEventEnabled(v14, SHIDWORD(v14), (int)KMPnPEvt_DriverDatabaseLoaded_Stop) )
      {
        v17 = *(unsigned __int16 *)(a1 + 8);
        v19 = *(_WORD *)(a1 + 8) >> 1;
        v22 = &v19;
        v23 = 0;
        v24 = 2;
        v25 = 0;
        v18 = *(_DWORD *)(a1 + 12);
        v28 = v17;
        v26 = v18;
        v27 = 0;
        v29 = 0;
        v30 = v21;
        v31 = 0;
        v32 = 4;
        v33 = 0;
        EtwWrite(v14, SHIDWORD(v14), (int)KMPnPEvt_DriverDatabaseLoaded_Stop, 0);
      }
    }
    v4 = 0;
    *(_DWORD *)(a1 + 128) = PiDrvDbLoadNodeWorkerCallback;
    *(_DWORD *)(a1 + 132) = a1;
    *(_DWORD *)(a1 + 120) = 0;
    KeInitializeEvent(a1 + 104, 1, 0);
    ExQueueWorkItem((_DWORD *)(a1 + 120), 0);
    KeWaitForSingleObject(a1 + 104, 0, 0, 0, 0);
    if ( !*(_DWORD *)(a1 + 36) )
    {
      v4 = *(_DWORD *)(a1 + 136);
      if ( v4 >= 0 )
        v4 = -1073741823;
    }
LABEL_6:
    *a2 = *(_DWORD *)(a1 + 36);
    goto LABEL_7;
  }
  v4 = -1073741077;
LABEL_7:
  v9 = ExReleaseResourceLite(a1 + 44);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = (__int16)(*(_WORD *)(v10 + 0x134) + 1);
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v4;
}
