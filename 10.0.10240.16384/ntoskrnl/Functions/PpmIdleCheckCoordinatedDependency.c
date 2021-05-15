// PpmIdleCheckCoordinatedDependency 
 
__int64 __fastcall PpmIdleCheckCoordinatedDependency(int a1, int a2, unsigned int a3, int a4, int a5, int a6, _DWORD *a7, _DWORD *a8, int a9, int a10)
{
  unsigned int v10; // lr
  _DWORD *v11; // r2
  int v12; // r8
  __int64 v13; // r4
  int v14; // r1
  int i; // r10
  int v16; // r6
  _DWORD *v17; // r7
  unsigned int v18; // r2
  __int64 v19; // r0
  unsigned int v20; // r6
  unsigned int v21; // r2
  _DWORD *v22; // r0
  _DWORD *v24; // [sp+20h] [bp-38h]
  unsigned int v25; // [sp+24h] [bp-34h]
  int v26; // [sp+28h] [bp-30h]
  int v28; // [sp+34h] [bp-24h]

  v25 = a3;
  v26 = 0;
  v10 = a3;
  v11 = a7;
  v24 = (_DWORD *)a1;
  v12 = *(_DWORD *)(PpmPlatformStates + (*(_DWORD *)(a7[1] + 4) << 8) + 172) >> *(_DWORD *)(a1 + 20);
  v28 = 0;
  v13 = 2147483649i64;
  if ( !*a7 )
    return v13;
  v14 = a10;
  for ( i = 0; ; i += 16 )
  {
    v16 = i + v11[1];
    v17 = (_DWORD *)(PpmPlatformStates + (*(_DWORD *)(v16 + 4) << 8));
    if ( (v12 & 1) == 0 )
      break;
    v26 = *(_DWORD *)(a9 + 4);
    if ( !*(_BYTE *)(v16 + 1) )
      goto LABEL_27;
    v13 = PpmIdleCheckCoordinatedStateEligibility(a1, a2, v10);
    if ( !v13 )
      goto LABEL_16;
    PpmIdleRollbackCoordinatedSelection(a9, v26);
LABEL_26:
    v14 = a10;
    a1 = (int)v24;
    v10 = v25;
LABEL_27:
    v11 = a7;
    if ( (unsigned int)++v28 >= *a7 )
      return v13;
  }
  if ( !*(_BYTE *)(v16 + 2) )
    goto LABEL_27;
  if ( (v17[47] & 0x40000000) == 0 )
  {
    LODWORD(v13) = -2147483637;
LABEL_11:
    HIDWORD(v13) = 0;
    goto LABEL_27;
  }
  v18 = v17[32];
  if ( v18 > v10 )
  {
    LODWORD(v13) = -2147483646;
    goto LABEL_11;
  }
  LODWORD(v19) = PpmIdleCheckCoordinatedDependencies(
                   a1,
                   a2,
                   v18 - v10,
                   a6,
                   a5,
                   a6,
                   *(_DWORD *)(v16 + 8),
                   *(unsigned int **)(v16 + 12),
                   0,
                   0,
                   v14);
  v13 = v19;
  if ( v19 )
    goto LABEL_26;
LABEL_16:
  if ( *(_BYTE *)v16 )
  {
    v20 = v17[43];
    v13 = 0i64;
    while ( v20 )
    {
      v21 = __clz(__rbit(v20));
      v20 &= ~(1 << v21);
      if ( v21 >= KeNumberProcessors_0 )
        v22 = 0;
      else
        v22 = *(&KiProcessorBlock + v21);
      if ( v24 != v22 && PpmTestAndLockProcessor(v22, a10, 0) < 0 )
      {
        v13 = 2147483653i64;
        if ( (v12 & 1) != 0 )
          PpmIdleRollbackCoordinatedSelection(a9, v26);
        goto LABEL_26;
      }
    }
  }
  if ( (v12 & 1) != 0 )
    *a8 = -1;
  return v13;
}
