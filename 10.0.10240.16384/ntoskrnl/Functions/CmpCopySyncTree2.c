// CmpCopySyncTree2 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpCopySyncTree2(int *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v8; // r2
  int v9; // r8
  unsigned int v10; // r4
  int *v11; // r10
  BOOL v12; // r3
  int v13; // r1
  int *v15; // r7
  int v16; // r9
  _DWORD *v17; // r1
  int v18; // r10
  int v19; // r0
  int v20; // r0
  int v21; // r8
  int v22; // r0
  int v23; // r3
  int v24; // r2
  void (__fastcall *v25)(_DWORD, _DWORD); // r3
  int v26; // r0
  int v27; // r1
  int v28; // r8
  unsigned int v29; // r10
  unsigned int v30; // r4
  int v31; // r0
  int *v32; // r8
  int *v33; // r10
  int *v34; // r4
  int v35; // r1
  int v36; // r2
  int v37; // r3
  unsigned int v38; // r7
  int *v39; // r4
  int v40; // r3
  unsigned int v41; // r8
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int *v46; // r10
  int v47; // r3
  int v48; // r0
  int v49; // r1
  int v50; // r2
  int v51; // r3
  int *v52; // lr
  int v53; // r0
  int v54; // r3
  int v55; // r1
  int v56; // r7
  int v57; // r1 OVERLAPPED
  int v58; // r0
  int v59; // r4
  char v60; // r9
  int v61; // r1
  int (__fastcall *v62)(_DWORD, _DWORD, _DWORD); // r3
  int v63; // r4
  int v64; // r0
  unsigned int v65; // r2
  int v66; // r4
  int *v67; // lr
  int *v68; // r1
  int v69; // r3
  int v71; // [sp+4h] [bp-9Ch]
  int v72; // [sp+10h] [bp-90h]
  unsigned int v73; // [sp+14h] [bp-8Ch]
  int v74; // [sp+1Ch] [bp-84h] BYREF
  _DWORD *v75; // [sp+20h] [bp-80h]
  int v76; // [sp+24h] [bp-7Ch]
  int v77; // [sp+28h] [bp-78h]
  unsigned int v78; // [sp+2Ch] [bp-74h]
  int *v79; // [sp+30h] [bp-70h]
  BOOL v80; // [sp+34h] [bp-6Ch]
  int v81; // [sp+38h] [bp-68h]
  int v82; // [sp+3Ch] [bp-64h] BYREF
  int v83; // [sp+40h] [bp-60h]
  int v84; // [sp+44h] [bp-5Ch] BYREF
  int v85; // [sp+48h] [bp-58h]
  int v86; // [sp+4Ch] [bp-54h] BYREF
  int v87; // [sp+50h] [bp-50h] BYREF
  int v88; // [sp+54h] [bp-4Ch] BYREF
  int v89; // [sp+58h] [bp-48h]
  int v90; // [sp+5Ch] [bp-44h]
  unsigned int v91; // [sp+60h] [bp-40h]
  int v92; // [sp+64h] [bp-3Ch] BYREF
  int v93; // [sp+68h] [bp-38h] BYREF
  int v94; // [sp+6Ch] [bp-34h] BYREF
  int v95; // [sp+70h] [bp-30h] BYREF
  char v96[40]; // [sp+78h] [bp-28h] BYREF

  v90 = 0;
  v81 = 0;
  v8 = -1;
  v9 = 0;
  v76 = 0;
  v10 = 0;
  v11 = a1;
  v79 = a1;
  v77 = 0;
  v82 = -1;
  v86 = -1;
  v87 = -1;
  v88 = -1;
  v89 = -1;
  v92 = -1;
  if ( (a6 & 1) != 0 )
  {
    v85 = 1;
    v8 = -1;
  }
  else
  {
    v85 = 0;
  }
  v12 = a7 == 1 || a7 == 2;
  v80 = v12;
  v73 = 0;
  v91 = 0;
  v83 = 1;
  v84 = -1;
  v13 = 0;
  v78 = -1;
  v72 = 0;
  if ( v12 )
  {
    v9 = ExAllocatePoolWithTag(1, 512, 1851419971);
    v76 = v9;
    if ( !v9 )
      return 0;
    v8 = v78;
    v13 = 0;
  }
  while ( 2 )
  {
    v15 = &v11[5 * v10];
    v16 = 5 * v8;
    v74 = 20 * v8 + 20;
    v15[2] = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v13 )
          (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v86);
        v17 = (_DWORD *)(*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, *v15, &v86);
        v75 = v17;
        if ( !v17 )
        {
          v33 = (int *)v73;
          goto LABEL_112;
        }
        if ( CmpFindSubKeyByNumber(a4, v17, v15[2], &v94) < 0 )
          goto LABEL_99;
        v18 = v94;
        ++v15[2];
        if ( v18 != -1 && (v85 || v18 >= 0) )
          break;
        if ( v80 && a7 != 2 )
        {
          v26 = (*(int (__fastcall **)(int, int, int *))(a5 + 4))(a5, v15[1], &v88);
          if ( !v26 )
            goto LABEL_99;
          if ( v85 )
            v27 = v75[6];
          else
            v27 = 0;
          if ( *(_DWORD *)(v26 + 24) + *(_DWORD *)(v26 + 20) > (unsigned int)(v75[5] + v27) )
            CmpSyncSubKeysAfterDelete(a4, v75, a5, v26, v9);
          (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v88);
        }
        v28 = v74;
        if ( (v15[4] & 1) != 0 )
        {
          v29 = v91;
          v28 = v74 + 20;
          ++v78;
          v16 += 5;
          v74 += 20;
          if ( v78 < v91 )
          {
            v33 = (int *)v73;
          }
          else
          {
            v30 = v91 + 1;
            if ( v91 + 1 <= v91 + (v91 >> 1) )
              v30 = v91 + (v91 >> 1);
            v31 = ExAllocatePoolWithTag(1, 20 * v30, 538987843);
            v32 = (int *)v31;
            if ( !v31 )
              goto LABEL_99;
            memmove(v31, v73, 20 * v29);
            if ( v73 )
              ExFreePoolWithTag(v73);
            v33 = v32;
            v73 = (unsigned int)v32;
            v28 = v74;
            v91 = v30;
          }
          v34 = &v33[v16];
          v15[3] = v15[3] & 0xFFFFFFF8 | v83 & 7;
          v15[2] = 0;
          *((_BYTE *)v15 + 16) &= 0xFEu;
          v35 = v15[1];
          v36 = v15[2];
          v37 = v15[3];
          *v34 = *v15;
          v34[1] = v35;
          v34[2] = v36;
          v34[3] = v37;
          v34[4] = v15[4];
          v10 = v77;
        }
        else
        {
          v33 = (int *)v73;
        }
        if ( v10 )
        {
          v46 = v79;
        }
        else
        {
          v38 = v78;
          if ( v78 == -1 )
          {
            if ( (a6 & 0x40) != 0 )
              *(_DWORD *)(a5 + 3848) = *(_DWORD *)(a5 + 952);
            v90 = 1;
            goto LABEL_100;
          }
          v39 = &v33[v16];
          v40 = v33[v16 + 3];
          v41 = v28 - 20;
          v16 -= 5;
          v42 = v40 ^ v33[3];
          v74 = v41;
          if ( (v42 & 7) != 0 )
          {
            v48 = *v33;
            v49 = v33[1];
            v50 = v33[2];
            v51 = v33[3];
            v52 = v79;
            v10 = 1;
            --v78;
            *v79 = v48;
            v52[1] = v49;
            v52[2] = v50;
            v52[3] = v51;
            v52[4] = v33[4];
            memmove((int)v33, (int)(v33 + 5), v41);
            v46 = v79;
          }
          else
          {
            v43 = v39[1];
            v44 = v39[2];
            v45 = v39[3];
            v46 = v79;
            *v79 = *v39;
            v46[1] = v43;
            v46[2] = v44;
            v46[3] = v45;
            v47 = v39[4];
            v10 = 1;
            v78 = v38 - 1;
            v46[4] = v47;
          }
          v53 = v83;
          if ( v83 == v46[3] << 29 >> 29 )
          {
            v54 = *(_DWORD *)(a5 + 952);
            ++v83;
            if ( v53 == 1 )
              *(_DWORD *)(a5 + 3840) = v54;
            else
              *(_DWORD *)(a5 + 3844) = v54;
          }
        }
        --v10;
        v15 = &v46[5 * v10];
        v13 = (int)v75;
        v9 = v76;
        v77 = v10;
        if ( v81 )
        {
          v13 = (int)v75;
          v9 = v76;
          if ( v10 == v89 )
          {
            v80 = 1;
            v81 = 0;
            goto LABEL_70;
          }
        }
      }
      if ( v80 )
        break;
