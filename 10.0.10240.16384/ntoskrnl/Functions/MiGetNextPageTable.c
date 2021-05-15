// MiGetNextPageTable 
 
int __fastcall MiGetNextPageTable(unsigned int a1, unsigned int a2, int a3, int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r7
  int v7; // r1
  int v8; // r6
  int v9; // r5
  unsigned int v10; // r4
  int v12; // [sp+8h] [bp-30h]
  _DWORD v13[10]; // [sp+10h] [bp-28h] BYREF

  v12 = a3;
  v6 = a1;
  *a6 = 0;
  v13[0] = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v13[1] = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v7 = a5;
  v8 = 0;
  v9 = 0;
LABEL_2:
  v10 = v13[2 * v9];
  do
  {
    if ( *(_DWORD *)v10 )
    {
      if ( (*(_DWORD *)v10 & 2) == 0 )
        return sub_50DD90(2, v7);
      if ( (v8 & 1) != 0 )
      {
        a3 = v12;
        v7 = a5;
        v8 &= 0xFFFFFFFE;
      }
      if ( ++v9 )
      {
        if ( (v8 & 2) != 0 || (*(_DWORD *)v10 & 0x400) != 0 )
          v6 = v10 << 10;
        if ( (*(_DWORD *)v10 & 0x400) != 0 )
          *a6 = 1;
        return v6;
      }
      goto LABEL_2;
    }
    v10 += 4;
    v8 |= 3u;
    if ( (v10 & 0xFFF) == 0 )
      JUMPOUT(0x50DD9C);
  }
  while ( v10 <= v13[2 * v9 + 1] );
  if ( a3 != 1 && a3 )
    MiFlushTbList(a3);
  return 0;
}
