// PopDiagTraceThermalStateChange 
 
int PopDiagTraceThermalStateChange(int result, ...)
{
  int v1; // r4
  int v2; // r4
  int v3; // r1
  int v4; // r2
  __int16 v5; // [sp+8h] [bp-48h] BYREF
  __int16 *v6; // [sp+10h] [bp-40h]
  int v7; // [sp+14h] [bp-3Ch]
  int v8; // [sp+18h] [bp-38h]
  int v9; // [sp+1Ch] [bp-34h]
  int v10; // [sp+20h] [bp-30h]
  int v11; // [sp+24h] [bp-2Ch]
  int v12; // [sp+28h] [bp-28h]
  int v13; // [sp+2Ch] [bp-24h]
  va_list v14; // [sp+30h] [bp-20h]
  int v15; // [sp+34h] [bp-1Ch]
  int v16; // [sp+38h] [bp-18h]
  int v17; // [sp+3Ch] [bp-14h]
  int varg_r1; // [sp+5Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  va_list varg_r3; // [sp+64h] [bp+14h] BYREF

  va_start(varg_r3, result);
  va_start(varg_r1a, result);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, varg_r2);
    if ( result )
    {
      result = IoGetDeviceAttachmentBaseRef(v1);
      v2 = result;
      if ( result )
        v3 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v3 = 0;
      if ( v3 )
      {
        v4 = *(unsigned __int16 *)(v3 + 160) >> 1;
        v6 = &v5;
        v7 = 0;
        v8 = 2;
        v9 = 0;
        v5 = v4;
        v10 = *(_DWORD *)(v3 + 164);
        v11 = 0;
        v12 = 2 * v4;
        v13 = 0;
        va_copy(v14, varg_r1a);
        v15 = 0;
        v16 = 4;
        v17 = 0;
        result = EtwWrite(PopDiagHandle, dword_61E154, varg_r2, 0);
      }
      if ( v2 )
        result = ObfDereferenceObjectWithTag(v2);
    }
  }
  return result;
}
