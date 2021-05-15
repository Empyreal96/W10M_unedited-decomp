// HvpLogEntryCheckHeaderChecksum 
 
BOOL __fastcall HvpLogEntryCheckHeaderChecksum(__int64 *a1)
{
  BOOL result; // r0
  _DWORD v3[4]; // [sp-4h] [bp-10h] BYREF

  result = 0;
  if ( *(_DWORD *)a1 == 1162638920 )
  {
    SymCryptMarvin32((int)a1, a1, 0x20u, v3);
    if ( !memcmp((unsigned int)(a1 + 4), (unsigned int)v3, 8) )
      result = 1;
  }
  return result;
}
