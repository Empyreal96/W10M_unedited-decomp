// CmMoveKey 
 
int __fastcall CmMoveKey(int a1)
{
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r8
  int v4; // r5
  int v5; // r4
  int v6; // r6
  int v7; // r9
  int v8; // r1
  _WORD *v9; // r5
  int *v10; // r1
  int v11; // r6
  _WORD *v12; // r7
  int v13; // t1
  int v14; // r5
  int v15; // r10
  unsigned __int16 *v16; // r0
  unsigned __int16 *v17; // r10
  int v18; // r2
  int i; // r2
  int v20; // r7
  int (__fastcall *v21)(int, int, int *); // r3
  unsigned __int16 *v22; // r0
  int v23; // r3
  int v24; // r5
  unsigned __int16 *v25; // r1
  int v26; // t1
  unsigned int v27; // r5
  unsigned __int16 *v28; // r2
  unsigned int v29; // r3
  int v30; // r5
  unsigned __int16 *v31; // r1
  int v32; // t1
  unsigned int *v33; // r7
  unsigned int v34; // r8
  int v35; // r1
  int v36; // r2
  int v37; // r3
  int v38; // r0
  _DWORD *v39; // r7
  int v40; // r1
  _WORD *v41; // r0
  _WORD *v42; // r6
  unsigned int v43; // r9
  _WORD *v44; // r8
  unsigned int v45; // t1
  int v46; // r7
  unsigned int v48; // r5
  unsigned __int16 *v49; // r2
  int v50; // r5
  int v51; // r1
  _WORD *v52; // r0
  _WORD *v53; // r5
  unsigned int v54; // r6
  _WORD *v55; // r7
  unsigned int v56; // t1
  int v57; // [sp+0h] [bp-58h]
  int v58; // [sp+4h] [bp-54h] BYREF
  unsigned int *v59; // [sp+8h] [bp-50h]
  unsigned __int16 *v60; // [sp+Ch] [bp-4Ch]
  int v61; // [sp+10h] [bp-48h] BYREF
  int v62; // [sp+14h] [bp-44h]
  unsigned int v63; // [sp+18h] [bp-40h] BYREF
  int v64; // [sp+1Ch] [bp-3Ch] BYREF
  int v65; // [sp+20h] [bp-38h] BYREF
  int v66; // [sp+24h] [bp-34h] BYREF
  int v67; // [sp+28h] [bp-30h]
  int v68; // [sp+2Ch] [bp-2Ch] BYREF
  int v69; // [sp+30h] [bp-28h]
  _DWORD *v70; // [sp+34h] [bp-24h]

  v1 = *(_DWORD **)(a1 + 4);
  v65 = -1;
  v66 = -1;
  v60 = 0;
  v61 = -1;
  v68 = -1;
  v58 = -1;
  v63 = -1;
  v64 = -1;
  v2 = v1[1];
  v3 = 0;
  v59 = 0;
  v70 = v1;
  if ( (v2 & 0x20000) == 0 )
  {
    v6 = v1[6];
    v5 = v1[5];
    v62 = v6;
    if ( v6 < 0 )
      return 0;
    if ( v6 == *(_DWORD *)(*(_DWORD *)(v5 + 32) + 36) )
      return -1073741811;
    v7 = (*(int (__fastcall **)(int, int, int *))(v5 + 4))(v5, v6, &v66);
    if ( !v7 )
      return -1073741670;
    if ( !CmpMarkKeyDirty(v5, v6, 1) )
      goto LABEL_12;
    if ( (*(_WORD *)(v7 + 2) & 0x10) != 0 )
    {
      v4 = -1073741811;
      goto LABEL_87;
    }
    v8 = *(_DWORD *)(v7 + 28);
    if ( v8 != -1 )
    {
      v9 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(v5 + 4))(v5, v8, &v58);
      if ( !v9 )
      {
LABEL_17:
        v4 = -1073741670;
        goto LABEL_87;
      }
      if ( !HvpMarkCellDirty(v5, *(_DWORD *)(v7 + 28), 0, 0) )
        goto LABEL_19;
      if ( *v9 == 26994 )
      {
        v11 = 0;
        if ( v9[1] )
        {
          v12 = v9;
          while ( 1 )
          {
            v13 = *((_DWORD *)v12 + 1);
            v12 += 2;
            if ( !HvpMarkCellDirty(v5, v13, 0, 0) )
              break;
            if ( ++v11 >= (unsigned int)(unsigned __int16)v9[1] )
              goto LABEL_25;
          }
LABEL_19:
          v4 = -1073741443;
          v10 = &v58;
LABEL_86:
          (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, v10);
          goto LABEL_87;
        }
LABEL_25:
        v6 = v62;
      }
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v58);
    }
    v14 = *(_DWORD *)(v7 + 16);
    v15 = (*(int (__fastcall **)(int, int, int *))(v5 + 4))(v5, v14, &v61);
    v57 = v15;
    if ( !v15 )
      goto LABEL_17;
    if ( !HvpMarkCellDirty(v5, v14, 0, 0) )
    {
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v61);
LABEL_12:
      v4 = -1073741443;
