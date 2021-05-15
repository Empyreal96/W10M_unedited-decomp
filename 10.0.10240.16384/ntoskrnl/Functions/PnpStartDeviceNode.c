// PnpStartDeviceNode 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpStartDeviceNode(int a1, int a2, int a3)
{
  int *v6; // r7
  __int64 v7; // kr00_8
  int v8; // r0
  int v9; // r0
  int v10; // r6
  int v11; // r7 OVERLAPPED
  int v12; // r8 OVERLAPPED
  int v13; // r4
  int v14; // r3
  int v15; // r4
  int v16; // r3
  __int64 v17; // r6
  int v18; // r4
  int v19; // r3
  int v20; // r2
  int v21; // r1
  int v22; // r0
  int v23; // r3
  int v24; // r2
  __int16 v25[4]; // [sp+18h] [bp-60h] BYREF
  int v26; // [sp+20h] [bp-58h] BYREF
  char v27[16]; // [sp+24h] [bp-54h] BYREF
  int v28; // [sp+34h] [bp-44h]
  __int16 *v29; // [sp+38h] [bp-40h]
  int v30; // [sp+3Ch] [bp-3Ch]
  int v31; // [sp+40h] [bp-38h]
  int v32; // [sp+44h] [bp-34h]
  int v33; // [sp+48h] [bp-30h]
  int v34; // [sp+4Ch] [bp-2Ch]
  int v35; // [sp+50h] [bp-28h]
  int v36; // [sp+54h] [bp-24h]

  if ( a2 )
    return sub_7CA404(a1, a2, a3, 779);
  if ( IopGetSessionIdFromPDO(*(_DWORD *)(a1 + 16)) != -1 )
    PpMarkDeviceStackExtensionFlag(*(_DWORD *)(a1 + 16), 1024, 1);
  if ( a3
    || (PnpAsyncOptions & 1) == 0
    || (*(_DWORD *)(a1 + 268) & 0x400000) != 0
    || (*(_DWORD *)(*(_DWORD *)(a1 + 16) + 28) & 0x4000) != 0
    || InitSafeBootMode
    || (v6 = (int *)PnpDeviceCompletionRequestCreate(a1, 774)) == 0 )
  {
    v17 = PnpEtwHandle;
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceStart_Start) )
    {
      v18 = *(unsigned __int16 *)(a1 + 20);
      v25[0] = *(_WORD *)(a1 + 20) >> 1;
      v29 = v25;
      v30 = 0;
      v31 = 2;
      v32 = 0;
      v19 = *(_DWORD *)(a1 + 24);
      v35 = v18;
      v33 = v19;
      v34 = 0;
      v36 = 0;
      EtwWrite(v17, SHIDWORD(v17), (int)KMPnPEvt_DeviceStart_Start, 0);
    }
    v28 = -1073741823;
    v26 = 0;
    KeInitializeEvent((int)v27, 1, 0);
    v10 = PnpStartDevice(*(_DWORD *)(a1 + 16), (int)PnpDiagnosticCompletionRoutine, (int)&v26);
    if ( v10 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v27, 0, 0, 0, 0);
      v10 = v28;
    }
    if ( v10 >= 0 )
    {
      v20 = *(_DWORD *)(a1 + 16);
      v21 = 0;
      v22 = v20;
      if ( v20 )
      {
        do
        {
          v23 = *(_DWORD *)(v22 + 32);
          v22 = *(_DWORD *)(v22 + 16);
          v21 |= v23 & 0x40000;
        }
        while ( v22 );
        if ( v21 )
        {
          do
          {
            *(_DWORD *)(v20 + 32) |= v21;
            v20 = *(_DWORD *)(v20 + 16);
          }
          while ( v20 );
        }
      }
      PnpSetObjectProperty(
        PiPnpRtlCtx,
        *(_DWORD *)(a1 + 24),
        1,
        0,
        0,
        (int)DEVPKEY_Device_DriverProblemDesc,
        0,
        0,
        0,
        0);
      PiSwProcessParentStartIrp(*(_DWORD *)(a1 + 16));
    }
    v24 = v26;
    *(_DWORD *)(a1 + 264) = v10;
    PnpTraceStartDevice(a1, v10, v24);
    PipSetDevNodeState((_DWORD *)a1, 774);
  }
  else
  {
    v7 = PnpEtwHandle;
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceStart_Start) )
    {
      v13 = *(unsigned __int16 *)(a1 + 20);
      v25[0] = *(_WORD *)(a1 + 20) >> 1;
      v29 = v25;
      v30 = 0;
      v31 = 2;
      v32 = 0;
      v14 = *(_DWORD *)(a1 + 24);
      v35 = v13;
      v33 = v14;
      v34 = 0;
      v36 = 0;
      EtwWrite(v7, SHIDWORD(v7), (int)KMPnPEvt_DeviceStart_Start, 0);
    }
    v8 = PipSetDevNodeState((_DWORD *)a1, 773);
    *(_DWORD *)(a1 + 264) = 259;
    PnpDeviceCompletionQueueAddDispatchedRequest(v8, v6);
    v9 = PnpStartDevice(*(_DWORD *)(a1 + 16), (int)PnpDeviceCompletionRoutine, (int)v6);
    v10 = v9;
    if ( v9 == 259 )
    {
      *(_QWORD *)&v11 = PnpEtwHandle;
      if ( PnpEtwHandle )
      {
        if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceStart_Pend) )
        {
          v15 = *(unsigned __int16 *)(a1 + 20);
          v25[0] = *(_WORD *)(a1 + 20) >> 1;
          v29 = v25;
          v30 = 0;
          v31 = 2;
          v32 = 0;
          v16 = *(_DWORD *)(a1 + 24);
          v35 = v15;
          v33 = v16;
          v34 = 0;
          v36 = 0;
          EtwWrite(v11, v12, (int)KMPnPEvt_DeviceStart_Pend, 0);
        }
      }
    }
    else
    {
      PnpDeviceCompletionQueueRemoveCompletedRequest(v9, (int)v6);
      v10 = PnpDeviceCompletionProcessCompletedRequest(v6);
    }
  }
  return v10;
}
