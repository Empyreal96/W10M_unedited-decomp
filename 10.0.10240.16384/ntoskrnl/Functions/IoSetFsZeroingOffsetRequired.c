// IoSetFsZeroingOffsetRequired 
 
int __fastcall IoSetFsZeroingOffsetRequired(int a1)
{
  int v2; // r2
  int v5; // r0

  v2 = *(_DWORD *)(a1 + 104);
  if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 && v2 && (*(_WORD *)(v2 + 2) & 0x10) != 0 )
    return -1073741791;
  if ( !IopIrpHasValidCombinationOfExtensionTypes(a1, 4) )
    return -1073741637;
  v5 = IopAllocateIrpExtension(a1, 4);
  if ( !v5 )
    return -1073741670;
  *(_DWORD *)(v5 + 28) = 0;
  return 0;
}
