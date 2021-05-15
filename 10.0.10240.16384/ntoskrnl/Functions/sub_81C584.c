// sub_81C584 
 
void sub_81C584()
{
  int v0; // r4
  int v1; // r5

  if ( EtwEventEnabled(v0, v1, (int)KMPnPEvt_SystemStartPnPEnum_Start) )
    EtwWrite(v0, v1, (int)KMPnPEvt_SystemStartPnPEnum_Start, 0);
  JUMPOUT(0x7BC9CA);
}
