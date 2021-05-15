// HvExtendHivePrimaryFileValidDataLength 
 
int __fastcall HvExtendHivePrimaryFileValidDataLength(int a1, int a2, int a3)
{
  int v5; // r3
  int v6; // r7
  int v7; // r4
  _DWORD *v8; // r0
  int v9; // r0
  int v11; // [sp+8h] [bp-28h] BYREF
  int v12; // [sp+Ch] [bp-24h] BYREF
  int v13[8]; // [sp+10h] [bp-20h] BYREF

  if ( (*(_BYTE *)(a1 + 72) & 4) == 0 )
  {
    v12 = 0;
    v13[0] = a2 - 4;
    v13[1] = (int)&v11;
    v13[2] = 4;
    if ( !(*(int (__fastcall **)(int, _DWORD, int *, int, int *, int, int))(a1 + 20))(
            a1,
            0,
            v13,
            1,
            &v12,
            a3,
            -16843010) )
      return -1073741491;
    v9 = CmpFileFlushAndPurge(a1, 0);
LABEL_9:
    if ( v9 )
      return 0;
    return -1073741491;
  }
  v6 = HvViewMapIsRangePinned(a1 + 152, a2 - 4);
  if ( !v6 )
  {
    v7 = HvViewMapPinForFileOffset(a1 + 152, a2 - 4, 4);
    if ( v7 < 0 )
      return v7;
    v8 = (_DWORD *)HvViewMapAddressForFileOffset(a1 + 152, a2 - 4);
    v5 = -16843010;
    *v8 = -16843010;
  }
  v7 = HvViewMapFlush((_DWORD *)(a1 + 152), a2 - 4, 4, v5);
  if ( !v6 )
    HvViewMapUnpinForFileOffset(a1 + 152, a2 - 4, 4);
  if ( v7 >= 0 )
  {
    v9 = CmpFileFlush(a1, 0);
    goto LABEL_9;
  }
  return v7;
}
