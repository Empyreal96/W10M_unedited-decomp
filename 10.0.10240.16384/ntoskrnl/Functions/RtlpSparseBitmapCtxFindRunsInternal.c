// RtlpSparseBitmapCtxFindRunsInternal 
 
int __fastcall RtlpSparseBitmapCtxFindRunsInternal(_DWORD *a1, unsigned __int64 a2, int a3, int a4, int a5, int a6)
{
  unsigned int v8; // r4
  int v9; // r6
  int v10; // r10
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r9
  unsigned int v16; // r0
  int v17; // lr
  int v18; // r3
  int v19; // r4
  int v20; // r7
  __int64 v21; // r2
  int v22; // r7
  int v23; // r0
  __int64 v24; // kr08_8
  int v26; // [sp+0h] [bp-58h]
  int v27; // [sp+18h] [bp-40h]
  __int64 v28; // [sp+1Ch] [bp-3Ch]
  int v29; // [sp+28h] [bp-30h]
  int v30; // [sp+30h] [bp-28h]

  v8 = a1[8];
  v9 = a6;
  v10 = 1;
  v29 = 0;
  v27 = 0;
  if ( !v8 )
    __brkdiv0();
  v11 = _rt_udiv64(v8, a2);
  v30 = v13;
  v14 = v8 * v11;
  v15 = v11;
  v16 = 0;
  v28 = (unsigned int)v14;
  v17 = v13;
  if ( v15 < a1[7] )
  {
    do
    {
      v18 = a1[1];
      v19 = 0;
      if ( v18 && (v19 = *(_DWORD *)(v18 + 4 * v15)) != 0 )
      {
        v20 = 1;
        v27 = 1;
        v17 = v30;
        v29 = RtlpSparseBitmapCtxLockShared(a1, *(_DWORD *)(v18 + 4 * v15));
        v16 = HIDWORD(v28);
      }
      else
      {
        v20 = v27;
      }
      if ( v9 == a6
        || (v12 = *(_DWORD *)(v9 - 8)) != 0
        || (LODWORD(v21) = *(_DWORD *)(v9 - 12),
            HIDWORD(v21) = *(_DWORD *)(v9 - 16),
            v20 = v27,
            v21 != __PAIR64__(v28, v16))
        || (v17 = RtlpSparseBitmapCtxAppendNextRangeToRun((int)a1, v19, v15, v9 - 16, v26, 1), v17 != a1[8]) )
      {
        if ( !v10 )
          goto LABEL_22;
        if ( v19 )
          v23 = RtlpSparseBitmapCtxFindRunsFromRange(a1, v12, 1u, v10, v9, v15, v17, v19, 0);
        else
          v23 = RtlpSparseBitmapCtxFindRunsFromNullRange(a1, v12, 1u, v10, v9, v15, v17, 0);
        v22 = v23;
      }
      else
      {
        v22 = 0;
      }
      if ( v27 )
      {
        RtlpSparseBitmapCtxUnlockShared(a1, v19, v29);
        v27 = 0;
      }
      v9 += 16 * v22;
      v10 -= v22;
      v17 = 0;
      ++v15;
      v24 = v28 + (unsigned int)a1[8];
      v16 = HIDWORD(v24);
      v28 = v24;
      v30 = 0;
    }
    while ( v15 < a1[7] );
    v20 = v27;
LABEL_22:
    if ( v20 )
      RtlpSparseBitmapCtxUnlockShared(a1, v19, v29);
  }
  return (v9 - a6) >> 4;
}
