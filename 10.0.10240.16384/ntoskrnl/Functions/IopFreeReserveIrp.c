// IopFreeReserveIrp 
 
_DWORD *__fastcall IopFreeReserveIrp(int a1)
{
  unsigned int v1; // r1
  char *v2; // r0
  unsigned int v3; // r1
  unsigned int v4; // r1

  *(_BYTE *)(a1 + 39) &= 0xDEu;
  if ( a1 == IopReserveIrps )
  {
    __dmb(0xBu);
    do
      v1 = __ldrex((unsigned int *)&dword_6318E4);
    while ( __strex(0, (unsigned int *)&dword_6318E4) );
    __dmb(0xBu);
    v2 = &byte_6318E8;
    return (_DWORD *)KeSetEvent((int)v2, 1, 0);
  }
  if ( a1 == dword_6318F8 )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&dword_6318FC);
    while ( __strex(0, (unsigned int *)&dword_6318FC) );
    __dmb(0xBu);
    v2 = &byte_631900;
    return (_DWORD *)KeSetEvent((int)v2, 1, 0);
  }
  if ( a1 == dword_631910 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&dword_631914);
    while ( __strex(0, (unsigned int *)&dword_631914) );
    __dmb(0xBu);
    v2 = &byte_631918;
    return (_DWORD *)KeSetEvent((int)v2, 1, 0);
  }
  return IopFreeBackpocketIrp((_DWORD *)a1, 1);
}
