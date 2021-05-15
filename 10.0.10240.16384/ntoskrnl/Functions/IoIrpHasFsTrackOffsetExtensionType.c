// IoIrpHasFsTrackOffsetExtensionType 
 
BOOL __fastcall IoIrpHasFsTrackOffsetExtensionType(int a1)
{
  int v1; // r2
  BOOL v2; // r3

  v1 = *(_DWORD *)(a1 + 104);
  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
    v2 = 0;
  else
    v2 = v1 && (*(_WORD *)(v1 + 2) & 0x20) != 0;
  return v2;
}
