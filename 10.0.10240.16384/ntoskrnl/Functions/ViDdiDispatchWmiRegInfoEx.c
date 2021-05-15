// ViDdiDispatchWmiRegInfoEx 
 
int __fastcall ViDdiDispatchWmiRegInfoEx(int a1, int a2)
{
  _DWORD *v3; // r5
  int result; // r0
  __int64 v5; // kr00_8
  unsigned int *v6; // r7
  unsigned int v7; // r6

  v3 = *(_DWORD **)(a2 + 96);
  if ( v3[2] != a1 )
    return -1073741637;
  v5 = *(_QWORD *)(v3 + 3);
  v6 = (unsigned int *)v3[5];
  v7 = ViDdiBuildWmiRegInfoData(v5, 0);
  if ( v7 <= HIDWORD(v5) )
  {
    ViDdiBuildWmiRegInfoData(v3[3], (int)v6);
    *(_DWORD *)(a2 + 28) = v7;
    result = 0;
  }
  else
  {
    if ( HIDWORD(v5) < 4 )
      return -1073741637;
    result = -1073741789;
    *v6 = v7;
    *(_DWORD *)(a2 + 28) = 4;
  }
  return result;
}
