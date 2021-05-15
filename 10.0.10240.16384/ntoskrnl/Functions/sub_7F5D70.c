// sub_7F5D70 
 
void __fastcall sub_7F5D70(int a1)
{
  int v1; // r6

  if ( v1 <= 0 )
  {
    if ( v1 )
      KeBugCheckEx(24, 0, a1, 32, v1);
    JUMPOUT(0x717632);
  }
  JUMPOUT(0x717604);
}
