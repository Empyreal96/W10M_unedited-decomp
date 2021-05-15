// BgpGetBitsPerPixel 
 
int BgpGetBitsPerPixel()
{
  if ( dword_618FD0 == 4 )
    return 24;
  if ( dword_618FD0 == 5 )
    return 32;
  return 1;
}
