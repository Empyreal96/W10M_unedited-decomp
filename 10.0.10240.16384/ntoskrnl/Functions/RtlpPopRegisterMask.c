// RtlpPopRegisterMask 
 
int __fastcall RtlpPopRegisterMask(_DWORD *a1, unsigned int a2, int a3)
{
  int v4; // r1
  unsigned int v5; // r4
  int v7; // r3
  unsigned int *v9; // r3
  unsigned int v10; // r1
  int v11; // r2
  unsigned int v12; // r2

  v4 = 0;
  v5 = 0;
  do
  {
    v7 = (a2 >> v5++) & 1;
    v4 += v7;
  }
  while ( v5 < 0xF );
  if ( a1[16] <= (unsigned int)MmHighestUserAddress )
    return sub_547FB8();
  v9 = *(unsigned int **)(a3 + 4);
  if ( v9 )
  {
    v12 = a1[14];
    if ( v12 < *v9 || v12 > **(_DWORD **)(a3 + 8) - 4 * v4 )
      return -1073741784;
  }
  v10 = 0;
  do
  {
    if ( ((1 << v10) & a2) != 0 )
    {
      v11 = *(_DWORD *)(a3 + 12);
      if ( v11 )
      {
        if ( v10 - 4 > 7 )
        {
          if ( v10 == 14 )
            *(_DWORD *)(v11 + 32) = a1[14];
        }
        else
        {
          *(_DWORD *)(v11 + 4 * v10 - 16) = a1[14];
        }
      }
      a1[v10 + 1] = *(_DWORD *)a1[14];
      a1[14] += 4;
    }
    ++v10;
  }
  while ( v10 < 0xF );
  if ( (a2 & 0x4000) != 0 )
    a1[16] = a1[15];
  return 0;
}
