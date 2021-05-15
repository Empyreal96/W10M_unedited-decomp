// PspClearProcessThreadCidRefs 
 
unsigned int *__fastcall PspClearProcessThreadCidRefs(int a1, int a2, int a3)
{
  unsigned int *result; // r0
  unsigned int v6; // r1
  int v7; // r7
  int v8; // r6
  unsigned int v9; // r4
  __int16 v10; // r3

  --*(_WORD *)(a1 + 310);
  result = (unsigned int *)ExMapHandleToPointer(PspCidTable, a2);
  v6 = result[1];
  result[1] = v6 & 0x7FFFFFF;
  v7 = PspCidTable;
  v8 = v6 >> 27;
  __dmb(0xBu);
  do
    v9 = __ldrex(result);
  while ( __strex(v9 + 1, result) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(v7 + 32) )
    return (unsigned int *)sub_7F71A8();
  v10 = *(_WORD *)(a1 + 310) + 1;
  *(_WORD *)(a1 + 310) = v10;
  if ( !v10 && *(_DWORD *)(a1 + 100) != a1 + 100 )
    result = (unsigned int *)KiCheckForKernelApcDelivery((int)result);
  if ( v8 )
    result = (unsigned int *)ObDereferenceObjectEx(a3, v8);
  return result;
}
