// RtlRemoveInvertedFunctionTable 
 
int __fastcall RtlRemoveInvertedFunctionTable(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  int v6; // r6
  int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  MmLockLoadedModuleListExclusive(v11);
  v5 = 1;
  v6 = PsInvertedFunctionTable[0];
  if ( PsInvertedFunctionTable[0] > 1u )
  {
    v7 = dword_616490;
    do
    {
      if ( a1 == v7[5] )
        break;
      ++v5;
      v7 += 4;
    }
    while ( v5 < PsInvertedFunctionTable[0] );
  }
  if ( v5 != PsInvertedFunctionTable[0] )
  {
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)&dword_616488);
    while ( __strex(v8 + 1, (unsigned int *)&dword_616488) );
    __dmb(0xBu);
    if ( v6 != 2 )
      memmove((int)&dword_616490[4 * v5], (int)&unk_6164A0 + 16 * v5, 16 * (v6 - v5 - 1));
    --PsInvertedFunctionTable[0];
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&dword_616488);
    while ( __strex(v9 + 1, (unsigned int *)&dword_616488) );
    __dmb(0xBu);
  }
  return MmUnlockLoadedModuleListExclusive(LOBYTE(v11[0]));
}
