// PopDiagSnapPassiveHistogram 
 
int __fastcall PopDiagSnapPassiveHistogram(int a1, int *a2)
{
  int v4; // r9
  __int64 v5; // r5
  __int64 v6; // r3
  int result; // r0

  v4 = 20;
  do
  {
    v5 = *(_QWORD *)(a1 + 176);
    v6 = *(_QWORD *)(a1 + 16);
    *(_QWORD *)(a1 + 16) = v5;
    result = _rt_udiv64((unsigned int)dword_989680, v6 - v5);
    a1 += 8;
    --v4;
    *a2++ = result;
  }
  while ( v4 );
  return result;
}
