// LdrpResSearchResourceInsideDirectory 
 
int __fastcall LdrpResSearchResourceInsideDirectory(int a1, int a2, int a3, int a4, int a5, int a6, int *a7, int a8, __int16 *a9, unsigned int *a10, unsigned int *a11, int a12, _WORD *a13)
{
  unsigned int v13; // r5
  unsigned int v14; // r8
  int v15; // lr
  int v16; // r1
  int v17; // r2
  unsigned int v18; // r4
  unsigned int *v19; // r6
  bool v20; // zf
  unsigned int v22; // r6
  int v23; // r5
  int *v24; // r0
  int v25; // r1
  int *v26; // r8
  unsigned int v27; // r2
  int v28; // r3
  int v29; // r5
  int v30; // r6
  int v31; // r0
  int v32; // r3
  int v33; // r1
  int v34; // r0
  int v35; // r2
  unsigned int v36; // r4
  unsigned int v37; // r8
  int v38; // r2
  int v39; // r1
  unsigned int v40; // r5
  int v41; // r0
  int v42; // r0
  int v43; // r6
  int v44; // r0
  int v45; // r5
  unsigned int v46; // r2
  unsigned int v47; // r1
  unsigned int v48; // r3
  int v49; // r2
  unsigned int v50; // r5
  unsigned int v51; // r3
  unsigned int v52; // r1
  int v53; // r1
  unsigned int v54; // r8
  unsigned int v55; // r6
  int v56; // r3
  int v58; // [sp+10h] [bp-A8h]
  unsigned int v59; // [sp+14h] [bp-A4h] BYREF
  int v60; // [sp+18h] [bp-A0h]
  unsigned int *v61; // [sp+1Ch] [bp-9Ch]
  int v62; // [sp+20h] [bp-98h]
  unsigned int v63; // [sp+24h] [bp-94h]
  unsigned int v64; // [sp+28h] [bp-90h]
  int v65; // [sp+2Ch] [bp-8Ch]
  unsigned int v66; // [sp+30h] [bp-88h]
  int v67; // [sp+34h] [bp-84h]
  int *v68; // [sp+38h] [bp-80h]
  int v69; // [sp+3Ch] [bp-7Ch]
  unsigned int v70; // [sp+40h] [bp-78h]
  int v71; // [sp+44h] [bp-74h]
  unsigned int v72; // [sp+48h] [bp-70h]
  unsigned int v73; // [sp+4Ch] [bp-6Ch]
  int v74; // [sp+50h] [bp-68h]
  int v75; // [sp+54h] [bp-64h]
  int v76; // [sp+58h] [bp-60h] BYREF
  int v77; // [sp+5Ch] [bp-5Ch]
  int *v78; // [sp+60h] [bp-58h]
  __int16 v79; // [sp+64h] [bp-54h]
  int v80; // [sp+68h] [bp-50h] BYREF
  int *v81; // [sp+6Ch] [bp-4Ch]
  int v82; // [sp+70h] [bp-48h]
  unsigned int v83; // [sp+74h] [bp-44h]
  __int16 v84; // [sp+78h] [bp-40h]
  int v85; // [sp+84h] [bp-34h]
  int v86; // [sp+88h] [bp-30h]
  int v87; // [sp+8Ch] [bp-2Ch]
  int v88; // [sp+90h] [bp-28h]
  int *v89; // [sp+94h] [bp-24h]
  unsigned int v90; // [sp+98h] [bp-20h]
  int varg_r0; // [sp+C0h] [bp+8h]
  int varg_r1; // [sp+C4h] [bp+Ch]
  int varg_r2; // [sp+C8h] [bp+10h]
  int varg_r3; // [sp+CCh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v13 = a4;
  v62 = a4;
  v14 = a3;
  v64 = a3;
  v15 = a1;
  v60 = a1;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v73 = 0;
  LOWORD(a1) = 0;
  v77 = 0;
  if ( !a4 )
    return -1073741811;
  if ( !a5 )
    return -1073741811;
  v81 = a7;
  if ( !a7 )
    return -1073741811;
  if ( (unsigned int)(a8 - 1) > 3 )
    return -1073741811;
  v16 = a12;
  v69 = a12;
  if ( (a12 & 0x8000) != 0 )
    return -1073741811;
  v17 = (a12 & 0x8800) == 34816;
  v74 = v17;
  if ( (a12 & 0x1000) != 0 && !v14 )
    return -1073741811;
  if ( (a12 & 0x8800) != 34816 && !v15 || v17 == 1 )
    return -1073741811;
  v65 = a8;
  v18 = a4;
  v19 = 0;
  v61 = 0;
  v70 = 0;
  if ( a13 )
    *a13 = 0;
LABEL_13:
  if ( !v18 )
    goto LABEL_117;
  v20 = v65-- == 0;
  v88 = v65;
  if ( v20 )
    goto LABEL_117;
  v71 = *v81;
  v75 = v71;
  if ( !v65 && a8 == 3 )
  {
    v70 = v18;
    v90 = v18;
    if ( !a9 )
      return -1073741811;
    v73 = *a9;
    v84 = v73;
    v77 = 0;
    v79 = 0;
    if ( (~v16 & 4) != 0 )
    {
      v71 = (unsigned __int16)a9[2];
      v75 = v71;
    }
  }
  if ( v17 )
    goto LABEL_28;
  if ( (a12 & 0x1000) != 0 )
  {
    if ( RtlUIntAdd(v18, 24, &v59) < 0 )
      return -1073741701;
    v15 = v60;
    if ( v18 + 24 > (v60 & 0xFFFFFFFC) + v14 )
      return -1073741701;
    v17 = v74;
  }
  if ( v17 )
LABEL_28:
    v22 = (unsigned __int16)v87;
  else
    v22 = *(unsigned __int16 *)(v18 + 12);
  v72 = v22;
  v67 = v22;
  if ( v22 && (a12 & 0x1000) != 0 )
  {
    if ( RtlULongLongToULong(8 * v22, v22 >> 29, &v80) < 0 )
      return -1073741701;
    v23 = v80;
    if ( RtlUIntAdd(v18, v80 + 16, &v59) < 0 )
      return -1073741701;
    v15 = v60;
    if ( v23 + v18 + 16 > (v60 & 0xFFFFFFFC) + v14 )
      return -1073741701;
    v13 = v62;
  }
  v24 = (int *)(v18 + 16);
  v68 = (int *)(v18 + 16);
  v78 = (int *)(v18 + 16);
  if ( (v71 & 0xFFFF0000) == 0 )
  {
    if ( v22 )
    {
      if ( (a12 & 0x1000) != 0 )
      {
        if ( RtlUIntAdd((unsigned int)v24, v22, &v59) < 0 )
          return -1073741701;
        v24 = v68;
        v15 = v60;
      }
      v24 += 2 * v22;
      v68 = v24;
      v78 = v24;
    }
    v22 = v74 ? HIWORD(v87) : *(unsigned __int16 *)(v18 + 14);
    v72 = v22;
    v67 = v22;
    if ( (a12 & 0x1000) != 0 )
    {
      if ( RtlULongLongToULong(8 * v22, v22 >> 29, &v80) < 0 )
        return -1073741701;
      if ( RtlUIntAdd((unsigned int)v68, v80, &v59) < 0 )
        return -1073741701;
      v15 = v60;
      v24 = v68;
      if ( (unsigned int)v68 + v25 > (v60 & 0xFFFFFFFC) + v14 )
        return -1073741701;
    }
  }
  if ( !v22 )
  {
    v66 = 0;
    goto LABEL_191;
  }
  v16 = v69;
LABEL_52:
  if ( !v70 || (v16 & 0x20) == 0 )
  {
LABEL_59:
    v18 = 0;
    v66 = 0;
    v26 = v24;
    v78 = v24;
    v27 = (unsigned int)&v24[2 * v22 - 2];
    v82 = v27;
    v83 = v27;
    v28 = v22;
    v67 = v22;
    while ( 1 )
    {
      if ( (unsigned int)v26 > v27 )
      {
        v19 = v61;
        v13 = v62;
        goto LABEL_107;
      }
      v29 = v28 >> 1;
      if ( !(v28 >> 1) )
      {
        v13 = v62;
        if ( !v28 )
        {
          v19 = v61;
          goto LABEL_107;
        }
        v34 = LdrpResCompareResourceNames(v15, v16, v64, v71, v62, v26, v16, &v76, v58);
        v58 = v34;
        if ( v34 < 0 )
        {
          v32 = v34;
          v65 = v34;
          return v32;
        }
        if ( !v76 )
        {
          v33 = v26[1];
          if ( v33 >= 0 )
          {
            if ( (a12 & 0x1000) == 0 )
              goto LABEL_91;
            if ( !v70 )
              return -1073741701;
LABEL_87:
            if ( RtlUIntAdd(v13, v33, &v59) < 0 )
              return -1073741701;
            v19 = (unsigned int *)v59;
LABEL_89:
            v61 = v19;
            v63 = (unsigned int)v19;
            goto LABEL_106;
          }
          if ( (a12 & 0x1000) == 0 )
            goto LABEL_83;
          if ( v70 )
            return -1073741701;
LABEL_79:
          if ( RtlUIntAdd(v13, v33 & 0x7FFFFFFF, &v59) < 0 )
            return -1073741701;
          v18 = v59;
LABEL_81:
          v66 = v18;
        }
        v19 = v61;
LABEL_106:
        v15 = v60;
LABEL_107:
        v16 = v69;
        if ( !v70 || v19 )
          goto LABEL_114;
        if ( (v69 & 4) != 0 )
        {
          LOWORD(a1) = v71;
          goto LABEL_116;
        }
        v35 = (unsigned __int16)(v77 + 1);
        v77 = v35;
        v79 = v35;
        if ( v35 < (int)v73 )
        {
          v71 = (unsigned __int16)a9[4 * v35 + 2];
          v75 = v71;
          v22 = v72;
          v24 = v68;
          goto LABEL_59;
        }
        if ( !*((_BYTE *)a9 + 516) )
        {
          v16 = v69 | 0x20;
          v69 |= 0x20u;
          v22 = v72;
          v24 = v68;
          goto LABEL_52;
        }
LABEL_114:
        v89 = ++v81;
        v14 = v64;
        LOWORD(a1) = v71;
        v17 = v74;
        goto LABEL_13;
      }
      if ( (v67 & 1) != 0 )
        v30 = (int)&v26[2 * v29];
      else
        v30 = (int)&v26[2 * v29 - 2];
      v31 = LdrpResCompareResourceNames(v15, v16, v64, v71, v62, v30, v16, &v76, v58);
      v58 = v31;
      if ( v31 < 0 )
      {
        v32 = v31;
        v65 = v31;
        return v32;
      }
      if ( !v76 )
      {
        v33 = *(_DWORD *)(v30 + 4);
        if ( v33 < 0 )
        {
          if ( (a12 & 0x1000) != 0 )
          {
            if ( v70 )
              return -1073741701;
            v13 = v62;
            goto LABEL_79;
          }
          v13 = v62;
LABEL_83:
          v18 = (v33 & 0x7FFFFFFF) + v13;
          goto LABEL_81;
        }
        v18 = 0;
        v66 = 0;
        if ( (a12 & 0x1000) != 0 )
        {
          if ( !v70 )
            return -1073741701;
          v13 = v62;
          goto LABEL_87;
        }
        v13 = v62;
LABEL_91:
        v19 = (unsigned int *)(v33 + v13);
        goto LABEL_89;
      }
      if ( v76 < 0 )
      {
        v27 = v30 - 8;
        v82 = v30 - 8;
        v83 = v30 - 8;
        if ( (v67 & 1) == 0 )
        {
          v28 = v29 - 1;
          v67 = v29 - 1;
          goto LABEL_74;
        }
        v67 = v29;
      }
      else
      {
        v26 = (int *)(v30 + 8);
        v78 = (int *)(v30 + 8);
        v67 = v29;
        v27 = v82;
      }
      v28 = v29;
LABEL_74:
      v16 = v69;
      v15 = v60;
    }
  }
  v18 = 0;
  v66 = 0;
  if ( (a12 & 0x1000) == 0 )
  {
    v19 = (unsigned int *)(v13 + v24[1]);
    v63 = (unsigned int)v19;
    goto LABEL_58;
  }
  if ( RtlUIntAdd(v13, v24[1], &v59) < 0 )
    return -1073741701;
  v19 = (unsigned int *)v59;
  v63 = v59;
  v24 = v68;
  LOBYTE(v16) = v69;
  v15 = v60;
LABEL_58:
  v61 = v19;
  a1 = *v24;
  v75 = a1;
LABEL_116:
  v14 = v64;
LABEL_117:
  if ( v19 && (v16 & 2) == 0 )
  {
    if ( (a12 & 0x1000) != 0 && ((unsigned int)v19 <= v13 || (unsigned int)(v19 + 4) > (v15 & 0xFFFFFFFC) + v14) )
    {
LABEL_122:
      v63 = 0;
      return -1073741701;
    }
    if ( a13 )
      *a13 = a1;
    v36 = v15 & 0xFFFFFFFC;
    if ( (v15 & 1) == 0 && !v74 )
    {
      v37 = 0;
      goto LABEL_155;
    }
    v38 = *(unsigned __int16 *)(a5 + 24);
    if ( v38 == 267 )
    {
      v39 = *(_DWORD *)(a5 + 136);
    }
    else if ( v38 == 523 )
    {
      v39 = *(_DWORD *)(a5 + 152);
    }
    else
    {
      v39 = 0;
    }
    if ( !v39 )
    {
      v63 = 0;
      return -1073741687;
    }
    if ( (a12 & 0x1000) != 0 )
    {
      if ( RtlUIntAdd(v15 & 0xFFFFFFFC, v39, &v59) < 0 )
        return -1073741701;
      if ( v59 >= v13 )
      {
        v59 -= v13;
        goto LABEL_140;
      }
LABEL_139:
      v59 = -1;
      return -1073741701;
    }
LABEL_140:
    v37 = v39 - v13 + v36;
    v40 = v64;
    v41 = LdrpSectionTableFromVirtualAddress(v15 & 0xFFFFFFFC, v64, a5);
    if ( !v41 )
      goto LABEL_122;
    if ( *v19 <= *(_DWORD *)(v41 + 8) )
    {
      v15 = v60;
LABEL_155:
      v49 = v62;
    }
    else
    {
      v73 = *(_DWORD *)(v41 + 12);
      v42 = LdrpSectionTableFromVirtualAddress(v15 & 0xFFFFFFFC, v40, a5);
      if ( !v42 )
        goto LABEL_122;
      v43 = *(_DWORD *)(v42 + 12);
      v44 = LdrpSectionTableFromVirtualAddress(v15 & 0xFFFFFFFC, v40, a5);
      v45 = v44;
      if ( v44 )
      {
        if ( (a12 & 0x1000) != 0
          && (RtlUIntAdd(v15 & 0xFFFFFFFC, v43 - *(_DWORD *)(v44 + 12), &v59) < 0
           || RtlUIntAdd(v59, *(_DWORD *)(v45 + 20), &v59) < 0) )
        {
          return -1073741701;
        }
        v46 = *(_DWORD *)(v45 + 20) - *(_DWORD *)(v45 + 12) + v43 + v36;
      }
      else
      {
        v46 = 0;
      }
      if ( (a12 & 0x1000) != 0 )
      {
        v47 = *(_DWORD *)(v45 + 12);
        if ( v47 < v73 )
          goto LABEL_139;
        v59 = v47 - v73;
        if ( v47 - v73 < v46 - v62 )
          goto LABEL_139;
        v59 = v47 - v73 - (v46 - v62);
      }
      v48 = *(_DWORD *)(v45 + 12) - v46 - v73;
      v49 = v62;
      v37 += v48 + v62;
      v19 = v61;
      v15 = v60;
    }
    v50 = v19[1];
    if ( (a12 & 0x1000) != 0 )
    {
      v51 = *v19;
      if ( *v19 < v37 )
        goto LABEL_139;
      v52 = v51 - v37;
      v59 = v51 - v37;
      if ( v51 - v37 < v49 - v15 || v52 > v64 || !v50 || v50 > v64 || v50 + v52 > v64 )
        goto LABEL_122;
    }
    else
    {
      v52 = 0;
    }
    if ( a10 )
    {
      if ( (a12 & 0x1000) != 0 )
      {
        if ( RtlUIntAdd(v36, v52, &v59) < 0 )
          return -1073741701;
        if ( v59 < v36 )
          return -1073741701;
        v54 = v64;
        if ( v59 > (v36 & 0xFFFFFFFC) + v64 )
          return -1073741701;
        *a10 = v53 + v36;
        goto LABEL_173;
      }
      *a10 = *v61 - v37 + v36;
    }
    v54 = v64;
LABEL_173:
    if ( a11 )
    {
      if ( (a12 & 0x1000) != 0 )
      {
        if ( a10 )
        {
          v55 = *a10;
          if ( RtlUIntAdd(*a10, v50, &v59) < 0 || v55 + v50 > (v60 & 0xFFFFFFFC) + v54 )
            return -1073741701;
        }
      }
      *a11 = v50;
    }
    return 0;
  }
  if ( v18 && (v16 & 2) != 0 )
  {
    if ( (a12 & 0x1000) != 0 )
    {
      if ( RtlUIntAdd(v18, 24, &v59) < 0 || (v15 = v60, v18 + 24 > (v60 & 0xFFFFFFFC) + v14) )
      {
        v66 = 0;
        return -1073741701;
      }
    }
    if ( a10 )
    {
      if ( (a12 & 0x1000) != 0 && (v18 < (v15 & 0xFFFFFFFC) || v18 > (v15 & 0xFFFFFFFC) + v14) )
        return -1073741701;
      *a10 = v18;
    }
    return 0;
  }
LABEL_191:
  v56 = a8 - v65;
  if ( a8 - v65 == 1 )
    return -1073741686;
  if ( v56 == 2 )
    return -1073741685;
  if ( v56 != 3 )
    return -1073741811;
  return -1073741308;
}
