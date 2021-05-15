// sub_50E448 
 
void __fastcall sub_50E448(int a1, int a2, int *a3)
{
  int v3; // r8
  unsigned int v4; // r8
  int *v5; // r7
  int v6; // r0
  int v7; // t1
  unsigned int v8; // r2
  unsigned int v9; // r3
  int v10; // r2
  int v11; // r1
  int v12; // r4
  unsigned int v13; // r3
  int v14; // r2
  unsigned int v15; // [sp+14h] [bp+14h]

  v4 = (unsigned int)&a3[v3];
  v5 = a3;
  v15 = v4;
  while ( 1 )
  {
    v7 = *v5++;
    v6 = v7;
    v8 = v7 & 0xFFFFF000;
    __mcr(15, 0, v7 & 0xFFFFF000, 8, 3, 3);
    if ( (v7 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
    {
      v9 = (v8 & 0xFFFFF000) << 10;
      v10 = 4;
      do
      {
        __mcr(15, 0, v9, 8, 3, 3);
        v9 += 0x100000;
        --v10;
      }
      while ( v10 );
    }
    v11 = v6 & 0x7FF;
    if ( (v6 & 0x800) != 0 )
      v12 = 0x400000;
    else
      v12 = 4096;
    if ( (v6 & 0x7FF) != 0 )
    {
      do
      {
        v6 += v12;
        __mcr(15, 0, v6 & 0xFFFFF000, 8, 3, 3);
        if ( (v6 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
        {
          v13 = (v6 & 0xFFFFF000) << 10;
          v14 = 4;
          do
          {
            __mcr(15, 0, v13, 8, 3, 3);
            v13 += 0x100000;
            --v14;
          }
          while ( v14 );
        }
        --v11;
      }
      while ( v11 );
      v4 = v15;
    }
    if ( (unsigned int)v5 >= v4 )
      JUMPOUT(0x4B6B8C);
  }
}
