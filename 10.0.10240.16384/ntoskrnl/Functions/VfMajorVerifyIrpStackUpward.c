// VfMajorVerifyIrpStackUpward 
 
int __fastcall VfMajorVerifyIrpStackUpward(int result, unsigned __int8 *a2, int a3)
{
  unsigned int v4; // r4
  int v6; // r10
  int (__fastcall *v7)(int, unsigned __int8 *, _DWORD, int); // r7

  v4 = *a2;
  v6 = result;
  if ( v4 > 0x1B )
  {
    if ( v4 == 255 )
      v4 = 28;
    else
      v4 = 29;
  }
  v7 = *(int (__fastcall **)(int, unsigned __int8 *, _DWORD, int))&ViMajorVerifierRoutines[48 * v4 + 12];
  if ( v7 )
    result = v7(result, a2, *(_DWORD *)(a3 + 8), a3);
  if ( dword_908BE4 )
    result = dword_908BE4(v6, a2, *(_DWORD *)(a3 + 8), a3);
  return result;
}
