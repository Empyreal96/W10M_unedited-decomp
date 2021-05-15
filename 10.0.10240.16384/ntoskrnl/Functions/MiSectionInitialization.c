// MiSectionInitialization 
 
int MiSectionInitialization()
{
  _BYTE *v0; // r0
  _DWORD *v1; // r4
  _DWORD *v3; // r0
  int v4[2]; // [sp+18h] [bp-A0h] BYREF
  __int16 v5[2]; // [sp+20h] [bp-98h] BYREF
  const __int16 *v6; // [sp+24h] [bp-94h]
  int v7; // [sp+28h] [bp-90h] BYREF
  int v8[6]; // [sp+30h] [bp-88h] BYREF
  int v9[22]; // [sp+48h] [bp-70h] BYREF

  v4[0] = 1048590;
  v4[1] = (int)L"Section";
  v5[0] = 44;
  v5[1] = 46;
  v6 = L"\\Device\\PhysicalMemory";
  dword_6348E4 = -1;
  dword_632E0C = 0;
  memset(v9, 0, sizeof(v9));
  LOWORD(v9[0]) = 88;
  v9[2] = 256;
  v9[9] = 1;
  v9[10] = 40;
  v9[7] = 983071;
  v9[13] = (int)MiSectionOpen;
  v9[14] = (int)MiSectionClose;
  v9[15] = (int)MiSectionDelete;
  v9[3] = 131077;
  v9[4] = 131074;
  v9[5] = 131080;
  v9[6] = 983071;
  BYTE2(v9[0]) |= 4u;
  v9[1] = 128;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_8;
  if ( PsCreateSystemThread((int)v4, 0x1FFFFF, 0) < 0 )
    goto LABEL_8;
  ObCloseHandle(v4[0]);
  v0 = (_BYTE *)ExAllocatePoolWithTag(1, 48, 1733520717);
  v1 = v0;
  if ( !v0 )
    goto LABEL_8;
  memset(v0, 0, 48);
  memset(dword_632E68, 0, 80);
  memset(dword_632E24, 0, sizeof(dword_632E24));
  v1[7] = 0;
  dword_632E24[0] = (int)dword_632E68;
  dword_632E68[0] = (int)v1;
  dword_632E74 = 1;
  dword_632E84 |= 0x400u;
  *v1 = dword_632E68;
  v8[0] = 24;
  v8[1] = 0;
  v8[3] = 65552;
  v8[2] = (int)v5;
  v8[4] = 0;
  v8[5] = 0;
  if ( ObCreateObject(0, (_DWORD *)MmSectionObjectType, (int)v8, 0, 0, 40, 40, 0, v4) < 0 )
    return sub_969EA0();
  v3 = (_DWORD *)v4[0];
  *(_DWORD *)(v4[0] + 20) = dword_632E68;
  v3[6] = -1;
  v3[7] = 0;
  v3[8] = 0;
  v3[9] = v3[9] & 0xFFFFF000 | 0x40;
  if ( ObInsertObject((int)v3, 0, 4, 0, 0, (int)&v7) < 0 )
LABEL_8:
    JUMPOUT(0x969EA8);
  ObCloseHandle(v7);
  return 1;
}
