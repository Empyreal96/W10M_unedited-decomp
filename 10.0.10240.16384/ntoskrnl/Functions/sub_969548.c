// sub_969548 
 
void sub_969548()
{
  int v0; // r5
  int v1; // r6

  if ( EtwEventEnabled(v0, v1, (int)KMPnPEvt_BootDriverReinit_Start) )
    EtwWrite(v0, v1, (int)KMPnPEvt_BootDriverReinit_Start, 0);
  JUMPOUT(0x952346);
}
