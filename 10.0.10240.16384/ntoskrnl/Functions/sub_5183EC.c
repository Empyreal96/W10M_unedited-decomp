// sub_5183EC 
 
void sub_5183EC()
{
  char v0; // r3

  __dmb(0xBu);
  v0 = PspDebugFlags;
  __dmb(0xBu);
  if ( (v0 & 2) != 0 )
    __debugbreak();
  JUMPOUT(0x43D654);
}
