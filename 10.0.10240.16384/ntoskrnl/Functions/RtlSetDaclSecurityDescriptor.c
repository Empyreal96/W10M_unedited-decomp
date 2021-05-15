// RtlSetDaclSecurityDescriptor 
 
int __fastcall RtlSetDaclSecurityDescriptor(int a1, int a2, int a3, int a4)
{
  __int16 v5; // r2
  int result; // r0

  if ( *(_BYTE *)a1 != 1 )
    return -1073741736;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    return -1073741703;
  if ( !a2 )
    JUMPOUT(0x7BDA92);
  v5 = *(_WORD *)(a1 + 2) | 4;
  *(_WORD *)(a1 + 2) = v5;
  *(_DWORD *)(a1 + 16) = 0;
  if ( a3 )
    *(_DWORD *)(a1 + 16) = a3;
  *(_WORD *)(a1 + 2) = v5 & 0xFFF7;
  if ( a4 )
    result = sub_7BDA8C();
  else
    result = 0;
  return result;
}
