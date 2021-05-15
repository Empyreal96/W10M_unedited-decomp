// PpDevCfgProcessDevice 
 
int PpDevCfgProcessDevice()
{
  int result; // r0

  if ( PiDevCfgMode )
    result = PiDevCfgProcessDevice();
  else
    result = -1073741637;
  return result;
}
