// RtlpRemoveUCRBlock 
 
int __fastcall RtlpRemoveUCRBlock(int a1, __int64 *a2)
{
  _DWORD **v3; // r1
  __int64 v4; // kr00_8
  int result; // r0
  __int64 v6; // kr08_8
  __int64 *v7; // r1

  v3 = (_DWORD **)(a2 + 1);
  v4 = *(_QWORD *)v3;
  result = *v3[1];
  if ( result != (*v3)[1] || (_DWORD **)result != v3 )
    return sub_554150();
  *(_DWORD *)HIDWORD(v4) = v4;
  *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  if ( *((_DWORD *)a2 + 5) )
  {
    v6 = *a2;
    v7 = (__int64 *)**((_DWORD **)a2 + 1);
    result = *(_DWORD *)(*(_DWORD *)a2 + 4);
    if ( v7 == (__int64 *)result && v7 == a2 )
    {
      *(_DWORD *)HIDWORD(v6) = v6;
      *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    }
    else
    {
      result = RtlpLogHeapFailure(12, 0);
    }
  }
  return result;
}
