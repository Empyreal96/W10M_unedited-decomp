// sub_817410 
 
int __fastcall sub_817410(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v11; // r4
  int v12; // r1
  int v13; // r2
  int v14; // r0
  int v15; // r0
  _DWORD v17[12]; // [sp-30h] [bp-30h] BYREF

  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  KeQueryActiveProcessorAffinity(&a9);
  v12 = *(_DWORD *)(v11 + 8);
  v13 = a11 & ~v12;
  if ( v13 )
  {
    *(_WORD *)(v11 + 2) = 1;
    *(_WORD *)v11 = 1;
    *(_DWORD *)(v11 + 4) = 0;
    *(_DWORD *)(v11 + 8) = v12 | v13;
    if ( v13 )
      PopExecuteOnTargetProcessors((int)v17, (int)PpmCheckReset, 0, 0);
    v15 = PpmParkRegisterParking();
    PpmCheckReInit(v15);
    v14 = PpmCheckApplyParkConstraints();
  }
  else
  {
    v14 = PpmReleaseLock(&PpmPerfPolicyLock);
  }
  return ((int (__fastcall *)(int))v17[11])(v14);
}
