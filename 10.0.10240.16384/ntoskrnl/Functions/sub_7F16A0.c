// sub_7F16A0 
 
void sub_7F16A0()
{
  int v0; // r5
  int v1; // r0
  int v2; // r2
  int v3; // r3
  int v4; // r0

  while ( 1 )
  {
    v4 = MmGetNextSession();
    if ( !v4 )
      break;
    v1 = MmGetSessionId(v4);
    if ( v1 )
    {
      if ( v0 != v1 )
        PopSetSessionUserStatus(v1, 0, v2, v3);
    }
  }
  JUMPOUT(0x78C6FA);
}
