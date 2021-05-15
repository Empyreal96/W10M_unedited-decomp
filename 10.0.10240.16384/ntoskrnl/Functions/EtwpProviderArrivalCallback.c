// EtwpProviderArrivalCallback 
 
int __fastcall EtwpProviderArrivalCallback(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r0
  int v7; // r4
  _DWORD *v8; // r6
  int v9; // r5
  unsigned int v10; // r8
  unsigned int v12; // [sp+8h] [bp-148h] BYREF
  int v13; // [sp+Ch] [bp-144h] BYREF
  _DWORD *v14; // [sp+10h] [bp-140h] BYREF
  _DWORD v15[2]; // [sp+18h] [bp-138h] BYREF
  int v16; // [sp+20h] [bp-130h] BYREF
  int v17; // [sp+24h] [bp-12Ch]
  int v18; // [sp+28h] [bp-128h]
  _DWORD _30[75]; // [sp+30h] [bp-120h] BYREF
  int varg_r1; // [sp+15Ch] [bp+Ch]
  int varg_r2; // [sp+160h] [bp+10h]
  int varg_r3; // [sp+164h] [bp+14h]

  _30[74] = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v17 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v15[0] = a1;
  v6 = *(_DWORD *)(a3 + 44);
  if ( !v6 )
    return -1073741503;
  if ( (*(_DWORD *)(a1 + 12) & 0x80) != 0 && (*(_BYTE *)(a3 + 50) & 8) != 0 )
    return -1073741637;
  v8 = _30;
  v14 = _30;
  v12 = 0;
  v9 = 0;
  v13 = 0;
  if ( !(_BYTE)a2 )
  {
    RtlPcToFileHeader(v6, &v12, 0, 0);
    v10 = v12;
    if ( !v12 )
    {
      v7 = -1073741275;
      goto LABEL_30;
    }
LABEL_11:
    v7 = RtlImageNtHeaderEx(1, v10 & 0xFFFFFFFC, (unsigned int)v9, &v16);
    v18 = v7;
    if ( v7 >= 0 )
    {
      if ( (*(_BYTE *)(a3 + 50) & 8) != 0 )
      {
        if ( !v9 )
        {
          v7 = EtwpGetImageSize(v16, &v13);
          v9 = v13;
        }
        if ( v7 >= 0 )
        {
          if ( v17 == 1 && v9 && (v9 + v10 > MmUserProbeAddress || v9 + v10 < v10) )
            *(_BYTE *)MmUserProbeAddress = 0;
          v15[0] = 256;
          v7 = EtwpFindDebugId(v10, v9, &v14, v15);
          v8 = v14;
          if ( v7 >= 0 )
          {
            if ( (EtwpAddProviderToSession(a1, v14, v15[0]), !KdDebuggerNotPresent) && !KdPitchDebugger
              || KdEventLoggingPresent )
            {
              if ( (*(_DWORD *)(a1 + 12) & 0x80000) != 0 )
                EtwpSendDbgId(a1);
            }
          }
        }
      }
      else if ( (*(_BYTE *)(a3 + 50) & 0x20) != 0 )
      {
        v7 = MmGetFileNameForAddress(v16, v15);
        if ( v7 >= 0 )
        {
          EtwpAddWinRtProviderToSession(a1, v15, *(_DWORD *)(a3 + 16) + 12);
          ExFreePoolWithTag(v15[1]);
        }
      }
    }
    goto LABEL_30;
  }
  v7 = MmGetImageBase(v6, &v12, &v13);
  if ( v7 >= 0 )
  {
    v10 = v12;
    v9 = v13;
    goto LABEL_11;
  }
LABEL_30:
  if ( v8 != _30 )
    ExFreePoolWithTag((unsigned int)v8);
  return v7;
}
