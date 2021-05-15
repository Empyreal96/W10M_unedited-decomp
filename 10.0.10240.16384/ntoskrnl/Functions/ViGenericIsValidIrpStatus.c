// ViGenericIsValidIrpStatus 
 
int __fastcall ViGenericIsValidIrpStatus(int a1, unsigned int a2)
{
  return IoIsValidIrpStatus(a2);
}
