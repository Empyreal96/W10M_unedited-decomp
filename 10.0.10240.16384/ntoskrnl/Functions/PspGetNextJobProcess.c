// PspGetNextJobProcess 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall PspGetNextJobProcess(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v8; // r9
  int v9; // r0
  _DWORD *v10; // r2 OVERLAPPED
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r4
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  int v15; // r0
  __int16 v16; // r3

  v8 = 0;
  if ( a2 )
    --*(_WORD *)(a2 + 310);
  v9 = ExAcquireResourceExclusiveLite(a1 + 32, 1, (int)a3, a4);
  if ( !a4 )
  {
    v10 = (_DWORD *)(a1 + 580);
    v11 = *(_DWORD *)(a1 + 580);
    *(_QWORD *)a3 = *(_QWORD *)&v11;
    if ( *(_DWORD *)(v11 + 4) != a1 + 580 )
      sub_7C0BD4(v9);
    *(_DWORD *)(v11 + 4) = a3;
    *v10 = a3;
    a3[2] = a1 + 24;
  }
  v12 = *(_DWORD **)a3[2];
  while ( v12 != (_DWORD *)(a1 + 24) )
  {
    v8 = v12 - 96;
    if ( ObReferenceObjectSafeWithTag((int)(v12 - 96)) )
      goto LABEL_11;
    v12 = (_DWORD *)*v12;
    v8 = 0;
  }
  *(_QWORD *)&v13 = *(_QWORD *)a3;
  if ( *(_DWORD **)(*a3 + 4) != a3 || (_DWORD *)*v14 != a3 )
    __fastfail(3u);
  *v14 = v13;
  *(_DWORD *)(v13 + 4) = v14;
LABEL_11:
  a3[2] = v12;
  v15 = ExReleaseResourceLite(a1 + 32);
  if ( a2 )
  {
    v16 = *(_WORD *)(a2 + 310) + 1;
    *(_WORD *)(a2 + 310) = v16;
    if ( !v16 && *(_DWORD *)(a2 + 100) != a2 + 100 )
      KiCheckForKernelApcDelivery(v15);
  }
  if ( a4 )
    ObfDereferenceObjectWithTag(a4);
  return v8;
}
