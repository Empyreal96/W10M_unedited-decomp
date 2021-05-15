// EtwpCalculateUpdateNotification 
 
int __fastcall EtwpCalculateUpdateNotification(int a1, int a2, int a3, int a4, char a5, int a6, int *a7)
{
  int v10; // r2
  int v11; // r3
  _DWORD *v13; // r0
  int v14; // r3
  int v15; // r4
  int v16; // r5
  int v17; // r0
  int v18; // [sp+0h] [bp-A0h]
  char v19; // [sp+4h] [bp-9Ch]
  int v20[38]; // [sp+8h] [bp-98h] BYREF

  v19 = *(_BYTE *)(a1 + 50);
  if ( (v19 & 8) == 0 )
  {
    if ( a5 )
    {
      v11 = *(unsigned __int8 *)(a1 + 52);
      v10 = *(unsigned __int8 *)(a1 + 51);
    }
    else
    {
      v10 = *(unsigned __int8 *)(a1 + 52);
      v11 = *(unsigned __int8 *)(a1 + 51);
    }
    if ( (a3 & a2) == 0 && (v11 & a2) == 0 )
      return 0;
    if ( v10 || a4 != v11 || a5 == 2 )
    {
      memset(v20, 0, 120);
      v18 = *a7;
      memmove((int)v20, *a7, 0x48u);
      v13 = *(_DWORD **)(a1 + 16);
      v20[2] = 1;
      v14 = v13[4];
      v15 = v13[5];
      v16 = v13[6];
      v20[10] = v13[3];
      v20[11] = v14;
      v20[12] = v15;
      v20[13] = v16;
      v20[1] = 120;
      v17 = EtwpGetSchematizedFilterSize((int)v13);
      if ( v17 )
        v20[1] = v17 + 136;
      EtwpComputeRegEntryEnableInfo(a1, (int)&v20[18]);
      if ( (v19 & 8) != 0 )
      {
        v20[27] = 0;
        v20[28] = 0;
        v20[26] = 0;
      }
      if ( !v18 )
        goto LABEL_19;
      if ( *(_DWORD *)(v18 + 4) != v20[1] || RtlCompareMemory((unsigned __int8 *)v18, (int)v20, 120) != 120 )
        *a7 = 0;
      if ( !*a7 )
      {
LABEL_19:
        if ( EtwpBuildNotificationPacket(*(_DWORD *)(a1 + 16), (int)v20, *(unsigned __int8 *)(a1 + 51), a7) < 0 )
          return 0;
      }
      return 1;
    }
LABEL_8:
    *a7 = 0;
    return 1;
  }
  if ( *(_BYTE *)(a1 + 51) )
    goto LABEL_8;
  return sub_808638();
}
