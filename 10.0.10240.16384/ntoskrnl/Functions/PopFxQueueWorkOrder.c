// PopFxQueueWorkOrder 
 
int __fastcall PopFxQueueWorkOrder(int result, _DWORD *a2, int a3, int a4)
{
  int v6; // r7
  unsigned int *v7; // r5
  unsigned int v8; // r6
  unsigned int v9; // r6
  unsigned __int8 v10; // r9
  unsigned int v11; // r6
  int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r1
  _DWORD *v15; // r1

  v6 = result;
  __dmb(0xBu);
  v7 = a2 + 4;
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 + 1;
  }
  while ( __strex(v9, v7) );
  __dmb(0xBu);
  if ( v9 == 1 )
  {
    if ( a3 )
      PopFxAddRefDevice(a3);
    if ( a4 || (result = ExTryQueueWorkItem(a2, 48)) == 0 )
    {
      v10 = KfRaiseIrql(2);
      v11 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v12 = *(_DWORD *)(v11 + 1412);
      if ( (dword_682604 & 0x1000000) != 0 )
      {
        result = sub_53EB28();
      }
      else
      {
        do
          v13 = __ldrex((unsigned __int8 *)v6);
        while ( __strex(v13 | 0x80, (unsigned __int8 *)v6) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v13 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v6 & 0x80) != 0 );
          do
            v13 = __ldrex((unsigned __int8 *)v6);
          while ( __strex(v13 | 0x80, (unsigned __int8 *)v6) );
        }
        if ( *(_DWORD *)(v6 + 12) == v6 + 8
          || *(_DWORD *)(v6 + 24) >= *(_DWORD *)(v6 + 28)
          || *(_DWORD *)(v12 + 152) == v6 && *(_BYTE *)(v12 + 395) == 15
          || !KiWakeQueueWaiter(v11 + 1408, v6, (int)a2) )
        {
          ++*(_DWORD *)(v6 + 4);
          v15 = *(_DWORD **)(v6 + 20);
          *a2 = v6 + 16;
          a2[1] = v15;
          if ( *v15 != v6 + 16 )
            __fastfail(3u);
          *v15 = a2;
          *(_DWORD *)(v6 + 20) = a2;
        }
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)v6);
        while ( __strex(v14 & 0xFFFFFF7F, (unsigned int *)v6) );
        result = KiExitDispatcher(v11 + 1408, 0, 1, 0, v10);
      }
    }
  }
  return result;
}
