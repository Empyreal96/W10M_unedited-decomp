// PiAuCreateSecurityObjects 
 
int PiAuCreateSecurityObjects()
{
  int v0; // r4
  _BYTE v2[32]; // [sp+0h] [bp-20h] BYREF

  memset(v2, 0, 28);
  v0 = PiAuCreateUserSids(v2);
  if ( v0 >= 0 )
  {
    v0 = PiAuCreateStandardSecurityObject(v2);
    if ( v0 >= 0 )
      v0 = PiAuCreateLocalSystemSecurityObject(v2);
  }
  PiAuFreeUserSids(v2);
  return v0;
}
