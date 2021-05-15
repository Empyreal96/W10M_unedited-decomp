// ResFwpPageInBackground 
 
int ResFwpPageInBackground()
{
  int result; // r0

  if ( (dword_619018 & 0xC00) != 3072 && (dword_619018 & 0x100000) == 0 )
  {
    if ( dword_619060 )
      result = sub_8DEDF4();
  }
  return result;
}
