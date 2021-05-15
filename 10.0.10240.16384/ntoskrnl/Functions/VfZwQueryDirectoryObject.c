// VfZwQueryDirectoryObject 
 
int __fastcall VfZwQueryDirectoryObject(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, int a7)
{
  int v12; // [sp+Ch] [bp-1Ch]

  v12 = a4;
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a6);
    ViZwCheckVirtualAddress(a7);
  }
  return pXdvZwQueryDirectoryObject(a1, a2, a3, a4, a5, a6, a7, v12);
}
