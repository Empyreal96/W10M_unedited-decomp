// _CmGetDeviceInterfacePathFormat 
 
int __fastcall CmGetDeviceInterfacePathFormat(int a1, unsigned __int16 *a2, char *a3, int a4)
{
  int v6; // r4
  char v7; // r3
  unsigned __int16 v9; // [sp+0h] [bp-18h] BYREF
  char *v10; // [sp+4h] [bp-14h]
  int v11; // [sp+8h] [bp-10h]

  v10 = a3;
  v11 = a4;
  v6 = CmValidateDeviceInterfaceName(a1, a2);
  if ( v6 >= 0 )
  {
    v6 = RtlInitUnicodeStringEx((int)&v9, a2);
    if ( v6 >= 0 )
    {
      if ( RtlPrefixUnicodeString((unsigned __int16 *)&dword_402888, &v9, 0) )
      {
        v7 = 1;
        goto LABEL_6;
      }
      if ( RtlPrefixUnicodeString((unsigned __int16 *)&dword_402890, &v9, 0) )
      {
        v7 = 0;
LABEL_6:
        *a3 = v7;
        return v6;
      }
    }
    v6 = -1073741773;
  }
  return v6;
}
