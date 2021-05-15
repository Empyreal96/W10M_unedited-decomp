// PopTraceThermalStandbyComplete 
 
int __fastcall PopTraceThermalStandbyComplete(int result, int a2, int a3)
{
  int v5; // r7
  int v6; // [sp+8h] [bp-78h] BYREF
  int v7; // [sp+Ch] [bp-74h] BYREF
  int v8; // [sp+10h] [bp-70h] BYREF
  _DWORD v9[26]; // [sp+18h] [bp-68h] BYREF

  v5 = result;
  if ( (unsigned int)dword_6163C8 > 5 )
  {
    result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
    if ( result )
    {
      v9[8] = &v8;
      v9[9] = 0;
      v9[10] = 4;
      v9[11] = 0;
      v9[12] = &v6;
      v9[13] = 0;
      v9[14] = 4;
      v9[15] = 0;
      v9[16] = &v7;
      v9[17] = 0;
      v9[18] = 4;
      v9[19] = 0;
      v7 = a3;
      v8 = v5;
      v6 = a2;
      result = TlgWrite(&dword_6163C8, (unsigned __int8 *)dword_4143B8, 0, 0, 5, v9);
    }
  }
  return result;
}
