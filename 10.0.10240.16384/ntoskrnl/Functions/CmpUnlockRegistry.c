// CmpUnlockRegistry 
 
void CmpUnlockRegistry()
{
  int v0; // r0
  unsigned int v1; // r1
  __int16 v2; // r3

  if ( !CmpPuntBoot )
  {
    v0 = ExReleaseResourceLite((int)&CmpRegistryLock);
    v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v2 = *(_WORD *)(v1 + 0x134) + 1;
    *(_WORD *)(v1 + 308) = v2;
    if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
      KiCheckForKernelApcDelivery(v0);
    PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
  }
}
