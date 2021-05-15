// IopFreeIrpExtension 
 
int __fastcall IopFreeIrpExtension(int a1, int a2, int a3)
{
  char v4; // r3
  int result; // r0

  v4 = *(_BYTE *)(a1 + 39);
  result = *(_DWORD *)(a1 + 104);
  if ( (v4 & 0x80) != 0 )
    return sub_52A348(result);
  if ( result )
  {
    if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 && (*(_WORD *)(result + 2) & 0x20) != 0 )
      *(_DWORD *)(result + 28) = 0;
    if ( a2 != -1 )
      JUMPOUT(0x52A352);
    *(_WORD *)(result + 2) = 0;
    if ( !*(_WORD *)(result + 2) && (*(_WORD *)result & 1) != 0 )
    {
      if ( a3 )
        JUMPOUT(0x52A362);
    }
  }
  return result;
}
