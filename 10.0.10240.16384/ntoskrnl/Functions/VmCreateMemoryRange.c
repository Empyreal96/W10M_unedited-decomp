// VmCreateMemoryRange 
 
int __fastcall VmCreateMemoryRange(unsigned int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  int v9; // r5
  int v10; // r4
  unsigned int *v11; // r4
  unsigned int *v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r3
  _BYTE *v16; // r0
  _DWORD *v17; // r5
  int v18; // r3

  v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( VmValidateMemoryRangeParameters() )
    return -1073741811;
  if ( !VmTbFlushEnabled )
    VmTbFlushEnabled = 1;
  v11 = *(unsigned int **)(v9 + 800);
  if ( !v11 )
  {
    v12 = (unsigned int *)ExAllocatePoolWithTag(512, 28, 1666215254);
    v11 = v12;
    if ( !v12 )
      return -1073741670;
    memset(v12, 0, 28);
    v11[6] = a5;
    v11[1] = 0;
    v11[2] = 0;
    v11[3] = 0;
    v11[4] = 0;
    __dmb(0xBu);
    v13 = (unsigned int *)(v9 + 800);
    do
      v14 = __ldrex(v13);
    while ( !v14 && __strex((unsigned int)v11, v13) );
    __dmb(0xBu);
    if ( v14 )
    {
      ExFreePoolWithTag((unsigned int)v11);
      v11 = *(unsigned int **)(v9 + 800);
    }
  }
  v15 = v11[6];
  if ( v15 != -1 && v15 != a5 )
    return -1073740007;
  v16 = (_BYTE *)ExAllocatePoolWithTag(512, 40, 1917676886);
  v17 = v16;
  if ( !v16 )
    return -1073741670;
  memset(v16, 0, 40);
  v18 = (a2 << 20) | (a1 >> 12);
  v17[6] = v18;
  v17[7] = v18 + a4 - 1;
  v17[8] = a3 >> 12;
  v17[9] = (a3 >> 12) + a4 - 1;
  v10 = VmpInsertMemoryRange(v11, v17, a5);
  if ( v10 >= 0 )
  {
    v17 = 0;
    v10 = 0;
  }
  if ( v17 )
    ExFreePoolWithTag((unsigned int)v17);
  return v10;
}
