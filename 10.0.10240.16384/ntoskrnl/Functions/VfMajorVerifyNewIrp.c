// VfMajorVerifyNewIrp 
 
int __fastcall VfMajorVerifyNewIrp(int result, int a2, unsigned __int8 *a3, int a4)
{
  unsigned int v5; // r4
  int v8; // r10
  int (__fastcall *v9)(int, int, unsigned __int8 *, int); // r6

  v5 = *a3;
  v8 = result;
  if ( v5 > 0x1B )
  {
    if ( v5 == 255 )
      v5 = 28;
    else
      v5 = 29;
  }
  v9 = *(int (__fastcall **)(int, int, unsigned __int8 *, int))&ViMajorVerifierRoutines[48 * v5 + 32];
  if ( v9 )
    result = v9(result, a2, a3, a4);
  if ( dword_908BF8 )
    result = dword_908BF8(v8, a2, a3, a4);
  return result;
}
