// _CmGetDeviceRelationsList 
 
int __fastcall CmGetDeviceRelationsList(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6)
{
  int v8; // r4
  int result; // r0
  char v10[24]; // [sp+10h] [bp-18h] BYREF

  switch ( a3 )
  {
    case 4:
      v8 = 0;
      break;
    case 8:
      v8 = 1;
      break;
    case 16:
      v8 = 2;
      break;
    case 32:
      v8 = 3;
      break;
    case 64:
      v8 = 4;
      break;
    default:
      return -1073741811;
  }
  result = RtlInitUnicodeStringEx((int)v10, a2);
  if ( result >= 0 )
    result = NtPlugPlayGetDeviceRelationsList(a1, v10, v8, a4, a5, a6);
  return result;
}
