// sub_7CF40C 
 
void __fastcall sub_7CF40C(int a1, int a2, int a3, int a4)
{
  int v4; // r5

  if ( (v4 & a1) == 0 )
  {
    DbgPrintEx(0, 0, (int)"Error creating object type\n", a4);
    __debugbreak();
  }
  JUMPOUT(0x788BE2);
}
