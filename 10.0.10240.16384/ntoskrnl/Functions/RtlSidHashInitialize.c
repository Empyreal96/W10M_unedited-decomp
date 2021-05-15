// RtlSidHashInitialize 
 
int __fastcall RtlSidHashInitialize(int *a1, unsigned int a2, int a3)
{
  unsigned int v6; // r7
  int v7; // t1
  int v8; // r5
  unsigned int v9; // r4

  if ( !a3 )
    return -1073741811;
  memset((_BYTE *)a3, 0, 136);
  if ( !a1 || !a2 )
    return 0;
  *(_DWORD *)a3 = a2;
  *(_DWORD *)(a3 + 4) = a1;
  if ( a2 > 0x20 )
    a2 = 32;
  v6 = 0;
  do
  {
    v7 = *a1;
    a1 += 2;
    v8 = 1 << v6++;
    v9 = *(unsigned __int8 *)(v7 + 4 * *(unsigned __int8 *)(v7 + 1) + 4);
    *(_DWORD *)(a3 + 4 * (v9 & 0xF) + 8) |= v8;
    *(_DWORD *)(a3 + 4 * (v9 >> 4) + 72) |= v8;
  }
  while ( v6 < a2 );
  return 0;
}
