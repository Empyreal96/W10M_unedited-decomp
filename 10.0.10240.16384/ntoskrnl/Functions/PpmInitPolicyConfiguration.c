// PpmInitPolicyConfiguration 
 
int PpmInitPolicyConfiguration()
{
  char **v0; // r1
  int v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // lr
  int v5; // r8
  char v6; // r2
  int v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r1

  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v0 = &PpmPolicyConfigTable;
  v1 = dword_61DC74;
  v2 = dword_61DC70;
  v3 = dword_61DBC4;
  v4 = dword_61DBC0[0];
  v5 = 42;
  do
  {
    v6 = *((_BYTE *)v0 + 24);
    v7 = 1 << (v6 - 32);
    v8 = 1 << v6;
    if ( (*((_BYTE *)v0 + 25) & 4) != 0 )
      v0[5] = (char *)((unsigned int)v0[5] >> 1);
    v3 |= v7;
    v2 |= v8;
    v1 |= v7;
    v0 += 7;
    --v5;
    v4 |= v8;
  }
  while ( v5 );
  dword_61DBC0[0] = v4;
  dword_61DBC4 = v3;
  dword_61DC70 = v2;
  dword_61DC74 = v1;
  PpmDefaultProfile = (int)PpmInfoDefaultProfileName;
  dword_61DBB8 = 2;
  unk_61DD38 = -1;
  unk_61DD3C = -1;
  unk_61DBA8 = 0;
  unk_61DBAC = 0;
  unk_61DBB0 = 0;
  unk_61DBB4 = 0;
  PpmEnableProfile((int)&PpmDefaultProfile);
  v9 = KeQueryInterruptTime();
  PpmBeginProfileAccumulation((int)&PpmDefaultProfile, v10, v9, v10);
  qsort(
    (unsigned int)&PpmPolicyConfigTable,
    0x2Au,
    0x1Cu,
    (int (__fastcall *)(unsigned int, _BYTE *))PpmInfoConfigComparer);
  return PpmReleaseLock(&PpmPerfPolicyLock);
}
