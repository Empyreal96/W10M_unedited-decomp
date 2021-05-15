// RtlGetSaclSecurityDescriptor 
 
int __fastcall RtlGetSaclSecurityDescriptor(int a1, _BYTE *a2, _DWORD *a3, bool *a4)
{
  BOOL v5; // r3
  int v7; // r3
  int v8; // r3

  if ( *(_BYTE *)a1 == 1 )
  {
    v5 = (*(_WORD *)(a1 + 2) & 0x10) != 0;
    *a2 = v5;
    if ( !v5 )
      return 0;
    if ( (*(_WORD *)(a1 + 2) & 0x10) == 0 )
      goto LABEL_9;
    if ( (*(_WORD *)(a1 + 2) & 0x8000) == 0 )
    {
      v8 = *(_DWORD *)(a1 + 12);
      goto LABEL_8;
    }
    v7 = *(_DWORD *)(a1 + 12);
    if ( v7 )
      v8 = v7 + a1;
    else
LABEL_9:
      v8 = 0;
LABEL_8:
    *a3 = v8;
    *a4 = (*(_WORD *)(a1 + 2) & 0x20) != 0;
    return 0;
  }
  return -1073741736;
}
