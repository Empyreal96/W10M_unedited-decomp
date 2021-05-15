// IopParentToRawTranslation 
 
int __fastcall IopParentToRawTranslation(int a1)
{
  int v2; // r3
  int result; // r0

  v2 = *(_DWORD *)(a1 + 32);
  result = 0;
  if ( !v2 || *(_BYTE *)(a1 + 80) == 8 )
    return -1073741811;
  if ( !*(_DWORD *)(a1 + 12) )
    result = sub_80DEA0(0);
  return result;
}
