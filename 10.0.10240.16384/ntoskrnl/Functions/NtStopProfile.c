// NtStopProfile 
 
int __fastcall NtStopProfile(int a1, int a2, int a3, int a4)
{
  char v4; // r3
  int v5; // r4
  int v6; // r7
  __int64 v7; // r4
  unsigned int v8; // r6
  int v9; // r2
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v11[0] = a4;
  v4 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v5 = ObReferenceObjectByHandle(a1, 1, ExProfileObjectType, v4, (int)v11, 0);
  if ( v5 >= 0 )
  {
    KeWaitForSingleObject((unsigned int)&ExpProfileStateMutex, 0, 0, 0, 0);
    v6 = v11[0];
    if ( *(_DWORD *)(v11[0] + 28) )
    {
      KeStopProfile(*(_DWORD *)(v11[0] + 24));
      v7 = *(_QWORD *)(v6 + 28);
      v8 = *(_DWORD *)(v6 + 24);
      --ExpCurrentProfileUsage;
      *(_DWORD *)(v6 + 28) = 0;
      KeReleaseMutex((int)&ExpProfileStateMutex);
      MmUnmapLockedPages(v7, SHIDWORD(v7), v9);
      MmUnlockPages(SHIDWORD(v7));
      ExFreePoolWithTag(v8);
      v5 = 0;
    }
    else
    {
      KeReleaseMutex((int)&ExpProfileStateMutex);
      v5 = -1073741641;
    }
    ObfDereferenceObject(v6);
  }
  return v5;
}
