// sub_7F0C14 
 
void sub_7F0C14()
{
  int v0; // r5
  unsigned int *v1; // r7
  unsigned int v2; // r2
  unsigned int v3; // r2

  __dmb(0xBu);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 + 1;
  }
  while ( __strex(v3, v1) );
  __dmb(0xBu);
  *(_DWORD *)(v0 + 4 * (((_BYTE)v3 - 1) & 0x7F) + 3328) = 11;
  JUMPOUT(0x785FAA);
}
