// MiLocateWsle 
 
unsigned int __fastcall MiLocateWsle(unsigned int a1, int a2, unsigned int a3)
{
  _DWORD *v3; // r8
  int v5; // r2
  unsigned int v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  unsigned int result; // r0
  int v10; // r1
  int v11; // r10
  unsigned int v12; // r9
  int v13; // r2
  int v14; // r0
  int v15; // r3
  int v16; // r2
  unsigned int v17; // r2
  _DWORD *v18; // r1
  unsigned int v19; // r0
  char *v20; // r6
  char *v21; // r2

  v3 = *(_DWORD **)(a2 + 92);
  v5 = v3[9] * a3;
  v6 = a1 & 0xFFFFF000 | 1;
  if ( a3 <= v3[4] )
  {
    v7 = *(_DWORD *)(v5 + v3[63]);
    v8 = (v7 & 1) != 0 ? v7 & 0xFFFFF000 | 1 : 0;
    if ( v8 == v6 )
    {
      result = a3;
      goto LABEL_6;
    }
  }
  v10 = v3[12];
  if ( v10 )
  {
    if ( (v10 & 1) == 0 )
    {
      v14 = (a1 >> 12) & 0x1FF;
      v15 = v14;
      while ( 1 )
      {
        v16 = *(_DWORD *)(v10 + 8 * v15);
        v17 = (v16 & 1) != 0 ? v16 & 0xFFFFF000 | 1 : 0;
        if ( v17 == v6 )
          break;
        if ( (unsigned int)++v15 >= 0x200 )
          v15 = 0;
        if ( v15 == v14 )
          goto LABEL_29;
      }
      result = *(_DWORD *)(v10 + 8 * v15 + 4);
LABEL_6:
      if ( result != 0xFFFFF )
        return result;
      goto LABEL_29;
    }
  }
  else
  {
    v11 = v3[13];
    v12 = (a1 - v3[11]) >> 12;
    if ( MiIsAddressValid(v11 + 4 * v12, 0) == 1 )
    {
      result = *(_DWORD *)(v11 + 4 * v12);
      if ( result )
      {
        v13 = *(_DWORD *)(v3[9] * result + v3[63]);
        if ( (v13 & 4) == 0 || (v13 & 8) != 0 || (v13 & 1) == 0 || (v13 & 0xFFFFF000 | 1) != v6 )
          sub_532150();
        goto LABEL_6;
      }
    }
  }
LABEL_29:
  ++dword_63440C;
  v18 = *(_DWORD **)(a2 + 92);
  v19 = v18[9];
  v20 = (char *)v18[63];
  v21 = v20;
  while ( (*(_DWORD *)v21 & 1) == 0 || (*(_DWORD *)v21 & 0xFFFFF000 | 1) != v6 )
  {
    v21 += v19;
    if ( v21 > &v20[v18[4] * v19] )
      KeBugCheckEx(26, 266884, a1);
  }
  if ( !v19 )
    __brkdiv0();
  return (v21 - v20) / v19;
}
