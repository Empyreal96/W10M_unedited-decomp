// sub_7CC1F8 
 
void __fastcall sub_7CC1F8(int a1, int a2)
{
  int v2; // r7
  int *v3; // r8
  __int16 v4; // r9
  unsigned int *v5; // r10
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r3

  __dmb(0xBu);
  do
  {
    v6 = __ldrex(v5);
    v7 = v6 + 1;
  }
  while ( __strex(v7, v5) );
  __dmb(0xBu);
  v8 = v2 + 8 * (v7 & 0x3F);
  *(_DWORD *)(v8 + 4) = a2;
  *(_WORD *)(v8 + 2) = v4;
  v9 = *v3;
  *(_WORD *)(v2 + 8 * (v7 & 0x3F)) = 753;
  if ( (v9 & a1) != 0 )
    RtlAssert((int)"IoCallbacks != NULL", (int)"minkernel\\ntos\\kshim\\kseloader.c", 753, 0);
  JUMPOUT(0x770072);
}
