// KeSetKernelStackSwapEnable 
 
int __fastcall KeSetKernelStackSwapEnable(int a1)
{
  int v2; // r3
  int result; // r0
  unsigned __int8 *v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r2

  v2 = __mrc(15, 0, 13, 0, 3);
  result = (*(_DWORD *)((v2 & 0xFFFFFFC0) + 0x50) >> 5) & 1;
  if ( a1 != result )
  {
    __dmb(0xBu);
    v4 = (unsigned __int8 *)((v2 & 0xFFFFFFC0) + 80);
    if ( a1 )
    {
      do
        v6 = __ldrex(v4);
      while ( __strex(v6 | 0x20, v4) );
    }
    else
    {
      do
        v5 = __ldrex(v4);
      while ( __strex(v5 & 0xDF, v4) );
    }
    __dmb(0xBu);
  }
  return result;
}
