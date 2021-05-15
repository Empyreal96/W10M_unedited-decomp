// RtlpFillMemoryRandomUp 
 
unsigned int __fastcall RtlpFillMemoryRandomUp(unsigned int result, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  _DWORD *v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r4
  _DWORD *v9; // r1

  v5 = (_DWORD *)result;
  v6 = 0;
  if ( result > result + 4096 )
    v7 = 0;
  else
    v7 = 512;
  if ( v7 )
  {
    result = a5;
    do
    {
      v9 = (_DWORD *)(a5 + 8 * (a3 & 0xF));
      *v5 = a3;
      v5[1] = a4;
      ++v6;
      v5 += 2;
      a3 = ((a4 << 28) | (a3 >> 4)) ^ *v9;
      a4 = v9[1] ^ (a4 >> 4);
    }
    while ( v6 < v7 );
  }
  return result;
}
