// SepSetSqmObjectName 
 
int __fastcall SepSetSqmObjectName(int a1, int a2, int a3)
{
  int v4; // [sp+8h] [bp-88h] BYREF
  int v5[33]; // [sp+Ch] [bp-84h] BYREF

  v5[0] = 1;
  v4 = 2;
  v5[1] = (int)&dword_41CF18;
  v5[2] = 0;
  v5[3] = 16;
  v5[4] = 0;
  v5[5] = (int)&dword_41CF14;
  v5[6] = 0;
  v5[7] = 4;
  v5[8] = 0;
  v5[9] = (int)&unk_6534E0;
  v5[10] = 0;
  v5[11] = 4;
  v5[12] = 0;
  v5[13] = (int)v5;
  v5[14] = 0;
  v5[15] = 4;
  v5[16] = 0;
  v5[17] = (int)&v4;
  v5[18] = 0;
  v5[19] = 4;
  v5[20] = 0;
  v5[21] = (int)&dword_41CF10;
  v5[22] = 0;
  v5[23] = 4;
  v5[24] = 0;
  v5[25] = *(_DWORD *)(a3 + 4);
  v5[26] = 0;
  v5[27] = *(unsigned __int16 *)(a3 + 2);
  v5[28] = 0;
  return EtwWrite(a1, a2, (int)SQM_ADD_LEGACYSTREAMROW, 0);
}
