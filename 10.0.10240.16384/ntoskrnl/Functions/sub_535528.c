// sub_535528 
 
void sub_535528()
{
  int v0; // r9
  int v1; // r10
  int v2; // lr
  char v3; // r3
  unsigned int v4; // r2
  unsigned int *v5; // r2
  unsigned int v6; // r4

  v3 = *(_BYTE *)(v1 + 19);
  if ( (v3 & 8) != 0 )
    v4 = 5;
  else
    v4 = v3 & 7;
  if ( (*(_DWORD *)(v2 + 40) & 7u) > v4 )
    *(_BYTE *)(v1 + 19) = v3 & 0xF8 | *(_BYTE *)(v2 + 40) & 7;
  __dmb(0xBu);
  v5 = (unsigned int *)(v1 + 12);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 & 0x7FFFFFFF, v5) );
  MiUnlockProtoPoolPage(v0, 17);
  JUMPOUT(0x490234);
}
