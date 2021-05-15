// sub_52E730 
 
void __fastcall sub_52E730(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  int v8; // r6
  char v9; // lr
  int v10; // lr
  unsigned int v11; // r3
  int v12; // lr
  BOOL v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r2
  _DWORD *v16; // lr
  unsigned int v17; // r1
  int v18; // r3
  int v19; // [sp+10h] [bp+10h]
  int v20; // [sp+1Ch] [bp+1Ch]

  *(_BYTE *)(a2 + 9) = v9;
  v10 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)a2 = 0;
  v19 = v10;
  KfRaiseIrql(2);
  v11 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v12 = *(_DWORD *)(v11 + 4);
  v20 = v11;
  if ( (dword_682604 & 0x1000000) != 0 )
  {
    v13 = *(_BYTE *)(v12 + 132) == 2
       && *(_DWORD *)(v12 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    EtwTraceEnqueueWork(v12, a8, v13);
  }
  do
    v14 = __ldrex((unsigned __int8 *)v19);
  while ( __strex(v14 | 0x80, (unsigned __int8 *)v19) );
  __dmb(0xBu);
  if ( v14 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)v19 & 0x80) != 0 );
      do
        v15 = __ldrex((unsigned __int8 *)v19);
      while ( __strex(v15 | 0x80, (unsigned __int8 *)v19) );
      __dmb(0xBu);
    }
    while ( v15 >> 7 );
  }
  if ( *(_DWORD *)(v19 + 12) == v19 + 8
    || *(_DWORD *)(v19 + 24) >= *(_DWORD *)(v19 + 28)
    || *(_DWORD *)(v12 + 152) == v19 && *(_BYTE *)(v12 + 395) == 15
    || !KiWakeQueueWaiter(v20, v19, (int)a8) )
  {
    ++*(_DWORD *)(v19 + 4);
    v16 = *(_DWORD **)(v19 + 20);
    *a8 = v19 + 16;
    a8[1] = v16;
    if ( *v16 != v19 + 16 )
      __fastfail(3u);
    *v16 = a8;
    *(_DWORD *)(v19 + 20) = a8;
  }
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)v19);
  while ( __strex(v17 & 0xFFFFFF7F, (unsigned int *)v19) );
  v18 = *(_DWORD *)(v8 + 4) - 1;
  *(_DWORD *)(v8 + 4) = v18;
  if ( v18 )
    JUMPOUT(0x47D4BA);
  JUMPOUT(0x47D484);
}
