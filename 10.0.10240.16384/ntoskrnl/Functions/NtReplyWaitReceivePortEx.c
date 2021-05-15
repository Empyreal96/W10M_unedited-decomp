// NtReplyWaitReceivePortEx 
 
int __fastcall NtReplyWaitReceivePortEx(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v7; // r5
  int v8; // r0
  int v9; // r4
  int v10; // r5
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  char v15; // [sp+8h] [bp-50h]
  int v17; // [sp+10h] [bp-48h] BYREF
  _DWORD v18[3]; // [sp+18h] [bp-40h] BYREF
  int v19; // [sp+24h] [bp-34h]
  int v20; // [sp+28h] [bp-30h]
  int v21; // [sp+2Ch] [bp-2Ch]
  int v22; // [sp+30h] [bp-28h]
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  unsigned int varg_r2; // [sp+68h] [bp+10h]
  unsigned int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 0x134);
  v15 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v15 )
  {
    if ( (a4 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a4 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a4 = *(_BYTE *)a4;
    *(_BYTE *)(a4 + 16) = *(_BYTE *)(a4 + 16);
  }
  v8 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v15, &v17);
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = v17;
    v18[0] = v17;
    v22 = 0;
    if ( !a3 )
      goto LABEL_15;
    if ( (*(_DWORD *)(v17 + 244) & 0x2000) != 0 )
    {
      v22 = 4;
      v20 = 0;
      v19 = 0;
      v21 = 0;
      v11 = AlpcpReplyLegacySynchronousRequest((int)v18, a3, v15, 0);
    }
    else
    {
      v22 = 65541;
      v20 = 0;
      v19 = 0;
      v21 = 0;
      v11 = AlpcpSendMessage(v18, a3);
    }
    v9 = v11;
    if ( v11 < 0 )
    {
      v8 = ObfDereferenceObject(v10);
      if ( v9 == -1073740029 )
        v9 = -1073741769;
    }
    else
    {
LABEL_15:
      v9 = AlpcpReceiveLegacyMessage(v18, a4, a5, a2);
      AlpcpCompleteDeferSignalRequest((int)v18);
      v8 = ObfDereferenceObject(v10);
    }
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v9;
}
