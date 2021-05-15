// VfMajorTestStartedPdoStack 
 
int __fastcall VfMajorTestStartedPdoStack(int a1)
{
  int result; // r0
  unsigned int i; // r4
  int (__fastcall *v4)(int); // r3

  result = IovUtilIsVerifiedDeviceStack(a1);
  if ( result && VfVerifyMode > 2 )
  {
    for ( i = 0; i <= 0x1B; ++i )
    {
      v4 = *(int (__fastcall **)(int))&ViMajorVerifierRoutines[48 * i + 40];
      if ( v4 )
        result = v4(a1);
    }
    if ( dword_908C00 )
      result = ((int (__fastcall *)(int))dword_908C00)(a1);
  }
  return result;
}
