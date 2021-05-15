// sub_968E24 
 
void sub_968E24()
{
  int v0; // r4
  int v1; // r5

  if ( EtwEventEnabled(v0, v1, (int)KMPnPEvt_SystemStart_Start) )
    EtwWrite(v0, v1, (int)KMPnPEvt_SystemStart_Start, 0);
  JUMPOUT(0x950E94);
}
