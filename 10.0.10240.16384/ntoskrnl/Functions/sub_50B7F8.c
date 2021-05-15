// sub_50B7F8 
 
void sub_50B7F8()
{
  int *v0; // r5
  int v1; // r6
  void (__fastcall *v2)(_DWORD); // r3
  void **v3; // r3
  int v4; // r0

  if ( dword_6328F4 )
  {
    v2 = *(void (__fastcall **)(_DWORD))(dword_6328F4 + 68);
    if ( v2 )
      v2(0);
  }
  if ( v1 == 4 )
  {
    v3 = &off_616268;
    v4 = 4;
  }
  else
  {
    v3 = &off_618110;
    v4 = 3;
  }
  dword_6328F4 = (int)v3;
  *v0 = v4;
  JUMPOUT(0x464122);
}
