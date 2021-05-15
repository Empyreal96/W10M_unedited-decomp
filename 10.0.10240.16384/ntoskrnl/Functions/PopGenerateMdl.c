// PopGenerateMdl 
 
_DWORD *__fastcall PopGenerateMdl(unsigned int a1)
{
  int v2; // r0
  unsigned int v3; // r1
  unsigned int v4; // r7
  int v5; // r8
  _DWORD *v6; // r0
  _DWORD *v7; // r5
  __int64 v8; // r0

  v2 = ReadTimeStampCounter();
  v4 = v3;
  v5 = v2;
  v6 = (_DWORD *)MmAllocatePagesForMdlEx(0, 0, -1, -1, 0, 0, a1 << 12, 1, 13);
  v7 = v6;
  if ( v6 )
  {
    *v6 = *(_DWORD *)(dword_61EC98 + 80);
    *(_DWORD *)(dword_61EC98 + 80) = v6;
    *(_QWORD *)(dword_61EC98 + 88) += a1;
  }
  LODWORD(v8) = ReadTimeStampCounter();
  qword_61EFB0 += v8 - __PAIR64__(v4, v5);
  return v7;
}
