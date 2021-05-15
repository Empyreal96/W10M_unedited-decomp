// BiUnloadHiveByName 
 
int __fastcall BiUnloadHiveByName(int a1, int a2, int a3)
{
  unsigned int v4; // r4
  int v6; // r0
  unsigned __int16 *v7; // r5
  int v8; // r4
  int v9; // r2
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  char v15[8]; // [sp+8h] [bp-38h] BYREF
  char v16[8]; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+18h] [bp-28h]
  int v18; // [sp+1Ch] [bp-24h]
  char *v19; // [sp+20h] [bp-20h]
  int v20; // [sp+24h] [bp-1Ch]
  int v21; // [sp+28h] [bp-18h]
  int v22; // [sp+2Ch] [bp-14h]

  v4 = a2 + 38;
  v6 = ExAllocatePoolWithTag(1, a2 + 38, 1262764866);
  v7 = (unsigned __int16 *)v6;
  if ( !v6 )
    return -1073741670;
  swprintf_s(v6, v4 >> 1, (int)L"%s\\%s", L"\\Registry\\Machine", a1);
  RtlInitUnicodeString((unsigned int)v15, v7);
  v17 = 24;
  v18 = 0;
  v20 = 576;
  v19 = v15;
  v21 = 0;
  v22 = 0;
  v8 = BiAcquirePrivilege(18, (int)v16, v9, 0);
  if ( v8 >= 0 )
  {
    if ( a3 )
      v10 = ZwUnloadKey2();
    else
      v10 = ZwUnloadKey();
    v8 = v10;
    BiReleasePrivilege((int)v16, v11, v12, v13);
  }
  ExFreePoolWithTag((unsigned int)v7);
  return v8;
}
