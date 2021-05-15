// sub_7EF7A0 
 
void sub_7EF7A0()
{
  _DWORD *v0; // r4
  int v1; // r5
  unsigned __int16 **v2; // r3
  int v3; // r3
  int v4; // r3

  v2 = (unsigned __int16 **)v0[4];
  if ( !v2 || RtlEqualSid((unsigned __int16 *)(v1 + 8), *v2) )
  {
    v4 = v0[7];
    if ( (v4 & 1) == 0 )
    {
      v0[7] = v4 | 1;
      JUMPOUT(0x783FB4);
    }
    v3 = -1073741811;
  }
  else
  {
    v3 = -1073741790;
  }
  v0[6] = v3;
  JUMPOUT(0x784062);
}
