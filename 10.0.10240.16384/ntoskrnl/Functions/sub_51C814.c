// sub_51C814 
 
void sub_51C814()
{
  _DWORD *v0; // r4
  int v1; // r5

  while ( v1 == *v0 )
  {
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xFu);
  JUMPOUT(0x447B04);
}
