// MiGetPagePrivilege 
 
int MiGetPagePrivilege()
{
  int result; // r0

  if ( (MiFlags & 0x8000) != 0 )
    result = sub_53A1E0();
  else
    result = 0;
  return result;
}
