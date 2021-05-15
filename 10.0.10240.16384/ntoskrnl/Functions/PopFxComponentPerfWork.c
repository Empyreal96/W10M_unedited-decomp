// PopFxComponentPerfWork 
 
int __fastcall PopFxComponentPerfWork(int a1)
{
  int v2; // r5
  unsigned int *v3; // r6
  unsigned int *v4; // r9
  int v5; // r7
  int v6; // r8
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r2
  int result; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1

  v2 = *(_DWORD *)a1;
  v3 = (unsigned int *)(a1 + 24);
  v4 = (unsigned int *)(a1 + 72);
  v5 = *(_DWORD *)(*(_DWORD *)a1 + 16);
  v6 = *(_DWORD *)(*(_DWORD *)a1 + 48);
  do
  {
    do
      v7 = __ldrex(v3);
    while ( __strex(v7, v3) );
    __dmb(0xBu);
    PopFxCompleteComponentPerfState(v6, v5, a1, (v7 & 0x40000000) != 0);
    __dmb(0xBu);
    do
    {
      v8 = __ldrex(v4);
      v9 = v8 - 1;
    }
    while ( __strex(v9, v4) );
    __dmb(0xBu);
  }
  while ( v9 );
  result = *(_DWORD *)(v2 + 48);
  __dmb(0xBu);
  v11 = (unsigned int *)(result + 112);
  do
  {
    v12 = __ldrex(v11);
    v13 = v12 - 1;
  }
  while ( __strex(v13, v11) );
  __dmb(0xBu);
  if ( !v13 )
    result = KeSetEvent(result + 116, 0, 0);
  return result;
}
