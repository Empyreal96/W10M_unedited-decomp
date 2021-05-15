// FsRtlInitializeSmssEvent 
 
int FsRtlInitializeSmssEvent()
{
  int v0; // r4
  int v2; // [sp+8h] [bp-30h] BYREF
  int v3; // [sp+Ch] [bp-2Ch] BYREF
  __int16 v4[2]; // [sp+10h] [bp-28h] BYREF
  const __int16 *v5; // [sp+14h] [bp-24h]
  int v6[8]; // [sp+18h] [bp-20h] BYREF

  v5 = L"\\Device\\VolumesSafeForWriteAccess";
  v4[0] = 66;
  v4[1] = 68;
  v6[0] = 24;
  v6[1] = 0;
  v6[3] = 592;
  v6[2] = (int)v4;
  v6[4] = 0;
  v6[5] = 0;
  v0 = NtCreateEvent((unsigned int)&v2, 2031619, (int)v6, 0, 0);
  if ( v0 >= 0 )
  {
    v0 = ObReferenceObjectByHandle(v2, 0x100000, 0, 0, (int)&v3, 0);
    NtClose();
    if ( v0 >= 0 )
    {
      dword_631ED8 = (int)FsRtlWaitForSmssEvent;
      dword_631EDC = v3;
      SmssEventWorkItem = 0;
      ExQueueWorkItem(&SmssEventWorkItem, 1);
      v0 = 0;
    }
  }
  return v0;
}
