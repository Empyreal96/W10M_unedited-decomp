// MiMapPageInHyperSpaceWorker 
 
int __fastcall MiMapPageInHyperSpaceWorker(int a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r3
  unsigned int v6; // r5
  unsigned int v7; // r3
  unsigned int v8; // r7
  unsigned int *v9; // r1
  unsigned int v10; // r3
  int v11; // r4
  int v12; // r0
  unsigned int v13; // r3
  int v14; // r4
  int v15; // r0

  if ( (a3 & 0x20000000) != 0 )
    return sub_50DAAC(a1, a3 & 0x20000000);
  v4 = 4;
  if ( (a3 & 0x40000000) != 0 )
    v5 = a3 & 3;
  else
    v5 = *(unsigned __int8 *)(MmPfnDatabase + 24 * a1 + 18) >> 6;
  if ( !v5 || v5 == 3 )
  {
    v4 = 12;
  }
  else if ( v5 == 2 )
  {
    v4 = 28;
  }
  v6 = (MmProtectToPteMask[v4] & 0xFED | (a1 << 12) | 0x12) & 0xFFFFF1FF;
  v7 = (unsigned int)KeGetPcr();
  v8 = (*(_DWORD *)((v7 & 0xFFFFF000) + 0x1384) & 0xFFFFF000)
     + ((*(_DWORD *)((v7 & 0xFFFFF000) + 0x1384) & 0xFFF) << 12);
  v9 = (unsigned int *)(((v8 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( a3 >= 0 )
  {
    v13 = *v9;
    v14 = 0;
    __dmb(0xBu);
    *v9 = v6;
    if ( (v13 & 2) == 0 )
      v14 = 1;
    if ( ((v8 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
    {
      v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v15, v15 + 4 * ((v8 >> 10) & 0xFFC), v6);
    }
    if ( v14 != 1 )
      return v8;
  }
  else
  {
    v10 = *v9;
    v11 = 0;
    __dmb(0xBu);
    if ( (v10 & 2) == 0 )
      v11 = 1;
    *v9 = v6;
    if ( (unsigned int)v9 >= 0xC0300000 && (unsigned int)v9 <= 0xC0300FFF )
    {
      v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v12, v12 + 4 * ((v8 >> 10) & 0xFFC), v6);
    }
    if ( v11 != 1 )
      return v8;
  }
  __dsb(0xFu);
  __isb(0xFu);
  return v8;
}
