// IopCheckSessionDeviceAccess 
 
BOOL __fastcall IopCheckSessionDeviceAccess(int a1)
{
  int v2; // r4
  int v3; // r0
  BOOL result; // r0

  v2 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( v2 == -1 )
    v2 = 0;
  result = 1;
  if ( v2 != PsGetServerSiloServiceSessionId(-1) || IopSessionZeroAccessCheckEnabled )
  {
    v3 = IopGetSessionIdFromPDO(a1);
    if ( v3 != -1 && v2 != v3 )
      result = 0;
  }
  return result;
}
