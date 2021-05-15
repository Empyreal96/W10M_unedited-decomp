// MiAddTriageDumpPtes 
 
int __fastcall MiAddTriageDumpPtes(unsigned int a1)
{
  unsigned int v1; // r5
  unsigned int v2; // r6
  unsigned int i; // r4
  int v4; // r2
  int v5; // r3
  int v6; // r4
  int result; // r0

  v1 = a1;
  v2 = a1;
  for ( i = 0; i < 2; ++i )
  {
    v2 = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
    if ( !i )
    {
      v4 = (v1 >> 20) & 0xFFC;
      if ( (*(_DWORD *)(v4 - 1070596096) & 0x402) == 1026 )
        continue;
    }
    IoAddTriageDumpDataBlock(v2, 4);
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_DWORD *)(v5 + 116);
  result = MiIsAddressValid(v6 + 32, 0, v4, v5);
  if ( result )
    result = IoAddTriageDumpDataBlock(*(_DWORD *)(v6 + 32) + 4 * ((v1 >> 20) & 0xFFC), 16);
  return result;
}
