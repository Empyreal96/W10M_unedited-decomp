// PopDiagTraceFxPerfSetRegistration 
 
int PopDiagTraceFxPerfSetRegistration(int a1, ...)
{
  int v2; // r0
  int v3; // r3
  __int16 v5; // [sp+8h] [bp-E8h] BYREF
  va_list v6; // [sp+10h] [bp-E0h]
  int v7; // [sp+14h] [bp-DCh]
  int v8; // [sp+18h] [bp-D8h]
  int v9; // [sp+1Ch] [bp-D4h]
  va_list v10; // [sp+20h] [bp-D0h]
  int v11; // [sp+24h] [bp-CCh]
  int v12; // [sp+28h] [bp-C8h]
  int v13; // [sp+2Ch] [bp-C4h]
  va_list v14; // [sp+30h] [bp-C0h]
  int v15; // [sp+34h] [bp-BCh]
  int v16; // [sp+38h] [bp-B8h]
  int v17; // [sp+3Ch] [bp-B4h]
  __int16 *v18; // [sp+40h] [bp-B0h]
  int v19; // [sp+44h] [bp-ACh]
  int v20; // [sp+48h] [bp-A8h]
  int v21; // [sp+4Ch] [bp-A4h]
  int v22; // [sp+50h] [bp-A0h]
  int v23; // [sp+54h] [bp-9Ch]
  int v24; // [sp+58h] [bp-98h]
  int v25; // [sp+5Ch] [bp-94h]
  va_list v26; // [sp+60h] [bp-90h]
  int v27; // [sp+64h] [bp-8Ch]
  int v28; // [sp+68h] [bp-88h]
  int v29; // [sp+6Ch] [bp-84h]
  va_list v30; // [sp+70h] [bp-80h]
  int v31; // [sp+74h] [bp-7Ch]
  int v32; // [sp+78h] [bp-78h]
  int v33; // [sp+7Ch] [bp-74h]
  va_list v34; // [sp+80h] [bp-70h]
  int v35; // [sp+84h] [bp-6Ch]
  int v36; // [sp+88h] [bp-68h]
  int v37; // [sp+8Ch] [bp-64h]
  va_list v38; // [sp+90h] [bp-60h]
  int v39; // [sp+94h] [bp-5Ch]
  int v40; // [sp+98h] [bp-58h]
  int v41; // [sp+9Ch] [bp-54h]
  va_list v42; // [sp+A0h] [bp-50h]
  int v43; // [sp+A4h] [bp-4Ch]
  int v44; // [sp+A8h] [bp-48h]
  int v45; // [sp+ACh] [bp-44h]
  int v46; // [sp+B0h] [bp-40h]
  int v47; // [sp+B4h] [bp-3Ch]
  int v48; // [sp+B8h] [bp-38h]
  int v49; // [sp+BCh] [bp-34h]
  va_list v50; // [sp+C0h] [bp-30h]
  int v51; // [sp+C4h] [bp-2Ch]
  int v52; // [sp+C8h] [bp-28h]
  int v53; // [sp+CCh] [bp-24h]
  int varg_r1; // [sp+E4h] [bp-Ch] BYREF
  va_list varg_r1a; // [sp+E4h] [bp-Ch]
  void *varg_r2; // [sp+E8h] [bp-8h] BYREF
  va_list varg_r2a; // [sp+E8h] [bp-8h]
  void *varg_r3; // [sp+ECh] [bp-4h] BYREF
  va_list varg_r3a; // [sp+ECh] [bp-4h]
  void *v60; // [sp+F0h] [bp+0h] BYREF
  va_list va3; // [sp+F0h] [bp+0h]
  void *v62; // [sp+F4h] [bp+4h] BYREF
  va_list va4; // [sp+F4h] [bp+4h]
  void *v64; // [sp+F8h] [bp+8h] BYREF
  va_list va5; // [sp+F8h] [bp+8h]
  int v66; // [sp+FCh] [bp+Ch]
  void *v67; // [sp+100h] [bp+10h] BYREF
  va_list va6; // [sp+100h] [bp+10h]
  int v69; // [sp+104h] [bp+14h]
  unsigned __int16 *v70; // [sp+108h] [bp+18h]
  void *v71; // [sp+10Ch] [bp+1Ch] BYREF
  va_list va7; // [sp+10Ch] [bp+1Ch]
  int v73; // [sp+110h] [bp+20h]
  int v74; // [sp+114h] [bp+24h]
  va_list va8; // [sp+118h] [bp+28h] BYREF

  va_start(va8, a1);
  va_start(va7, a1);
  va_start(va6, a1);
  va_start(va5, a1);
  va_start(va4, a1);
  va_start(va3, a1);
  va_start(varg_r3a, a1);
  va_start(varg_r2a, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r2a, _DWORD);
  va_copy(varg_r3a, varg_r2a);
  varg_r2 = va_arg(varg_r3a, void *);
  va_copy(va3, varg_r3a);
  varg_r3 = va_arg(va3, void *);
  va_copy(va4, va3);
  v60 = va_arg(va4, void *);
  va_copy(va5, va4);
  v62 = va_arg(va5, void *);
  va_copy(va6, va5);
  v64 = va_arg(va6, void *);
  v66 = va_arg(va6, _DWORD);
  va_copy(va7, va6);
  v67 = va_arg(va7, void *);
  v69 = va_arg(va7, _DWORD);
  v70 = va_arg(va7, unsigned __int16 *);
  va_copy(va8, va7);
  v71 = va_arg(va8, void *);
  v73 = va_arg(va8, _DWORD);
  v74 = va_arg(va8, _DWORD);
  v2 = *v70;
  v5 = *v70 >> 1;
  va_copy(v6, varg_r1a);
  v7 = 0;
  v8 = 4;
  v9 = 0;
  va_copy(v10, varg_r2a);
  v11 = 0;
  v12 = 4;
  v13 = 0;
  va_copy(v14, varg_r3a);
  v15 = 0;
  v16 = 4;
  v17 = 0;
  v18 = &v5;
  v19 = 0;
  v20 = 2;
  v21 = 0;
  v3 = *((_DWORD *)v70 + 1);
  v24 = v2;
  v22 = v3;
  v23 = 0;
  v25 = 0;
  va_copy(v26, va3);
  v27 = 0;
  v28 = 4;
  v29 = 0;
  va_copy(v30, va4);
  v31 = 0;
  v32 = 4;
  v33 = 0;
  va_copy(v34, va5);
  v35 = 0;
  v36 = 8;
  v37 = 0;
  va_copy(v38, va6);
  v39 = 0;
  v40 = 8;
  v41 = 0;
  va_copy(v42, va7);
  v43 = 0;
  v44 = 4;
  v45 = 0;
  v46 = v73;
  v47 = 0;
  v48 = 8 * (_DWORD)v71;
  v49 = 0;
  va_copy(v50, va8);
  v51 = 0;
  v52 = 8;
  v53 = 0;
  return EtwWrite(PopDiagHandle, dword_61E154, a1, 0);
}
