// sub_51DC58 
 
void sub_51DC58()
{
  int v0; // r4
  int v1; // r6
  int v2; // r7
  unsigned int *v3; // r1
  unsigned int v4; // r2
  unsigned int v5; // r2

  if ( v0 == 1 )
  {
    if ( !*(_DWORD *)(v1 + 12) )
      __brkdiv0();
    JUMPOUT(0x44B8AE);
  }
  v3 = (unsigned int *)(v0 & ~v2);
  __dmb(0xBu);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 - 1;
  }
  while ( __strex(v5, v3) );
  __dmb(0xBu);
  if ( !v5 )
    KeSetEvent((int)(v3 + 1), 0, 0);
  JUMPOUT(0x44B8D4);
}
