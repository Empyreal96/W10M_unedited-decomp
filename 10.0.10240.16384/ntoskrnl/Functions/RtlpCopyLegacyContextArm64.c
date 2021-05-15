// RtlpCopyLegacyContextArm64 
 
int __fastcall RtlpCopyLegacyContextArm64(int result, _DWORD *a2, int a3, _DWORD *a4)
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

  result = (char)result;
  *a2 = a3 & 0x67FFFFFF;
  if ( (_BYTE)result )
  {
    if ( (a3 & 0x40000000) != 0 )
      *a2 = *a4 & 0x98000000 | a3 & 0x67FFFFFF;
    result = a3 & 0x400001;
    if ( (a3 & 0x400001) == 4194305 )
    {
      a2[66] = a4[66];
      a2[67] = a4[67];
      a2[64] = a4[64];
      a2[65] = a4[65];
      a2[1] = a4[1];
    }
    if ( (a3 & 0x400002) == 4194306 )
    {
      result = memmove((int)(a2 + 2), (int)(a4 + 2), 0xE8u);
      a2[60] = a4[60];
      a2[61] = a4[61];
      a2[62] = a4[62];
      a2[63] = a4[63];
    }
    if ( (a3 & 0x400004) == 4194308 )
    {
      a2[197] = a4[197];
      a2[196] = a4[196];
      result = memmove((int)(a2 + 68), (int)(a4 + 68), 0x200u);
    }
    if ( (a3 & 0x400008) == 4194312 )
    {
      memmove((int)(a2 + 206), (int)(a4 + 206), 0x40u);
      v7 = a4[199];
      v8 = a4[200];
      v9 = a4[201];
      a2[198] = a4[198];
      a2[199] = v7;
      a2[200] = v8;
      a2[201] = v9;
      v10 = a4[203];
      v11 = a4[204];
      v12 = a4[205];
      a2[202] = a4[202];
      a2[203] = v10;
      a2[204] = v11;
      a2[205] = v12;
      result = a4[224];
      v13 = a4[225];
      v14 = a4[226];
      v15 = a4[227];
      a2[224] = result;
      a2[225] = v13;
      a2[226] = v14;
      a2[227] = v15;
      a2[222] = a4[222];
      a2[223] = a4[223];
    }
  }
  return result;
}
