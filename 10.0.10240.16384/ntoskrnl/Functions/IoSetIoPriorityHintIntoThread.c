// IoSetIoPriorityHintIntoThread 
 
int __fastcall IoSetIoPriorityHintIntoThread(int a1, unsigned int a2)
{
  unsigned int *v4; // r0
  unsigned int v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r1

  if ( a2 >= 5 )
    return -1073741811;
  v4 = (unsigned int *)(a1 + 960);
  v5 = *v4;
  __dmb(0xBu);
  do
  {
    v6 = v5;
    __dmb(0xBu);
    do
      v7 = __ldrex(v4);
    while ( v7 == v5 && __strex(v5 & 0xFFFFF1FF | (a2 << 9), v4) );
    v5 = v7;
    __dmb(0xBu);
  }
  while ( v7 != v6 );
  if ( (dword_682604 & 0x2000) != 0 )
    return sub_523578();
  if ( a2 != ((v6 >> 9) & 7) )
    KeAbProcessBaseIoPriorityChange(a1, (v6 >> 9) & 7, a2);
  return 0;
}
