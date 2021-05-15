// RtlGetGroupSecurityDescriptor 
 
int __fastcall RtlGetGroupSecurityDescriptor(int a1, _DWORD *a2, bool *a3)
{
  int v3; // r3
  int v4; // r3

  if ( *(_BYTE *)a1 != 1 )
    return -1073741736;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( v3 )
      v4 = v3 + a1;
    else
      v4 = 0;
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 8);
  }
  *a2 = v4;
  *a3 = (*(_WORD *)(a1 + 2) & 2) != 0;
  return 0;
}
