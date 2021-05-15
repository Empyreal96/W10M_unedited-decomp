// EtwpCheckLoggerControlAccess 
 
int __fastcall EtwpCheckLoggerControlAccess(int a1, int a2)
{
  int v4; // r4
  int v5; // r5

  if ( !PsEqualCurrentServerSilo(*(_DWORD *)(a2 + 652)) )
    return -1073741790;
  v4 = EtwpReferenceLoggerSecurityDescriptor(a2);
  v5 = EtwpAccessCheck(v4, a1, 0);
  EtwpDereferenceLoggerSecurityDescriptor(a2, v4);
  return v5;
}
