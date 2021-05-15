// PiDevCfgResolveVariableFormatString 
 
int __fastcall PiDevCfgResolveVariableFormatString(int a1, int a2, int a3)
{
  unsigned int v5; // r6
  int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r3
  int v9; // r3
  int v11; // r0
  unsigned int v12; // r9
  int v13; // r5
  unsigned __int16 *v14; // r6
  unsigned int v15; // r8
  unsigned int v16; // r0
  unsigned int **v17; // r0
  __int64 v18; // kr00_8
  _WORD *v19; // r1
  _WORD *v20; // r0
  int v21; // r3
  unsigned int v23; // r7
  unsigned __int16 *v24; // r6
  unsigned int **v25; // r5
  int v26; // r0
  int v27; // r8
  int v28; // r9
  int v29; // r3
  unsigned __int16 *v30; // r5
  int v31; // t1
  unsigned int v32; // r2
  int v33; // r9
  int v34; // r0
  int v35; // r2
  unsigned int v36; // r1
  unsigned int v37; // r3
  int v38; // r2
  unsigned int v39; // r3
  unsigned __int16 *v40; // r0
  _WORD *v41; // r10
  unsigned int v42; // r6
  _WORD *v43; // r7
  __int16 v44; // r3
  int v45; // t1
  unsigned int v46; // r2
  unsigned int i; // r1
  unsigned int v48; // r3
  unsigned int *v49; // r2
  unsigned int v50; // r3
  unsigned __int16 *v51; // r8
  unsigned int v52; // r5
  unsigned int v53; // r0
  int v55; // r3
  unsigned int v56; // [sp+0h] [bp-50h]
  int v57; // [sp+4h] [bp-4Ch]
  int v58; // [sp+4h] [bp-4Ch]
  _DWORD *v59; // [sp+8h] [bp-48h] BYREF
  unsigned int v60; // [sp+Ch] [bp-44h] BYREF
  unsigned int **v61; // [sp+10h] [bp-40h]
  int v62; // [sp+14h] [bp-3Ch]
  unsigned __int16 v63[28]; // [sp+18h] [bp-38h] BYREF

  v59 = 0;
  v60 = 0;
  v56 = 0;
  v62 = a3;
  v5 = 0;
  v61 = 0;
  v6 = IopGetRegistryValue(a2, L"Format", 0, (int *)&v59);
  v7 = (unsigned int)v59;
  if ( v6 < 0 )
    goto LABEL_115;
  if ( v59[1] != 1
    || ((v8 = v59[3], v8 < 2) || *(_WORD *)((char *)v59 + 2 * (v8 >> 1) + v59[2] - 2) ? (v9 = 0) : (v9 = 1), !v9) )
  {
    v6 = -1073741823;
    goto LABEL_115;
  }
  v57 = v59[2];
  v11 = IopGetRegistryValue(a2, L"Variables", 0, (int *)&v60);
  v6 = v11;
  v12 = v60;
  if ( v11 >= 0 )
  {
    if ( *(_DWORD *)(v60 + 4) != 7
      || (((v18 = *(_QWORD *)(v60 + 8), v19 = (_WORD *)(v18 + v60), HIDWORD(v18) < 4)
        || (v20 = &v19[HIDWORD(v18) >> 1], *(v20 - 1))
        || *(v20 - 2))
       && (HIDWORD(v18) != 2 || *v19) ? (v21 = 0) : (v21 = 1),
          !v21) )
    {
      v6 = -1073741823;
      goto LABEL_113;
    }
  }
  else
  {
    if ( v11 != -1073741772 )
      goto LABEL_113;
    v6 = 0;
  }
  if ( v60 )
  {
    v13 = *(_DWORD *)(v60 + 8);
    v14 = (unsigned __int16 *)(v13 + v60);
    if ( *(_WORD *)(v13 + v60) )
    {
      v15 = 0;
      do
      {
        ++v15;
        v14 += wcslen(v14) + 1;
      }
      while ( *v14 );
      v16 = v15;
      v56 = v15;
      if ( v15 )
      {
        v17 = (unsigned int **)ExAllocatePoolWithTag(1, 4 * v15, 1667526736);
        v61 = v17;
        if ( !v17 )
        {
          v6 = -1073741670;
          goto LABEL_113;
        }
        memset(v17, 0, 4 * v15);
        v23 = 0;
        v24 = (unsigned __int16 *)(v13 + v12);
        if ( *(_WORD *)(v13 + v12) )
        {
          v25 = v61;
          while ( 1 )
          {
            v16 = v15;
            if ( v23 >= v15 )
              break;
            v26 = PiDevCfgResolveVariable(a1, v24, v25);
            v6 = v26;
            if ( v26 < 0 )
            {
              if ( v26 == -1073741772 )
                v6 = -1073741823;
              goto LABEL_43;
            }
            v24 += wcslen(v24) + 1;
            ++v23;
            ++v25;
            if ( !*v24 )
              goto LABEL_43;
          }
        }
        else
        {
LABEL_43:
          v16 = v15;
        }
        v7 = (unsigned int)v59;
        if ( v6 < 0 )
          goto LABEL_111;
        v5 = (unsigned int)v61;
      }
      else
      {
        v5 = 0;
      }
      goto LABEL_48;
    }
    v5 = 0;
  }
  v16 = 0;
LABEL_48:
  v27 = v57;
  v28 = 0;
  v29 = *(unsigned __int16 *)(v57 + v7);
  v30 = (unsigned __int16 *)(v57 + v7);
  while ( v29 )
  {
    v31 = *v30++;
    if ( v31 != 37 )
      goto LABEL_53;
    v32 = *v30;
    if ( v32 == 37 )
    {
      ++v30;
LABEL_53:
      v28 += 2;
      goto LABEL_54;
    }
    if ( v32 >= 0x30 && v32 <= 0x39 )
    {
      v36 = 0;
      while ( v32 && v32 - 48 <= 9 )
      {
        v37 = v32 + 10 * v36;
        v32 = *++v30;
        v36 = v37 - 48;
      }
      if ( v36 < v16 )
      {
        v38 = *(_DWORD *)(v5 + 4 * v36);
        if ( v38 )
        {
          v39 = *(_DWORD *)(v38 + 16);
          if ( v39 )
          {
            if ( v39 <= 2 )
            {
              v28 = *(_DWORD *)(v38 + 20) + v28 - 2;
            }
            else
            {
              if ( v39 != 4 )
              {
                if ( v39 != 7 )
                  goto LABEL_54;
                v40 = *(unsigned __int16 **)(v38 + 24);
                goto LABEL_71;
              }
              if ( RtlStringCchPrintfW(v63, 0xBu, (int)L"%u", **(_DWORD **)(v38 + 24)) >= 0 )
              {
                v40 = v63;
LABEL_71:
                v28 += 2 * wcslen(v40);
                goto LABEL_54;
              }
            }
          }
        }
      }
    }
LABEL_54:
    v29 = *v30;
    v16 = v56;
  }
  v33 = v28 + 2;
  v34 = ExAllocatePoolWithTag(1, v33, 1667526736);
  v35 = v34;
  v58 = v34;
  if ( !v34 )
  {
    v6 = -1073741670;
    goto LABEL_110;
  }
  v41 = (_WORD *)v34;
  v42 = v33;
  v43 = (_WORD *)(v7 + v27);
  if ( !*(_WORD *)((char *)v59 + v27) )
    goto LABEL_120;
  while ( 2 )
  {
    v45 = (unsigned __int16)*v43++;
    v44 = v45;
    if ( v45 == 37 )
    {
      v46 = (unsigned __int16)*v43;
      if ( v46 == 37 )
      {
        if ( v42 <= 2 )
          goto LABEL_105;
        *v41 = 37;
        ++v43;
LABEL_102:
        v42 -= 2;
        ++v41;
LABEL_103:
        if ( !*v43 )
          goto LABEL_119;
        continue;
      }
      if ( v46 < 0x30 || v46 > 0x39 )
        goto LABEL_103;
      for ( i = 0; *v43; i = v48 - 48 )
      {
        if ( v46 - 48 > 9 )
          break;
        ++v43;
        v48 = v46 + 10 * i;
        v46 = (unsigned __int16)*v43;
      }
      if ( i >= v56 )
        goto LABEL_103;
      v49 = v61[i];
      if ( !v49 )
        goto LABEL_103;
      v50 = v49[4];
      if ( v50 )
      {
        if ( v50 <= 2 )
        {
          v51 = (unsigned __int16 *)v49[6];
          v52 = v49[5] - 2;
          goto LABEL_96;
        }
        if ( v50 == 4 )
        {
          if ( RtlStringCchPrintfW(v63, 0xBu, (int)L"%u", *(_DWORD *)v49[6]) < 0 )
            goto LABEL_103;
          v51 = v63;
          v52 = 2 * wcslen(v63);
          goto LABEL_97;
        }
        if ( v50 == 7 )
        {
          v51 = (unsigned __int16 *)v49[6];
          v52 = 2 * wcslen(v51);
LABEL_96:
          if ( !v51 )
            goto LABEL_103;
LABEL_97:
          if ( v52 )
          {
            if ( v42 <= v52 )
              goto LABEL_105;
            memmove((int)v41, (int)v51, v52);
            v41 += v52 >> 1;
            v42 -= v52;
          }
          goto LABEL_103;
        }
      }
      v51 = 0;
      v52 = 0;
      goto LABEL_96;
    }
    break;
  }
  if ( v42 > 2 )
  {
    *v41 = v44;
    goto LABEL_102;
  }
  v6 = -1073741823;
LABEL_119:
  v35 = v58;
LABEL_120:
  if ( v6 < 0 )
  {
LABEL_106:
    v53 = v58;
    goto LABEL_107;
  }
  if ( v42 != 2 )
  {
LABEL_105:
    v6 = -1073741823;
    goto LABEL_106;
  }
  *v41 = 0;
  v55 = v62;
  v53 = 0;
  *(_DWORD *)(v62 + 16) = 1;
  *(_DWORD *)(v55 + 20) = v33;
  *(_DWORD *)(v55 + 24) = v35;
LABEL_107:
  if ( v53 )
    ExFreePoolWithTag(v53);
  v7 = (unsigned int)v59;
LABEL_110:
  v12 = v60;
LABEL_111:
  if ( v61 )
    ExFreePoolWithTag((unsigned int)v61);
LABEL_113:
  if ( v12 )
    ExFreePoolWithTag(v12);
LABEL_115:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v6;
}
