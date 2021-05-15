// MiStoreLogNotCandidate 
 
int __fastcall MiStoreLogNotCandidate(int result, int a2)
{
  _DWORD *v3; // r4
  int v4; // r5
  int v5; // r2
  int v6; // [sp+8h] [bp-58h] BYREF
  int v7; // [sp+Ch] [bp-54h] BYREF
  _DWORD v8[20]; // [sp+10h] [bp-50h] BYREF

  v3 = (_DWORD *)dword_634CA0;
  v4 = result;
  if ( dword_634CA0 && result != -1073741401 && *(_DWORD *)dword_634CA0 > 5u )
  {
    result = TlgKeywordOn(dword_634CA0, 2i64);
    if ( result )
    {
      v8[8] = &v7;
      v8[9] = 0;
      v8[10] = 4;
      v8[11] = 0;
      v8[12] = &v6;
      v8[13] = 0;
      v8[14] = 4;
      v8[15] = 0;
      v6 = a2;
      v7 = v4;
      result = MmTlgWrite(v3, (unsigned __int8 *)dword_4140B4 + 1, v5, (int)dword_4140B4, 4, v8);
    }
  }
  return result;
}
