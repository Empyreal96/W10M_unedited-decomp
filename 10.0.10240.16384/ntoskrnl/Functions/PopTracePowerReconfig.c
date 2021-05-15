// PopTracePowerReconfig 
 
void PopTracePowerReconfig()
{
  int v0; // r6
  unsigned int v1; // r7
  BOOL v2; // r8
  unsigned int v3; // [sp+8h] [bp-88h] BYREF
  int v4; // [sp+Ch] [bp-84h] BYREF
  BOOL v5; // [sp+10h] [bp-80h] BYREF
  int v6; // [sp+14h] [bp-7Ch] BYREF
  _DWORD v7[30]; // [sp+18h] [bp-78h] BYREF

  v0 = dword_61EDA8;
  v1 = 0;
  v2 = (dword_61ED84 & 1) != 0;
  if ( dword_61EDA8 )
    v1 = 100 * dword_61ED88 / (unsigned int)dword_61EDA8;
  if ( (unsigned int)dword_6163C8 > 5 )
  {
    if ( TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64) )
    {
      v5 = v2;
      v6 = v0;
      v3 = v1;
      v4 = dword_61ED6C;
      v7[8] = &v4;
      v7[9] = 0;
      v7[10] = 4;
      v7[11] = 0;
      v7[12] = &v6;
      v7[13] = 0;
      v7[14] = 4;
      v7[15] = 0;
      v7[16] = &v3;
      v7[17] = 0;
      v7[18] = 4;
      v7[19] = 0;
      v7[20] = &v5;
      v7[21] = 0;
      v7[22] = 4;
      v7[23] = 0;
      TlgWrite(&dword_6163C8, (unsigned __int8 *)dword_414528, 0, 0, 6, v7);
    }
  }
}
