// PopDiagTraceIllegalProcessorThrottle 
 
int *__fastcall PopDiagTraceIllegalProcessorThrottle(int *result, int a2, int a3, int a4, __int64 *a5)
{
  int v5; // r7
  __int64 v6; // kr08_8
  int v7; // r6
  int v8; // r5
  __int64 v9; // kr18_8
  int *v10; // [sp+8h] [bp-70h] BYREF
  __int64 v11; // [sp+10h] [bp-68h] BYREF
  int *v12; // [sp+18h] [bp-60h]
  int v13; // [sp+1Ch] [bp-5Ch]
  int v14; // [sp+20h] [bp-58h]
  int v15; // [sp+24h] [bp-54h]
  int *v16; // [sp+28h] [bp-50h]
  int v17; // [sp+2Ch] [bp-4Ch]
  int v18; // [sp+30h] [bp-48h]
  int v19; // [sp+34h] [bp-44h]
  int *v20; // [sp+38h] [bp-40h]
  int v21; // [sp+3Ch] [bp-3Ch]
  int v22; // [sp+40h] [bp-38h]
  int v23; // [sp+44h] [bp-34h]
  int *v24; // [sp+48h] [bp-30h]
  int v25; // [sp+4Ch] [bp-2Ch]
  int v26; // [sp+50h] [bp-28h]
  int v27; // [sp+54h] [bp-24h]
  int varg_r0[2]; // [sp+80h] [bp+8h] BYREF
  int varg_r2[2]; // [sp+88h] [bp+10h] BYREF

  varg_r0[0] = (int)result;
  varg_r0[1] = a2;
  varg_r2[0] = a3;
  varg_r2[1] = a4;
  v5 = (unsigned __int8)PopDiagHandleRegistered;
  v6 = *(_QWORD *)&PopDiagHandle;
  v7 = 1;
  v8 = 1;
  if ( !PopDiagHandleRegistered
    || (result = (int *)EtwEventEnabled(
                          PopDiagHandle,
                          dword_61E154,
                          (int)POP_ETW_EVENT_ILLEGAL_PROCESSOR_THROTTLE_DIAGNOSTIC)) == 0 )
  {
    v7 = 0;
  }
  if ( !v5
    || (result = (int *)EtwEventEnabled(v6, SHIDWORD(v6), (int)POP_ETW_EVENT_ILLEGAL_PROCESSOR_THROTTLE_OPERATIONAL)) == 0 )
  {
    v8 = 0;
  }
  if ( v7 || v8 )
  {
    v12 = varg_r0;
    v13 = 0;
    v14 = 4;
    v15 = 0;
    v16 = varg_r2;
    v17 = 0;
    v18 = 8;
    v19 = 0;
    result = KeQueryTickCount((int *)&v11);
    v9 = v11;
    if ( *a5 )
    {
      result = (int *)_rt_sdiv64((unsigned int)dword_989680, (v11 - *a5) * (unsigned int)KeMaximumIncrement);
      v10 = result;
    }
    else
    {
      v10 = 0;
    }
    v20 = (int *)&v10;
    v21 = 0;
    v22 = 4;
    v23 = 0;
    *a5 = v9;
    v24 = &PopProcessorThrottleLogInterval;
    v25 = 0;
    v26 = 4;
    v27 = 0;
    if ( v7 )
      result = (int *)EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_ILLEGAL_PROCESSOR_THROTTLE_DIAGNOSTIC, 0);
    if ( v8 )
      result = (int *)EtwWrite(
                        PopDiagHandle,
                        dword_61E154,
                        (int)POP_ETW_EVENT_ILLEGAL_PROCESSOR_THROTTLE_OPERATIONAL,
                        0);
  }
  return result;
}
