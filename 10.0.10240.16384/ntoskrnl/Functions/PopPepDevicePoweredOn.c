// PopPepDevicePoweredOn 
 
int __fastcall PopPepDevicePoweredOn(int a1, int a2)
{
  int v3; // r6
  unsigned int *v5; // r1
  unsigned int v6; // r4
  unsigned int v7; // r4

  if ( a2 )
  {
    v3 = 0;
    if ( *(int *)(a1 + 84) > 0 )
    {
      __dmb(0xBu);
      v5 = (unsigned int *)(a1 + 84);
      do
      {
        v6 = __ldrex(v5);
        v7 = v6 - 1;
      }
      while ( __strex(v7, v5) );
      __dmb(0xBu);
      if ( !v7 )
        PopPepUpdateConstraints(a1, 4, 1);
    }
  }
  else
  {
    v3 = 4;
  }
  return PopPepProcessEvent(a1, 0, v3, 6);
}
