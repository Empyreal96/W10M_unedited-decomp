// KeSwapProcessOrStack 
 
void __noreturn KeSwapProcessOrStack()
{
  unsigned int v0; // r2
  _DWORD *v1; // r0
  _DWORD *v2; // r0
  _DWORD *v3; // r0

  KeSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 23);
  while ( 1 )
  {
    KeWaitForSingleObject((unsigned int)&KiSwapEvent, 0, 0, 0, 0);
    __dmb(0xBu);
    do
      v0 = __ldrex(&KiStackOutSwapRequest);
    while ( v0 == 1 && __strex(0, &KiStackOutSwapRequest) );
    __dmb(0xBu);
    if ( v0 == 1 )
      KiOutSwapKernelStacks();
    do
      v1 = (_DWORD *)__ldrex((unsigned int *)&KiProcessOutSwapListHead);
    while ( __strex(0, (unsigned int *)&KiProcessOutSwapListHead) );
    if ( v1 )
      KiOutSwapProcesses(v1);
    do
      v2 = (_DWORD *)__ldrex((unsigned int *)&KiProcessInSwapListHead);
    while ( __strex(0, (unsigned int *)&KiProcessInSwapListHead) );
    if ( v2 )
      KiInSwapProcesses(v2);
    do
      v3 = (_DWORD *)__ldrex((unsigned int *)&KiStackInSwapListHead);
    while ( __strex(0, (unsigned int *)&KiStackInSwapListHead) );
    if ( v3 )
      KiInSwapKernelStacks(v3);
  }
}
