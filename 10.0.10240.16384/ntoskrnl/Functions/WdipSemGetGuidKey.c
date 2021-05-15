// WdipSemGetGuidKey 
 
int __fastcall WdipSemGetGuidKey(int a1, unsigned int *a2)
{
  int v2; // r5
  int v3; // r4
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r3

  v2 = a1;
  v3 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  v5 = ((320411091 * *(unsigned __int16 *)(a1 + 4) + 1) & 0xFFFF0000 | ((-393795277
                                                                       * (unsigned int)*(unsigned __int16 *)(a1 + 4)
                                                                       + 12345) >> 16))
     + ((320411091 * *(unsigned __int16 *)(a1 + 6) + 1) & 0xFFFF0000 | ((-393795277
                                                                       * (unsigned int)*(unsigned __int16 *)(a1 + 6)
                                                                       + 12345) >> 16))
     + *(_DWORD *)a1;
  v6 = 8;
  do
  {
    v7 = *(unsigned __int8 *)(v2 + 8);
    ++v2;
    v5 += (320411091 * v7 + 1) & 0xFFFF0000 | ((unsigned int)(-393795277 * v7 + 12345) >> 16);
    --v6;
  }
  while ( v6 );
  *a2 = ((69069 * v5 + 1) & 0xFFFF0000 | ((1103515245 * v5 + 12345) >> 16)) % 0x7FFFFFFF;
  return v3;
}
