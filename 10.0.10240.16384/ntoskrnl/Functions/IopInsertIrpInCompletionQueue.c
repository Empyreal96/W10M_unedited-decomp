// IopInsertIrpInCompletionQueue 
 
int __fastcall IopInsertIrpInCompletionQueue(_DWORD *a1, int a2, char a3)
{
  __int64 v4; // kr00_8
  int v5; // r10
  int v6; // r8
  _DWORD *v7; // r5
  unsigned int v8; // r0
  int v9; // r6
  int result; // r0
  unsigned int v11; // r2
  unsigned int v12; // r0
  _DWORD *v13; // r1
  unsigned int v14; // [sp+8h] [bp-30h]
  int v15; // [sp+Ch] [bp-2Ch]
  char v16[40]; // [sp+10h] [bp-28h] BYREF

  v4 = *(_QWORD *)*(_DWORD *)(a2 + 108);
  v5 = a3;
  v6 = 0;
  a1[16] = HIDWORD(v4);
  a1[24] = 0;
  KeAcquireInStackQueuedSpinLock(v4 + 40, v16);
  a1[2] |= 0x10000u;
  if ( *(_BYTE *)(v4 + 44) )
  {
    v6 = 1;
  }
  else
  {
    v7 = a1 + 22;
    v15 = KfRaiseIrql(2);
    v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v9 = *(_DWORD *)(v8 + 1412);
    v14 = v8;
    if ( (dword_682604 & 0x1000000) != 0 )
      return sub_520D44();
    if ( v5 && (*(_BYTE *)(v4 + 1) & 2) != 0 )
      v5 = 0;
    do
      v11 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v11 | 0x80, (unsigned __int8 *)v4) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v11 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)v4 & 0x80) != 0 );
      do
        v11 = __ldrex((unsigned __int8 *)v4);
      while ( __strex(v11 | 0x80, (unsigned __int8 *)v4) );
    }
    if ( *(_DWORD *)(v4 + 12) == (_DWORD)v4 + 8
      || *(_DWORD *)(v4 + 24) >= *(_DWORD *)(v4 + 28)
      || *(_DWORD *)(v9 + 152) == (_DWORD)v4 && *(_BYTE *)(v9 + 395) == 15
      || !KiWakeQueueWaiter(v8 + 1408, v4, a1 + 22) )
    {
      ++*(_DWORD *)(v4 + 4);
      v13 = *(_DWORD **)(v4 + 20);
      *v7 = v4 + 16;
      a1[23] = v13;
      if ( *v13 != (_DWORD)v4 + 16 )
        __fastfail(3u);
      *v13 = v7;
      *(_DWORD *)(v4 + 20) = v7;
    }
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v4);
    while ( __strex(v12 & 0xFFFFFF7F, (unsigned int *)v4) );
    KiExitDispatcher(v14 + 1408, 0, 1, v5, v15);
  }
  result = KeReleaseInStackQueuedSpinLock(v16);
  if ( v6 )
    result = IopDropIrp(a1, a1[25]);
  return result;
}
