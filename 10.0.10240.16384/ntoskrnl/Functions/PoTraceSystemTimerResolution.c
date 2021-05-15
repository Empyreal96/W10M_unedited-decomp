// PoTraceSystemTimerResolution 
 
int *__fastcall PoTraceSystemTimerResolution(int a1, _DWORD *a2)
{
  int v4; // r6
  int v5; // r8
  int *result; // r0
  BOOL v7; // r3
  unsigned __int16 *v8; // r2
  int v9; // r3
  int v10; // r4
  int *v11; // r2
  __int16 v12; // [sp+8h] [bp-98h] BYREF
  int v13; // [sp+Ch] [bp-94h] BYREF
  _DWORD v14[2]; // [sp+10h] [bp-90h] BYREF
  int v15; // [sp+18h] [bp-88h] BYREF
  _DWORD v16[17]; // [sp+1Ch] [bp-84h] BYREF
  int *v17; // [sp+60h] [bp-40h]
  int v18; // [sp+64h] [bp-3Ch]
  int v19; // [sp+68h] [bp-38h]
  int v20; // [sp+6Ch] [bp-34h]
  int *v21; // [sp+70h] [bp-30h]
  int v22; // [sp+74h] [bp-2Ch]
  int v23; // [sp+78h] [bp-28h]
  int v24; // [sp+7Ch] [bp-24h]
  int anonymous11; // [sp+A8h] [bp+8h]
  _DWORD *anonymous12; // [sp+ACh] [bp+Ch]

  anonymous11 = a1;
  anonymous12 = a2;
  LOBYTE(anonymous11) = a1;
  v4 = dword_61E154;
  v5 = PopDiagHandle;
  if ( a1 )
  {
    v7 = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_TIME_RESOLUTION_REQUEST_RUNDOWN)
      || EtwEventEnabled(v5, v4, (int)POP_ETW_EVENT_TIME_RESOLUTION_STACK_RUNDOWN);
    result = (int *)v7;
  }
  else
  {
    result = (int *)EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_STRS);
  }
  if ( PopDiagHandleRegistered && result )
  {
    v8 = (unsigned __int16 *)a2[95];
    v14[1] = v8;
    v12 = *v8 >> 1;
    v14[0] = a2[171];
    v13 = 0;
    if ( !a1 )
    {
      if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
        || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
      {
        v9 = 0;
      }
      else
      {
        v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
      }
      if ( v9 )
        v13 = *(_DWORD *)(v9 + 3936);
      v4 = dword_61E154;
      v5 = PopDiagHandle;
    }
    v16[0] = a2[44];
    v16[1] = v14;
    v16[2] = 0;
    v16[3] = 4;
    v16[4] = 0;
    v16[5] = v16;
    v16[6] = 0;
    v16[7] = 4;
    v16[8] = 0;
    v16[9] = &v12;
    v16[10] = 0;
    v16[11] = 2;
    v16[12] = 0;
    v10 = *v8;
    v16[13] = *((_DWORD *)v8 + 1);
    v16[14] = 0;
    v16[15] = v10;
    v16[16] = 0;
    if ( !a1 )
    {
      v17 = &v13;
      v18 = 0;
      v19 = 4;
      v20 = 0;
      v11 = POP_ETW_EVENT_STRS;
      return (int *)EtwWrite(v5, v4, (int)v11, 0);
    }
    if ( (a2[48] & 0x1000) != 0 )
    {
      EtwWrite(v5, v4, (int)POP_ETW_EVENT_TIME_RESOLUTION_REQUEST_RUNDOWN, 0);
      v4 = dword_61E154;
      v5 = PopDiagHandle;
    }
    result = (int *)a2[170];
    if ( result && *result )
    {
      v14[0] = a2[172];
      v15 = *result;
      v17 = &v15;
      v18 = 0;
      v19 = 4;
      v20 = 0;
      v21 = result + 1;
      v22 = 0;
      v23 = 4 * v15;
      v24 = 0;
      v11 = POP_ETW_EVENT_TIME_RESOLUTION_STACK_RUNDOWN;
      return (int *)EtwWrite(v5, v4, (int)v11, 0);
    }
  }
  return result;
}
