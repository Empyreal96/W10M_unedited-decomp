// sub_7D64DC 
 
void sub_7D64DC()
{
  char v0; // r6

  if ( RtlIsSandboxedToken(0, v0) )
    JUMPOUT(0x6DC70E);
  JUMPOUT(0x6DC78A);
}
