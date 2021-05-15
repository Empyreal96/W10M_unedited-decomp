// WheapSqmDwordCommon 
 
int __fastcall WheapSqmDwordCommon(int a1, int a2, int a3, int a4)
{
  int v5; // [sp+8h] [bp-58h] BYREF
  int v6; // [sp+Ch] [bp-54h] BYREF
  _DWORD v7[20]; // [sp+10h] [bp-50h] BYREF

  v6 = a4;
  v7[0] = a1;
  v7[2] = v7;
  v7[3] = 0;
  v7[4] = 4;
  v7[5] = 0;
  v7[6] = dword_41D4AC;
  v7[7] = 0;
  v7[8] = 16;
  v7[9] = 0;
  v7[10] = &v5;
  v7[11] = 0;
  v7[12] = 4;
  v7[13] = 0;
  v7[14] = &v6;
  v7[15] = 0;
  v7[16] = 4;
  v7[17] = 0;
  v5 = a3;
  return EtwWrite(WheapEtwHandle, unk_6197CC, a2, 0);
}
