// IopAllocateReserveIrp 
 
int __fastcall IopAllocateReserveIrp(int a1, char a2, int a3)
{
  __int16 v3; // r6
  unsigned int v4; // r1
  unsigned int v5; // r0
  int v6; // r2
  int v7; // r3
  unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned int v15; // r1
  unsigned int v16; // r1
  int v17; // r2
  int v18; // r3
  int v20[6]; // [sp+8h] [bp-18h] BYREF

  if ( a2 > byte_631964 )
    return 0;
  v3 = (char)(a2 + 1);
  if ( !a3 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&dword_6318E4);
    while ( __strex(1u, (unsigned int *)&dword_6318E4) );
    __dmb(0xBu);
    if ( v4 == 1 )
    {
      do
      {
        KeWaitForSingleObject((unsigned int)&byte_6318E8, 0, 0, 0, 0);
        __dmb(0xBu);
        do
          v5 = __ldrex((unsigned int *)&dword_6318E4);
        while ( __strex(1u, (unsigned int *)&dword_6318E4) );
        __dmb(0xBu);
      }
      while ( v5 == 1 );
    }
    IoInitializeIrp(IopReserveIrps, 40 * v3 + 112, v3);
    *(_BYTE *)(IopReserveIrps + 39) = 33;
    v6 = IopReserveIrps;
    --*(_BYTE *)(IopReserveIrps + 35);
    --*(_BYTE *)(v6 + 34);
    v7 = *(_DWORD *)(v6 + 96) - 40;
    *(_DWORD *)(v6 + 96) = v7;
    *(_DWORD *)(v6 + 104) = v7;
    if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
      IopInitActivityIdIrp(IopReserveIrps);
    return IopReserveIrps;
  }
  if ( a3 == 1 )
  {
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&dword_6318FC);
    while ( __strex(1u, (unsigned int *)&dword_6318FC) );
    __dmb(0xBu);
    if ( v10 == 1 )
    {
      do
      {
        KeWaitForSingleObject((unsigned int)&byte_631900, 0, 0, 0, 0);
        __dmb(0xBu);
        do
          v11 = __ldrex((unsigned int *)&dword_6318FC);
        while ( __strex(1u, (unsigned int *)&dword_6318FC) );
        __dmb(0xBu);
      }
      while ( v11 == 1 );
    }
    IoInitializeIrp(dword_6318F8, 40 * v3 + 112, v3);
    *(_BYTE *)(dword_6318F8 + 39) = 33;
    v12 = dword_6318F8;
    --*(_BYTE *)(dword_6318F8 + 35);
    --*(_BYTE *)(v12 + 34);
    v13 = *(_DWORD *)(v12 + 96) - 40;
    *(_DWORD *)(v12 + 96) = v13;
    *(_DWORD *)(v12 + 104) = v13;
    if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
      IopInitActivityIdIrp(dword_6318F8);
    return dword_6318F8;
  }
  if ( a3 != 3 )
    return 0;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&dword_631914);
  while ( __strex(1u, (unsigned int *)&dword_631914) );
  __dmb(0xBu);
  if ( v15 == 1 )
  {
    v20[0] = -50000000;
    v20[1] = -1;
    while ( KeWaitForSingleObject((unsigned int)&byte_631918, 0, 0, 0, v20) != 258 )
    {
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&dword_631914);
      while ( __strex(1u, (unsigned int *)&dword_631914) );
      __dmb(0xBu);
      if ( v16 != 1 )
        goto LABEL_39;
    }
    return 0;
  }
LABEL_39:
  IoInitializeIrp(dword_631910, 40 * v3 + 112, v3);
  *(_BYTE *)(dword_631910 + 39) = 33;
  v17 = dword_631910;
  --*(_BYTE *)(dword_631910 + 35);
  --*(_BYTE *)(v17 + 34);
  v18 = *(_DWORD *)(v17 + 96) - 40;
  *(_DWORD *)(v17 + 96) = v18;
  *(_DWORD *)(v17 + 104) = v18;
  if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
    IopInitActivityIdIrp(dword_631910);
  return dword_631910;
}
