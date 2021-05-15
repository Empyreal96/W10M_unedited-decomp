// sub_7F35CC 
 
void sub_7F35CC()
{
  int v0; // r4

  if ( (PoDebug & 1) != 0 )
    DbgPrint("PopWnfAudioPlaybackCallback: Failed to query WNF state data (Status=0x%x)\n", v0);
  JUMPOUT(0x70D11A);
}
