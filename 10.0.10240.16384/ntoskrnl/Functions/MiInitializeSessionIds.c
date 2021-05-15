// MiInitializeSessionIds 
 
int MiInitializeSessionIds()
{
  _DWORD *v0; // r0
  int result; // r0
  int v2[22]; // [sp+10h] [bp-68h] BYREF

  dword_633780 = 0;
  v0 = (_DWORD *)ExAllocatePoolWithTag(1, 16, 538996045);
  dword_634D30 = (int)v0;
  if ( !v0 || (v0[1] = v0 + 2, *v0 = 64, !dword_634D30) )
    KeBugCheck2(125, dword_640508, dword_640500, dword_640504, 0x200u, 0);
  RtlClearAllBits(dword_634D30);
  memset(v2, 0, sizeof(v2));
  LOWORD(v2[0]) = 88;
  BYTE2(v2[0]) |= 8u;
  v2[9] = 512;
  v2[2] = 0;
  v2[3] = 131073;
  v2[4] = 131074;
  v2[5] = 1179649;
  v2[6] = 983043;
  v2[11] = 24;
  v2[7] = 983043;
  v2[15] = (int)MiSessionObjectDelete;
  BYTE2(v2[0]) |= 4u;
  result = ObCreateObjectType();
  if ( result < 0 )
    sub_969EFC();
  return result;
}
