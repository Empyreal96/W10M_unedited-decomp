// ObpAdjustAccessMask 
 
int __fastcall ObpAdjustAccessMask(_DWORD *a1, int a2)
{
  int v3; // r4

  v3 = a1[11];
  if ( !v3 )
    return 0;
  if ( RtlValidSecurityDescriptor(a1[11], a2) )
  {
    if ( (*(_WORD *)(v3 + 2) & 0x10) != 0 && (a1[5] & 0x1000000) == 0 )
      a1[4] |= SeObjectCreateSaclAccessBits(v3);
    return 0;
  }
  return -1073741703;
}
