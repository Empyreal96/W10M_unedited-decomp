// SeAuditHeaderRequired 
 
BOOL __fastcall SeAuditHeaderRequired(void *a1)
{
  BOOL result; // r0
  BOOL v2; // r3
  int v3; // r3

  result = 0;
  if ( a1 == IoFileObjectType )
  {
    v2 = byte_61D400 || byte_61D401;
    if ( v2 || (byte_61D418 || byte_61D419 ? (v3 = 1) : (v3 = 0), v3) )
      result = 1;
  }
  return result;
}
