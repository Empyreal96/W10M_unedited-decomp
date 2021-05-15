// sub_80B520 
 
void __fastcall sub_80B520(int a1, int a2, int a3, int a4)
{
  if ( a4 != 1 )
  {
    ZwSetValueKey();
    ZwFlushKey();
    ZwSetValueKey();
  }
  JUMPOUT(0x78F9C0);
}
