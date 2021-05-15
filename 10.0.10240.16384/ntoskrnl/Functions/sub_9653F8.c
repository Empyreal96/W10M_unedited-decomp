// sub_9653F8 
 
void __fastcall sub_9653F8(int a1)
{
  int v1; // r8
  unsigned int *v2; // r9
  _DWORD *v3; // r10
  unsigned int v4; // r2
  unsigned int v5; // r2
  int v6; // r1
  int v7; // r2

  __dmb(0xBu);
  do
  {
    v4 = __ldrex(v2);
    v5 = v4 + 1;
  }
  while ( __strex(v5, v2) );
  __dmb(0xBu);
  v6 = v5 & 0x3F;
  v7 = v1 + 8 * v6;
  *(_WORD *)(v7 + 2) = a1;
  *(_DWORD *)(v7 + 4) = -1073740768;
  *(_WORD *)v7 = 100;
  if ( (*v3 & a1) != 0 )
    RtlAssert((int)"Engine != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 100, 0);
  JUMPOUT(0x94823C);
}
