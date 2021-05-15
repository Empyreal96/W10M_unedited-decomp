// sub_517E14 
 
void sub_517E14()
{
  int *v0; // r4
  _DWORD *v1; // r6
  int *v2; // r7
  _BYTE *v3; // r0
  _BYTE *v4; // r5
  int v5; // r0
  unsigned __int16 v6; // r3

  while ( 1 )
  {
    v3 = AuthzBasepAllocateSecurityAttributeValue(*((unsigned __int16 *)v0 + 16));
    v4 = v3;
    if ( !v3 )
      break;
    v5 = (int)(v3 + 40);
    *((_DWORD *)v4 + 6) = v0[6];
    *((_DWORD *)v4 + 7) = v0[7];
    v6 = *((_WORD *)v0 + 16);
    *((_DWORD *)v4 + 9) = v5;
    *((_WORD *)v4 + 16) = v6;
    memmove(v5, v0[9], v6);
    AuthzBasepAddSecurityAttributeValueToLists(v1, v4, 0, 1);
    v0 = (int *)*v0;
    if ( v0 == v2 )
      JUMPOUT(0x43A95E);
  }
  JUMPOUT(0x43AA20);
}
