// CmpCheckValueList 
 
int __fastcall CmpCheckValueList(int a1, int a2, int a3, unsigned int a4, int a5, int a6, unsigned int *a7, unsigned int *a8)
{
  int **v9; // r3
  _DWORD *v11; // r4
  unsigned int *v12; // r5
  int *v13; // r8
  unsigned int *v15; // r0
  int v16; // r8
  unsigned int v17; // r2
  unsigned int v18; // r7
  int v19; // r0
  __int16 v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r7
  int v23; // r8
  int v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r0
  unsigned int v27; // r3
  unsigned int *v28; // r0
  int v29; // lr
  unsigned int v30; // r7
  unsigned int *v31; // r3
  int v32; // r1
  int v33; // r0
  int v34; // r3
  int v35; // r2
  int *v36; // r3
  int *v37; // r3
  int v38; // r3
  int v39; // r3
  int *v40; // r3
  int *v41; // r3
  int *v42; // r3
  unsigned int v43; // r7
  int v44; // r8
  int v45; // r0
  int v46; // r1
  int v47; // r3
  int v48; // r3
  int *v49; // r3
  unsigned int v50; // [sp+8h] [bp-70h]
  int v51; // [sp+Ch] [bp-6Ch]
  int v52; // [sp+10h] [bp-68h] BYREF
  int *v53; // [sp+14h] [bp-64h]
  unsigned int *v54; // [sp+18h] [bp-60h]
  int v55; // [sp+1Ch] [bp-5Ch] BYREF
  unsigned int *v56; // [sp+20h] [bp-58h]
  int v57; // [sp+24h] [bp-54h] BYREF
  int v58; // [sp+28h] [bp-50h]
  int **v59; // [sp+2Ch] [bp-4Ch]
  int v60; // [sp+30h] [bp-48h] BYREF
  int v61; // [sp+34h] [bp-44h] BYREF
  int v62; // [sp+38h] [bp-40h]
  char v63[56]; // [sp+40h] [bp-38h] BYREF

  v9 = (int **)a3;
  v62 = a2;
  v58 = a6;
  v59 = (int **)a3;
  v51 = 0;
  strcpy(v63, "SymbolicLinkValue");
  v50 = 0;
  v54 = a7;
  v11 = *(_DWORD **)(a1 + 28);
  v52 = -1;
  v55 = -1;
  v56 = a8;
  v60 = -1;
  v61 = -1;
  v57 = -1;
  v11[59] = a3;
  v11[60] = -1;
  v11[61] = 0;
  v11[62] = 0;
  *a7 = 0;
  *a8 = 0;
  if ( !a4 )
    return v51;
  v12 = v56;
  while ( 1 )
  {
    v13 = *v9;
    v53 = *v9;
    if ( v62 )
      return sub_7FC954();
    if ( v13 == (int *)-1 )
    {
      v44 = 5010;
      SetFailureLocation((int)v11, 1, 15, 5010, 80);
      v11[61] = -1;
      goto LABEL_78;
    }
    if ( !HvIsCellAllocated(a1, v13, v58) )
    {
      v44 = 5020;
      SetFailureLocation((int)v11, 1, 15, 5020, 96);
      v11[61] = v53;
LABEL_78:
      v43 = v50;
      v11[60] = v50;
      goto LABEL_79;
    }
    v15 = (unsigned int *)(*(int (__fastcall **)(int, int *, int *))(a1 + 4))(a1, v13, &v52);
    v16 = (int)v15;
    v54 = v15;
    if ( !v15 )
    {
      v49 = v53;
      v11[60] = v50;
      v11[61] = v49;
      v51 = 5099;
      SetFailureLocation((int)v11, 0, 15, 5099, 112);
      return v51;
    }
    v17 = -4 - *(v15 - 1);
    if ( v17 < 0x14 || *(_WORD *)v15 != 27510 )
    {
      SetFailureLocation((int)v11, 1, 15, 5030, 128);
      v43 = v50;
      v11[61] = v53;
      v11[62] = v16;
      v11[60] = v50;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
      v44 = 5030;
      goto LABEL_79;
    }
    v18 = *((unsigned __int16 *)v15 + 1);
    if ( v18 + 20 > v17 )
    {
      SetFailureLocation((int)v11, 1, 15, 5040, 144);
      v43 = v50;
      v11[61] = v53;
      v11[62] = v16;
      v11[60] = v50;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
      v44 = 5040;
      goto LABEL_79;
    }
    v19 = v62;
    if ( v62 )
    {
      if ( memcmp(v16 + 20, (unsigned int)v63, 17) )
      {
        v34 = 5045;
        v35 = 160;
        goto LABEL_89;
      }
      if ( *(_DWORD *)(v16 + 12) != 6 )
      {
        v34 = 5046;
        v35 = 176;
        goto LABEL_89;
      }
      v19 = v62;
    }
    v20 = *(_WORD *)(v16 + 16);
    if ( (v20 & 1) != 0 )
      v21 = (unsigned __int16)(2 * v18);
    else
      v21 = v18;
    if ( *a7 < v21 )
    {
      if ( (v20 & 1) != 0 )
        v27 = (unsigned __int16)(2 * v18);
      else
        v27 = v18;
      *a7 = v27;
    }
    v22 = *(_DWORD *)(v16 + 4);
    if ( v19 )
    {
      if ( (v22 & 1) != 0 )
      {
        v34 = 5047;
        v35 = 192;
      }
      else
      {
        if ( v22 <= 0xFFFF )
          goto LABEL_16;
        v34 = 5048;
        v35 = 208;
      }
LABEL_89:
      v51 = v34;
      SetFailureLocation((int)v11, 0, 15, v34, v35);
      v11[61] = v53;
      v11[62] = v16;
      v11[60] = v50;
      goto LABEL_91;
    }
LABEL_16:
    if ( v22 >= 0x80000000 )
    {
      if ( v22 + 0x80000000 <= 4 )
        goto LABEL_28;
      SetFailureLocation((int)v11, 1, 15, 5051, 416);
      v43 = v50;
      v11[61] = v53;
      v11[62] = v16;
      v11[60] = v50;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
      v44 = 5051;
    }
    else
    {
      v23 = 0;
      v24 = v54[2];
      v56 = (unsigned int *)v24;
      if ( v22 )
      {
        if ( !HvIsCellAllocated(a1, v24, v58) )
        {
          v44 = 5060;
          SetFailureLocation((int)v11, 1, 15, 5060, 240);
          v37 = v53;
          v43 = v50;
          v11[60] = v50;
          v11[61] = v37;
          v11[62] = v54;
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
          goto LABEL_79;
        }
        v23 = (*(int (__fastcall **)(int, unsigned int *, int *))(a1 + 4))(a1, v56, &v55);
        if ( !v23 )
        {
          v48 = (int)v56;
          v11[60] = v50;
          v11[61] = v48;
          v51 = 5098;
          SetFailureLocation((int)v11, 0, 15, 5098, 256);
          goto LABEL_91;
        }
        v24 = (int)v56;
      }
      else if ( v24 != -1 )
      {
        v44 = 5050;
        SetFailureLocation((int)v11, 1, 15, 5050, 224);
        v36 = v53;
        v43 = v50;
        v11[60] = v50;
        v11[61] = v36;
        v11[62] = v54;
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
        goto LABEL_79;
      }
      if ( *(_DWORD *)(a1 + 148) >= 4u && v22 > 0x3FD8 )
      {
        if ( (unsigned int)(-4 - *(_DWORD *)(v23 - 4)) < 8
          || *(_WORD *)v23 != 25188
          || !*(_WORD *)(v23 + 2)
          || *(_DWORD *)(v23 + 4) == -1 )
        {
          v43 = v50;
          v44 = 5097;
          v11[60] = v50;
          v11[61] = v24;
          SetFailureLocation((int)v11, 1, 15, 5097, 272);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
          goto LABEL_79;
        }
        if ( !HvIsCellAllocated(a1, *(_DWORD *)(v23 + 4), v58) )
        {
          SetFailureLocation((int)v11, 1, 15, 5096, 288);
          v43 = v50;
          v11[60] = v50;
          v11[61] = *(_DWORD *)(v23 + 4);
          v11[62] = v23;
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
          v44 = 5096;
          goto LABEL_79;
        }
        v28 = (unsigned int *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v23 + 4), &v57);
        v56 = v28;
        if ( !v28 )
        {
          v51 = 5095;
          v11[60] = v50;
          v11[61] = *(_DWORD *)(v23 + 4);
          SetFailureLocation((int)v11, 0, 15, 5095, 304);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
          goto LABEL_91;
        }
        v29 = *(unsigned __int16 *)(v23 + 2);
        if ( (unsigned int)(4 * v29) < 4 || 4 * v29 > -4 - *(v28 - 1) )
        {
          v44 = 5100;
          SetFailureLocation((int)v11, 1, 15, 5100, 320);
          v41 = v53;
          v43 = v50;
          v11[60] = v50;
          v11[61] = v41;
          v11[62] = v54;
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v57);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
          goto LABEL_79;
        }
        if ( v29 == (((v22 + 16343) / 0x3FD8) & 0x7FFFF) )
        {
          v30 = 0;
          if ( !*(_WORD *)(v23 + 2) )
          {
LABEL_56:
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v57);
LABEL_25:
            if ( v23 )
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
            v16 = (int)v54;
LABEL_28:
            v25 = *(_DWORD *)(v16 + 4);
            if ( v25 >= 0x80000000 )
              v25 += 0x80000000;
            if ( *v12 < v25 )
              *v12 = v25;
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
            v26 = v50 + 1;
            v9 = ++v59;
            ++v50;
            goto LABEL_33;
          }
          v31 = v28;
          v53 = (int *)v28;
          while ( 1 )
          {
            if ( !HvIsCellAllocated(a1, *v31, v58) )
            {
              SetFailureLocation((int)v11, 1, 15, 5094, 352);
              v39 = (int)v56;
              v11[60] = v30;
              v11[61] = *(_DWORD *)(v39 + 4 * v30);
              v11[62] = v23;
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v57);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
              v43 = v50;
              v44 = 5094;
              goto LABEL_79;
            }
            v32 = *v53++;
            v33 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v32, &v60);
            if ( !v33 )
              break;
            if ( (unsigned int)(-4 - *(_DWORD *)(v33 - 4)) < 0x3FD8 )
            {
              SetFailureLocation((int)v11, 1, 15, 5036, 384);
              v38 = (int)v56;
              v11[60] = v30;
              v11[61] = *(_DWORD *)(v38 + 4 * v30);
              v11[62] = v23;
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v60);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v57);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
              v43 = v50;
              v44 = 5036;
              goto LABEL_79;
            }
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v60);
            ++v30;
            v31 = (unsigned int *)v53;
            if ( v30 >= *(unsigned __int16 *)(v23 + 2) )
              goto LABEL_56;
          }
          v51 = 5034;
          SetFailureLocation((int)v11, 0, 15, 5034, 368);
          v47 = (int)v56;
          v11[60] = v30;
          v11[61] = *(_DWORD *)(v47 + 4 * v30);
          v11[62] = v23;
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v57);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
LABEL_91:
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
          return v51;
        }
        v44 = 5101;
        SetFailureLocation((int)v11, 1, 15, 5101, 336);
        v40 = v53;
        v43 = v50;
        v11[60] = v50;
        v11[61] = v40;
        v11[62] = v54;
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v57);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
      }
      else
      {
        if ( !v22 || v22 <= -4 - *(_DWORD *)(v23 - 4) )
          goto LABEL_25;
        v44 = 5052;
        SetFailureLocation((int)v11, 1, 15, 5052, 400);
        v42 = v53;
        v43 = v50;
        v11[60] = v50;
        v11[61] = v42;
        v11[62] = v54;
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v55);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v52);
      }
    }
LABEL_79:
    if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
    {
      SetFailureLocation((int)v11, 1, 15, v44, 48);
      return v44;
    }
    v54 = (unsigned int *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a5, &v61);
    SetFailureLocation((int)v11, 1, 15, v44, 0);
    if ( !v54 )
      break;
    if ( !HvpMarkCellDirty(a1, a5, 0, 0) || !HvpMarkCellDirty(a1, v54[10], 0, 0) )
    {
      SetFailureLocation((int)v11, 1, 15, v44, 32);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v61);
      return v44;
    }
    v45 = (int)v59;
    --a4;
    v46 = (int)(v59 + 1);
    --v54[9];
    memmove(v45, v46, 4 * (a4 - v43));
    v51 = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v61);
    v9 = v59;
    v26 = v50;
LABEL_33:
    if ( v26 >= a4 )
      return v51;
  }
  SetFailureLocation((int)v11, 0, 15, v44, 16);
  return v44;
}
