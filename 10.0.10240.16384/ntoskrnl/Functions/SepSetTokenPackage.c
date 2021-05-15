// SepSetTokenPackage 
 
int __fastcall SepSetTokenPackage(int a1, int a2)
{
  int v4; // r7
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r0

  if ( *(_DWORD *)(a1 + 480) )
    return sub_7C5148();
  v4 = 4 * *(unsigned __int8 *)(a2 + 1) + 11;
  v5 = ExAllocatePoolWithTag(1, v4 & 0xFFFFFFFC, 1767073107);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  RtlCopySid(v4 & 0xFFFFFFFC, v5, a2);
  v7 = *(_DWORD *)(a1 + 480);
  if ( v7 )
  {
    ExFreePoolWithTag(v7);
    *(_DWORD *)(a1 + 480) = 0;
  }
  *(_DWORD *)(a1 + 480) = v6;
  return 0;
}
