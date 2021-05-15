// KiCheckForKernelApcDelivery 
 
int __fastcall KiCheckForKernelApcDelivery(int a1)
{
  int (__fastcall **v1)(int); // r3
  int v2; // r0

  if ( KeGetCurrentIrql(a1) )
  {
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x79) = 1;
    v1 = &HalRequestSoftwareInterrupt;
    v2 = 1;
  }
  else
  {
    KfRaiseIrql(1);
    KiDeliverApc(0, 0, 0);
    v1 = &KfLowerIrql;
    v2 = 0;
  }
  return (*v1)(v2);
}
