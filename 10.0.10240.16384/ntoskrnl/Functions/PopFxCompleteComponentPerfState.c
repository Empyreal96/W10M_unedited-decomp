// PopFxCompleteComponentPerfState 
 
int __fastcall PopFxCompleteComponentPerfState(int a1, int a2, int a3, int a4)
{
  unsigned int *v8; // r7
  unsigned int v9; // r5
  signed int v10; // r5
  unsigned int v11; // r1
  int v12; // lr
  int v13; // r4
  int v14; // r2
  unsigned int v15; // r5
  unsigned int v16; // r2
  int v18; // [sp+0h] [bp-20h]

  v8 = (unsigned int *)(a3 + 24);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 - 1;
  }
  while ( __strex(v10, v8) );
  __dmb(0xBu);
  v18 = *(_DWORD *)(a3 + 52);
  __dmb(0xBu);
  v11 = 0;
  if ( *(_DWORD *)(a3 + 32) )
  {
    v12 = 0;
    do
    {
      ++v11;
      v13 = *(_DWORD *)(a3 + 88) + 32 * *(_DWORD *)(*(_DWORD *)(a3 + 28) + v12);
      *(_DWORD *)(v13 + 16) = *(_DWORD *)(a3 + 40);
      *(_DWORD *)(v13 + 20) = *(_DWORD *)(a3 + 44);
      *(_BYTE *)(v13 + 24) = 0;
      v14 = *(_DWORD *)(a3 + 28) + v12;
      v12 += 16;
      *(_DWORD *)(v13 + 8) = *(_DWORD *)(v14 + 8);
      *(_DWORD *)(v13 + 12) = *(_DWORD *)(v14 + 12);
    }
    while ( v11 < *(_DWORD *)(a3 + 32) );
  }
  PopDiagTraceFxPerfRequestProgress(a3, v10 & 7);
  if ( v10 >= 0 )
  {
    __dmb(0xBu);
    do
    {
      v15 = __ldrex(v8);
      v10 = v15 - 1;
    }
    while ( __strex(v10, v8) );
    __dmb(0xBu);
  }
  (*(void (__fastcall **)(_DWORD, int, int, int))(a3 + 20))(*(_DWORD *)(a1 + 88), a2, a4, v18);
  if ( v10 < 0 )
  {
    __dmb(0xBu);
    do
      v16 = __ldrex(v8);
    while ( __strex(v16 - 1, v8) );
    __dmb(0xBu);
    KeSetEvent(a3 + 4, 0, 0);
  }
  return PopDiagTraceFxPerfRequestComplete(a3, a4);
}
