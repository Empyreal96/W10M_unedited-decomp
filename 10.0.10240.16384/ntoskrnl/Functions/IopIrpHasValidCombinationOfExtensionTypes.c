// IopIrpHasValidCombinationOfExtensionTypes 
 
int __fastcall IopIrpHasValidCombinationOfExtensionTypes(int a1, int a2)
{
  int v2; // r2
  __int16 v3; // r0

  if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 )
  {
    v2 = *(_DWORD *)(a1 + 104);
    if ( v2 )
    {
      if ( ((1 << a2) & 0x32) != 0 )
      {
        v3 = *(_WORD *)(v2 + 2);
        if ( (v3 & 0x32) != 0 && (v3 & 0x32) != 1 << a2 )
        {
          if ( a2 == 1 || (v3 & 2) == 0 )
            return 0;
          *(_WORD *)(v2 + 2) = v3 & 0xFFFE;
          *(_DWORD *)(v2 + 28) = 0;
          *(_DWORD *)(v2 + 32) = 0;
        }
      }
    }
  }
  return 1;
}
