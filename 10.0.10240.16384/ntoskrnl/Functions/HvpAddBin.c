// HvpAddBin 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall HvpAddBin(int a1, int a2, int a3)
{
  unsigned int v3; // r10
  unsigned int v4; // r5
  unsigned int v6; // r7
  unsigned int *v9; // r0
  unsigned int *v10; // r8
  int v11; // r5
  unsigned int v12; // r4
  _BYTE *v13; // r0
  int v14; // r4
  unsigned int v15; // r4
  char v16; // r3
  int v17; // r4
  int v18; // r4
  unsigned int v19; // r3
  int v20; // r10
  int v21; // r10
  __int64 v22; // r4
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r5
  unsigned int v28; // r4
  unsigned int *v29; // r0
  unsigned int v30; // r3
  unsigned int *v31; // r1 OVERLAPPED
  unsigned int **v32; // r2 OVERLAPPED
  int v33; // r5
  unsigned int v34; // r4
  char v35; // r3
  _DWORD *v36; // r0
  int *v37; // r2 OVERLAPPED
  int v38; // r1 OVERLAPPED
  int v39; // r3
  int v40; // r4
  int v41; // r1
  unsigned int v42; // r0
  int v43; // r3
  int v44; // r4
  unsigned int **v45; // r2 OVERLAPPED
  unsigned int *v46; // r1 OVERLAPPED
  unsigned int v47; // [sp+10h] [bp-70h]
  int v48; // [sp+14h] [bp-6Ch]
  unsigned int v49; // [sp+18h] [bp-68h]
  unsigned int v50; // [sp+1Ch] [bp-64h]
  int v51; // [sp+20h] [bp-60h]
  int v52; // [sp+24h] [bp-5Ch]
  _BYTE *v53; // [sp+28h] [bp-58h]
  _BYTE *v54; // [sp+2Ch] [bp-54h]
  int i; // [sp+30h] [bp-50h]
  int v56; // [sp+34h] [bp-4Ch]
  _QWORD *v57; // [sp+38h] [bp-48h]
  int v58[2]; // [sp+40h] [bp-40h] BYREF
  unsigned int v59; // [sp+48h] [bp-38h] BYREF
  unsigned int v60; // [sp+4Ch] [bp-34h] BYREF
  unsigned int v61; // [sp+50h] [bp-30h] BYREF
  unsigned int v62; // [sp+54h] [bp-2Ch] BYREF
  int v63[2]; // [sp+58h] [bp-28h] BYREF
  int v64; // [sp+60h] [bp-20h]

  i = -1;
  v58[0] = 0;
  v64 = 0;
  v62 = 0;
  v63[0] = 0;
  v50 = 0;
  v51 = 0;
  v54 = 0;
  v56 = 0;
  v57 = 0;
  v60 = 0;
  v61 = 0;
  v48 = 0;
  v59 = 0;
  v52 = 0;
  v3 = (a2 + 4127) & 0xFFFFF000;
  v4 = 0;
  v6 = 0;
  v53 = 0;
  v47 = 0;
  if ( v3 <= 0x3000 && v3 - a2 - 32 < 0xE00 )
    v3 += 4096;
  if ( *(_BYTE *)(a1 + 2560) )
    return sub_80A010();
  v9 = (unsigned int *)HvpFindFreeBin(a1, v3, a3, v58);
  v10 = v9;
  if ( !v9 )
  {
    v11 = a1 + 412 * a3;
    v6 = *(_DWORD *)(v11 + 952);
    v12 = v3 + v6;
    v47 = v3 + v6;
    v48 = v6;
    if ( !a3 && v3 <= 0x40000 && !HvpCheckViewBoundary(v6, v12 - 1) )
    {
      v12 = v3 + ((v6 + 266239) & 0xFFFC0000) - 4096;
      v47 = v12;
      v48 = ((v6 + 266239) & 0xFFFC0000) - 4096;
    }
    if ( v12 < v6 || !CmpCanGrowHive(a1, v12) || HvpExpandMap(a1, a3, v6, v12) < 0 )
      goto LABEL_25;
    v64 = 1;
    v13 = (_BYTE *)HvpAdjustHiveFreeDisplay(a1, v12, a3);
    if ( (int)v13 < 0 )
      goto LABEL_43;
    *(_DWORD *)(v11 + 952) = v12;
    if ( !a3 )
    {
      if ( (*(_DWORD *)(a1 + 92) & 1) == 0 )
      {
        LODWORD(v22) = (v12 + 511) >> 9;
        HIDWORD(v22) = *(_DWORD *)(a1 + 36);
        v50 = (((unsigned int)(v22 + 7) >> 3) + 3) & 0xFFFFFFFC;
        if ( *(_DWORD *)(a1 + 48) < v50 )
        {
          v54 = (_BYTE *)(*(int (**)(void))(a1 + 12))();
          if ( !v54 )
            goto LABEL_43;
          v25 = (*(int (__fastcall **)(unsigned int, _DWORD, int))(a1 + 12))(v50, 0, 959532355);
          v53 = (_BYTE *)v25;
          if ( !v25 )
            goto LABEL_43;
          v58[0] = v22;
          v58[1] = v25;
          v26 = *(_DWORD *)(a1 + 40);
          v63[0] = v22;
          v63[1] = (int)v54;
          if ( v26 )
          {
            RtlCopyBitMap((unsigned int *)(a1 + 36), v63, 0);
            RtlClearBits(v63, HIDWORD(v22), v22 - HIDWORD(v22));
            (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 40), *(_DWORD *)(a1 + 48));
          }
          else
          {
            memset(v54, 0, v50);
          }
          if ( *(_DWORD *)(a1 + 56) )
          {
            RtlCopyBitMap((unsigned int *)(a1 + 52), v58, 0);
            RtlClearBits(v58, HIDWORD(v22), v22 - HIDWORD(v22));
            v13 = (_BYTE *)(*(int (__fastcall **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 48));
            HIDWORD(v22) = v53;
          }
          else
          {
            HIDWORD(v22) = v53;
            v13 = memset(v53, 0, v50);
          }
          *(_DWORD *)(a1 + 36) = v22;
          *(_DWORD *)(a1 + 40) = v54;
          *(_QWORD *)(a1 + 52) = v22;
          *(_DWORD *)(a1 + 48) = v50;
          v53 = 0;
          v54 = 0;
        }
        else
        {
          v23 = *(_DWORD *)(a1 + 40);
          *(_DWORD *)(a1 + 36) = v22;
          *(_DWORD *)(a1 + 40) = v23;
          RtlClearBits((_BYTE *)(a1 + 36), HIDWORD(v22), v22 - HIDWORD(v22));
          v24 = *(_DWORD *)(a1 + 56);
          *(_DWORD *)(a1 + 52) = v22;
          *(_DWORD *)(a1 + 56) = v24;
          v13 = RtlClearBits((_BYTE *)(a1 + 52), HIDWORD(v22), v22 - HIDWORD(v22));
        }
        v12 = v47;
        v63[0] = 1;
      }
      if ( (*(_DWORD *)(a1 + 92) & 0x8001) == 0 )
      {
        CmpBoostActiveHiveWriter(v13, a1 + 3300);
        if ( CmpDoFileSetSizeEx(a1, 0, v12 + 4096, 0, 1) < 0 )
          goto LABEL_43;
        if ( (*(_DWORD *)(a1 + 3228) & 0x800) != 0 && !*(_DWORD *)(a1 + 3316) )
          *(_DWORD *)(a1 + 3316) = v6;
      }
    }
    v14 = v48;
    if ( v48 == v6 )
      goto LABEL_14;
    v33 = v48 - v6;
    if ( HvpAllocateBin(a1, v48 - v6, a3, v6, 808602947, (int *)&v62, (int *)&v61) < 0 )
    {
      v56 = v62;
      v51 = v61;
      goto LABEL_43;
    }
    v56 = v62;
    v51 = v61;
    if ( v61 )
    {
      v34 = v61;
    }
    else
    {
      v34 = v62;
      if ( v62 )
      {
        v35 = 0;
        goto LABEL_75;
      }
    }
    v35 = 1;
LABEL_75:
    if ( HvpProtectBin(a1, v33, a3, v6, v34, v35) >= 0 )
    {
      memset((_BYTE *)v34, 0, v33);
      *(_DWORD *)(v34 + 8) = v33;
      *(_DWORD *)v34 = 1852400232;
      *(_DWORD *)(v34 + 28) = 0;
      *(_DWORD *)(v34 + 4) = v6 & 0x7FFFFFFF;
      *(_DWORD *)(v34 + 32) = v33 - 32;
      v36 = (_DWORD *)(*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(20, 0, 825380163);
      v57 = v36;
      if ( v36 )
      {
        v36[3] = v6;
        v36[4] = 1;
        v36[2] = v33;
        v14 = v48;
LABEL_14:
        if ( HvpAllocateBin(a1, v3, a3, v14, 909200707, (int *)&v60, (int *)&v59) < 0 )
        {
          v49 = v59;
          v52 = v60;
LABEL_99:
          v20 = v49;
          goto LABEL_44;
        }
        v52 = v60;
        v49 = v59;
        if ( v59 )
        {
          v15 = v59;
        }
        else
        {
          v15 = v60;
          if ( v60 )
          {
            v16 = 0;
            goto LABEL_18;
          }
        }
        v16 = 1;
LABEL_18:
        if ( HvpProtectBin(a1, v3, a3, v48, v15, v16) >= 0 )
        {
          memset((_BYTE *)v15, 0, v3);
          *(_DWORD *)(v15 + 28) = 0;
          *(_DWORD *)v15 = 1852400232;
          *(_DWORD *)(v15 + 4) = v48 & 0x7FFFFFFF;
          *(_DWORD *)(v15 + 8) = v3;
          *(_DWORD *)(v15 + 32) = v3 - 32;
          if ( v56 || v51 )
          {
            v17 = v48;
            HvpPointMapEntriesToBuffer(a1, v56, v51, v48 - v6, v6 + (a3 << 31), (unsigned int)v57);
            v37 = (int *)(a1 + 412 * a3 + 1352);
            v38 = *v37;
            *v57 = *(_QWORD *)&v38;
            if ( *(int **)(v38 + 4) != v37 )
              __fastfail(3u);
            *(_DWORD *)(v38 + 4) = v57;
            *v37 = (int)v57;
          }
          else
          {
            v17 = v48;
          }
          v18 = v17 + (a3 << 31);
          v19 = v3;
          v20 = v49;
          v48 = v18;
          HvpPointMapEntriesToBuffer(a1, v52, v49, v19, v18, 0);
          v4 = v47;
          if ( a3 )
            goto LABEL_23;
          if ( (*(_DWORD *)(a1 + 92) & 1) != 0 || HvpMarkDirty(a1, v6, v47 - v6) )
          {
            CmpUpdateSystemHiveHysteresis(a1, v47, v6);
            HvpSetRangeProtection(a1, v6, v47 - v6, 4);
LABEL_23:
            v51 = 0;
            v52 = 0;
            v21 = v18;
            i = v18;
            v56 = 0;
            v57 = 0;
            goto LABEL_24;
          }
LABEL_45:
          HvpShrinkMap(a1, a3, v4, v6);
          *(_DWORD *)(a1 + 412 * a3 + 952) = v6;
LABEL_87:
          if ( v63[0] )
          {
            v39 = *(_DWORD *)(a1 + 40);
            *(_DWORD *)(a1 + 36) = v6 >> 9;
            *(_DWORD *)(a1 + 40) = v39;
            v40 = *(_DWORD *)(a1 + 44);
            *(_DWORD *)(a1 + 44) = RtlNumberOfSetBits((unsigned int *)(a1 + 36));
            __dmb(0xBu);
            v41 = *(_DWORD *)(a1 + 44) - v40;
            do
              v42 = __ldrex((unsigned int *)&CmpDirtySectorCount);
            while ( __strex(v42 + v41, (unsigned int *)&CmpDirtySectorCount) );
            __dmb(0xBu);
            v43 = *(_DWORD *)(a1 + 56);
            *(_DWORD *)(a1 + 52) = v6 >> 9;
            *(_DWORD *)(a1 + 56) = v43;
            v4 = v47;
            *(_DWORD *)(a1 + 60) = RtlNumberOfSetBits((unsigned int *)(a1 + 52));
          }
          if ( v53 )
            (*(void (__fastcall **)(_BYTE *, unsigned int))(a1 + 16))(v53, v50);
          if ( v54 )
            (*(void (__fastcall **)(_BYTE *, unsigned int))(a1 + 16))(v54, v50);
          if ( v56 || v51 )
          {
            v44 = v48;
            HvpFreeBin(a1, v48 - v6, a3, v56, v51);
          }
          else
          {
            v44 = v48;
          }
          if ( v57 )
            (*(void (__fastcall **)(_QWORD *, int))(a1 + 16))(v57, 20);
          if ( v52 || v20 )
            HvpFreeBin(a1, v4 - v44, a3, v52, v20);
          goto LABEL_25;
        }
        goto LABEL_99;
      }
    }
LABEL_43:
    v20 = 0;
LABEL_44:
    v4 = v47;
    goto LABEL_45;
  }
  *(_QWORD *)&v31 = *(_QWORD *)v9;
  if ( *(unsigned int **)(*v9 + 4) != v9 || *v32 != v9 )
    __fastfail(3u);
  *v32 = v31;
  v31[1] = (unsigned int)v32;
  if ( !HvpMarkDirty(a1, v9[3] + (a3 << 31), v9[2]) )
    goto LABEL_25;
  if ( (v10[4] & 1) != 0 )
  {
    v27 = v58[0];
    v21 = v10[3] + (a3 << 31);
    v28 = 0;
    for ( i = v21; v28 < v27; v29[1] = v30 & 0xFFFFFFFD )
    {
      v29 = (unsigned int *)HvpGetCellMap(a1, v28 + v21);
      if ( !v29 )
        KeBugCheckEx(81, 1, a1, v28 + v21, 909);
      v30 = v29[1];
      *v29 = v28;
      v28 += 4096;
    }
    if ( !a3 )
      HvpSetRangeProtection(a1, v21, v27, 4);
    v4 = 0;
  }
  else
  {
    if ( HvpReviveDiscardedBin(a1, v10, v58[0], a3) < 0 )
      goto LABEL_25;
    v21 = v10[3] + (a3 << 31);
    i = v21;
  }
LABEL_24:
  if ( v21 == -1 )
  {
    v20 = 0;
    if ( !v64 )
      goto LABEL_87;
    goto LABEL_45;
  }
LABEL_25:
  if ( v10 )
  {
    if ( i == -1 )
    {
      v45 = (unsigned int **)(a1 + 412 * a3 + 1352);
      v46 = *v45;
      *(_QWORD *)v10 = *(_QWORD *)&v46;
      if ( (unsigned int **)v46[1] != v45 )
        __fastfail(3u);
      v46[1] = (unsigned int)v10;
      *v45 = v10;
    }
    else
    {
      (*(void (__fastcall **)(unsigned int *, int))(a1 + 16))(v10, 20);
    }
  }
  return i;
}
