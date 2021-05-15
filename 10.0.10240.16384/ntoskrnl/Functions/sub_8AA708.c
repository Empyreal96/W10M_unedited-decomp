// sub_8AA708 
 
int __fastcall sub_8AA708(int a1, int a2, int a3, _DWORD *a4, unsigned int *a5)
{
  int v7; // r5
  _DWORD *v8; // r0
  unsigned int v9; // r4
  _DWORD v11[5]; // [sp+8h] [bp-28h] BYREF

  memset(v11, 0, sizeof(v11));
  v11[0] = 1381190978;
  v11[1] = 1;
  v11[2] = 0;
  v11[3] = 0;
  if ( ZwQuerySystemInformation() != -1073741789 )
    return -1073741823;
  *a4 = 0;
  if ( a3 )
    return 0;
  v8 = (_DWORD *)ExAllocatePoolWithTag(1, 0, 542329939);
  v9 = (unsigned int)v8;
  if ( !v8 )
    return -1073741670;
  *v8 = 1381190978;
  v8[1] = 1;
  v8[2] = 0;
  v8[3] = -16;
  v7 = ZwQuerySystemInformation();
  if ( v7 >= 0 )
  {
    *a5 = v9;
    v9 = 0;
  }
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v7;
}
