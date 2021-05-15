// IoMakeAssociatedIrpPriv 
 
int __fastcall IoMakeAssociatedIrpPriv(int a1, int a2, char a3)
{
  int v3; // r9
  int v5; // r7
  int v8; // r8
  char v9; // r5
  unsigned int v10; // r0
  int v11; // r3
  unsigned int v12; // r10
  int v13; // r5
  int v14; // r4
  int v15; // r3
  int v16; // r3
  int v17; // r2
  unsigned int v19; // r3
  int v20; // [sp+4h] [bp-2Ch]
  int v21; // [sp+Ch] [bp-24h]

  v3 = 0;
  v5 = a3;
  v20 = 0;
  if ( (IopFunctionPointerMask & 4) != 0 )
    return sub_521578(&IopIrpExtensionStatus);
  if ( a2 && (*(_DWORD *)(a2 + 28) & 0x8000000) != 0 )
  {
    v5 = (char)(a3 + 1);
    v20 = 1;
    if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
    {
      v17 = *(_DWORD *)(a1 + 104);
      if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 && v17 && (*(_WORD *)(v17 + 2) & 1) != 0 )
        v3 = *(_DWORD *)(a1 + 104);
    }
  }
  v8 = (unsigned __int16)(40 * v5 + 112);
  v9 = 0;
  v10 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( v5 > (char)IopLargeIrpStackLocations )
    goto LABEL_22;
  if ( v5 == 1 )
  {
    v11 = 0;
  }
  else if ( v5 <= (char)IopMediumIrpStackLocations )
  {
    v8 = (unsigned __int16)(40 * (char)IopMediumIrpStackLocations + 112);
    v11 = 1;
  }
  else
  {
    v8 = (unsigned __int16)(40 * (char)IopLargeIrpStackLocations + 112);
    v11 = 2;
  }
  v12 = v10 + 8 * v11;
  v13 = *(_DWORD *)(v12 + 1408);
  ++*(_DWORD *)(v13 + 12);
  v14 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v13);
  if ( !v14 )
  {
    ++*(_DWORD *)(v13 + 16);
    v13 = *(_DWORD *)(v12 + 1412);
    ++*(_DWORD *)(v13 + 12);
    v14 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v13);
    if ( !v14 )
      ++*(_DWORD *)(v13 + 16);
  }
  if ( (IopIrpStackProfilerFlags & 3) != 0 )
  {
    if ( v14 )
    {
      v19 = *(_DWORD *)(v14 + 28);
      if ( v19 >= (unsigned __int16)(40 * v5 + 112) )
      {
        v8 = (unsigned __int16)v19;
        goto LABEL_14;
      }
      ++*(_DWORD *)(v13 + 20);
      ExFreePoolWithTag(v14, 0);
    }
    v9 = 4;
    goto LABEL_22;
  }
LABEL_14:
  v9 = 4;
  if ( v14 )
  {
LABEL_15:
    memset((_BYTE *)v14, 0, v8);
    *(_WORD *)v14 = 6;
    *(_BYTE *)(v14 + 35) = v5 + 1;
    *(_WORD *)(v14 + 2) = v8;
    *(_BYTE *)(v14 + 34) = v5;
    *(_BYTE *)(v14 + 38) = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A);
    *(_DWORD *)(v14 + 16) = v14 + 16;
    *(_DWORD *)(v14 + 20) = v14 + 16;
    v21 = 40 * v5;
    v15 = *(_DWORD *)(v14 + 8);
    *(_DWORD *)(v14 + 96) = 40 * v5 + v14 + 112;
    *(_DWORD *)(v14 + 8) = v15 | 8;
    *(_DWORD *)(v14 + 8) = *(_DWORD *)(a1 + 8) & 0xE0002 | v15 | 8;
    *(_BYTE *)(v14 + 39) |= v9;
    v16 = *(_DWORD *)(a1 + 80);
    *(_DWORD *)(v14 + 12) = a1;
    *(_DWORD *)(v14 + 80) = v16;
    if ( v20 )
    {
      --*(_BYTE *)(v14 + 35);
      --*(_BYTE *)(v14 + 34);
      *(_DWORD *)(v14 + 96) = v21 + v14 + 72;
      *(_DWORD *)(v14 + 104) = v21 + v14 + 72;
    }
    if ( v3 )
      IoSetActivityIdIrp(v14, v3 + 12);
    return v14;
  }
LABEL_22:
  v14 = ExAllocatePoolWithTag(512, v8, 544240201);
  if ( v14 )
    goto LABEL_15;
  return 0;
}
