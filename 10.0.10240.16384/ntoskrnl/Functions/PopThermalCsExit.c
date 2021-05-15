// PopThermalCsExit 
 
void PopThermalCsExit()
{
  PopThermalStandbyEndTracking();
  PopSystemThermalInfo = 1;
  if ( dword_61E4A4 )
  {
    sub_50FED8();
  }
  else if ( byte_61E4A1 )
  {
    PopThermalStandbyNotify(0);
    byte_61E4A1 = 0;
  }
}
