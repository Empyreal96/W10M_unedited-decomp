// sub_6B50D4 
 
int __fastcall sub_6B50D4(int a1, int a2, int a3, _DWORD *a4, int *a5)
{
  int result; // r0
  int v7; // r3
  _DWORD v8[3]; // [sp+8h] [bp-20h] BYREF
  int v9; // [sp+14h] [bp-14h]
  int v10; // [sp+18h] [bp-10h]
  int v11; // [sp+1Ch] [bp-Ch]

  v8[0] = a1;
  v8[1] = a2;
  v8[2] = a3;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  result = KeExpandKernelStackAndCalloutEx((int)sub_6DF3D0, (int)v8, 15360, 0, 0);
  if ( result >= 0 )
  {
    v7 = v10;
    result = v11;
    *a4 = v9;
    *a5 = v7;
  }
  return result;
}
