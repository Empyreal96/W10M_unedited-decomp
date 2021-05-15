// WmipSecurityMethod 
 
int __fastcall WmipSecurityMethod(int a1, int a2, int a3, unsigned int a4, int a5, int a6)
{
  switch ( a2 )
  {
    case 3:
      return ObAssignObjectSecurityDescriptor(a1, a4, a3, a5);
    case 1:
      return ObQuerySecurityDescriptorInfo(a1, a3, a4, a5);
    case 2:
      return ObDeassignSecurity(a6, 2, a3, a5);
  }
  return sub_818540(a6, a2, a3, a5);
}
