// MiPrefetchRestOfCluster 
 
int __fastcall MiPrefetchRestOfCluster(int result, int a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  int v5; // r8
  unsigned int v6; // r5
  unsigned int v7; // r2
  unsigned int *v8; // r3
  unsigned int v9; // r1
  int v10; // r3
  char v11; // r0
  unsigned int v12; // [sp+0h] [bp-20h] BYREF
  int v13; // [sp+4h] [bp-1Ch]
  int v14; // [sp+8h] [bp-18h]

  v12 = a2;
  v13 = a3;
  v14 = a4;
  v4 = *(_QWORD *)(a2 + 8);
  v5 = a3;
  if ( HIDWORD(v4) < (unsigned int)v4 )
  {
    v6 = *(_DWORD *)(result + 128);
    if ( v6 >= dword_63389C )
    {
      v10 = *((unsigned __int8 *)&MiState[2423]
            + ((int)(((v6 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v10 != 1 && v10 != 11 )
        v5 = 1;
    }
    v7 = (*(_DWORD *)(result + 104) + v6 + 4095) & 0xFFFFF000;
    v8 = (unsigned int *)(*(_DWORD *)(a2 + 4) + 8 * HIDWORD(v4));
    v9 = *v8;
    if ( v7 >= *v8 )
    {
      result = v8[1];
      if ( v7 < result + v9 )
      {
        v12 = v7;
        v13 = result - v7 + v9;
        v11 = MiGetEffectivePagePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
        result = MiPrefetchVirtualMemory(1, &v12, v5, v11 & 7 | (8 * (v11 & 7 | 0x800)));
      }
    }
  }
  return result;
}
