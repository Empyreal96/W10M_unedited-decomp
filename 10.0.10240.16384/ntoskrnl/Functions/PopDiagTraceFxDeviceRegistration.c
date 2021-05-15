// PopDiagTraceFxDeviceRegistration 
 
int PopDiagTraceFxDeviceRegistration(int a1, ...)
{
  unsigned int v2; // r0
  int v3; // r3
  char v5; // [sp+8h] [bp-A8h] BYREF
  __int16 v6; // [sp+Ah] [bp-A6h] BYREF
  va_list v7; // [sp+10h] [bp-A0h]
  int v8; // [sp+14h] [bp-9Ch]
  int v9; // [sp+18h] [bp-98h]
  int v10; // [sp+1Ch] [bp-94h]
  va_list v11; // [sp+20h] [bp-90h]
  int v12; // [sp+24h] [bp-8Ch]
  int v13; // [sp+28h] [bp-88h]
  int v14; // [sp+2Ch] [bp-84h]
  char *v15; // [sp+30h] [bp-80h]
  int v16; // [sp+34h] [bp-7Ch]
  int v17; // [sp+38h] [bp-78h]
  int v18; // [sp+3Ch] [bp-74h]
  va_list v19; // [sp+40h] [bp-70h]
  int v20; // [sp+44h] [bp-6Ch]
  int v21; // [sp+48h] [bp-68h]
  int v22; // [sp+4Ch] [bp-64h]
  __int16 *v23; // [sp+50h] [bp-60h]
  int v24; // [sp+54h] [bp-5Ch]
  int v25; // [sp+58h] [bp-58h]
  int v26; // [sp+5Ch] [bp-54h]
  int v27; // [sp+60h] [bp-50h]
  int v28; // [sp+64h] [bp-4Ch]
  unsigned int v29; // [sp+68h] [bp-48h]
  int v30; // [sp+6Ch] [bp-44h]
  va_list v31; // [sp+70h] [bp-40h]
  int v32; // [sp+74h] [bp-3Ch]
  int v33; // [sp+78h] [bp-38h]
  int v34; // [sp+7Ch] [bp-34h]
  int v35; // [sp+80h] [bp-30h]
  int v36; // [sp+84h] [bp-2Ch]
  int v37; // [sp+88h] [bp-28h]
  int v38; // [sp+8Ch] [bp-24h]
  int varg_r1; // [sp+A4h] [bp-Ch] BYREF
  va_list varg_r1a; // [sp+A4h] [bp-Ch]
  void *varg_r2; // [sp+A8h] [bp-8h] BYREF
  va_list varg_r2a; // [sp+A8h] [bp-8h]
  int varg_r3; // [sp+ACh] [bp-4h]
  void *v44; // [sp+B0h] [bp+0h] BYREF
  va_list va2; // [sp+B0h] [bp+0h]
  unsigned __int16 *v46; // [sp+B4h] [bp+4h]
  void *v47; // [sp+B8h] [bp+8h] BYREF
  va_list va3; // [sp+B8h] [bp+8h]
  int v49; // [sp+BCh] [bp+Ch]
  va_list va4; // [sp+C0h] [bp+10h] BYREF

  va_start(va4, a1);
  va_start(va3, a1);
  va_start(va2, a1);
  va_start(varg_r2a, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r2a, _DWORD);
  va_copy(va2, varg_r2a);
  varg_r2 = va_arg(va2, void *);
  varg_r3 = va_arg(va2, _DWORD);
  va_copy(va3, va2);
  v44 = va_arg(va3, void *);
  v46 = va_arg(va3, unsigned __int16 *);
  va_copy(va4, va3);
  v47 = va_arg(va4, void *);
  v49 = va_arg(va4, _DWORD);
  v2 = *v46;
  v5 = varg_r3 - 1;
  v6 = v2 >> 1;
  va_copy(v7, varg_r1a);
  v8 = 0;
  v9 = 4;
  v10 = 0;
  va_copy(v11, varg_r2a);
  v12 = 0;
  v13 = 4;
  v14 = 0;
  v15 = &v5;
  v16 = 0;
  v17 = 1;
  v18 = 0;
  va_copy(v19, va2);
  v20 = 0;
  v21 = 4;
  v22 = 0;
  v23 = &v6;
  v24 = 0;
  v25 = 2;
  v26 = 0;
  v3 = *((_DWORD *)v46 + 1);
  v29 = v2;
  v27 = v3;
  v28 = 0;
  v30 = 0;
  va_copy(v31, va3);
  v32 = 0;
  v33 = 4;
  v34 = 0;
  v35 = v49;
  v36 = 0;
  v37 = 12;
  v38 = 0;
  return EtwWrite(PopDiagHandle, dword_61E154, a1, 0);
}
