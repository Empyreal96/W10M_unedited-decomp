// MiRelinkStandbyPage 
 
int __fastcall MiRelinkStandbyPage(int a1, int a2, int a3)
{
  int result; // r0
  int v7; // r1

  if ( *(_WORD *)(a1 + 16) )
  {
    if ( a2 != 0xFFFFFF )
      *(_BYTE *)(a1 + 19) ^= (*(_BYTE *)(a1 + 19) ^ a2) & 7;
    result = 1;
  }
  else if ( MiUnlinkPageFromList(a1, 0) )
  {
    if ( a2 != 0xFFFFFF )
      *(_BYTE *)(a1 + 19) ^= (*(_BYTE *)(a1 + 19) ^ a2) & 7;
    if ( a3 == 1022 || (*(_DWORD *)(a1 + 8) & 0x400) != 0 || (v7 = MiCaptureDirtyBitToPfn(a1)) == 0 )
    {
      MiInsertPageInList(a1, 4);
      result = 1;
    }
    else
    {
      MiReleasePageFileInfo(MiSystemPartition, v7, 1);
      MiInsertPageInList(a1, 8);
      result = 1;
    }
  }
  else
  {
    result = sub_516AA8();
  }
  return result;
}
