// DbgkpWerInitializeDeferredLiveDump 
 
int __fastcall DbgkpWerInitializeDeferredLiveDump(int a1)
{
  int v2; // r7
  int v3; // r0
  int v4; // r4
  int v5; // r0
  int v6; // r5
  _DWORD *v7; // r0
  int v8; // r3
  int v10[13]; // [sp+14h] [bp-34h] BYREF

  v10[1] = 24;
  v10[2] = 0;
  v10[4] = 512;
  v2 = *(_DWORD *)(a1 + 88);
  v10[3] = 0;
  v10[5] = 0;
  v10[6] = 0;
  v3 = ZwCreateTimer();
  v4 = v3;
  if ( v3 >= 0 )
  {
    v10[0] = 0;
    v5 = ObReferenceObjectByHandleWithTag(0, 2031619, ExTimerObjectType, 0, 1466393156, v10, 0);
    v4 = v5;
    v6 = v10[0];
    if ( v5 >= 0 )
    {
      ZwClose();
      *(_DWORD *)(v2 + 12) = v6;
      v7 = (_DWORD *)DbgkpWerAllocateNonpagedPool();
      if ( !v7 )
      {
        DbgPrintEx(5, 0, (int)"DBGK: Could not allocate timer.\n", v8);
        return -1073741801;
      }
      *(_DWORD *)(a1 + 84) = v7;
      v7[2] = DbgkpWerDeferredWriteRoutine;
      v7[3] = a1;
      *v7 = 0;
    }
    else
    {
      DbgPrintEx(5, 0, (int)"DBGK: Failed to reference timer, status 0x%X\n", v5);
    }
    if ( v4 < 0 && v6 )
    {
      ObfDereferenceObject(v6);
      *(_DWORD *)(v2 + 12) = 0;
    }
  }
  else
  {
    DbgPrintEx(5, 0, (int)"DBGK: Failed to create timer, status 0x%X\n", v3);
  }
  return v4;
}
