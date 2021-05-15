// NtAlpcCreateResourceReserve 
 
int __fastcall NtAlpcCreateResourceReserve(int a1, int a2, int a3, unsigned int a4)
{
  _DWORD *v4; // r6
  int v6; // lr
  unsigned int v7; // r5
  int v8; // r4
  int v9; // r0
  _DWORD *v10; // r2
  int v11; // r5
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // [sp+Ch] [bp-1Ch] BYREF
  _DWORD _10[12]; // [sp+10h] [bp-18h] BYREF

  _10[9] = a2;
  v15 = a3;
  _10[0] = a4;
  v4 = (_DWORD *)a4;
  _10[11] = a4;
  _10[10] = a3;
  v6 = a1;
  _10[8] = a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  if ( a2 )
  {
    v8 = -1073741811;
  }
  else
  {
    v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( v9 )
    {
      v10 = (_DWORD *)a4;
      if ( a4 >= MmUserProbeAddress )
        v10 = (_DWORD *)MmUserProbeAddress;
      *v10 = *v10;
    }
    a1 = ObReferenceObjectByHandle(v6, 1, AlpcPortObjectType, v9, &v15);
    v8 = a1;
    if ( a1 >= 0 )
    {
      v11 = v15;
      v8 = AlpcpCreateReserve(v15, a3, _10);
      if ( v8 >= 0 )
        *v4 = _10[0] | 0x80000000;
      a1 = ObfDereferenceObject(v11);
    }
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v8;
}
