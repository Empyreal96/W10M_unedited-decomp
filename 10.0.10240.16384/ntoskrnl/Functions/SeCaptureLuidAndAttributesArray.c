// SeCaptureLuidAndAttributesArray 
 
int __fastcall SeCaptureLuidAndAttributesArray(unsigned int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int *a8, unsigned int *a9)
{
  int v9; // r4
  unsigned int v11; // r6
  int v12; // r0

  v9 = a1;
  if ( a2 )
  {
    if ( a2 > 0x41 )
      return -1073741811;
    v11 = 12 * a2;
    *a9 = (12 * a2 + 3) & 0xFFFFFFFC;
    if ( (_BYTE)a3 && v11 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( v11 + a1 > MmUserProbeAddress || v11 + a1 < a1 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v12 = ExAllocatePoolWithTag(1, 12 * a2, 1967940947);
    *a8 = v12;
    if ( !v12 )
      return -1073741670;
    memmove(v12, v9, v11);
  }
  else
  {
    *a8 = 0;
    *a9 = 0;
  }
  return 0;
}
