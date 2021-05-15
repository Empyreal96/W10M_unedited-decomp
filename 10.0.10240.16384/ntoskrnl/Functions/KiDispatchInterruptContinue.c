// KiDispatchInterruptContinue 
 
int KiDispatchInterruptContinue()
{
  int v0; // r3
  int v1; // r0
  int v3; // r0
  int (__fastcall *v4)(int); // [sp-4h] [bp-4h]

  v0 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __enable_irq();
  if ( *(_BYTE *)(v0 + 1753) )
  {
    *(_BYTE *)(v0 + 1753) = 0;
    v1 = KiQuantumEnd();
    return v4(v1);
  }
  v1 = *(_DWORD *)(v0 + 8);
  if ( !v1 )
    return v4(v1);
  v3 = *(_DWORD *)(v0 + 4);
  if ( (*(_BYTE *)(v3 + 2) & 4) != 0 )
  {
    v1 = KiDeferGroupSchedulingPreemption(v3, v0);
    if ( v1 )
      return v4(v1);
  }
  return KxDispatchInterrupt();
}
