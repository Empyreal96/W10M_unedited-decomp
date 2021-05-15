// NtRemoveProcessDebug 
 
int __fastcall NtRemoveProcessDebug(int a1, int a2)
{
  int v3; // r6
  int v4; // r4
  int v5; // r3
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  int *v10[8]; // [sp+10h] [bp-20h] BYREF

  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v4 = ObReferenceObjectByHandleWithTag(a1, 2048, PsProcessType, v3, 1332175428, (int *)v10, 0);
  if ( v4 >= 0 )
  {
    v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v6 = v10[0];
    if ( PspCheckForInvalidAccessByProtection(v3, *(_BYTE *)(v5 + 734), *((_BYTE *)v10[0] + 734)) )
    {
      v4 = -1073740014;
    }
    else
    {
      v4 = ObReferenceObjectByHandle(a2, 2, DbgkDebugObjectType, v3, (int)v10, 0);
      if ( v4 >= 0 )
      {
        v4 = DbgkClearProcessDebugObject((int)v6, v10[0], v7, v8);
        ObfDereferenceObject((int)v10[0]);
      }
    }
    ObfDereferenceObjectWithTag((int)v6);
  }
  return v4;
}
