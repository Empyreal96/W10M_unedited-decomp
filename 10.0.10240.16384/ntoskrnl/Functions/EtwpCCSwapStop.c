// EtwpCCSwapStop 
 
int __fastcall EtwpCCSwapStop(int result, int a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r5
  unsigned int v4; // lr
  void **v5; // r4
  _DWORD *v6; // r3
  int v7; // r7

  v2 = 0;
  v3 = KeNumberProcessors_0;
  v4 = KeNumberProcessors_0;
  if ( KeNumberProcessors_0 )
  {
    v5 = &KiProcessorBlock;
    do
    {
      if ( v2 >= v3 )
        v6 = 0;
      else
        v6 = *v5;
      v7 = v6[899];
      if ( *(_DWORD *)(v7 + 4 * result + 1884) )
      {
        *(_BYTE *)(v7 + result + 1880) = 1;
        v3 = KeNumberProcessors_0;
      }
      ++v2;
      ++v5;
    }
    while ( v2 < v4 );
  }
  if ( a2 )
    --CCSwapNumLoggersPerClockType[result];
  return result;
}
