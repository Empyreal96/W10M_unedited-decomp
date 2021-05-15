// SepFreeDefaultDacl 
 
int __fastcall SepFreeDefaultDacl(int a1)
{
  int v1; // r3
  int result; // r0
  __int64 v3; // kr00_8

  v1 = *(_DWORD *)(a1 + 164);
  if ( v1 )
  {
    *(_DWORD *)(a1 + 140) += *(unsigned __int16 *)(v1 + 2);
    *(_DWORD *)(a1 + 164) = 0;
  }
  v3 = *(_QWORD *)(a1 + 156);
  result = *(_DWORD *)(a1 + 160);
  if ( result != (_DWORD)v3 )
    result = sub_7C23DC();
  return result;
}
