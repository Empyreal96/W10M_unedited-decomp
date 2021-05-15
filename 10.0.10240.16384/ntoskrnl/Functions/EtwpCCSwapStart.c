// EtwpCCSwapStart 
 
int __fastcall EtwpCCSwapStart(int a1)
{
  if ( !CCSwapNumLoggersPerClockType[a1] )
    return sub_7D0924();
  ++CCSwapNumLoggersPerClockType[a1];
  return 0;
}
