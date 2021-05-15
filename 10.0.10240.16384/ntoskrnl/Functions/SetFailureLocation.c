// SetFailureLocation 
 
int __fastcall SetFailureLocation(int result, int a2, int a3, int a4, int a5)
{
  int v8; // r5
  unsigned int v9; // r3
  unsigned int v10; // r3
  char v11; // [sp+8h] [bp-90h] BYREF
  int v12; // [sp+Ch] [bp-8Ch] BYREF
  int v13; // [sp+10h] [bp-88h] BYREF
  int v14; // [sp+14h] [bp-84h] BYREF
  _DWORD v15[32]; // [sp+18h] [bp-80h] BYREF

  v8 = result;
  if ( (unsigned int)dword_616398 > 5 )
  {
    result = TlgKeywordOn((int)&dword_616398, 0x200000000000i64);
    if ( result )
    {
      v15[8] = &v11;
      v15[9] = 0;
      v15[10] = 1;
      v15[11] = 0;
      v15[12] = &v14;
      v15[13] = 0;
      v15[14] = 4;
      v15[15] = 0;
      v15[16] = &v12;
      v15[17] = 0;
      v15[18] = 4;
      v15[19] = 0;
      v15[20] = &v13;
      v15[21] = 0;
      v15[22] = 4;
      v15[23] = 0;
      v11 = a2;
      v13 = a5;
      v14 = a3;
      v12 = a4;
      result = TlgWrite(&dword_616398, (unsigned __int8 *)`SetFailureLocation'::`3'::_TlgEvent + 1, 0, 0, 6, v15);
    }
  }
  if ( v8 )
  {
    if ( a2 )
    {
      v9 = *(_DWORD *)(v8 + 8);
      if ( v9 < 8 )
      {
        *(_DWORD *)(v8 + 12 * v9 + 108) = a3;
        *(_DWORD *)(v8 + 12 * *(_DWORD *)(v8 + 8) + 112) = a4;
        *(_DWORD *)(v8 + 12 * (*(_DWORD *)(v8 + 8))++ + 116) = a5;
      }
    }
    else
    {
      v10 = *(_DWORD *)(v8 + 4);
      if ( v10 < 8 )
      {
        *(_DWORD *)(v8 + 12 * v10 + 12) = a3;
        *(_DWORD *)(v8 + 12 * *(_DWORD *)(v8 + 4) + 16) = a4;
        *(_DWORD *)(v8 + 12 * (*(_DWORD *)(v8 + 4))++ + 20) = a5;
      }
    }
  }
  return result;
}
