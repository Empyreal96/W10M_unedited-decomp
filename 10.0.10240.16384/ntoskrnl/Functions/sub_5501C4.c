// sub_5501C4 
 
void __fastcall sub_5501C4(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r6
  unsigned int *v4; // r5
  int v5; // r2
  int v6; // r4
  int v7; // r2
  unsigned int v8; // r0
  unsigned int v9; // r3
  unsigned int v10; // r0

  v4 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(a2 + 6408) + 4) + 4 * (v3 >> 5));
  v5 = v3 & 0x1F;
  if ( (v3 & 0x1F) == 0 )
    goto LABEL_5;
  v6 = 32 - v5;
  __dmb(0xBu);
  v7 = ((1 << (32 - v5)) - 1) << v5;
  do
    v8 = __ldrex(v4);
  while ( __strex(v8 | v7, v4) );
  __dmb(0xBu);
  v2 = 1024 - v6;
  ++v4;
  if ( v2 >= 0x20 )
  {
LABEL_5:
    v9 = v2 >> 5;
    do
    {
      v2 -= 32;
      *v4++ = -1;
      --v9;
    }
    while ( v9 );
  }
  if ( v2 )
  {
    __dmb(0xBu);
    do
      v10 = __ldrex(v4);
    while ( __strex(v10 | ((1 << v2) - 1), v4) );
    __dmb(0xBu);
  }
  JUMPOUT(0x4EBFD6);
}
