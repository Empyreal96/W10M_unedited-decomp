// sub_50AC8C 
 
void __fastcall sub_50AC8C(unsigned int a1, unsigned int a2)
{
  unsigned int *v2; // r6
  int v3; // r7
  int v4; // r8
  int v5; // r10
  int v6; // r2
  void **v7; // r8
  int v8; // t1
  unsigned int *v9; // lr
  unsigned int v10; // r7
  unsigned int v11; // r0
  unsigned int v12; // r1

  if ( v5 == v4 )
  {
    v6 = KeNumberProcessors_0;
    if ( KeNumberProcessors_0 )
    {
      v7 = &KiProcessorBlock;
      do
      {
        v8 = (int)*v7++;
        v9 = (unsigned int *)(v8 + v3);
        if ( *(_DWORD *)(v8 + v3) != -1 )
        {
          do
            v10 = __ldrex(v9);
          while ( __strex(0xFFFFFFFF, v9) );
          if ( v10 != -1 )
            a1 += v10;
          v3 = 3584;
        }
        --v6;
      }
      while ( v6 );
    }
    if ( a1 >= a2 )
    {
      v11 = a1 - a2;
      if ( v11 )
      {
        do
          v12 = __ldrex(v2);
        while ( __strex(v12 + v11, v2) );
      }
      JUMPOUT(0x456D88);
    }
  }
  JUMPOUT(0x456D10);
}
