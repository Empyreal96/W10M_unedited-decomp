// MiUpdateWsleHash 
 
unsigned int __fastcall MiUpdateWsleHash(unsigned int result, unsigned int a2, int a3, char a4)
{
  _DWORD *v4; // r7
  int v6; // lr
  int v7; // r2
  int v9; // r6
  int v10; // r5
  unsigned int v11; // r8
  unsigned int v12; // r4
  unsigned int v13; // r8
  unsigned int v14; // r6
  int v15; // r2
  char *v16; // r1
  int *v17; // t1
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r5
  unsigned int v22; // r4
  int v23; // r2
  unsigned int v24; // r1
  int v25; // r3
  bool v26; // zf
  unsigned int v27; // r3
  int v28; // r2
  int v29; // r3
  unsigned int *v30; // r3
  unsigned int v31; // r1
  int v32; // r3
  int v33; // r4
  char v34; // r1
  int v35; // r4
  unsigned int v36; // r6
  unsigned int v37; // r5
  int v38; // r4
  int v40; // [sp+Ch] [bp-2Ch]
  _DWORD v41[2]; // [sp+10h] [bp-28h]
  char v42; // [sp+18h] [bp-20h] BYREF

  v4 = *(_DWORD **)(a3 + 92);
  v6 = a3;
  v7 = 2;
  v9 = *(_DWORD *)(v4[9] * a2 + v4[63]);
  v10 = v4[12];
  v11 = result;
  v40 = v9;
  if ( (v10 & 1) != 0 )
  {
    if ( (*(_BYTE *)(v6 + 115) & 2) != 0 )
      return result;
    v36 = v10 & 0xFFFFFFFE;
    v37 = v10 & 0xFFFFFFFE;
    v38 = 0;
    do
    {
      if ( !MiMapWsleHash(v6, v37, v7) )
        return sub_530FB4();
      ++v38;
      v6 = a3;
      v37 += 4096;
    }
    while ( !v38 );
    v4[10] = 0;
    v4[12] = v36;
    v9 = v40;
  }
  v12 = v4[12];
  if ( !v12 || (v12 & 1) != 0 )
  {
LABEL_3:
    v13 = v4[13] + 4 * ((v11 - v4[11]) >> 12);
    v14 = ((v13 >> 10) & 0x3FFFFC) - 0x40000000;
    v15 = ((v14 >> 10) & 0x3FFFFC) - 0x40000000;
    result = 2;
    v41[0] = v14;
    v41[1] = v15;
    v16 = &v42;
    while ( 1 )
    {
      v17 = (int *)*((_DWORD *)v16 - 1);
      v16 -= 4;
      --result;
      v18 = *v17;
      if ( (*v17 & 2) == 0 )
        break;
      if ( result <= 1 && (v18 & 0x400) != 0 )
      {
        if ( !result )
          break;
LABEL_8:
        v15 = 2;
        while ( 1 )
        {
          v19 = *(_DWORD *)v41[--v15];
          if ( (v19 & 0x10) == 0 )
            goto LABEL_52;
          if ( v15 == 1 )
          {
            if ( (v19 & 0x400) != 0 )
            {
LABEL_12:
              v20 = 1;
              goto LABEL_13;
            }
          }
          else if ( !v15 )
          {
            goto LABEL_12;
          }
        }
      }
      if ( !result )
        goto LABEL_8;
    }
LABEL_52:
    v20 = 0;
LABEL_13:
    if ( v20 || (*(_BYTE *)(a3 + 115) & 2) == 0 && (result = MiMapWsleHash(a3, v13, v15)) != 0 )
    {
      v21 = MmPfnDatabase + 24 * (*(_DWORD *)v14 >> 12);
      v22 = *(_DWORD *)(v21 + 8);
      if ( (a4 & 1) != 0 )
      {
        result = v40 & 0xFFFFFFFB;
        *(_DWORD *)(v4[9] * a2 + v4[63]) = v40 & 0xFFFFFFFB;
        v23 = v22 & 0x1FFF | (((v22 >> 13) - 1) << 13);
        *(_DWORD *)(v21 + 8) = v23;
        if ( (v23 & 0xFFFFE000) != 0 )
        {
          *(_DWORD *)v13 = 0;
        }
        else
        {
          result = MiDeletePteRange(a3, ((v13 >> 10) & 0x3FFFFC) - 0x40000000, ((v13 >> 10) & 0x3FFFFC) - 1073741820, 0);
          v34 = *(_BYTE *)(a3 + 112);
          *(_DWORD *)(a3 + 80) -= result;
          if ( (v34 & 7) != 1 )
          {
            v35 = -result;
            do
              result = __ldrex(&dword_634DA0);
            while ( __strex(result + v35, &dword_634DA0) );
          }
        }
      }
      else
      {
        *(_DWORD *)v13 = a2;
        *(_DWORD *)(v4[9] * a2 + v4[63]) = v40 | 4;
        result = v22 & 0xFFFFE000;
        *(_DWORD *)(v21 + 8) = ((v22 & 0xFFFFE000) + 0x2000) ^ v22 & 0x1FFF;
      }
    }
  }
  else
  {
    v11 &= 0xFFFFF000;
    if ( (a4 & 1) != 0 )
      v24 = v11 & 0xFFFFF000 | 1;
    else
      v24 = 0;
    result = (v11 >> 12) & 0x1FF;
    do
    {
      v25 = *(_DWORD *)(v12 + 8 * result);
      if ( v24 )
      {
        v9 = v40;
        if ( (v25 & 1) != 0 )
        {
          v27 = v25 & 0xFFFFF000 | 1;
          v6 = a3;
        }
        else
        {
          v27 = 0;
        }
        v26 = v27 == v24;
      }
      else
      {
        v26 = v25 == 0;
      }
      if ( v26 )
      {
        v28 = v4[9] * a2;
        v29 = v4[63];
        if ( (a4 & 1) != 0 )
        {
          *(_DWORD *)(v28 + v29) = v9 & 0xFFFFFFFB;
          *(_DWORD *)(v12 + 8 * result) = 0;
          v32 = v4[10] - 1;
          v4[10] = v32;
          if ( !v32 )
          {
            v4[12] = v12 | 1;
            result = MiDeletePteRange(
                       v6,
                       ((v12 >> 10) & 0x3FFFFC) - 0x40000000,
                       ((v12 >> 10) & 0x3FFFFC) - 1073741820,
                       0);
            *(_DWORD *)(a3 + 80) -= result;
            if ( (*(_BYTE *)(a3 + 112) & 7) != 1 )
            {
              v33 = -result;
              do
                result = __ldrex(&dword_634DA0);
              while ( __strex(result + v33, &dword_634DA0) );
            }
          }
        }
        else
        {
          *(_DWORD *)(v28 + v29) = v9 | 4;
          v30 = (unsigned int *)(v12 + 8 * result);
          v30[1] = a2;
          if ( ((v9 | 4) & 1) != 0 )
            v31 = (v9 | 4) & 0xFFFFF000 | 1;
          else
            v31 = 0;
          *v30 = v31;
          ++v4[10];
        }
        return result;
      }
      if ( ++result >= 0x200 )
        result = 0;
    }
    while ( result != ((v11 >> 12) & 0x1FF) );
    if ( (a4 & 1) != 0 )
      KeBugCheckEx(26, 266885, v6);
    if ( (*(_BYTE *)(v6 + 115) & 2) == 0 )
    {
      MiConvertWsleHash(v6);
      goto LABEL_3;
    }
  }
  return result;
}
