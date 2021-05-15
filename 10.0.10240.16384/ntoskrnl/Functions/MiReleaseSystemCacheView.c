// MiReleaseSystemCacheView 
 
__int16 *__fastcall MiReleaseSystemCacheView(unsigned int a1)
{
  unsigned int v2; // r6
  int v3; // r1
  char v4; // r3
  __int16 *result; // r0
  unsigned int v6; // r10
  unsigned int v7; // r4
  int v8; // r0
  _DWORD *v9; // r1
  int v10; // r4
  int v11; // r0
  char v12[16]; // [sp+8h] [bp-108h] BYREF
  int v13; // [sp+18h] [bp-F8h] BYREF
  char v14; // [sp+1Ch] [bp-F4h]
  char v15; // [sp+1Dh] [bp-F3h]
  int v16; // [sp+20h] [bp-F0h]
  int v17; // [sp+24h] [bp-ECh]
  int v18; // [sp+28h] [bp-E8h]
  int v19; // [sp+2Ch] [bp-E4h]

  MiChargeWsles((int)&dword_634E00, -64, 0);
  v2 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_6342D0, (unsigned int)v12);
  v3 = (int)(((a1 >> 10) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2;
  v4 = byte_6338A0[v3] - 1;
  byte_6338A0[v3] = v4;
  if ( v4 )
  {
    InsertTailListPte(&dword_6342C4, a1);
  }
  else
  {
    v2 = a1 & 0xFFFFF000;
    v6 = (a1 & 0xFFFFF000) + 4096;
    v7 = a1 & 0xFFFFF000;
    if ( (a1 & 0xFFFFF000) < v6 )
    {
      do
      {
        if ( v7 != a1 )
        {
          v8 = RemoveListEntryPte(&dword_6342C4, v7);
          if ( (*(_DWORD *)(v7 + 12) & 0xFFFFF000) == 4096 )
            return (__int16 *)sub_54D15C(v8);
          v9 = (_DWORD *)(v7 + 12);
          if ( v7 + 1073741836 > 0x3FFFFF )
          {
            *v9 = 0;
          }
          else
          {
            __dmb(0xBu);
            *v9 = 0;
            if ( v7 + 1070596108 <= 0xFFF )
            {
              v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * ((unsigned __int16)v9 & 0xFFF)), 0);
            }
          }
        }
        v7 += 256;
      }
      while ( v7 < v6 );
      v2 = a1 & 0xFFFFF000;
    }
  }
  result = (__int16 *)KeReleaseInStackQueuedSpinLock((int)v12);
  if ( v2 )
  {
    v17 = 0;
    v18 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v16 = 33;
    v19 = 0;
    MiInsertTbFlushEntry((int)&v13, v2 << 10, 1024, 0);
    v10 = (v2 << 10 >> 20) & 0xFFC;
    ExFreePoolWithTag(MiState[((int)(v10 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2) + 1032], 0);
    MiState[((int)(v10 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2) + 1032] = 0;
    result = MiReturnSystemVa(v2 << 10, (v2 + 4096) << 10, 8, (unsigned int)&v13);
  }
  return result;
}
