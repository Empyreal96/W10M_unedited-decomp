// MmFreeIndependentPages 
 
int *__fastcall MmFreeIndependentPages(unsigned int a1, unsigned int a2)
{
  _DWORD *v2; // r4
  int v3; // r5
  _DWORD *v4; // r8
  unsigned int v5; // r6
  int v6; // r10
  int v7; // r9
  int v9; // [sp+0h] [bp-40h]
  unsigned int v10; // [sp+4h] [bp-3Ch]
  unsigned int v11; // [sp+8h] [bp-38h]
  unsigned int v12; // [sp+10h] [bp-30h] BYREF
  int v13; // [sp+14h] [bp-2Ch]
  int v14; // [sp+18h] [bp-28h]
  unsigned int v15; // [sp+1Ch] [bp-24h]

  v13 = 0;
  v14 = 0;
  v2 = (_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v10 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v3 = 0;
  v4 = &v2[v10];
  v5 = ((a1 >> 10) & 0x3FFFFC) - 3145728;
  v12 = v10;
  v15 = v10;
  v11 = (unsigned int)v2;
  do
  {
    v6 = MmPfnDatabase;
    v7 = MmPfnDatabase + 24 * (*v2 >> 12);
    v9 = 3 * (*(_DWORD *)(v7 + 20) & 0xFFFFF);
    if ( v5 + 3145728 > 0x3FFFFF )
    {
      *v2 = 0;
    }
    else
    {
      __dmb(0xBu);
      *v2 = 0;
      if ( v5 <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v2);
    }
    if ( MiLockAndDecrementShareCount(v7, 1) == 3 )
      ++v3;
    MiLockAndDecrementShareCount(v6 + 8 * v9, 0);
    ++v2;
    v5 += 4;
  }
  while ( v2 < v4 );
  v13 = v3;
  MiReleasePtes(&dword_634D58, v11, v10);
  return MiReturnNonPagedPoolCharges((int *)&v12);
}
