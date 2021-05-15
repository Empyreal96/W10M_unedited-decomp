// CmpAddRemoveContainerToCLFSLog 
 
int __fastcall CmpAddRemoveContainerToCLFSLog(int a1, unsigned __int16 *a2, unsigned __int16 *a3, unsigned __int16 *a4, unsigned __int16 *a5, int a6, int a7, char a8)
{
  unsigned __int16 v11; // r5
  unsigned __int16 v12; // r4
  int v13; // r4
  int v14; // r3
  int v15; // r5
  int v16; // r0
  unsigned __int16 v18; // [sp+0h] [bp-68h] BYREF
  unsigned __int16 v19; // [sp+2h] [bp-66h]
  int v20; // [sp+4h] [bp-64h]
  _DWORD v21[2]; // [sp+8h] [bp-60h] BYREF
  unsigned __int16 *v22[4]; // [sp+10h] [bp-58h] BYREF
  char v23[24]; // [sp+20h] [bp-48h] BYREF
  char v24[48]; // [sp+38h] [bp-30h] BYREF

  v22[0] = a2;
  RtlInitUnicodeString((unsigned int)v21, 0);
  v11 = *a5;
  v12 = *a4;
  v18 = 0;
  v19 = *v22[0] + v11 + v12 + *a3 + 34;
  v20 = ExAllocatePoolWithTag(1, v19, 538987843);
  if ( !v20 )
    return -1073741670;
  RtlAppendUnicodeStringToString(&v18, v22[0]);
  RtlAppendUnicodeStringToString(&v18, a3);
  RtlAppendUnicodeStringToString(&v18, a4);
  sprintf_s((int)v24, 16, (int)".%u", a6);
  RtlInitAnsiString((unsigned int)v22, (unsigned int)v24);
  v13 = RtlAnsiStringToUnicodeString((unsigned __int16 *)v21, (unsigned __int16 *)v22, 1, v14);
  if ( v13 >= 0 && LOWORD(v21[0]) <= 0x20u )
  {
    RtlAppendUnicodeStringToString(&v18, (unsigned __int16 *)v21);
    RtlAppendUnicodeStringToString(&v18, a5);
    v15 = PsDisableImpersonation((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), (int)v22);
    KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v23);
    if ( a8 == 1 )
      v16 = ClfsAddLogContainer(a1, a7, &v18);
    else
      v16 = ClfsRemoveLogContainer(a1, &v18, 1);
    v13 = v16;
    KiUnstackDetachProcess((unsigned int)v23, 0);
    if ( v15 )
      PsRestoreImpersonation((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), (int)v22);
  }
  RtlFreeAnsiString(v21);
  ExFreePoolWithTag(v20);
  return v13;
}
