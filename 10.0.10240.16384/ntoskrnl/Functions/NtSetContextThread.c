// NtSetContextThread 
 
int __fastcall NtSetContextThread(int a1, int a2)
{
  int v3; // r6
  int v4; // r5
  int v5; // r4
  int v7[12]; // [sp+8h] [bp-30h] BYREF

  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v4 = ObReferenceObjectByHandle(a1, 16, PsThreadType, v3, v7, 0);
  if ( v4 >= 0 )
  {
    v5 = v7[0];
    if ( (*(_DWORD *)(v7[0] + 76) & 0x400) != 0 )
      v4 = -1073741816;
    else
      v4 = PsSetContextThread(v7[0], a2, v3);
    ObfDereferenceObject(v5);
  }
  v7[2] = (int)v7;
  v7[3] = 0;
  v7[4] = 4;
  v7[5] = 0;
  v7[0] = v4;
  EtwWrite(EtwApiCallsProvRegHandle, MEMORY[0x61A654], (int)KERNEL_AUDIT_API_SETCONTEXTTHREAD, 0);
  return v4;
}
