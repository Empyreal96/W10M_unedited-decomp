// HvCheckBin 
 
int __fastcall HvCheckBin(int a1, int a2, _DWORD *a3, _BYTE *a4, _DWORD *a5)
{
  int v6; // r2
  int v8; // r3
  unsigned int v10; // r9
  int v11; // lr
  unsigned int v12; // r0
  int v13; // r6
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r5
  int result; // r0
  int v19; // r2
  int v20; // r1
  int v21; // r3
  int v22; // r3
  _DWORD *v23; // r0
  int v24; // [sp+8h] [bp-30h]
  int v25; // [sp+Ch] [bp-2Ch]
  unsigned int v26; // [sp+10h] [bp-28h]
  _DWORD *v27; // [sp+14h] [bp-24h]

  v6 = *(_DWORD *)(a1 + 28);
  v8 = 0;
  v24 = v6;
  v25 = 0;
  v26 = 0;
  v27 = a3;
  v10 = 0;
  v11 = 0;
  if ( v6 )
    *(_DWORD *)(v6 + 276) = a2;
  v12 = *(_DWORD *)(a2 + 8);
  v13 = a2 + 32;
  v14 = v12 + a2;
  if ( a2 + 32 >= v12 + a2 )
  {
LABEL_14:
    v19 = *(_DWORD *)(a2 + 8);
    if ( v8 + v10 + 32 == v19 )
    {
      if ( v13 == v19 + a2 )
      {
        if ( a3 )
          *a3 += v11;
        result = 0;
      }
      else
      {
        SetFailureLocation(v24, 0, 17, 1000, 112);
        result = 1000;
      }
    }
    else
    {
      SetFailureLocation(v24, 0, 17, 995, 96);
      result = 995;
    }
    return result;
  }
  while ( 1 )
  {
    v15 = *(_DWORD *)v13;
    if ( *(int *)v13 < 0 )
    {
      v16 = -v15;
      if ( -v15 > v12 || (v17 = v13 - v15, v13 - v15 > v14) )
      {
        if ( v24 )
        {
          SetFailureLocation(v24, 0, 17, 40, 32);
          *(_DWORD *)(v24 + 280) = v13;
        }
        return 40;
      }
      v10 -= v15;
      v25 = v11 - v15 - 4;
      if ( v10 > v12 )
        return sub_80153C();
      if ( v16 < 0x54 || !a5 || *(_WORD *)(v13 + 4) != 27502 )
        goto LABEL_10;
      v20 = 8 * *(_DWORD *)(v13 + 24) + 20;
      v21 = *(_DWORD *)(v13 + 16);
      if ( (v21 & 2) != 0 )
      {
        HvMoveLayoutStats(a5 + 8);
        HvMoveLayoutStats(a5 + 4);
        v22 = 0;
        a5[12] = 0;
      }
      else
      {
        if ( (v21 & 1) != 0 )
        {
          HvAddToLayoutStats((int)(a5 + 8), v20 + v16);
          HvMoveLayoutStats(a5 + 4);
          if ( !a5[12] )
            a5[12] = *(_DWORD *)(a2 + 4);
          a5[13] = 0;
          goto LABEL_10;
        }
        HvAddToLayoutStats((int)(a5 + 4), v20 + v16);
        if ( a5[13] )
        {
LABEL_10:
          if ( a4 )
            RtlSetBits(a4, (unsigned int)(*(_DWORD *)(a2 + 4) - a2 + v13) >> 3, 1u);
          goto LABEL_12;
        }
        v22 = *(_DWORD *)(a2 + 4);
      }
      a5[13] = v22;
      goto LABEL_10;
    }
    if ( v15 > v12 || v15 + v13 > v14 || !v15 )
      break;
    v26 += v15;
    if ( v26 > v12 )
    {
      if ( v24 )
      {
        SetFailureLocation(v24, 0, 17, 70, 80);
        *(_DWORD *)(v24 + 280) = v13;
      }
      return 70;
    }
    if ( a5 )
    {
      v23 = (_DWORD *)HvAddToLayoutStats((int)a5, v15);
      HvMoveLayoutStats(v23);
    }
    v17 = *(_DWORD *)v13 + v13;
LABEL_12:
    v12 = *(_DWORD *)(a2 + 8);
    v11 = v25;
    v13 = v17;
    v14 = v12 + a2;
    if ( v17 >= v12 + a2 )
    {
      v8 = v26;
      a3 = v27;
      goto LABEL_14;
    }
  }
  if ( v24 )
  {
    SetFailureLocation(v24, 0, 17, 60, 64);
    *(_DWORD *)(v24 + 280) = v13;
  }
  return 60;
}
