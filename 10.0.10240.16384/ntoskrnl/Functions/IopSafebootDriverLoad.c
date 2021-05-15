// IopSafebootDriverLoad 
 
int __fastcall IopSafebootDriverLoad(unsigned __int16 *a1)
{
  int v2; // r5
  __int16 *v3; // r1
  unsigned __int16 v4; // r2
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v12; // [sp+8h] [bp-20h] BYREF
  int v13; // [sp+Ch] [bp-1Ch] BYREF
  unsigned __int16 v14[2]; // [sp+10h] [bp-18h] BYREF
  int v15; // [sp+14h] [bp-14h]
  unsigned __int16 v16[8]; // [sp+18h] [bp-10h] BYREF

  switch ( InitSafeBootMode )
  {
    case 1:
      v3 = L"MINIMAL";
      break;
    case 2:
      v3 = L"NETWORK";
      break;
    case 3:
      return 1;
    default:
      return 0;
  }
  RtlInitUnicodeString((unsigned int)v16, (unsigned __int16 *)v3);
  v4 = *a1;
  v14[0] = 0;
  v5 = (unsigned __int16)(v16[0] + v4 + 8);
  v14[1] = v16[0] + v4 + 8;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v7 = 40;
    else
      v7 = 32;
    v6 = ExAllocatePoolWithTagPriority(1, v5, 538996553, v7);
  }
  else
  {
    v6 = ExAllocatePoolWithTag(1, v5, 538996553);
  }
  v15 = v6;
  if ( !v6 )
    return 0;
  RtlCopyUnicodeString(v14, v16);
  if ( RtlAppendUnicodeToString(v14, (int)L"\\", v8, v9) < 0 )
  {
    ExFreePoolWithTag(v15);
    return 0;
  }
  if ( RtlAppendUnicodeStringToString(v14, a1) >= 0 )
  {
    v2 = 0;
    if ( IopOpenRegistryKey((int)&v12, 0, (int)&CmRegistryMachineSystemCurrentControlSetControlSafeBoot, 983103, 0) >= 0 )
    {
      v10 = IopOpenRegistryKey((int)&v13, v12, (int)v14, 983103, 0);
      ObCloseHandle(v12);
      if ( v10 >= 0 )
      {
        ObCloseHandle(v13);
        v2 = 1;
      }
    }
  }
  else
  {
    v2 = 0;
  }
  ExFreePoolWithTag(v15);
  return v2;
}
