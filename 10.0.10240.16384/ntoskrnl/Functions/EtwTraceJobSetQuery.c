// EtwTraceJobSetQuery 
 
int *EtwTraceJobSetQuery(int a1, int a2, int a3, _DWORD *a4, int *a5, ...)
{
  int *result; // r0
  int v9; // r6
  int v10; // r4
  int v11; // r4
  int *v12; // r2
  int v13; // r4
  int *v14; // r3
  int *v15; // r2
  int *v16; // r2
  unsigned int v17; // r1
  int *v18; // r2
  unsigned int v19; // r1
  int *v20; // r2
  int *v21; // r2
  int *v22; // r2
  int *v23; // r2
  int *v24; // r2
  int *v25; // r2
  int *v26; // r2
  int v27; // [sp+8h] [bp-178h] BYREF
  int v28[2]; // [sp+10h] [bp-170h] BYREF
  int v29[2]; // [sp+18h] [bp-168h] BYREF
  char v30[16]; // [sp+20h] [bp-160h] BYREF
  int v31; // [sp+30h] [bp-150h]
  int v32; // [sp+34h] [bp-14Ch]
  int v33[4]; // [sp+38h] [bp-148h] BYREF
  va_list v34; // [sp+48h] [bp-138h]
  int v35; // [sp+4Ch] [bp-134h]
  int v36; // [sp+50h] [bp-130h]
  int v37; // [sp+54h] [bp-12Ch]
  _DWORD *v38; // [sp+58h] [bp-128h]
  int v39; // [sp+5Ch] [bp-124h]
  int v40; // [sp+60h] [bp-120h]
  int v41; // [sp+64h] [bp-11Ch]
  _DWORD *v42; // [sp+68h] [bp-118h]
  int v43; // [sp+6Ch] [bp-114h]
  int v44; // [sp+70h] [bp-110h]
  int v45; // [sp+74h] [bp-10Ch]
  _DWORD *v46; // [sp+78h] [bp-108h]
  int v47; // [sp+7Ch] [bp-104h]
  int v48; // [sp+80h] [bp-100h]
  int v49; // [sp+84h] [bp-FCh]
  _DWORD *v50; // [sp+88h] [bp-F8h]
  int v51; // [sp+8Ch] [bp-F4h]
  int v52; // [sp+90h] [bp-F0h]
  int v53; // [sp+94h] [bp-ECh]
  _DWORD *v54; // [sp+98h] [bp-E8h]
  int v55; // [sp+9Ch] [bp-E4h]
  int v56; // [sp+A0h] [bp-E0h]
  int v57; // [sp+A4h] [bp-DCh]
  _DWORD *v58; // [sp+A8h] [bp-D8h]
  int v59; // [sp+ACh] [bp-D4h]
  int v60; // [sp+B0h] [bp-D0h]
  int v61; // [sp+B4h] [bp-CCh]
  _DWORD *v62; // [sp+B8h] [bp-C8h]
  int v63; // [sp+BCh] [bp-C4h]
  int v64; // [sp+C0h] [bp-C0h]
  int v65; // [sp+C4h] [bp-BCh]
  _DWORD *v66; // [sp+C8h] [bp-B8h]
  int v67; // [sp+CCh] [bp-B4h]
  int v68; // [sp+D0h] [bp-B0h]
  int v69; // [sp+D4h] [bp-ACh]
  _DWORD *v70; // [sp+D8h] [bp-A8h]
  int v71; // [sp+DCh] [bp-A4h]
  int v72; // [sp+E0h] [bp-A0h]
  int v73; // [sp+E4h] [bp-9Ch]
  _DWORD *v74; // [sp+E8h] [bp-98h]
  int v75; // [sp+ECh] [bp-94h]
  int v76; // [sp+F0h] [bp-90h]
  int v77; // [sp+F4h] [bp-8Ch]
  _DWORD *v78; // [sp+F8h] [bp-88h]
  int v79; // [sp+FCh] [bp-84h]
  int v80; // [sp+100h] [bp-80h]
  int v81; // [sp+104h] [bp-7Ch]
  _DWORD *v82; // [sp+108h] [bp-78h]
  int v83; // [sp+10Ch] [bp-74h]
  int v84; // [sp+110h] [bp-70h]
  int v85; // [sp+114h] [bp-6Ch]
  _DWORD *v86; // [sp+118h] [bp-68h]
  int v87; // [sp+11Ch] [bp-64h]
  int v88; // [sp+120h] [bp-60h]
  int v89; // [sp+124h] [bp-5Ch]
  _DWORD *v90; // [sp+128h] [bp-58h]
  int v91; // [sp+12Ch] [bp-54h]
  int v92; // [sp+130h] [bp-50h]
  int v93; // [sp+134h] [bp-4Ch]
  _DWORD *v94; // [sp+138h] [bp-48h]
  int v95; // [sp+13Ch] [bp-44h]
  int v96; // [sp+140h] [bp-40h]
  int v97; // [sp+144h] [bp-3Ch]
  _DWORD *v98; // [sp+148h] [bp-38h]
  int v99; // [sp+14Ch] [bp-34h]
  int v100; // [sp+150h] [bp-30h]
  int v101; // [sp+154h] [bp-2Ch]
  int *v102; // [sp+158h] [bp-28h]
  int v103; // [sp+15Ch] [bp-24h]
  int v104; // [sp+160h] [bp-20h]
  int v105; // [sp+164h] [bp-1Ch]
  int v106; // [sp+19Ch] [bp+1Ch] BYREF
  va_list va; // [sp+19Ch] [bp+1Ch]
  int v108; // [sp+1A0h] [bp+20h]
  va_list va1; // [sp+1A4h] [bp+24h] BYREF

  va_start(va1, a5);
  va_start(va, a5);
  v106 = va_arg(va1, _DWORD);
  v108 = va_arg(va1, _DWORD);
  result = (int *)EtwpCopyJobGuidSafe(v30, a1);
  v33[1] = 0;
  v9 = (unsigned __int16)v108;
  v33[2] = 24;
  v32 = a3;
  v33[0] = (int)v30;
  v31 = a2;
  v10 = 1;
  v33[3] = 0;
  if ( (unsigned __int16)v108 != 1829 )
  {
    if ( (unsigned __int16)v108 == 1830 )
    {
      if ( a3 != 13 )
        return result;
      v34 = (va_list)a4;
      v35 = 0;
      v36 = 4;
      v37 = 0;
      v38 = a4 + 1;
      v39 = 0;
      v40 = 4;
      v41 = 0;
      v42 = a4 + 2;
      v43 = 0;
      v44 = 8;
      v45 = 0;
      v46 = a4 + 4;
      v47 = 0;
      v48 = 8;
      v49 = 0;
      v50 = a4 + 6;
      v51 = 0;
      v52 = 8;
      v53 = 0;
      v54 = a4 + 8;
      v55 = 0;
      v56 = 8;
      v57 = 0;
      v58 = a4 + 10;
      v59 = 0;
      v60 = 8;
      v61 = 0;
      v62 = a4 + 12;
      v63 = 0;
      v64 = 8;
      v65 = 0;
      v66 = a4 + 14;
      v67 = 0;
      v68 = 8;
      v69 = 0;
      v70 = a4 + 20;
      v71 = 0;
      v72 = 8;
      v73 = 0;
      v74 = a4 + 16;
      v75 = 0;
      v76 = 8;
      v77 = 0;
      v78 = a4 + 18;
      v79 = 0;
      v80 = 4;
      v81 = 0;
      v82 = a4 + 19;
      v83 = 0;
      v84 = 4;
      v85 = 0;
      v86 = a4 + 22;
      v87 = 0;
      v88 = 4;
      v89 = 0;
      v90 = a4 + 23;
      v91 = 0;
      v92 = 4;
      v93 = 0;
      v94 = a4 + 24;
      v95 = 0;
      v96 = 4;
      v97 = 0;
      v98 = a4 + 25;
      v99 = 0;
      v100 = 4;
      v101 = 0;
      v9 = 1835;
      v27 = *a5;
      v102 = &v27;
      v103 = 0;
      v104 = 4;
      v105 = 0;
      v11 = 19;
    }
    else
    {
      if ( (unsigned int)(unsigned __int16)v108 - 1831 > 1 )
        return result;
      va_copy(v34, va);
      v35 = 0;
      v36 = 4;
      v37 = 0;
      v11 = 2;
    }
    return EtwTraceKernelEvent(v33, v11, 0x80000u, v9, (int)off_501904);
  }
  if ( a3 != 12 )
  {
    if ( a3 == 15 )
    {
      v34 = (va_list)a4;
      v35 = 0;
      v36 = 4;
      v37 = 0;
      v38 = a4 + 1;
      v39 = 0;
      v40 = 4;
      v41 = 0;
      v11 = 3;
      v9 = 1836;
      return EtwTraceKernelEvent(v33, v11, 0x80000u, v9, (int)off_501904);
    }
    if ( a3 != 32 )
      return result;
    v34 = (va_list)a4;
    v35 = 0;
    v36 = 4;
    v37 = 0;
    v38 = a4 + 2;
    v39 = 0;
    v40 = 8;
    v41 = 0;
    v42 = a4 + 4;
    v43 = 0;
    v44 = 1;
    v45 = 0;
    v10 = 4;
  }
  v12 = &v33[4 * v10];
  *v12 = (int)(a4 + 10);
  v13 = v10 + 1;
  v14 = &v33[4 * v13];
  v12[1] = 0;
  v12[2] = 4;
  v12[3] = 0;
  *v14 = (int)a4;
  v14[1] = 0;
  v14[2] = 8;
  v14[3] = 0;
  ++v13;
  v15 = &v33[4 * v13];
  *v15 = (int)(a4 + 2);
  v15[1] = 0;
  ++v13;
  v15[2] = 8;
  v15[3] = 0;
  v16 = &v33[4 * v13];
  v17 = a4[13];
  *v16 = (int)(a4 + 4);
  v16[1] = 0;
  v16[2] = 8;
  v16[3] = 0;
  ++v13;
  v29[0] = (v17 << 20) | (a4[12] >> 12);
  v29[1] = v17 >> 12;
  v18 = &v33[4 * v13];
  v19 = a4[7];
  *v18 = (int)v29;
  v18[1] = 0;
  v18[2] = 8;
  v18[3] = 0;
  ++v13;
  v28[0] = (v19 << 20) | (a4[6] >> 12);
  v28[1] = v19 >> 12;
  v20 = &v33[4 * v13];
  *v20 = (int)v28;
  v20[1] = 0;
  ++v13;
  v20[2] = 8;
  v20[3] = 0;
  v21 = &v33[4 * v13];
  *v21 = (int)(a4 + 8);
  v21[1] = 0;
  ++v13;
  *((_QWORD *)v21 + 1) = 4i64;
  v22 = &v33[4 * v13];
  *v22 = (int)(a4 + 9);
  v22[1] = 0;
  ++v13;
  *((_QWORD *)v22 + 1) = 4i64;
  v23 = &v33[4 * v13];
  *v23 = (int)(a4 + 11);
  v23[1] = 0;
  ++v13;
  *((_QWORD *)v23 + 1) = 4i64;
  v24 = &v33[4 * v13];
  *v24 = (int)(a4 + 14);
  v24[1] = 0;
  ++v13;
  *((_QWORD *)v24 + 1) = 4i64;
  v25 = &v33[4 * v13];
  *v25 = (int)(a4 + 15);
  v25[1] = 0;
  ++v13;
  *((_QWORD *)v25 + 1) = 4i64;
  v26 = &v33[4 * v13];
  v26[1] = 0;
  v26[2] = 4;
  *v26 = (int)(a4 + 16);
  v9 = 1833;
  v26[3] = 0;
  v11 = v13 + 1;
  return EtwTraceKernelEvent(v33, v11, 0x80000u, v9, (int)off_501904);
}
