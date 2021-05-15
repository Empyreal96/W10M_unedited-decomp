// KiSetSafeToPowerDownFrozenProcessors 
 
int __fastcall KiSetSafeToPowerDownFrozenProcessors(int result, int a2, int a3)
{
  unsigned int v3; // r6
  int v4; // r5
  void **v5; // r7
  int v6; // t1

  v3 = 0;
  v4 = result;
  if ( KeNumberProcessors_0 )
  {
    v5 = &KiProcessorBlock;
    do
    {
      v6 = (int)*v5++;
      result = v6;
      if ( v6 != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 )
        result = KiSetSafeToPowerDownFrozenProcessor(result, v4, a3);
      ++v3;
    }
    while ( v3 < KeNumberProcessors_0 );
  }
  if ( v4 )
  {
    __dsb(0xFu);
    __sev();
  }
  return result;
}
