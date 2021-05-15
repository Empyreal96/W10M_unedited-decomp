// LdrpResSearchResourceMappedFile 
 
int __fastcall LdrpResSearchResourceMappedFile(int a1, int a2, int a3, _DWORD *a4, int a5, _DWORD *a6, int *a7, int a8, int a9)
{
  int v10; // r6
  int v11; // r4
  int v12; // lr
  BOOL v13; // r1
  int v14; // r9
  int v15; // r8
  int v16; // r2
  BOOL v17; // r3
  int v18; // r2
  int v19; // r0
  int v20; // r4
  int v21; // r2
  unsigned int v22; // r8
  unsigned int v23; // r2
  int v24; // lr
  int v25; // r8
  _WORD *v26; // r3
  int v27; // r5
  int v28; // r3
  unsigned int i; // r2
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r5
  char *v34; // r4
  int v35; // r1
  int *v36; // r0
  int v37; // r3
  int v38; // r0
  _DWORD *v39; // r8
  int v40; // r2
  int v41; // r0
  unsigned int *v42; // r6
  unsigned int v43; // r5
  int v44; // r8
  int v46; // [sp+4h] [bp-374h]
  char v47[6]; // [sp+2Ah] [bp-34Eh] BYREF
  int v48; // [sp+30h] [bp-348h] BYREF
  int v49; // [sp+34h] [bp-344h] BYREF
  int v50; // [sp+38h] [bp-340h]
  bool v51; // [sp+3Ch] [bp-33Ch]
  int v52; // [sp+40h] [bp-338h]
  int v53; // [sp+44h] [bp-334h] BYREF
  unsigned int v54; // [sp+48h] [bp-330h]
  int v55; // [sp+4Ch] [bp-32Ch]
  int v56; // [sp+50h] [bp-328h]
  _DWORD *v57; // [sp+54h] [bp-324h]
  unsigned int v58; // [sp+58h] [bp-320h]
  int v59; // [sp+5Ch] [bp-31Ch]
  int v60; // [sp+60h] [bp-318h]
  int v61; // [sp+64h] [bp-314h] BYREF
  int v62; // [sp+68h] [bp-310h] BYREF
  int v63; // [sp+6Ch] [bp-30Ch]
  _DWORD *v64; // [sp+70h] [bp-308h]
  int v65; // [sp+74h] [bp-304h]
  int *v66; // [sp+78h] [bp-300h]
  int v67; // [sp+7Ch] [bp-2FCh]
  int v68; // [sp+80h] [bp-2F8h]
  BOOL v69; // [sp+84h] [bp-2F4h]
  int v70; // [sp+88h] [bp-2F0h]
  unsigned int *v71; // [sp+8Ch] [bp-2ECh]
  _DWORD *v72; // [sp+90h] [bp-2E8h]
  _DWORD *v73; // [sp+94h] [bp-2E4h]
  int *v74; // [sp+98h] [bp-2E0h]
  int v75; // [sp+9Ch] [bp-2DCh]
  _WORD v76[260]; // [sp+A0h] [bp-2D8h] BYREF
  unsigned __int16 _2A8[106]; // [sp+2A8h] [bp-D0h] BYREF
  int varg_r0; // [sp+380h] [bp+8h]
  int varg_r1; // [sp+384h] [bp+Ch]
  int varg_r2; // [sp+388h] [bp+10h]
  _DWORD *varg_r3; // [sp+38Ch] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v57 = a4;
  v10 = a3;
  varg_r2 = a3;
  v11 = a2;
  v59 = a2;
  varg_r1 = a2;
  v12 = a1;
  v52 = a1;
  v58 = a1;
  v72 = a4;
  v64 = a6;
  v73 = a6;
  v66 = a7;
  v74 = a7;
  v67 = a8;
  v75 = a8;
  v71 = (unsigned int *)a9;
  v70 = a9;
  *(_DWORD *)&v47[2] = 0;
  v65 = 0;
  v49 = 0;
  v60 = 0;
  v62 = 0;
  v63 = 0;
  v53 = 0;
  v56 = 0;
  v61 = 0;
  v13 = 0;
  v69 = (a3 & 0x40) != 0;
  v51 = (a3 & 0x40) != 0;
  v55 = 0;
  v47[0] = 0;
  v14 = 0;
  v54 = 0;
  v15 = 0;
  if ( (a3 & 0x80) != 0 )
  {
    v14 = 128;
    v54 = 128;
  }
  v16 = a5;
  if ( a5 == 3 )
  {
    v15 = (unsigned __int16)a4[2];
    LOWORD(v50) = a4[2];
    v17 = (*a4 & 0xFFFF0000) != 0 && !wcsicmp();
    v13 = v17;
    v16 = 3;
    v12 = v52;
    v11 = v59;
  }
  if ( (v10 & 0x10) == 0 && (unsigned int)(v16 - 1) <= 2 )
  {
    if ( v16 == 3 )
      v18 = *((unsigned __int16 *)a4 + 4);
    else
      v18 = 0;
    if ( (*a4 == 16 || *a4 == 24 || v13) && (~v10 & 8) != 0 && (!v18 || v18 == 1024 || v18 == 2048) )
    {
      v10 |= 0x10u;
    }
    else
    {
      v19 = LdrResGetRCConfig(v12, v11, 0, v10, 1);
      v20 = v19;
      if ( v19 < 0 )
      {
        if ( v19 != -1073741686 )
          return v20;
        v14 |= 0x80000u;
      }
      else
      {
        v14 |= LdrIsResItemExist(v52, a4);
      }
    }
  }
  if ( (v14 & 0x60000) == 393216 )
    return -1073741686;
  v21 = 0;
  if ( (~v10 & 0x10) != 0 && (~v14 & 0x80000) != 0 && (~v14 & 0x20000) != 0 )
    v21 = 1;
  v54 = 1;
  v76[0] = 1;
  v76[2] = 0;
  if ( !v21 && a5 != 3 || (v10 & 0x10) != 0 && (v10 & 0x20) != 0 )
  {
    v22 = 1;
  }
  else
  {
    if ( (v10 & 4) != 0 )
      v14 |= 4u;
    v20 = LdrResFallbackLangList(16, 1, v15, v14, v76);
    if ( v20 >= 0 )
    {
      v22 = v76[0];
      v54 = v76[0];
    }
    else
    {
      if ( (v10 & 0x1000) != 0 )
        return v20;
      v22 = v76[0];
      v54 = v76[0];
    }
  }
  if ( (v10 & 0x10) != 0 || (v14 & 0x80000) != 0 || (~v14 & 0x40000) != 0 )
  {
    v20 = LdrpResGetResourceDirectory(v52, v59, v10, &v49, &v53);
    if ( v20 < 0 )
      return v20;
    v65 = v49;
    v63 = v53;
  }
  v20 = 0;
  v23 = 0;
LABEL_49:
  v58 = v23;
  if ( v23 < v22 )
  {
    v24 = 0;
    *(_DWORD *)&v47[2] = 0;
    v25 = 0;
    v48 = 0;
    v26 = &v76[4 * v23];
    v27 = (unsigned __int16)v26[2];
    *(_DWORD *)v47 = v27;
    v28 = *((_DWORD *)v26 + 2);
    v50 = v28;
    for ( i = 0; ; ++i )
    {
      v49 = i;
      if ( i >= 2 )
      {
LABEL_116:
        v23 = v58 + 1;
        v22 = v54;
        goto LABEL_49;
      }
      if ( i )
      {
        v55 = 0;
        v32 = v56;
        goto LABEL_71;
      }
      if ( v28 == 9 )
      {
        v10 |= 0x20u;
        continue;
      }
      if ( (v14 & 0xA0000) == 0 && (v10 & 0x10) == 0 && v27 )
        break;
LABEL_115:
      ;
    }
    if ( !PnPBootDriversInitialized )
      goto LABEL_114;
    v55 = 1;
    v30 = LdrLoadAlternateResourceModuleEx(v52, v27, &v47[2], &v48, v14 | 0x1000);
    v20 = v30;
    if ( v30 < 0 )
    {
      if ( v30 == -1073741772 || v30 == -1073741766 )
        v20 = -1073020927;
LABEL_112:
      v24 = *(_DWORD *)&v47[2];
      v25 = v48;
LABEL_113:
      i = v49;
LABEL_114:
      v28 = v50;
      goto LABEL_115;
    }
    v31 = v48;
    if ( !v48 )
    {
      v20 = LdrpResGetMappingSize(*(_DWORD *)&v47[2], &v48, 512);
      v31 = v48;
    }
    if ( (v10 & 0x1000) != 0 && v20 < 0 )
      goto LABEL_116;
    v20 = LdrpResGetResourceDirectory(*(_DWORD *)&v47[2], v31, v10, &v62, &v61);
    v24 = *(_DWORD *)&v47[2];
    v25 = v48;
    v60 = v62;
    if ( v20 < 0 )
    {
      v56 = v61;
      goto LABEL_113;
    }
    v32 = v61;
    v56 = v61;
LABEL_71:
    if ( (~v10 & 2) != 0 && a5 > 2 )
      v57[2] = v27;
    v53 = 0;
    v33 = v55;
    if ( v55 )
      v34 = 0;
    else
      v34 = v47;
    if ( v55 )
    {
      v35 = v10 | 0x20;
    }
    else if ( (v10 & 0x20) != 0 )
    {
      v35 = v10;
    }
    else
    {
      v35 = v10 | 4;
    }
    if ( v66 )
      v36 = v66;
    else
      v36 = &v53;
    if ( v55 )
    {
      v37 = v60;
    }
    else
    {
      v32 = v63;
      v37 = v65;
    }
    if ( !v55 )
    {
      v25 = v59;
      v24 = v52;
    }
    v38 = LdrpResSearchResourceInsideDirectory(v24, v57, v25, v37, v32, v46, v57, a5, v76, v64, v36, v35, v34);
    v20 = v38;
    if ( v69 )
    {
      if ( v38 < 0 )
      {
LABEL_111:
        v27 = *(unsigned __int16 *)v47;
        goto LABEL_112;
      }
      v39 = v64;
      if ( v64 && v33 )
      {
        if ( v66 )
          v40 = *v66;
        else
          v40 = v53;
        v41 = LdrpFindMessageInAlternateModule(*(_DWORD *)&v47[2], *v64, v40, v57[3], 1);
        v20 = v41;
        if ( v41 >= 0 )
        {
LABEL_101:
          v42 = v71;
          if ( !v71 )
            return v20;
          if ( *(_WORD *)v47 )
          {
            if ( !DownLevelLangIDToLanguageName() )
              return -1073741823;
            v43 = wcslen(_2A8);
          }
          else
          {
            _2A8[0] = 0;
            v43 = 0;
          }
          if ( v43 < *v42 && (v44 = v67) != 0 )
          {
            memmove(v67, (int)_2A8, 2 * v43);
            *v42 = v43 + 1;
            *(_WORD *)(v44 + 2 * v43) = 0;
          }
          else
          {
            *v42 = v43 + 1;
            v20 = -1073741789;
            v68 = -1073741789;
          }
          return v20;
        }
        *v39 = 0;
        if ( v41 == -1073741701 )
          return v20;
      }
    }
    if ( v20 >= 0 )
      goto LABEL_101;
    goto LABEL_111;
  }
  return v20;
}
