// sub_8E538C 
 
void sub_8E538C()
{
  int v0; // r4
  int v1; // r6

  if ( RtlEqualUnicodeString((unsigned __int16 *)(v0 + 16), (unsigned __int16 *)(v1 + 44), 1) )
    JUMPOUT(0x8E5046);
  JUMPOUT(0x8E5040);
}
