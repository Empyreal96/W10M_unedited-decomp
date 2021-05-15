// KeTryToInsertQueueApc 
 
int __fastcall KeTryToInsertQueueApc(int a1, int a2, int a3)
{
  int v4; // r5
  int result; // r0
  BOOL v9; // r0
  int v10; // r4
  unsigned int v11; // r8
  unsigned int *v12; // r7
  unsigned int v13; // r2

  v4 = *(_DWORD *)(a1 + 8);
  if ( *(_BYTE *)(v4 + 132) != 2
    || *(_DWORD *)(v4 + 328) != *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
  {
    return 0;
  }
  v9 = KeAreInterruptsEnabled();
  v10 = v9 ? KeGetCurrentIrql(v9) : 15;
  v11 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v12 = (unsigned int *)(v4 + 44);
  do
    v13 = __ldrex(v12);
  while ( __strex(1u, v12) );
  __dmb(0xBu);
  if ( v13 )
    return 0;
  if ( (*(_DWORD *)(v4 + 76) & 0x4000) == 0 || *(_BYTE *)(a1 + 46) )
  {
    result = 0;
  }
  else
  {
    *(_BYTE *)(a1 + 46) = 1;
    *(_DWORD *)(a1 + 36) = a2;
    *(_DWORD *)(a1 + 40) = a3;
    KiInsertQueueApc(a1);
    KiSignalThreadForApc(v11 + 1408, a1, v10);
    result = 1;
  }
  __dmb(0xBu);
  *v12 = 0;
  return result;
}
