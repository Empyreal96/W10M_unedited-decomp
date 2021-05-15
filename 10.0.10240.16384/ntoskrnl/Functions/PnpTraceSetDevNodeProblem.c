// PnpTraceSetDevNodeProblem 
 
unsigned __int16 *__fastcall PnpTraceSetDevNodeProblem(unsigned __int16 *result, unsigned __int16 *a2, int a3, int a4, int a5, int a6)
{
  unsigned __int16 *v9; // r7
  int v10; // [sp+8h] [bp-D0h] BYREF
  int v11; // [sp+Ch] [bp-CCh] BYREF
  int v12; // [sp+10h] [bp-C8h] BYREF
  int v13; // [sp+14h] [bp-C4h] BYREF
  _DWORD v14[14]; // [sp+18h] [bp-C0h] BYREF
  int v15[8]; // [sp+50h] [bp-88h] BYREF
  int v16[26]; // [sp+70h] [bp-68h] BYREF

  v9 = result;
  if ( (unsigned int)dword_6174F0 > 5 )
  {
    result = (unsigned __int16 *)TlgKeywordOn((int)&dword_6174F0, 0x400000000000i64);
    if ( result )
    {
      v10 = a5;
      v11 = a3;
      v12 = a6;
      v13 = a4;
      v14[8] = v15;
      v14[9] = 0;
      v14[10] = 2;
      v14[11] = 0;
      v14[12] = *((_DWORD *)v9 + 1);
      v14[13] = 0;
      v15[0] = *v9;
      v15[1] = 0;
      v15[2] = (int)v16;
      v15[3] = 0;
      v15[4] = 2;
      v15[5] = 0;
      v15[6] = *((_DWORD *)a2 + 1);
      v15[7] = 0;
      v16[0] = *a2;
      v16[1] = 0;
      v16[2] = (int)&v11;
      v16[3] = 0;
      v16[4] = 4;
      v16[5] = 0;
      v16[6] = (int)&v13;
      v16[7] = 0;
      v16[8] = 4;
      v16[9] = 0;
      v16[10] = (int)&v10;
      v16[11] = 0;
      v16[12] = 4;
      v16[13] = 0;
      v16[14] = (int)&v12;
      v16[15] = 0;
      v16[16] = 4;
      v16[17] = 0;
      result = (unsigned __int16 *)TlgWrite(&dword_6174F0, (unsigned __int8 *)&word_413B6A + 1, 0, 0, 10, v14);
    }
  }
  return result;
}
