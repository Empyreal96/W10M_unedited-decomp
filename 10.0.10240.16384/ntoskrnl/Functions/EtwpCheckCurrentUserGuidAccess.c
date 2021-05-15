// EtwpCheckCurrentUserGuidAccess 
 
int __fastcall EtwpCheckCurrentUserGuidAccess(int a1, int a2, int a3, int a4)
{
  return EtwpCheckGuidAccess(a1, a2, 0, a4);
}