LABEL_87:
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v66);
      return v4;
    }
    v16 = (unsigned __int16 *)(*(int (__fastcall **)(int, _DWORD, int *))(v5 + 4))(v5, *(_DWORD *)(v15 + 28), &v65);
    v17 = v16;
    if ( !v16 )
    {
LABEL_32:
      v4 = -1073741670;
LABEL_79:
      v46 = v57;
      goto LABEL_80;
    }
    v18 = *v16;
    if ( v18 == 26994 )
    {
      v67 = 0;
      if ( v16[1] )
      {
        for ( i = (int)v16; ; i = v69 )
        {
          v20 = *(_DWORD *)(i + 4);
          v21 = *(int (__fastcall **)(int, int, int *))(v5 + 4);
          v69 = i + 4;
          v22 = (unsigned __int16 *)v21(v5, v20, &v64);
          v60 = v22;
          if ( !v22 )
            goto LABEL_32;
          v23 = *v22;
          if ( v23 == 26220 || v23 == 26732 )
          {
            v27 = 0;
            if ( v22[1] )
            {
              v28 = v22;
              while ( *((_DWORD *)v28 + 1) != v6 )
              {
                ++v27;
                v28 += 4;
                if ( v27 >= v22[1] )
                  goto LABEL_54;
              }
              if ( !HvpMarkCellDirty(v5, v20, 0, 0) )
              {
LABEL_57:
                v4 = -1073741443;
                goto LABEL_79;
              }
              v3 = (int)&v60[4 * v27 + 2];
              goto LABEL_53;
            }
          }
          else
          {
            v24 = 0;
            if ( v22[1] )
            {
              v25 = v22;
              while ( 1 )
              {
                v26 = *((_DWORD *)v25 + 1);
                v25 += 2;
                if ( v26 == v6 )
                  break;
                if ( ++v24 >= (unsigned int)v22[1] )
                  goto LABEL_54;
              }
              if ( !HvpMarkCellDirty(v5, v20, 0, 0) )
                goto LABEL_57;
              v3 = (int)&v60[2 * v24 + 2];
LABEL_53:
              v59 = (unsigned int *)v3;
              goto LABEL_54;
            }
          }
LABEL_54:
          if ( !v3 )
          {
            (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v64);
            v60 = 0;
            v29 = v17[1];
            if ( ++v67 < v29 )
              continue;
          }
          v33 = v59;
          goto LABEL_65;
        }
      }
      goto LABEL_64;
    }
    if ( v18 == 26220 || v18 == 26732 )
    {
      v48 = 0;
      if ( v16[1] )
      {
        v49 = v16;
        while ( *((_DWORD *)v49 + 1) != v6 )
        {
          ++v48;
          v49 += 4;
          if ( v48 >= v16[1] )
            goto LABEL_64;
        }
        v46 = v57;
        if ( HvpMarkCellDirty(v5, *(_DWORD *)(v57 + 28), 0, 0) )
        {
          v33 = (unsigned int *)&v17[4 * v48 + 2];
          goto LABEL_65;
        }
        goto LABEL_97;
      }
    }
    else
    {
      v30 = 0;
      if ( v16[1] )
      {
        v31 = v16;
        while ( 1 )
        {
          v32 = *((_DWORD *)v31 + 1);
          v31 += 2;
          if ( v32 == v6 )
            break;
          if ( ++v30 >= (unsigned int)v16[1] )
            goto LABEL_64;
        }
        v46 = v57;
        if ( HvpMarkCellDirty(v5, *(_DWORD *)(v57 + 28), 0, 0) )
        {
          v33 = (unsigned int *)&v17[2 * v30 + 2];
          goto LABEL_65;
        }
LABEL_97:
        v4 = -1073741443;
LABEL_80:
        if ( v46 )
          (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v61);
        goto LABEL_82;
      }
    }
