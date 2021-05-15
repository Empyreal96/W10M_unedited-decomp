// MiTryLocateWsle 
 
int __fastcall MiTryLocateWsle(unsigned int a1, int a2, unsigned int a3)
{
  _DWORD *v3; // r6
  unsigned int v4; // r4
  int v6; // r2
  unsigned int v7; // r7
  int v8; // r3
  unsigned int v9; // r3
  int v10; // r1
  int v11; // r0
  int v12; // r3
  int v13; // r2
  unsigned int v14; // r2
  int v15; // r9
  unsigned int v16; // r3
  unsigned int v17; // r4
  int v18; // r2

  v3 = *(_DWORD **)(a2 + 92);
  v4 = a3;
  v6 = v3[9] * a3;
  v7 = a1 & 0xFFFFF000 | 1;
  if ( v4 > v3[4]
    || ((v8 = *(_DWORD *)(v6 + v3[63]), (v8 & 1) == 0) ? (v9 = 0) : (v6 = 1, v9 = v8 & 0xFFFFF000 | 1), v9 != v7) )
  {
    v10 = v3[12];
    if ( v10 )
    {
      if ( (v10 & 1) == 0 )
      {
        v11 = (a1 >> 12) & 0x1FF;
        v12 = (a1 >> 12) & 0x1FF;
        while ( 1 )
        {
          v13 = *(_DWORD *)(v10 + 8 * v12);
          v14 = (v13 & 1) != 0 ? v13 & 0xFFFFF000 | 1 : 0;
          if ( v14 == v7 )
            break;
          if ( (unsigned int)++v12 >= 0x200 )
            v12 = 0;
          if ( v12 == v11 )
          {
            v12 = 0xFFFFF;
            break;
          }
        }
        if ( v12 != 0xFFFFF )
          return *(_DWORD *)(v10 + 8 * v12 + 4);
      }
      return 0xFFFFF;
    }
    v15 = v3[13];
    v16 = a1 - v3[11];
    v17 = v16 >> 12;
    if ( MiIsAddressValid(v15 + 4 * (v16 >> 12), 0, v6, v16) != 1 )
      return 0xFFFFF;
    v4 = *(_DWORD *)(v15 + 4 * v17);
    if ( !v4 )
      return 0xFFFFF;
    v18 = *(_DWORD *)(v3[9] * v4 + v3[63]);
    if ( (v18 & 4) == 0 || (v18 & 8) != 0 || (v18 & 1) == 0 || (v18 & 0xFFFFF000 | 1) != v7 )
      KeBugCheckEx(26, 266889, a1, v4, *(_DWORD *)(v3[9] * v4 + v3[63]));
  }
  return v4;
}
