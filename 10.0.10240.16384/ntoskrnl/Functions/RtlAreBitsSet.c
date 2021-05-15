// RtlAreBitsSet 
 
int __fastcall RtlAreBitsSet(unsigned int *a1, int a2, unsigned int a3)
{
  char v3; // r4
  char v4; // r5
  unsigned int v5; // r6
  unsigned int v7; // r2
  int *v8; // r1
  int *v9; // r0
  unsigned int v10; // r2
  int v11; // t1

  v3 = a3;
  v4 = a2;
  v5 = a2 + a3 - 1;
  if ( v5 < *a1 )
  {
    if ( a3 <= 1 )
    {
      if ( a3 == 1 )
        return (*(unsigned __int8 *)((a2 >> 3) + a1[1]) >> (a2 & 7)) & 1;
      return 0;
    }
    v7 = a1[1];
    v8 = (int *)(v7 + 4 * ((unsigned int)a2 >> 5));
    v9 = (int *)(v7 + 4 * (v5 >> 5));
    if ( v8 == v9 )
    {
      v10 = 0xFFFFFFFF >> (32 - v3) << (v4 & 0x1F);
      return (*v8 & v10) == v10;
    }
    if ( (*v8 & (-1 << (v4 & 0x1F))) == -1 << (v4 & 0x1F) )
    {
      for ( ++v8; v8 != v9; ++v8 )
      {
        v11 = *v8;
        if ( v11 != -1 )
          return 0;
      }
      v10 = 0xFFFFFFFF >> (31 - (v5 & 0x1F));
      return (*v8 & v10) == v10;
    }
  }
  return 0;
}
