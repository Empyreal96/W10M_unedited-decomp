// sub_96F604 
 
void __fastcall sub_96F604(int a1, __int16 a2)
{
  int v2; // r4
  int v3; // r6
  _DWORD *v4; // r9
  unsigned int *v5; // r10
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r3

  __dmb(0xBu);
  do
  {
    v6 = __ldrex(v5);
    v7 = v6 + 1;
  }
  while ( __strex(v7, v5) );
  __dmb(0xBu);
  v8 = v3 + 8 * (v7 & 0x3F);
  *(_DWORD *)(v8 + 4) = v2;
  *(_WORD *)(v8 + 2) = a2;
  *(_WORD *)v8 = 121;
  if ( (*v4 & a1) != 0 )
    RtlAssert((int)"KsepShimDbDuringBoot == FALSE", (int)"minkernel\\ntos\\kshim\\ksesdb.c", 121, 0);
  JUMPOUT(0x96364A);
}
