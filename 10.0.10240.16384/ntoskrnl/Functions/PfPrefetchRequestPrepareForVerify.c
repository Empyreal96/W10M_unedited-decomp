// PfPrefetchRequestPrepareForVerify 
 
int __fastcall PfPrefetchRequestPrepareForVerify(_DWORD *a1, unsigned int a2, int a3)
{
  unsigned int v6; // r6
  _BYTE *v7; // r0
  int result; // r0
  unsigned int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r2

  v6 = 104;
  v7 = memset((_BYTE *)a3, 0, 60);
  if ( a1[2] )
  {
    if ( a1[8] )
      result = sub_80F238(v7);
    else
      result = 4000;
  }
  else
  {
    if ( a1[8] )
      return 4100;
    v9 = a1[3];
    if ( v9 )
    {
      v10 = a1[9];
      if ( !v10 )
        return 5000;
      if ( v10 < 0x68 )
        return 5200;
      if ( v9 > a2 >> 5 )
        return 5300;
      v11 = 32 * v9;
      if ( v10 >= a2 || v11 >= a2 || v10 > a2 - v11 )
        return 5400;
      v6 = v10 + v11;
      *(_DWORD *)(a3 + 12) = v10;
      *(_DWORD *)(a3 + 16) = v10 + v11;
      *(_DWORD *)(a3 + 20) = a1[3];
    }
    else if ( a1[9] )
    {
      return 5100;
    }
    v12 = a1[4];
    if ( v12 )
    {
      v13 = a1[10];
      if ( !v13 )
        return 6000;
      if ( v13 < v6 )
        return 6200;
      if ( v12 > a2 >> 4 )
        return 6300;
      v14 = 16 * v12;
      if ( v13 >= a2 || v14 >= a2 || v13 > a2 - v14 )
        return 6400;
      v6 = v13 + v14;
      *(_DWORD *)(a3 + 24) = v13;
      *(_DWORD *)(a3 + 28) = v13 + v14;
      *(_DWORD *)(a3 + 32) = a1[4];
    }
    else if ( a1[10] )
    {
      return 6100;
    }
    v15 = a1[5];
    if ( v15 )
    {
      v18 = a1[11];
      if ( !v18 )
        return 7000;
      if ( v18 < v6 )
        return 7200;
      if ( v15 > a2 / 0x18 )
        return 7300;
      v19 = 24 * v15;
      if ( v18 >= a2 || v19 >= a2 || v18 > a2 - v19 )
        return 7400;
      v6 = v18 + v19;
      *(_DWORD *)(a3 + 36) = v18;
      *(_DWORD *)(a3 + 40) = v18 + v19;
      *(_DWORD *)(a3 + 44) = a1[5];
    }
    else if ( a1[11] )
    {
      return 7100;
    }
    v16 = a1[6];
    if ( v16 )
    {
      v17 = a1[12];
      if ( !v17 )
        return 8000;
      if ( v17 < v6 )
        return 8200;
      if ( v17 >= a2 || v16 >= a2 || v17 > a2 - v16 )
        return 8300;
      v6 = v17 + v16;
      *(_DWORD *)(a3 + 48) = v17;
      *(_DWORD *)(a3 + 52) = v17 + v16;
    }
    else if ( a1[12] )
    {
      return 8100;
    }
    if ( v6 == a2 )
      result = 0;
    else
      result = 9000;
  }
  return result;
}
