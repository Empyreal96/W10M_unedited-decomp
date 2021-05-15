// KiInSwapKernelStacks 
 
int __fastcall KiInSwapKernelStacks(_DWORD *a1)
{
  int v2; // r5
  unsigned __int8 *v3; // r3
  unsigned int v4; // r2
  int result; // r0
  _DWORD v6[8]; // [sp+0h] [bp-20h] BYREF

  do
  {
    v2 = (int)(a1 - 36);
    a1 = (_DWORD *)*a1;
    if ( (MiFlags & 0x40) != 0 )
    {
      KeGetNextKernelStackSegment(v2, v6, 1);
      do
        MiInPageSingleKernelStack(v2, v6);
      while ( KeGetNextKernelStackSegment(v2, v6, 0) );
    }
    __dmb(0xBu);
    v3 = (unsigned __int8 *)(v2 + 82);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 1, v3) );
    __dmb(0xBu);
    result = KiFastReadyThread(v2);
  }
  while ( a1 );
  return result;
}
