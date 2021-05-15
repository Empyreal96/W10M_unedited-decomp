// ExSetResourceOwnerPointerEx 
 
int __fastcall ExSetResourceOwnerPointerEx(int a1, int a2, char a3)
{
  char v3; // r6
  unsigned int v7; // r8
  int v8; // r9
  int *v9; // r0
  int *v10; // r6
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r3
  int v16; // r3
  char v18[40]; // [sp+10h] [bp-28h] BYREF

  v3 = a3;
  if ( (dword_682604 & 0x20000) != 0 )
    return sub_54A670();
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 52), (unsigned int)v18);
  if ( (*(_WORD *)(a1 + 14) & 0x80) != 0 )
  {
    if ( (v3 & 1) != 0 )
    {
      if ( (a2 & 0xFFFFFFFC) != v7 )
        KeBugCheck2(306, a1, *(_DWORD *)(a1 + 8), v7, a2, 0);
      ObfReferenceObjectWithTag(a2 & 0xFFFFFFFC);
      v14 = *(_DWORD *)(a1 + 28) | 2;
    }
    else
    {
      if ( (*(_DWORD *)(a1 + 28) & 1) == 0 )
        goto LABEL_24;
      PsBoostThreadIoEx(*(_DWORD *)(a1 + 24), 1, 0);
      v14 = *(_DWORD *)(a1 + 28) & 0xFFFFFFFE;
    }
    *(_DWORD *)(a1 + 28) = v14;
LABEL_24:
    *(_DWORD *)(a1 + 24) = a2;
    v15 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v15 & 0xFFFFF000) + 0x1494);
    return KeReleaseInStackQueuedSpinLock((int)v18);
  }
  v8 = ExpFindCurrentThread(a1, a2, v18, 0, 0);
  v9 = (int *)ExpFindCurrentThread(a1, v7, v18, 0, 0);
  v10 = v9;
  if ( !v9 )
    KeBugCheck2(227, a1, v7, *(_DWORD *)(a1 + 8), 3, 0);
  if ( v8 )
  {
    if ( (a3 & 1) != 0 )
    {
      if ( (a2 & 0xFFFFFFFC) != v7 )
        KeBugCheck2(306, a1, *(_DWORD *)(a1 + 8), v7, a2, 0);
      if ( (v9[1] & 1) != 0 )
      {
        v16 = *(_DWORD *)(v8 + 4);
        if ( (v16 & 1) != 0 )
          PsBoostThreadIoEx(*v9, 1, 0);
        else
          *(_DWORD *)(v8 + 4) = v16 | 1;
        v10[1] &= 0xFFFFFFFE;
      }
      if ( (*(_DWORD *)(v8 + 4) & 2) == 0 )
      {
        ObfReferenceObjectWithTag(*v10);
        *(_DWORD *)(v8 + 4) |= 2u;
      }
    }
    else if ( (v9[1] & 1) != 0 )
    {
      PsBoostThreadIoEx(*v9, 1, 0);
      v10[1] &= 0xFFFFFFFE;
    }
    *(_DWORD *)(v8 + 4) += v10[1] & 0xFFFFFFFC;
    v10[1] &= 3u;
    *v10 = 0;
    --*(_DWORD *)(a1 + 32);
    v13 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v13 & 0xFFFFF000) + 0x149C);
    return KeReleaseInStackQueuedSpinLock((int)v18);
  }
  if ( (a3 & 1) != 0 )
  {
    if ( (a2 & 0xFFFFFFFC) != v7 )
      KeBugCheck2(306, a1, *(_DWORD *)(a1 + 8), v7, a2, 0);
    ObfReferenceObjectWithTag(a2 & 0xFFFFFFFC);
    v11 = v10[1] | 2;
  }
  else
  {
    if ( (v9[1] & 1) == 0 )
      goto LABEL_10;
    PsBoostThreadIoEx(*v9, 1, 0);
    v11 = v10[1] & 0xFFFFFFFE;
  }
  v10[1] = v11;
LABEL_10:
  *v10 = a2;
  v12 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v12 & 0xFFFFF000) + 0x1498);
  return KeReleaseInStackQueuedSpinLock((int)v18);
}
