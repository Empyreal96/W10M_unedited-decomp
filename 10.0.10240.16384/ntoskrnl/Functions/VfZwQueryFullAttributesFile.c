// VfZwQueryFullAttributesFile 
 
int __fastcall VfZwQueryFullAttributesFile(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckObjectAttributes(a1);
    ViZwCheckVirtualAddress(a2);
  }
  return pXdvZwQueryFullAttributesFile(a1, a2);
}
