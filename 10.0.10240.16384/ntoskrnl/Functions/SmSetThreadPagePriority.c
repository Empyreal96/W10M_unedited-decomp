// SmSetThreadPagePriority 
 
int __fastcall SmSetThreadPagePriority(unsigned int *a1, int a2)
{
  unsigned int v3; // r0
  int v5; // r4
  unsigned int *v7; // r4
  unsigned int v8; // r6
  unsigned int v9; // r7
  unsigned int v10; // r1

  v3 = *a1;
  if ( !v3 )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *a1 = v3;
  }
  v5 = (*(_DWORD *)(v3 + 960) >> 12) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(v3 + 336) + 192) & 0x100000) != 0 )
    return sub_5257D0();
  if ( v5 != a2 )
  {
    v7 = (unsigned int *)(v3 + 960);
    v8 = *(_DWORD *)(v3 + 960);
    __dmb(0xBu);
    do
    {
      v9 = v8;
      __dmb(0xBu);
      do
        v10 = __ldrex(v7);
      while ( v10 == v8 && __strex(v8 & 0xFFFF8FFF | (a2 << 12), v7) );
      v8 = v10;
      __dmb(0xBu);
    }
    while ( v10 != v9 );
    v5 = (v9 >> 12) & 7;
    if ( (dword_682604 & 0x2000) != 0 )
      EtwTracePriority(v3, 1331, (v9 >> 12) & 7, a2, 0);
  }
  return v5;
}
