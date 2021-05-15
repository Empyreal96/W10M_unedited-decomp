// VfMajorVerifyIrpStackDownward 
 
int __fastcall VfMajorVerifyIrpStackDownward(int result, int a2, int a3, unsigned __int8 *a4, int a5, int a6)
{
  unsigned int v7; // r4
  void (__fastcall *v10)(int, int, int, unsigned __int8 *, _DWORD, int, int); // r7
  int v11; // [sp+10h] [bp-20h]

  v7 = *a4;
  v11 = result;
  if ( v7 > 0x1B )
  {
    if ( v7 == 255 )
      v7 = 28;
    else
      v7 = 29;
  }
  v10 = *(void (__fastcall **)(int, int, int, unsigned __int8 *, _DWORD, int, int))&ViMajorVerifierRoutines[48 * v7 + 8];
  if ( v10 )
  {
    v10(result, a2, a3, a4, *(_DWORD *)(a5 + 8), a5, a6);
    result = v11;
  }
  if ( dword_908BE0 )
    result = dword_908BE0(result, a2, a3, a4, *(_DWORD *)(a5 + 8), a5, a6);
  return result;
}
