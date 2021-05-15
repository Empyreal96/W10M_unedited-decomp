// SmcProcessListRequest 
 
int __fastcall SmcProcessListRequest(int a1, unsigned int a2, int a3, _DWORD *a4, char a5)
{
  _BYTE *v9; // r0
  int v10; // r4
  _DWORD anonymous0[30]; // [sp+8h] [bp-60h] BYREF

  anonymous0[27] = a2;
  anonymous0[28] = a3;
  anonymous0[29] = a4;
  anonymous0[26] = a1;
  v9 = memset(anonymous0, 0, 68);
  if ( a3 != 68 )
    return -1073741306;
  if ( a5 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v9);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 64) = *(_BYTE *)(a2 + 64);
  }
  memmove((int)anonymous0, a2, 0x44u);
  if ( LOBYTE(anonymous0[0]) != 1 || (anonymous0[0] & 0xFF00) != 0 || (anonymous0[0] & 0xFFFF0000) != 0 )
    return -1073741811;
  v10 = SmcGetCacheList(a1, anonymous0);
  if ( v10 >= 0 )
  {
    memmove(a2, (int)anonymous0, 0x44u);
    *a4 = 68;
  }
  return v10;
}
