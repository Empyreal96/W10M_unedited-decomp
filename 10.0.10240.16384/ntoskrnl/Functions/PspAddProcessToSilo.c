// PspAddProcessToSilo 
 
int __fastcall PspAddProcessToSilo(_DWORD *a1, _DWORD *a2)
{
  int v4; // r2
  int v5; // r3
  _DWORD *v6; // r0
  _DWORD *v7; // r2
  int v8; // r3
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x136) - 1;
  *(_WORD *)(v4 + 310) = v5;
  ExAcquireResourceExclusiveLite((int)(a1 + 7), 1, v4, v5);
  a2[201] = a1;
  v6 = (_DWORD *)a1[27];
  v7 = a2 + 202;
  a2[202] = a1 + 26;
  a2[203] = v6;
  if ( (_DWORD *)*v6 != a1 + 26 )
    __fastfail(3u);
  *v6 = v7;
  a1[27] = v7;
  v8 = a1[25];
  a1[25] = v8 + 1;
  if ( !v8 )
  {
    KeResetEvent((int)a1);
    if ( a1[36] )
    {
      if ( !a1[24] )
        KeResetEvent((int)(a1 + 32));
    }
  }
  v9 = ExReleaseResourceLite((int)(a1 + 7));
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x136) + 1;
  *(_WORD *)(v10 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 )
    KiCheckForKernelApcDelivery(v9);
  PspReferenceSiloObject((int)a1);
  return 0;
}
