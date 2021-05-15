// KiInitializeIdleThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiInitializeIdleThread(int a1, int a2, int a3, int a4)
{
  int v7; // r1
  int v8; // r3
  int *v9; // r0
  int **v10; // r4 OVERLAPPED
  int *v11; // r3
  int v12; // r3
  int result; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r4

  *(_DWORD *)(a1 + 56) = 0;
  KeInitThread((_DWORD *)a1, a2, (int)KiIdleLoop, 0, 0, 0, 0, a3, 0);
  *(_DWORD *)(a1 + 76) &= 0xFFFFBFFF;
  KeStartThread(a1, 0, 0);
  v7 = *(_DWORD *)(a4 + 20);
  *(_BYTE *)(a1 + 132) = 2;
  *(_DWORD *)(a1 + 328) = v7;
  *(_WORD *)(a1 + 344) = *(unsigned __int8 *)(a4 + 1052);
  *(_DWORD *)(a1 + 340) = *(_DWORD *)(a4 + 1048);
  *(_DWORD *)(a1 + 124) = *(_DWORD *)(a4 + 20);
  *(_WORD *)(a1 + 360) = *(_WORD *)(a1 + 344);
  *(_DWORD *)(a1 + 356) = *(_DWORD *)(a1 + 340);
  v8 = *(_DWORD *)(a1 + 76);
  *(_BYTE *)(a1 + 134) = 2;
  *(_DWORD *)(a1 + 76) = v8 | 8;
  *(_DWORD *)(a1 + 364) = *(_DWORD *)(a1 + 124);
  *(_BYTE *)(a1 + 73) = 1;
  *(_DWORD *)(a1 + 856) = KiIdleLoop;
  *(_DWORD *)(a1 + 924) = KiIdleLoop;
  **(_BYTE **)(a4 + 28) = 127;
  *(_BYTE *)(a1 + 123) = 127;
  if ( !*(_DWORD *)(a4 + 20) )
  {
    off_683390 = &dword_68338C;
    dword_68338C = (int)&dword_68338C;
  }
  *(_DWORD *)(a1 + 1004) = a1 + 1004;
  *(_DWORD *)(a1 + 1008) = a1 + 1004;
  *(_DWORD *)(a1 + 1012) = a1 + 1012;
  *(_DWORD *)(a1 + 1016) = a1 + 1012;
  *(_DWORD *)(a1 + 1020) = 0;
  v9 = (int *)(a1 + 932);
  v10 = (int **)off_683390;
  v11 = &dword_68338C;
  *(_QWORD *)v9 = *(_QWORD *)(&v10 - 1);
  if ( *v10 != &dword_68338C )
    sub_69445C();
  *v10 = v9;
  off_683390 = v9;
  v12 = *(_DWORD *)(a4 + 20);
  __dmb(0xBu);
  result = 1 << v12;
  v14 = (unsigned int *)(a3 + 96);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 | result, v14) );
  __dmb(0xBu);
  return result;
}
