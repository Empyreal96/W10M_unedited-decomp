// MiForcedTrim 
 
int __fastcall MiForcedTrim(int a1, int a2)
{
  int v2; // r4
  int v4; // r8
  int v5; // r6
  unsigned int v6; // r0
  unsigned int v7; // r9
  unsigned int v8; // r3
  __int64 v9; // r0
  unsigned int v10; // r8
  unsigned int v11; // r1
  char v12; // r10
  unsigned int v13; // r0
  unsigned int v14; // r3
  int v15; // r0
  int v16; // r0
  int v17; // r0
  unsigned int *v18; // r1
  int *v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v23; // [sp+8h] [bp-70h]
  int v24; // [sp+Ch] [bp-6Ch]
  int v25[3]; // [sp+10h] [bp-68h] BYREF
  int v26; // [sp+1Ch] [bp-5Ch]
  char v27; // [sp+20h] [bp-58h] BYREF
  unsigned __int8 v28; // [sp+21h] [bp-57h]
  char v29; // [sp+23h] [bp-55h]
  unsigned int v30; // [sp+48h] [bp-30h]
  unsigned int v31; // [sp+4Ch] [bp-2Ch]
  unsigned int v32; // [sp+50h] [bp-28h]
  int vars4; // [sp+7Ch] [bp+4h]

  v2 = a2;
  v4 = 0;
  v5 = *(_DWORD *)(a1 + 108);
  v26 = a2;
  v23 = 0;
  v24 = 1;
  v32 = 0;
  v6 = MiGetAvailablePagesForTrimPass((int)MiSystemPartition, 0);
  v7 = v6;
  if ( v2 == 1 )
  {
    v8 = *(_DWORD *)(dword_6404B8 + 1248);
    if ( v6 >= v8 )
    {
      v5 = 0;
    }
    else
    {
      v5 = v8 - v6;
      if ( v8 - v6 < 0x10 )
        v5 = 16;
    }
    v24 = 9;
  }
  if ( v5 )
  {
    LODWORD(v9) = &v27;
    HIDWORD(v9) = MiSystemPartition;
    MiInitializeTrimCriteria(v9, v5, 4);
    v10 = v32;
    v11 = v30;
    v12 = v27;
    do
    {
      v31 = v5 - v10;
      if ( v5 == v10 )
        break;
      if ( (v12 & 0x7F) != 0 )
      {
        v28 = *((_BYTE *)MiTrimPassToAge + (v12 & 0x7F));
        v29 = 0;
        v13 = MiComputeTrimAmount((int)&v27, a1, 1);
        v10 = v32;
        v11 = v30;
        v14 = v28;
        v12 = v27;
      }
      else
      {
        v13 = *(_DWORD *)(a1 + 44) + *(_DWORD *)(a1 + 40);
        v14 = 6;
      }
      if ( v10 >= v11 || v14 < 2 && (unsigned int)dword_640580 >= 0x80 || v7 >= (unsigned int)dword_6402AC >> 1 )
        break;
      if ( v13 )
      {
        if ( v13 > v11 - v10 )
          v13 = v11 - v10;
        v15 = MiTrimWorkingSet(v13, a1, 17, v14, v24);
        v10 += v15;
        v32 = v10;
        v23 = v15;
      }
      if ( v2 == 1 )
        break;
      v12 = v12 & 0x80 | (v12 + 1) & 0x7F;
      v27 = v12;
      v16 = MiGetAvailablePagesForTrimPass((int)MiSystemPartition, v12 & 0x7F);
      v11 = v30;
      v2 = v26;
      v7 = v16;
    }
    while ( (v12 & 0x7Fu) < 4 );
    v4 = v23;
  }
  if ( *(_DWORD *)(a1 + 108) )
  {
    KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634980, v25);
    *(_DWORD *)(a1 + 108) = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v25, vars4);
    }
    else
    {
      v17 = v25[0];
      if ( !v25[0] )
      {
        v18 = (unsigned int *)v25[1];
        __dmb(0xBu);
        do
          v19 = (int *)__ldrex(v18);
        while ( v19 == v25 && __strex(0, v18) );
        if ( v19 == v25 )
          goto LABEL_35;
        v17 = KxWaitForLockChainValid(v25);
      }
      v25[0] = 0;
      __dmb(0xBu);
      v20 = (unsigned int *)(v17 + 4);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 ^ 1, v20) );
    }
  }
LABEL_35:
  if ( !v2 || (*(_DWORD *)(a1 + 100) & 0x3FFF) == 0 )
    *(_BYTE *)(a1 + 115) |= 0x10u;
  return v4;
}
