// IoGetContainerInformation 
 
int __fastcall IoGetContainerInformation(int a1, int a2, int a3, unsigned int a4)
{
  int v5; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v5 = a2;
  if ( a1 )
    return -1073741585;
  if ( a4 < 0xC )
    return -1073741582;
  if ( !a2 )
  {
    v7 = PsGetCurrentProcessSessionId();
    v5 = MmGetSessionObjectById(v7, v8, v9, v10);
    if ( !v5 )
      return -1073741584;
  }
  *(_DWORD *)(a3 + 4) = MmGetIoSessionState(v5, v13);
  v11 = MEMORY[0xFFFF92D8];
  __dmb(0xBu);
  v12 = v13[0];
  *(_BYTE *)(a3 + 8) = v13[0] == v11;
  *(_DWORD *)a3 = v12;
  return 0;
}
