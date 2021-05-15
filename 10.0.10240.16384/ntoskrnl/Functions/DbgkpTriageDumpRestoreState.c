// DbgkpTriageDumpRestoreState 
 
int __fastcall DbgkpTriageDumpRestoreState(int result)
{
  __int64 v1; // kr00_8

  v1 = *(_QWORD *)(result + 8);
  *(_DWORD *)(result + 20) = v1;
  *(_DWORD *)(*(_DWORD *)result + 4192) = HIDWORD(v1);
  *(_DWORD *)(*(_DWORD *)result + 4196) = *(_DWORD *)(result + 16);
  return result;
}
