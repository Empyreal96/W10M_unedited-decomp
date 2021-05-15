// KeTimeOutQueueWaiters 
 
int __fastcall KeTimeOutQueueWaiters(int a1, unsigned __int64 a2, unsigned int a3)
{
  int v5; // r10
  unsigned int v6; // r6
  unsigned int v7; // r2
  int *v9; // r4
  int *v10; // r1
  int v11; // r3
  unsigned int v12; // r1
  __int64 v13; // kr00_8
  unsigned int v14; // [sp+8h] [bp-30h]
  int v15; // [sp+10h] [bp-28h]

  v5 = KeTickCount;
  v6 = 0;
  if ( !KeMaximumIncrement )
    __brkdiv0();
  v14 = _rt_udiv64((unsigned int)KeMaximumIncrement, a2);
  v15 = KfRaiseIrql(2);
  do
    v7 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    return sub_522B60();
  v9 = *(int **)(a1 + 8);
  while ( v9 != (int *)(a1 + 8) )
  {
    if ( v6 >= a3 )
      break;
    v10 = v9;
    v11 = *((unsigned __int8 *)v9 + 8);
    v9 = (int *)*v9;
    if ( v11 == 1 )
    {
      if ( v5 - *(_DWORD *)(v10[3] + 304) < v14 )
        break;
      v13 = *(_QWORD *)v10;
      if ( *(int **)(*v10 + 4) != v10 || *(int **)HIDWORD(v13) != v10 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v13) = v13;
      *(_DWORD *)(v13 + 4) = HIDWORD(v13);
      if ( KiTryUnwaitThread(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, v10, 258, 0) )
        ++v6;
    }
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)a1);
  while ( __strex(v12 & 0xFFFFFF7F, (unsigned int *)a1) );
  KiExitDispatcher(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0, 1, 0, v15);
  return v6;
}
