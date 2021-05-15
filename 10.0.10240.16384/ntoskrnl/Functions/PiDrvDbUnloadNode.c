// PiDrvDbUnloadNode 
 
int __fastcall PiDrvDbUnloadNode(int a1, _DWORD *a2)
{
  int v4; // r2
  int v5; // r3
  __int64 v6; // r0
  __int64 v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  ExAcquireResourceExclusiveLite(a1 + 44, 1, v4, v5);
  if ( *(_DWORD *)(a1 + 36) )
  {
    LODWORD(v7) = *(_DWORD *)(a1 + 276);
    HIDWORD(v7) = *(_DWORD *)(a1 + 272);
    if ( v7 )
    {
      if ( (int)v7 < 0 )
      {
        LODWORD(v6) = a1 + 144;
        KeSetCoalescableTimer(v6, *(_QWORD *)(a1 + 272), 0, 0x3A98u, a1 + 192);
      }
    }
    else
    {
      KiSetTimerEx(a1 + 144, HIDWORD(v6), *(_QWORD *)(a1 + 272), 0, 0, a1 + 192);
    }
    *(_BYTE *)(a1 + 280) = 1;
  }
  *a2 = 0;
  v8 = ExReleaseResourceLite(a1 + 44);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return 0;
}
