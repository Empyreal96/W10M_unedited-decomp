// sub_7EA214 
 
void sub_7EA214()
{
  int v0; // r0
  unsigned int v1; // r1
  __int16 v2; // r3
  unsigned int v3; // r4
  _DWORD *v4; // r7
  int v5; // r3
  int v6; // r10
  int v7; // r5
  int v8; // r2
  _DWORD *v9; // r5
  int v10; // r0
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // [sp+0h] [bp+0h]

  memset((_BYTE *)v3, 0, 92);
  *(_DWORD *)(v3 + 4) = *v4;
  v5 = v4[1];
  *(_DWORD *)(v3 + 28) = 0;
  *(_DWORD *)(v3 + 32) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 8) = v5;
  *(_DWORD *)(v3 + 20) = 1;
  *(_DWORD *)(v3 + 60) = 0;
  *(_DWORD *)(v3 + 64) = 0;
  *(_DWORD *)(v3 + 68) = 0;
  *(_DWORD *)(v3 + 72) = v3 + 72;
  *(_DWORD *)(v3 + 76) = v3 + 72;
  *(_DWORD *)(v3 + 80) = 0;
  *(_DWORD *)(v3 + 84) = 0;
  v6 = *v4 & 0xF;
  v7 = SepLogonSessions;
  v15 = SepLogonSessions;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v6 & 3), 1, v8, v6 & 3);
  v9 = *(_DWORD **)(v7 + 4 * v6);
  v10 = PsGetCurrentServerSilo();
  v11 = v10;
  while ( v9 )
  {
    if ( v10 == v9[22] && *v4 == v9[1] && v4[1] == v9[2] )
    {
      v12 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v6 & 3));
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(v12);
      ExFreePoolWithTag(v3);
      if ( v11 )
        PspDereferenceSiloObject(v11);
LABEL_18:
      JUMPOUT(0x70477E);
    }
    v9 = (_DWORD *)*v9;
  }
  *(_DWORD *)(v3 + 88) = v10;
  *(_DWORD *)v3 = *(_DWORD *)(v15 + 4 * v6);
  *(_DWORD *)(v15 + 4 * v6) = v3;
  v0 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v6 & 3));
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_WORD *)(v1 + 0x134) + 1;
  *(_WORD *)(v1 + 308) = v2;
  if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(v0);
  goto LABEL_18;
}
