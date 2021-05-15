// SepSecureBootGetPolicyValueByRef 
 
int __fastcall SepSecureBootGetPolicyValueByRef(unsigned __int16 *a1, int a2, _DWORD *a3, int *a4)
{
  int v5; // r3
  int v6; // r5
  int v7; // r3
  int v8; // r3

  v5 = *a1;
  v6 = 0;
  if ( a2 != v5 )
    return -1073741772;
  v7 = v5 & 0x1F;
  switch ( v7 )
  {
    case 0:
    case 10:
      *a3 = a1 + 2;
      v8 = a1[1];
LABEL_5:
      *a4 = v8;
      return v6;
    case 2:
      *a3 = a1 + 1;
      v8 = 4;
      goto LABEL_5;
    case 4:
      *a3 = a1 + 4;
      v8 = 4 * a1[3];
      goto LABEL_5;
  }
  return sub_80FF2C();
}
