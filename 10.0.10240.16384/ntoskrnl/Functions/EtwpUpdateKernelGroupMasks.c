// EtwpUpdateKernelGroupMasks 
 
int __fastcall EtwpUpdateKernelGroupMasks(unsigned int a1, int a2)
{
  int v4; // r0
  int v5; // r3
  unsigned int i; // r1
  int v8; // r0
  int *v9; // r2
  int v10; // r6
  int v11; // t1
  int v12; // r2
  int v13; // r6
  _DWORD *v14; // r5
  unsigned int j; // r4
  int v16; // r1
  _DWORD v17[8]; // [sp+8h] [bp-80h] BYREF
  char v18[32]; // [sp+28h] [bp-60h] BYREF
  char v19[64]; // [sp+48h] [bp-40h] BYREF

  v4 = KeWaitForSingleObject((unsigned int)&EtwpGroupMaskMutex, 0, 0, 0, 0);
  if ( a2 != 8 )
  {
    if ( a1 >= 0x40 )
      LOBYTE(v5) = 1;
    else
      v5 = WmipLoggerContext[a1];
    if ( (v5 & 1) != 0 )
      return sub_7D03C0(v4);
  }
  memset(v17, 0, sizeof(v17));
  for ( i = 0; i < 8; ++i )
  {
    v8 = v17[i];
    v9 = &EtwpGroupMasks[i];
    v10 = 9;
    do
    {
      v11 = *v9;
      v9 += 8;
      v8 |= v11;
      --v10;
    }
    while ( v10 );
    v12 = PerfGlobalGroupMask[i];
    v17[i] = v8;
    *(_DWORD *)&v18[i * 4] = v8 & ~v12;
    *(_DWORD *)&v19[i * 4] = v12 & ~v8;
  }
  EtwpDisableKernelTrace(v17, v19, a1);
  v13 = EtwpEnableKernelTrace(v17, v18, a1);
  if ( v13 < 0 )
  {
    v14 = &EtwpGroupMasks[8 * a2];
    for ( j = 0; j < 8; ++j )
    {
      v16 = *(_DWORD *)&v18[j * 4];
      v17[j] &= ~v16;
      *v14++ &= ~v16;
    }
  }
  PerfGlobalGroupMask[0] = v17[0];
  dword_682604 = v17[1];
  dword_682608 = v17[2];
  *(_DWORD *)algn_68260C = v17[3];
  dword_682610 = v17[4];
  dword_682614 = v17[5];
  *(_DWORD *)algn_682618 = v17[6];
  *(_DWORD *)&algn_682618[4] = v17[7];
  KeReleaseMutex((int)&EtwpGroupMaskMutex);
  return v13;
}
