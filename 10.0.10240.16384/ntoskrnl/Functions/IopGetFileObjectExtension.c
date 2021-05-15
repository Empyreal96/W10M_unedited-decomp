// IopGetFileObjectExtension 
 
int __fastcall IopGetFileObjectExtension(int a1, int a2, int **a3)
{
  int *v3; // r4
  int result; // r0

  v3 = *(int **)(a1 + 124);
  if ( v3 )
  {
    if ( v3 == IopRevocationExtension )
    {
      result = 0;
    }
    else
    {
      result = v3[a2 + 1];
      if ( a3 )
        *a3 = v3;
    }
  }
  else if ( a3 )
  {
    result = sub_52C790();
  }
  else
  {
    result = 0;
  }
  return result;
}
