// sub_51C03C 
 
void sub_51C03C()
{
  int v0; // r5
  int v1; // r7

  __dmb(0xAu);
  __yield();
  if ( (v0 & v1) == 0 )
    JUMPOUT(0x4462BC);
  JUMPOUT(0x4462EE);
}
