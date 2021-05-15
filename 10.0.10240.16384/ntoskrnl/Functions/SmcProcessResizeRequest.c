// SmcProcessResizeRequest 
 
int __fastcall SmcProcessResizeRequest(int a1, unsigned int a2, int a3, char a4)
{
  int v4; // r6
  _BYTE *v8; // r0
  int v9; // r4
  _DWORD v11[12]; // [sp+8h] [bp-30h] BYREF

  v4 = a4;
  v8 = memset(v11, 0, 20);
  if ( a3 != 20 )
    return -1073741306;
  if ( v4 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v8);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 16) = *(_BYTE *)(a2 + 16);
  }
  memmove((int)v11, a2, 0x14u);
  if ( LOBYTE(v11[0]) != 1 )
    return -1073741735;
  if ( (v11[0] & 0xFFFFFE00) != 0 || !v11[4] || v11[3] >= 2 )
    return -1073741811;
  v9 = SmcStoreResize(a1, v11);
  if ( v9 >= 0 )
  {
    memmove(a2, (int)v11, 0x14u);
    v9 = 0;
  }
  return v9;
}
