// MiPfnReferenceCountIsZero 
 
int __fastcall MiPfnReferenceCountIsZero(int a1, int a2)
{
  int v2; // r2
  int v4; // r1
  int result; // r0
  int v6; // r3

  v2 = *(_DWORD *)(a1 + 12);
  if ( (v2 & 0x3FFFFFFF) != 0 )
    sub_5454EC();
  if ( (v2 & 0x40000000) != 0 )
  {
    v6 = *(unsigned __int8 *)(a1 + 19);
    if ( (v6 & 0x10) != 0 )
    {
      v6 &= 0xEFu;
      *(_BYTE *)(a1 + 19) = v6;
    }
    MiReleasePageFileSpace((int)MiSystemPartition, *(_DWORD *)(a1 + 8), 1, v6);
    result = MiInsertPageInFreeOrZeroedList(a2, 2);
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 18) & 0x10) != 0 )
      v4 = 8;
    else
      v4 = 4;
    result = MiInsertPageInList(a1, v4, v2);
  }
  return result;
}
