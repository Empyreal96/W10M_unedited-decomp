// BiConvertNtFilePathToBootEnvironment 
 
int __fastcall BiConvertNtFilePathToBootEnvironment(int *a1, unsigned int a2, unsigned __int16 *a3, int a4, _DWORD *a5)
{
  int v6; // r4
  unsigned int v7; // r5
  int v8; // r6
  _DWORD *v9; // r0
  _DWORD *v10; // r4
  unsigned int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[1] = a4;
  v12[0] = 0;
  v6 = BiConvertNtDeviceToBootEnvironment(a1, a2, a4, (int *)v12);
  if ( v6 >= 0 )
  {
    v7 = wcslen(a3) + 1;
    v8 = *(_DWORD *)(v12[0] + 8) + 2 * v7 + 12;
    v9 = (_DWORD *)ExAllocatePoolWithTag(1, v8, 1262764866);
    v10 = v9;
    if ( v9 )
    {
      *v9 = 1;
      v9[1] = v8;
      v9[2] = 5;
      memmove((int)(v9 + 3), v12[0], *(_DWORD *)(v12[0] + 8));
      memmove((int)v10 + *(_DWORD *)(v12[0] + 8) + 12, (int)a3, 2 * v7);
      *a5 = v10;
      v6 = 0;
    }
    else
    {
      v6 = -1073741670;
    }
  }
  if ( v12[0] )
    ExFreePoolWithTag(v12[0]);
  return v6;
}
