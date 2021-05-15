// sub_965BA0 
 
void __fastcall sub_965BA0(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  unsigned __int16 v5[16]; // [sp+8h] [bp-20h] BYREF

  *v4 = a4 | 1;
  RtlInitUnicodeString((unsigned int)v5, L"DATABASE NOT LOADED");
  PnpLogEvent(v5, 0, -1073740947, 0, 0);
  JUMPOUT(0x948F56);
}
