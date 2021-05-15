// IopCheckDiskName 
 
int __fastcall IopCheckDiskName(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  int v6; // r5
  __int64 v8[3]; // [sp+0h] [bp-18h] BYREF

  v8[0] = 0i64;
  *a3 = 0;
  v6 = 0;
  if ( RtlPrefixString(a1, a2, 0) )
  {
    v6 = 1;
    RtlInitAnsiString((unsigned int)v8, *a1 + *(_DWORD *)(a2 + 4));
    if ( LOWORD(v8[0]) > 0xAu )
    {
      if ( RtlPrefixString(&dword_402880, v8, 0) )
        RtlCharToInteger(HIDWORD(v8[0]) + 10, 10, a3);
    }
  }
  return v6;
}
