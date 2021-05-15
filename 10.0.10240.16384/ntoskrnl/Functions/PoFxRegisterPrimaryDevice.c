// PoFxRegisterPrimaryDevice 
 
int __fastcall PoFxRegisterPrimaryDevice(int a1, _DWORD *a2)
{
  unsigned int v3; // r5
  int v5; // r0
  int v6; // r4
  int v8[12]; // [sp+18h] [bp-30h] BYREF

  v3 = 0;
  if ( a1 && a2 && *a2 == 1 )
  {
    v5 = PopFxConvertV1Components(a2 + 10, a2[1]);
    v3 = v5;
    if ( !v5 )
      return -1073741670;
    v8[0] = a2[2];
    v8[1] = a2[3];
    v8[2] = a2[4];
    v8[3] = a2[5];
    v8[4] = a2[6];
    v8[5] = a2[7];
    v8[6] = a2[8];
    v6 = PopFxRegisterDevice(a1, v8, v5, a2[1], a2[9]);
  }
  else
  {
    v6 = -1073741811;
  }
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v6;
}
