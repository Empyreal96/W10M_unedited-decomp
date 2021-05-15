// _PnpIsNullGuidString 
 
BOOL __fastcall PnpIsNullGuidString(char *a1)
{
  return wcscmp((char *)L"{00000000-0000-0000-0000-000000000000}", a1) == 0;
}
