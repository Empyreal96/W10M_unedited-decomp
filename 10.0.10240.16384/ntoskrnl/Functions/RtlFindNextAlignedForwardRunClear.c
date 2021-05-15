// RtlFindNextAlignedForwardRunClear 
 
int __fastcall RtlFindNextAlignedForwardRunClear(unsigned int *a1, int a2, int a3)
{
  unsigned int v3; // r8
  unsigned int v4; // r4
  unsigned int v5; // r1
  int v7; // lr
  int v8; // r3
  unsigned int v9; // r10
  int *v10; // r5
  int v11; // t1
  int v12; // r9
  unsigned int v14; // r0
  int v15; // r1

  v3 = *a1;
  v4 = 0;
  v5 = 1;
  v7 = 1;
  do
  {
    v8 = 1 << v5++;
    v7 |= v8;
  }
  while ( v5 < 0x20 );
  v9 = a1[1] + 4 * ((v3 - 1) >> 5);
  while ( 1 )
  {
    v10 = (int *)(a1[1] + 4 * (v4 >> 5));
LABEL_5:
    if ( (unsigned int)v10 > v9 )
      return -1;
    v11 = *v10++;
    v12 = dword_40A280[v4 & 0x1F] | v11;
    if ( (v12 & v7) == v7 )
      return sub_54CB50(dword_40A280);
    v4 &= 0xFFFFFFE0;
    v14 = 0;
    while ( 1 )
    {
      if ( ((1 << v14) & v12) != 0 )
        goto LABEL_14;
      v15 = 0;
      if ( v4 >= v3 )
        goto LABEL_14;
      do
      {
        if ( ((*(int *)(a1[1] + 4 * (v4 >> 5)) >> (v4 & 0x1F)) & 1) != 0 )
          break;
        ++v15;
        ++v4;
        if ( v15 == a3 )
          return v4 - v15;
      }
      while ( v4 < v3 );
      if ( !v15 )
        goto LABEL_14;
      if ( v15 + v14 >= 0x20 )
        break;
      v14 = v15 + v14 - 1;
LABEL_14:
      ++v14;
      ++v4;
      if ( v14 >= 0x20 )
        goto LABEL_5;
    }
    ++v4;
  }
}
