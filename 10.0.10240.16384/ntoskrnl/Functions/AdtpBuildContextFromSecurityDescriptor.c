// AdtpBuildContextFromSecurityDescriptor 
 
int __fastcall AdtpBuildContextFromSecurityDescriptor(int a1, _DWORD *a2)
{
  int result; // r0
  int v4; // r3
  int v5; // [sp+0h] [bp-8h]

  v5 = 0;
  *a2 = a1;
  result = AdtpGetCapID();
  if ( result < 0 || (result = SeRmReferenceFindCapName(v5, (int)(a2 + 1), a2 + 2, v4), result < 0) )
  {
    a2[1] = 0;
    a2[2] = 0;
  }
  return result;
}
