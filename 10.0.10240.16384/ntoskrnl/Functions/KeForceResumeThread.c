// KeForceResumeThread 
 
int __fastcall KeForceResumeThread(int a1)
{
  int v2; // r8
  unsigned int v3; // r7
  unsigned __int8 *v4; // r5
  unsigned int v5; // r2
  int v7; // r6
  unsigned int v8; // r1
  unsigned __int8 *v9; // r3
  unsigned int v10; // r2

  v2 = KfRaiseIrql(2);
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v4 = (unsigned __int8 *)(a1 + 452);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_52B18C();
  v7 = ((*(_DWORD *)(a1 + 80) >> 13) & 1) + *(char *)(a1 + 396);
  if ( v7 )
  {
    __dmb(0xBu);
    v9 = (unsigned __int8 *)(a1 + 81);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0xDF, v9) );
    __dmb(0xBu);
    *(_BYTE *)(a1 + 396) = 0;
  }
  KiResumeThread(a1, v3 + 1408, 1);
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v4);
  while ( __strex(v8 & 0xFFFFFF7F, (unsigned int *)v4) );
  KiExitDispatcher(v3 + 1408, 0, 1, 0, v2);
  return v7;
}
