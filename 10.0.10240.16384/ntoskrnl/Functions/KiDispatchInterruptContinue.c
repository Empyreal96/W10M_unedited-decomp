// KiDispatchInterruptContinue 
 
int KiDispatchInterruptContinue()
{
  unsigned int v0; // r3
  int v1; // r0
  int (__fastcall *v3)(int); // [sp-4h] [bp-4h]

  v0 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __enable_irq();
  if ( *(_BYTE *)(v0 + 1753) )
  {
    *(_BYTE *)(v0 + 1753) = 0;
    v1 = KiQuantumEnd();
    return v3(v1);
  }
  v1 = *(_DWORD *)(v0 + 8);
  if ( !v1 )
    return v3(v1);
  if ( (*(_BYTE *)(*(_DWORD *)(v0 + 4) + 2) & 4) != 0 )
  {
    v1 = KiDeferGroupSchedulingPreemption();
    if ( v1 )
      return v3(v1);
  }
  return KxDispatchInterrupt();
}
