// sub_80A380 
 
void sub_80A380()
{
  _BYTE *v0; // r4

  *v0 = 1;
  if ( CmpSystemHiveHysteresisLowSeen == 1 )
  {
    if ( CmpDoQueueSystemHiveHysteresis() == 1 )
      CmpSystemHiveHysteresisLowSeen = 0;
    else
      *v0 = 0;
  }
  JUMPOUT(0x75FB00);
}
