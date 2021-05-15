// CmpLinkKeyToHive 
 
int __fastcall CmpLinkKeyToHive(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int v4; // r4
  int v5; // [sp+14h] [bp-34h]
  __int16 v6; // [sp+18h] [bp-30h] BYREF
  char v7[8]; // [sp+20h] [bp-28h] BYREF
  int v8; // [sp+28h] [bp-20h]
  int v9; // [sp+2Ch] [bp-1Ch]
  char *v10; // [sp+30h] [bp-18h]
  int v11; // [sp+34h] [bp-14h]
  int v12; // [sp+38h] [bp-10h]
  int v13; // [sp+3Ch] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v7, a1);
  v8 = 24;
  v9 = 0;
  v11 = 576;
  v10 = v7;
  v12 = 0;
  v13 = 0;
  if ( ZwCreateKey() < 0 )
    goto LABEL_6;
  if ( v5 != 1 )
    return sub_80B27C();
  RtlInitUnicodeString((unsigned int)&v6, a2);
  v4 = ZwSetValueKey();
  ZwClose();
  if ( v4 < 0 )
LABEL_6:
    JUMPOUT(0x80B282);
  return 1;
}
