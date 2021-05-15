// CmpComputeKcbConvKey 
 
unsigned int __fastcall CmpComputeKcbConvKey(int a1)
{
  int v1; // r3
  unsigned int v2; // r4
  int *v3; // r3
  unsigned int v4; // r5
  unsigned int v5; // r8
  unsigned __int8 *v6; // r6
  unsigned __int16 *v7; // r7
  int v8; // r9
  unsigned int v9; // r0

  v1 = *(_DWORD *)(a1 + 40);
  v2 = 0;
  if ( v1 )
    v2 = *(_DWORD *)(v1 + 12);
  v3 = *(int **)(a1 + 44);
  v4 = 0;
  v5 = *((unsigned __int16 *)v3 + 6);
  v6 = (unsigned __int8 *)v3 + 14;
  v7 = (unsigned __int16 *)v3 + 7;
  if ( *((_WORD *)v3 + 6) )
  {
    v8 = *v3;
    do
    {
      if ( (v8 & 1) != 0 )
      {
        v9 = *v6++;
        ++v4;
      }
      else
      {
        v9 = *v7++;
        v4 += 2;
      }
      if ( v9 >= 0x61 )
      {
        if ( v9 <= 0x7A )
          v9 -= 32;
        else
          v9 = RtlUpcaseUnicodeChar(v9);
      }
      v2 = 37 * v2 + v9;
    }
    while ( v4 < v5 );
  }
  return v2;
}
