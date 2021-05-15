// VerifierIoSetCompletionRoutineEx 
 
int __fastcall VerifierIoSetCompletionRoutineEx(int a1, int a2, int a3, int a4, unsigned __int8 a5, unsigned __int8 a6, unsigned __int8 a7)
{
  int v11; // r6
  _DWORD *v12; // r0
  int v13; // r5
  _DWORD *v14; // r7
  int v15; // r2
  int v16; // r3
  int v17; // r4
  BOOL v18; // r1
  int v20; // [sp+Ch] [bp-14h]

  v20 = a4;
  if ( VfFaultsInjectResourceFailure(0) )
    return -1073741670;
  v11 = pXdvIoSetCompletionRoutineEx(a1, a2, a3, a4, a5, a6, a7, v20);
  if ( v11 >= 0 )
  {
    v12 = (_DWORD *)VeAllocatePoolWithTagPriority(640, 0x10u, 1934976598, 32);
    if ( v12 )
    {
      v13 = *(_DWORD *)(a2 + 96);
      v14 = *(_DWORD **)(v13 - 4);
      v15 = v14[1];
      v16 = v14[2];
      v17 = v14[3];
      *v12 = *v14;
      v12[1] = v15;
      v12[2] = v16;
      v12[3] = v17;
      *(_DWORD *)(v13 - 4) = v12;
      v18 = KeGetCurrentIrql(v12) != 2;
      VfPoolDelayFreeIfPossible((int)v14, v18);
    }
  }
  return v11;
}
