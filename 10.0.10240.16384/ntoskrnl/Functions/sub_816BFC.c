// sub_816BFC 
 
void sub_816BFC()
{
  int v0; // r5
  int v1; // r7

  ZwClose();
  ZwAcceptConnectPort();
  if ( v1 )
    PspDereferenceSiloObject(v1);
  if ( !v0 )
    JUMPOUT(0x7ADD5C);
  JUMPOUT(0x7ADD56);
}
