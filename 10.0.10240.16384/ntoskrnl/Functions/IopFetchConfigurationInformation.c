// IopFetchConfigurationInformation 
 
int __fastcall IopFetchConfigurationInformation(unsigned __int16 **a1, int a2, int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  unsigned int v8; // r5
  int result; // r0
  unsigned __int16 *i; // r4
  int var28[16]; // [sp+0h] [bp-28h] BYREF

  var28[12] = (int)a1;
  var28[13] = a2;
  var28[14] = a3;
  var28[15] = a4;
  var28[1] = a3;
  var28[2] = a4;
  var28[3] = a5;
  var28[0] = a2;
  v8 = 0;
  if ( IoGetDeviceInterfaces((int)var28, 0, 0, a1) < 0 )
    return sub_969538();
  for ( i = *a1; wcslen(i); i += wcslen(i) + 1 )
    ++v8;
  *a7 = v8;
  if ( v8 < a6 )
    result = -1073741823;
  else
    result = 0;
  return result;
}
