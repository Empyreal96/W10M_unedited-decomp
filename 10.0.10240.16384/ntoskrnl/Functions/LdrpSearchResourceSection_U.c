// LdrpSearchResourceSection_U 
 
int __fastcall LdrpSearchResourceSection_U(int a1, int a2, unsigned int a3, int a4, int **a5)
{
  int v5; // r8
  int v6; // r9
  int *v7; // r6
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r10
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // lr
  int v17; // r0
  int v18; // r3
  int v19; // r4
  int v20; // r3
  int v21; // r2
  bool v22; // zf
  int v23; // r3
  int v24; // lr
  int v25; // r0
  int *v26; // r4
  int v27; // r4
  int v28; // r3
  int v29; // r6
  int v30; // r3
  unsigned int v31; // r2
  int *v32; // r4
  unsigned int v33; // r3
  unsigned int v34; // r5
  char v35; // r9
  int v36; // r8
  int v37; // r0
  int v38; // r3
  int v39; // r5
  unsigned __int16 v40; // [sp+8h] [bp-B0h] BYREF
  int v41; // [sp+Ch] [bp-ACh]
  int v42; // [sp+10h] [bp-A8h]
  int v43; // [sp+14h] [bp-A4h] BYREF
  __int16 v44; // [sp+18h] [bp-A0h]
  int v45; // [sp+1Ch] [bp-9Ch]
  int v46; // [sp+20h] [bp-98h]
  int **v47; // [sp+24h] [bp-94h]
  int v48; // [sp+28h] [bp-90h]
  int v49; // [sp+2Ch] [bp-8Ch]
  int v50; // [sp+30h] [bp-88h]
  int *v51; // [sp+34h] [bp-84h]
  int v52; // [sp+38h] [bp-80h]
  unsigned int v53; // [sp+3Ch] [bp-7Ch]
  int v54; // [sp+40h] [bp-78h]
  int *v55; // [sp+44h] [bp-74h]
  int v56; // [sp+48h] [bp-70h]
  int v57; // [sp+4Ch] [bp-6Ch]
  int v58; // [sp+50h] [bp-68h] BYREF
  int v59; // [sp+54h] [bp-64h]
  int v60; // [sp+58h] [bp-60h]
  int v61; // [sp+5Ch] [bp-5Ch]
  __int16 v62; // [sp+60h] [bp-58h]
  bool v63; // [sp+62h] [bp-56h]
  char v64; // [sp+63h] [bp-55h]
  int *v65; // [sp+64h] [bp-54h]
  int v66; // [sp+68h] [bp-50h]
  int v67; // [sp+6Ch] [bp-4Ch]
  unsigned int v68; // [sp+70h] [bp-48h]
  int *v69; // [sp+74h] [bp-44h]
  int v70; // [sp+78h] [bp-40h]
  int v71; // [sp+7Ch] [bp-3Ch]
  int v72; // [sp+80h] [bp-38h]
  int v73; // [sp+84h] [bp-34h]
  _DWORD v74[2]; // [sp+88h] [bp-30h] BYREF
  int v75; // [sp+90h] [bp-28h]
  int v76; // [sp+94h] [bp-24h]
  int varg_r0; // [sp+C0h] [bp+8h]
  int varg_r1; // [sp+C4h] [bp+Ch]
  unsigned int varg_r2; // [sp+C8h] [bp+10h]
  int varg_r3; // [sp+CCh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a4;
  v56 = a4;
  v6 = a3;
  v70 = a3;
  v7 = (int *)a2;
  v48 = a1;
  v47 = a5;
  v72 = a2;
  v60 = 0;
  v66 = 1;
  if ( a3 < 3 && (a4 & 2) == 0 || a3 > 4 )
    return -1073741583;
  v9 = a4 & 0x41;
  if ( (v5 & 0x41) != 0 )
  {
    if ( a3 != 4 )
      return -1073741583;
  }
  else if ( a3 != 4 )
  {
    v10 = a3;
    goto LABEL_12;
  }
  if ( !v9 )
    return -1073741583;
  v10 = 3;
LABEL_12:
  v53 = v10;
  v61 = v10;
  v46 = 0;
  v11 = 0;
  v40 = 0;
  if ( !a2 || a2 == -1 || !a1 || a1 == -1 || !a5 || a5 == (int **)-1 )
  {
    result = -1073741811;
    v41 = -1073741811;
    return result;
  }
  v12 = RtlImageDirectoryEntryToData(a1, 1, 2, (int)&v58);
  v52 = v12;
  if ( !v12 )
  {
    result = -1073741687;
    v41 = -1073741687;
    return result;
  }
  v50 = v12;
  v49 = v12;
  v13 = 61166;
  v57 = 61166;
  v43 = 61166;
  v45 = 0;
  v67 = 0;
  v51 = 0;
  v55 = 0;
  v54 = 0;
  v71 = 0;
  if ( (~v5 & 0x10) != 0 )
  {
    v14 = v53;
    if ( v53 - 1 <= 2 && PnPBootDriversInitialized == 1 )
    {
      if ( v53 == 3 )
        v15 = *((unsigned __int16 *)v7 + 4);
      else
        v15 = 0;
      v16 = v15;
      v46 = v15;
      v62 = v15;
      v17 = *v7;
      if ( *v7 != 16 && v17 != 24 )
      {
        v15 = v17 & 0xFFFF0000;
        if ( (v17 & 0xFFFF0000) == 0 || wcsicmp(v17, L"MUI") )
        {
LABEL_37:
          v5 |= LdrIsResItemExist(v48, v7, v14, v15);
          v56 = v5;
          varg_r3 = v5;
          v13 = v43;
          v57 = v43;
          v12 = v50;
          v16 = v46;
          goto LABEL_39;
        }
        v13 = v43;
        v57 = v43;
        v16 = v46;
      }
      if ( (~(_BYTE)v5 & 8) != 0 && (!v16 || v16 == 1024 || v16 == 2048) )
      {
        v5 |= 0x10u;
        v56 = v5;
        varg_r3 = v5;
        v12 = v50;
        goto LABEL_39;
      }
      goto LABEL_37;
    }
  }
  v16 = 0;
LABEL_39:
  v19 = 0;
  if ( PnPBootDriversInitialized == 1 )
  {
    v18 = ~v5;
    if ( (~v5 & 0x80000) != 0 && (v18 & 0x20000) != 0 && (v18 & 0x10) != 0 )
      v19 = 1;
  }
  v59 = v19;
  if ( v19 )
  {
    v74[0] = *v7;
    v20 = v53 < 2 ? 0 : v7[1];
    v74[1] = v20;
    if ( v6 == 4 )
      v76 = v7[3];
  }
  v21 = (unsigned __int16)PsMachineUILanguageId;
  v41 = (unsigned __int16)PsMachineUILanguageId;
  while ( v12 )
  {
    v22 = v61 == 0;
    v23 = v61 - 1;
    v61 = v23;
    v73 = v23;
    if ( v22 )
      break;
    if ( v23 || v53 != 3 )
    {
      v24 = v54;
    }
    else
    {
      v24 = v12;
      v54 = v12;
      v71 = v12;
    }
    if ( !v24 )
      goto LABEL_136;
    v16 = (unsigned __int16)*(_DWORD *)(v72 + 8);
    v46 = v16;
    v62 = v16;
    v25 = (v16 & 0x3FF) == 0;
    v60 = v25;
    v63 = (v16 & 0x3FF) == 0;
LABEL_75:
    v29 = v45;
    while ( 1 )
    {
      v30 = v29++;
      v45 = v29;
      v67 = v29;
      if ( !v30 )
      {
        if ( v19 && v16 )
        {
          v75 = v16;
          result = LdrpLoadResourceFromAlternativeModule(v48, (int)v74, v6, v5, v47);
          v42 = result;
          if ( result >= 0 )
          {
            v41 = result;
            return result;
          }
          v13 = v43;
          v21 = (unsigned __int16)PsMachineUILanguageId;
          v41 = (unsigned __int16)PsMachineUILanguageId;
          v16 = v46;
        }
        v11 = v16;
        v40 = v16;
        goto LABEL_132;
      }
      if ( v30 != 1 )
      {
        switch ( v30 )
        {
          case 2:
            if ( !v25 )
              goto LABEL_167;
            if ( v19 )
            {
              if ( !v21 )
                goto LABEL_130;
              v75 = v21;
              result = LdrpLoadResourceFromAlternativeModule(v48, (int)v74, v6, v5, v47);
              v42 = result;
              if ( result >= 0 )
              {
                v41 = result;
                return result;
              }
              v21 = (unsigned __int16)PsMachineUILanguageId;
              v41 = (unsigned __int16)PsMachineUILanguageId;
              v11 = (unsigned __int16)PsMachineUILanguageId;
              v40 = PsMachineUILanguageId;
              v13 = v43;
            }
            else
            {
              if ( !v21 )
              {
LABEL_130:
                v11 = (unsigned __int16)v13;
                v40 = v13;
                goto LABEL_132;
              }
              v11 = v21;
              v40 = v21;
            }
            goto LABEL_132;
          case 3:
            if ( (unsigned __int16)PsInstallUILanguageId == v21 )
              break;
            if ( v19 )
            {
              v75 = (unsigned __int16)PsInstallUILanguageId;
              result = LdrpLoadResourceFromAlternativeModule(v48, (int)v74, v6, v5, v47);
              v42 = result;
              if ( result >= 0 )
              {
                v41 = result;
                return result;
              }
              v13 = v43;
              v21 = (unsigned __int16)PsMachineUILanguageId;
              v41 = (unsigned __int16)PsMachineUILanguageId;
            }
            v11 = (unsigned __int16)PsInstallUILanguageId;
LABEL_100:
            v40 = v11;
LABEL_131:
            v29 = v45;
            goto LABEL_132;
          case 4:
            v11 = (unsigned __int16)PsDefaultSystemLocaleId;
            v40 = PsDefaultSystemLocaleId;
            if ( (unsigned __int16)PsDefaultSystemLocaleId != (unsigned __int16)PsInstallUILanguageId
              && (unsigned __int16)PsDefaultSystemLocaleId != v21 )
            {
              if ( !v19 )
                goto LABEL_131;
              v75 = (unsigned __int16)PsDefaultSystemLocaleId;
              result = LdrpLoadResourceFromAlternativeModule(v48, (int)v74, v6, v5, v47);
              v42 = result;
              if ( result >= 0 )
              {
                v41 = result;
                return result;
              }
LABEL_119:
              v13 = v43;
              v21 = (unsigned __int16)PsMachineUILanguageId;
              v41 = (unsigned __int16)PsMachineUILanguageId;
              goto LABEL_131;
            }
            break;
          case 5:
            v11 = 1033;
            v40 = 1033;
            if ( PsDefaultSystemLocaleId != 1033 && PsInstallUILanguageId != 1033 && v21 != 1033 )
            {
              if ( !v19 )
                goto LABEL_131;
              v75 = 1033;
              result = LdrpLoadResourceFromAlternativeModule(v48, (int)v74, v6, v5, v47);
              v42 = result;
              if ( result >= 0 )
              {
                v41 = result;
                return result;
              }
              goto LABEL_119;
            }
            break;
          case 6:
            v5 |= 0x20u;
            v56 = v5;
            varg_r3 = v5;
            goto LABEL_132;
          default:
            goto LABEL_167;
        }
        v11 = (unsigned __int16)v13;
        goto LABEL_100;
      }
      if ( v11 )
      {
        if ( LdrpGetParentLangId(v11, &v40) >= 0 )
        {
          v11 = v40;
        }
        else
        {
          v11 = 0;
          v40 = 0;
        }
        v21 = (unsigned __int16)PsMachineUILanguageId;
        v41 = (unsigned __int16)PsMachineUILanguageId;
        v13 = v43;
      }
      if ( v19 )
      {
        if ( !v11 )
          goto LABEL_132;
        v75 = v11;
        result = LdrpLoadResourceFromAlternativeModule(v48, (int)v74, v6, v5, v47);
        v42 = result;
        if ( result >= 0 )
        {
          v41 = result;
          return result;
        }
        v13 = v43;
        v21 = (unsigned __int16)PsMachineUILanguageId;
        v41 = (unsigned __int16)PsMachineUILanguageId;
      }
      if ( v11 )
      {
        v45 = --v29;
        v67 = v29;
      }
LABEL_132:
      if ( (~v5 & 0x20) == 0 || v11 != v13 )
        break;
      v19 = v59;
      v16 = v46;
      v25 = v60;
    }
    v13 = v11;
    v57 = v11;
    v43 = v11;
    v7 = &v43;
    v69 = &v43;
    v24 = v54;
    v12 = v54;
    v49 = v54;
LABEL_136:
    v31 = *(unsigned __int16 *)(v12 + 12);
    v44 = *(_WORD *)(v12 + 12);
    v32 = (int *)(v12 + 16);
    v65 = (int *)(v12 + 16);
    if ( (*v7 & 0xFFFF0000) == 0 )
    {
      v32 += 2 * v31;
      v65 = v32;
      v31 = *(unsigned __int16 *)(v12 + 14);
      v44 = *(_WORD *)(v12 + 14);
    }
    if ( !v31 )
    {
      v49 = 0;
      v66 = 0;
      v64 = 0;
      v21 = v41;
      v16 = v46;
      goto LABEL_68;
    }
    if ( v24 && (v5 & 0x20) != 0 )
    {
      v12 = 0;
      v49 = 0;
      v13 = *v32;
      v43 = *v32;
      v26 = (int *)(v52 + v32[1]);
      v55 = v26;
      v21 = v41;
      v16 = v46;
      goto LABEL_61;
    }
    v12 = 0;
    v50 = 0;
    v49 = 0;
    v33 = (unsigned int)&v32[2 * v31 - 2];
    v58 = v33;
    v68 = v33;
    while ( 2 )
    {
      if ( (unsigned int)v32 > v33 )
        goto LABEL_166;
      v34 = v31 >> 1;
      if ( v31 >> 1 )
      {
        v35 = v44;
        if ( (v44 & 1) != 0 )
          v36 = (int)&v32[2 * v34];
        else
          v36 = (int)&v32[2 * v34 - 2];
        v37 = LdrpCompareResourceNames_U(*v7, v52, v36);
        if ( !v37 )
        {
          v38 = *(_DWORD *)(v36 + 4);
          if ( v38 >= 0 )
          {
            v12 = 0;
            v49 = 0;
            v51 = (int *)(v38 + v52);
            v55 = (int *)(v38 + v52);
            goto LABEL_166;
          }
          v39 = v52;
          goto LABEL_163;
        }
        if ( v37 >= 0 )
        {
          v32 = (int *)(v36 + 8);
          v65 = (int *)(v36 + 8);
          v44 = v34;
          v33 = v58;
          goto LABEL_158;
        }
        v33 = v36 - 8;
        v58 = v36 - 8;
        v68 = v36 - 8;
        if ( (v35 & 1) != 0 )
        {
          v44 = v34;
LABEL_158:
          v31 = v34;
        }
        else
        {
          v31 = (unsigned __int16)(v34 - 1);
          v44 = v34 - 1;
          v33 = v58;
        }
        v12 = v50;
        continue;
      }
      break;
    }
    if ( !v31 )
      goto LABEL_166;
    v39 = v52;
    if ( !LdrpCompareResourceNames_U(*v7, v52, v32) )
    {
      v38 = v32[1];
      if ( v38 < 0 )
      {
LABEL_163:
        v12 = (v38 & 0x7FFFFFFF) + v39;
        v49 = v12;
        goto LABEL_166;
      }
      v51 = (int *)(v38 + v39);
      v55 = (int *)(v38 + v39);
    }
    v12 = v50;
LABEL_166:
    v69 = ++v7;
    v21 = v41;
    v5 = v56;
    v13 = v57;
    v6 = v70;
    v19 = v59;
    v16 = v46;
  }
  v26 = v51;
LABEL_61:
  if ( v26 && (v5 & 2) == 0 )
  {
    *v47 = v26;
LABEL_67:
    v27 = 0;
    v42 = 0;
    return v27;
  }
  if ( v12 && (v5 & 2) != 0 )
  {
    *v47 = (int *)v12;
    goto LABEL_67;
  }
LABEL_68:
  v28 = v53 - v61;
  if ( v53 - v61 != 1 )
  {
    if ( v28 == 2 )
    {
      v27 = -1073741685;
      goto LABEL_170;
    }
    if ( v28 != 3 )
    {
      v27 = -1073741811;
      v42 = -1073741811;
      return v27;
    }
    v27 = -1073741308;
    v42 = -1073741308;
    if ( !v54 )
      return v27;
    v51 = 0;
    v55 = 0;
    if ( !v66 )
    {
LABEL_167:
      v27 = -1073741308;
      v42 = -1073741308;
      return v27;
    }
    v19 = v59;
    v25 = v60;
    goto LABEL_75;
  }
  v27 = -1073741686;
LABEL_170:
  v42 = v27;
  return v27;
}
