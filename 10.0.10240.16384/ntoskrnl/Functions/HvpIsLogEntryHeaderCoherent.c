// HvpIsLogEntryHeaderCoherent 
 
BOOL __fastcall HvpIsLogEntryHeaderCoherent(int a1, unsigned int a2)
{
  unsigned int v3; // r1
  unsigned int v4; // r2
  unsigned int v5; // r2
  BOOL result; // r0

  result = 0;
  if ( *(_DWORD *)a1 == 1162638920 )
  {
    v3 = *(_DWORD *)(a1 + 4);
    if ( v3 > 0x28 && !((a2 + (unsigned __int64)v3) >> 32) )
    {
      v4 = *(_DWORD *)(a1 + 16);
      if ( v4 )
      {
        if ( v4 <= 0x7FFFE000 && (v4 & 0xFFF) == 0 )
        {
          v5 = *(_DWORD *)(a1 + 20);
          if ( v5 )
          {
            if ( v3 >= 8 * v5 + __PAIR64__(v5 >> 29, 40) && HvpLogEntryCheckHeaderChecksum((__int64 *)a1) )
              result = 1;
          }
        }
      }
    }
  }
  return result;
}
