// MiUpdateThunks 
 
unsigned int *__fastcall MiUpdateThunks(unsigned int *result, unsigned int a2, int a3, unsigned int a4)
{
  _DWORD *v4; // r6
  _DWORD *v6; // r7
  unsigned int v7; // r5
  int i; // r8
  unsigned int v9; // r2
  unsigned int v10; // r3
  unsigned int v11; // t1
  unsigned int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v4 = (_DWORD *)result[4];
  v6 = result + 4;
  v7 = a4 + a2 - 1;
  for ( i = a3 - a2; v4 != v6; v4 = (_DWORD *)*v4 )
  {
    result = (unsigned int *)RtlImageDirectoryEntryToData(v4[6], 1, 12, (int)v12);
    if ( result )
    {
      v9 = v12[0] >> 2;
      v12[0] >>= 2;
      if ( v12[0] )
      {
        do
        {
          v11 = *result++;
          v10 = v11;
          if ( v11 >= a2 && v10 <= v7 )
            *(result - 1) = v10 + i;
          --v9;
        }
        while ( v9 );
      }
    }
  }
  return result;
}
