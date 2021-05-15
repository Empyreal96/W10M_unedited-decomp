// PopSqmThermalUsermodeEvent 
 
int __fastcall PopSqmThermalUsermodeEvent(int result, int a2, int a3, int a4, char a5)
{
  __int16 v8; // r9
  int v9; // [sp+8h] [bp-A0h] BYREF
  BOOL v10; // [sp+Ch] [bp-9Ch] BYREF
  int v11; // [sp+10h] [bp-98h] BYREF
  _DWORD v12[26]; // [sp+18h] [bp-90h] BYREF
  int v13[10]; // [sp+80h] [bp-28h] BYREF

  v8 = result;
  if ( (unsigned int)dword_6163C8 > 5 )
  {
    result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
    if ( result )
    {
      v12[8] = &v11;
      v12[9] = 0;
      v12[10] = 4;
      v12[11] = 0;
      v12[12] = &v9;
      v12[13] = 0;
      v12[14] = 4;
      v12[15] = 0;
      v12[16] = &v10;
      v12[17] = 0;
      v12[18] = 4;
      v12[19] = 0;
      v12[20] = v13;
      v12[21] = 0;
      v12[22] = 2;
      v12[23] = 0;
      v12[24] = a2;
      v12[25] = 0;
      v13[0] = (unsigned __int16)(2 * v8);
      v13[1] = 0;
      v10 = a5 != 0;
      v11 = a3;
      v9 = a4;
      result = TlgWrite(&dword_6163C8, (unsigned __int8 *)&byte_414705[1], 0, 0, 7, v12);
    }
  }
  return result;
}
