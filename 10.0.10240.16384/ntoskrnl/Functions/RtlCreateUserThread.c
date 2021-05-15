// RtlCreateUserThread 
 
int __fastcall RtlCreateUserThread(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9, _DWORD *a10)
{
  bool v10; // zf
  int v12; // [sp+8h] [bp-20h]

  v10 = a3 == 1;
  if ( a3 == 1 )
    a3 = 1;
  if ( !v10 )
    a3 = 0;
  return RtlpCreateUserThreadEx(a1, a2, a3, a4, a5, a6, v12, a7, a8, a9, a10);
}
