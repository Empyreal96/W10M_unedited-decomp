// MiReleaseWsle 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall MiReleaseWsle(unsigned int result, _DWORD *a2, unsigned int a3, int a4)
{
  unsigned int *v6; // r5
  int v7; // r9
  unsigned int v8; // r7
  unsigned int v9; // r1
  unsigned int v10; // r4
  unsigned int v11; // r9
  unsigned int v12; // lr
  int v13; // r1
  unsigned int v14; // r4
  int v15; // r2
  int v16; // r3
  int v17; // r3
  unsigned int v18; // r1 OVERLAPPED
  unsigned int v19; // r2 OVERLAPPED
  unsigned int *v20; // r4
  int v21; // [sp+8h] [bp-28h]

  v6 = (unsigned int *)a2[23];
  v7 = a4;
  v8 = result;
  if ( a4 )
  {
    v9 = v6[1];
    if ( result >= v9 )
    {
      v10 = v6[9];
      v11 = v6[63];
      v12 = v11 + v10 * result;
      result = *(_DWORD *)v12;
      if ( v10 == 16 && (int)(v12 - v11) >> 4 >= v9 )
      {
        v17 = 2 * ((result >> 9) & 7);
        *(_QWORD *)&v18 = *(_QWORD *)(v12 + 4);
        v21 = v17;
        if ( result < 0xC0000000 || result > 0xC03FFFFF )
          v21 = ++v17;
        v20 = &v6[2 * v17];
        if ( v19 == 0xFFFFF )
        {
          v20[31] = v18;
        }
        else
        {
          *(_DWORD *)(v11 + 16 * v19 + 4) = v18;
          v17 = v21;
        }
        if ( v18 == 0xFFFFF )
          v20[32] = v19;
        else
          *(_DWORD *)(v11 + 16 * v18 + 8) = v19;
        --v6[v17 + 15];
      }
      v13 = (result >> 9) & 7;
      if ( v13 )
      {
        v15 = (int)&a2[v13 - 1];
        v16 = *(_DWORD *)(v15 + 20) - 1;
        *(_DWORD *)(v15 + 20) = v16;
        if ( v13 == 7 )
          result = MiVolunteerForTrimFirst((int)a2, -1, v15, v16);
      }
      v7 = a4;
    }
  }
  v14 = *v6;
  if ( *v6 != 0xFFFFF )
  {
    if ( v14 < v6[1] || v14 > v6[4] )
      sub_50DA08();
    result = v6[9] * v14;
    *(_DWORD *)(result + v6[63]) ^= (*(_DWORD *)(result + v6[63]) ^ (2 * v8)) & 0xFFE;
  }
  *(_DWORD *)(v6[9] * v8 + v6[63]) = (v14 << 12) | 0xFFE;
  *v6 = v8;
  if ( v7 )
  {
    --a2[15];
    if ( a3 < 0xC0000000 || a3 > 0xC03FFFFF )
      --a2[13];
  }
  return result;
}