LABEL_25:
      if ( (a6 & 0x40) == 0 )
        goto LABEL_79;
      v22 = (*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, v18, &v84);
      if ( !v22 )
        goto LABEL_99;
      v23 = *(_DWORD *)(v22 + 12);
      if ( (v23 & 2) != 0 )
      {
        v24 = 1;
      }
      else if ( (v23 & 1) != 0 )
      {
        v24 = 2;
      }
      else
      {
        v24 = 3;
      }
      if ( v24 > v83 )
      {
        *((_BYTE *)v15 + 16) |= 1u;
        (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v84);
        goto LABEL_70;
      }
      v25 = *(void (__fastcall **)(_DWORD, _DWORD))(a4 + 8);
      if ( v24 > v15[3] << 29 >> 29 )
      {
        v25(a4, &v84);
LABEL_79:
        v21 = CmpCopyKeyPartial(a4, v18, a5, v15[1], a6 | 4, v71, 2);
        if ( v21 != -1 )
        {
          v60 = 1;
          if ( (v15[4] & 2) != 0 )
            goto LABEL_83;
          if ( HvpMarkCellDirty(a5, v15[1], 0, 0) )
          {
            *((_BYTE *)v15 + 16) |= 2u;
LABEL_83:
            if ( CmpAddSubKeyEx(a5, v15[1], v21, v75[((unsigned int)v18 >> 31) + 5]) )
            {
              v61 = v15[1];
              v62 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(a5 + 4);
              v74 = -1;
              v93 = -1;
              v63 = v62(a5, v61, &v74);
              if ( v63 )
              {
                v64 = (*(int (__fastcall **)(int, int, int *))(a5 + 4))(a5, v21, &v93);
                if ( v64 )
                {
                  v65 = *(unsigned __int16 *)(v64 + 72);
                  if ( (*(_WORD *)(v64 + 2) & 0x20) != 0 )
                    v65 = (unsigned __int16)(2 * v65);
                  if ( *(unsigned __int16 *)(v63 + 52) < v65 )
                    *(_WORD *)(v63 + 52) = v65;
                  (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v93);
                  (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v74);
                  if ( !v80 || !v81 )
                  {
                    v56 = 0;
                    goto LABEL_95;
                  }
                  v56 = 0;
                  if ( CmpMarkKeyParentDirty(a5, v21) )
                  {
                    v66 = v77;
                    v80 = 0;
                    v89 = v77;
                    goto LABEL_96;
                  }
                  goto LABEL_109;
                }
                (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v74);
              }
            }
          }
        }
LABEL_99:
        v33 = (int *)v73;
LABEL_100:
        v56 = 0;
        goto LABEL_101;
      }
      v25(a4, &v84);
