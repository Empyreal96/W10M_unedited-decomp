// sub_7CE634 
 
void __fastcall sub_7CE634(int a1, unsigned int *a2)
{
  int v2; // r7
  int *v3; // r8
  int v4; // lr
  unsigned int v5; // r5
  unsigned int v6; // r5
  int v7; // r3
  int v8; // r3

  __dmb(0xBu);
  do
  {
    v5 = __ldrex(a2);
    v6 = v5 + 1;
  }
  while ( __strex(v6, a2) );
  __dmb(0xBu);
  v7 = v2 + 8 * (v6 & 0x3F);
  *(_DWORD *)(v7 + 4) = a1;
  *(_WORD *)(v7 + 2) = 3;
  v8 = *v3;
  *(_WORD *)(v2 + 8 * (v6 & 0x3F)) = 719;
  if ( (v8 & v4) != 0 )
    RtlAssert((int)"ResultString != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 719, 0);
  JUMPOUT(0x787CB4);
}
