// MiFreeBootPageTable 
 
int __fastcall MiFreeBootPageTable(int a1)
{
  int v1; // r4

  v1 = MmPfnDatabase + 24 * a1;
  if ( !*(_WORD *)(v1 + 16) )
    JUMPOUT(0x96AF36);
  if ( *(_WORD *)(v1 + 16) != 2 || (*(_DWORD *)(v1 + 12) & 0x3FFFFFFF) != 1 )
    KeBugCheckEx(26, 50529031, a1, 0, 0);
  return sub_96AEB0();
}
