// ExTryToAcquireResourceExclusiveLite 
 
int __fastcall ExTryToAcquireResourceExclusiveLite(int a1, int a2, int a3, int a4)
{
  BOOL v5; // r6
  unsigned int v6; // r3
  unsigned int v7; // r7
  int v8; // r5
  int v9; // r8
  unsigned int v10; // r10
  int v11; // r9
  __int16 v12; // r3
  int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r3
  _DWORD v17[10]; // [sp+0h] [bp-28h] BYREF

  v17[1] = a3;
  v17[2] = a4;
  v5 = (dword_682604 & 0x20000) != 0;
  v6 = (unsigned int)KeGetPcr();
  v7 = 0;
  v8 = 65537;
  ++*(_DWORD *)((v6 & 0xFFFFF000) + 0x14A0);
  v9 = 0;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 52), (unsigned int)v17);
  v11 = 0;
  v12 = *(_WORD *)(a1 + 14);
  if ( !*(_DWORD *)(a1 + 32) )
  {
    *(_WORD *)(a1 + 14) = v12 | 0x80;
    v13 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 24) = v10;
    *(_DWORD *)(a1 + 28) = v13 & 3 | 4;
    *(_DWORD *)(a1 + 32) = 1;
    *(_WORD *)(a1 + 12) = 1;
    v11 = 1;
    v14 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v14 & 0xFFFFF000) + 0x14A4);
    ++*(_DWORD *)((v14 & 0xFFFFF000) + 0x1424);
    if ( !v5 )
      goto LABEL_9;
    v8 = 65569;
    v7 = 1;
    goto LABEL_8;
  }
  if ( (v12 & 0x80) != 0 && *(_DWORD *)(a1 + 24) == v10 )
  {
    v11 = 1;
    *(_DWORD *)(a1 + 28) = *(_DWORD *)(a1 + 28) & 3 ^ ((*(_DWORD *)(a1 + 28) & 0xFFFFFFFC) + 4);
    v15 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v15 & 0xFFFFF000) + 0x14A4);
    ++*(_DWORD *)((v15 & 0xFFFFF000) + 0x1424);
    if ( v5 )
    {
      v8 = 65585;
      v7 = *(_DWORD *)(a1 + 28) >> 2;
LABEL_8:
      v9 = *(_DWORD *)(a1 + 36);
      goto LABEL_9;
    }
  }
LABEL_9:
  KeReleaseInStackQueuedSpinLock((int)v17);
  if ( v5 )
    PerfLogExecutiveResourceAcquire(v8, a1, v7, v9);
  return v11;
}
