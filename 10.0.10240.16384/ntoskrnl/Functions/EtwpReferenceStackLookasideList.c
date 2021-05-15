// EtwpReferenceStackLookasideList 
 
_DWORD *EtwpReferenceStackLookasideList()
{
  unsigned int v0; // r1
  unsigned int v1; // r1
  int v2; // r5
  _DWORD *result; // r0
  unsigned int v4; // r2
  signed int v5; // r2

  __dmb(0xBu);
  do
  {
    v0 = __ldrex((unsigned int *)&dword_61ABF8);
    v1 = v0 + 1;
  }
  while ( __strex(v1, (unsigned int *)&dword_61ABF8) );
  __dmb(0xBu);
  v2 = v1 * KeNumberProcessors_0;
  do
  {
    result = (_DWORD *)ExAllocatePoolWithTag(512, 1044, 1819767877);
    if ( !result )
      break;
    result = (_DWORD *)RtlpInterlockedPushEntrySList(&EtwpStackLookAsideList, result);
    __dmb(0xBu);
    do
    {
      v4 = __ldrex((unsigned int *)&dword_61ABFC);
      v5 = v4 + 1;
    }
    while ( __strex(v5, (unsigned int *)&dword_61ABFC) );
    __dmb(0xBu);
  }
  while ( v5 < 2 * v2 );
  return result;
}
