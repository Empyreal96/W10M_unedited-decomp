// CmpGetFileSize 
 
int __fastcall CmpGetFileSize(int a1, _DWORD *a2)
{
  int result; // r0
  int v4; // [sp+18h] [bp-18h]
  int v5; // [sp+1Ch] [bp-14h]

  result = ZwQueryInformationFile();
  if ( result >= 0 )
  {
    result = 0;
    *a2 = v4;
    a2[1] = v5;
  }
  return result;
}
