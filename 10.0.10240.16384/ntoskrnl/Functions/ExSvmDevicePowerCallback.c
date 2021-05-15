// ExSvmDevicePowerCallback 
 
int ExSvmDevicePowerCallback()
{
  return ((int (__cdecl *)())HalIommuDispatch[16])();
}
