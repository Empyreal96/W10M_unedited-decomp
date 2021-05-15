// FsRtlCopyWrite 
 
int __fastcall FsRtlCopyWrite(int a1, _DWORD *a2, unsigned int a3, int a4, int a5, int a6, _DWORD *a7, int a8)
{
  int v8; // r9
  _DWORD *v9; // r8
  BOOL v10; // r4
  int v11; // r5
  int v12; // r2
  int v13; // r3
  __int64 v14; // kr08_8
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  unsigned int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r9
  unsigned int v21; // r10
  signed __int64 v22; // kr18_8
  int v23; // r1
  unsigned int v24; // lr
  unsigned int v25; // r0
  int v26; // r6
  int v27; // r8
  int v28; // r2
  int v29; // r3
  unsigned int v30; // lr
  _DWORD *v31; // r0
  __int64 v32; // r2
  int v33; // r4
  int v34; // r0
  int v35; // r2
  __int64 v36; // r2
  int v37; // r0
  int v38; // r3
  int v39; // r0
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  signed __int64 v46; // [sp+1Ch] [bp-64h]
  int v47; // [sp+24h] [bp-5Ch]
  int v49; // [sp+28h] [bp-58h]
  int v51; // [sp+2Ch] [bp-54h]
  _DWORD v52[4]; // [sp+30h] [bp-50h] BYREF
  signed __int64 v53; // [sp+40h] [bp-40h] BYREF
  int v54; // [sp+48h] [bp-38h]
  int v55; // [sp+4Ch] [bp-34h]
  int v56; // [sp+50h] [bp-30h]
  int v57; // [sp+54h] [bp-2Ch]
  __int64 v58; // [sp+58h] [bp-28h]
  int varg_r0; // [sp+88h] [bp+8h]
  _DWORD *varg_r1; // [sp+8Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+90h] [bp+10h]
  int varg_r3; // [sp+94h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v8 = (int)a2;
  v9 = (_DWORD *)a1;
  varg_r0 = a1;
  v52[0] = 0;
  v47 = 0;
  v10 = *a2 == -1 && a2[1] == -1;
  if ( IoGetTopLevelIrp() )
    return 0;
  v11 = v9[3];
  v52[2] = v11;
  if ( !CcCanIWrite((int)v9, a3, a4, 0) || (v9[11] & 0x10) != 0 || !CcCopyWriteWontFlush((int)v9, v8, a3) )
    return 0;
  *a7 = 0;
  a7[1] = a3;
  if ( !a3 )
    return 1;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(__int16 *)(v12 + 0x134) - 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( v10 || (v14 = *(_QWORD *)v8 + a3, v12 = HIDWORD(v14), v13 = *(_DWORD *)(v11 + 36), v14 > *(_QWORD *)(v11 + 32)) )
  {
    v15 = ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 8), a4, v12, v13);
    if ( !v15 )
      goto LABEL_13;
  }
  else
  {
    v15 = ExAcquireResourceSharedLite(*(_DWORD *)(v11 + 8), a4);
    if ( !v15 )
    {
LABEL_13:
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
      *(_WORD *)(v16 + 308) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v15);
      return 0;
    }
    v52[0] = 1;
  }
  if ( v10 )
  {
    LODWORD(v46) = *(_DWORD *)(v11 + 24);
    LODWORD(v53) = v46;
    HIDWORD(v46) = *(_DWORD *)(v11 + 28);
    HIDWORD(v53) = HIDWORD(v46);
    v18 = *(_DWORD *)(v11 + 24);
    v19 = HIDWORD(v46);
  }
  else
  {
    v46 = *(_QWORD *)v8;
    v53 = *(_QWORD *)v8;
    v18 = *(_DWORD *)v8;
    v19 = *(_DWORD *)(v8 + 4);
  }
  v22 = __PAIR64__(v19, a3) + v18;
  v20 = HIDWORD(v22);
  v21 = v22;
  v58 = v22;
  if ( !v9[6]
    || (v23 = *(unsigned __int8 *)(v11 + 5), !*(_BYTE *)(v11 + 5))
    || (v24 = *(_DWORD *)(v11 + 32),
        v25 = *(_DWORD *)(v11 + 36),
        v26 = 1,
        v46 >= (__int64)(__PAIR64__(v25, v24) + 0x2000))
    || (v27 = a1, 0x7FFFFFFF - HIDWORD(v46) < 0)
    || 0x7FFFFFFF - HIDWORD(v46) <= 0 && -1 - (int)v46 < a3
    || v22 > *(_QWORD *)(v11 + 16) )
  {
LABEL_37:
    v15 = ExReleaseResourceLite(*(_DWORD *)(v11 + 8));
    goto LABEL_13;
  }
  if ( v52[0] && v22 > __SPAIR64__(v25, v24) )
  {
    ExReleaseResourceLite(*(_DWORD *)(v11 + 8));
    v15 = ExAcquireResourceExclusiveLite(*(_DWORD *)(v11 + 8), a4, v28, v29);
    if ( !v15 )
      goto LABEL_13;
    v30 = a3;
    if ( v10 )
    {
      LODWORD(v46) = *(_DWORD *)(v11 + 24);
      LODWORD(v53) = v46;
      HIDWORD(v46) = *(_DWORD *)(v11 + 28);
      HIDWORD(v53) = HIDWORD(v46);
      v58 = *(_QWORD *)(v11 + 24) + a3;
      v20 = HIDWORD(v58);
      v21 = v58;
    }
    if ( !*(_DWORD *)(a1 + 24) )
      goto LABEL_37;
    v23 = *(unsigned __int8 *)(v11 + 5);
    if ( !*(_BYTE *)(v11 + 5) || __SPAIR64__(v20, v21) > *(_QWORD *)(v11 + 16) )
      goto LABEL_37;
  }
  else
  {
    v30 = a3;
  }
  if ( v23 == 2 )
  {
    v31 = a2;
    if ( (v31[1] & *v31) == -1 )
      v31 = (_DWORD *)(v11 + 24);
    if ( !(*(int (__fastcall **)(int, _DWORD *, unsigned int, int, int, _DWORD, _DWORD *, int))(*(_DWORD *)(*(_DWORD *)(a8 + 8) + 40)
                                                                                              + 4))(
            a1,
            v31,
            v30,
            a4,
            a5,
            0,
            v52,
            a8) )
      goto LABEL_37;
  }
  v32 = *(_QWORD *)(v11 + 24);
  if ( __SPAIR64__(v20, v21) <= v32 )
  {
    v49 = v55;
    v33 = v54;
    v52[0] = v57;
    v51 = v56;
  }
  else
  {
    v47 = 1;
    v33 = *(_DWORD *)(v11 + 24);
    v54 = v33;
    v49 = *(_DWORD *)(v11 + 28);
    v55 = v49;
    v51 = *(_DWORD *)(v11 + 32);
    v56 = v51;
    v52[0] = *(_DWORD *)(v11 + 36);
    v57 = v52[0];
    HIDWORD(v32) = *(_DWORD *)(v11 + 28);
    if ( HIDWORD(v32) == v20 || (v34 = *(_DWORD *)(v11 + 12)) == 0 )
    {
      *(_DWORD *)(v11 + 24) = v21;
      *(_DWORD *)(v11 + 28) = v20;
    }
    else
    {
      ExAcquireResourceExclusiveLite(v34, 1, v32, SHIDWORD(v32));
      *(_DWORD *)(v11 + 24) = v21;
      *(_DWORD *)(v11 + 28) = v20;
      ExReleaseResourceLite(*(_DWORD *)(v11 + 12));
    }
  }
  IoSetTopLevelIrp(4);
  if ( v46 > *(_QWORD *)(v11 + 32) )
    v26 = CcZeroData(v27, v11 + 32, &v53, a4);
  if ( v26 )
    v26 = CcCopyWrite();
  IoSetTopLevelIrp(0);
  if ( v26 )
  {
    v36 = *(_QWORD *)(v11 + 32);
    if ( __SPAIR64__(v20, v21) > v36 )
    {
      HIDWORD(v36) = *(_DWORD *)(v11 + 36);
      if ( HIDWORD(v36) == v20 || (v37 = *(_DWORD *)(v11 + 12)) == 0 )
      {
        *(_DWORD *)(v11 + 32) = v21;
        *(_DWORD *)(v11 + 36) = v20;
      }
      else
      {
        ExAcquireResourceExclusiveLite(v37, 1, v36, SHIDWORD(v36));
        *(_DWORD *)(v11 + 32) = v21;
        *(_DWORD *)(v11 + 36) = v20;
        ExReleaseResourceLite(*(_DWORD *)(v11 + 12));
      }
    }
    *(_DWORD *)(v27 + 44) |= 0x1000u;
    if ( v47 )
    {
      v38 = *(_DWORD *)(*(_DWORD *)(v27 + 20) + 4);
      *(_DWORD *)(v38 + 8) = v21;
      *(_DWORD *)(v38 + 12) = v20;
      *(_DWORD *)(v27 + 44) |= 0x2000u;
    }
    *(_QWORD *)(v27 + 56) = v46 + a3;
  }
  else if ( v47 )
  {
    v39 = *(_DWORD *)(v11 + 12);
    if ( v39 )
    {
      ExAcquireResourceExclusiveLite(v39, 1, v35, v47);
      *(_DWORD *)(v11 + 24) = v33;
      *(_DWORD *)(v11 + 28) = v49;
      *(_DWORD *)(v11 + 32) = v51;
      *(_DWORD *)(v11 + 36) = v52[0];
      ExReleaseResourceLite(*(_DWORD *)(v11 + 12));
    }
    else
    {
      *(_DWORD *)(v11 + 24) = v33;
      *(_DWORD *)(v11 + 28) = v49;
      *(_DWORD *)(v11 + 32) = v51;
      *(_DWORD *)(v11 + 36) = v52[0];
    }
  }
  v40 = ExReleaseResourceLite(*(_DWORD *)(v11 + 8));
  v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v42 = *(_WORD *)(v41 + 0x134) + 1;
  *(_WORD *)(v41 + 308) = v42;
  if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
    KiCheckForKernelApcDelivery(v40);
  return v26;
}
