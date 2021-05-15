// PoFxRegisterCoreDevice 
 
int __fastcall PoFxRegisterCoreDevice(int a1, _DWORD *a2, int **a3)
{
  int *v4; // r4
  unsigned int v5; // r6
  int v8; // r0
  int v9; // r1
  int v10; // r5
  int *v12; // [sp+20h] [bp-38h]
  int v13[12]; // [sp+28h] [bp-30h] BYREF

  v4 = 0;
  v5 = 0;
  v12 = 0;
  if ( a1 && *a2 == 1 && a2[4] )
  {
    v5 = PopFxConvertV1Components(a2 + 7, a2[1]);
    if ( !v5 )
    {
      v10 = -1073741670;
      goto LABEL_9;
    }
    memset(v13, 0, 28);
    v13[0] = a2[2];
    v13[1] = a2[3];
    v13[2] = a2[5];
    v13[6] = a2[4];
    v8 = ((int (__fastcall *)(_DWORD, int, int *, unsigned int, _DWORD, _DWORD, _DWORD))PopFxRegisterDeviceWorker)(
           0,
           a1,
           v13,
           v5,
           a2[1],
           a2[6],
           0);
    v10 = v8;
    if ( v8 < 0 )
    {
      v4 = 0;
    }
    else
    {
      v4 = v12;
      PopFxInsertDevice(v8, v9, v12);
      v10 = 0;
    }
  }
  else
  {
    v10 = -1073741811;
  }
  if ( v5 )
    ExFreePoolWithTag(v5);
LABEL_9:
  *a3 = v4;
  return v10;
}
