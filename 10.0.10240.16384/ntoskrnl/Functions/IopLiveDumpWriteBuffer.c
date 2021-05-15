// IopLiveDumpWriteBuffer 
 
int __fastcall IopLiveDumpWriteBuffer(int a1, int a2, unsigned int a3, _QWORD *a4)
{
  int result; // r0
  int v7; // [sp+18h] [bp-10h]

  result = ZwWriteFile();
  if ( result >= 0 )
  {
    result = v7;
    if ( v7 >= 0 )
      *a4 += a3;
  }
  return result;
}
