// MmPrefetchVirtualAddresses 
 
int __fastcall MmPrefetchVirtualAddresses(_DWORD *a1)
{
  unsigned int v3; // r2
  int v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r4
  _DWORD *v7; // r0
  int v8; // r1

  if ( *a1 != 1 )
    return -1073741585;
  v3 = a1[1];
  if ( (v3 & 0xFFFFFFF8) != 0 )
    return -1073741585;
  v4 = (v3 >> 1) & 3;
  if ( v4 == 3 )
    return -1073741585;
  if ( v4 )
  {
    if ( v4 == 1 )
      v5 = 2;
    else
      v5 = MiGetEffectivePagePriorityThread((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0)) & 7;
  }
  else
  {
    v5 = 5;
  }
  if ( (v5 & 7) < 5 )
    v5 |= 0x40u;
  v6 = ((unsigned __int8)v5 ^ (unsigned __int8)(8 * v5)) & 0x38 ^ v5;
  if ( (v6 & 7) < 5 && (a1[1] & 1) == 0 )
    v6 = v6 & 0xFFFFFFC7 | 0x28;
  v7 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v8 = (v7[240] >> 9) & 7;
  if ( (*(_DWORD *)(v7[84] + 192) & 0x100000) != 0 )
    v8 = 0;
  if ( v8 < 2 && v7 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v7[250] )
    v8 = 2;
  if ( v8 <= 1 )
    v6 |= 0x400u;
  return MmPrefetchVirtualMemory(a1[2], a1[3], a1[4], v6);
}
