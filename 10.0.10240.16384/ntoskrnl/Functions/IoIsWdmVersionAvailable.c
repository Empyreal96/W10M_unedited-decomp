// IoIsWdmVersionAvailable 
 
int __fastcall IoIsWdmVersionAvailable(unsigned int a1)
{
  int result; // r0

  if ( a1 < 6 )
    result = 1;
  else
    result = sub_7F103C();
  return result;
}
