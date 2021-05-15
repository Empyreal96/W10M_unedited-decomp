// VfMajorVerifyNewRequest 
 
int __fastcall VfMajorVerifyNewRequest(int result, int a2, int a3, unsigned __int8 *a4, int a5)
{
  unsigned int v6; // r4
  int v9; // r10
  int (__fastcall *v10)(int, int, int, unsigned __int8 *); // lr

  v6 = *a4;
  v9 = result;
  if ( v6 > 0x1B )
  {
    if ( v6 == 255 )
      v6 = 28;
    else
      v6 = 29;
  }
  v10 = *(int (__fastcall **)(int, int, int, unsigned __int8 *))&ViMajorVerifierRoutines[48 * v6 + 4];
  if ( v10 )
    result = v10(result, a2, a3, a4);
  if ( dword_908BDC )
    result = dword_908BDC(v9, a2, a3, a4);
  return result;
}
