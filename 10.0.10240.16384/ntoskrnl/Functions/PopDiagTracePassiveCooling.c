// PopDiagTracePassiveCooling 
 
int PopDiagTracePassiveCooling(int result, int a2, int a3, ...)
{
  int v5; // r10
  __int64 v6; // kr00_8
  int v7; // r5
  int v8; // r1
  int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r2
  int *v12; // r2
  _BOOL2 v13; // [sp+8h] [bp-F0h] BYREF
  __int16 v14; // [sp+Ah] [bp-EEh] BYREF
  unsigned int v15; // [sp+Ch] [bp-ECh] BYREF
  __int64 v16; // [sp+10h] [bp-E8h] BYREF
  unsigned int v17; // [sp+18h] [bp-E0h] BYREF
  int varD8[55]; // [sp+20h] [bp-D8h] BYREF
  int varg_r3; // [sp+10Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+10Ch] [bp+14h]
  int v21; // [sp+110h] [bp+18h]
  va_list va1; // [sp+114h] [bp+1Ch] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v21 = va_arg(va1, _DWORD);
  v13 = 0;
  v5 = result;
  if ( PopDiagHandleRegistered )
  {
    v6 = *(_QWORD *)&PopDiagHandle;
    if ( (v21
       || (result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_PASSIVE_COOLING_DIAGNOSTIC)) != 0)
      && (v21 != 1 || (result = EtwEventEnabled(v6, SHIDWORD(v6), (int)POP_ETW_EVENT_PASSIVE_COOLING_OPERATIONAL)) != 0)
      && (!v21 || v21 == 1) )
    {
      result = IoGetDeviceAttachmentBaseRef(a2);
      v7 = result;
      if ( result )
        v8 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v8 = 0;
      if ( v8 )
      {
        v9 = *(unsigned __int16 *)(v8 + 160) >> 1;
        varD8[2] = (int)&v14;
        varD8[3] = 0;
        varD8[4] = 2;
        varD8[5] = 0;
        v14 = v9;
        varD8[6] = *(_DWORD *)(v8 + 164);
        varD8[7] = 0;
        varD8[8] = 2 * v9;
        varD8[9] = 0;
        v16 = 0i64;
        KeQuerySystemTime(&v16);
        ExSystemTimeToLocalTime(&v16, varD8);
        varD8[10] = (int)varD8;
        varD8[11] = 0;
        varD8[12] = 8;
        varD8[13] = 0;
        v13 = a3 != 0;
        varD8[14] = (int)&v13;
        varD8[15] = 0;
        v10 = *(_DWORD *)(v5 + 20);
        varD8[16] = 2;
        varD8[17] = 0;
        v17 = v10 / 0xA;
        varD8[18] = (int)&v17;
        varD8[19] = 0;
        v11 = *(_DWORD *)(v5 + 16);
        varD8[20] = 4;
        varD8[21] = 0;
        v15 = v11 / 0xA;
        varD8[22] = (int)&v15;
        varD8[23] = 0;
        varD8[24] = 4;
        varD8[25] = 0;
        varD8[26] = v5 + 4;
        varD8[27] = 0;
        varD8[28] = 4;
        varD8[29] = 0;
        varD8[30] = v5 + 8;
        varD8[31] = 0;
        varD8[32] = 4;
        varD8[33] = 0;
        varD8[34] = v5 + 12;
        varD8[35] = 0;
        varD8[36] = 4;
        varD8[37] = 0;
        va_copy((va_list)&varD8[38], varg_r3a);
        varD8[39] = 0;
        varD8[40] = 4;
        varD8[41] = 0;
        varD8[42] = v5 + 80;
        varD8[43] = 0;
        varD8[44] = 4;
        varD8[45] = 0;
        if ( v21 )
          v12 = POP_ETW_EVENT_PASSIVE_COOLING_OPERATIONAL;
        else
          v12 = POP_ETW_EVENT_PASSIVE_COOLING_DIAGNOSTIC;
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)v12, 0);
      }
      if ( v7 )
        result = ObfDereferenceObject(v7);
    }
  }
  return result;
}
