// FsRtlIsNtstatusExpected 
 
BOOL __fastcall FsRtlIsNtstatusExpected(int a1)
{
  int v1; // r3

  if ( a1 <= -1073741676 )
  {
    if ( a1 == -1073741676 )
      return 0;
    if ( a1 == 0x80000000 )
      return 1;
    if ( a1 <= -2147483645 || a1 == -1073741819 || a1 == -1073741795 )
      return 0;
    if ( a1 <= -1073741755 )
      return 1;
    if ( a1 <= -1073741753 )
      return 0;
    v1 = -1073741684;
  }
  else
  {
    if ( a1 == -1073741674 || a1 == -1073741654 || a1 == -1073740791 )
      return 0;
    v1 = -1073740768;
  }
  return a1 != v1;
}
