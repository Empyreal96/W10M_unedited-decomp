// sub_7CE594 
 
void sub_7CE594()
{
  int v0; // r8
  int *v1; // r9
  unsigned int *v2; // r10
  int v3; // lr
  unsigned int v4; // r4
  unsigned int v5; // r4
  int v6; // r3
  int v7; // r3

  __dmb(0xBu);
  do
  {
    v4 = __ldrex(v2);
    v5 = v4 + 1;
  }
  while ( __strex(v5, v2) );
  __dmb(0xBu);
  v6 = v0 + 8 * (v5 & 0x3F);
  *(_DWORD *)(v6 + 4) = v3;
  *(_WORD *)(v6 + 2) = 4;
  v7 = *v1;
  *(_WORD *)(v0 + 8 * (v5 & 0x3F)) = 422;
  if ( (v7 & 4) != 0 )
    RtlAssert((int)"EnginePath != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 422, 0);
  JUMPOUT(0x787BF8);
}
