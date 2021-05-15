// ExDereferenceHandleDebugInfo 
 
int __fastcall ExDereferenceHandleDebugInfo(int result, unsigned int *a2)
{
  int v2; // r6
  unsigned int v3; // r2
  unsigned int v4; // r2
  unsigned int v5; // r4
  int v6; // r0
  unsigned int v7; // r4

  v2 = result;
  __dmb(0xBu);
  do
  {
    v3 = __ldrex(a2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, a2) );
  __dmb(0xBu);
  if ( !v4 )
  {
    v5 = a2[1];
    ExFreePoolWithTag((unsigned int)a2);
    v6 = *(_DWORD *)(v2 + 12);
    if ( v6 )
      PsReturnProcessNonPagedPoolQuota(v6, 80 * v5 + 48);
    __dmb(0xBu);
    result = -v5;
    do
      v7 = __ldrex(&ExpTotalTraceBuffers);
    while ( __strex(v7 + result, &ExpTotalTraceBuffers) );
    __dmb(0xBu);
  }
  return result;
}
