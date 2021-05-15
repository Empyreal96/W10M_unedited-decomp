// PiAuIsLocalSystem 
 
int __fastcall PiAuIsLocalSystem(int a1, _BYTE *a2)
{
  int v3; // r1
  int result; // r0

  v3 = PiAuLocalSystemSecurityObject;
  *a2 = 0;
  result = PiAuVerifyAccessToObject(983040, v3, PiAuLocalSystemSecurityMapping, a1);
  if ( result < 0 )
    *a2 = 0;
  return result;
}
