// BiGetPhysicalDriveName 
 
int __fastcall BiGetPhysicalDriveName(unsigned __int16 *a1, unsigned int *a2)
{
  int v3; // r4
  unsigned int v4; // r5
  _WORD *v5; // r0
  unsigned int v6; // r6
  int v8[3]; // [sp+Ch] [bp-3Ch] BYREF
  char v9[8]; // [sp+18h] [bp-30h] BYREF
  int v10; // [sp+20h] [bp-28h]
  int v11; // [sp+24h] [bp-24h]
  char *v12; // [sp+28h] [bp-20h]
  int v13; // [sp+2Ch] [bp-1Ch]
  int v14; // [sp+30h] [bp-18h]
  int v15; // [sp+34h] [bp-14h]

  v8[0] = 0;
  RtlInitUnicodeString((unsigned int)v9, a1);
  v10 = 24;
  v11 = 0;
  v13 = 576;
  v12 = v9;
  v14 = 0;
  v15 = 0;
  v8[1] = 0;
  v8[2] = 0;
  v3 = ZwOpenFile();
  if ( v3 >= 0 )
  {
    v3 = BiGetVolumeDiskExtentsInformation(0, v8);
    v4 = v8[0];
    if ( v3 >= 0 )
    {
      if ( *(_DWORD *)v8[0] == 1 )
      {
        v5 = (_WORD *)ExAllocatePoolWithTag(1, 62, 1262764866);
        v6 = (unsigned int)v5;
        if ( v5 )
        {
          v3 = RtlStringCbPrintfW(v5, 0x3Eu, (int)L"\\??\\PhysicalDrive%lu", *(_DWORD *)(v4 + 8));
          if ( v3 < 0 )
            ExFreePoolWithTag(v6);
          else
            *a2 = v6;
        }
        else
        {
          v3 = -1073741670;
        }
      }
      else
      {
        v3 = -1073741637;
      }
    }
    if ( v4 )
      ExFreePoolWithTag(v4);
  }
  return v3;
}
