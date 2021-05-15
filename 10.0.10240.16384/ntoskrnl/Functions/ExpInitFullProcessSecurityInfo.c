// ExpInitFullProcessSecurityInfo 
 
int __fastcall ExpInitFullProcessSecurityInfo(int a1, int a2, _DWORD *a3)
{
  int v4; // r5
  int result; // r0
  unsigned int v6; // [sp+38h] [bp-60h]
  char v7[92]; // [sp+3Ch] [bp-5Ch] BYREF

  if ( ZwOpenKey() < 0 )
    goto LABEL_9;
  v4 = ZwQueryValueKey();
  if ( v4 >= 0 )
  {
    if ( v6 > 0x44 )
    {
      v4 = -1073741789;
    }
    else
    {
      memmove((int)&ExpFullProcessInformationSid, (int)v7, v6);
      *a3 = &ExpFullProcessInformationSid;
    }
  }
  ZwClose();
  if ( v4 < 0 )
LABEL_9:
    result = 0;
  else
    result = 1;
  return result;
}
