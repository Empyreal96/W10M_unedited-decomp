// IopEnumerateEnvironmentVariablesSysEnv 
 
int __fastcall IopEnumerateEnvironmentVariablesSysEnv(int a1, int a2, int a3, int a4, int *a5)
{
  int result; // r0
  char v6[4]; // [sp+18h] [bp-10h] BYREF
  int v7[3]; // [sp+1Ch] [bp-Ch] BYREF

  if ( a3 != 2 )
    return sub_81516C(a4);
  v6[0] = 1;
  result = IopIssueSystemEnvironmentRequest((int)&dword_52000C, 1, 0, a2, (int)v6, 1, a4, *a5, v7);
  if ( result == -1073741789 )
    *a5 = v7[0];
  return result;
}
