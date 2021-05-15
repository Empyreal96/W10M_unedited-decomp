// VfZwEnumerateDriverEntries 
 
int __fastcall VfZwEnumerateDriverEntries(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a2);
  }
  return pXdvZwEnumerateDriverEntries(a1, a2);
}
