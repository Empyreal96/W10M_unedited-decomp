// CmpInitializeSystemHive 
 
int __fastcall CmpInitializeSystemHive(int a1)
{
  int v2; // r6
  int v3; // r3
  int v4; // r3
  _DWORD *v5; // r4
  int v6; // r2
  int v7; // r0
  _DWORD *v8; // r6
  int v9; // r3
  _BYTE *v10; // r5
  int v11; // r4
  char v13[4]; // [sp+20h] [bp-148h] BYREF
  _DWORD *v14; // [sp+24h] [bp-144h] BYREF
  unsigned __int16 v15[4]; // [sp+28h] [bp-140h] BYREF
  int v16[78]; // [sp+30h] [bp-138h] BYREF

  v13[0] = 0;
  v14 = 0;
  v16[0] = 0;
  memset(&v16[1], 0, 284);
  RtlInitAnsiString((unsigned int)v15, *(_DWORD *)(a1 + 120));
  v2 = v15[0];
  CmpLoadOptions = 0;
  v3 = v15[0] + 1;
  word_98223A = 2 * v3;
  dword_98223C = ExAllocatePoolWithTag(1, 2 * v3, 538987843);
  if ( !dword_98223C )
    sub_966BCC();
  RtlAnsiStringToUnicodeString((unsigned __int16 *)&CmpLoadOptions, v15, 0, v4);
  *(_WORD *)(dword_98223C + 2 * v2) = 0;
  CmpLoadOptions += 2;
  v5 = *(_DWORD **)(a1 + 96);
  memset(v16, 0, 288);
  v6 = 18;
  if ( (dword_60E8A8 & 0x20000) != 0 )
    v6 = 131090;
  v7 = CmpInitializeHive((int)&v14, 1u, v6, 2u, v5, 0, (int)&CmpSystemFileName, 65544, 0, 0, v13, v16);
  if ( v7 < 0 )
    KeBugCheckEx(116, 3, 2, (int)v16, v7);
  if ( v13[0] == 1 )
    CmpInitRmLogOnLoad = 1;
  v8 = v14;
  if ( CmpShareSystemHives )
    v14[23] = v14[23] & 0xFFFDFFFF | 0x8001;
  v9 = *(_DWORD *)(v8[8] + 4088);
  CmpBootType = v9;
  if ( !CmSelfHeal )
  {
    CmpSelfHeal = 0;
    if ( (v9 & 4) != 0 )
      KeBugCheckEx(116, 3, 3, (int)v8, 0);
  }
  v10 = CmpHiveRootSecurityDescriptor();
  v11 = CmpLinkHiveToMaster(CmRegistryMachineSystemName, 0, (int)v8, 0, dword_60E8B0, 0, 0, (int)v10, 1);
  ExFreePoolWithTag((unsigned int)v10);
  if ( v11 < 0 )
    return 0;
  off_60E8A4 = v8;
  return 1;
}
