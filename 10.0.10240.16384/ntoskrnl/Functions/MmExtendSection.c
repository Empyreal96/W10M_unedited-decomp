// MmExtendSection 
 
int __fastcall MmExtendSection(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(MiSectionControlArea(a1) + 28) & 0x400) != 0 )
    result = -1073741689;
  else
    result = sub_7D53C4();
  return result;
}
