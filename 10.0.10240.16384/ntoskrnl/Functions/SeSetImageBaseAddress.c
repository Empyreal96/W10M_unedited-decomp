// SeSetImageBaseAddress 
 
int SeSetImageBaseAddress()
{
  int result; // r0

  if ( dword_61D8C0 )
    result = dword_61D8C0();
  else
    result = -1073741637;
  return result;
}
