// RtlSidDominatesForTrust 
 
int __fastcall RtlSidDominatesForTrust(int a1, int a2, _BYTE *a3)
{
  unsigned int v7; // r3

  *a3 = 0;
  if ( a1 && !RtlIsValidProcessTrustLabelSid(a1) )
    return -1073741811;
  if ( !a2 )
  {
LABEL_3:
    *a3 = 1;
    return 0;
  }
  if ( !RtlIsValidProcessTrustLabelSid(a2) )
    return -1073741811;
  v7 = *(_DWORD *)(a2 + 8);
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 8) >= v7 && *(_DWORD *)(a1 + 12) >= *(_DWORD *)(a2 + 12) )
      goto LABEL_3;
  }
  else if ( !v7 )
  {
    goto LABEL_3;
  }
  *a3 = 0;
  return 0;
}
