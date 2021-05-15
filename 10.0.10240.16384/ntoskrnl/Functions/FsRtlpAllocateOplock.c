// FsRtlpAllocateOplock 
 
int FsRtlpAllocateOplock()
{
  _DWORD *v0; // r0
  int v2; // [sp+0h] [bp-10h]

  v2 = ExAllocatePoolWithTag(273, 80, 1869763398);
  memset((_BYTE *)v2, 0, 80);
  v0 = (_DWORD *)ExAllocatePoolWithTag(528, 32, 1869763398);
  *(_DWORD *)(v2 + 76) = v0;
  *v0 = 1;
  v0[1] = 0;
  v0[2] = 0;
  KeInitializeEvent((int)(v0 + 3), 1, 0);
  *(_DWORD *)(v2 + 24) = v2 + 20;
  *(_DWORD *)(v2 + 20) = v2 + 20;
  *(_DWORD *)(v2 + 32) = v2 + 28;
  *(_DWORD *)(v2 + 28) = v2 + 28;
  *(_DWORD *)(v2 + 40) = v2 + 36;
  *(_DWORD *)(v2 + 36) = v2 + 36;
  *(_DWORD *)(v2 + 48) = v2 + 44;
  *(_DWORD *)(v2 + 44) = v2 + 44;
  *(_DWORD *)(v2 + 56) = v2 + 52;
  *(_DWORD *)(v2 + 52) = v2 + 52;
  *(_DWORD *)(v2 + 64) = v2 + 60;
  *(_DWORD *)(v2 + 60) = v2 + 60;
  *(_DWORD *)(v2 + 72) = 1;
  return v2;
}
