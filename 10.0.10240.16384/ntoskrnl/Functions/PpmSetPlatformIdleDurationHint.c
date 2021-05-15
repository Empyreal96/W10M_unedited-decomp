// PpmSetPlatformIdleDurationHint 
 
int __fastcall PpmSetPlatformIdleDurationHint(__int64 a1)
{
  int v1; // r4
  unsigned __int64 v2; // kr00_8

  v1 = a1;
  if ( KeNumberProcessors_0 != 1 )
  {
    if ( HIDWORD(a1) <= 0xFFFF )
    {
      LODWORD(a1) = a1 >> 16;
      HIDWORD(a1) = (unsigned __int16)(KeNumberProcessors_0 - 1) | (v1 << 16);
      do
        v2 = __ldrexd(&PpmPlatformIdleHint);
      while ( __strexd(__PAIR64__(a1, HIDWORD(a1)), &PpmPlatformIdleHint) );
    }
    else
    {
      LODWORD(a1) = sub_527284();
    }
  }
  return a1;
}
