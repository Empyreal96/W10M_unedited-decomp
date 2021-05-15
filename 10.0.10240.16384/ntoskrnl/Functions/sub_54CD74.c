// sub_54CD74 
 
void __fastcall sub_54CD74(int a1, unsigned int a2)
{
  int v2; // r4
  int v3; // r6
  int v4; // lr
  unsigned int v5; // r5
  unsigned int *v6; // r7
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r0
  unsigned int v10; // r0

  if ( v4 != v2 )
  {
    v5 = v4 - v2;
    v6 = (unsigned int *)(*(_DWORD *)(a1 + 4) + 4 * (a2 >> 5));
    if ( (unsigned int)(v3 + v4 - v2) <= 0x20 )
    {
      if ( v5 != 32 )
      {
        __dmb(0xBu);
        do
          v10 = __ldrex(v6);
        while ( __strex(v10 & ~(((1 << v5) - 1) << v3), v6) );
        goto LABEL_13;
      }
      *v6 = 0;
    }
    else
    {
      if ( v3 )
      {
        __dmb(0xBu);
        do
          v7 = __ldrex(v6);
        while ( __strex(v7 & ~(((1 << (32 - v3)) - 1) << v3), v6) );
        __dmb(0xBu);
        v5 -= 32 - v3;
        ++v6;
      }
      if ( v5 >= 0x20 )
      {
        v8 = v5 >> 5;
        do
        {
          v5 -= 32;
          --v8;
          *v6++ = 0;
        }
        while ( v8 );
      }
      if ( v5 )
      {
        __dmb(0xBu);
        do
          v9 = __ldrex(v6);
        while ( __strex(v9 & ~((1 << v5) - 1), v6) );
LABEL_13:
        __dmb(0xBu);
        goto LABEL_19;
      }
    }
  }
LABEL_19:
  JUMPOUT(0x4D6E2A);
}
