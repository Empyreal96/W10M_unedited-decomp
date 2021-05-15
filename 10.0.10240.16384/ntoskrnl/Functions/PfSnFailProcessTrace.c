// PfSnFailProcessTrace 
 
int __fastcall PfSnFailProcessTrace(int a1)
{
  unsigned __int16 *v1; // r2
  unsigned int v2; // r4

  if ( (*(_WORD *)(a1 + 344) & 2) == 0 )
  {
    __dmb(0xBu);
    v1 = (unsigned __int16 *)(a1 + 344);
    do
      v2 = __ldrex(v1);
    while ( __strex(v2 | 2, v1) );
    __dmb(0xBu);
  }
  return PfSnEndProcessTrace(*(_DWORD *)(a1 + 264), 0xAu, a1 + 12);
}
