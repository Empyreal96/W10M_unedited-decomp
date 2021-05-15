// PsQueryThreadStartAddress 
 
int __fastcall PsQueryThreadStartAddress(int a1, int a2)
{
  char v2; // r3
  int result; // r0

  if ( (*(_DWORD *)(a1 + 76) & 0x400) != 0 || !a2 )
    return *(_DWORD *)(a1 + 924);
  v2 = *(_BYTE *)(a1 + 968);
  __dmb(0xBu);
  if ( (v2 & 8) != 0 )
    result = 0;
  else
    result = sub_50E16C();
  return result;
}
