// sub_526DC8 
 
void __fastcall sub_526DC8(int a1, _DWORD *a2)
{
  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *a2 );
  JUMPOUT(0x462236);
}
