// RtlSetOwnerSecurityDescriptor 
 
int __fastcall RtlSetOwnerSecurityDescriptor(int a1, int a2, int a3)
{
  __int16 v4; // r2

  if ( *(_BYTE *)a1 != 1 )
    return -1073741736;
  v4 = *(_WORD *)(a1 + 2);
  if ( (v4 & 0x8000) != 0 )
    return -1073741703;
  *(_DWORD *)(a1 + 4) = 0;
  if ( a2 )
    *(_DWORD *)(a1 + 4) = a2;
  *(_WORD *)(a1 + 2) = v4 & 0xFFFE;
  if ( a3 )
    *(_WORD *)(a1 + 2) = v4 & 0xFFFE | 1;
  return 0;
}
