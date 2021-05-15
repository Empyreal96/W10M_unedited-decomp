// MiMarkNonPagedHiberPhasePages 
 
char *__fastcall MiMarkNonPagedHiberPhasePages(int a1, unsigned int *a2, unsigned int a3, int a4)
{
  unsigned int *v4; // r5
  char *result; // r0
  unsigned int v6; // r1
  unsigned int v7; // r6
  unsigned int v8; // r4
  unsigned int v10; // r7
  unsigned int v11; // r3
  unsigned int v12; // r7
  int v13; // r1

  v4 = a2;
  result = (char *)(a3 - (_DWORD)a2);
  v6 = a3 - (_DWORD)a2 + 4;
  v7 = 1;
  if ( (unsigned int)v4 > a3 )
    v8 = 0;
  else
    v8 = v6 >> 2;
  if ( v8 )
  {
    do
    {
      if ( a4 )
      {
        v10 = *v4;
        result = (char *)MI_IS_PFN(*v4 >> 12);
        if ( result )
          result = PoSetHiberRange(0, 81920, (const void *)(v10 >> 12), (const void *)0x400, 1818521678);
      }
      else
      {
        v11 = *v4;
        if ( (*v4 & 2) != 0 )
        {
          v12 = v11 >> 12;
          result = (char *)MI_IS_PFN(v11 >> 12);
          if ( result )
          {
            v13 = MmPfnDatabase + 24 * v12;
            if ( *(unsigned __int16 *)(v13 + 16) > 1u || !*(_DWORD *)v13 || (*(_BYTE *)(v13 + 19) & 8) != 0 )
              result = PoSetHiberRange(0, 81920, (const void *)v12, (const void *)1, 1935962190);
          }
        }
      }
      ++v7;
      ++v4;
    }
    while ( v7 <= v8 );
  }
  return result;
}
