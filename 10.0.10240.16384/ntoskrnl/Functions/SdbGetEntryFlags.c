// SdbGetEntryFlags 
 
int __fastcall SdbGetEntryFlags(int a1, _DWORD *a2)
{
  int v3; // r0
  char v5[88]; // [sp+10h] [bp-58h] BYREF

  *a2 = 0;
  v3 = AslGuidToString(v5);
  if ( v3 >= 0 )
  {
    if ( SdbpQueryAppCompatFlagsByExeID() >= 0 )
      *a2 = 0;
    if ( SdbpQueryAppCompatFlagsByExeID() >= 0 )
      *a2 = *a2;
    *a2 &= 0xFFFu;
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbGetEntryFlags", 125, "Failed to convert EXE id to string [%x]", v3);
  }
  return 1;
}
