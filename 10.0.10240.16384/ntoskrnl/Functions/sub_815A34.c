// sub_815A34 
 
void sub_815A34()
{
  _DWORD *v0; // r4
  int v1; // r5
  int v2; // r0
  int v3; // r3

  if ( v1 )
    v2 = 5;
  else
    v2 = 7;
  WmipSendEnableDisableRequest(v2, v0, v1);
  if ( v1 )
    v3 = v0[14];
  else
    v3 = v0[15];
  if ( v3 )
    JUMPOUT(0x7ABCB0);
  JUMPOUT(0x7ABCC8);
}
