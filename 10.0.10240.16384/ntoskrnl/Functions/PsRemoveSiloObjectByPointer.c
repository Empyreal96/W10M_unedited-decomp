// PsRemoveSiloObjectByPointer 
 
int __fastcall PsRemoveSiloObjectByPointer(int a1, int a2)
{
  int v2; // r4
  unsigned int v5; // r5
  int v6; // r2
  int v7; // r3
  _DWORD *i; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  __int64 v13; // r0

  v2 = -1073741275;
  v5 = 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x136) - 1;
  *(_WORD *)(v6 + 310) = v7;
  ExAcquireResourceExclusiveLite(a1 + 28, 1, v6, v7);
  for ( i = *(_DWORD **)(a1 + 120); i != (_DWORD *)(a1 + 120); i = (_DWORD *)*i )
  {
    v5 = (unsigned int)i;
    if ( a2 == i[2] )
    {
      v13 = *(_QWORD *)i;
      if ( *(_DWORD **)(*i + 4) != i || *(_DWORD **)HIDWORD(v13) != i )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v13) = v13;
      *(_DWORD *)(v13 + 4) = HIDWORD(v13);
      v2 = 0;
      break;
    }
  }
  v9 = ExReleaseResourceLite(a1 + 28);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x136) + 1;
  *(_WORD *)(v10 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 )
    KiCheckForKernelApcDelivery(v9);
  if ( v2 >= 0 )
  {
    ObfDereferenceObject(*(_DWORD *)(v5 + 12));
    ExFreePoolWithTag(v5);
  }
  return v2;
}
