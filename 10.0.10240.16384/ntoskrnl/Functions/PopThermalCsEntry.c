// PopThermalCsEntry 
 
void __fastcall PopThermalCsEntry(int result)
{
  PopSystemThermalInfo = 0;
  if ( result )
  {
    sub_50FEC0();
  }
  else if ( !dword_61E4A4 )
  {
    PopThermalStandbyEndTracking();
  }
}
