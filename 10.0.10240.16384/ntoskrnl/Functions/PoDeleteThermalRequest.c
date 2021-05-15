// PoDeleteThermalRequest 
 
unsigned int __fastcall PoDeleteThermalRequest(unsigned int a1)
{
  PopDeactiveThermalRequest();
  PoDestroyReasonContext(*(_DWORD **)(a1 + 12));
  return ExFreePoolWithTag(a1);
}
