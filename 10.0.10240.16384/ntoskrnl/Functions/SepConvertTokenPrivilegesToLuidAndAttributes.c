// SepConvertTokenPrivilegesToLuidAndAttributes 
 
int __fastcall SepConvertTokenPrivilegesToLuidAndAttributes(_DWORD *a1, int a2)
{
  int result; // r0
  unsigned int i; // r4
  int v5; // r7
  int v6; // lr
  int v7; // r5

  result = 0;
  for ( i = 0; i <= 0x23; ++i )
  {
    v5 = 1 << (i - 32);
    v6 = 1 << i;
    if ( a1[17] & v5 | a1[16] & (1 << i) )
    {
      *(_QWORD *)a2 = (int)i;
      if ( a1[19] & v5 | a1[18] & v6 )
        v7 = 2;
      else
        v7 = 0;
      *(_DWORD *)(a2 + 8) = ((a1[21] & v5 | a1[20] & v6) != 0) | v7;
      ++result;
      a2 += 12;
    }
  }
  return result;
}
