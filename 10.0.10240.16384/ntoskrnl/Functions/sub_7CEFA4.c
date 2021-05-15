// sub_7CEFA4 
 
void __fastcall sub_7CEFA4(int a1)
{
  int v1; // r6
  int *v2; // r9
  unsigned int *v3; // r10
  unsigned int v4; // r5
  unsigned int v5; // r5
  int v6; // r3
  int v7; // r3

  __dmb(0xBu);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 + 1;
  }
  while ( __strex(v5, v3) );
  __dmb(0xBu);
  v6 = v1 + 8 * (v5 & 0x3F);
  *(_WORD *)(v6 + 2) = a1;
  *(_DWORD *)(v6 + 4) = -1073740768;
  v7 = *v2;
  *(_WORD *)(v1 + 8 * (v5 & 0x3F)) = 849;
  if ( (v7 & a1) != 0 )
    RtlAssert((int)"KeyHandle != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 849, 0);
  JUMPOUT(0x7880FA);
}
