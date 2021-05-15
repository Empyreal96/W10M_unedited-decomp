// PopThermalCsExit 
 
int PopThermalCsExit()
{
  int result; // r0

  result = PopThermalStandbyEndTracking(1);
  PopSystemThermalInfo = 1;
  if ( dword_61E4A4 )
    return sub_50FED8(result);
  if ( byte_61E4A1 )
  {
    result = PopThermalStandbyNotify(0);
    byte_61E4A1 = 0;
  }
  return result;
}
