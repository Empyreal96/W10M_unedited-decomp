// SepBuildDefaultCape 
 
int __fastcall SepBuildDefaultCape(_DWORD *a1)
{
  int v2; // r4
  _BYTE *v3; // r0
  _BYTE *v4; // r5

  v2 = 0;
  v3 = (_BYTE *)ExAllocatePoolWithTag(1, 28);
  v4 = v3;
  if ( !v3 )
    return -1073741670;
  memset(v3, 0, 28);
  *a1 = v4;
  *(_DWORD *)v4 = DefaultCapeName;
  *((_DWORD *)v4 + 1) = off_9201F8;
  *((_DWORD *)v4 + 2) = 0;
  *(_QWORD *)(v4 + 20) = 0x100000000i64;
  *((_DWORD *)v4 + 3) = 0;
  *((_DWORD *)v4 + 4) = SeDefaultCapeSd;
  return v2;
}
