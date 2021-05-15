// VfZwModifyBootEntry 
 
int __fastcall VfZwModifyBootEntry(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a1);
  return pXdvZwModifyBootEntry(a1);
}
