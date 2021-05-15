// VfMajorAdvanceIrpStatus 
 
int __fastcall VfMajorAdvanceIrpStatus(unsigned __int8 *a1, int a2, int a3)
{
  unsigned int v6; // r3
  int (__fastcall *v7)(unsigned __int8 *, int, int); // r3
  int result; // r0

  if ( VfVerifyMode <= 2 || (MmVerifierData & 0x1000) == 0 )
    goto LABEL_12;
  v6 = *a1;
  if ( v6 > 0x1B )
  {
    if ( v6 == 255 )
      v6 = 28;
    else
      v6 = 29;
  }
  v7 = *(int (__fastcall **)(unsigned __int8 *, int, int))&ViMajorVerifierRoutines[48 * v6 + 20];
  if ( v7 && v7(a1, a2, a3) )
    return 1;
  if ( dword_908BEC )
    result = ((int (__fastcall *)(unsigned __int8 *, int, int))dword_908BEC)(a1, a2, a3);
  else
LABEL_12:
    result = 0;
  return result;
}
