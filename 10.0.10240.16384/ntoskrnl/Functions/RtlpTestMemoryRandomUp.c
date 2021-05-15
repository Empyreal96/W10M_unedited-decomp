// RtlpTestMemoryRandomUp 
 
int __fastcall RtlpTestMemoryRandomUp(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  _DWORD *v5; // r6
  _DWORD *v7; // r1

  v5 = a1 + 1024;
  if ( a1 >= a1 + 1024 )
    return 1;
  while ( *a1 == a3 && a1[1] == a4 )
  {
    v7 = (_DWORD *)(a5 + 8 * (a3 & 0xF));
    a1 += 2;
    a3 = ((a4 << 28) | (a3 >> 4)) ^ *v7;
    a4 = v7[1] ^ (a4 >> 4);
    if ( a1 >= v5 )
      return 1;
  }
  return 0;
}
