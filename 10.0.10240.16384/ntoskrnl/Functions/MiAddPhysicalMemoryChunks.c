// MiAddPhysicalMemoryChunks 
 
int __fastcall MiAddPhysicalMemoryChunks(int result, __int64 *a2, unsigned int *a3)
{
  unsigned int v4; // r7
  unsigned int v5; // r5
  unsigned int v6; // r6
  unsigned int v7; // r8
  unsigned __int64 v8; // [sp+0h] [bp-30h] BYREF
  __int64 v9[5]; // [sp+8h] [bp-28h] BYREF

  v4 = *a3;
  v9[0] = *a2;
  v5 = 0;
  v6 = 0;
  LODWORD(v8) = *a3;
  v7 = a3[1];
  HIDWORD(v8) = v7;
  do
  {
    result = MiAddPhysicalMemory(result, v9, &v8, 0);
    if ( result < 0 )
      return sub_80FAF0();
    v6 = (__PAIR64__(v6, v5) + v8) >> 32;
    v5 += v8;
    v9[0] += v8;
    v8 = __PAIR64__(v7, v4) - __PAIR64__(v6, v5);
  }
  while ( __PAIR64__(v7, v4) != __PAIR64__(v6, v5) );
  *a3 = v5;
  a3[1] = v6;
  return result;
}
