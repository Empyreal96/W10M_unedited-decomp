// NtIsUILanguageComitted 
 
int NtIsUILanguageComitted()
{
  int result; // r0

  if ( PsUILanguageComitted )
    result = 0;
  else
    result = -1073741772;
  return result;
}
