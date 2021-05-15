// SeCaptureAcl 
 
int __fastcall SeCaptureAcl(unsigned int a1, int a2, int a3, int a4, int a5, int a6, unsigned int *a7, unsigned int *a8)
{
  int v8; // r8
  unsigned __int16 *v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r5
  int v13; // r0

  v8 = a1;
  if ( (_BYTE)a2 )
  {
    v9 = (unsigned __int16 *)(a1 + 2);
    if ( a1 + 2 >= MmUserProbeAddress )
      v9 = (unsigned __int16 *)MmUserProbeAddress;
    v10 = *v9;
    v11 = v10;
    if ( v10 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( v10 + a1 > MmUserProbeAddress || v10 + a1 < a1 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  else
  {
    v11 = *(unsigned __int16 *)(a1 + 2);
  }
  if ( v11 >= 8 )
  {
    *a8 = (v11 + 3) & 0xFFFFFFFC;
    v13 = ExAllocatePoolWithTag(a5, v11, 1665230163);
    *a7 = v13;
    if ( !v13 )
      return -1073741670;
    memmove(v13, v8, v11);
    if ( SepCheckAcl(*a7, v11) )
      return 0;
    ExFreePoolWithTag(*a7);
    *a7 = 0;
  }
  return -1073741705;
}
