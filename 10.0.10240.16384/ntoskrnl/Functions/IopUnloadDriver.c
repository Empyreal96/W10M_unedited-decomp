// IopUnloadDriver 
 
int __fastcall IopUnloadDriver(int *a1, int a2)
{
  unsigned int v4; // r3
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r1
  int v9; // r5
  int v10; // r3
  __int64 v11; // kr00_8
  int v12; // r4
  int v13; // r5
  int v14; // r0
  int v15; // r0
  int v16; // r2
  int v17; // r2
  int v18; // r2
  __int64 v19; // kr08_8
  int v21; // [sp+10h] [bp-F8h] BYREF
  int v22; // [sp+14h] [bp-F4h] BYREF
  _WORD v23[2]; // [sp+18h] [bp-F0h] BYREF
  int v24; // [sp+1Ch] [bp-ECh]
  int v25; // [sp+20h] [bp-E8h]
  int v26; // [sp+24h] [bp-E4h]
  int v27; // [sp+28h] [bp-E0h] BYREF
  int v28; // [sp+2Ch] [bp-DCh]
  int v29; // [sp+30h] [bp-D8h] BYREF
  int v30; // [sp+34h] [bp-D4h] BYREF
  int v31; // [sp+38h] [bp-D0h] BYREF
  _DWORD v32[6]; // [sp+40h] [bp-C8h] BYREF
  _DWORD v33[2]; // [sp+58h] [bp-B0h] BYREF
  int v34; // [sp+60h] [bp-A8h]
  _DWORD *v35; // [sp+64h] [bp-A4h]
  _DWORD v36[40]; // [sp+68h] [bp-A0h] BYREF

  v28 = 0;
  v21 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v4 + 346) && !a2 )
  {
    v5 = SeSinglePrivilegeCheck(SeLoadDriverPrivilege, dword_922B84, *(char *)(v4 + 346), (int)&SeLoadDriverPrivilege);
    if ( !v5 )
      return -1073741727;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (int *)MmUserProbeAddress;
    v25 = *a1;
    v7 = a1[1];
    v26 = v7;
    v8 = (unsigned __int16)v25;
    if ( !(_WORD)v25 )
    {
      v6 = -1073741811;
      v21 = -1073741811;
      return v6;
    }
    if ( (v7 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v5);
    if ( (unsigned __int16)v25 + v7 > MmUserProbeAddress || (unsigned __int16)v25 + v7 < v7 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v8 = (unsigned __int16)v25;
    }
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v10 = 40;
      else
        v10 = 32;
      v9 = ExAllocatePoolWithTagPriority(1, v8, 538996553, v10);
      if ( !v9 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v9 = ExAllocatePoolWithQuotaTag(1u, v8, 538996553);
    }
    v28 = v9;
    memmove(v9, v26, (unsigned __int16)v25);
    v26 = v9;
    v6 = ZwUnloadDriver();
    goto LABEL_51;
  }
  v11 = PnpEtwHandle;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverUnload_Start) )
  {
    v12 = *(unsigned __int16 *)a1;
    LOWORD(v22) = *(_WORD *)a1 >> 1;
    v33[0] = &v22;
    v33[1] = 0;
    v34 = 2;
    v35 = 0;
    v36[0] = a1[1];
    v36[1] = 0;
    v36[2] = v12;
    v36[3] = 0;
    EtwWrite(v11, SHIDWORD(v11), (int)KMPnPEvt_DriverUnload_Start, 0);
  }
  v24 = 0;
  v23[0] = 0;
  v23[1] = 0;
  if ( PsIsCurrentThreadInServerSilo() )
  {
    DbgPrint("Server Silo attempting to unload driver %wZ\n", a1);
    return -1073741727;
  }
  v6 = IopOpenRegistryKey(&v27, 0, a1, 131097, 0);
  if ( v6 >= 0 )
  {
    v6 = IopGetDriverNameFromKeyNode(v27);
    ObCloseHandle(v27);
    if ( v6 >= 0 )
    {
      v32[0] = 24;
      v32[1] = 0;
      v32[3] = 576;
      v32[2] = v23;
      v32[4] = 0;
      v32[5] = 0;
      v6 = ObOpenObjectByName((int)v32, IoDriverObjectType, 0, 0, 1, 0, &v29);
      if ( v6 >= 0 )
      {
        v6 = ObReferenceObjectByHandle(v29, 0, IoDriverObjectType, 0, (int)&v22, 0);
        ObCloseHandle(v29);
        if ( v6 >= 0 )
        {
          v13 = v22;
          v14 = RtlImageNtHeader(*(_DWORD *)(v22 + 12));
          v21 = *(unsigned __int16 *)(v14 + 70) | (*(unsigned __int16 *)(v14 + 68) << 16);
          if ( *(_DWORD *)(v13 + 52) && *(_DWORD *)(v13 + 20) && (a2 || PnpIsLegacyDriver(v13)) )
          {
            v15 = IopCheckUnloadDriver(v13, &v22);
            v6 = v15;
            if ( v15 < 0 && v15 != -1073741808 )
            {
              if ( (_BYTE)v22 )
              {
                v16 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
                if ( v16 == PsInitialSystemProcess )
                {
                  (*(void (__fastcall **)(int))(v13 + 52))(v13);
                }
                else
                {
                  KeInitializeEvent((int)v36, 0, 0);
                  v36[4] = v13;
                  v34 = (int)IopLoadUnloadDriver;
                  v35 = v33;
                  v33[0] = 0;
                  ExQueueWorkItem(v33, 1);
                  KeWaitForSingleObject((unsigned int)v36, 0, 0, 0, 0);
                }
                IopCleanupNotifications(v13, v13);
                ObMakeTemporaryObject(v13);
                ObfDereferenceObject(v13);
              }
              ObfDereferenceObject(v13);
              v6 = 0;
            }
          }
          else
          {
            ObfDereferenceObject(v13);
            v6 = -1073741808;
          }
        }
      }
    }
  }
  v31 = v21;
  v30 = v6;
  v17 = *(unsigned __int16 *)a1;
  LOWORD(v22) = *(_WORD *)a1 >> 1;
  v36[8] = &v22;
  v36[9] = 0;
  v36[10] = 2;
  v36[11] = 0;
  v36[12] = a1[1];
  v36[13] = 0;
  v36[14] = v17;
  v36[15] = 0;
  v36[16] = &v30;
  v36[17] = 0;
  v36[18] = 4;
  v36[19] = 0;
  v9 = v24;
  if ( v24 )
    v18 = v23[0] >> 1;
  else
    v18 = 0;
  LOWORD(v21) = v18;
  v36[20] = &v21;
  v36[21] = 0;
  v36[22] = 2;
  v36[23] = 0;
  v36[24] = v24;
  v36[25] = 0;
  v36[26] = 2 * v18;
  v36[27] = 0;
  v36[28] = &v31;
  v36[29] = 0;
  v36[30] = 4;
  v36[31] = 0;
  v19 = PnpEtwHandle;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverUnload_Stop) )
  {
    EtwWrite(v19, SHIDWORD(v19), (int)KMPnPEvt_DriverUnload_Stop, 0);
    v9 = v24;
  }
  if ( v9 )
LABEL_51:
    ExFreePoolWithTag(v9);
  return v6;
}
