// PopInitSIdle 
 
int __fastcall PopInitSIdle(int a1, int a2)
{
  int result; // r0
  int v3; // r10
  __int64 v4; // kr00_8
  int v5; // r2
  int v6; // r3
  int v7; // [sp+8h] [bp-D8h] BYREF
  int v8; // [sp+Ch] [bp-D4h] BYREF
  int v9; // [sp+10h] [bp-D0h] BYREF
  int v10; // [sp+14h] [bp-CCh] BYREF
  int v11; // [sp+18h] [bp-C8h] BYREF
  int v12[6]; // [sp+1Ch] [bp-C4h] BYREF
  int v13; // [sp+34h] [bp-ACh] BYREF
  int v14; // [sp+38h] [bp-A8h]
  int v15; // [sp+3Ch] [bp-A4h]
  int v16; // [sp+40h] [bp-A0h]
  int v17[32]; // [sp+60h] [bp-80h] BYREF

  v13 = 0;
  v14 = 1;
  v15 = *(_DWORD *)(PopPolicy + 56);
  v16 = 2;
  v12[4] = -1;
  if ( (PopFullWake & 3) == 0 && dword_61EC20 )
    return sub_7F1DDC(a1, a2, dword_61EC20);
  PopFilterCapabilities((int)&PopCapabilities, v17, dword_61EC20, PopFullWake);
  if ( *(_DWORD *)(PopPolicy + 60) )
    JUMPOUT(0x7F1E12);
  if ( *(_DWORD *)(PopPolicy + 88) )
    JUMPOUT(0x7F1E10);
  if ( RtlCompareMemory((unsigned __int8 *)&dword_61E814, (int)&v13, 12) == 12
    && dword_61E820 == 2
    && (result = dword_61E80C, dword_61E80C == -1) )
  {
    v3 = 0;
  }
  else
  {
    if ( (PoDebug & 0x40000000) != 0 )
      DbgPrint("PoSIdle: new idle params set\n");
    v3 = 1;
    PopResetIdleTime(4);
    byte_61E828 = 1;
    dword_61E814 = v13;
    dword_61E818 = v14;
    *(_DWORD *)algn_61E81C = v15;
    dword_61E820 = 2;
    dword_61E80C = -1;
    result = -1;
    if ( dword_60E1E8 )
      v5 = dword_61E824 | 1;
    else
      v5 = dword_61E824 & 0xFFFFFFFE;
    dword_61E824 = v5;
    if ( !byte_61EA54 )
    {
      if ( dword_60E1F8 )
        v6 = v5 | 2;
      else
        v6 = v5 & 0xFFFFFFFD;
      dword_61E824 = v6;
    }
  }
  v7 = 2;
  v8 = -1;
  v9 = 5;
  v10 = dword_61E818;
  v12[0] = dword_61E814;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SYSTEM_IDLE_TIMEOUT_INITIALIZED);
    if ( result )
    {
      v17[0] = (int)&v11;
      v17[1] = 0;
      v17[2] = 4;
      v17[3] = 0;
      v17[4] = (int)&v9;
      v17[5] = 0;
      v17[6] = 4;
      v17[7] = 0;
      v17[8] = (int)v12;
      v17[9] = 0;
      v17[10] = 4;
      v17[11] = 0;
      v17[12] = (int)&v7;
      v17[13] = 0;
      v17[14] = 4;
      v17[15] = 0;
      v17[16] = (int)&v8;
      v17[17] = 0;
      v17[18] = 4;
      v17[19] = 0;
      v17[20] = (int)&v10;
      v17[21] = 0;
      v17[22] = 4;
      v17[23] = 0;
      v11 = v3;
      result = EtwWrite(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_SYSTEM_IDLE_TIMEOUT_INITIALIZED, 0);
    }
  }
  return result;
}
