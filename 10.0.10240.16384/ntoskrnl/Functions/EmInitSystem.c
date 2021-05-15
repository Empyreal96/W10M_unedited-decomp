// EmInitSystem 
 
int __fastcall EmInitSystem(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int v4; // r0
  int i; // r0
  int v7; // r3
  int v8; // r4
  int v9; // r9
  int v10; // r7
  int v11; // r4
  unsigned __int16 v12[4]; // [sp+30h] [bp-170h] BYREF
  unsigned __int16 v13[2]; // [sp+38h] [bp-168h] BYREF
  char *v14; // [sp+3Ch] [bp-164h]
  int v15; // [sp+40h] [bp-160h]
  int v16; // [sp+48h] [bp-158h]
  int v17; // [sp+4Ch] [bp-154h]
  unsigned __int16 *v18; // [sp+50h] [bp-150h]
  int v19; // [sp+54h] [bp-14Ch]
  int v20; // [sp+58h] [bp-148h]
  int v21; // [sp+5Ch] [bp-144h]
  int v22; // [sp+70h] [bp-130h]
  int v23; // [sp+74h] [bp-12Ch]
  char v24; // [sp+80h] [bp-120h] BYREF

  v2 = 0;
  v3 = 0;
  if ( !a1 )
  {
    EmpParseLock = 0;
    EmpDatabaseLock = 0;
    EmpEvaluationQueueLock = 0;
    EmpPagingLock = 0;
    EmpEntryListHead = 0;
    EmpCallbackListHead = 0;
    EmpRuleListHead = 0;
    EmpTargetRuleListHead = 0;
    EmpStringTable = 0;
    EmpNumberOfEntryTypes = 0;
    EmpNumberOfCallbacks = 0;
    EmpNumberOfRules = 0;
    EmpNumberOfStrings = 0;
    EmpNumberOfTargetRules = 0;
    EmpRuleUpdateQueue = 0;
    EmpWorkerBusy = 0;
    dword_631F1C |= 0x80000000;
    dword_631F38 = (int)EmpRuleUpdateWorkerThread;
    dword_631F3C = 0;
    EmpRuleUpdateWorker = 0;
    v7 = *(_DWORD *)(a2 + 132);
    if ( *(_DWORD *)(v7 + 20) && *(_DWORD *)(v7 + 24) && ((int (*)(void))EmpParseInfDatabase)() < 0 )
      goto LABEL_33;
    EmpCachedBiosDate = 0;
    HalRegisterErrataCallbacks();
    if ( EmpProviderRegister(0, 0, 0, (unsigned int *)&BuiltinCallbackReg, 6u, &EmBuiltinProviderHandle) < 0 )
      goto LABEL_33;
    goto LABEL_17;
  }
  if ( a1 != 1 )
  {
LABEL_17:
    v8 = 0;
    goto LABEL_18;
  }
  RtlInitUnicodeString((unsigned int)v12, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Errata\\Dynamic");
  v16 = 24;
  v17 = 0;
  v18 = v12;
  v20 = 0;
  v21 = 0;
  v19 = 576;
  if ( ZwCreateKey() < 0 )
    goto LABEL_33;
  v4 = ZwQueryKey();
  if ( v4 != -2147483643 && v4 != -1073741789 )
    return sub_96B970();
  v2 = ExAllocatePoolWithTag(1, 0, 1953058117);
  if ( v2 )
  {
    if ( ZwQueryKey() < 0 )
      goto LABEL_33;
    v3 = ExAllocatePoolWithTag(1, *(_DWORD *)(v2 + 40) + 16, 1953058117);
    if ( v3 )
    {
      v15 = 0;
      for ( i = ZwEnumerateValueKey(); ; i = ZwEnumerateValueKey() )
      {
        if ( i == -2147483622 )
          goto LABEL_17;
        if ( i < 0 )
          goto LABEL_33;
        v13[1] = 256;
        v13[0] = 0;
        v14 = &v24;
        RtlInitUnicodeString((unsigned int)v12, L"\\SystemRoot\\inf\\");
        RtlAppendStringToString(v13, v12);
        *(_BYTE *)(*(_DWORD *)(v3 + 8) + v3 + 12) = 0;
        RtlInitUnicodeString((unsigned int)v12, (unsigned __int16 *)(v3 + 12));
        RtlAppendStringToString(v13, v12);
        v16 = 24;
        v17 = 0;
        v18 = v13;
        v19 = 576;
        v20 = 0;
        v21 = 0;
        if ( ZwCreateFile() < 0 )
          goto LABEL_33;
        if ( ZwQueryInformationFile() < 0 )
          break;
        if ( v23 )
          JUMPOUT(0x96B974);
        v9 = v22;
        v10 = ExAllocatePoolWithTag(1, v22, 1953058117);
        if ( !v10 )
          break;
        v11 = ZwReadFile();
        ZwClose();
        if ( v11 < 0 )
          JUMPOUT(0x96B980);
        if ( EmpParseInfDatabase(v10, v9) < 0 )
          JUMPOUT(0x96B97E);
        ++v15;
      }
      ZwClose();
LABEL_33:
      JUMPOUT(0x96B986);
    }
  }
  v8 = -1073741670;
LABEL_18:
  if ( v2 )
    ExFreePoolWithTag(v2);
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v8;
}
