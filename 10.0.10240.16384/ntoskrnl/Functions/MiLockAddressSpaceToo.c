// MiLockAddressSpaceToo 
 
int __fastcall MiLockAddressSpaceToo(int a1, int a2)
{
  int v4; // r4
  unsigned __int8 *v5; // r5
  int result; // r0
  unsigned int v7; // r2
  unsigned __int8 *v8; // r6
  unsigned int v9; // r2
  int v10; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 310);
  v5 = (unsigned __int8 *)(a1 + 252);
  result = KeAbPreAcquire(a1 + 252, 0, 1);
  do
    v7 = __ldrex(v5);
  while ( __strex(v7 | 1, v5) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
  {
    if ( result )
      KeAbPostReleaseEx(v5, result);
    MiUnlockVad(v4, a2);
    LOCK_ADDRESS_SPACE(v4, a1);
    --*(_WORD *)(v4 + 310);
    v8 = (unsigned __int8 *)(a2 + 24);
    result = KeAbPreAcquire(a2 + 24, 0, 0);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 1, v8) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
    {
      result = sub_549F60(result);
    }
    else
    {
      if ( result )
        *(_BYTE *)(result + 14) |= 1u;
      *(_BYTE *)(v4 + 968) |= 0x80u;
      v10 = (__int16)(*(_WORD *)(v4 + 310) + 1);
      *(_WORD *)(v4 + 310) = v10;
      if ( !v10 && *(_DWORD *)(v4 + 100) != v4 + 100 )
        result = KiCheckForKernelApcDelivery(result);
    }
  }
  else
  {
    if ( result )
      *(_BYTE *)(result + 14) |= 1u;
    *(_BYTE *)(v4 + 968) |= 1u;
  }
  return result;
}
