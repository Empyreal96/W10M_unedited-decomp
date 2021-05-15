// IopAddRunTimeTriageDataBlocks 
 
int __fastcall IopAddRunTimeTriageDataBlocks(unsigned int a1, int *a2, __int64 *a3, int a4, unsigned int a5, unsigned int a6)
{
  unsigned int v6; // r5
  unsigned int v8; // r4
  int v10; // r7
  int v11; // r0
  int result; // r0
  __int16 *v13; // r4
  unsigned int v14; // r3
  unsigned int v15; // t1

  v6 = 0;
  v8 = (*(_DWORD *)(a4 + 64) - 1) & 0xFFFFF000;
  if ( v8 )
  {
    v10 = 0;
    do
    {
      if ( !MiIsAddressValid(v8, 0, (int)a3, a4) )
        break;
      v6 += v10;
      if ( !v8 )
        break;
      v8 -= 4096;
      v10 = 4096;
    }
    while ( v6 < 0x100 );
    if ( v6 >= 0x100 )
      v6 = 256;
  }
  v11 = IopGetMaxValidMemorySize(*(_DWORD *)(a4 + 64), 256);
  result = IopAddTriageDumpDataBlock(a1, a2, a3, *(_DWORD *)(a4 + 64) - v6, v11 + v6);
  v13 = &IopRunTimeContextOffsets;
  do
  {
    v14 = *(_DWORD *)((unsigned __int16)*v13 + a4);
    if ( v14 < a5 || v14 >= a6 )
      result = IopAddTriageDumpDataBlock(a1, a2, a3, v14 & 0xFFFFF000, 0x1000u);
    v15 = (unsigned __int16)v13[1];
    ++v13;
  }
  while ( v15 < 0xFFFF );
  return result;
}
