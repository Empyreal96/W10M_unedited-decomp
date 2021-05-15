// AnFwDisplayFade 
 
int AnFwDisplayFade()
{
  int result; // r0

  if ( (dword_619018 & 0x2000) != 0 )
    result = 0;
  else
    result = sub_8DEE44();
  return result;
}
