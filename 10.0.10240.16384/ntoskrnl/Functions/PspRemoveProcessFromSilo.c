// PspRemoveProcessFromSilo 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspRemoveProcessFromSilo(_DWORD *a1, int a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED
  int v8; // r3
  int v9; // r0
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x136) - 1;
  *(_WORD *)(v4 + 310) = v5;
  ExAcquireResourceExclusiveLite((int)(a1 + 7), 1, v4, v5);
  *(_DWORD *)(a2 + 804) = 0;
  *(_QWORD *)&v6 = *(_QWORD *)(a2 + 808);
  if ( *(_DWORD *)(v6 + 4) != a2 + 808 || *v7 != a2 + 808 )
    __fastfail(3u);
  *v7 = v6;
  *(_DWORD *)(v6 + 4) = v7;
  v8 = a1[25] - 1;
  a1[25] = v8;
  if ( !v8 && !a1[24] )
  {
    v9 = (int)(a1 + 32);
    if ( !a1[36] )
      v9 = (int)a1;
    KeSetEvent(v9, 0, 0);
  }
  v10 = ExReleaseResourceLite((int)(a1 + 7));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x136) + 1;
  *(_WORD *)(v11 + 310) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 )
    KiCheckForKernelApcDelivery(v10);
  return PspDereferenceSiloObject((int)a1);
}
