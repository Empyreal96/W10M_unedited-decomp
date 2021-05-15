// IoRegisterLastChanceShutdownNotification 
 
int __fastcall IoRegisterLastChanceShutdownNotification(int a1)
{
  int *v2; // r5
  __int64 v3; // kr00_8
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int *v8; // r2
  int *v9; // r2
  __int16 v11; // [sp+8h] [bp-48h] BYREF
  int v12; // [sp+Ch] [bp-44h] BYREF
  int v13[16]; // [sp+10h] [bp-40h] BYREF

  v2 = (int *)ExAllocatePoolWithTag(512, 12, 1750298441);
  if ( !v2 )
    return -1073741670;
  ObfReferenceObject(a1);
  v2[2] = a1;
  IopInterlockedInsertHeadList(&IopNotifyLastChanceShutdownQueueHead, v2);
  *(_DWORD *)(a1 + 28) |= 0x800u;
  v12 = 0;
  v3 = EtwApiCallsProvRegHandle;
  if ( EtwApiCallsProvRegHandle )
  {
    v11 = 0;
    v4 = *(_DWORD *)(a1 + 8);
    v5 = 0;
    if ( v4 )
    {
      v6 = *(_DWORD *)(v4 + 32);
      if ( v6 )
      {
        v7 = *(unsigned __int16 *)(v4 + 28);
        v13[0] = v6;
        v13[1] = 0;
        v13[2] = v7;
        v13[3] = 0;
        v5 = 1;
      }
    }
    v8 = &v13[4 * v5];
    *v8 = (int)&v11;
    v8[2] = 2;
    v8[1] = 0;
    v8[3] = 0;
    v9 = &v13[4 * v5 + 4];
    *(_QWORD *)v9 = (unsigned int)&v12;
    *((_QWORD *)v9 + 1) = 4i64;
    EtwWrite(v3, SHIDWORD(v3), (int)KERNEL_AUDIT_API_IOREGISTERLASTCHANCESHUTDOWNNOTIFICATION, 0);
  }
  return 0;
}
