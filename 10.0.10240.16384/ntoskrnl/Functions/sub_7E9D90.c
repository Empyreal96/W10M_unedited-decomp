// sub_7E9D90 
 
void __fastcall sub_7E9D90(unsigned int a1)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r6
  unsigned int *v4; // r7
  unsigned int v5; // r1

  while ( 1 )
  {
    a1 = (unsigned __int16)(a1 + 1);
    ++v1;
    if ( a1 >= v3 )
      a1 = 0;
    if ( *(_DWORD *)(*(_DWORD *)(v2 + 4 * a1) + 260) )
    {
      if ( v1 )
      {
        __dmb(0xBu);
        do
          v5 = __ldrex(v4);
        while ( __strex(v5 + v1, v4) );
        __dmb(0xBu);
      }
      JUMPOUT(0x703F92);
    }
  }
}
