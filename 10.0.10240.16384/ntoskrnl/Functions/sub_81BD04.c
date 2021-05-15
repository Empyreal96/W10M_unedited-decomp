// sub_81BD04 
 
void sub_81BD04()
{
  int v0; // r4
  _BYTE *v1; // r6

  CmpSystemHiveHysteresisHighSeen = 1;
  if ( CmpDoQueueSystemHiveHysteresis(v0) )
    *v1 = 0;
  else
    CmpSystemHiveHysteresisHighSeen = 0;
  JUMPOUT(0x7BC16E);
}
