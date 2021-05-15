// VfMajorVerifyFinalIrpStack 
 
int __fastcall VfMajorVerifyFinalIrpStack(int result, unsigned __int8 *a2)
{
  unsigned int v3; // r3
  int v4; // r6
  int (__fastcall *v5)(int, unsigned __int8 *); // r3

  v3 = *a2;
  v4 = result;
  if ( v3 > 0x1B )
  {
    if ( v3 == 255 )
      v3 = 28;
    else
      v3 = 29;
  }
  v5 = *(int (__fastcall **)(int, unsigned __int8 *))&ViMajorVerifierRoutines[48 * v3 + 36];
  if ( v5 )
    result = v5(result, a2);
  if ( dword_908BFC )
    result = ((int (__fastcall *)(int, unsigned __int8 *))dword_908BFC)(v4, a2);
  return result;
}
