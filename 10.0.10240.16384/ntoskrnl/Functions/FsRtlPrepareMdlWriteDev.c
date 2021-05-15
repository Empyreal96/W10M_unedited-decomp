// FsRtlPrepareMdlWriteDev 
 
int __fastcall FsRtlPrepareMdlWriteDev(_DWORD *a1, _DWORD *a2, unsigned int a3, int a4, int *a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // r8
  int v9; // r6
  BOOL v10; // r4
  int v11; // r5
  int v12; // r2
  int v13; // r3
  __int64 v14; // kr00_8
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r8
  unsigned int v20; // r9
  signed __int64 v21; // kr08_8
  int v22; // r2
  unsigned int v23; // r1
  int v24; // r2
  int v25; // r3
  unsigned int v26; // r0
  __int64 v27; // r2
  int v28; // r4
  int v29; // r0
  int v30; // r2
  __int64 v31; // r2
  int v32; // r0
  int v33; // r3
  int v34; // r0
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  int v43; // [sp+18h] [bp-58h]
  int v45; // [sp+1Ch] [bp-54h]
  int v47; // [sp+20h] [bp-50h]
  int v48; // [sp+24h] [bp-4Ch]
  int v49; // [sp+24h] [bp-4Ch]
  __int64 v50; // [sp+30h] [bp-40h] BYREF
  int v51; // [sp+38h] [bp-38h]
  int v52; // [sp+3Ch] [bp-34h]
  int v53; // [sp+40h] [bp-30h]
  int v54; // [sp+44h] [bp-2Ch]
  __int64 v55; // [sp+48h] [bp-28h]
  _DWORD *varg_r0; // [sp+78h] [bp+8h]
  _DWORD *varg_r1; // [sp+7Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = a2;
  varg_r0 = a1;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v9 = 1;
  v48 = 0;
  v43 = 0;
  v10 = *a2 == -1 && a2[1] == -1;
  if ( IoGetTopLevelIrp() || !CcCanIWrite((int)a1, a3, 1, 0) || (a1[11] & 0x10) != 0 )
    return 0;
  *a6 = 0;
  if ( !a3 )
    return 1;
  v11 = a1[3];
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(__int16 *)(v12 + 0x134) - 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( v10 || (v14 = *(_QWORD *)v7 + a3, v12 = HIDWORD(v14), v13 = *(_DWORD *)(v11 + 36), v14 > *(_QWORD *)(v11 + 32)) )
  {
    ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 8), 1, v12, v13);
  }
  else
  {
    ExAcquireResourceSharedLite(*(_DWORD *)(v11 + 8), 1);
    v48 = 1;
  }
  if ( v10 )
  {
    v15 = *(_DWORD *)(v11 + 24);
    LODWORD(v50) = v15;
    v16 = *(_DWORD *)(v11 + 28);
    HIDWORD(v50) = v16;
    v17 = *(_DWORD *)(v11 + 24);
    v18 = *(_DWORD *)(v11 + 28);
  }
  else
  {
    LODWORD(v50) = *v7;
    v15 = v50;
    v16 = v7[1];
    HIDWORD(v50) = v16;
    v17 = v50;
    v18 = v16;
  }
  v21 = __PAIR64__(v18, a3) + v17;
  v19 = HIDWORD(v21);
  v20 = v21;
  v55 = v21;
  if ( !a1[6] )
    goto LABEL_60;
  v22 = *(unsigned __int8 *)(v11 + 5);
  if ( !*(_BYTE *)(v11 + 5) )
    goto LABEL_60;
  v23 = -1 - v15;
  if ( (int)(0x7FFFFFFF - v16) < 0 || (int)(0x7FFFFFFF - v16) <= 0 && v23 < a3 )
    goto LABEL_60;
  if ( v21 > *(_QWORD *)(v11 + 16) )
    goto LABEL_60;
  if ( v48 && v21 > *(_QWORD *)(v11 + 32) )
  {
    ExReleaseResourceLite(*(_DWORD *)(v11 + 8));
    ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 8), 1, v24, v25);
    v26 = a3;
    if ( v10 )
    {
      v50 = *(_QWORD *)(v11 + 24);
      v55 = *(_QWORD *)(v11 + 24) + a3;
      v19 = HIDWORD(v55);
      v20 = v55;
    }
    if ( !a1[6] )
      goto LABEL_60;
    v22 = *(unsigned __int8 *)(v11 + 5);
    if ( !*(_BYTE *)(v11 + 5) || __SPAIR64__(v19, v20) > *(_QWORD *)(v11 + 16) )
      goto LABEL_60;
  }
  else
  {
    v26 = a3;
  }
  if ( v22 == 2
    && !(*(int (__fastcall **)(_DWORD *, _DWORD *, unsigned int, int, int, _DWORD, _DWORD *, int, _BYTE))(*(_DWORD *)(*(_DWORD *)(a7 + 8) + 40) + 4))(
          a1,
          a2,
          v26,
          1,
          a4,
          0,
          a6,
          a7,
          0) )
  {
LABEL_60:
    v38 = ExReleaseResourceLite(*(_DWORD *)(v11 + 8));
    v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v40 = *(_WORD *)(v39 + 0x134) + 1;
    *(_WORD *)(v39 + 308) = v40;
    if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
      KiCheckForKernelApcDelivery(v38);
    return 0;
  }
  v27 = *(_QWORD *)(v11 + 24);
  if ( __SPAIR64__(v19, v20) <= v27 )
  {
    v45 = v52;
    v28 = v51;
    v49 = v54;
    v47 = v53;
  }
  else
  {
    v43 = 1;
    v28 = *(_DWORD *)(v11 + 24);
    v51 = v28;
    v45 = *(_DWORD *)(v11 + 28);
    v52 = v45;
    v47 = *(_DWORD *)(v11 + 32);
    v53 = v47;
    v49 = *(_DWORD *)(v11 + 36);
    v54 = v49;
    HIDWORD(v27) = *(_DWORD *)(v11 + 28);
    if ( HIDWORD(v27) == v19 || (v29 = *(_DWORD *)(v11 + 12)) == 0 )
    {
      *(_DWORD *)(v11 + 24) = v20;
      *(_DWORD *)(v11 + 28) = v19;
    }
    else
    {
      ExAcquireResourceExclusiveLite(v29, 1, v27, SHIDWORD(v27));
      *(_DWORD *)(v11 + 24) = v20;
      *(_DWORD *)(v11 + 28) = v19;
      ExReleaseResourceLite(*(_DWORD *)(v11 + 12));
    }
  }
  IoSetTopLevelIrp(4);
  if ( v50 > *(_QWORD *)(v11 + 32) )
    v9 = CcZeroData(a1, (int *)(v11 + 32), &v50, 1);
  if ( v9 )
    CcPrepareMdlWrite((int)a1, &v50, a3, a5, a6);
  IoSetTopLevelIrp(0);
  if ( v9 )
  {
    v31 = *(_QWORD *)(v11 + 32);
    if ( __SPAIR64__(v19, v20) > v31 )
    {
      HIDWORD(v31) = *(_DWORD *)(v11 + 36);
      if ( HIDWORD(v31) == v19 || (v32 = *(_DWORD *)(v11 + 12)) == 0 )
      {
        *(_DWORD *)(v11 + 32) = v20;
        *(_DWORD *)(v11 + 36) = v19;
      }
      else
      {
        ExAcquireResourceExclusiveLite(v32, 1, v31, SHIDWORD(v31));
        *(_DWORD *)(v11 + 32) = v20;
        *(_DWORD *)(v11 + 36) = v19;
        ExReleaseResourceLite(*(_DWORD *)(v11 + 12));
      }
    }
    a1[11] |= 0x1000u;
    if ( v43 )
    {
      v33 = *(_DWORD *)(a1[5] + 4);
      *(_DWORD *)(v33 + 8) = v20;
      *(_DWORD *)(v33 + 12) = v19;
      a1[11] |= 0x2000u;
    }
  }
  else if ( v43 )
  {
    v34 = *(_DWORD *)(v11 + 12);
    if ( v34 )
    {
      ExAcquireResourceExclusiveLite(v34, 1, v30, v43);
      *(_DWORD *)(v11 + 24) = v28;
      *(_DWORD *)(v11 + 28) = v45;
      *(_DWORD *)(v11 + 32) = v47;
      *(_DWORD *)(v11 + 36) = v49;
      ExReleaseResourceLite(*(_DWORD *)(v11 + 12));
    }
    else
    {
      *(_DWORD *)(v11 + 24) = v28;
      *(_DWORD *)(v11 + 28) = v45;
      *(_DWORD *)(v11 + 32) = v47;
      *(_DWORD *)(v11 + 36) = v49;
    }
  }
  v35 = ExReleaseResourceLite(*(_DWORD *)(v11 + 8));
  v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v37 = *(_WORD *)(v36 + 0x134) + 1;
  *(_WORD *)(v36 + 308) = v37;
  if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
    KiCheckForKernelApcDelivery(v35);
  return v9;
}
