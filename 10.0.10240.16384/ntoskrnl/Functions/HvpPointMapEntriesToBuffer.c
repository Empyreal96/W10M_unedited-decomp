// HvpPointMapEntriesToBuffer 
 
int __fastcall HvpPointMapEntriesToBuffer(int result, unsigned int a2, unsigned int a3, unsigned int a4, int a5, unsigned int a6)
{
  unsigned int v7; // r4
  int i; // r10
  unsigned int *v11; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1
  unsigned int v15; // r3

  v7 = 0;
  for ( i = result; v7 < a4; v7 += 4096 )
  {
    v11 = (unsigned int *)HvpGetCellMap(i, v7 + a5);
    if ( !v11 )
      sub_80433C();
    v11[1] = a2;
    v11[2] = a3;
    if ( v7 )
    {
      v11[4] = 0;
    }
    else
    {
      v11[1] = a2 | 1;
      v11[4] = a4;
    }
    if ( a6 )
    {
      v15 = v11[1];
      *v11 = a6;
      v11[1] = v15 | 2;
    }
    else
    {
      *v11 = v7;
    }
    __dmb(0xBu);
    v12 = v11 + 3;
    if ( a3 )
    {
      result = 0;
      do
        v14 = __ldrex(v12);
      while ( __strex(0, v12) );
    }
    else
    {
      result = 1;
      do
        v13 = __ldrex(v12);
      while ( __strex(1u, v12) );
    }
    __dmb(0xBu);
  }
  return result;
}
