// CmpInitializeActualPrimaryFileSize 
 
int __fastcall CmpInitializeActualPrimaryFileSize(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]

  v7 = a3;
  v8 = a4;
  result = CmpGetFileSize(a1[444], &v7);
  if ( result >= 0 )
  {
    a1[486] = v7;
    a1[487] = v8;
    *a2 = a1[486];
  }
  if ( !*((_QWORD *)a1 + 243) || (int)a1[487] > 0 )
    result = sub_7F3D2C();
  return result;
}
