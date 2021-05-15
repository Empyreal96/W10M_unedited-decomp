// RtlTestProtectedAccess 
 
BOOL __fastcall RtlTestProtectedAccess(unsigned __int8 a1, unsigned __int8 a2)
{
  return (a2 & 7) == 0 || (a1 & 7u) >= (a2 & 7u) && ((1 << (a2 >> 4)) & RtlProtectedAccess[3 * (a1 >> 4)]) != 0;
}
