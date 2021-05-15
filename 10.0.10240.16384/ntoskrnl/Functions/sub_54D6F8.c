// sub_54D6F8 
 
void sub_54D6F8(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  void (*v6)(void); // r3
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( dword_637604 )
    dword_637604((int *)va);
  if ( dword_6328F4 )
  {
    v6 = *(void (**)(void))(dword_6328F4 + 20);
    if ( v6 )
    {
      v6();
      JUMPOUT(0x4E1EDA);
    }
  }
  JUMPOUT(0x4E1ED8);
}
