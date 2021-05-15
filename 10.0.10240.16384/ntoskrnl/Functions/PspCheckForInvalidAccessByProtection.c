// PspCheckForInvalidAccessByProtection 
 
BOOL __fastcall PspCheckForInvalidAccessByProtection(char a1, unsigned __int8 a2, unsigned __int8 a3)
{
  return a1 && !RtlTestProtectedAccess(a2, a3);
}
