// MmGetSessionCreateTime 
 
__int64 __fastcall MmGetSessionCreateTime(int a1)
{
  int v1; // r4
  __int64 result; // r0

  v1 = *(_DWORD *)(a1 + 324);
  if ( !v1 || PsIsSystemProcess(a1) )
    result = 0i64;
  else
    result = *(_QWORD *)(v1 + 8416);
  return result;
}
