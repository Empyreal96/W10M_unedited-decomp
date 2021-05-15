// PiAuDoesClientHaveAccess 
 
int __fastcall PiAuDoesClientHaveAccess(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v5[2]; // [sp+8h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  LOBYTE(v5[0]) = 0;
  if ( PiAuVerifyAccessToObject(a1, PiAuSecurityObject, (int)PiAuSecurityObjectMapping, 0, v5) < 0 )
    result = 0;
  else
    result = LOBYTE(v5[0]);
  return result;
}
