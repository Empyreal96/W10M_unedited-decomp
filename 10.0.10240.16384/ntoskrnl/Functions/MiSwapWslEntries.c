// MiSwapWslEntries 
 
unsigned int __fastcall MiSwapWslEntries(int a1, int a2, int a3)
{
  _DWORD *v3; // r8
  int v4; // r7
  int v5; // lr
  int v6; // r5
  unsigned int v7; // r4
  unsigned int v8; // r3
  unsigned int *v9; // r10
  unsigned int v10; // r1
  int v11; // r2
  unsigned int v12; // lr
  unsigned int v13; // r7
  int v14; // r0
  _DWORD *v15; // r1
  int v16; // r4
  unsigned int result; // r0
  _DWORD *v18; // r1
  unsigned int v19; // r0
  int v20; // r2
  int v21; // r3
  unsigned int v22; // r3
  unsigned int v23; // r1
  int v24; // r2
  int v25; // r3
  unsigned int v26; // r3
  int v27; // r4
  __int64 v28; // kr00_8
  int v29; // r2
  _DWORD *v30; // r6
  int v31; // r4
  __int64 v32; // kr08_8
  unsigned int v33; // r0
  int v34; // r2
  int v35; // r2
  _DWORD *v36; // r4
  unsigned int v37; // r1
  int v38; // r2
  _DWORD *v39; // r4
  int v40; // r1
  unsigned int v41; // [sp+8h] [bp-30h]

  v3 = *(_DWORD **)(a3 + 92);
  v4 = a2;
  v5 = a3;
  v6 = v3[63] + v3[9] * a1;
  v7 = *(_DWORD *)v6;
  if ( (*(_DWORD *)v6 & 4) == 0 )
  {
    v8 = *(_DWORD *)(((v7 >> 10) & 0x3FFFFC) - 0x40000000);
    if ( (v8 & 2) == 0 )
      sub_530F20(&MmPfnDatabase);
    if ( (*(_DWORD *)(MmPfnDatabase + 24 * (v8 >> 12) + 20) & 0x8000000) != 0 )
    {
      if ( (v7 & 8) != 0 )
        *(_DWORD *)v6 = v7 & 0xFFFFFFF7;
      MiUpdateWsleHash(*(_DWORD *)v6, a1, a3, 0);
      v5 = a3;
    }
  }
  v9 = (unsigned int *)(v3[63] + v3[9] * v4);
  v10 = *v9;
  if ( (*v9 & 1) != 0 && (v10 & 4) == 0 )
  {
    v11 = ((v10 >> 10) & 0x3FFFFC) - 0x40000000;
    if ( (*(_DWORD *)v11 & 2) == 0 )
      KeBugCheckEx(26, 399680, v11 << 10);
    if ( (*(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v11 >> 12) + 20) & 0x8000000) != 0 )
    {
      if ( (v10 & 8) != 0 )
        *v9 = v10 & 0xFFFFFFF7;
      MiUpdateWsleHash(*v9, v4, v5, 0);
    }
  }
  v12 = *(_DWORD *)v6;
  v13 = *v9;
  v41 = *(_DWORD *)v6;
  if ( (*v9 & 1) != 0 )
  {
    if ( v3[9] == 16 )
    {
      v27 = v3[63];
      if ( (unsigned int)((v6 - v27) >> 4) >= v3[1] )
      {
        v28 = *(_QWORD *)(v6 + 4);
        v29 = 2 * ((v12 >> 9) & 7);
        if ( v12 < 0xC0000000 || v12 > 0xC03FFFFF )
          ++v29;
        v30 = &v3[2 * v29];
        if ( HIDWORD(v28) == 0xFFFFF )
          v30[31] = v28;
        else
          *(_DWORD *)(v27 + 16 * HIDWORD(v28) + 4) = v28;
        if ( (_DWORD)v28 == 0xFFFFF )
          v30[32] = HIDWORD(v28);
        else
          *(_DWORD *)(v27 + 16 * v28 + 8) = HIDWORD(v28);
        --v3[v29 + 15];
      }
      if ( v3[9] == 16 )
      {
        v31 = v3[63];
        if ( (unsigned int)(((int)v9 - v31) >> 4) >= v3[1] )
        {
          v32 = *(_QWORD *)v9;
          v33 = v9[2];
          v34 = 2 * ((*v9 >> 9) & 7);
          if ( *v9 < 0xC0000000 || (unsigned int)v32 > 0xC03FFFFF )
            ++v34;
          if ( v33 == 0xFFFFF )
            *(_DWORD *)(v32 + 124) = HIDWORD(v32);
          else
            *(_DWORD *)(v31 + 16 * v33 + 4) = HIDWORD(v32);
          if ( HIDWORD(v32) == 0xFFFFF )
            v3[2 * v34 + 32] = v33;
          else
            *(_DWORD *)(v31 + 16 * HIDWORD(v32) + 8) = v33;
          --v3[v34 + 15];
        }
      }
    }
    v14 = ((v13 >> 10) & 0x3FFFFC) - 0x40000000;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 92) + 36) * a1 + *(_DWORD *)(*(_DWORD *)(a3 + 92) + 252)) = v13;
    if ( (v13 & 8) != 0 )
    {
      if ( (*(_DWORD *)v14 & 2) == 0 )
        KeBugCheckEx(26, 399680, v14 << 10);
      *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v14 >> 12)) = a1;
    }
    else
    {
      v15 = *(_DWORD **)(a3 + 92);
      if ( (v13 & 4) != 0 )
      {
        v16 = v15[12];
        if ( !v16 || (v16 & 1) != 0 )
        {
          *(_DWORD *)(v15[13] + 4 * ((v13 - v15[11]) >> 12)) = a1;
        }
        else
        {
          v19 = v13 & 0xFFFFF000 | 1;
          v20 = (v19 >> 12) & 0x1FF;
          while ( 1 )
          {
            v21 = *(_DWORD *)(v16 + 8 * v20);
            v22 = (v21 & 1) != 0 ? v21 & 0xFFFFF000 | 1 : 0;
            if ( v22 == v19 )
              break;
            if ( (unsigned int)++v20 >= 0x200 )
              v20 = 0;
            if ( v20 == ((v19 >> 12) & 0x1FF) )
              KeBugCheckEx(26, 266882, a3);
          }
          *(_DWORD *)(v16 + 8 * v20 + 4) = a1;
        }
      }
    }
    result = ((v12 >> 10) & 0x3FFFFC) - 0x40000000;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 92) + 36) * a2 + *(_DWORD *)(*(_DWORD *)(a3 + 92) + 252)) = v12;
    if ( (v12 & 8) != 0 )
    {
      if ( (*(_DWORD *)result & 2) == 0 )
        KeBugCheckEx(26, 399680, result << 10);
      *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)result >> 12)) = a2;
    }
    else
    {
      v18 = *(_DWORD **)(a3 + 92);
      if ( (v12 & 4) != 0 )
      {
        result = v18[12];
        if ( result && (result & 1) == 0 )
        {
          if ( (v12 & 1) != 0 )
            v23 = v12 & 0xFFFFF000 | 1;
          else
            v23 = 0;
          v24 = (v23 >> 12) & 0x1FF;
          while ( 1 )
          {
            v25 = *(_DWORD *)(result + 8 * v24);
            if ( v23 )
            {
              if ( (v25 & 1) != 0 )
                v26 = v25 & 0xFFFFF000 | 1;
              else
                v26 = 0;
              if ( v26 == v23 )
              {
LABEL_51:
                *(_DWORD *)(result + 8 * v24 + 4) = a2;
                goto LABEL_22;
              }
            }
            else if ( !v25 )
            {
              goto LABEL_51;
            }
            if ( (unsigned int)++v24 >= 0x200 )
              v24 = 0;
            if ( v24 == ((v23 >> 12) & 0x1FF) )
              KeBugCheckEx(26, 266882, a3);
          }
        }
        *(_DWORD *)(v18[13] + 4 * ((v12 - v18[11]) >> 12)) = a2;
      }
    }
