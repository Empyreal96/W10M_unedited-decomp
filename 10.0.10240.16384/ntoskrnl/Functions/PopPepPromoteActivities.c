// PopPepPromoteActivities 
 
int __fastcall PopPepPromoteActivities(int result, int a2, int a3)
{
  int v3; // r4
  int v4; // r6
  int v5; // r7
  _DWORD *v6; // r2
  int v7; // r2
  int v8; // r1
  int v9; // r5
  int v10; // r8
  int v11; // r4
  _DWORD *v12; // r2
  int v13; // r4
  int v14; // r5
  _DWORD *v15; // r2

  v3 = a3;
  v4 = a2;
  v5 = result;
  if ( !a3 )
    return result;
  if ( !a2 && a3 == 2 )
    v3 = 1;
  v6 = *(_DWORD **)(result + 48);
  if ( (*v6 & 1) != 0 )
    result = PopPepAttemptAcitivityPromotion(result, a2, (int)v6, 0, (unsigned int *)(result + 72));
  if ( v3 == 2 )
  {
    v7 = *(_DWORD *)(v4 + 8);
    v8 = v7;
    goto LABEL_7;
  }
  if ( v3 == 3 )
  {
    v8 = 0;
    v7 = *(_DWORD *)(v5 + 120) - 1;
    goto LABEL_7;
  }
  v8 = *(_DWORD *)(v5 + 120);
  v7 = 0;
  if ( !v8 )
  {
LABEL_7:
    v9 = v5 + 168 * v8 + 128;
    v10 = v7 - v8 + 1;
    do
    {
      v11 = 1;
      v4 = v9;
      do
      {
        v12 = *(_DWORD **)(v9 + 4 * v11 + 48);
        if ( (*v12 & 1) != 0 )
          result = PopPepAttemptAcitivityPromotion(v5, v9, (int)v12, v11, (unsigned int *)(v9 + 72));
        ++v11;
      }
      while ( v11 <= 3 );
      v9 += 168;
      --v10;
    }
    while ( v10 );
  }
  v13 = 4;
  v14 = v5 + 16;
  do
  {
    v15 = *(_DWORD **)(v14 + 48);
    if ( (*v15 & 1) != 0 )
      result = PopPepAttemptAcitivityPromotion(v5, v4, (int)v15, v13, (unsigned int *)(v5 + 72));
    ++v13;
    v14 += 4;
  }
  while ( v13 <= 5 );
  return result;
}
