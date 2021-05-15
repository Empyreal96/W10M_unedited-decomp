// sub_528A54 
 
void __fastcall sub_528A54(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  _DWORD *v15; // r5
  _DWORD *v16; // r6
  unsigned int v17; // r7
  int v18; // r8
  int v19; // r9
  int v20; // r10
  _DWORD *i; // r6
  unsigned int v22; // r1
  _DWORD *v23; // r0
  int v25; // t1

  if ( *v16 || v18 != v16[1] - 1 )
  {
    v22 = v17 >> 5;
    v23 = (_DWORD *)(v16[7] + 4 * (v17 >> 5));
    if ( !(*v23 & ~((1 << (v17 & 0x1F)) - 1)) )
    {
      do
      {
        if ( v22 > ((unsigned int)(v16[1] - v16[5]) >> 5) - 1 )
          break;
        v25 = v23[1];
        ++v23;
        ++v22;
      }
      while ( !v25 );
    }
  }
  else
  {
    if ( v16[2] )
      v17 *= 2;
    for ( i = *(_DWORD **)(v16[8] + 4 * v17); v15 != i && RtlpHeapListCompare(v20, (int)i, a15, v19) > 0; i = (_DWORD *)*i )
      ;
  }
  JUMPOUT(0x4DE7AC);
}
