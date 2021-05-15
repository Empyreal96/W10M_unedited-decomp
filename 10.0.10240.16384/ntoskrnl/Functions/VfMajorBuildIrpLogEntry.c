// VfMajorBuildIrpLogEntry 
 
int __fastcall VfMajorBuildIrpLogEntry(int a1, int a2, int a3, int a4)
{
  int result; // r0
  unsigned int v9; // r4
  int (__fastcall *v10)(int, int, int, int); // r4

  result = 0;
  if ( dword_908C04 )
    result = dword_908C04(a1);
  v9 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 96) - 40);
  if ( v9 > 0x1B )
  {
    if ( v9 == 255 )
      v9 = 28;
    else
      v9 = 29;
  }
  v10 = *(int (__fastcall **)(int, int, int, int))&ViMajorVerifierRoutines[48 * v9 + 44];
  if ( v10 )
    result = v10(a1, a2, a3, a4);
  return result;
}
