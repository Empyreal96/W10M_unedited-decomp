// PpmEndProfileAccumulation 
 
int __fastcall PpmEndProfileAccumulation(int result, __int64 a2)
{
  unsigned __int64 v3; // kr00_8
  __int64 v4; // kr08_8
  unsigned __int64 v5; // r2

  v3 = a2 - *(_QWORD *)(result + 384);
  v4 = *(_QWORD *)(result + 416);
  *(_DWORD *)(result + 416) = v4 + v3;
  HIDWORD(v5) = *(_DWORD *)(result + 404);
  *(_DWORD *)(result + 420) = (v4 + v3) >> 32;
  LODWORD(v5) = *(_DWORD *)(result + 400);
  if ( v5 < v3 )
    *(_QWORD *)(result + 400) = v3;
  if ( *(_QWORD *)(result + 408) > v3 )
    *(_QWORD *)(result + 408) = v3;
  ++*(_QWORD *)(result + 392);
  *(_DWORD *)(result + 384) = 0;
  *(_DWORD *)(result + 388) = 0;
  return result;
}
