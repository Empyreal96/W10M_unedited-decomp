// sub_51B7C8 
 
void sub_51B7C8()
{
  int v0; // r6
  unsigned int v1; // r2
  unsigned int v2; // r1
  int v3; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  if ( !ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v0], 1) )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v3 = (__int16)(*(_WORD *)(v2 + 0x134) + 1);
    *(_WORD *)(v2 + 308) = v3;
    if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
      KiCheckForKernelApcDelivery(0);
    JUMPOUT(0x4435A6);
  }
  JUMPOUT(0x443638);
}
