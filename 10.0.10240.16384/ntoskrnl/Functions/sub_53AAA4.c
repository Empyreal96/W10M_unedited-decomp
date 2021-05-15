// sub_53AAA4 
 
void sub_53AAA4()
{
  int v0; // r4
  unsigned __int8 *v1; // r5
  int v2; // r3
  unsigned int v3; // r2

  do
  {
    __dmb(0xAu);
    __yield();
    v2 = *(_DWORD *)(v0 + 12);
    __dmb(0xBu);
  }
  while ( v2 < 0 );
  do
    v3 = __ldrex(v1);
  while ( __strex(v3 | 0x80, v1) );
  JUMPOUT(0x49B0DA);
}
