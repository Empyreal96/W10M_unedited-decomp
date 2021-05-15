// PopMirrorPhysicalMemory 
 
int __fastcall PopMirrorPhysicalMemory(__int64 a1, __int64 a2)
{
  int v2; // r5
  unsigned int v3; // r2

  v2 = 0;
  if ( !dword_61EC98 )
    return -1073741670;
  v3 = (a2 + 4095) >> 12;
  if ( !v3 )
    v3 = 1;
  RtlClearBits((_BYTE *)(dword_61EC98 + 32), a1 >> 12, v3);
  return v2;
}
