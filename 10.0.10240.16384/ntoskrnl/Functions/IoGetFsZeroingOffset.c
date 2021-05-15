// IoGetFsZeroingOffset 
 
int __fastcall IoGetFsZeroingOffset(int a1)
{
  int result; // r0

  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 || !*(_DWORD *)(a1 + 104) )
    result = -1073741275;
  else
    result = sub_523644();
  return result;
}
