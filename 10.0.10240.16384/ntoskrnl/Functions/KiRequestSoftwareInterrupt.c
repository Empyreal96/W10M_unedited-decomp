// KiRequestSoftwareInterrupt 
 
int __fastcall KiRequestSoftwareInterrupt(int a1, int a2)
{
  return HalRequestSoftwareInterrupt(a2);
}
