// PiDevCfgResolveVariableKeyHandle 
 
int __fastcall PiDevCfgResolveVariableKeyHandle(unsigned int **a1, int a2, int *a3)
{
  int v5; // r4
  _WORD *v6; // r5
  unsigned int v7; // r3
  int v10; // r6
  int v11; // r4
  int *v12; // r8
  int v13; // t1
  const __int16 *v14; // r3
  __int16 **v15; // r7
  int v16; // r2
  unsigned int *v17; // r1
  int v18; // r1
  int v19; // r0
  __int16 *v20; // r3
  unsigned __int16 *v21; // r6
  int v22; // r1
  int v23; // r0
  unsigned int v24; // r3
  unsigned __int16 *v27; // r6
  _WORD *v28; // r0
  unsigned int v29; // r8
  unsigned int **v30; // r0
  unsigned int **v31; // r9
  unsigned __int16 *v32; // r7
  unsigned int v33; // r10
  _WORD *v34; // r0
  _WORD *v35; // r6
  int v36; // r8
  int v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r3
  int v40; // r1
  unsigned int v41; // r3
  unsigned __int16 *v42; // r6
  unsigned int v43; // r0
  int v44; // r0
  const __int16 *v45; // r2
  int v46; // r3
  unsigned int v47; // r1
  _WORD *v48; // r9
  unsigned __int16 *v49; // r7
  _WORD *v50; // r0
  _WORD *v51; // r6
  unsigned int v52; // r8
  unsigned __int16 *v53; // r10
  unsigned int v54; // r3
  unsigned int *v55; // r3
  unsigned int v56; // r2
  unsigned int v57; // r1
  unsigned __int16 *v58; // r6
  unsigned int v59; // r0
  int v60; // r3
  int v62; // [sp+10h] [bp-E0h] BYREF
  unsigned int v63; // [sp+14h] [bp-DCh]
  _WORD *v64[2]; // [sp+18h] [bp-D8h] BYREF
  int v65; // [sp+20h] [bp-D0h] BYREF
  const __int16 *v66; // [sp+24h] [bp-CCh]
  unsigned int **v67; // [sp+28h] [bp-C8h] BYREF
  int v68; // [sp+2Ch] [bp-C4h]
  unsigned int v69; // [sp+30h] [bp-C0h]
  int v70; // [sp+38h] [bp-B8h]
  int v71; // [sp+3Ch] [bp-B4h]
  int *v72; // [sp+40h] [bp-B0h]
  int v73; // [sp+44h] [bp-ACh]
  int v74; // [sp+48h] [bp-A8h]
  int v75; // [sp+4Ch] [bp-A4h]
  int v76; // [sp+50h] [bp-A0h]
  const __int16 *v77; // [sp+54h] [bp-9Ch]
  unsigned int v78; // [sp+58h] [bp-98h]
  int v79; // [sp+5Ch] [bp-94h]
  unsigned int **v80; // [sp+60h] [bp-90h]
  int v81; // [sp+68h] [bp-88h] BYREF
  int v82; // [sp+6Ch] [bp-84h]
  int *v83; // [sp+70h] [bp-80h]
  int v84; // [sp+74h] [bp-7Ch] BYREF
  int v85; // [sp+78h] [bp-78h] BYREF
  char v86[76]; // [sp+80h] [bp-70h] BYREF
  __int16 v87; // [sp+CCh] [bp-24h]

  v63 = 0;
  v64[0] = 0;
  v62 = 0;
  v79 = 0;
  v80 = 0;
  v76 = 0;
  v81 = 0;
  v82 = 0;
  v83 = a3;
  *a3 = 0;
  v67 = a1;
  v5 = IopGetRegistryValue(a2, L"KeyRoot", 0, (int *)v64);
  v6 = v64[0];
  if ( v5 < 0 )
    goto LABEL_117;
  if ( *((_DWORD *)v64[0] + 1) != 1 )
    goto LABEL_11;
  v7 = *((_DWORD *)v64[0] + 3);
  if ( v7 < 2 || *(_WORD *)((char *)&v64[0][(v7 >> 1) - 1] + *((_DWORD *)v64[0] + 2)) )
    goto LABEL_11;
  v10 = *((_DWORD *)v64[0] + 2);
  v11 = 0;
  v12 = (int *)&off_8C6DC8;
  while ( 1 )
  {
    v13 = *v12;
    v12 += 5;
    if ( !wcsicmp(v13, (_WORD *)((char *)v6 + v10)) )
      break;
    if ( (unsigned int)++v11 >= 7 )
      goto LABEL_15;
  }
  v15 = &(&off_8C6DC8)[5 * v11];
  if ( !v15 )
  {
LABEL_15:
    if ( wcsicmp((int)v6 + v10, L"SYSTEM") )
    {
      if ( wcsicmp((int)v6 + v10, L"SOFTWARE") )
      {
        if ( wcsicmp((int)v6 + v10, L"HARDWARE") )
        {
          v5 = -1073741772;
          goto LABEL_117;
        }
        v65 = 3538996;
        v66 = L"\\Registry\\Machine\\HARDWARE";
        v62 = 0;
        v70 = 24;
        v71 = 0;
        v73 = 576;
        v72 = &v65;
        v74 = 0;
        v75 = 0;
        v68 = 131097;
        goto LABEL_36;
      }
      v65 = 3538996;
      v14 = L"\\Registry\\Machine\\SOFTWARE";
    }
    else
    {
      v65 = 3276848;
      v14 = L"\\Registry\\Machine\\SYSTEM";
    }
    v66 = v14;
    v62 = 0;
    v70 = 24;
    v71 = 0;
    v73 = 576;
    v72 = &v65;
    v74 = 0;
    v75 = 0;
    v68 = 131097;
LABEL_36:
    v19 = ZwOpenKey();
    goto LABEL_37;
  }
  v16 = (int)v15[3];
  v17 = *a1;
  if ( !v16 )
  {
    v20 = v15[2];
    if ( !v20 )
    {
      v5 = -1073741595;
      goto LABEL_117;
    }
    if ( v20 == (__int16 *)7 )
    {
      v85 = 78;
      v5 = CmGetDeviceRegProp(PiPnpRtlCtx, v17[6], 0, 9, (int)&v84, (int)v86, (int)&v85);
      if ( v5 < 0 )
        goto LABEL_117;
      if ( v84 != 1 )
        goto LABEL_11;
      v87 = 0;
      v21 = (unsigned __int16 *)v86;
    }
    else
    {
      v21 = (unsigned __int16 *)v15[4];
    }
    v22 = (int)v15[2];
    v68 = 131097;
    v5 = PnpCtxOpenContextBaseKey((int *)PiPnpRtlCtx, v22, v16, 131097);
    if ( v5 < 0 )
      goto LABEL_117;
    if ( v21 )
    {
      RtlInitUnicodeString((unsigned int)&v65, v21);
      v79 = 0;
      v70 = 24;
      v71 = v62;
      v73 = 576;
      v72 = &v65;
      v74 = 0;
      v75 = 0;
      v5 = ZwOpenKey();
      if ( v5 < 0 )
        goto LABEL_117;
      ZwClose();
      v62 = v79;
    }
    goto LABEL_38;
  }
  v18 = v17[6];
  v68 = 131097;
  v19 = CmOpenDeviceRegKey(PiPnpRtlCtx, v18, v16, 0, 131097, 0, (int)&v62, 0);
LABEL_37:
  v5 = v19;
  if ( v19 < 0 )
    goto LABEL_117;
LABEL_38:
  ExFreePoolWithTag((unsigned int)v6);
  v64[0] = 0;
  v23 = IopGetRegistryValue(a2, L"KeyPath", 0, (int *)v64);
  v5 = v23;
  v6 = v64[0];
  if ( v23 < 0 )
  {
    if ( v23 != -1073741772 )
      goto LABEL_117;
    v60 = v62;
    v62 = 0;
    v76 = v60;
    v5 = 0;
    goto LABEL_115;
  }
  if ( *((_DWORD *)v64[0] + 1) != 1 )
    goto LABEL_11;
  v24 = *((_DWORD *)v64[0] + 3);
  if ( v24 < 2 || *(_WORD *)((char *)&v64[0][(v24 >> 1) - 1] + *((_DWORD *)v64[0] + 2)) )
    goto LABEL_11;
  v64[0] = (_WORD *)((char *)v64[0] + *((_DWORD *)v64[0] + 2));
  v27 = v64[0];
  v28 = wcschr(v64[0], 36);
  if ( !v28 )
    goto LABEL_110;
  v29 = 0;
  do
  {
    ++v29;
    v28 = wcschr(v28 + 1, 36);
  }
  while ( v28 );
  v69 = v29;
  if ( !v29 )
  {
LABEL_110:
    PnpRegSzToString((char *)v6 + *((_DWORD *)v6 + 2), *((_DWORD *)v6 + 3), &v67);
    LOWORD(v65) = (_WORD)v67;
    HIWORD(v65) = *((_DWORD *)v6 + 3);
    v66 = (_WORD *)((char *)v6 + *((_DWORD *)v6 + 2));
    goto LABEL_111;
  }
  v30 = (unsigned int **)ExAllocatePoolWithTag(1, 4 * v29, 1667526736);
  v31 = v30;
  v80 = v30;
  if ( !v30 )
  {
LABEL_53:
    v5 = -1073741670;
    goto LABEL_117;
  }
  memset(v30, 0, 4 * v29);
  v32 = v27;
  v33 = 0;
  if ( *v27 )
  {
    while ( v33 < v29 )
    {
      v34 = wcschr(v32, 92);
      v35 = v34;
      if ( v34 )
      {
        *v34 = 0;
        v36 = 2 * (v34 - v32);
      }
      else
      {
        v36 = 2 * wcslen(v32);
      }
      if ( *v32 == 36 )
      {
        v37 = PiDevCfgResolveVariable((int)v67, v32 + 1, v31);
        v5 = v37;
        if ( v37 < 0 )
        {
          if ( v37 != -1073741772 )
          {
            v40 = v63;
            goto LABEL_74;
          }
          v5 = 0;
        }
        else
        {
          v38 = *v31;
          v39 = (*v31)[4];
          if ( v39 )
          {
            if ( v39 <= 2 )
            {
              v36 = v38[5] - 2;
            }
            else if ( v39 == 7 )
            {
              v36 = 2 * wcslen((unsigned __int16 *)v38[6]);
            }
          }
        }
        ++v33;
        ++v31;
      }
      v40 = v63;
      v41 = v63 + v36 + 2;
      if ( v41 >= 0xFFFE )
      {
        v5 = -2147483643;
LABEL_74:
        v27 = v64[0];
        v29 = v69;
        goto LABEL_79;
      }
      v40 = (unsigned __int16)v41;
      v63 = (unsigned __int16)v41;
      HIWORD(v81) = v41;
      if ( v35 )
      {
        *v35 = 92;
        v42 = v35 + 1;
      }
      else
      {
        v43 = wcslen(v32);
        v40 = v63;
        v42 = &v32[v43];
      }
      v29 = v69;
      v32 = v42;
      if ( !*v42 )
        goto LABEL_74;
    }
    v40 = v63;
    v27 = v64[0];
  }
  else
  {
    v40 = 0;
  }
LABEL_79:
  if ( v5 >= 0 )
  {
    LOWORD(v81) = v40 - 2;
    v44 = ExAllocatePoolWithTag(1, v40, 1667526736);
    v45 = (const __int16 *)v44;
    v77 = (const __int16 *)v44;
    v82 = v44;
    if ( !v44 )
      goto LABEL_53;
    v46 = *v27;
    v47 = 0;
    v48 = (_WORD *)v44;
    v49 = v27;
    v78 = 0;
    if ( v46 )
    {
      v67 = v80;
      while ( v47 < v29 )
      {
        v50 = wcschr(v49, 92);
        v51 = v50;
        if ( v50 )
        {
          *v50 = 0;
          v52 = 2 * (v50 - v49);
        }
        else
        {
          v52 = 2 * wcslen(v49);
        }
        v53 = v49;
        if ( v49 != v64[0] )
        {
          if ( v63 <= 2 )
            goto LABEL_11;
          v54 = v63 - 2;
          *v48++ = 92;
          v63 = v54;
        }
        if ( *v49 == 36 )
        {
          v55 = *v67;
          ++v78;
          ++v67;
          if ( v55 )
          {
            v56 = v55[4];
            if ( v56 )
            {
              if ( v56 <= 2 )
              {
                v53 = (unsigned __int16 *)v55[6];
                v52 = v55[5] - 2;
              }
              else if ( v56 == 7 )
              {
                v53 = (unsigned __int16 *)v55[6];
                v52 = 2 * wcslen(v53);
              }
            }
          }
        }
        v57 = v63;
        if ( v63 <= v52 )
        {
          v5 = -1073741823;
LABEL_104:
          v45 = v77;
          goto LABEL_107;
        }
        memmove((int)v48, (int)v53, v52);
        v48 += v52 >> 1;
        v57 = v63 - v52;
        v63 -= v52;
        if ( v51 )
        {
          *v51 = 92;
          v58 = v51 + 1;
        }
        else
        {
          v59 = wcslen(v49);
          v57 = v63;
          v58 = &v49[v59];
        }
        v49 = v58;
        if ( !*v58 )
          goto LABEL_104;
        v47 = v78;
        v29 = v69;
      }
      v45 = v77;
    }
    v57 = v63;
LABEL_107:
    if ( v5 >= 0 )
    {
      if ( v57 == 2 )
      {
        *v48 = 0;
        v65 = v81;
        v66 = v45;
LABEL_111:
        v76 = 0;
        v70 = 24;
        v71 = v62;
        v73 = 576;
        v72 = &v65;
        v74 = 0;
        v75 = 0;
        v5 = ZwOpenKey();
        if ( v5 < 0 )
          goto LABEL_117;
        v60 = v76;
LABEL_115:
        *v83 = v60;
        goto LABEL_117;
      }
LABEL_11:
      v5 = -1073741823;
      goto LABEL_117;
    }
  }
LABEL_117:
  RtlFreeAnsiString(&v81);
  if ( v80 )
    ExFreePoolWithTag((unsigned int)v80);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  if ( v62 )
    ZwClose();
  return v5;
}
