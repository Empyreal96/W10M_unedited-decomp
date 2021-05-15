// sub_7F644C 
 
void sub_7F644C()
{
  char v0; // r5
  char v1; // r6

  if ( (v0 & 0xF8) == 8 && (v1 & 2) != 0 )
    JUMPOUT(0x718052);
  JUMPOUT(0x718034);
}
