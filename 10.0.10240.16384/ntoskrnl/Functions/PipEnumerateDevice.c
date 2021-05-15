// PipEnumerateDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PipEnumerateDevice(int a1, int a2, int a3)
{
  int *v5; // r6
  int v6; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r7
  __int64 v11; // kr00_8
  int v12; // r4
  int v13; // r3
  int v14; // r7 OVERLAPPED
  int v15; // r8 OVERLAPPED
  int v16; // r4
  int v17; // r3
  __int64 v18; // r6
  int v19; // r4
  int v20; // r3
  int v21; // r0
  int v22; // r4
  __int64 v23; // r6
  int v24; // r4
  int v25; // r3
  __int16 v26[4]; // [sp+8h] [bp-48h] BYREF
  __int16 *v27; // [sp+10h] [bp-40h]
  int v28; // [sp+14h] [bp-3Ch]
  int v29; // [sp+18h] [bp-38h]
  int v30; // [sp+1Ch] [bp-34h]
  int v31; // [sp+20h] [bp-30h]
  int v32; // [sp+24h] [bp-2Ch]
  int v33; // [sp+28h] [bp-28h]
  int v34; // [sp+2Ch] [bp-24h]

  if ( a2
    || (PnpAsyncOptions & 2) == 0
    || (*(_DWORD *)(a1 + 268) & 0x800000) != 0
    || InitSafeBootMode
    || (v5 = (int *)PnpDeviceCompletionRequestCreate(a1, 781)) == 0 )
  {
    if ( a3 && (*(_DWORD *)(a1 + 268) & 0x800000) != 0 )
      return -1073741267;
    v18 = PnpEtwHandle;
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEnum_Start) )
    {
      v19 = *(unsigned __int16 *)(a1 + 20);
      v26[0] = *(_WORD *)(a1 + 20) >> 1;
      v27 = v26;
      v28 = 0;
      v29 = 2;
      v30 = 0;
      v20 = *(_DWORD *)(a1 + 24);
      v33 = v19;
      v31 = v20;
      v32 = 0;
      v34 = 0;
      EtwWrite(v18, SHIDWORD(v18), (int)KMPnPEvt_DeviceEnum_Start, 0);
    }
    PipClearDevNodeFlags(a1, 8);
    PoFxActivateDevice(*(_DWORD *)(a1 + 16));
    v21 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 456) |= 0x80u;
    v22 = PnpQueryDeviceRelations(v21, 0, 0, a1 + 352);
    PoFxIdleDevice(*(_DWORD *)(a1 + 16));
    *(_DWORD *)(a1 + 456) &= 0xFFFFFF7F;
    *(_DWORD *)(a1 + 264) = v22;
    PipSetDevNodeState((_DWORD *)a1, 781);
    v23 = PnpEtwHandle;
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEnum_Stop) )
    {
      v24 = *(unsigned __int16 *)(a1 + 20);
      v26[0] = *(_WORD *)(a1 + 20) >> 1;
      v27 = v26;
      v28 = 0;
      v29 = 2;
      v30 = 0;
      v25 = *(_DWORD *)(a1 + 24);
      v33 = v24;
      v31 = v25;
      v32 = 0;
      v34 = 0;
      EtwWrite(v23, SHIDWORD(v23), (int)KMPnPEvt_DeviceEnum_Stop, 0);
    }
  }
  else
  {
    v6 = PipSetDevNodeState((_DWORD *)a1, 780);
    *(_DWORD *)(a1 + 264) = 259;
    PnpDeviceCompletionQueueAddDispatchedRequest(v6, v5);
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEnum_Start) )
      return sub_7C9ECC();
    PipClearDevNodeFlags(a1, 8);
    PoFxActivateDevice(*(_DWORD *)(a1 + 16));
    v8 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 456) |= 0x80u;
    v9 = PnpQueryDeviceRelations(v8, 0, PnpDeviceCompletionRoutine, v5);
    v10 = v9;
    if ( v9 == 259 )
    {
      v11 = PnpEtwHandle;
      if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEnum_Pend) )
      {
        v12 = *(unsigned __int16 *)(a1 + 20);
        v26[0] = *(_WORD *)(a1 + 20) >> 1;
        v27 = v26;
        v28 = 0;
        v29 = 2;
        v30 = 0;
        v13 = *(_DWORD *)(a1 + 24);
        v33 = v12;
        v31 = v13;
        v32 = 0;
        v34 = 0;
        EtwWrite(v11, SHIDWORD(v11), (int)KMPnPEvt_DeviceEnum_Pend, 0);
      }
      return v10;
    }
    if ( v5[6] != v9 )
    {
      v5[6] = v9;
      *(_QWORD *)&v14 = PnpEtwHandle;
      if ( PnpEtwHandle )
      {
        v9 = EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEnum_Stop);
        if ( v9 )
        {
          v16 = *(unsigned __int16 *)(a1 + 20);
          v26[0] = *(_WORD *)(a1 + 20) >> 1;
          v27 = v26;
          v28 = 0;
          v29 = 2;
          v30 = 0;
          v17 = *(_DWORD *)(a1 + 24);
          v33 = v16;
          v31 = v17;
          v32 = 0;
          v34 = 0;
          v9 = EtwWrite(v14, v15, (int)KMPnPEvt_DeviceEnum_Stop, 0);
        }
      }
      v9 = PnpDeviceCompletionQueueDispatchedEntryCompleted(v9, v5);
    }
    PnpDeviceCompletionQueueRemoveCompletedRequest(v9, (int)v5);
    PnpDeviceCompletionProcessCompletedRequest(v5);
  }
  return 0;
}
