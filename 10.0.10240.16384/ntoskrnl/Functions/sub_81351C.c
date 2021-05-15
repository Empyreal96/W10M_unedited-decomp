// sub_81351C 
 
void sub_81351C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // [sp+18h] [bp+18h] BYREF
  va_list va; // [sp+18h] [bp+18h]
  int v17; // [sp+1Ch] [bp+1Ch]
  va_list va1; // [sp+20h] [bp+20h] BYREF

  va_start(va1, a10);
  va_start(va, a10);
  v15 = va_arg(va1, _DWORD);
  v17 = va_arg(va1, _DWORD);
  if ( BiAcquirePrivilege(22, (int)va1, a3, a4) < 0 )
LABEL_14:
    JUMPOUT(0x7A4E14);
  RtlInitUnicodeString((unsigned int)va, L"MsVariablesSupportedTest");
  v10 = ZwQuerySystemEnvironmentValueEx();
  if ( v10 >= 0 || v10 == -1073741789 )
  {
    if ( ZwSetSystemEnvironmentValueEx() < 0 )
    {
LABEL_13:
      BiReleasePrivilege((int)va1, v11, v12, v13);
      goto LABEL_14;
    }
  }
  else
  {
    v13 = -1073741568;
    if ( v10 != -1073741568 )
      goto LABEL_13;
  }
  if ( ZwSetSystemEnvironmentValueEx() >= 0
    && ZwQuerySystemEnvironmentValueEx() >= 0
    && ZwSetSystemEnvironmentValueEx() >= 0
    && ZwEnumerateSystemEnvironmentValuesEx() == -1073741789 )
  {
    v14 = ExAllocatePoolWithTag(1, 0, 1262764866);
    if ( v14 )
    {
      ZwEnumerateSystemEnvironmentValuesEx();
      ExFreePoolWithTag(v14);
    }
  }
  goto LABEL_13;
}
