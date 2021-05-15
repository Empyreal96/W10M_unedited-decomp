// KeAbPostReleaseEx 
 
int __fastcall KeAbPostReleaseEx(int a1, int a2)
{
  int result; // r0
  int v4; // r4
  int v5; // r6
  int v6; // r2
  int v7; // r3
  __int16 v8; // r3
  unsigned __int8 *v9; // r2
  unsigned int v10; // r4

  if ( (a2 & 1) != 0 )
    return sub_54A078();
  v4 = a2 - 8 * *(unsigned __int8 *)(a2 + 12);
  v5 = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) <= 1 )
  {
    v5 = 1;
    --*(_WORD *)(v4 + 310);
  }
  *(_BYTE *)(a2 + 14) &= 0xFEu;
  result = KeAbEntryFree(a2, v4, v6);
  v7 = (a2 - v4 - 488) / 48;
  if ( v5 )
  {
    *(_BYTE *)(v4 + 484) |= 1 << v7;
    v8 = *(_WORD *)(v4 + 310) + 1;
    *(_WORD *)(v4 + 310) = v8;
    if ( !v8 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  else
  {
    __dmb(0xBu);
    result = (char)(1 << v7);
    v9 = (unsigned __int8 *)(v4 + 810);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | result, v9) );
    __dmb(0xBu);
  }
  return result;
}
