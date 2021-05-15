// PopWakeSourceGetDeviceProperty 
 
int __fastcall PopWakeSourceGetDeviceProperty(int a1, __int16 a2, int a3, unsigned int a4)
{
  int *v7; // r0
  unsigned __int16 *v8; // r4
  __int16 v9; // r0
  int v11; // [sp+0h] [bp-20h]
  unsigned int v12[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  if ( IoGetDeviceProperty(a3, a2, 0, 0, v12) == -1073741789 )
  {
    v7 = (int *)ExAllocatePoolWithTag(1, v12[0], 544040269);
    v8 = (unsigned __int16 *)v7;
    if ( v7 )
    {
      if ( IoGetDeviceProperty(a3, a2, v12[0], v7, v12) >= 0 )
      {
        *(_WORD *)(a1 + 2) = v12[0];
        v9 = wcslen(v8);
        *(_DWORD *)(a1 + 4) = v8;
        *(_WORD *)a1 = 2 * v9;
        v8 = 0;
      }
      if ( v8 )
        ExFreePoolWithTag((unsigned int)v8);
    }
  }
  return v11;
}
