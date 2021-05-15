// sub_50EDB8 
 
void __fastcall sub_50EDB8(int a1, _DWORD *a2)
{
  do
  {
    __dmb(0xAu);
    __yield();
  }
  while ( *a2 );
  JUMPOUT(0x4D1A34);
}
