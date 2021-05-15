// BgkResumeInitialize 
 
int BgkResumeInitialize()
{
  int result; // r0

  byte_64A430 = 0;
  result = dword_64B0A4;
  if ( dword_64B0A4 )
  {
    result = BgLibraryInitialize(dword_64B0A4, -1);
    if ( result >= 0 )
      byte_64A430 = 1;
  }
  return result;
}
