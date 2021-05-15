// KeAbPreWait 
 
int __fastcall KeAbPreWait(int result)
{
  int v1; // r4

  v1 = result;
  *(_BYTE *)(result + 16) |= 2u;
  if ( *(int *)(result + 16) < 0 )
    result = KiAbEntryRemoveFromTree(result);
  *(_BYTE *)(v1 + 13) |= 1u;
  *(_BYTE *)(v1 + 16) &= 0xFDu;
  return result;
}
