// MiTerminateWsle 
 
int __fastcall MiTerminateWsle(unsigned int a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v4; // r7
  unsigned int v6; // r0
  unsigned int v7; // r4
  int result; // r0

  v4 = (_DWORD *)a2[23];
  v6 = MiLocateWsle(a1, (int)a2, a3);
  v7 = v6;
  if ( (*(_DWORD *)(v4[9] * v6 + v4[63]) & 8) != 0
    && (*(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 20) & 0x8000000) == 0 )
  {
    --a2[16];
    if ( a1 + 0x40000000 > 0x3FFFFF )
      --a2[14];
  }
  MiRemoveWsle(v6, a2);
  result = MiReleaseWsle(v7, a2, a1, 1);
  if ( v7 < v4[1] )
    result = sub_538ACC(result);
  return result;
}
