// PnpEarlyLaunchImageNotificationPreProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpEarlyLaunchImageNotificationPreProcess(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0
  int v7; // r5 OVERLAPPED
  int v8; // r6 OVERLAPPED
  int v9; // r4
  int v10; // r3
  __int16 v11; // [sp+8h] [bp-40h] BYREF
  __int16 *v12; // [sp+10h] [bp-38h]
  int v13; // [sp+14h] [bp-34h]
  int v14; // [sp+18h] [bp-30h]
  int v15; // [sp+1Ch] [bp-2Ch]
  int v16; // [sp+20h] [bp-28h]
  int v17; // [sp+24h] [bp-24h]
  int v18; // [sp+28h] [bp-20h]
  int v19; // [sp+2Ch] [bp-1Ch]

  memmove(a3, a5, 0x40u);
  RtlDuplicateUnicodeString(0, a5 + 8, a3 + 8);
  RtlDuplicateUnicodeString(0, a5 + 16, a3 + 16);
  RtlDuplicateUnicodeString(0, a5 + 32, a3 + 32);
  result = RtlDuplicateUnicodeString(0, a5 + 24, a3 + 24);
  *(_QWORD *)&v7 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    result = EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_EarlyLaunch_LoadNotification_Start);
    if ( result )
    {
      v9 = *(unsigned __int16 *)(a3 + 8);
      v11 = *(_WORD *)(a3 + 8) >> 1;
      v12 = &v11;
      v13 = 0;
      v14 = 2;
      v15 = 0;
      v10 = *(_DWORD *)(a3 + 12);
      v18 = v9;
      v16 = v10;
      v17 = 0;
      v19 = 0;
      result = EtwWrite(v7, v8, (int)KMPnPEvt_EarlyLaunch_LoadNotification_Start, 0);
    }
  }
  return result;
}
