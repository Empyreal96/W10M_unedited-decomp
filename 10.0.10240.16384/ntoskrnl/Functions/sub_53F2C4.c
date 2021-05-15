// sub_53F2C4 
 
void sub_53F2C4()
{
  _DWORD *v0; // r5
  int v1; // r2

  while ( 1 )
  {
    v1 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    __dmb(0xBu);
    if ( v1 == *v0 )
      break;
    __dmb(0xAu);
    __yield();
  }
  JUMPOUT(0x4A8868);
}
