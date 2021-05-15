// MiGetPageForHeader 
 
int __fastcall MiGetPageForHeader(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r6
  int v6; // r0
  int v7; // r5
  unsigned int v9; // r7
  int v10; // r0
  unsigned __int8 *v11; // r1
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r0
  int v16; // r3
  _DWORD v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  if ( !MiObtainFaultCharges(MiSystemPartition, 1, 1) )
    JUMPOUT(0x53AA72);
  v5 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  MI_INITIALIZE_COLOR_BASE(v5[29] + 492, a1, v17);
  v6 = MiGetSystemPage((int)v17);
  v7 = v6;
  if ( !v6 )
    return sub_53AA68();
  v9 = (int)((unsigned __int64)(715827883i64 * (v6 - MmPfnDatabase)) >> 32) >> 2;
  v10 = KfRaiseIrql(2);
  v11 = (unsigned __int8 *)(v7 + 15);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v12 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v16 = *(_DWORD *)(v7 + 12);
      __dmb(0xBu);
    }
    while ( v16 < 0 );
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
  }
  *(_WORD *)(v7 + 16) = 1;
  __dmb(0xBu);
  v13 = (unsigned int *)(v7 + 12);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0x7FFFFFFF, v13) );
  KfLowerIrql(v10);
  *(_DWORD *)(v7 + 8) = 0;
  v15 = MiGetEffectivePagePriorityThread(v5);
  MiInitializePageForHeader(v7, v15);
  return v9 + (v9 >> 31);
}
