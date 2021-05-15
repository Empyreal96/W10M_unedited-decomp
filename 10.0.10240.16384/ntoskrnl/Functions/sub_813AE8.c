// sub_813AE8 
 
void __fastcall sub_813AE8(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, unsigned int a18)
{
  int v18; // r10
  unsigned int v19; // r3
  int v20; // r2
  int v21; // r3
  int v22; // r0

  v19 = a3 >> 28;
  if ( a3 >> 28 == a18 >> 28 )
  {
    if ( v19 != 1 && v19 != 2 )
    {
      if ( v19 != 3 )
      {
        if ( ((a3 ^ a18) & ~v18) != 0 )
          goto LABEL_16;
LABEL_17:
        JUMPOUT(0x7A60BE);
      }
      v20 = a3 & ~v18;
      if ( !v20 )
        goto LABEL_17;
      v21 = a18 & ~v18;
LABEL_15:
      if ( v20 != v21 )
        goto LABEL_16;
      goto LABEL_17;
    }
    v22 = (a3 >> 20) & 0xF;
    if ( (!v22 || v22 == ((a18 >> 20) & 0xF)) && ((a3 & 0xFFFFF) == 0 || (a3 & 0xFFFFF) == (a18 & 0xFFFFF)) )
    {
      v20 = HIBYTE(a3) & 0xF;
      if ( !v20 )
        goto LABEL_17;
      v21 = HIBYTE(a18) & 0xF;
      goto LABEL_15;
    }
  }
LABEL_16:
  JUMPOUT(0x7A60C2);
}
