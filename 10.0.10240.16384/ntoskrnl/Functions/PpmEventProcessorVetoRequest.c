// PpmEventProcessorVetoRequest 
 
int PpmEventProcessorVetoRequest(int result, ...)
{
  int v1; // r7
  int *v2; // r4
  __int64 v3; // kr00_8
  __int16 v4; // [sp+8h] [bp-60h] BYREF
  __int16 *v5; // [sp+10h] [bp-58h]
  int v6; // [sp+14h] [bp-54h]
  int v7; // [sp+18h] [bp-50h]
  int v8; // [sp+1Ch] [bp-4Ch]
  int v9; // [sp+20h] [bp-48h]
  int v10; // [sp+24h] [bp-44h]
  int v11; // [sp+28h] [bp-40h]
  int v12; // [sp+2Ch] [bp-3Ch]
  va_list v13; // [sp+30h] [bp-38h]
  int v14; // [sp+34h] [bp-34h]
  int v15; // [sp+38h] [bp-30h]
  int v16; // [sp+3Ch] [bp-2Ch]
  va_list v17; // [sp+40h] [bp-28h]
  int v18; // [sp+44h] [bp-24h]
  int v19; // [sp+48h] [bp-20h]
  int v20; // [sp+4Ch] [bp-1Ch]
  int varg_r1; // [sp+74h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+74h] [bp+Ch]
  void *varg_r2; // [sp+78h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+78h] [bp+10h]
  int varg_r3; // [sp+7Ch] [bp+14h]
  va_list va2; // [sp+80h] [bp+18h] BYREF

  va_start(va2, result);
  va_start(varg_r2a, result);
  va_start(varg_r1a, result);
  varg_r1 = va_arg(varg_r2a, _DWORD);
  va_copy(va2, varg_r2a);
  varg_r2 = va_arg(va2, void *);
  varg_r3 = va_arg(va2, _DWORD);
  v1 = result;
  if ( varg_r3 )
    v2 = PPM_ETW_PROCESSOR_IDLE_VETO_INCREMENT;
  else
    v2 = PPM_ETW_PROCESSOR_IDLE_VETO_DECREMENT;
  if ( PpmEtwRegistered )
  {
    v3 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)v2);
    if ( result )
    {
      v4 = *(unsigned __int8 *)(v1 + 1052);
      v5 = &v4;
      v6 = 0;
      v7 = 2;
      v8 = 0;
      v9 = v1 + 1053;
      v10 = 0;
      v11 = 1;
      v12 = 0;
      va_copy(v13, varg_r1a);
      v14 = 0;
      v15 = 4;
      v16 = 0;
      va_copy(v17, varg_r2a);
      v18 = 0;
      v19 = 4;
      v20 = 0;
      result = EtwWrite(v3, SHIDWORD(v3), (int)v2, 0);
    }
  }
  return result;
}
