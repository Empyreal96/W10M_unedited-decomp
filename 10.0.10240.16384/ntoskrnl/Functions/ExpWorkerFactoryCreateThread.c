// ExpWorkerFactoryCreateThread 
 
int __fastcall ExpWorkerFactoryCreateThread(_DWORD *a1)
{
  int v2; // r2
  int v3; // r5
  int v5; // [sp+20h] [bp-28h]
  char v6[24]; // [sp+30h] [bp-18h] BYREF

  if ( (a1[22] & 0x800) != 0 )
    v2 = 17;
  else
    v2 = 1;
  v3 = RtlpCreateUserThreadEx(a1[4], 0, v2, 0, a1[6], a1[7]);
  a1[24] = v3;
  if ( v3 >= 0 )
  {
    if ( a1[23] )
      ZwSetInformationThread();
    KeAcquireInStackQueuedSpinLock(a1[1], v6);
    if ( *(_BYTE *)(a1[1] + 21) )
      v3 = 128;
    else
      ++a1[18];
    KeReleaseInStackQueuedSpinLock(v6);
    if ( v3 == 128 )
      return sub_52AFC8();
    ZwResumeThread();
    ObCloseHandle(v5);
  }
  return v3;
}
