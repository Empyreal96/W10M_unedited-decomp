// PopDiagTraceThermalZoneRundown 
 
int PopDiagTraceThermalZoneRundown(int result, int a2, ...)
{
  int v3; // r4
  int v4; // r4
  int v5; // r1
  int v6; // r2
  _BOOL2 v7; // [sp+8h] [bp-A0h] BYREF
  _BOOL2 v8; // [sp+Ah] [bp-9Eh] BYREF
  __int16 v9; // [sp+Ch] [bp-9Ch] BYREF
  __int16 *v10; // [sp+10h] [bp-98h]
  int v11; // [sp+14h] [bp-94h]
  int v12; // [sp+18h] [bp-90h]
  int v13; // [sp+1Ch] [bp-8Ch]
  int v14; // [sp+20h] [bp-88h]
  int v15; // [sp+24h] [bp-84h]
  int v16; // [sp+28h] [bp-80h]
  int v17; // [sp+2Ch] [bp-7Ch]
  _BOOL2 *v18; // [sp+30h] [bp-78h]
  int v19; // [sp+34h] [bp-74h]
  int v20; // [sp+38h] [bp-70h]
  int v21; // [sp+3Ch] [bp-6Ch]
  va_list v22; // [sp+40h] [bp-68h]
  int v23; // [sp+44h] [bp-64h]
  int v24; // [sp+48h] [bp-60h]
  int v25; // [sp+4Ch] [bp-5Ch]
  _BOOL2 *v26; // [sp+50h] [bp-58h]
  int v27; // [sp+54h] [bp-54h]
  int v28; // [sp+58h] [bp-50h]
  int v29; // [sp+5Ch] [bp-4Ch]
  va_list v30; // [sp+60h] [bp-48h]
  int v31; // [sp+64h] [bp-44h]
  int v32; // [sp+68h] [bp-40h]
  int v33; // [sp+6Ch] [bp-3Ch]
  va_list v34; // [sp+70h] [bp-38h]
  int v35; // [sp+74h] [bp-34h]
  int v36; // [sp+78h] [bp-30h]
  int v37; // [sp+7Ch] [bp-2Ch]
  va_list v38; // [sp+80h] [bp-28h]
  int v39; // [sp+84h] [bp-24h]
  int v40; // [sp+88h] [bp-20h]
  int v41; // [sp+8Ch] [bp-1Ch]
  int varg_r2; // [sp+B8h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+B8h] [bp+10h]
  int varg_r3; // [sp+BCh] [bp+14h]
  void *v45; // [sp+C0h] [bp+18h] BYREF
  va_list va1; // [sp+C0h] [bp+18h]
  void *v47; // [sp+C4h] [bp+1Ch] BYREF
  va_list va2; // [sp+C4h] [bp+1Ch]
  va_list va3; // [sp+C8h] [bp+20h] BYREF

  va_start(va3, a2);
  va_start(va2, a2);
  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v45 = va_arg(va2, void *);
  va_copy(va3, va2);
  v47 = va_arg(va3, void *);
  v3 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_ZONE_RUNDOWN);
    if ( result )
    {
      result = IoGetDeviceAttachmentBaseRef(v3);
      v4 = result;
      if ( result )
        v5 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v5 = 0;
      if ( v5 )
      {
        v6 = *(unsigned __int16 *)(v5 + 160) >> 1;
        v10 = &v9;
        v11 = 0;
        v12 = 2;
        v13 = 0;
        v9 = v6;
        v14 = *(_DWORD *)(v5 + 164);
        v15 = 0;
        v16 = 2 * v6;
        v17 = 0;
        v8 = a2 != 0;
        v18 = &v8;
        v19 = 0;
        v20 = 2;
        v21 = 0;
        va_copy(v22, varg_r2a);
        v23 = 0;
        v24 = 4;
        v25 = 0;
        v7 = varg_r3 != 0;
        v26 = &v7;
        v27 = 0;
        v28 = 2;
        v29 = 0;
        va_copy(v30, va1);
        v31 = 0;
        v32 = 4;
        v33 = 0;
        va_copy(v34, va2);
        v35 = 0;
        v36 = 4;
        v37 = 0;
        va_copy(v38, va3);
        v39 = 0;
        v40 = 4;
        v41 = 0;
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_ZONE_RUNDOWN, 0);
      }
      if ( v4 )
        result = ObfDereferenceObjectWithTag(v4);
    }
  }
  return result;
}
