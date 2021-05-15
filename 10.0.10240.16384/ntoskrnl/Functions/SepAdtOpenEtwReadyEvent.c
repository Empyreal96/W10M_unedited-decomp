// SepAdtOpenEtwReadyEvent 
 
int __fastcall SepAdtOpenEtwReadyEvent(unsigned int a1)
{
  int result; // r0
  char v3[8]; // [sp+8h] [bp-28h] BYREF
  int v4[8]; // [sp+10h] [bp-20h] BYREF

  RtlInitUnicodeString((unsigned int)v3, L"\\ADT_ETW_CHANNEL_INIT");
  v4[0] = 24;
  v4[1] = 0;
  v4[3] = 640;
  v4[2] = (int)v3;
  v4[4] = 0;
  v4[5] = 0;
  result = NtCreateEvent(a1, 1048579, (int)v4, 0, 0);
  if ( result == 0x40000000 || result == -1073741771 )
    result = 0;
  return result;
}
