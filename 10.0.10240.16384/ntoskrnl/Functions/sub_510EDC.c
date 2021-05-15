// sub_510EDC 
 
void sub_510EDC()
{
  int v0; // r7
  int v1; // r9
  int v2; // r10
  __int16 v3; // lr
  unsigned int v4; // r2
  int v5; // r1
  _WORD *v6; // r3

  v4 = 2;
  v5 = v2 + 4;
  do
  {
    if ( *(unsigned __int16 *)(v5 + 1024) != v0 )
      goto LABEL_10;
    ++v4;
    v5 += 2;
  }
  while ( v4 <= 0xF );
  if ( *(unsigned __int16 *)(v2 + 1026) != v0 )
  {
    v6 = (_WORD *)(v2 + 1056);
    do
      *v6++ = v3;
    while ( v6 != (_WORD *)(v2 + 1056 + v1) );
    JUMPOUT(0x429406);
  }
LABEL_10:
  JUMPOUT(0x429408);
}
