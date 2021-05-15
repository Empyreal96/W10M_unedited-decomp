// CmpWaitOnHiveWriteQueue 
 
int __fastcall CmpWaitOnHiveWriteQueue(int a1, int *a2, char a3)
{
  int v6; // r0
  char v8[16]; // [sp+8h] [bp-28h] BYREF
  int v9; // [sp+18h] [bp-18h]
  int v10; // [sp+1Ch] [bp-14h]

  v6 = KeInitializeEvent((int)v8, 1, 0);
  v10 = a2[1];
  a2[1] = (int)v8;
  if ( (a3 & 0x10) == 0 )
    CmpBoostActiveHiveWriter(v6, a2);
  ExReleaseResourceLite(*(_DWORD *)(a1 + 1872));
  CmpUnlockRegistry();
  CmpTraceHiveFlushStartWaitForActive();
  KeWaitForSingleObject((unsigned int)v8, 0, 0, 0, 0);
  CmpTraceHiveFlushFinishWaitForActive();
  return v9;
}
