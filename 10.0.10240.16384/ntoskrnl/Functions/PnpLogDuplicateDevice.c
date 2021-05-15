// PnpLogDuplicateDevice 
 
int __fastcall PnpLogDuplicateDevice(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int v3; // r3
  unsigned __int16 *v4; // r0
  __int16 v6[4]; // [sp+8h] [bp-18h] BYREF
  unsigned __int16 v7; // [sp+10h] [bp-10h] BYREF
  unsigned __int16 v8; // [sp+12h] [bp-Eh]

  RtlInitUnicodeString((unsigned int)v6, a1);
  RtlInitUnicodeString((unsigned int)&v7, a2);
  if ( (unsigned int)v8 + 2 > 0x98 )
  {
    v7 = 150;
    v3 = 0;
  }
  else
  {
    if ( (unsigned __int16)v6[1] + (unsigned int)v8 <= 0x98 )
    {
      v3 = (unsigned __int16)v6[0];
      goto LABEL_7;
    }
    v3 = (unsigned __int16)(150 - v8);
  }
  v6[0] = v3;
LABEL_7:
  if ( v3 )
    v4 = (unsigned __int16 *)v6;
  else
    v4 = 0;
  return PnpLogEvent(v4, &v7, -1073479624, 0, 0);
}
