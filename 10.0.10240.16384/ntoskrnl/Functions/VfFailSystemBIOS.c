// VfFailSystemBIOS 
 
int __fastcall VfFailSystemBIOS(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int varg_r0; // [sp+18h] [bp+8h]
  int varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  result = VfIsVerificationEnabled();
  if ( result )
    result = VerifierBugCheckIfAppropriate(a1, a2, 0);
  return result;
}
