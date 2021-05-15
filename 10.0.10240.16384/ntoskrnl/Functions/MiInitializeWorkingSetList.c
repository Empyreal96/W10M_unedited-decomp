// MiInitializeWorkingSetList 
 
int __fastcall MiInitializeWorkingSetList(_DWORD *a1)
{
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r6
  int v5; // r8
  int *v6; // lr
  int v7; // r1

  MEMORY[0xC0402008] = a1[135];
  MEMORY[0xC0402024] = 4;
  MEMORY[0xC04020FC] = -1069537344;
  MEMORY[0xC0402034] = dword_6342A0;
  MEMORY[0xC0402038] = dword_6342A4;
  MEMORY[0xC0402030] = dword_6342A8;
  MEMORY[0xC04027C0] = -1070596087;
  if ( (*(_DWORD *)(MmPfnDatabase + 24 * (MEMORY[0xC0300C00] >> 12) + 20) & 0xFFFFF) != 24
                                                                                      * (MEMORY[0xC0300C00] >> 12)
                                                                                      / 24 )
    return sub_7F56B0();
  v2 = -1069537340;
  v3 = -1069539328;
  v4 = 2;
  do
  {
    *(_DWORD *)v2 = v3 | 9;
    v5 = (v3 >> 10) & 0x3FFFFC;
    v6 = (int *)(MmPfnDatabase + 24 * (*(_DWORD *)(v5 - 0x40000000) >> 12));
    if ( (v6[5] & 0xFFFFF) != 24 * (*(_DWORD *)(v5 - 0x40000000) >> 12) / 24 )
      *v6 = (v2 + 1069537344) >> 2;
    v2 += 4;
    --v4;
    v3 = v5 - 0x40000000;
  }
  while ( v4 );
  v7 = (v2 + 1069537344) >> 2;
  MEMORY[0xC0402004] = v7;
  MEMORY[0xC040200C] = v7;
  a1[136] = 1;
  a1[137] = 1;
  a1[138] = v7;
  a1[139] = v7;
  a1[69] = v7;
  MEMORY[0xC0402010] = 527;
  return MiPopulateWorkingSetFreeList((int)(a1 + 123), v7, 0x20Fu);
}
