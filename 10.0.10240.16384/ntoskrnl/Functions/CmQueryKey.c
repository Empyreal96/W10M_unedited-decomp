// CmQueryKey 
 
int __fastcall CmQueryKey(int a1, int a2, int a3, _DWORD *a4, unsigned int a5, _DWORD *a6)
{
  int v10; // r9
  int v11; // r4
  int v12; // r4
  int v13; // r4
  int v14; // r3
  __int16 *v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  int v18; // lr
  int v19; // r4
  int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r3
  int v23; // r0
  int v24; // r2
  unsigned int v25; // r3
  BOOL v26; // r2
  int v27; // r1
  int v28; // r2
  int v29; // r1
  int v30; // r3
  unsigned int v31; // r3
  int v32; // r1
  _DWORD *v33; // r6
  int v34; // r0
  int v35; // r0
  int v37; // [sp+18h] [bp-90h]
  int v39; // [sp+20h] [bp-88h] BYREF
  int v40; // [sp+24h] [bp-84h] BYREF
  _DWORD *v41; // [sp+28h] [bp-80h]
  _DWORD *v42; // [sp+2Ch] [bp-7Ch]
  int v43; // [sp+30h] [bp-78h]
  int v44; // [sp+34h] [bp-74h]
  int v45; // [sp+38h] [bp-70h]
  _DWORD *v46; // [sp+3Ch] [bp-6Ch]
  __int16 *v47; // [sp+40h] [bp-68h]
  __int16 v48; // [sp+48h] [bp-60h] BYREF
  _DWORD v49[3]; // [sp+4Ah] [bp-5Eh]
  int v50; // [sp+58h] [bp-50h] BYREF
  unsigned int v51; // [sp+68h] [bp-40h]
  unsigned int v52; // [sp+70h] [bp-38h]
  unsigned int v53; // [sp+74h] [bp-34h]
  unsigned int v54; // [sp+7Ch] [bp-2Ch]
  unsigned int v55; // [sp+80h] [bp-28h]
  int varg_r0; // [sp+B0h] [bp+8h]
  int varg_r1; // [sp+B4h] [bp+Ch]
  int varg_r2; // [sp+B8h] [bp+10h]
  _DWORD *varg_r3; // [sp+BCh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v43 = a1;
  v44 = a2;
  v46 = a4;
  v41 = a6;
  v42 = a6;
  v47 = 0;
  v40 = 0;
  v48 = 0;
  v49[0] = 0;
  LOWORD(v49[1]) = 0;
  if ( a3 == 7 )
  {
    *a6 = 4;
    if ( a5 < 4 )
      return -1073741789;
    *a4 = *(unsigned __int16 *)(a1 + 26);
    return 0;
  }
  CmpLockRegistry(0, 0);
  v10 = *(_DWORD *)(a1 + 4);
  v45 = v10;
  v11 = *(_DWORD *)(a1 + 28);
  if ( v11 || *(_DWORD *)(a1 + 32) )
  {
    if ( CmRmIsKCBDeleted(v10, v40) == 1 )
    {
      if ( (*(_DWORD *)(a1 + 24) & 1) != 0 )
        v12 = -1073740763;
      else
        v12 = -1073741444;
      goto LABEL_12;
    }
    v12 = CmpSearchAddTrans(a1, 0, 0, v11, *(_DWORD *)(a1 + 32), 0, &v40);
    if ( v12 < 0 )
    {
LABEL_12:
      CmpUnlockRegistry();
      return v12;
    }
  }
  if ( a2 )
  {
    v10 = *(_DWORD *)(a2 + 4);
    v45 = v10;
    CmpLockTwoKcbsShared(v10, *(_DWORD *)(a1 + 4));
  }
  else
  {
    CmpLockKcbShared(*(_DWORD **)(a1 + 4));
  }
  if ( a3 == 3 )
  {
    v13 = *(_DWORD *)(a1 + 4);
    if ( CmRmIsKCBDeleted(v13, v40) == 1 )
    {
      if ( (*(_DWORD *)(a1 + 24) & 1) != 0 )
      {
        v14 = -1073740763;
LABEL_122:
        v37 = v14;
        goto LABEL_123;
      }
      v39 = -1073741444;
      v37 = -1073741444;
    }
    else
    {
      v39 = 0;
      v37 = 0;
    }
    if ( !*(_DWORD *)(v13 + 44)
      || (!CmpVEEnabled || (*(_WORD *)(v13 + 106) & 0x100) == 0 ? (v15 = (__int16 *)CmpConstructName(v13), v47 = v15) : CmVirtualKCBToRealPath(v13, &v48) < 0 ? (v15 = 0) : (v15 = &v48, v47 = &v48),
          !v15) )
    {
      v14 = -1073741670;
      goto LABEL_122;
    }
    v16 = (unsigned __int16)*v15;
    *v41 = v16 + 4;
    if ( a5 >= 4 )
    {
      *a4 = v16;
      if ( a5 - 4 < v16 )
      {
        v16 = a5 - 4;
        v39 = -2147483643;
        v37 = -2147483643;
      }
      memmove((int)(a4 + 1), *((_DWORD *)v15 + 1), v16);
      v17 = v39;
    }
    else
    {
      v17 = -1073741789;
      v37 = -1073741789;
    }
    v18 = v40;
    goto LABEL_76;
  }
  v19 = v40;
  v39 = v40;
  if ( CmRmIsKCBDeleted(v10, v40) == 1 || a2 && CmRmIsKCBDeleted(*(_DWORD *)(a1 + 4), v19) == 1 )
  {
    if ( (*(_DWORD *)(a1 + 24) & 1) != 0 )
      v14 = -1073740763;
    else
      v14 = -1073741444;
    goto LABEL_122;
  }
  switch ( a3 )
  {
    case 5:
      *v41 = 12;
      if ( a5 >= 0xC )
      {
        *a4 = CmGetKeyFlags(v10, v19);
        a4[1] = 0;
        if ( *(int *)(v10 + 24) < 0 )
          a4[1] = 1;
        if ( (*(_WORD *)(v10 + 106) & 0x10) != 0 )
          a4[1] |= 2u;
        a4[2] = (unsigned __int8)*(_DWORD *)(v10 + 104) >> 4;
        v17 = 0;
        v37 = 0;
      }
      else
      {
        v39 = -1073741789;
        v37 = -1073741789;
        v17 = -1073741789;
      }
      v18 = v40;
      goto LABEL_76;
    case 6:
      *v41 = 4;
      if ( a5 < 4 )
      {
        v17 = -1073741789;
        v37 = -1073741789;
        v18 = v39;
        goto LABEL_76;
      }
      if ( !CmpVEEnabled || (*(_WORD *)(v10 + 106) & 0x200) != 0 || CmpIsMasterHive(v10) )
      {
        v18 = v39;
      }
      else
      {
        v23 = CmpIsSystemEntity(0, v20, v21, v22);
        v18 = v40;
        if ( !v23 )
        {
          v24 = 1;
          goto LABEL_60;
        }
      }
      v24 = 0;
LABEL_60:
      v25 = *a4 & 0xFFFFFFFE | (v24 != 0);
      *a4 = v25;
      *a4 = v25 & 0xFFFFFFFD;
      if ( v24 && (*(_DWORD *)(v10 + 104) & 0x20) == 0 )
        *a4 = v25 & 0xFFFFFFFD | 2;
      v26 = CmpVEEnabled && (*(_WORD *)(v10 + 106) & 0x100) != 0;
      v27 = (*a4 ^ (4 * v26)) & 4 ^ *a4;
      *a4 = v27;
      v28 = v45;
      v29 = v27 ^ ((unsigned __int8)v27 ^ (unsigned __int8)(8 * ((*(_WORD *)(v45 + 106) & 0x200) != 0))) & 8;
      *a4 = v29;
      *a4 = ((unsigned __int8)v29 ^ (unsigned __int8)(16 * ((*(_WORD *)(v28 + 106) & 0x80) != 0))) & 0x10 ^ v29;
      v17 = 0;
      v37 = 0;
      goto LABEL_76;
    case 8:
      *v41 = 4;
      if ( a5 < 4 )
      {
        v14 = -1073741789;
        goto LABEL_122;
      }
      v30 = *a4;
      if ( (*(_DWORD *)(*(_DWORD *)(v10 + 20) + 3228) & 1) != 0 )
        v31 = v30 & 0xFFFFFFFE;
      else
        v31 = v30 | 1;
      *a4 = v31;
      v37 = 0;
      v18 = v40;
LABEL_77:
      if ( a2 )
      {
        if ( a3 != 3 && a3 != 5 && a3 != 6 )
        {
          v32 = *(_DWORD *)(a2 + 4);
          if ( *(_QWORD *)(*(_DWORD *)(a1 + 4) + 88) < *(_QWORD *)(v32 + 88) )
          {
            *a4 = *(_DWORD *)(v32 + 88);
            a4[1] = *(_DWORD *)(v32 + 92);
          }
        }
        if ( a3 == 2 || a3 == 4 )
        {
          if ( CmpFindSubKeyByNumberFromMergedView(*(_DWORD *)(a2 + 4), *(_DWORD *)(a1 + 4), -1, v18) == -2147483622 )
          {
            if ( a3 == 2 )
              a4[5] = v39;
            else
              a4[3] = v39;
          }
          if ( CmEnumerateValueKeyFromMergedView(a1, a2, 1, -1, 0, 0, 0, 0, &v39) == -2147483622 )
          {
            v33 = a4;
            if ( a3 == 2 )
              a4[8] = v39;
            else
              a4[5] = v39;
          }
          else
          {
            v33 = a4;
          }
          v34 = CmpQueryKeyData(*(_DWORD *)(a1 + 4), a3, &v50, 48, v41, v40);
          v37 = v34;
          if ( v34 >= 0 || v34 == -2147483643 )
          {
            if ( a3 == 2 )
            {
              if ( v52 > v33[6] )
                v33[6] = v52;
              if ( v54 > v33[9] )
                v33[9] = v54;
              if ( v55 > v33[10] )
                v33[10] = v55;
            }
            else
            {
              if ( v51 > v33[4] )
                v33[4] = v51;
              if ( v52 > v33[6] )
                v33[6] = v52;
              if ( v53 > v33[7] )
                v33[7] = v53;
            }
          }
        }
      }
      else if ( CmpVEEnabled )
      {
        v35 = *(_DWORD *)(a1 + 4);
        if ( (*(_WORD *)(v35 + 106) & 0x100) != 0 && (a3 == 2 || a3 == 4) )
        {
          v37 = CmpFindSubKeyByNumberFromMergedView(v35, 0, -1, v18);
          if ( v37 == -2147483622 )
          {
            if ( a3 == 2 )
              a4[5] = v45;
            else
              a4[3] = v45;
            v37 = 0;
          }
        }
      }
      goto LABEL_123;
  }
  v17 = CmpQueryKeyData(v10, a3, a4, a5, v41, v19);
  v39 = v17;
  v37 = v17;
  v18 = v40;
LABEL_76:
  if ( v17 >= 0 )
    goto LABEL_77;
LABEL_123:
  if ( v44 )
    CmpUnlockTwoKcbs(*(_DWORD **)(v44 + 4), *(_DWORD **)(v43 + 4));
  else
    CmpUnlockKcb(*(_DWORD **)(v43 + 4));
  CmpUnlockRegistry();
  if ( *(_DWORD *)((char *)v49 + 2) )
  {
    RtlFreeAnsiString(&v48);
  }
  else if ( v47 )
  {
    ExFreePoolWithTag((unsigned int)v47);
  }
  return v37;
}
