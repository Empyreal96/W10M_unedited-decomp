// sub_7CD628 
 
void sub_7CD628()
{
  _DWORD *v0; // r4
  char v1[80]; // [sp+30h] [bp-50h] BYREF

  if ( !InitIsWinPEMode && (*v0 & 0x10) == 0 )
  {
    *v0 |= 0x10u;
    RtlInitUnicodeString((unsigned int)v1, L"DATABASE OPEN FAILED");
    PnpLogEvent(v1, 0, -1073740947, 0);
  }
  JUMPOUT(0x771592);
}
