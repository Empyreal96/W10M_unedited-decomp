// PdcPoIdleScanEnabled 
 
int PdcPoIdleScanEnabled()
{
  int result; // r0

  if ( PopIdleScanInterval )
    result = 0;
  else
    result = -1073741823;
  return result;
}
