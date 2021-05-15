// PpmIdleCheckCoordinatedStateEligibility 
 
__int64 __fastcall PpmIdleCheckCoordinatedStateEligibility(int a1, int a2, unsigned int a3, int a4, unsigned __int64 a5, int a6, _DWORD *a7, int a8)
{
  int v8; // r4
  int v10; // r6
  int v11; // r10
  __int64 v12; // r4
  __int64 v13; // r0
  int v17; // [sp+28h] [bp-20h]

  v8 = *(_DWORD *)(a1 + 2944);
  v10 = PpmPlatformStates + (a6 << 8) + 128;
  v11 = v8 + 68;
  v17 = *(_DWORD *)(a8 + 4);
  if ( *(_BYTE *)(PpmPlatformStates + (a6 << 8) + 157) )
  {
    if ( !*(_BYTE *)(v8 + 172) )
    {
LABEL_3:
      LODWORD(v12) = -1;
LABEL_4:
      HIDWORD(v12) = 0;
LABEL_23:
      PpmIdleRollbackCoordinatedSelection(a8, v17);
      return v12;
    }
  }
  else if ( (*(_DWORD *)(v8 + 208) & *(_DWORD *)(PpmPlatformStates + (a6 << 8) + 172)) != *(_DWORD *)(PpmPlatformStates + (a6 << 8) + 172) )
  {
    goto LABEL_3;
  }
  if ( !PpmClaimCoordinatedIdleState((unsigned int *)(PpmPlatformStates + (a6 << 8) + 188)) )
    goto LABEL_3;
  *(_DWORD *)(*(_DWORD *)(a8 + 12) + 4 * (*(_DWORD *)(a8 + 4))++) = a6;
  LODWORD(v12) = PpmCheckIdleVeto((_DWORD *)(v10 + 8));
  if ( (_DWORD)v12 )
  {
    HIDWORD(v12) = 1;
    goto LABEL_22;
  }
  if ( *(_DWORD *)v10 > a3 )
  {
    LODWORD(v12) = -2147483646;
    goto LABEL_4;
  }
  if ( *(_DWORD *)(v10 + 128) )
  {
    LODWORD(v12) = -2147483644;
    goto LABEL_4;
  }
  if ( *(unsigned int *)(v10 + 4) > a5 )
  {
    LODWORD(v12) = -2147483645;
    goto LABEL_4;
  }
  LODWORD(v13) = PpmIdleCheckCoordinatedDependencies(
                   a1,
                   a2,
                   a3 - *(_DWORD *)v10,
                   *(_DWORD *)v10,
                   a5,
                   SHIDWORD(a5),
                   *(_DWORD *)(v10 + 32),
                   *(unsigned int **)(v10 + 56),
                   (int)a7,
                   a8,
                   v11);
  v12 = v13;
  if ( v13 )
    goto LABEL_23;
  if ( *a7 == -1 )
  {
    LODWORD(v12) = -2147483647;
    goto LABEL_4;
  }
  if ( PpmIdleWaitForDependentTransitions(v11) < 0 )
  {
    LODWORD(v12) = -2147483643;
    goto LABEL_4;
  }
  if ( *(_DWORD *)(v10 + 128) )
  {
    v12 = 2147483652i64;
LABEL_22:
    if ( v12 )
      goto LABEL_23;
  }
  return v12;
}
