// sub_8086AC 
 
void __fastcall sub_8086AC(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r1
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r0

  PfCalculateProcessHash(v5, (unsigned __int16 **)((unsigned int)&a5 | v7));
  if ( (*(_DWORD *)(v6 + 672) & v7) != 0 )
  {
    v9 = *(_DWORD *)(v5 + 408);
    if ( v9 )
    {
      if ( PfCheckDeprioritizeImage(v9, v8) )
      {
        __dmb(0xBu);
        v10 = (unsigned int *)(v5 + 192);
        do
          v11 = __ldrex(v10);
        while ( __strex(v11 | 0x4000, v10) );
        __dmb(0xBu);
      }
    }
  }
  JUMPOUT(0x75B570);
}
