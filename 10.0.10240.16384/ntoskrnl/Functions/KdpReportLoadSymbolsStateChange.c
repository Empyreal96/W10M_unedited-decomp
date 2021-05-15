// KdpReportLoadSymbolsStateChange 
 
int __fastcall KdpReportLoadSymbolsStateChange(unsigned __int16 *a1, int *a2, char a3, int a4)
{
  int v8; // r0
  int v9; // r3
  int v10; // r4
  int v11; // r3
  int result; // r0
  int v13; // r0
  __int16 v14; // [sp+10h] [bp-120h] BYREF
  char *v15; // [sp+14h] [bp-11Ch]
  __int16 v16; // [sp+18h] [bp-118h] BYREF
  _BYTE *v17; // [sp+1Ch] [bp-114h]
  char v18[32]; // [sp+20h] [bp-110h] BYREF
  int v19; // [sp+40h] [bp-F0h] BYREF
  __int64 v20; // [sp+48h] [bp-E8h]
  int v21; // [sp+50h] [bp-E0h]
  int v22; // [sp+54h] [bp-DCh]
  int v23; // [sp+58h] [bp-D8h]
  int v24; // [sp+5Ch] [bp-D4h]
  char v25; // [sp+60h] [bp-D0h]
  int v26; // [sp+E0h] [bp-50h]

  do
  {
    v8 = KdpSetCommonState(12337, a4, (int)v18);
    v9 = *a2;
    v10 = *(_DWORD *)(a4 + 68);
    v25 = a3;
    v20 = v9;
    v11 = a2[1];
    v26 = v10;
    v21 = v11;
    v22 = 0;
    v23 = a2[2];
    v24 = a2[3];
    if ( !a1 )
      return sub_903B90(v8);
    v13 = KdpCopyMemoryChunks(*((_DWORD *)a1 + 1), 0, (int)KdpPathBuffer, *a1, 0, 4, &v19);
    v17 = KdpPathBuffer;
    v16 = ++v19;
    KdpPathBuffer[(unsigned __int16)v19 - 1] = 0;
    v14 = 240;
    v15 = v18;
    result = KdpSendWaitContinue(v13, &v14, &v16, a4);
  }
  while ( result == 2 );
  return (unsigned __int8)result;
}
