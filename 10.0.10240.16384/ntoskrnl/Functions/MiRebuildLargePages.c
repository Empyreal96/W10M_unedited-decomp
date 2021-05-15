// MiRebuildLargePages 
 
int __fastcall MiRebuildLargePages(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r7
  unsigned int v6; // r6
  int v7; // r8
  _BYTE *v8; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // r3
  char v14; // r3

  v4 = 0;
  v6 = (unsigned __int16)KeNumberNodes;
  if ( KeNumberNodes )
  {
    v7 = 0;
    v8 = (_BYTE *)(a1 + 3084);
    do
    {
      if ( !*v8 )
      {
        if ( (unsigned int)MiNodeFreeZeroPages(*(_DWORD *)(a1 + 24) + v7, 0, 0) < 0x4000 )
          return sub_7EE324();
        if ( MiRebuildLargePage(a1, v4, 0) == 1 )
        {
          v8[1] = 8;
        }
        else
        {
          v13 = (unsigned __int8)v8[1];
          if ( v13 >= 0x80 )
            v14 = -1;
          else
            v14 = 2 * v13;
          v8[1] = v14;
        }
        v6 = (unsigned __int16)KeNumberNodes;
        *v8 = v8[1];
      }
      ++v4;
      v8 += 2;
      v7 += 104;
    }
    while ( v4 < v6 );
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 3080);
  do
  {
    v11 = __ldrex(v10);
    v12 = v11 - 1;
  }
  while ( __strex(v12, v10) );
  return MiDereferencePartition(a1, v12, (int)v10, a4);
}
