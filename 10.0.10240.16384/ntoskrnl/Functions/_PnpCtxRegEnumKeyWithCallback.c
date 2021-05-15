// _PnpCtxRegEnumKeyWithCallback 
 
int __fastcall PnpCtxRegEnumKeyWithCallback(int *a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6[4]; // [sp+0h] [bp-20h] BYREF
  _DWORD v7[4]; // [sp+10h] [bp-10h] BYREF

  if ( a1 )
    v4 = *a1;
  else
    v4 = 0;
  v6[1] = a3;
  v6[2] = a4;
  v6[0] = (int)a1;
  v7[0] = v4;
  v7[1] = PnpCtxInternalEnumKeyCallback;
  v7[2] = v6;
  return RegRtlEnumKeyWithCallback(a2, a2, (int)v7);
}
