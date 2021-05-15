// _CmValidateDeviceInterfaceName 
 
int __fastcall CmValidateDeviceInterfaceName(int a1, unsigned __int16 *a2)
{
  int v3; // r6
  unsigned __int16 *v4; // r4
  unsigned __int16 *v5; // r2
  int v6; // r3
  int v7; // t1
  unsigned int v8; // r2
  int result; // r0
  __int16 v10[4]; // [sp+10h] [bp-78h] BYREF
  char v11[16]; // [sp+18h] [bp-70h] BYREF
  unsigned __int16 v12[48]; // [sp+28h] [bp-60h] BYREF

  v3 = 0;
  v4 = 0;
  if ( RtlInitUnicodeStringEx((int)v10, a2) < 0
    || (v10[1] & 0xFFFEu) < 0x62
    || !RtlPrefixUnicodeString(&dword_401850, v10, 0) && !RtlPrefixUnicodeString(&dword_401858, v10, 0) )
  {
    return -1073741773;
  }
  v5 = a2 + 4;
  v6 = a2[4];
  if ( !a2[4] )
    goto LABEL_9;
  do
  {
    if ( v6 == 92 )
    {
      if ( (unsigned int)++v3 > 1 )
        return -1073741773;
      v4 = v5;
    }
    v7 = v5[1];
    ++v5;
    v6 = v7;
  }
  while ( v7 );
  if ( v4 )
    v8 = v4 - a2;
  else
LABEL_9:
    v8 = (unsigned __int16)v10[0] >> 1;
  if ( v8 < 0x30 )
    return -1073741773;
  result = RtlStringCchCopyNExW(v12, 0x27u, (int)&a2[v8 - 38], 38, 0, 0, 2048);
  if ( result >= 0 )
  {
    result = RtlInitUnicodeStringEx((int)v10, v12);
    if ( result >= 0 )
    {
      result = RtlGUIDFromString(v10, v11);
      if ( result < 0 )
        return -1073741773;
    }
  }
  return result;
}
