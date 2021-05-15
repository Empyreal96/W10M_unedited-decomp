// CmpSetIoPriorityThread 
 
int __fastcall CmpSetIoPriorityThread(int a1, int a2)
{
  unsigned int *v3; // r1
  unsigned int v5; // r0
  unsigned int v6; // r7
  unsigned int v7; // r4

  v3 = (unsigned int *)(a1 + 960);
  v5 = *(_DWORD *)(a1 + 960);
  __dmb(0xBu);
  do
  {
    v6 = v5;
    __dmb(0xBu);
    do
      v7 = __ldrex(v3);
    while ( v7 == v5 && __strex(v5 & 0xFFFFF1FF | (a2 << 9), v3) );
    v5 = v7;
    __dmb(0xBu);
  }
  while ( v7 != v6 );
  if ( (dword_682604 & 0x2000) != 0 )
    return sub_525C50();
  if ( a2 != ((v6 >> 9) & 7) )
    KeAbProcessBaseIoPriorityChange(a1, (v6 >> 9) & 7, a2);
  return (v6 >> 9) & 7;
}
