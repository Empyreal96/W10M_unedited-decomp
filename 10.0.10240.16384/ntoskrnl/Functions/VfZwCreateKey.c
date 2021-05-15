// VfZwCreateKey 
 
int __fastcall VfZwCreateKey(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v12; // [sp+Ch] [bp-1Ch]

  v12 = a4;
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckObjectAttributes(a3);
    ViZwCheckUnicodeString(a5);
    ViZwCheckVirtualAddress(a7);
  }
  return pXdvZwCreateKey(a1, a2, a3, a4, a5, a6, a7, v12);
}
