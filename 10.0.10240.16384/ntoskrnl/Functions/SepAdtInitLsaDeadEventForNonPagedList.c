// SepAdtInitLsaDeadEventForNonPagedList 
 
BOOL __fastcall SepAdtInitLsaDeadEventForNonPagedList(int a1, int a2, int a3, int a4)
{
  BOOL v5; // r4
  _DWORD v7[6]; // [sp+0h] [bp-18h] BYREF

  v7[0] = a1;
  v7[1] = a2;
  v7[2] = a3;
  v7[3] = a4;
  KeAcquireInStackQueuedSpinLock(dword_6418C0, (unsigned int)v7);
  dword_6418E4 = a1;
  v5 = dword_641880 != (_DWORD)&dword_641880;
  KeReleaseInStackQueuedSpinLock((int)v7);
  return v5;
}
