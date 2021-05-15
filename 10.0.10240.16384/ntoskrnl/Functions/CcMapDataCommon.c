// CcMapDataCommon 
 
int __fastcall CcMapDataCommon(int a1, int a2, int a3, char a4)
{
  unsigned int *v5; // r5
  unsigned int v6; // r6

  if ( (a4 & 1) != 0 )
  {
    v5 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4240);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 + 1, v5) );
    JUMPOUT(0x7E6DF8);
  }
  return sub_7E6DD8();
}
