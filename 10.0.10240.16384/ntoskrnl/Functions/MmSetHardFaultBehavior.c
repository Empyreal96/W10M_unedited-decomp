// MmSetHardFaultBehavior 
 
int __fastcall MmSetHardFaultBehavior(int a1, int a2)
{
  unsigned int v3; // r0
  __int16 v4; // r3
  unsigned int v6; // r0

  if ( !a2 )
  {
    MiReturnResidentAvailable(10);
    do
      v3 = __ldrex(&dword_634A2C[75]);
    while ( __strex(v3 + 10, &dword_634A2C[75]) );
    *(_BYTE *)(a1 + 968) &= 0xFBu;
    v4 = *(_WORD *)(a1 + 310) + 1;
    *(_WORD *)(a1 + 310) = v4;
    if ( !v4 && *(_DWORD *)(a1 + 100) != a1 + 100 )
      KiCheckForKernelApcDelivery(v3);
    return 0;
  }
  if ( MiChargeResident(MiSystemPartition, 10, 1024) )
  {
    do
      v6 = __ldrex(&dword_634A2C[74]);
    while ( __strex(v6 + 10, &dword_634A2C[74]) );
    --*(_WORD *)(a1 + 310);
    *(_BYTE *)(a1 + 968) |= 4u;
    return 0;
  }
  return -1073741670;
}
