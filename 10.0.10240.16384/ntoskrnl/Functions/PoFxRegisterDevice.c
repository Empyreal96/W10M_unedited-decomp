// PoFxRegisterDevice 
 
int __fastcall PoFxRegisterDevice(int a1, _DWORD *a2)
{
  unsigned int v3; // r5
  _DWORD *v4; // r7
  int v6; // r8
  int v7; // r9
  int v8; // r4
  int v10[14]; // [sp+20h] [bp-38h] BYREF

  v3 = 0;
  v4 = 0;
  if ( !a1 )
    return -1073741811;
  memset(v10, 0, 28);
  if ( *a2 == 1 )
  {
    PopPrintEx(1);
    PopPrintEx(1);
    PopPrintEx(1);
    v6 = a2[1];
    v7 = a2[8];
    v10[0] = a2[2];
    v10[1] = a2[3];
    v10[2] = a2[4];
    v10[3] = a2[5];
    v10[4] = a2[6];
    v10[5] = a2[7];
    v3 = PopFxConvertV1Components(a2 + 9, v6);
  }
  else
  {
    if ( *a2 != 2 )
    {
      v8 = -1073741811;
      goto LABEL_5;
    }
    v6 = a2[11];
    v7 = a2[10];
    v10[0] = a2[4];
    v4 = a2;
    v3 = (unsigned int)(a2 + 12);
    v10[1] = a2[5];
    v10[2] = a2[6];
    v10[3] = a2[7];
    v10[4] = a2[8];
    v10[5] = a2[9];
  }
  v8 = PopFxRegisterDevice(a1, v10, v3, v6, v7);
LABEL_5:
  if ( !v4 && v3 )
    ExFreePoolWithTag(v3);
  return v8;
}
