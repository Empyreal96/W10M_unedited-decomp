// HvpDetermineLatestLogFile 
 
BOOL __fastcall HvpDetermineLatestLogFile(__int64 *a1)
{
  __int64 v1; // kr00_8
  unsigned int v2; // r2
  BOOL result; // r0

  v1 = *a1;
  if ( (unsigned int)v1 >= HIDWORD(v1) )
  {
    v2 = v1 - HIDWORD(v1);
    result = 0;
  }
  else
  {
    v2 = HIDWORD(v1) - v1;
    result = 1;
  }
  if ( v2 > 0x7FFFFFFF )
    result = !result;
  return result;
}
