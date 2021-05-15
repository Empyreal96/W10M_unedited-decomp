// MiRemoveWorkingSetPages 
 
unsigned int __fastcall MiRemoveWorkingSetPages(int a1)
{
  _DWORD *v1; // r5
  int v2; // r4
  unsigned int v3; // r1
  unsigned int v4; // r9
  unsigned int v5; // r2
  int v6; // r3
  int v7; // lr
  int v8; // r7
  unsigned int v9; // r10
  _DWORD *v10; // r6
  unsigned int v11; // r4
  unsigned int v12; // r5
  unsigned int *v13; // r8
  int v14; // r0
  int v15; // r0
  int v16; // r2
  unsigned int result; // r0
  _DWORD *v18; // r6
  int v19; // r5
  unsigned int v20; // r9
  unsigned int v21; // r10
  unsigned int v22; // r1
  unsigned int *v23; // r5
  unsigned int v24; // r6
  unsigned int v25; // [sp+8h] [bp-38h]
  _DWORD *v26; // [sp+Ch] [bp-34h]
  int v28; // [sp+14h] [bp-2Ch]
  int v29; // [sp+18h] [bp-28h]
  unsigned int v30; // [sp+20h] [bp-20h]

  v1 = *(_DWORD **)(a1 + 92);
  v26 = v1;
  v2 = v1[63];
  v3 = v1[9];
  v4 = v1[1];
  v29 = v2;
  v30 = v3;
  v25 = v4;
  v5 = v4;
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
    v5 = v4 - 1;
  v6 = *(_DWORD *)(a1 + 60);
  v7 = 0;
  v28 = 0;
  v8 = v6 - v5;
  if ( v6 == v5 )
  {
    v11 = v2 + v3 * v4;
    goto LABEL_25;
  }
  v9 = v1[1];
  v10 = (_DWORD *)(v2 + v3 * v4);
  v4 = v1[2];
  v11 = v2 + v3 * v4;
  v25 = v4;
  if ( (unsigned int)v10 >= v11 )
    goto LABEL_25;
  while ( 1 )
  {
    if ( (*v10 & 1) != 0 )
    {
      v10 = (_DWORD *)((char *)v10 + v3);
      --v8;
    }
    else
    {
      v12 = *(_DWORD *)v11;
      if ( (*(_DWORD *)v11 & 1) == 0 )
      {
        --v4;
        v1 = v26;
        v25 = v4;
        v11 -= v3;
        goto LABEL_8;
      }
      v13 = (unsigned int *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v12 >> 10) & 0x3FFFFC) - 0x40000000) >> 12));
      if ( (v13[1] & 0x80000000) == 0 )
      {
        MiDemoteCombinedPte();
        v12 = *(_DWORD *)v11;
      }
      v28 = 1;
      v14 = MiRemoveEntryWsle(v26, v11);
      *(_DWORD *)(*(_DWORD *)(v14 + 36) * v9 + *(_DWORD *)(v14 + 252)) = v12;
      v1 = v26;
      MiInsertWsle(v26, v10, 1);
      v15 = *v10;
      if ( (*v10 & 8) != 0 )
      {
        if ( (v13[5] & 0x8000000) != 0 )
        {
          *(_DWORD *)(v26[9] * v9 + v26[63]) = v15 & 0xFFFFFFF7;
          MiUpdateWsleHash();
        }
        else
        {
          *v13 = v9;
        }
      }
      else if ( (v15 & 4) != 0 )
      {
        MiReplaceWsleHash(a1, *v10, v9, v4);
      }
      else
      {
        MiUpdateWsleHash();
      }
      v16 = v26[9] * v4--;
      --v8;
      *(_DWORD *)(v16 + v26[63]) = 0;
      v3 = v26[9];
      v25 = v4;
      v11 -= v3;
      v10 = (_DWORD *)((char *)v10 + v3);
    }
    ++v9;
LABEL_8:
    if ( !v8 )
      break;
    if ( (unsigned int)v10 >= v11 )
      goto LABEL_24;
  }
  v11 = (unsigned int)v10;
  v4 = v9;
  v25 = v9;
LABEL_24:
  v7 = v28;
LABEL_25:
  if ( (*(_DWORD *)v11 & 1) != 0 )
  {
    v25 = ++v4;
    v11 += v1[9];
  }
  result = v4 - 1;
  v1[2] = v4 - 1;
  if ( v7 || ((v11 + 4095) & 0xFFFFF000) != v29 + (v1[4] + 1) * v1[9] )
  {
    v18 = v26;
    v19 = v1[9];
    v20 = ((v11 >> 10) & 0x3FFFFC) - 1073741820;
    v21 = (((unsigned int)(v29 + v19 * v26[4]) >> 10) & 0x3FFFFC) - 1073741820;
    if ( (v11 & 0xFFF) != 0 )
    {
      if ( *v26 != 0xFFFFF )
      {
        v22 = ((v11 + 4095) & 0xFFFFF000) - v19 - v29;
        if ( !v30 )
          __brkdiv0();
        result = v22 / v30;
        v26[4] = v22 / v30;
        *v26 = 0xFFFFF;
        do
        {
          v23 = *(unsigned int **)(a1 + 92);
          v24 = *v23;
          if ( *v23 != 0xFFFFF )
          {
            if ( v24 < v23[1] || v24 > v23[4] )
              KeBugCheckEx(26, 20484, v23);
            *(_DWORD *)(v23[9] * v24 + v23[63]) ^= (*(_DWORD *)(v23[9] * v24 + v23[63]) ^ (2 * result)) & 0xFFE;
          }
          *(_DWORD *)(v23[9] * result + v23[63]) = (v24 << 12) | 0xFFE;
          *v23 = result--;
        }
        while ( result >= v25 );
        v18 = v26;
      }
      v18[3] = v18[1];
      if ( v20 < v21 )
        result = MiDeletePteRange(a1, v20, v21, 16);
    }
    else
    {
      result = sub_51A280();
    }
  }
  return result;
}
