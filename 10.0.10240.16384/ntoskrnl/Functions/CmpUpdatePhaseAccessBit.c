// CmpUpdatePhaseAccessBit 
 
void CmpUpdatePhaseAccessBit()
{
  int v0; // r0

  if ( CmpAccessBitForPhase != 2 )
  {
    CmpAccessBitForPhase = 2;
    v0 = 0;
    do
      v0 = CmpGetNextActiveHive(v0);
    while ( v0 );
    CmpUpdateReorganizeRegistryValues();
  }
}
