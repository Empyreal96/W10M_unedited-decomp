// MiMarkKernelStack 
 
unsigned int __fastcall MiMarkKernelStack(unsigned int result, unsigned int a2, int a3)
{
  int *v3; // r6
  int v5; // lr
  int v6; // r0
  unsigned __int8 *v7; // r3
  unsigned int v8; // r5
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int *v11; // r2

  v3 = (int *)result;
  if ( result < a2 )
  {
    while ( 1 )
    {
      v5 = *v3;
      v6 = MmPfnDatabase + 24 * ((unsigned int)*v3 >> 12);
      v7 = (unsigned __int8 *)(v6 + 15);
      do
        v8 = __ldrex(v7);
      while ( __strex(v8 | 0x80, v7) );
      __dmb(0xBu);
      if ( v8 >> 7 )
        break;
      if ( v5 == *v3 )
      {
        v9 = *(_DWORD *)(v6 + 20);
        *(_DWORD *)v6 = a3;
        *(_DWORD *)(v6 + 20) = v9 & 0xF8FFFFFF | 0x2000000;
        *(_DWORD *)(v6 + 8) |= 0x3E0u;
        *(_BYTE *)(v6 + 19) = *(_BYTE *)(v6 + 19) & 0xF8 | 5;
        __dmb(0xBu);
        v10 = (unsigned int *)(v6 + 12);
        do
          result = __ldrex(v10);
        while ( __strex(result & 0x7FFFFFFF, v10) );
        ++v3;
      }
      else
      {
        __dmb(0xBu);
        v11 = (unsigned int *)(v6 + 12);
        do
          result = __ldrex(v11);
        while ( __strex(result & 0x7FFFFFFF, v11) );
      }
      if ( (unsigned int)v3 >= a2 )
        return result;
    }
    result = sub_50DEC0();
  }
  return result;
}
