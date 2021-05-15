// PspCaptureCreateInfo 
 
int __fastcall PspCaptureCreateInfo(char a1, unsigned int a2, int a3)
{
  char v3; // r3

  if ( a1 )
  {
    if ( (a2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 64) = *(_BYTE *)(a2 + 64);
  }
  if ( *(_DWORD *)(a2 + 4) || *(_DWORD *)a2 != 72 )
    return -1073741811;
  *(_BYTE *)(a3 + 8) = (*(_BYTE *)(a3 + 8) ^ (32 * *(_BYTE *)(a2 + 8))) & 0x7F ^ (32 * *(_BYTE *)(a2 + 8));
  *(_BYTE *)(a3 + 9) = *(_BYTE *)(a3 + 9) & 0xFE | ((*(_BYTE *)(a2 + 8) & 8) != 0);
  *(_DWORD *)(a3 + 96) = *(_DWORD *)(a2 + 12);
  v3 = *(_BYTE *)(a3 + 8) ^ (*(_BYTE *)(a3 + 8) ^ (2 * *(_BYTE *)(a2 + 8))) & 2;
  *(_BYTE *)(a3 + 8) = v3;
  *(_BYTE *)(a3 + 8) ^= (v3 ^ (8 * *(_BYTE *)(a2 + 8))) & 0x10;
  *(_WORD *)(a3 + 10) = *(_WORD *)(a2 + 10);
  *(_DWORD *)(a3 + 24) = a2;
  return 0;
}