LABEL_70:
      v13 = (int)v75;
      v9 = v76;
    }
    v19 = (*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, v18, &v82);
    v72 = v19;
    if ( !v19 )
      goto LABEL_99;
    CmpInitializeKeyNameString(v19, v96, v9);
    v20 = (*(int (__fastcall **)(int, int, int *))(a5 + 4))(a5, v15[1], &v92);
    if ( !v20 )
      goto LABEL_99;
    CmpFindSubKeyByNameWithStatus(a5, v20, (int)v96, &v95);
    v21 = v95;
    (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v92);
    if ( v21 == -1 )
    {
      (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v82);
      v72 = 0;
      v81 = 1;
      goto LABEL_25;
    }
    v56 = (*(int (__fastcall **)(int, int, int *))(a5 + 4))(a5, v21, &v87);
    if ( !v56 )
      goto LABEL_109;
    if ( a7 != 2 )
    {
      *(_QWORD *)&v57 = *(_QWORD *)(v56 + 4);
      if ( *(__int64 *)&v57 < *(_QWORD *)(v72 + 4) )
      {
        v71 = v56;
        v58 = CmpSyncKeyValues(a4, v57, v72, a5, v21);
        v59 = v72;
        goto LABEL_76;
      }
LABEL_78:
      (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v87);
      v56 = 0;
      (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v82);
      v72 = 0;
      v60 = 0;
LABEL_95:
      v66 = v77;
LABEL_96:
      v10 = v66 + 1;
      v77 = v10;
      if ( v10 < 0x200 )
      {
        v67 = v79;
        v68 = &v79[5 * v10];
        v69 = v68[3];
        *v68 = v18;
        v68[1] = v21;
        v9 = v76;
        v68[3] = v69 & 0xFFFFFFF8;
        v11 = v67;
        v8 = v78;
        *((_BYTE *)v68 + 16) = v68[4] & 0xFC | (2 * (v60 & 1));
        v13 = (int)v75;
        continue;
      }
LABEL_109:
      v33 = (int *)v73;
LABEL_101:
      v59 = v72;
      goto LABEL_102;
    }
    break;
  }
  v59 = v72;
  v71 = v56;
  v58 = CmpMergeKeyValues(a4, v55, v72, a5, v21);
LABEL_76:
  if ( v58 )
  {
    *(_DWORD *)(v56 + 4) = *(_DWORD *)(v59 + 4);
    *(_DWORD *)(v56 + 8) = *(_DWORD *)(v59 + 8);
    goto LABEL_78;
  }
  v33 = (int *)v73;
LABEL_102:
  (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v86);
  if ( v59 )
    (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v82);
  if ( v56 )
    (*(void (__fastcall **)(int, int *))(a5 + 8))(a5, &v87);
LABEL_112:
  if ( v76 )
    ExFreePoolWithTag(v76);
  if ( v33 )
    ExFreePoolWithTag((unsigned int)v33);
  return v90;
}
