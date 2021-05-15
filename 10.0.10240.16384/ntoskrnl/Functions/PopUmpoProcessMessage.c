// PopUmpoProcessMessage 
 
int __fastcall PopUmpoProcessMessage(int a1)
{
  int v1; // r2
  signed int v2; // r3
  int v3; // r4
  int result; // r0
  _BYTE *v5; // r0
  int v6[11]; // [sp+2Ch] [bp-48h] BYREF

  v1 = *(unsigned __int16 *)(a1 + 4);
  v2 = v1 & 0xFFFF00FF;
  if ( (v1 & 0xFFFF00FF) == 3 )
  {
    if ( (v1 & 0x2000) != 0 )
      JUMPOUT(0x7C3BDE);
    v3 = PopUmpoProcessPowerMessage(a1 + 24);
    if ( v3 >= 0 )
      v3 = 0;
    result = v3;
  }
  else
  {
    if ( v2 == 1 )
      JUMPOUT(0x7C3BEC);
    if ( v2 <= 4 )
      goto LABEL_20;
    if ( v2 <= 6 )
      JUMPOUT(0x7C3B2A);
    if ( v2 != 10 )
LABEL_20:
      JUMPOUT(0x7C3BC8);
    v5 = memset(v6, 0, sizeof(v6));
    v6[4] = 512;
    if ( !PopUmpoAlpcClientConnected )
      JUMPOUT(0x7C3ACA);
    result = sub_7C3AC8(v5);
  }
  return result;
}
