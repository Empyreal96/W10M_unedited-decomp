// HvpReviveDiscardedBin 
 
int __fastcall HvpReviveDiscardedBin(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // r7
  int v5; // r10
  int v8; // r5
  int v9; // r4
  int v10; // r6
  unsigned int v11; // r7
  char v12; // r3
  unsigned int v13; // r6
  unsigned int *v14; // r0
  int v16; // [sp+10h] [bp-28h] BYREF
  unsigned int v17; // [sp+14h] [bp-24h] BYREF
  int v18; // [sp+18h] [bp-20h]

  v4 = a4;
  v5 = *(_DWORD *)(a2 + 12) + (a4 << 31);
  v17 = 0;
  v18 = a4;
  v16 = 0;
  if ( a4 == 1 )
  {
    v8 = 0;
    v9 = ExAllocatePoolWithTag(1, a3, 1648905539);
    if ( !v9 )
      return -1073741670;
    goto LABEL_7;
  }
  v10 = HvpAllocateBin(a1, a3, a4, v5, 892423491, &v16, (int *)&v17);
  v9 = v16;
  v8 = v17;
  if ( v10 >= 0 )
  {
    if ( v17 )
    {
      v11 = v17;
      goto LABEL_8;
    }
LABEL_7:
    v11 = v9;
    if ( v9 )
    {
      v12 = 0;
      goto LABEL_10;
    }
LABEL_8:
    v12 = 1;
LABEL_10:
    v10 = HvpProtectBin(a1, a3, v18, v5, v11, v12);
    if ( v10 >= 0 )
    {
      memset((_BYTE *)v11, 0, a3);
      *(_DWORD *)(v11 + 8) = a3;
      v13 = 0;
      *(_DWORD *)v11 = 1852400232;
      *(_DWORD *)(v11 + 28) = 0;
      *(_DWORD *)(v11 + 4) = v5 & 0x7FFFFFFF;
      for ( *(_DWORD *)(v11 + 32) = a3 - 32; v13 < a3; v13 += 4096 )
      {
        v14 = (unsigned int *)HvpGetCellMap(a1, v13 + v5);
        if ( !v14 )
          KeBugCheckEx(81, 1, a1, v13 + v5, 642);
        *v14 = v13;
        v14[1] = v9;
        v14[2] = v8;
        if ( v13 )
        {
          v14[4] = 0;
        }
        else
        {
          v14[1] = v9 | 1;
          v14[4] = a3;
        }
        if ( v8 )
          v14[3] = 0;
        else
          v14[3] = 1;
      }
      v9 = 0;
      v8 = 0;
      v10 = 0;
    }
    v4 = v18;
  }
  if ( v9 || v8 )
    HvpFreeBin(a1, a3, v4, v9, v8);
  return v10;
}
