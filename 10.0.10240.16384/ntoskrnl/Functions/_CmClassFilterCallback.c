// _CmClassFilterCallback 
 
int __fastcall CmClassFilterCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  unsigned __int16 *v9; // r1
  int (__fastcall *v10)(int, int, int, _DWORD); // r4
  unsigned int v12; // [sp+10h] [bp-88h] BYREF
  int v13; // [sp+14h] [bp-84h] BYREF
  unsigned __int16 v14[4]; // [sp+18h] [bp-80h] BYREF
  unsigned __int16 v15[4]; // [sp+20h] [bp-78h] BYREF
  unsigned __int16 v16[56]; // [sp+28h] [bp-70h] BYREF

  v5 = 0;
  v12 = 0;
  v13 = 0;
  if ( a4 )
  {
    v9 = *(unsigned __int16 **)a4;
    if ( !*(_DWORD *)a4
      || !*v9
      || RtlInitUnicodeStringEx((int)v15, v9) >= 0
      && (v12 = 78, CmGetDeviceRegProp(a1, a2, 0, 9, (int)&v13, (int)v16, (int)&v12) >= 0)
      && v13 == 1
      && v12 >= 2
      && (v16[38] = 0, RtlInitUnicodeStringEx((int)v14, v16) >= 0)
      && RtlEqualUnicodeString(v15, v14, 1) )
    {
      v5 = 1;
      v10 = *(int (__fastcall **)(int, int, int, _DWORD))(a4 + 4);
      if ( v10 )
        v5 = v10(a1, a2, a3, *(_DWORD *)(a4 + 8));
    }
  }
  return v5;
}
