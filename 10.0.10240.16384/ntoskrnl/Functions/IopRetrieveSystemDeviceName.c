// IopRetrieveSystemDeviceName 
 
int __fastcall IopRetrieveSystemDeviceName(int (__fastcall *a1)(unsigned int, unsigned int, _DWORD *), unsigned int a2, unsigned int a3, int *a4)
{
  unsigned int v6; // r8
  unsigned int v7; // r10
  int result; // r0
  int v9; // r2
  int v10; // r3
  _DWORD _0[16]; // [sp+0h] [bp-28h] BYREF

  _0[2] = a4;
  _0[15] = a4;
  _0[14] = a3;
  _0[13] = a2;
  _0[1] = a1;
  _0[12] = a1;
  if ( a2 && a3 > 8 )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    {
      if ( (a2 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a2 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a2 = *(_BYTE *)a2;
      *(_BYTE *)(a2 + 4) = *(_BYTE *)(a2 + 4);
    }
    v6 = a3 - 8;
    v7 = a2 + 8;
  }
  else
  {
    v6 = 0;
    v7 = 0;
  }
  if ( v6 > 0xFFFF )
    v6 = 0xFFFF;
  result = a1(v7, v6, _0);
  if ( result >= 0 )
  {
    v9 = _0[0];
    *(_WORD *)a2 = LOWORD(_0[0]) - 2;
    *(_WORD *)(a2 + 2) = v6;
    *(_DWORD *)(a2 + 4) = v7;
    v10 = v9 + 8;
LABEL_17:
    *a4 = v10;
    return result;
  }
  if ( result == -1073741789 )
  {
    v10 = _0[0] + 8;
    goto LABEL_17;
  }
  *a4 = 0;
  return result;
}