LABEL_64:
    v33 = 0;
LABEL_65:
    (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v61);
    v57 = 0;
    (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v65);
    v17 = 0;
    v4 = CmpDuplicateKey(v5, v6, &v63);
    if ( v4 < 0 )
    {
LABEL_82:
      if ( v60 )
        (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v64);
      if ( !v17 )
        goto LABEL_87;
      v10 = &v65;
      goto LABEL_86;
    }
    v34 = v63;
    if ( CmpUpdateParentForEachSon(v5, v63) )
    {
      v50 = (int)v70;
      *v33 = v34;
      CmpCleanUpSubKeyInfo(*(_DWORD **)(v50 + 40), v35, v36, v37);
      *(_DWORD *)(v50 + 24) = v34;
      CmpRebuildKcbCache(v50);
      v51 = *(_DWORD *)(v7 + 28);
      if ( v51 != -1 )
      {
        v52 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(v5 + 4))(v5, v51, &v58);
        v53 = v52;
        if ( *v52 == 26994 )
        {
          v54 = 0;
          if ( v52[1] )
          {
            v55 = v52;
            do
            {
              v56 = *((_DWORD *)v55 + 1);
              v55 += 2;
              HvFreeCell(v5, v56);
              ++v54;
            }
            while ( v54 < (unsigned __int16)v53[1] );
          }
          v6 = v62;
        }
        (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v58);
        HvFreeCell(v5, *(_DWORD *)(v7 + 28));
      }
      *(_DWORD *)(v7 + 20) = 0;
      *(_DWORD *)(v7 + 24) = 0;
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v66);
      CmpFreeKeyByCell(v5, v6, 0);
      return 0;
    }
    v4 = -1073741670;
    v38 = (*(int (__fastcall **)(int, unsigned int, int *))(v5 + 4))(v5, v34, &v68);
    v39 = (_DWORD *)v38;
    if ( v38 )
    {
      v40 = *(_DWORD *)(v38 + 28);
      if ( v40 != -1 )
      {
        v41 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(v5 + 4))(v5, v40, &v58);
        v42 = v41;
        if ( v41 )
        {
          if ( *v41 == 26994 )
          {
            v43 = 0;
            if ( v41[1] )
            {
              v44 = v41;
              do
              {
                v45 = *((_DWORD *)v44 + 1);
                v44 += 2;
                HvFreeCell(v5, v45);
                ++v43;
              }
              while ( v43 < (unsigned __int16)v42[1] );
              v34 = v63;
            }
          }
          (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v58);
        }
        HvFreeCell(v5, v39[7]);
      }
      v39[5] = 0;
      v39[6] = 0;
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v68);
    }
    CmpFreeKeyByCell(v5, v34, 0);
    goto LABEL_79;
  }
  if ( (*(_DWORD *)(a1 + 24) & 1) != 0 )
    v4 = -1073740763;
  else
    v4 = -1073741444;
  return v4;
}
