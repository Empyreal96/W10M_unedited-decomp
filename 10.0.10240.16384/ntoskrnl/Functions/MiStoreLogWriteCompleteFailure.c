// MiStoreLogWriteCompleteFailure 
 
int __fastcall MiStoreLogWriteCompleteFailure(int result)
{
  int v1; // r5
  _DWORD *v2; // r4
  int v3; // r2
  int v4; // [sp+8h] [bp-48h] BYREF
  _DWORD v5[16]; // [sp+10h] [bp-40h] BYREF

  v1 = result;
  v2 = (_DWORD *)dword_634CA0;
  if ( dword_634CA0 && *(_DWORD *)dword_634CA0 > 5u )
  {
    result = TlgKeywordOn(dword_634CA0, 2i64);
    if ( result )
    {
      v5[8] = &v4;
      v5[9] = 0;
      v5[10] = 4;
      v5[11] = 0;
      v4 = v1;
      result = MmTlgWrite(v2, (unsigned __int8 *)&byte_414081[1], v3, (int)byte_414081, 3, v5);
    }
  }
  return result;
}
