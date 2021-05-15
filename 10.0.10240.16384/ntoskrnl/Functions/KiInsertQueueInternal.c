// KiInsertQueueInternal 
 
int __fastcall KiInsertQueueInternal(int a1, _DWORD *a2)
{
  int v4; // r7
  int result; // r0
  unsigned int v6; // r8
  int v7; // r6
  unsigned int v8; // r2
  unsigned int v9; // r1
  _DWORD *v10; // r1

  *a2 = 0;
  v4 = a1 + 8;
  result = KfRaiseIrql(2);
  v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v7 = *(_DWORD *)(v6 + 1412);
  if ( (dword_682604 & 0x1000000) != 0 )
    return sub_523978(result);
  do
    v8 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v8 | 0x80, (unsigned __int8 *)a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v8 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v8 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v8 | 0x80, (unsigned __int8 *)a1) );
  }
  if ( *(_DWORD *)(v4 + 4) == v4
    || *(_DWORD *)(a1 + 24) >= *(_DWORD *)(a1 + 28)
    || *(_DWORD *)(v7 + 152) == a1 && *(_BYTE *)(v7 + 395) == 15
    || (result = KiWakeQueueWaiter(v6 + 1408, a1, a2)) == 0 )
  {
    ++*(_DWORD *)(a1 + 4);
    v10 = *(_DWORD **)(a1 + 20);
    *a2 = a1 + 16;
    a2[1] = v10;
    if ( *v10 != a1 + 16 )
      __fastfail(3u);
    *v10 = a2;
    *(_DWORD *)(a1 + 20) = a2;
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)a1);
  while ( __strex(v9 & 0xFFFFFF7F, (unsigned int *)a1) );
  return result;
}
