// PopThermalCsEntry 
 
int __fastcall PopThermalCsEntry(int result)
{
  PopSystemThermalInfo = 0;
  if ( result )
    return sub_50FEC0();
  if ( !dword_61E4A4 )
    result = PopThermalStandbyEndTracking(0);
  return result;
}
