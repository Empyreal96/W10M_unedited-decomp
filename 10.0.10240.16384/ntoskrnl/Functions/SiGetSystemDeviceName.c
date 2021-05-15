// SiGetSystemDeviceName 
 
int __fastcall SiGetSystemDeviceName(int (__fastcall *a1)(int, unsigned __int16 **), int a2, unsigned int a3, unsigned __int16 *a4)
{
  int v8; // r4
  int v9; // r4
  unsigned __int16 *v10; // r5
  unsigned int v11; // r0
  unsigned __int16 *v12; // r6
  unsigned __int16 *v14[8]; // [sp+0h] [bp-50h] BYREF
  int v15; // [sp+20h] [bp-30h]

  v14[1] = a4;
  *(_DWORD *)a4 = 0;
  v14[0] = 0;
  v8 = 2;
  if ( ZwQuerySystemInformation() >= 0 )
  {
    v8 = v15;
    if ( v15 >= 3 )
      v8 = 0;
  }
  v9 = a1(v8, v14);
  v10 = v14[0];
  if ( v9 >= 0 )
  {
    v11 = wcslen(v14[0]);
    v12 = (unsigned __int16 *)(2 * (v11 + 1));
    v14[2] = v12;
    if ( a2 && a3 >= (unsigned int)v12 )
    {
      v9 = 0;
      memmove(a2, (int)v10, 2 * (v11 + 1));
    }
    else
    {
      v9 = -1073741789;
    }
    *(_DWORD *)a4 = v12;
  }
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  return v9;
}
