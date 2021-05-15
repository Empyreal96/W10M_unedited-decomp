// PnpEarlyLaunchImageNotificationPostProcess 
 
unsigned int __fastcall PnpEarlyLaunchImageNotificationPostProcess(int a1, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  __int64 v5; // r8
  unsigned int v8; // r5
  __int16 v10; // [sp+8h] [bp-48h] BYREF
  __int16 *v11; // [sp+10h] [bp-40h]
  int v12; // [sp+14h] [bp-3Ch]
  int v13; // [sp+18h] [bp-38h]
  int v14; // [sp+1Ch] [bp-34h]
  int v15; // [sp+20h] [bp-30h]
  int v16; // [sp+24h] [bp-2Ch]
  unsigned int v17; // [sp+28h] [bp-28h]
  int v18; // [sp+2Ch] [bp-24h]

  v5 = PnpEtwHandle;
  if ( PnpEtwHandle
    && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_EarlyLaunch_LoadNotification_Stop) )
  {
    v11 = &v10;
    v12 = 0;
    v13 = 2;
    v14 = 0;
    v8 = *(unsigned __int16 *)(a5 + 8);
    v15 = *(_DWORD *)(a5 + 12);
    v16 = 0;
    v17 = v8;
    v18 = 0;
    v10 = v8 >> 1;
    EtwWrite(v5, SHIDWORD(v5), (int)KMPnPEvt_EarlyLaunch_LoadNotification_Stop, 0);
  }
  if ( PnpClassificationRank[*a3] > (unsigned int)PnpClassificationRank[*a4] )
    *a4 = *a3;
  RtlFreeAnsiString(a3 + 2);
  RtlFreeAnsiString(a3 + 8);
  return RtlFreeAnsiString(a3 + 6);
}
