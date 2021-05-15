// VfMajorIsValidIrpStatus 
 
int __fastcall VfMajorIsValidIrpStatus(unsigned __int8 *a1, int a2)
{
  unsigned int v3; // r3
  int (__fastcall *v5)(unsigned __int8 *, int); // r3
  int result; // r0

  v3 = *a1;
  if ( v3 > 0x1B )
  {
    if ( v3 == 255 )
      v3 = 28;
    else
      v3 = 29;
  }
  v5 = *(int (__fastcall **)(unsigned __int8 *, int))&ViMajorVerifierRoutines[48 * v3 + 24];
  if ( (!v5 || v5(a1, a2)) && dword_908BF0 )
    result = ((int (__fastcall *)(unsigned __int8 *, int))dword_908BF0)(a1, a2);
  else
    result = 0;
  return result;
}
