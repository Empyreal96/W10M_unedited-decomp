// SepQueueWorkItem 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SepQueueWorkItem(int a1, _DWORD *a2, _BYTE *a3, int a4)
{
  int v6; // r7
  int v8; // r9
  int v10; // r8
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int (__fastcall *v14)(_DWORD *); // r3
  unsigned __int8 v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  _DWORD *v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int (*v26)(); // r3
  _DWORD *v27; // r1
  _DWORD v28[10]; // [sp+0h] [bp-28h] BYREF

  v28[0] = a2;
  v28[1] = a3;
  v28[2] = a4;
  v6 = 0;
  v8 = 0;
  if ( PsGetServerSiloState(a2[11]) != 1 )
    return sub_54D0FC();
  if ( a3 )
    *a3 = 0;
  v10 = KeGetCurrentIrql(1);
  if ( v10 == 2 )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 72), (unsigned int)v28);
    v13 = *(_DWORD *)(a1 + 108);
  }
  else
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(__int16 *)(v11 + 0x134) - 1;
    *(_WORD *)(v11 + 308) = v12;
    ExAcquireResourceExclusiveLite(a1 + 16, 1, v11, v12);
    v13 = *(_DWORD *)(a1 + 104);
  }
  if ( v13 )
  {
    if ( a3 )
      *a3 = 1;
  }
  else
  {
    v14 = *(int (__fastcall **)(_DWORD *))(a1 + 112);
    if ( v14 )
      v15 = v14(a2);
    else
      v15 = 1;
    v6 = v15;
    if ( v15 )
    {
      __dmb(0xBu);
      v16 = (unsigned int *)(a1 + 96);
      do
      {
        v17 = __ldrex(v16);
        v18 = v17 + 1;
      }
      while ( __strex(v18, v16) );
      __dmb(0xBu);
      a2[10] = v18;
      if ( v10 == 2 )
      {
        v27 = *(_DWORD **)(a1 + 12);
        *a2 = a1 + 8;
        a2[1] = v27;
        if ( *v27 != a1 + 8 )
          __fastfail(3u);
        *v27 = a2;
        *(_DWORD *)(a1 + 12) = a2;
      }
      else
      {
        v19 = *(_DWORD **)(a1 + 4);
        *a2 = a1;
        a2[1] = v19;
        if ( *v19 != a1 )
          __fastfail(3u);
        *v19 = a2;
        *(_DWORD *)(a1 + 4) = a2;
      }
      __dmb(0xBu);
      v20 = (unsigned int *)(a1 + 92);
      do
      {
        v21 = __ldrex(v20);
        v22 = v21 + 1;
      }
      while ( __strex(v22, v20) );
      __dmb(0xBu);
      if ( v22 == 1 )
        v8 = 1;
    }
  }
  if ( v10 == 2 )
  {
    KeReleaseInStackQueuedSpinLock((int)v28);
  }
  else
  {
    v23 = ExpReleaseResourceForThreadLite(a1 + 16, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
  }
  if ( v8 )
  {
    v26 = SepRmCallLsa;
    *(_QWORD *)(a1 + 84) = *(_QWORD *)(&a1 - 1);
    *(_DWORD *)(a1 + 76) = 0;
    ExQueueWorkItem((_DWORD *)(a1 + 76), 1);
  }
  return v6;
}
