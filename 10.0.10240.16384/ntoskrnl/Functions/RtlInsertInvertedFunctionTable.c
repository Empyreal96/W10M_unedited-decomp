// RtlInsertInvertedFunctionTable 
 
int __fastcall RtlInsertInvertedFunctionTable(unsigned int a1, int a2, int a3, int a4)
{
  int v6; // r0
  unsigned int v7; // r6
  unsigned int v9; // r4
  unsigned int v10; // r4
  int *v11; // r2
  int *v12; // r2
  int v13; // r3
  unsigned int v14; // r1
  int v15; // [sp+0h] [bp-20h] BYREF
  int v16; // [sp+4h] [bp-1Ch] BYREF
  int v17[6]; // [sp+8h] [bp-18h] BYREF

  v15 = a2;
  v16 = a3;
  v17[0] = a4;
  RtlCaptureImageExceptionValues(a1, &v16, v17);
  v6 = MmLockLoadedModuleListExclusive(&v15);
  v7 = PsInvertedFunctionTable[0];
  if ( PsInvertedFunctionTable[0] == unk_616484 )
    return sub_519178(v6);
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&dword_616488);
  while ( __strex(v9 + 1, (unsigned int *)&dword_616488) );
  __dmb(0xBu);
  v10 = 1;
  if ( v7 != 1 )
  {
    if ( v7 > 1 )
    {
      v11 = dword_616490;
      do
      {
        if ( a1 < v11[5] )
          break;
        ++v10;
        v11 += 4;
      }
      while ( v10 < v7 );
    }
    if ( v10 != v7 )
      memmove((int)&unk_6164A0 + 16 * v10, (int)&dword_616490[4 * v10], 16 * (v7 - v10));
  }
  v12 = &PsInvertedFunctionTable[4 * v10];
  v12[4] = v16;
  v12[5] = a1;
  v13 = v17[0];
  v12[6] = a2;
  v12[7] = v13;
  ++PsInvertedFunctionTable[0];
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&dword_616488);
  while ( __strex(v14 + 1, (unsigned int *)&dword_616488) );
  __dmb(0xBu);
  return MmUnlockLoadedModuleListExclusive((unsigned __int8)v15);
}
