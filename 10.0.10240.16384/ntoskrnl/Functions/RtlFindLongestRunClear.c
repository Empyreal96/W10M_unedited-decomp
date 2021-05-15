// RtlFindLongestRunClear 
 
int __fastcall RtlFindLongestRunClear(_DWORD *a1, int *a2, int a3, int a4)
{
  int result; // r0
  int v6; // r3
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v8 = a3;
  v9 = a4;
  if ( RtlFindClearRuns(a1, (int)&v7, 1u, 1) == 1 )
  {
    v6 = v7;
    result = v8;
  }
  else
  {
    v6 = 0;
    result = 0;
  }
  *a2 = v6;
  return result;
}
