// RtlpCopyLegacyContextArm 
 
int __fastcall RtlpCopyLegacyContextArm(int result, _DWORD *a2, int a3, _DWORD *a4)
{
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3

  result = (char)result;
  *a2 = a3 & 0x67FFFFFF;
  if ( (_BYTE)result )
  {
    if ( (a3 & 0x40000000) != 0 )
      *a2 = *a4 & 0x98000000 | a3 & 0x67FFFFFF;
    result = a3 & 0x200001;
    if ( (a3 & 0x200001) == 2097153 )
    {
      a2[16] = a4[16];
      a2[14] = a4[14];
      a2[15] = a4[15];
      a2[17] = a4[17];
    }
    if ( (a3 & 0x200002) == 2097154 )
      result = memmove((int)(a2 + 1), (int)(a4 + 1), 0x34u);
    if ( (a3 & 0x200004) == 2097156 )
    {
      a2[18] = a4[18];
      result = memmove((int)(a2 + 20), (int)(a4 + 20), 0x100u);
    }
    if ( (a3 & 0x200008) == 2097160 )
    {
      v7 = a4[85];
      v8 = a4[86];
      v9 = a4[87];
      a2[84] = a4[84];
      a2[85] = v7;
      a2[86] = v8;
      a2[87] = v9;
      v10 = a4[89];
      v11 = a4[90];
      v12 = a4[91];
      a2[88] = a4[88];
      a2[89] = v10;
      a2[90] = v11;
      a2[91] = v12;
      v13 = a4[93];
      v14 = a4[94];
      v15 = a4[95];
      a2[92] = a4[92];
      a2[93] = v13;
      a2[94] = v14;
      a2[95] = v15;
      result = a4[96];
      v16 = a4[97];
      v17 = a4[98];
      v18 = a4[99];
      a2[96] = result;
      a2[97] = v16;
      a2[98] = v17;
      a2[99] = v18;
      a2[100] = a4[100];
      a2[101] = a4[101];
    }
  }
  return result;
}
