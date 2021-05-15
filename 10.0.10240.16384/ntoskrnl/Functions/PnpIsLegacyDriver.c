// PnpIsLegacyDriver 
 
BOOL __fastcall PnpIsLegacyDriver(int a1)
{
  return !*(_DWORD *)(*(_DWORD *)(a1 + 24) + 4) && (*(_DWORD *)(a1 + 8) & 2) != 0;
}
