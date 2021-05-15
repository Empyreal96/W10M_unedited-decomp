// EtwpEnableKernelTrace 
 
int __fastcall EtwpEnableKernelTrace(int a1, int a2)
{
  _BYTE *v3; // r0
  int v5[8]; // [sp+14h] [bp-60h] BYREF

  v3 = memset(v5, 0, sizeof(v5));
  if ( !a2 )
    JUMPOUT(0x7D0410);
  return sub_7D03F0(v3);
}