LABEL_22:
    if ( v3[9] == 16 )
    {
      result = ((int)v9 - v3[63]) >> 4;
      if ( result >= v3[1] )
      {
        v35 = 2 * ((*v9 >> 9) & 7);
        if ( *v9 < 0xC0000000 || *v9 > 0xC03FFFFF )
          ++v35;
        v36 = &v3[2 * v35];
        v37 = v36[32];
        v9[1] = 0xFFFFF;
        v9[2] = v37;
        if ( v37 == 0xFFFFF )
          v36[31] = result;
        else
          *(_DWORD *)(v3[63] + 16 * v37 + 4) = result;
        v36[32] = result;
        ++v3[v35 + 15];
      }
      if ( v3[9] == 16 )
      {
        result = (v6 - v3[63]) >> 4;
        if ( result >= v3[1] )
        {
          v38 = 2 * ((*(_DWORD *)v6 >> 9) & 7);
          if ( *(_DWORD *)v6 < 0xC0000000 || *(_DWORD *)v6 > 0xC03FFFFF )
            ++v38;
          v39 = &v3[2 * v38];
          v40 = v39[32];
          *(_DWORD *)(v6 + 4) = 0xFFFFF;
          *(_DWORD *)(v6 + 8) = v40;
          if ( v40 == 0xFFFFF )
            v39[31] = result;
          else
            *(_DWORD *)(v3[63] + 16 * v40 + 4) = result;
          v39[32] = result;
          ++v3[v38 + 15];
        }
      }
    }
  }
  else
  {
    MiRemoveWsleFromFreeList(a3, a2);
    MiRemoveEntryWsle(v3, v6);
    MiExchangeWsle(a3, v41, a2, a1);
    MiInsertWsle(v3, v9, 0);
    result = MiReleaseWsle(a1, a3, 0, 0);
  }
  return result;
}
