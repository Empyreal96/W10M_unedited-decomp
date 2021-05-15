// MiMakeZeroedPageTableRange 
 
void __fastcall MiMakeZeroedPageTableRange(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5)
{
  int v6; // r9
  unsigned int *v9; // r0
  unsigned int v10; // r3
  unsigned int v11; // r4
  int v12; // r8
  _DWORD *v13; // r9
  int *v14; // r2
  int v15; // r0
  int v16; // r4
  char v17[4]; // [sp+8h] [bp-38h] BYREF
  int v18; // [sp+Ch] [bp-34h]
  char v19[8]; // [sp+10h] [bp-30h] BYREF
  _DWORD v20[10]; // [sp+18h] [bp-28h] BYREF

  v6 = a3;
  v18 = a3;
  __dmb(0xBu);
  v20[0] = 0;
  v20[1] = 0;
  v20[2] = 0;
  MI_INITIALIZE_COLOR_BASE(0, 0, (int)v19);
  v9 = (unsigned int *)(v6 + 8 * a4);
  if ( a1 < *v9 )
    a1 = *v9;
  if ( a2 > v9[1] )
    a2 = v9[1];
  if ( a1 <= a2 )
  {
    while ( 1 )
    {
      v10 = *(_DWORD *)(a5 + 16);
      if ( a4 < v10 )
        return;
      v11 = *(_DWORD *)a1;
      v12 = 0;
      if ( a4 )
      {
        if ( a4 > 1 && *(_DWORD *)(a5 + 8) )
        {
          v12 = 1;
          KeAcquireInStackQueuedSpinLock(&dword_633880, (unsigned int)v20);
          v11 = *(_DWORD *)a1;
        }
      }
      else if ( v10 )
      {
        sub_510620();
        return;
      }
      if ( (v11 & 2) == 0 )
        break;
      v14 = &MiState[a4];
      if ( v11 >> 12 == v14[1957] || v11 >> 12 == v14[1955] || (v11 & 0x80) == 0 && (v11 & 0x200) != 0 )
        break;
      if ( v12 == 1 )
        KeReleaseInStackQueuedSpinLock((int)v20);
      if ( a4 != 1 )
        goto LABEL_31;
      if ( (v11 & 0x400) == 0 )
        goto LABEL_27;
LABEL_18:
      a1 += 4;
      v6 = v18;
      if ( a1 > a2 )
        return;
    }
    v13 = *(_DWORD **)a5;
    *(_DWORD *)a5 = **(_DWORD **)a5;
    if ( (v11 & 2) != 0 )
    {
      v15 = ((int)v13 - MmPfnDatabase) / 24;
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
      {
        v16 = MiMapPageInHyperSpaceWorker(v15, (int)v17, 0x80000000);
        memmove(v16, a1 << 10, 0x1000u);
        MiUnmapPageInHyperSpaceWorker(v16, (unsigned __int8)v17[0], 0x80000000);
      }
      else
      {
        MxCopyPage(v15, a1 << 10);
      }
    }
    MiInitializeSystemPageTable(a1, v13);
    if ( a4 == 1 && *(_DWORD *)(a5 + 8) )
      MiReplicatePteChange(a1 << 10, a1 << 10);
    if ( v12 == 1 )
      KeReleaseInStackQueuedSpinLock((int)v20);
    ++*(_DWORD *)(a5 + 4);
    if ( a4 == 1 && *(_DWORD *)(a5 + 16) )
      goto LABEL_18;
    v6 = v18;
LABEL_31:
    if ( !a4 )
      goto LABEL_18;
LABEL_27:
    MiMakeZeroedPageTableRange(a1 << 10, (a1 << 10) + 4092, v6, a4 - 1, a5);
    goto LABEL_18;
  }
}
