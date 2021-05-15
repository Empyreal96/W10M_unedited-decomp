// KeSetEventBoostPriorityEx 
 
int __fastcall KeSetEventBoostPriorityEx(int a1, int a2, int *a3, int a4, char a5)
{
  int v7; // r10
  unsigned int v8; // r7
  unsigned int v9; // r5
  _QWORD *v10; // r5
  int v11; // r4
  BOOL v12; // r4
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r3
  int v16; // r2
  int v18; // r4
  int v19; // r2
  int v20; // r0
  _QWORD *v21; // r1
  __int64 v22; // kr00_8
  int v23; // r3
  unsigned int v24; // r2

  v7 = KfRaiseIrql(2);
  v8 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  do
    v9 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v9 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v9 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v24 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v24 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v24 >> 7 );
  }
  v10 = *(_QWORD **)(a1 + 8);
  v11 = 0;
  *(_DWORD *)(a1 + 4) = 1;
  if ( v10 != (_QWORD *)(a1 + 8) )
  {
    while ( 1 )
    {
      v21 = v10;
      v22 = *v10;
      v10 = *(_QWORD **)v10;
      if ( *(_QWORD **)(v22 + 4) != v21 || *(_QWORD **)HIDWORD(v22) != v21 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v22) = v22;
      *(_DWORD *)(v22 + 4) = HIDWORD(v22);
      if ( *((_BYTE *)v21 + 8) != 1 )
        return sub_50C080();
      if ( KiTryUnwaitThread(v8, v21, *((unsigned __int16 *)v21 + 5), a2) )
      {
        v23 = *(_DWORD *)(a1 + 4) - 1;
        *(_DWORD *)(a1 + 4) = v23;
        if ( !v23 )
          break;
      }
      if ( v10 == (_QWORD *)(a1 + 8) )
        goto LABEL_5;
    }
    v11 = 1;
  }
LABEL_5:
  v12 = v11 > 0 && a2;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)a1);
  while ( __strex(v13 & 0xFFFFFF7F, (unsigned int *)a1) );
  if ( (a5 & 1) != 0 )
  {
    v18 = *a3;
    if ( *a3 )
    {
      v19 = *(_DWORD *)(v8 + 1540);
      if ( v19 )
      {
        if ( KiAbEnabled )
        {
          v20 = KiAbFindWakeupLockEntry(a4, v19 - 144);
          if ( v20 )
            KiAbApplyWakeupBoost(v18, v20, 1);
        }
      }
    }
    goto LABEL_12;
  }
  v14 = KiRemoveBoostThread(v8, *(_DWORD *)(v8 + 4));
  if ( a3 )
  {
    v15 = *a3;
    if ( !*a3 )
      goto LABEL_12;
    if ( (char)v15 > v14 )
      v14 = (char)v15;
  }
  if ( v12 )
  {
    v16 = 2;
    return KiExitDispatcher(v8, 0, v16, v14, v7);
  }
LABEL_12:
  v16 = 1;
  v14 = 1;
  return KiExitDispatcher(v8, 0, v16, v14, v7);
}
