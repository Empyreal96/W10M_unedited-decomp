// KeHwPolicyLocateResource 
 
int __fastcall KeHwPolicyLocateResource(int a1, int a2, int a3, _DWORD *a4, int *a5)
{
  int v7; // r0
  int result; // r0
  int v11[10]; // [sp+10h] [bp-28h] BYREF

  v7 = KiHwPolicyDriverImageBase;
  if ( KiHwPolicyDriverImageBase
    || !KiHwPolicyDriverNotPresent && (v7 = KiHwPolicyFindDriverImage(a1), (KiHwPolicyDriverImageBase = v7) != 0) )
  {
    v11[1] = a3;
    v11[2] = 0;
    v11[0] = a2;
    result = LdrResSearchResource(v7, (int)v11, 3u, 48, a4, a5, 0, 0);
  }
  else
  {
    result = -1073741204;
    KiHwPolicyDriverNotPresent = 1;
  }
  return result;
}
