// EtwpCrimsonStackWalkApc 
 
int __fastcall EtwpCrimsonStackWalkApc(int a1, _DWORD *a2, _DWORD *a3, int *a4, int *a5)
{
  int v7; // r7
  int v8; // r8
  _DWORD v10[96]; // [sp+38h] [bp-180h] BYREF

  *a2 = 0;
  ExFreePoolWithTag(a1);
  v7 = *a4;
  v8 = *a5;
  memset(v10, 0, 352);
  v10[3] = -1233785801;
  v10[4] = 1179172278;
  v10[5] = -34368836;
  v10[6] = -1573106233;
  HIWORD(v10[23]) = *a3;
  v10[22] = 1;
  v10[24] = 68;
  LOBYTE(v10[23]) = -1;
  v10[26] = -1;
  v10[27] = -1;
  v10[28] = 0;
  v10[29] = 0;
  v10[10] = v7;
  v10[11] = v8;
  return EtwpEventWriteFull(
           v10,
           1,
           0,
           0,
           0,
           (unsigned __int16 *)ETW_EVENT_USER_STACK_TRACE,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           0);
}
