// RtlIsValidProcessTrustLabelSid 
 
int __fastcall RtlIsValidProcessTrustLabelSid(int a1)
{
  char v3[16]; // [sp+0h] [bp-10h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v3[4] = 0;
  v3[5] = 19;
  if ( *(_BYTE *)(a1 + 1) != 2 || *(_BYTE *)a1 != 1 || memcmp(a1 + 2, (unsigned int)v3, 6) )
    return 0;
  if ( *(_DWORD *)(a1 + 8) )
    return 1;
  return sub_7E6DCC();
}
