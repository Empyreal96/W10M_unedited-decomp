// ExInitLicenseCallback 
 
int ExInitLicenseCallback()
{
  int result; // r0

  result = ExCreateCallback(&dword_922C38, dword_8C7FBC, 1, 1);
  if ( result < 0 )
    result = sub_96C4AC();
  return result;
}
