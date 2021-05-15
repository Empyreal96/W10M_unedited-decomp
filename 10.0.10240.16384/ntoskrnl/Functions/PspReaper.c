// PspReaper 
 
int PspReaper()
{
  _DWORD *v0; // r5
  int v1; // r4
  int v2; // r0
  int result; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1
  unsigned int v7; // r2

  do
  {
    __dmb(0xBu);
    do
      v0 = (_DWORD *)__ldrex((unsigned int *)&PsReaperListHead);
    while ( __strex(1u, (unsigned int *)&PsReaperListHead) );
    __dmb(0xBu);
    do
    {
      v1 = (int)(v0 - 215);
      KiWaitForContextSwap(v0 - 215);
      v2 = KiDecrementProcessStackCount(*(v0 - 186));
      if ( *(v0 - 11) != 1 )
        return sub_5482FC(v2);
      if ( v0[42] )
        JUMPOUT(0x54838A);
      __dmb(0xBu);
      v4 = v0 + 47;
      do
      {
        v5 = __ldrex(v4);
        v6 = v5 - 1;
      }
      while ( __strex(v6, v4) );
      __dmb(0xBu);
      if ( !v6 )
      {
        KeEnumerateKernelStackSegments((int)(v0 - 215), (int (__fastcall *)(int, int *, int))PspDeleteKernelStack, 0);
        *(v0 - 207) = 0;
      }
      v0 = (_DWORD *)*v0;
      result = ObfDereferenceObjectWithTag(v1);
    }
    while ( v0 && v0 != (_DWORD *)1 );
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&PsReaperListHead);
    while ( v7 == 1 && __strex(0, (unsigned int *)&PsReaperListHead) );
    __dmb(0xBu);
  }
  while ( v7 != 1 );
  return result;
}
