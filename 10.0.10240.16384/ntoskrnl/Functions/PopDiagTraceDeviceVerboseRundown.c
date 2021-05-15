// PopDiagTraceDeviceVerboseRundown 
 
int __fastcall PopDiagTraceDeviceVerboseRundown(int result)
{
  int v1; // r6
  unsigned int *v2; // r0
  int v3; // r2
  int v4; // r2
  int v5; // r2
  __int16 v6; // [sp+8h] [bp-C8h] BYREF
  __int16 v7; // [sp+Ah] [bp-C6h] BYREF
  __int16 v8; // [sp+Ch] [bp-C4h] BYREF
  int v9; // [sp+10h] [bp-C0h] BYREF
  int v10; // [sp+14h] [bp-BCh] BYREF
  int v11; // [sp+18h] [bp-B8h] BYREF
  int v12[45]; // [sp+1Ch] [bp-B4h] BYREF

  v1 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_VERBOSE_RUNDOWN);
    if ( result )
    {
      v2 = *(unsigned int **)(v1 + 32);
      v9 = *(_DWORD *)(v1 + 28);
      v10 = 0;
      v7 = *(_WORD *)(v9 + 160) >> 1;
      v6 = *(_WORD *)(v9 + 20) >> 1;
      v8 = *(_WORD *)(v9 + 28) >> 1;
      PopPepGetDevicePlatformStateDependents(v2, &v10);
      v12[0] = *(_DWORD *)(v9 + 8);
      v11 = *(_DWORD *)(v9 + 16);
      v12[1] = (int)&v9;
      v12[2] = 0;
      v12[3] = 4;
      v12[4] = 0;
      v12[5] = (int)&v7;
      v12[6] = 0;
      v12[7] = 2;
      v12[8] = 0;
      v3 = *(unsigned __int16 *)(v9 + 160);
      v12[9] = *(_DWORD *)(v9 + 164);
      v12[10] = 0;
      v12[11] = v3;
      v12[12] = 0;
      v12[13] = (int)&v6;
      v12[14] = 0;
      v12[15] = 2;
      v12[16] = 0;
      v4 = *(unsigned __int16 *)(v9 + 20);
      v12[17] = *(_DWORD *)(v9 + 24);
      v12[18] = 0;
      v12[19] = v4;
      v12[20] = 0;
      v12[21] = (int)&v8;
      v12[22] = 0;
      v12[23] = 2;
      v12[24] = 0;
      v5 = *(unsigned __int16 *)(v9 + 28);
      v12[25] = *(_DWORD *)(v9 + 32);
      v12[26] = 0;
      v12[27] = v5;
      v12[28] = 0;
      v12[29] = (int)&v10;
      v12[30] = 0;
      v12[31] = 4;
      v12[32] = 0;
      v12[33] = (int)&v11;
      v12[34] = 0;
      v12[35] = 4;
      v12[36] = 0;
      v12[37] = (int)v12;
      v12[38] = 0;
      v12[39] = 4;
      v12[40] = 0;
      result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_VERBOSE_RUNDOWN, (int)&PopDiagActivityId);
    }
  }
  return result;
}
