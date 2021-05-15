// KiExpandKernelStackAndCalloutOnStackSegment 
 
int __fastcall KiExpandKernelStackAndCalloutOnStackSegment(int a1, int a2, unsigned int a3, char a4, _BYTE *a5)
{
  __int16 v5; // r7
  int v6; // r10
  unsigned int v9; // r5
  int v10; // r3
  _BYTE *v11; // r0
  int *v12; // r1
  int v13; // r4
  int v14; // r6
  int v15; // r2
  int v16; // r3
  int v17; // r3
  int v18; // r9
  int v19; // r0
  int v20; // r0
  unsigned int v22; // r2
  unsigned int v23; // r2
  char v24; // r3
  int *v25; // [sp+8h] [bp-38h]
  int v28; // [sp+14h] [bp-2Ch]
  _DWORD v29[10]; // [sp+18h] [bp-28h] BYREF

  v5 = 0;
  v6 = 0;
  v25 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = KeGetCurrentIrql(a1);
  v11 = a5;
  v28 = v10;
  if ( v10 == 2 )
  {
    v12 = v29;
    v29[0] = 0;
    v29[1] = 0;
    v25 = v29;
    if ( a5 )
      v5 = 16;
    else
      a4 |= 4u;
  }
  else
  {
    v12 = 0;
  }
  v13 = 0;
  if ( a3 <= KeKernelStackSize )
  {
    a4 |= 8u;
    goto LABEL_5;
  }
  v13 = 1;
  v6 = 1;
  v5 |= 1u;
  if ( !a5 )
  {
LABEL_5:
    if ( (v5 & 0x10) == 0 )
    {
      if ( (a4 & 2) == 0 )
        v13 |= 2u;
      if ( (a4 & 4) != 0 )
        v6 |= 2u;
      if ( (a4 & 8) != 0 )
      {
        v13 |= 0x10u;
        v6 |= 8u;
      }
      v14 = MmCreateKernelStack(
              v13,
              *(unsigned __int8 *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)(v9 + 364)) + 590) + 266),
              v9);
      if ( v14 )
        goto LABEL_13;
      v12 = v25;
      v11 = a5;
    }
    if ( v11 && ((v5 & 1) == 0 || v11[4]) )
    {
      v22 = *(unsigned __int8 *)(v9 + 77);
      *(_BYTE *)(v9 + 77) = v22 | 0x80;
      if ( v22 >> 7 )
        v5 |= 4u;
      if ( KeWaitForSingleObject((unsigned int)(v11 + 8), 25, 0, 0, v12) == 258 )
      {
        v18 = -1073740024;
        *(_DWORD *)(v9 + 76) ^= ((unsigned __int16)*(_DWORD *)(v9 + 76) ^ (unsigned __int16)(v5 << 13)) & 0x8000;
        return v18;
      }
      v23 = (unsigned __int8)a5[6];
      if ( v23 < (unsigned __int8)a5[5] )
      {
        v14 = *(_DWORD *)&a5[4 * v23 + 40];
        LOBYTE(v5) = v5 | 8;
        a5[6] = v23 + 1;
        if ( (v5 & 1) == 0 && a5[4] )
        {
          LOBYTE(v13) = v13 | 5;
          LOBYTE(v5) = v5 | 1;
        }
LABEL_13:
        v15 = v14 - 24;
        *(_DWORD *)(v14 - 24) = v14;
        if ( (v5 & 1) != 0 )
          v16 = v14 - 61439;
        else
          v16 = v14 - KeKernelStackSize + 1;
        *(_DWORD *)(v14 - 20) = v16;
        *(_DWORD *)(v14 - 16) = *(_DWORD *)(v9 + 40);
        *(_DWORD *)(v14 - 4) = *(_DWORD *)(v9 + 32);
        if ( (v13 & 1) != 0 )
        {
          v15 |= 1u;
          if ( (v13 & 4) != 0 )
            v15 |= 2u;
        }
        v17 = *(_DWORD *)(v9 + 76);
        if ( (v17 & 0x1000) != 0 )
          LOBYTE(v5) = v5 | 2;
        else
          *(_DWORD *)(v9 + 76) = v17 | 0x1000;
        v18 = KiSwitchKernelStackAndCallout(a2, a1, v15);
        if ( (v5 & 8) != 0 )
        {
          v24 = a5[6] - 1;
          a5[6] = v24;
          if ( !v24 && (v5 & 4) == 0 )
            *(_DWORD *)(v9 + 76) &= 0xFFFF7FFF;
          v19 = KeReleaseMutant((unsigned int)(a5 + 8), 1, 0, 0);
        }
        else
        {
          v19 = MmDeleteKernelStack(v14, v6);
        }
        if ( (v5 & 2) == 0 )
          *(_DWORD *)(v9 + 76) &= 0xFFFFEFFF;
        v20 = KeGetCurrentIrql(v19);
        if ( v20 != v28 )
          KeBugCheckEx(200, v28, v20);
        return v18;
      }
      KeReleaseMutant((unsigned int)(a5 + 8), 1, 0, 0);
    }
    return -1073741801;
  }
  return sub_5480E4(a5, v12, 8);
}
