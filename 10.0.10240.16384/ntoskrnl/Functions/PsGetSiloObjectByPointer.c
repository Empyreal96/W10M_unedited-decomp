// PsGetSiloObjectByPointer 
 
int __fastcall PsGetSiloObjectByPointer(int a1, int a2, _DWORD *a3)
{
  unsigned int v6; // r4
  int v7; // r5
  _DWORD *i; // r4
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 310);
  ExAcquireResourceSharedLite(a1 + 28, 1);
  v7 = -1073741275;
  *a3 = 0;
  for ( i = *(_DWORD **)(a1 + 120); i != (_DWORD *)(a1 + 120); i = (_DWORD *)*i )
  {
    if ( a2 == i[2] )
    {
      ObfReferenceObject(i[3]);
      v7 = 0;
      *a3 = i[3];
      break;
    }
  }
  v9 = ExReleaseResourceLite(a1 + 28);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x136) + 1;
  *(_WORD *)(v10 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 )
    KiCheckForKernelApcDelivery(v9);
  return v7;
}
