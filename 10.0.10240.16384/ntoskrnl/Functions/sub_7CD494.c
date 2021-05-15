// sub_7CD494 
 
void sub_7CD494(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r10
  int v11; // [sp+18h] [bp+18h] BYREF
  va_list va; // [sp+18h] [bp+18h]
  int v13; // [sp+1Ch] [bp+1Ch]
  int v14; // [sp+20h] [bp+20h]
  int v15; // [sp+24h] [bp+24h] BYREF
  va_list va1; // [sp+24h] [bp+24h]
  va_list va2; // [sp+28h] [bp+28h] BYREF

  va_start(va2, a10);
  va_start(va1, a10);
  va_start(va, a10);
  v11 = va_arg(va1, _DWORD);
  v13 = va_arg(va1, _DWORD);
  v14 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v15 = va_arg(va2, _DWORD);
  v14 = 4;
  v15 = 4;
  SdbQueryDataEx(v10, a3, a3, (int *)va1);
  if ( !SdbReadEntryInformation(v10, v11, va2) && (PiLoggedErrorEventsMask & 0x100) == 0 )
  {
    PiLoggedErrorEventsMask |= 0x100u;
    RtlInitUnicodeString((unsigned int)va, L"READ DRIVER ID FAILED");
    PnpLogEvent((int *)va, 0, -1073740947, 0);
  }
  JUMPOUT(0x771368);
}
