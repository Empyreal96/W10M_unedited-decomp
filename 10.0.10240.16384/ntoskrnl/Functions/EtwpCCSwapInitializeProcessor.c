// EtwpCCSwapInitializeProcessor 
 
int __fastcall EtwpCCSwapInitializeProcessor(int a1)
{
  int v1; // r4
  unsigned int i; // r5

  v1 = a1;
  for ( i = 0; i < 4; ++i )
  {
    if ( *(_DWORD *)((char *)&CCSwapNumLoggersPerClockType + v1 - a1) )
      return sub_7CFF50();
    v1 += 4;
  }
  return 0;
}
