// EtwpEventWriteTemplateSession 
 
int __fastcall EtwpEventWriteTemplateSession(int a1, int a2, int *a3, int a4)
{
  int v5; // r3
  int v6; // r4
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v11; // [sp+8h] [bp-D8h] BYREF
  int v12[53]; // [sp+Ch] [bp-D4h] BYREF

  v12[1] = a4 + 200;
  v12[2] = 0;
  v12[3] = 16;
  v12[4] = 0;
  v12[6] = 0;
  v12[7] = 4;
  v12[8] = 0;
  v12[10] = 0;
  v5 = *(unsigned __int16 *)(a4 + 92);
  v12[5] = a4 + 12;
  v12[11] = v5;
  v12[12] = 0;
  v12[15] = 2;
  v12[16] = 0;
  v6 = *(_DWORD *)(a4 + 96);
  v12[17] = *(_DWORD *)(a4 + 104);
  v12[18] = 0;
  v7 = *(unsigned __int16 *)(a4 + 100);
  v12[9] = v6;
  v12[19] = v7;
  v12[20] = 0;
  v12[21] = (int)&EtwpNull;
  v12[23] = 2;
  v12[24] = 0;
  v12[13] = (int)&EtwpNull;
  v12[14] = 0;
  v12[22] = 0;
  if ( a3 == ETW_EVENT_START_TRACE || a3 == ETW_EVENT_STOP_TRACE || a3 == ETW_EVENT_SESSION_INFO )
  {
    v12[25] = a4 + 152;
    v12[26] = 0;
    v12[27] = 4;
    v12[28] = 0;
    v12[29] = a4 + 164;
    v12[30] = 0;
    v12[31] = 4;
    v12[32] = 0;
    v12[33] = a4 + 4;
    v12[34] = 0;
    v12[35] = 4;
    v12[36] = 0;
    v8 = *(_DWORD *)(a4 + 172);
    __dmb(0xBu);
    v12[0] = v8;
    v9 = *(_DWORD *)(a4 + 160);
    __dmb(0xBu);
    v11 = v9;
    v12[37] = (int)v12;
    v12[38] = 0;
    v12[39] = 4;
    v12[40] = 0;
    v12[41] = (int)&v11;
    v12[42] = 0;
    v12[43] = 4;
    v12[44] = 0;
    v12[45] = a4 + 136;
    v12[46] = 0;
    v12[47] = 4;
    v12[48] = 0;
  }
  return EtwWrite(a1, a2, (int)a3, 0);
}
