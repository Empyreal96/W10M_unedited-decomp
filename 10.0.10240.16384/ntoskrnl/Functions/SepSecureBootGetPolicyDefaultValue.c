// SepSecureBootGetPolicyDefaultValue 
 
int __fastcall SepSecureBootGetPolicyDefaultValue(__int16 *a1, int a2, _DWORD *a3, int *a4)
{
  __int16 v5; // r1
  int result; // r0
  int v8; // r1
  int v9; // r3

  v5 = *a1;
  result = 0;
  v8 = v5 & 0x1F;
  switch ( v8 )
  {
    case 0:
      *a3 = a1 + 2;
      v9 = (unsigned __int16)a1[1];
      goto LABEL_12;
    case 1:
      *a3 = a1 + 1;
      v9 = 1;
      goto LABEL_12;
    case 5:
    case 6:
    case 7:
      *a3 = a1 + 1;
      v9 = 8;
LABEL_12:
      *a4 = v9;
      return result;
    case 8:
      result = -1073741275;
      break;
    default:
      result = -1069350909;
      break;
  }
  return result;
}
