// RtlpPopVfpRegisterRange 
 
int __fastcall RtlpPopVfpRegisterRange(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // lr
  unsigned int v7; // r6
  unsigned int *v9; // r3
  unsigned int v10; // r2
  int v11; // r3
  _DWORD *v12; // r2
  int v13; // r1

  v5 = a3 - a2 + 1;
  v7 = a2;
  if ( *(_DWORD *)(a1 + 64) <= (unsigned int)MmHighestUserAddress )
    return sub_527640();
  v9 = *(unsigned int **)(a4 + 4);
  if ( v9 )
  {
    v10 = *(_DWORD *)(a1 + 56);
    if ( v10 < *v9 || v10 > **(_DWORD **)(a4 + 8) - 8 * v5 )
      return -1073741784;
  }
  while ( v7 <= a3 )
  {
    v11 = *(_DWORD *)(a4 + 12);
    if ( v7 >= 8 && v11 && v7 <= 0xF )
      *(_DWORD *)(v11 + 4 * v7 + 4) = *(_DWORD *)(a1 + 56);
    v12 = *(_DWORD **)(a1 + 56);
    v13 = a1 + 8 * v7;
    *(_DWORD *)(v13 + 80) = *v12;
    *(_DWORD *)(v13 + 84) = v12[1];
    *(_DWORD *)(a1 + 56) += 8;
    ++v7;
  }
  return 0;
}
