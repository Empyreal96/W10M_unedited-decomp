// PnpTraceDeviceRemoveProcessVeto 
 
unsigned __int16 *__fastcall PnpTraceDeviceRemoveProcessVeto(unsigned __int16 *result, unsigned __int16 *a2, unsigned __int16 *a3)
{
  unsigned __int16 *v5; // r7
  _DWORD v6[14]; // [sp+8h] [bp-98h] BYREF
  int v7[8]; // [sp+40h] [bp-60h] BYREF
  int v8[8]; // [sp+60h] [bp-40h] BYREF
  int v9[8]; // [sp+80h] [bp-20h] BYREF

  v5 = result;
  if ( (unsigned int)dword_6174F0 > 5 )
  {
    result = (unsigned __int16 *)TlgKeywordOn((int)&dword_6174F0, 0x400000000000i64);
    if ( result )
    {
      v6[8] = v7;
      v6[9] = 0;
      v6[10] = 2;
      v6[11] = 0;
      v6[12] = *((_DWORD *)v5 + 1);
      v6[13] = 0;
      v7[0] = *v5;
      v7[1] = 0;
      v7[2] = (int)v8;
      v7[3] = 0;
      v7[4] = 2;
      v7[5] = 0;
      v7[6] = *((_DWORD *)a2 + 1);
      v7[7] = 0;
      v8[0] = *a2;
      v8[1] = 0;
      v8[2] = (int)v9;
      v8[3] = 0;
      v8[4] = 2;
      v8[5] = 0;
      v8[6] = *((_DWORD *)a3 + 1);
      v8[7] = 0;
      v9[0] = *a3;
      v9[1] = 0;
      result = (unsigned __int16 *)TlgWrite(&dword_6174F0, (unsigned __int8 *)&word_413A4A + 1, 0, 0, 8, v6);
    }
  }
  return result;
}
