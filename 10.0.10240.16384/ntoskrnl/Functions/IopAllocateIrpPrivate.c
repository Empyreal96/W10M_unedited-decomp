// IopAllocateIrpPrivate 
 
int __fastcall IopAllocateIrpPrivate(int a1, char a2, int a3)
{
  int v3; // r7
  int v4; // r5
  int v5; // r8
  unsigned int v6; // r9
  unsigned int v8; // r10
  int v9; // r4
  int v10; // r3
  unsigned int v11; // r3
  int v12; // r10
  char v13; // r6
  char v14; // r1
  char v15; // r2
  char v16; // r2
  int v18; // r0
  int v19; // r3
  unsigned int v20; // r3
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // [sp+8h] [bp-30h]
  char v24; // [sp+Ch] [bp-2Ch]
  unsigned int v25; // [sp+10h] [bp-28h]
  int v26; // [sp+18h] [bp-20h]

  v3 = 0;
  v4 = a2;
  v5 = a3;
  if ( a1 && (*(_DWORD *)(a1 + 28) & 0x8000000) != 0 )
  {
    v4 = (char)(a2 + 1);
    v3 = 1;
  }
  v6 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( (IopIrpStackProfilerFlags & 4) != 0 )
    return sub_52E3E4();
  v24 = 0;
  v26 = 40 * v4;
  v8 = (unsigned __int16)(40 * v4 + 112);
  v23 = v8;
  v9 = 0;
  if ( v4 <= (char)IopLargeIrpStackLocations && (!a3 || *(int *)(v6 + 1616) > 0) )
  {
    v24 = 4;
    if ( v4 == 1 )
    {
      v10 = 0;
    }
    else if ( v4 > (char)IopMediumIrpStackLocations )
    {
      v23 = (unsigned __int16)(40 * (char)IopLargeIrpStackLocations + 112);
      v10 = 2;
    }
    else
    {
      v23 = (unsigned __int16)(40 * (char)IopMediumIrpStackLocations + 112);
      v10 = 1;
    }
    v11 = v6 + 8 * v10;
    v12 = *(_DWORD *)(v11 + 1408);
    v25 = v11;
    ++*(_DWORD *)(v12 + 12);
    v9 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v12);
    if ( !v9 )
    {
      ++*(_DWORD *)(v12 + 16);
      v12 = *(_DWORD *)(v25 + 1412);
      ++*(_DWORD *)(v12 + 12);
      v9 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v12);
      if ( !v9 )
        ++*(_DWORD *)(v12 + 16);
    }
    if ( (IopIrpStackProfilerFlags & 3) != 0 && v9 )
    {
      v20 = *(_DWORD *)(v9 + 28);
      if ( v20 < (unsigned __int16)(40 * v4 + 112) )
      {
        ++*(_DWORD *)(v12 + 20);
        ExFreePoolWithTag(v9, 0);
        v8 = v23;
        v13 = 0;
        goto LABEL_25;
      }
      v8 = (unsigned __int16)v20;
    }
    else
    {
      v8 = v23;
    }
  }
  v13 = 0;
  if ( v9 )
  {
    if ( v5 )
    {
      v19 = IopIrpCreditsEnabled;
      __dmb(0xBu);
      if ( v19 > 1 )
      {
        v13 = 8;
        __dmb(0xBu);
        v21 = (unsigned int *)(v6 + 1616);
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 - 1, v21) );
        __dmb(0xBu);
      }
    }
    v5 = 0;
    goto LABEL_17;
  }
LABEL_25:
  if ( v5 )
    v18 = ExAllocatePoolWithQuotaTag(0x208u, v8, 544240201);
  else
    v18 = ExAllocatePoolWithTag(512, v8, 544240201);
  v9 = v18;
  if ( !v18 )
    return 0;
LABEL_17:
  memset((_BYTE *)v9, 0, v8);
  *(_WORD *)v9 = 6;
  *(_BYTE *)(v9 + 35) = v4 + 1;
  *(_WORD *)(v9 + 2) = v8;
  *(_BYTE *)(v9 + 34) = v4;
  *(_BYTE *)(v9 + 38) = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A);
  *(_DWORD *)(v9 + 16) = v9 + 16;
  *(_DWORD *)(v9 + 20) = v9 + 16;
  *(_DWORD *)(v9 + 96) = v26 + v9 + 112;
  *(_BYTE *)(v9 + 39) = v24 | v13;
  if ( v5 )
    *(_BYTE *)(v9 + 39) = v24 | v13 | 1;
  if ( v3 )
  {
    v14 = *(_BYTE *)(v9 + 34);
    v15 = *(_BYTE *)(v9 + 35) - 1;
    *(_DWORD *)(v9 + 96) = v26 + v9 + 72;
    *(_DWORD *)(v9 + 104) = v26 + v9 + 72;
    *(_BYTE *)(v9 + 35) = v15;
    v16 = IopFunctionPointerMask;
    *(_BYTE *)(v9 + 34) = v14 - 1;
    if ( (v16 & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
      IopInitActivityIdIrp(v9);
  }
  return v9;
}
