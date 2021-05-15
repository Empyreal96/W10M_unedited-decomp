// ObpCallPostOperationCallbacks 
 
int __fastcall ObpCallPostOperationCallbacks(int a1, _DWORD *a2)
{
  __int64 *v4; // r6
  __int64 v5; // kr00_8
  __int64 v6; // kr08_8
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  while ( (_DWORD *)*a2 != a2 )
  {
    v4 = (__int64 *)a2[1];
    v5 = *v4;
    if ( *(_DWORD **)v4 != a2 || *(__int64 **)HIDWORD(v5) != v4 )
      __fastfail(3u);
    a2[1] = HIDWORD(v5);
    *(_DWORD *)HIDWORD(v5) = a2;
    v6 = v4[1];
    *(_DWORD *)(a1 + 16) = HIDWORD(v6);
    (*(void (__fastcall **)(_DWORD, int))(v6 + 28))(*(_DWORD *)(*(_DWORD *)(v6 + 16) + 4), a1);
    v7 = (unsigned int *)(v6 + 32);
    __pld((void *)(v6 + 32));
    v8 = *(_DWORD *)(v6 + 32) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 - 2, v7) );
    if ( v9 != v8 )
      ExfReleaseRundownProtection((unsigned __int8 *)v7);
    ExFreePoolWithTag((unsigned int)v4);
  }
  v10 = ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 8));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return 0;
}
