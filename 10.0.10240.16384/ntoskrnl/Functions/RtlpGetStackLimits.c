// RtlpGetStackLimits 
 
int __fastcall RtlpGetStackLimits(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  result = KeQueryCurrentStackInformation(v5, a1, a2);
  if ( !result )
    sub_54828C();
  return result;
}
