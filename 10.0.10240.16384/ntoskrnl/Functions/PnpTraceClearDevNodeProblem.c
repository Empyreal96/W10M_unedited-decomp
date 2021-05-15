// PnpTraceClearDevNodeProblem 
 
unsigned __int16 *__fastcall PnpTraceClearDevNodeProblem(unsigned __int16 *result, unsigned __int16 *a2, int a3, int a4)
{
  unsigned __int16 *v7; // r7
  int v8; // r3
  int v9; // [sp+8h] [bp-A8h] BYREF
  int v10; // [sp+Ch] [bp-A4h] BYREF
  _DWORD v11[14]; // [sp+10h] [bp-A0h] BYREF
  int v12[8]; // [sp+48h] [bp-68h] BYREF
  int v13[18]; // [sp+68h] [bp-48h] BYREF

  v7 = result;
  if ( (unsigned int)dword_6174F0 > 5 )
  {
    result = (unsigned __int16 *)TlgKeywordOn((int)&dword_6174F0, 0x400000000000i64);
    if ( result )
    {
      v11[8] = v12;
      v11[9] = 0;
      v11[10] = 2;
      v11[11] = 0;
      v8 = *((_DWORD *)v7 + 1);
      v9 = a4;
      v10 = a3;
      v11[12] = v8;
      v11[13] = 0;
      v12[0] = *v7;
      v12[1] = 0;
      v12[2] = (int)v13;
      v12[3] = 0;
      v12[4] = 2;
      v12[5] = 0;
      v12[6] = *((_DWORD *)a2 + 1);
      v12[7] = 0;
      v13[0] = *a2;
      v13[1] = 0;
      v13[2] = (int)&v10;
      v13[3] = 0;
      v13[4] = 4;
      v13[5] = 0;
      v13[6] = (int)&v9;
      v13[7] = 0;
      v13[8] = 4;
      v13[9] = 0;
      result = (unsigned __int16 *)TlgWrite(&dword_6174F0, (unsigned __int8 *)&byte_413BE5[1], 0, 0, 8, v11);
    }
  }
  return result;
}
