// sub_537CA4 
 
void __fastcall sub_537CA4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  unsigned int v8; // r1
  unsigned int *v9; // r7
  unsigned int v10; // r2
  unsigned int v11; // r0
  unsigned int v12; // r0
  unsigned int v13; // r3
  int v14; // r2
  unsigned int v15; // r0

  if ( ((*(char *)(((a8 & 0xFFFFFC00) >> 13) + dword_634C94) >> (((a8 & 0xFFFFFC00) >> 10) & 7)) & 1) != 0 )
  {
    v8 = ((a8 & 0xFFFFFC00) >> 10) & 0x1F;
    v9 = (unsigned int *)(dword_634C94 + 4 * ((a8 & 0xFFFFFC00) >> 15));
    LOBYTE(v10) = 1;
    if ( v8 + 1 <= 0x20 )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( __strex(v11 & ~(1 << v8), v9) );
LABEL_15:
      __dmb(0xBu);
      goto LABEL_16;
    }
    if ( !v8 )
      goto LABEL_13;
    __dmb(0xBu);
    do
      v12 = __ldrex(v9);
    while ( __strex(v12 & ~(((1 << (32 - v8)) - 1) << v8), v9) );
    __dmb(0xBu);
    v10 = v8 - 31;
    ++v9;
    if ( v8 - 31 >= 0x20 )
    {
      v13 = v10 >> 5;
      do
      {
        v10 -= 32;
        --v13;
        *v9++ = 0;
      }
      while ( v13 );
    }
    if ( v10 )
    {
LABEL_13:
      __dmb(0xBu);
      v14 = ~((1 << v10) - 1);
      do
        v15 = __ldrex(v9);
      while ( __strex(v15 & v14, v9) );
      goto LABEL_15;
    }
  }
LABEL_16:
  MiFreeLargePageMemory(a8 & 0xFFFFFC00);
  JUMPOUT(0x495C4A);
}
