// RtlpUnlockAtomTable 
 
int __fastcall RtlpUnlockAtomTable(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r1
  int result; // r0
  unsigned int v4; // r1
  __int16 v5; // r3

  v1 = (unsigned int *)(a1 + 8);
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 - 1, v1) );
  if ( (v2 & 2) != 0 )
    return sub_7C0260();
  result = KeAbPostRelease(a1 + 8);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x134) + 1;
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
