// IopCompleteIrpInFileObjectList 
 
int __fastcall IopCompleteIrpInFileObjectList(int a1, int a2)
{
  int v3; // r4

  if ( !*(_BYTE *)(a1 + 33) )
  {
    v3 = *(_DWORD *)(a1 + 24);
    if ( (v3 & 0xC0000000) == -1073741824 || (*(_DWORD *)(a2 + 44) & 0x2000000) != 0 && v3 >= 0 )
      return 0;
  }
  if ( !*(_DWORD *)(a2 + 108) )
    return sub_520D2C();
  IopInsertIrpInCompletionQueue();
  return 1;
}
