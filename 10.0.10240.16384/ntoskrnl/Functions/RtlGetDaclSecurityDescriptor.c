// RtlGetDaclSecurityDescriptor 
 
int __fastcall RtlGetDaclSecurityDescriptor(int a1, _BYTE *a2, _DWORD *a3, bool *a4)
{
  BOOL v5; // r3
  int v6; // r3
  int v7; // r3

  if ( *(_BYTE *)a1 == 1 )
  {
    v5 = (*(_WORD *)(a1 + 2) & 4) != 0;
    *a2 = v5;
    if ( !v5 )
      return 0;
    if ( (*(_WORD *)(a1 + 2) & 4) != 0 )
    {
      if ( (*(_WORD *)(a1 + 2) & 0x8000) == 0 )
      {
        v7 = *(_DWORD *)(a1 + 16);
        goto LABEL_7;
      }
      v6 = *(_DWORD *)(a1 + 16);
      if ( v6 )
      {
        v7 = v6 + a1;
LABEL_7:
        *a3 = v7;
        *a4 = (*(_WORD *)(a1 + 2) & 8) != 0;
        return 0;
      }
    }
    v7 = 0;
    goto LABEL_7;
  }
  return -1073741736;
}
