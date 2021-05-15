// SepSetServerSiloToken 
 
int __fastcall SepSetServerSiloToken(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r2
  int v7; // r3
  int v8; // r5
  _DWORD *v9; // r2
  unsigned int *v10; // r6
  unsigned int i; // r1
  unsigned int v12; // r7
  int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v18[2]; // [sp+0h] [bp-20h] BYREF
  int v19; // [sp+8h] [bp-18h] BYREF
  int v20; // [sp+Ch] [bp-14h]

  v18[0] = (int)a1;
  v18[1] = a2;
  v19 = a3;
  v20 = a4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  ExAcquireResourceExclusiveLite(a1[12], 1, v6, v7);
  __dmb(0xFu);
  if ( (a1[44] & 0x20) != 0 )
  {
    v8 = -1073741816;
  }
  else
  {
    v8 = SepReferenceLogonSessionSilo(a1 + 6, a2, v18);
    if ( v8 < 0 )
      goto LABEL_17;
    v9 = (_DWORD *)a1[48];
    v10 = v9 + 5;
    __pld(v9 + 5);
    for ( i = v9[5]; (int)(i - 1) > 0; i = v12 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex(v10);
      while ( v12 == i && __strex(i - 1, v10) );
      if ( v12 == i )
        goto LABEL_13;
    }
    if ( i != 1 )
      __fastfail(0xEu);
    v13 = v9[22];
    v19 = v9[1];
    v20 = v9[2];
    SepDeReferenceLogonSession(&v19, v13);
LABEL_13:
    a1[48] = v18[0];
  }
  if ( v8 >= 0 )
    ExAllocateLocallyUniqueId(a1 + 13);
LABEL_17:
  __dmb(0xFu);
  v14 = ExReleaseResourceLite(a1[12]);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v8;
}
